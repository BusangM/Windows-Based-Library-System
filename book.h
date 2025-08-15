#ifndef BOOK_H
#define BOOK_H

#include "libraryitem.h"


#include <QString>
class book: public LibraryItem
{
public:

    book(QString bookTitle, QString bookAuthor, int bookId);
    QString displayInfo() override;
};

#endif // BOOK_H
