#include "librarymainwindow.h"
#include "./ui_librarymainwindow.h"

LibraryMainWindow::LibraryMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LibraryMainWindow)
{
    ui->setupUi(this);
}

LibraryMainWindow::~LibraryMainWindow()
{
    delete ui;
}
