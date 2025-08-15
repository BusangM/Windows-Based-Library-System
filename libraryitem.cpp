#include "libraryitem.h"

LibraryItem::LibraryItem(QString itemTitle, QString itemAuthor, int itemId) {

    title = itemTitle;
    author = itemAuthor;
    id = itemId;

}

QString LibraryItem::displayInfo()
{
    return title + " by " + author;
}

// Getters
QString LibraryItem::getTitle()
{
    return title;
}

QString LibraryItem::getAuthor()
{
    return author;
}

int LibraryItem::getId()
{
    return id;
}
