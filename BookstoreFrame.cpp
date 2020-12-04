#include "BookstoreFrame.h"

const int SIDE_MARGINS = 120;

BookstoreFrame::BookstoreFrame(const wxString& title)
			: wxFrame(NULL, wxID_ANY, title),
			  main_panel(new MainPanel(this)) {
	init();

	wxSize size = GetSize();
	size.SetWidth(size.GetWidth() + SIDE_MARGINS);
	size.SetHeight(size.GetHeight() + SIDE_MARGINS);
	SetSize(size);
}

BookstoreFrame::~BookstoreFrame() {
	delete main_panel;
}

void BookstoreFrame::init() {
    init_sizer();

    wxSize size = GetBestSize();
    SetMinClientSize(size);

}

void BookstoreFrame::init_sizer()
{
    wxSizer *frame_sizer = new wxBoxSizer(wxVERTICAL);

    frame_sizer->AddSpacer(20);
    frame_sizer->Add(main_panel, 0, wxALIGN_CENTER, 0);

    SetSizerAndFit(frame_sizer);
}

void BookstoreFrame::initBookstore() {
    Bookstore myBookstore;

    BookRecord m("Matilda", "Roald Dahl", 15);
    BookRecord q("1Q84", "Haruki Murakami", 20);
    BookRecord j("Jaws", "Peter Benchley", 9);
    BookRecord d("Dracula", "Bram Stroker", 26);
    BookRecord f("Frankenstein", "Mary Shelley", 17);
    BookRecord w("The Windup Bird Chronicle", "Haruki Murakami", 12);
    BookRecord g("The Girl With the Dragon Tattoo", "Stieg Larsson", 10);
    BookRecord p("The Girl Who Played with Fire", "Stieg Larsson", 7);
    BookRecord h("The Girl Who Kicked the Hornet's Nest", "Stieg Larsson", 8);
    BookRecord pe("The Pearl", "John Steinbeck", 27);
    BookRecord c("The Catcher in the Rye", "J.D. Salinger", 31);


    myBookstore.addBook(m);
    myBookstore.addBook(q);
    myBookstore.addBook(j);
    myBookstore.addBook(d);
    myBookstore.addBook(f);
    myBookstore.addBook(w);
    myBookstore.addBook(g);
    myBookstore.addBook(p);
    myBookstore.addBook(h);
    myBookstore.addBook(pe);
    myBookstore.addBook(c);
}
