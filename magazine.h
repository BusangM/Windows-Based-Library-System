#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "libraryitem.h"


class Magazine : public LibraryItem
{
public:
    Magazine(QString magazineTitle, QString magazineAuthor, int magazineId);
    QString displayInfo() override;
};

#endif // MAGAZINE_H
