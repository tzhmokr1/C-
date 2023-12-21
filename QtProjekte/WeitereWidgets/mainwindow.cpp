#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Dial Widget
    ui->DiaEingabe->setMinimum(10);
    ui->DiaEingabe->setMaximum(60);
    ui->DiaEingabe->setValue(35);
    connect(ui->DiaEingabe, SIGNAL(valueChanged(int)),
            SLOT(DiaEingabeValueChanged()));

    // Progress Bar Widget
    ui->PgrAusgabe->setValue(50);

    // Horizontal Slider Widget
    ui->SldEingabe->setMinimum(100);
    ui->SldEingabe->setMaximum(200);
    ui->SldEingabe->setValue(150);
    connect(ui->SldEingabe, SIGNAL(valueChanged(int)),
            SLOT(SldEingabeValueChanged()));

    // Date / Time Edit Widget
    QDate datum = QDate(2017,12,18);
    QTime uhrzeit = QTime(15,58,30);
    QDateTime datumUndUhrzeit = QDateTime(datum, uhrzeit);
    ui->DatEingabe->setDateTime(datumUndUhrzeit);
    ui->DatEingabe->setDisplayFormat("dd.MM.yyyy hh:mm:ss");
    connect(ui->DatEingabe, SIGNAL(dateTimeChanged(QDateTime)),
            SLOT(DatEingabeDateTimeChanged()));

    // Calendar Widget
    QDate datumMin = QDate(2017,11,15);
    ui->CalAuswahl->setMinimumDate(datumMin);
    QDate datumMax = QDate(2018,1,20);
    ui->CalAuswahl->setMaximumDate(datumMax);
    QDate datumStart = QDate(2017,11,30);
    ui->CalAuswahl->setSelectedDate(datumStart);
    connect(ui->CalAuswahl, SIGNAL(clicked(QDate)),
            SLOT(CalAuswahlClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DiaEingabeValueChanged()
{
    int wert = ui->DiaEingabe->value();
    ui->LblAusgabe->setText(QString("Dial: %1").arg(wert));

    int bereich = ui->DiaEingabe->maximum() -
        ui->DiaEingabe->minimum();
    int differenz = wert - ui->DiaEingabe->minimum();
    int anteil = 100 * differenz / bereich;
    ui->PgrAusgabe->setValue(anteil);

    ui->LcdAusgabe->display(wert);
}

void MainWindow::SldEingabeValueChanged()
{
    int wert = ui->SldEingabe->value();
    ui->LblAusgabe->setText(QString("Slider: %1").arg(wert));

    int differenz = wert - ui->SldEingabe->minimum();
    int bereich = ui->SldEingabe->maximum() -
        ui->SldEingabe->minimum();
    int anteil = 100 * differenz / bereich;
    ui->PgrAusgabe->setValue(anteil);

    ui->LcdAusgabe->display(wert);
}

void MainWindow::DatEingabeDateTimeChanged()
{
    QDateTime wert = ui->DatEingabe->dateTime();
    ui->LblAusgabe->setText(wert.toString("dd.MM.yyyy hh:mm:ss"));
}

void MainWindow::CalAuswahlClicked()
{
    QDate wert = ui->CalAuswahl->selectedDate();
    ui->LblAusgabe->setText(wert.toString("dd.MM.yyyy"));
}
