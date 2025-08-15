#include "libraryitem.h"

LibraryItem::LibraryItem(QString itemTitle, QString itemAuthor, int itemId) {

    title = itemTitle;
    author = itemAuthor;
    id = itemId;

}

QString LibraryItem::displayInfo() const
{
    return title + " by " + author;
}

// Getters
QString LibraryItem::getTitle() const
{
    return title;
}

QString LibraryItem::getAuthor() const
{
    return author;
}

int LibraryItem::getId()
{
    return id;
}
