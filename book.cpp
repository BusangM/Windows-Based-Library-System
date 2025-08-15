#include "book.h"

book::book(QString bookTitle, QString bookAuthor, int bookId): LibraryItem(bookTitle, bookAuthor, bookId) {


}

QString book::displayInfo() const
{
    return "Book: " + title + " by " + author;
}

book::book() : LibraryItem("", "", 0)
{
}
