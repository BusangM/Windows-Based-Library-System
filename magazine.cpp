#include "magazine.h"

Magazine::Magazine(QString magazineTitle, QString magazineAuthor, int magazineId):
    LibraryItem(magazineTitle, magazineAuthor, magazineId)
{
}

QString Magazine::displayInfo() const
{
    return QString("📚 %1 | Author: %2 | ID: %3").arg(title, author, QString::number(id));
}

Magazine::Magazine() : LibraryItem("", "", 0)
{
}
