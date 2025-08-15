#include "book.h"

book::book(QString bookTitle, QString bookAuthor, int bookId): LibraryItem(bookTitle, bookAuthor, bookId) {


}

QString book::displayInfo()
{
    return "Book: " + title + " by " + author;
}
