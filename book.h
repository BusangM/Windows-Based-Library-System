#ifndef BOOK_H
#define BOOK_H

#include "libraryitem.h"


#include <QString>
class book: public LibraryItem
{
public:
    book();
    book(QString bookTitle, QString bookAuthor, int bookId);
    QString displayInfo() const override;
};

#endif // BOOK_H
