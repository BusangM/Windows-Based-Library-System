#ifndef LIBRARYMAINWINDOW_H
#define LIBRARYMAINWINDOW_H

#include <QMainWindow>

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
};
#endif // LIBRARYMAINWINDOW_H
