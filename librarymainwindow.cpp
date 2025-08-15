#include "librarymainwindow.h"
#include "./ui_librarymainwindow.h"
#include "magazine.h"
#include "storage.h"
#include "book.h"
#include <QMessageBox>

LibraryMainWindow::LibraryMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LibraryMainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &LibraryMainWindow::onAddBookClicked);

    connect(ui->pushButton_5, &QPushButton::clicked, this, &LibraryMainWindow::onSearchClicked);

    connect(ui->pushButton_3, &QPushButton::clicked, this, &LibraryMainWindow::onSortByAuthorClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &LibraryMainWindow::onSortByTitleClicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &LibraryMainWindow::onClearClicked);
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

void LibraryMainWindow::showStorageInfo()
{
    QString info = QString("Books: %1, Magazines: %2")
    .arg(bookStorage.getSize())
        .arg(magazineStorage.getSize());

    // Show in window title for easy viewing
    this->setWindowTitle("Library System - " + info);
}



void LibraryMainWindow::onSearchClicked()
{
    QMessageBox::information(this, "Debug", "Search button clicked!");
    QString searchText = ui->lineEdit_3->text();
    ui->listWidget->clear();


    if (searchText.isEmpty()) {
        // Show all books
        for (int i = 0; i < bookStorage.getSize(); i++) {
            book book = bookStorage.getItem(i);
            ui->listWidget->addItem(book.displayInfo());
        }
        // Show all magazines
        for (int i = 0; i < magazineStorage.getSize(); i++) {
            Magazine magazine = magazineStorage.getItem(i);
            ui->listWidget->addItem(magazine.displayInfo());
        }
    } else {
        // Search books
        std::vector<book> foundBooks = bookStorage.searchByTitle(searchText);
        for (book bookItem : foundBooks) {
            ui->listWidget->addItem(bookItem.displayInfo());
        }

        // Search magazines
        std::vector<Magazine> foundMagazines = magazineStorage.searchByTitle(searchText);
        for (Magazine magazineItem : foundMagazines) {
            ui->listWidget->addItem(magazineItem.displayInfo());
        }
    }
}


void LibraryMainWindow::onSortByTitleClicked()
{

    QMessageBox::information(this, "Debug", "Sort by title button clicked!");

    ui->listWidget->clear();

    // Get all items
    std::vector<book> allBooks;
    std::vector<Magazine> allMagazines;

    for (int i = 0; i < bookStorage.getSize(); i++) {
        allBooks.push_back(bookStorage.getItem(i));
    }
    for (int i = 0; i < magazineStorage.getSize(); i++) {
        allMagazines.push_back(magazineStorage.getItem(i));
    }

    // Sort books by title
    std::sort(allBooks.begin(), allBooks.end(), [](const book& a, const book& b) {
        return a.getTitle() < b.getTitle();
    });

    // Sort magazines by title
    std::sort(allMagazines.begin(), allMagazines.end(), [](const Magazine& a, const Magazine& b) {
        return a.getTitle() < b.getTitle();
    });

    // Display sorted items
    for (const book& bookItem : allBooks) {
        ui->listWidget->addItem(bookItem.displayInfo());
    }
    for (const Magazine& magazineItem : allMagazines) {
        ui->listWidget->addItem(magazineItem.displayInfo());
    }
}

void LibraryMainWindow::onSortByAuthorClicked()
{
    QMessageBox::information(this, "Debug", "Sort by author button clicked!");

    ui->listWidget->clear();

    // Get all items
    std::vector<book> allBooks;
    std::vector<Magazine> allMagazines;

    for (int i = 0; i < bookStorage.getSize(); i++) {
        allBooks.push_back(bookStorage.getItem(i));
    }
    for (int i = 0; i < magazineStorage.getSize(); i++) {
        allMagazines.push_back(magazineStorage.getItem(i));
    }

    // Sort books by author
    std::sort(allBooks.begin(), allBooks.end(), [](const book& a, const book& b) {
        return a.getAuthor() < b.getAuthor();
    });

    // Sort magazines by author
    std::sort(allMagazines.begin(), allMagazines.end(), [](const Magazine& a, const Magazine& b) {
        return a.getAuthor() < b.getAuthor();
    });

    // Display sorted items
    for (const book& bookItem : allBooks) {
        ui->listWidget->addItem(bookItem.displayInfo());
    }
    for (const Magazine& magazineItem : allMagazines) {
        ui->listWidget->addItem(magazineItem.displayInfo());
    }
}

void LibraryMainWindow::onClearClicked()
{
    QMessageBox::information(this, "Debug", "clear button clicked!");

    ui->listWidget->clear();
}

void LibraryMainWindow::onAddBookClicked()
{
    // Get text from the input fields
    QString title = ui->lineEdit->text().trimmed();      // Title input field
    QString author = ui->lineEdit_2->text().trimmed();   // Author input field

    // Validation - check for empty fields
    if (title.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Title cannot be empty!\nPlease enter a title.");
        return;  // Exit function
    }

    if (author.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Author cannot be empty!\nPlease enter an author.");
        return;  // Exit function
    }


    QString itemInfo;

    // Check which radio button is selected
    if (ui->radioButton->isChecked()) {
        // Book is selected
        int newId = bookStorage.getSize() + 1;
        book newBook(title, author, newId);
        bookStorage.addItem(newBook);
        itemInfo = newBook.displayInfo();
    }
    else if (ui->radioButton_2->isChecked()) {
        // Magazine is selected
        int newId = magazineStorage.getSize() + 1;
        Magazine newMagazine(title, author, newId);
        magazineStorage.addItem(newMagazine);
        itemInfo = newMagazine.displayInfo();
    }

    // Add to GUI list
    ui->listWidget->addItem(itemInfo);

    // Clear the input fields
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    showStorageInfo();
}
