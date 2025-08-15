/********************************************************************************
** Form generated from reading UI file 'librarymainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARYMAINWINDOW_H
#define UI_LIBRARYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LibraryMainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QMenuBar *menubar;
    QMenu *menuLibaray_Management_System;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LibraryMainWindow)
    {
        if (LibraryMainWindow->objectName().isEmpty())
            LibraryMainWindow->setObjectName("LibraryMainWindow");
        LibraryMainWindow->resize(800, 600);
        centralwidget = new QWidget(LibraryMainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(440, 90, 113, 28));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(440, 150, 113, 28));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(380, 280, 90, 29));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(290, 340, 256, 192));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 90, 91, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(270, 150, 91, 20));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(360, 200, 111, 25));
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(360, 240, 111, 25));
        LibraryMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LibraryMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuLibaray_Management_System = new QMenu(menubar);
        menuLibaray_Management_System->setObjectName("menuLibaray_Management_System");
        LibraryMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LibraryMainWindow);
        statusbar->setObjectName("statusbar");
        LibraryMainWindow->setStatusBar(statusbar);

        menubar->addAction(menuLibaray_Management_System->menuAction());

        retranslateUi(LibraryMainWindow);

        QMetaObject::connectSlotsByName(LibraryMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LibraryMainWindow)
    {
        LibraryMainWindow->setWindowTitle(QCoreApplication::translate("LibraryMainWindow", "LibraryMainWindow", nullptr));
        lineEdit->setText(QString());
        lineEdit_2->setText(QString());
        pushButton->setText(QCoreApplication::translate("LibraryMainWindow", "Add Item", nullptr));
        label->setText(QCoreApplication::translate("LibraryMainWindow", "Item Title:", nullptr));
        label_2->setText(QCoreApplication::translate("LibraryMainWindow", "Item Author:", nullptr));
        radioButton->setText(QCoreApplication::translate("LibraryMainWindow", "Book", nullptr));
        radioButton_2->setText(QCoreApplication::translate("LibraryMainWindow", "Magazine", nullptr));
        menuLibaray_Management_System->setTitle(QCoreApplication::translate("LibraryMainWindow", "Libaray Management System", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LibraryMainWindow: public Ui_LibraryMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARYMAINWINDOW_H
