#ifndef LIBRARYMAINWINDOW_H
#define LIBRARYMAINWINDOW_H

#include <QMainWindow>
#include "book.h"
#include <vector>
#include <QButtonGroup>


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
    std::vector<book> books;
    QButtonGroup *itemTypeGroup;

private slots:
    void onAddBookClicked();
};
#endif // LIBRARYMAINWINDOW_H
