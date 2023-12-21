#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand((unsigned)time(NULL));
    ergebnis = -1;

    ui->LstOperation->addItem("Nur Addition");
    ui->LstOperation->addItem("Nur Subtraktion");
    ui->LstOperation->addItem("Addition oder Subtraktion");
    ui->LstOperation->setCurrentRow(0);

    ui->Opt20bis40->setChecked(true);
    ui->ChkLoesung->setChecked(true);

    connect(ui->CmdPruefenNeu, SIGNAL(clicked()),
            SLOT(CmdPruefenNeuClicked()));
    connect(ui->CmdEnde, SIGNAL(clicked()), SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CmdPruefenNeuClicked()
{
    if(ergebnis != -1)
    {
        int eingabe = ui->EdtEingabe->text().toInt();

        QString kommentar;
        if(eingabe == ergebnis)
            kommentar = "Richtig";
        else
            kommentar = "Falsch";

        if(ui->ChkLoesung->isChecked())
            kommentar += QString(": %1 %2 %3 = %4").
                arg(a).arg(operation).arg(b).arg(ergebnis);

        ui->LblKommentar->setText(kommentar);
        ui->EdtEingabe->setText("");
    }

    if(ui->LstOperation->currentRow() == 0)
        operation = "+";
    else if(ui->LstOperation->currentRow() == 1)
        operation = "-";
    else
    {
        int operationZahl = rand() % 2;
        if(operationZahl == 0)
            operation = "+";
        else
            operation = "-";
    }

    if(ui->Opt1bis10->isChecked())
    {
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
    }
    else if(ui->Opt20bis40->isChecked())
    {
        a = rand() % 20 + 20;
        b = rand() % 20 + 20;
    }
    else
    {
        a = rand() % 100 + 50;
        b = rand() % 100 + 50;
    }

    if(operation == "+")
        ergebnis = a + b;
    else
        ergebnis = a - b;

    QString aufgabe = QString("%1 %2 %3").
        arg(a).arg(operation).arg(b);
    ui->LblAufgabe->setText(aufgabe);

    ui->EdtEingabe->setFocus();
}
