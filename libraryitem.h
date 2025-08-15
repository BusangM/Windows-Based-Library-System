#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <QString>


class LibraryItem
{

protected:

    QString title;
    QString author;
    int id;

public:
    LibraryItem(QString itemTitle, QString itemAuthor, int itemId);

    virtual QString displayInfo();
    QString getAuthor();
    QString getTitle();

    int getId();
};

#endif // LIBRARYITEM_H
