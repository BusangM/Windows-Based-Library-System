#include "librarymainwindow.h"
#include "./ui_librarymainwindow.h"
#include "magazine.h"
#include "storage.h"
#include "book.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>
#include "libraryutils.h"


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
    loadFromFile();
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

void LibraryMainWindow::saveToFile()
{
    QStringList data;
    // Collect all data into QStringList format
    for (int i = 0; i < bookStorage.getSize(); i++) {
        book bookItem = bookStorage.getItem(i);
        data << QString("BOOK|%1|%2|%3").arg(bookItem.getTitle(), bookItem.getAuthor(), QString::number(bookItem.getId()));
    }
    // Use LibraryUtils for saving
    if (LibraryUtils::saveDataToFile("library_data.txt", data)) {
        QMessageBox::information(this, "Success", "Data saved using LibraryUtils!");
    }
}

void LibraryMainWindow::loadFromFile()
{
    // Use LibraryUtils to load data
    QStringList data = LibraryUtils::loadDataFromFile("library_data.txt");


    // Clear existing storage
    bookStorage = Storage<book>();
    magazineStorage = Storage<Magazine>();
    ui->listWidget->clear();

    // Process loaded data
    for (const QString& line : data) {
        QStringList parts = line.split("|");

        if (parts.size() >= 4) {
            QString type = parts[0];
            QString title = parts[1];
            QString author = parts[2];
            int id = parts[3].toInt();

            if (type == "BOOK") {
                book newBook(title, author, id);
                bookStorage.addItem(newBook);
                ui->listWidget->addItem(newBook.displayInfo());
            }
            else if (type == "MAGAZINE") {
                Magazine newMagazine(title, author, id);
                magazineStorage.addItem(newMagazine);
                ui->listWidget->addItem(newMagazine.displayInfo());
            }
        }
    }

    showStorageInfo();
    QMessageBox::information(this, "Success", "Data loaded using LibraryUtils!");
}

void LibraryMainWindow::onSearchClicked()
{
    QString searchText = ui->lineEdit_3->text();
    ui->listWidget->clear();

    if (searchText.isEmpty()) {
        // Show all items using LibraryUtils
        QStringList allItems;

        // Get all books
        for (int i = 0; i < bookStorage.getSize(); i++) {
            book bookItem = bookStorage.getItem(i);
            allItems << bookItem.displayInfo();
        }

        // Get all magazines
        for (int i = 0; i < magazineStorage.getSize(); i++) {
            Magazine magazineItem = magazineStorage.getItem(i);
            allItems << magazineItem.displayInfo();
        }

        // Display all items
        for (const QString& item : allItems) {
            ui->listWidget->addItem(item);
        }
    } else {
        // Use LibraryUtils for searching
        QStringList allItems;

        // Collect all items
        for (int i = 0; i < bookStorage.getSize(); i++) {
            allItems << bookStorage.getItem(i).displayInfo();
        }
        for (int i = 0; i < magazineStorage.getSize(); i++) {
            allItems << magazineStorage.getItem(i).displayInfo();
        }

        // Search using LibraryUtils
        QStringList searchResults = LibraryUtils::searchInList(allItems, searchText);

        // Display results
        for (const QString& result : searchResults) {
            ui->listWidget->addItem(result);
        }
    }
}


void LibraryMainWindow::onSortByTitleClicked()
{
    ui->listWidget->clear();

    // Collect all items into a QStringList
    QStringList allItems;

    // Add all books
    for (int i = 0; i < bookStorage.getSize(); i++) {
        book bookItem = bookStorage.getItem(i);
        allItems << bookItem.displayInfo();
    }

    // Add all magazines
    for (int i = 0; i < magazineStorage.getSize(); i++) {
        Magazine magazineItem = magazineStorage.getItem(i);
        allItems << magazineItem.displayInfo();
    }

    // Use LibraryUtils to sort by title
    QStringList sortedItems = LibraryUtils::sortByTitle(allItems);

    // Display sorted items
    for (const QString& item : sortedItems) {
        ui->listWidget->addItem(item);
    }
}

void LibraryMainWindow::onSortByAuthorClicked()
{
    ui->listWidget->clear();

    // Collect all items into a QStringList
    QStringList allItems;

    // Add all books
    for (int i = 0; i < bookStorage.getSize(); i++) {
        book bookItem = bookStorage.getItem(i);
        allItems << bookItem.displayInfo();
    }

    // Add all magazines
    for (int i = 0; i < magazineStorage.getSize(); i++) {
        Magazine magazineItem = magazineStorage.getItem(i);
        allItems << magazineItem.displayInfo();
    }

    // Use LibraryUtils to sort by author
    QStringList sortedItems = LibraryUtils::sortByAuthor(allItems);

    // Display sorted items
    for (const QString& item : sortedItems) {
        ui->listWidget->addItem(item);
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

    if (!LibraryUtils::validateInput(title, author)) {
        QMessageBox::warning(this, "Invalid Input", "Title and Author cannot be empty!\nPlease enter both fields.");
        return;
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
    saveToFile();
}
