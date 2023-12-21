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

        kommentar += QString(": %1 + %2 = %3").
            arg(a).arg(b).arg(ergebnis);

        ui->LblKommentar->setText(kommentar);
        ui->EdtEingabe->setText("");
    }

    a = rand() % 20 + 20;
    b = rand() % 20 + 20;
    ergebnis = a + b;

    QString aufgabe = QString("%1 + %2").arg(a).arg(b);
    ui->LblAufgabe->setText(aufgabe);

    ui->EdtEingabe->setFocus();
}
