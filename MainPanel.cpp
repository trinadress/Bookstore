#include "MainPanel.h"
#include "include/BookRecord.h"
#include <wx/numdlg.h>
#include <string>
#include <vector>

void MainPanel::init() {

	b = new Bookstore();

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
								"", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);

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

	wxPanel *label_panel = new wxPanel(this, wxID_ANY);
	wxGridSizer *label_sizer = new wxGridSizer(1, 5, 0, 0);
	wxStaticText *title = new wxStaticText(label_panel, wxID_ANY, wxT("Title"));
	wxStaticText *author = new wxStaticText(label_panel, wxID_ANY, wxT("Author"));
	wxStaticText *qty = new wxStaticText(label_panel, wxID_ANY, wxT("Qty"));
	label_panel->SetBackgroundColour(wxColour(200, 200, 200));

	label_sizer->Add(title, wxSizerFlags().Expand().Border(wxLEFT, 10));
	label_sizer->Add(author, wxSizerFlags().Expand().Border(wxLEFT, 30));
	label_sizer->Add(qty, wxSizerFlags().Expand().Border(wxLEFT, 85).Align(wxCENTER));
	label_panel->SetSizer(label_sizer);
	label_sizer->Layout();
	main_panel_sizer->Add(label_panel, wxSizerFlags().Border(wxLEFT | wxRIGHT, 50).Expand());

    booklistPanelInit();

    main_panel_sizer->Add(booklist_panel, wxSizerFlags().Border(wxRIGHT | wxLEFT, 50).Align(wxCENTER).Expand());
    main_panel_sizer->AddSpacer(0);
    main_panel_sizer->Layout();

    this->SetSizer(main_panel_sizer);
}

void MainPanel::booklistPanelInit() {
	booklist_panel = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxSize(1200, 500));
	booklist_sizer = new wxBoxSizer(wxVERTICAL);
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

	int i = 0;
	b->it->begin();
	while(!b->it->isDone()) {
		panel.push_back(new wxPanel(booklist_panel, wxID_ANY));
		panel[i]->SetSize(wxSize(900, 40));
		bookSizer.push_back(new wxGridSizer(1, 5, 0, 0));
		wxString titleStr;
		titleStr << b->it->currentItem().getTitle();
		titleString.push_back(new wxStaticText(panel[i], wxID_ANY, titleStr));
		wxString authStr;
		authStr << b->it->currentItem().getAuthor();
		authorString.push_back(new wxStaticText(panel[i], wxID_ANY, authStr));
		wxString qtyStr;
		qtyStr << b->it->currentItem().getNumOfCopies();
		numOfCopiesString.push_back(new wxStaticText(panel[i], wxID_ANY, qtyStr));
		editButtons.push_back(new wxButton(panel[i], i, edit));
		editButtons[i]->Bind(wxEVT_BUTTON, &MainPanel::onEditBook, this);
		deleteButtons.push_back(new wxButton(panel[i], i, remove));
		deleteButtons[i]->Bind(wxEVT_BUTTON, &MainPanel::onDeleteBook, this);

		bookSizer[i]->Add(titleString[i], 1, wxEXPAND | wxALL);
		bookSizer[i]->Add(authorString[i], wxSizerFlags().Expand().Border(wxLEFT, 20));
		bookSizer[i]->Add(numOfCopiesString[i], 1, wxALL | wxALIGN_CENTER);
		bookSizer[i]->Add(editButtons[i], 1, wxEXPAND | wxALL);
		bookSizer[i]->Add(deleteButtons[i], wxSizerFlags().Expand().Border(wxRIGHT, 20));
		panel[i]->SetSizer(bookSizer[i]);
		bookSizer[i]->Layout();

		booklist_sizer->Add(panel[i], wxSizerFlags().Expand().Border(wxLEFT, 10));
		booklist_sizer->AddSpacer(10);

		i++;
		b->it->next();
	}

	booklist_sizer->Layout();
	booklist_panel->SetSizer(booklist_sizer);
	booklist_panel->SetScrollbar(wxVERTICAL, 0, 10, 50);
	booklist_panel->SetScrollRate(5, 5);
}


void MainPanel::refreshBooklistPanel() {
	booklist_panel->Destroy();
	std::cout << "panel destroyed" << std::endl;
	booklistPanelInit();
	std::cout << "panel created" << std::endl;
    main_panel_sizer->Add(booklist_panel, wxSizerFlags().Border(wxRIGHT | wxLEFT, 50).Align(wxCENTER).Expand());
    main_panel_sizer->AddSpacer(0);
    main_panel_sizer->Layout();

    this->SetSizer(main_panel_sizer);
}


// Handlers

void MainPanel::onSearchBook(wxCommandEvent& event) {
	std::string t = std::string(text);
	std::cout << t << std::endl;
	int index = b->searchBookByTitle(t);
	std::cout << index << std::endl;

	if (-1 != index) {
		booklist_panel->Destroy();
		BookRecord result = b->searchBook(index);
		wxString titleStr;
		wxString authorStr;
		wxString numOfCopiesStr;

		titleStr << result.getTitle();
		authorStr << result.getAuthor();
		numOfCopiesStr << result.getNumOfCopies();

		searchResultPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(950, 100));
		wxPanel *bookResultPanel = new wxPanel(searchResultPanel, wxID_ANY, wxDefaultPosition, wxSize(900, 40));
		wxSizer *searchResultSizer = new wxBoxSizer(wxVERTICAL);
		wxSizer *bookResultSizer = new wxGridSizer(1, 5, 0, 0);
		searchResultPanel->SetBackgroundColour(wxColour(255, 255, 255));

		searchResultPanel->SetSize(wxSize(800, 40));

		wxStaticText *titleString = new wxStaticText(bookResultPanel, wxID_ANY, titleStr);
		wxStaticText *authorString = new wxStaticText(bookResultPanel, wxID_ANY, authorStr);
		wxStaticText *numOfCopiesString = new wxStaticText(bookResultPanel, wxID_ANY, numOfCopiesStr);
		wxButton *editButton = new wxButton(bookResultPanel, wxID_ANY, wxT("Edit"));
		wxButton *deleteButton = new wxButton(bookResultPanel, wxID_ANY, wxT("Delete"));
		wxButton *backButton = new wxButton(searchResultPanel, wxID_ANY, wxT("Back to Inventory"));

		editButton->Bind(wxEVT_BUTTON, &MainPanel::onEditBook, this);
		deleteButton->Bind(wxEVT_BUTTON, &MainPanel::onDeleteBook, this);
		backButton->Bind(wxEVT_BUTTON, &MainPanel::onBack, this);

		bookResultSizer->Add(titleString, 1, wxEXPAND | wxALL);
		bookResultSizer->Add(authorString, wxSizerFlags().Expand().Border(wxLEFT, 20));
		bookResultSizer->Add(numOfCopiesString, 1, wxALL | wxALIGN_CENTER);
		bookResultSizer->Add(editButton, 1, wxEXPAND | wxALL);
		bookResultSizer->Add(deleteButton, wxSizerFlags().Expand().Border(wxRIGHT, 20));
		bookResultPanel->SetSizer(bookResultSizer);
		bookResultSizer->Layout();

		searchResultSizer->Add(bookResultPanel, wxSizerFlags().Expand().Border(wxLEFT, 10));
		searchResultSizer->Add(backButton, wxSizerFlags().Expand().Border(wxLEFT, 10));
		searchResultPanel->SetSizer(searchResultSizer);
		searchResultSizer->Layout();

//		main_panel_sizer->Add(searchResultPanel, wxSizerFlags().Expand().Border(wxLEFT, 10));
//		main_panel_sizer->AddSpacer(10);

	    main_panel_sizer->Add(searchResultPanel, wxSizerFlags().Border(wxRIGHT | wxLEFT, 50).Align(wxCENTER).Expand());
	    main_panel_sizer->Layout();

	    this->SetSizer(main_panel_sizer);
	    text.Clear();
	}

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
	}
}
void MainPanel::onDeleteBook(wxCommandEvent& event) {

	int id = event.GetId();
	b->deleteBook(id);

	refreshBooklistPanel();

}

void MainPanel::onUpdateText(wxCommandEvent& event) {
	wxTextCtrl *tc = wxDynamicCast( event.GetEventObject(), wxTextCtrl );
	if( tc != NULL )
	{
		text = tc->GetValue();
	}
}

void MainPanel::onBack(wxCommandEvent &event) {
	searchResultPanel->Destroy();
	std::cout << "panel destroyed" << std::endl;
	booklistPanelInit();
	std::cout << "panel created" << std::endl;
    main_panel_sizer->Add(booklist_panel, wxSizerFlags().Border(wxRIGHT | wxLEFT, 50).Align(wxCENTER).Expand());
    main_panel_sizer->AddSpacer(0);
    main_panel_sizer->Layout();

    this->SetSizer(main_panel_sizer);
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
