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

    virtual QString displayInfo() const;
    QString getAuthor() const;
    QString getTitle() const;

    int getId();
};

#endif // LIBRARYITEM_H
