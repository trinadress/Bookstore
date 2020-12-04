#ifndef MAINPANEL_H_
#define MAINPANEL_H_


#include "BookstoreDemo.h"
#include "include/Bookstore.h"

class MainPanel : public wxPanel {
	public:
		MainPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY) {
			init();
		}

		// Event Handlers
		void onSearchBook(wxCommandEvent& event);
		void onAddNewBook(wxCommandEvent& event);
		void onEditBook(wxCommandEvent& event);
		void onDeleteBook(wxCommandEvent& event);
		void onAdd(wxCommandEvent& event);

		void onUpdateText(wxCommandEvent& event);

	private:
		wxString text;

		void init();
};

#endif
