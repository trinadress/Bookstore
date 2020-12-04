#ifndef BOOKSTOREFRAME_H_
#define BOOKSTOREFRAME_H_

#include "MainPanel.h"

class BookstoreFrame : public wxFrame {

	public:
		BookstoreFrame(const wxString& title);
		virtual ~BookstoreFrame();

	private:
		MainPanel *main_panel;

		void init();
		void init_sizer();
		void initBookstore();

};

#endif
