#include "MainPanel.h"
#include "include/BookRecord.h"
#include <string>
#include <vector>

void MainPanel::init() {
	// initialize sizers, panels, buttons, text, etc

	wxSizer *main_panel_sizer = new wxBoxSizer(wxVERTICAL);

// Head Panel
	// Header
	wxPanel *head_panel = new wxPanel(this, wxID_ANY);
	wxSizer *head_sizer = new wxBoxSizer(wxVERTICAL);

	wxStaticText *heading_text = new wxStaticText(head_panel, wxID_ANY,
													wxT("Dean's Bookstore"));
    heading_text->SetFont(heading_text->GetFont().Larger().Larger().Larger());

    wxStaticText *sub_heading_text = new wxStaticText(head_panel, wxID_ANY,
														wxT("Inventory Management System"));
	sub_heading_text->SetFont(sub_heading_text->GetFont().Larger().Larger());

	// Vertical Buttons Panel (Search, add, list view?, grid view?)
    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

	wxTextCtrl *search_field = new wxTextCtrl(button_panel, wxID_ANY,
								" ", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
	search_field->SetInsertionPoint(0);

    wxButton *search_button     = new wxButton(button_panel, wxID_ANY,
                                             "Search");
    wxButton *add_book_button    = new wxButton(button_panel, wxID_ANY,
                                             "Add Book");
    search_field->Bind(wxEVT_TEXT, &MainPanel::onUpdateText, this);
    search_button->Bind(wxEVT_BUTTON, &MainPanel::onSearchBook, this);
    add_book_button->Bind(wxEVT_BUTTON, &MainPanel::onAddNewBook, this);

    head_sizer->Add(heading_text, 0, 0, 0);
    head_sizer->AddSpacer(5);
    head_sizer->Add(sub_heading_text, 0, 0, 0);
    head_sizer->AddSpacer(5);
    head_panel->SetSizer(head_sizer);

    button_sizer->Add(search_field, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(search_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(add_book_button, 0, 0, 0);
    button_panel->SetSizer(button_sizer);

        main_panel_sizer->Add(head_panel, 0, wxALIGN_CENTER, 0);
        main_panel_sizer->AddSpacer(20);
        main_panel_sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
        main_panel_sizer->AddSpacer(20);

// Inventory List Panel
	// Inventory List Panel

	wxPanel *list_panel = new wxPanel(this, wxID_ANY);
	wxSizer *list_sizer = new wxBoxSizer(wxVERTICAL);

	wxPanel *book_panel = new wxPanel(this, wxID_ANY);
	wxSizer *book_sizer = new wxBoxSizer(wxVERTICAL);

	wxString edit = "edit";
	wxString a[] = {"Twilight", "Harry Potter", "Moby Dick", "1Q84", "Catcher in the Rye", "Frankenstein", "Dracula"};
	std::vector<wxPanel*> p;
	std::vector<wxBoxSizer*> bs;
	std::vector<wxStaticText*> s;
	std::vector<wxButton*> b;
	int size = sizeof(a)/sizeof(a[0]);
	for(int i = 0; i < size; i++) {
		p.push_back(new wxPanel(this, wxID_ANY));
		bs.push_back(new wxBoxSizer(wxHORIZONTAL));
		s.push_back(new wxStaticText(p[i], wxID_ANY, a[i]));
		b.push_back(new wxButton(p[i], wxID_ANY, edit));

		bs[i]->Add(s[i], 0, 0, 0);
		bs[i]->AddSpacer(20);
		bs[i]->Add(b[i], 0, 0, 0);
		p[i]->SetSizer(bs[i]);

	    main_panel_sizer->Add(p[i], 0, wxALIGN_LEFT, 0);
	    main_panel_sizer->AddSpacer(20);
	}

    SetSizer(main_panel_sizer);

	//Add Book dialog box
}

// Handlers

void MainPanel::onSearchBook(wxCommandEvent& event) {
	Bookstore b;
	int index;
	index = b.searchBookByTitle(std::string(text));

}
void MainPanel::onAddNewBook(wxCommandEvent& event) {

}
void MainPanel::onEditBook(wxCommandEvent& event) {

}
void MainPanel::onDeleteBook(wxCommandEvent& event) {

}
void MainPanel::onAdd(wxCommandEvent& event) {

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


