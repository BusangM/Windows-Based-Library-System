#include "magazine.h"

Magazine::Magazine(QString magazineTitle, QString magazineAuthor, int magazineId):
    LibraryItem(magazineTitle, magazineAuthor, magazineId)
{
}

QString Magazine::displayInfo()
{
    return "Magazine: " + title + " by " + author;
}
