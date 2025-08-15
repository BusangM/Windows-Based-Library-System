#ifndef LIBRARYMAINWINDOW_H
#define LIBRARYMAINWINDOW_H

#include <QMainWindow>
#include "book.h"
#include "magazine.h"

#include <vector>
#include <QButtonGroup>
#include "storage.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class LibraryMainWindow;
}
QT_END_NAMESPACE

class LibraryMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    LibraryMainWindow(QWidget *parent = nullptr);
    ~LibraryMainWindow();

private:
    Ui::LibraryMainWindow *ui;
    QButtonGroup *itemTypeGroup;
    Storage<book> bookStorage;
    Storage<Magazine> magazineStorage;

private slots:
    void onAddBookClicked();
    void showStorageInfo();

    void onSearchClicked();
    void onSortByTitleClicked();
    void onSortByAuthorClicked();
    void onClearClicked();
};
#endif // LIBRARYMAINWINDOW_H
