#include "BookstoreDemo.h"
#include "BookstoreFrame.h"

wxIMPLEMENT_APP(BookstoreDemo);

bool BookstoreDemo::OnInit()
{
    if (!wxApp::OnInit()) return false;

    BookstoreFrame *frame = new BookstoreFrame("Bookstore Demo");
    frame->Show(true);

    return true;
}
