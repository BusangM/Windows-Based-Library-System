#include "librarymainwindow.h"
#include "./ui_librarymainwindow.h"
#include "magazine.h"

LibraryMainWindow::LibraryMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LibraryMainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &LibraryMainWindow::onAddBookClicked);

    itemTypeGroup = new QButtonGroup(this);
    itemTypeGroup->addButton(ui->radioButton);    // Book radio button
    itemTypeGroup->addButton(ui->radioButton_2);  // Magazine radio button

    // Set Book as default selection
    ui->radioButton->setChecked(true);
}

LibraryMainWindow::~LibraryMainWindow()
{
    delete ui;
}

void LibraryMainWindow::onAddBookClicked()
{
    // Get text from the input fields
    QString title = ui->lineEdit->text();      // Title input field
    QString author = ui->lineEdit_2->text();   // Author input field

    int newId = books.size() + 1;
    QString bookInfo;

    // Check which radio button is selected
    if (ui->radioButton->isChecked()) {
        // Book is selected
        book newBook(title, author, newId);
        books.push_back(newBook);
        bookInfo = newBook.displayInfo();
    }
    else if (ui->radioButton_2->isChecked()) {
        // Magazine is selected
        Magazine newMagazine(title, author, newId);

        bookInfo = newMagazine.displayInfo();
    }

    // Add to GUI list
    ui->listWidget->addItem(bookInfo);

    // Clear the input fields
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}
