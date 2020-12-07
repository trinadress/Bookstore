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

		void onUpdateText(wxCommandEvent& event);

	private:
		Bookstore *b;
		wxString text;
		wxString a[7];
		wxPanel *booklist_panel;
		wxSizer *main_panel_sizer;

		void init();
		void booklistPanelInit();
		void refreshBooklistPanel();
};


class BasicDialog: public wxDialog
{
public:

	BasicDialog ( wxWindow * parent, wxWindowID id, const wxString & title,
	              const wxPoint & pos = wxDefaultPosition,
	              const wxSize & size = wxDefaultSize,
	              long style = wxDEFAULT_DIALOG_STYLE );

	virtual bool Validate();
	wxTextCtrl * titleDialogText;
	wxTextCtrl * authorDialogText;
	wxTextCtrl * qtyDialogText;
	wxString GetText();

private:

	void OnOk( wxCommandEvent & event );
};





#endif
