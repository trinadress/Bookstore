#ifndef BOOKSTOREDEMO_H_
#define BOOKSTOREDEMO_H_

#include "wx/wx.h"

/**
 * The main application class.
 */
class BookstoreDemo : public wxApp
{
public:
    /**
     * Initialization function that is called when the application opens.
     * @returns true if the app opened successfully, else returns false.
     */
    virtual bool OnInit() override;
};

#endif /* BOOKSTOREDEMO_H_ */
