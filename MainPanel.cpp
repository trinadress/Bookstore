#include "MainPanel.h"
#include "include/BookRecord.h"
#include <wx/numdlg.h>
#include <string>
#include <vector>

void MainPanel::init() {

	b = new Bookstore();

	a[0] = "Twilight";
	a[1] = "Harry Potter";
	a[2] = "Moby Dick";
	a[3] = "1Q84";
	a[4] = "Catcher in the Rye";
	a[5] = "Frankenstein";
	a[6] = "Dracula";

	main_panel_sizer = new wxBoxSizer(wxVERTICAL);
	this->SetBackgroundColour(wxColour(0, 0, 100));

	// Head Panel
	wxPanel *head_panel = new wxPanel(this, wxID_ANY);
	wxSizer *head_sizer = new wxBoxSizer(wxVERTICAL);
	head_panel->SetBackgroundColour(wxColour(200, 200, 200));

	wxStaticText *heading_text = new wxStaticText(head_panel, wxID_ANY, wxT("Dean's Bookstore"));
	heading_text->SetFont(heading_text->GetFont().Larger().Larger().Larger());

    wxStaticText *sub_heading_text = new wxStaticText(head_panel, wxID_ANY, wxT("Inventory Management System"));
	sub_heading_text->SetFont(sub_heading_text->GetFont().Larger().Larger());

    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

	wxTextCtrl *search_field = new wxTextCtrl(button_panel, wxID_ANY,
								" ", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);

    wxButton *search_button     = new wxButton(button_panel, wxID_ANY, "Search");
    wxButton *add_book_button    = new wxButton(button_panel, wxID_ANY, "Add Book");

    search_field->Bind(wxEVT_TEXT, &MainPanel::onUpdateText, this);
    search_button->Bind(wxEVT_BUTTON, &MainPanel::onSearchBook, this);
    add_book_button->Bind(wxEVT_BUTTON, &MainPanel::onAddNewBook, this);

    head_sizer->Add(heading_text, 0, 0, 0);
    head_sizer->AddSpacer(5);
    head_sizer->Add(sub_heading_text, 0, 0, 0);
    head_panel->SetSizer(head_sizer);

    button_sizer->Add(search_field, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(search_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(add_book_button, 0, 0, 0);
    button_panel->SetSizer(button_sizer);

	main_panel_sizer->Add(head_panel, 0, wxALIGN_CENTER, 0);
	main_panel_sizer->AddSpacer(10);
	main_panel_sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
	main_panel_sizer->AddSpacer(20);

// Inventory List Panel

    booklistPanelInit();

    main_panel_sizer->Add(booklist_panel, wxSizerFlags().Border(wxRIGHT | wxLEFT).Align(wxCENTER));
    main_panel_sizer->AddSpacer(0);
    main_panel_sizer->Layout();

    this->SetSizer(main_panel_sizer);


}

void MainPanel::booklistPanelInit() {
	booklist_panel = new wxPanel(this, wxID_ANY);
	wxSizer *booklist_sizer = new wxBoxSizer(wxVERTICAL);
	booklist_panel->SetBackgroundColour(wxColour(255, 255, 255));

	wxString edit = "Edit";
	wxString remove = "Delete";
	std::vector<wxPanel*> panel;
	std::vector<wxGridSizer*> bookSizer;
	std::vector<wxStaticText*> titleString;
	std::vector<wxStaticText*> authorString;
	std::vector<wxStaticText*> numOfCopiesString;
	std::vector<wxButton*> editButtons;
	std::vector<wxButton*> deleteButtons;
//	int size = sizeof(a)/sizeof(a[0]);

	wxPanel *label_panel = new wxPanel(booklist_panel, wxID_ANY);
	wxGridSizer *label_sizer = new wxGridSizer(1, 4, 0, 0);
	wxStaticText *title = new wxStaticText(label_panel, wxID_ANY, wxT("Title"));
	wxStaticText *qty = new wxStaticText(label_panel, wxID_ANY, wxT("Qty"));
	label_panel->SetBackgroundColour(wxColour(200, 200, 200));

	label_sizer->Add(title, 1, wxEXPAND | wxALL);
	label_sizer->Add(qty, 1, wxALL | wxALIGN_CENTER);
	label_panel->SetSizer(label_sizer);
	label_sizer->Layout();
	booklist_sizer->Add(label_panel, wxSizerFlags().Expand());
	booklist_sizer->AddSpacer(10);


//	for(int i = 0; i < size; i++) {
//		panel.push_back(new wxPanel(booklist_panel, wxID_ANY));
//		panel[i]->SetSize(wxSize(800, 40));
//		bookSizer.push_back(new wxGridSizer(1, 4, 0, 0));
//		bookString.push_back(new wxStaticText(panel[i], wxID_ANY, a[i]));
//		wxString myStr;
//		myStr << i;
//		numOfCopiesString.push_back(new wxStaticText(panel[i], wxID_ANY, myStr));
//		editButtons.push_back(new wxButton(panel[i], i, edit));
//	    editButtons[i]->Bind(wxEVT_BUTTON, &MainPanel::onEditBook, this);
//		deleteButtons.push_back(new wxButton(panel[i], i, remove));
//	    deleteButtons[i]->Bind(wxEVT_BUTTON, &MainPanel::onDeleteBook, this);
//
//
//		bookSizer[i]->Add(bookString[i], 1, wxEXPAND | wxALL);
//		bookSizer[i]->Add(numOfCopiesString[i], 1, wxALL | wxALIGN_CENTER);
//		bookSizer[i]->Add(editButtons[i], 1, wxEXPAND | wxALL);
//		bookSizer[i]->Add(deleteButtons[i], 1, wxEXPAND | wxALL);
//		panel[i]->SetSizer(bookSizer[i]);
//		bookSizer[i]->Layout();
//
//	    booklist_sizer->Add(panel[i], wxSizerFlags().Expand().Border(wxLEFT, 10));
//	    booklist_sizer->AddSpacer(10);
//	}


	int i = 0;
	b->it->begin();
	while(!b->it->isDone()) {

		panel.push_back(new wxPanel(booklist_panel, wxID_ANY));
		panel[i]->SetSize(wxSize(800, 40));
		bookSizer.push_back(new wxGridSizer(1, 4, 0, 0));
		wxString titleStr;
		titleStr << b->it->currentItem().getTitle();
		titleString.push_back(new wxStaticText(panel[i], wxID_ANY, titleStr));
		wxString qtyStr;
		qtyStr << b->it->currentItem().getNumOfCopies();
		numOfCopiesString.push_back(new wxStaticText(panel[i], wxID_ANY, qtyStr));
		editButtons.push_back(new wxButton(panel[i], i, edit));
		editButtons[i]->Bind(wxEVT_BUTTON, &MainPanel::onEditBook, this);
		deleteButtons.push_back(new wxButton(panel[i], i, remove));
		deleteButtons[i]->Bind(wxEVT_BUTTON, &MainPanel::onDeleteBook, this);


		bookSizer[i]->Add(titleString[i], 1, wxEXPAND | wxALL);
		bookSizer[i]->Add(numOfCopiesString[i], 1, wxALL | wxALIGN_CENTER);
		bookSizer[i]->Add(editButtons[i], 1, wxEXPAND | wxALL);
		bookSizer[i]->Add(deleteButtons[i], 1, wxEXPAND | wxALL);
		panel[i]->SetSizer(bookSizer[i]);
		bookSizer[i]->Layout();

		booklist_sizer->Add(panel[i], wxSizerFlags().Expand().Border(wxLEFT, 10));
		booklist_sizer->AddSpacer(10);

		i++;
		b->it->next();
	}
//
//	b->it->begin();
//	while(!b->it->isDone()) {
//		std::cout << b->it->currentItem().getTitle() << std::endl;
//		b->it->next();
//	}


	booklist_sizer->Layout();
	booklist_panel->SetSizer(booklist_sizer);
}


void MainPanel::refreshBooklistPanel() {
	booklist_panel->Destroy();
	std::cout << "panel destroyed" << std::endl;
	booklistPanelInit();
	std::cout << "panel created" << std::endl;
    main_panel_sizer->Add(booklist_panel, wxSizerFlags().Border(wxRIGHT | wxLEFT).Align(wxCENTER));
    main_panel_sizer->AddSpacer(0);
    main_panel_sizer->Layout();

    this->SetSizer(main_panel_sizer);
}


// Handlers

void MainPanel::onSearchBook(wxCommandEvent& event) {
//	int index;
//	index = b->searchBookByTitle(std::string(text));


}
void MainPanel::onAddNewBook(wxCommandEvent& event) {
	BasicDialog *addBookDialog = new BasicDialog(this, wxID_ANY, wxT("Add New Book"));
	if (addBookDialog->ShowModal() == wxID_OK) {
		wxString title = addBookDialog->titleDialogText->GetValue();
		wxString author = addBookDialog->authorDialogText->GetValue();
		wxString qty = addBookDialog->qtyDialogText->GetValue();

		std::string t = std::string(title);
		std::string a = std::string(author);
		int q = stoi(std::string(qty));

		BookRecord newBook(t, a, q);
		b->addBook(newBook);
		refreshBooklistPanel();

//		std::cout << std::string(title) << " " << std::string(author) << " " << std::string(qty) << std::endl;
	}

}
void MainPanel::onEditBook(wxCommandEvent& event) {
	int index = event.GetId();
	BookRecord br = b->searchBook(index);
	long currQty = br.getNumOfCopies();

	wxNumberEntryDialog dialog(this, wxT(" "), wxT("Enter Quantity:"), wxT("Qty"), currQty, 0, 100);
	if (dialog.ShowModal() == wxID_OK) {
		int value = dialog.GetValue();
		b->editNumOfCopies(br, value);
		refreshBooklistPanel();

		std::cout << value << std::endl;
	}
}
void MainPanel::onDeleteBook(wxCommandEvent& event) {

	int id = event.GetId();
	b->deleteBook(id);

	refreshBooklistPanel();

}

//set text string to value of text field
void MainPanel::onUpdateText(wxCommandEvent& event) {
	std::cerr << "updatetext" << std::endl;
	wxTextCtrl *tc = wxDynamicCast( event.GetEventObject(), wxTextCtrl );
	std::cerr << "after dynamic cast" << std::endl;
	if( tc != NULL )
	{
		std::cerr << "tc not null" << std::endl;
		text = tc->GetValue();
	  std::cerr << "got text value" << std::endl;
	}
	std::cerr << "end update text" << std::endl;
}




BasicDialog::BasicDialog ( wxWindow * parent, wxWindowID id, const wxString & title,
                           const wxPoint & position, const wxSize & size, long style )
: wxDialog( parent, id, title, position, size, style)
{
	wxString theTextData = "";
	wxBoxSizer *topsizer = new wxBoxSizer( wxVERTICAL );
	wxStaticText *t = new wxStaticText(this, wxID_ANY, wxT("Title"));
	wxStaticText *a = new wxStaticText(this, wxID_ANY, wxT("Author"));
	wxStaticText *q = new wxStaticText(this, wxID_ANY, wxT("Quantity"));

	titleDialogText = new wxTextCtrl( this, wxID_ANY, wxT("Title"), wxDefaultPosition,
								 wxSize(200, 40), wxTE_MULTILINE );
	authorDialogText = new wxTextCtrl( this, wxID_ANY, wxT("Author"), wxDefaultPosition,
								 wxSize(200, 40), wxTE_MULTILINE );
	qtyDialogText = new wxTextCtrl( this, wxID_ANY, wxT("Quantity"), wxDefaultPosition,
								 wxSize(80, 40), wxTE_MULTILINE );


	titleDialogText->SetBackgroundColour(wxColour(255, 255, 255));
	titleDialogText->SetForegroundColour(wxColour(0, 0, 0));
	authorDialogText->SetBackgroundColour(wxColour(255, 255, 255));
	authorDialogText->SetForegroundColour(wxColour(0, 0, 0));
	qtyDialogText->SetBackgroundColour(wxColour(255, 255, 255));
	qtyDialogText->SetForegroundColour(wxColour(0, 0, 0));

	topsizer->Add( t, 0, 0, 0);
	topsizer->Add( titleDialogText, 1, wxEXPAND | wxALL, 10 );
	topsizer->Add( a, 0, 0, 0 );
	topsizer->Add( authorDialogText, 1, wxEXPAND | wxALL, 10 );
	topsizer->Add( q, 0, 0, 0);
	topsizer->Add( qtyDialogText, 1, wxEXPAND | wxALL, 10 );

	wxBoxSizer *button_sizer = new wxBoxSizer( wxHORIZONTAL );
	button_sizer->Add( new wxButton( this, wxID_OK, _("OK") ), 0, wxALL, 10 );
	button_sizer->Add( new wxButton( this, wxID_CANCEL, _("Cancel") ), 0, wxALL, 10 );

	topsizer->Add( button_sizer, 0, wxALIGN_CENTER );
	SetAutoLayout( TRUE );
	SetSizer( topsizer );
	topsizer->Fit( this );
	topsizer->SetSizeHints( this );
}

bool BasicDialog::Validate()
{
	return true;
}

void BasicDialog::OnOk(wxCommandEvent & event)
{
	event.Skip();
}
