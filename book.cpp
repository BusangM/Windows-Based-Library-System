#include "book.h"

book::book(QString bookTitle, QString bookAuthor, int bookId): LibraryItem(bookTitle, bookAuthor, bookId) {


}

QString book::displayInfo() const
{
    return QString("📚 %1 | Author: %2 | ID: %3").arg(title, author, QString::number(id));
}

book::book() : LibraryItem("", "", 0)
{
}
