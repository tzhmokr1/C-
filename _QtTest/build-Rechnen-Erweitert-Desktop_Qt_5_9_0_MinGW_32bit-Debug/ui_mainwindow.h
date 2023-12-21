/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *LblAufgabe;
    QLineEdit *EdtEingabe;
    QPushButton *CmdPruefenNeu;
    QLabel *LblKommentar;
    QPushButton *CmdEnde;
    QListWidget *LstOperation;
    QRadioButton *Opt1bis10;
    QRadioButton *Opt20bis40;
    QRadioButton *Opt50bis150;
    QCheckBox *ChkLoesung;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(521, 324);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LblAufgabe = new QLabel(centralWidget);
        LblAufgabe->setObjectName(QStringLiteral("LblAufgabe"));
        LblAufgabe->setGeometry(QRect(90, 10, 61, 31));
        EdtEingabe = new QLineEdit(centralWidget);
        EdtEingabe->setObjectName(QStringLiteral("EdtEingabe"));
        EdtEingabe->setGeometry(QRect(90, 50, 113, 20));
        CmdPruefenNeu = new QPushButton(centralWidget);
        CmdPruefenNeu->setObjectName(QStringLiteral("CmdPruefenNeu"));
        CmdPruefenNeu->setGeometry(QRect(90, 90, 111, 31));
        LblKommentar = new QLabel(centralWidget);
        LblKommentar->setObjectName(QStringLiteral("LblKommentar"));
        LblKommentar->setGeometry(QRect(90, 140, 201, 31));
        CmdEnde = new QPushButton(centralWidget);
        CmdEnde->setObjectName(QStringLiteral("CmdEnde"));
        CmdEnde->setGeometry(QRect(90, 180, 111, 31));
        LstOperation = new QListWidget(centralWidget);
        LstOperation->setObjectName(QStringLiteral("LstOperation"));
        LstOperation->setGeometry(QRect(250, 20, 221, 91));
        Opt1bis10 = new QRadioButton(centralWidget);
        Opt1bis10->setObjectName(QStringLiteral("Opt1bis10"));
        Opt1bis10->setGeometry(QRect(250, 120, 82, 17));
        Opt20bis40 = new QRadioButton(centralWidget);
        Opt20bis40->setObjectName(QStringLiteral("Opt20bis40"));
        Opt20bis40->setGeometry(QRect(250, 150, 82, 17));
        Opt50bis150 = new QRadioButton(centralWidget);
        Opt50bis150->setObjectName(QStringLiteral("Opt50bis150"));
        Opt50bis150->setGeometry(QRect(250, 180, 82, 17));
        ChkLoesung = new QCheckBox(centralWidget);
        ChkLoesung->setObjectName(QStringLiteral("ChkLoesung"));
        ChkLoesung->setGeometry(QRect(250, 220, 101, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 521, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        LblAufgabe->setText(QApplication::translate("MainWindow", "(Aufgabe)", Q_NULLPTR));
        CmdPruefenNeu->setText(QApplication::translate("MainWindow", "Pr\303\274fen / Neu", Q_NULLPTR));
        LblKommentar->setText(QApplication::translate("MainWindow", "(Kommentar)", Q_NULLPTR));
        CmdEnde->setText(QApplication::translate("MainWindow", "Ende", Q_NULLPTR));
        Opt1bis10->setText(QApplication::translate("MainWindow", "1 BIS 10", Q_NULLPTR));
        Opt20bis40->setText(QApplication::translate("MainWindow", "20 BIS 40", Q_NULLPTR));
        Opt50bis150->setText(QApplication::translate("MainWindow", "50 BIS 150", Q_NULLPTR));
        ChkLoesung->setText(QApplication::translate("MainWindow", "MIT L\303\266sung", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
