#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Datenbankverbindung erstellen
    con = QSqlDatabase::addDatabase("QSQLITE");
    con.setDatabaseName("firma.db");
    if(!con.open())
    {
        QMessageBox mb;
        mb.setText("DB nicht geöffnet");
        mb.exec();
        return;
    }
    sqlBefehl = QSqlQuery(con);

    // Datenbank erzeugen und füllen
    sqlBefehl.exec("CREATE TABLE personen(name TEXT, "
       "vorname TEXT, personalnummer INTEGER PRIMARY KEY, "
       "gehalt REAL, geburtstag TEXT)");
    sqlBefehl.exec("INSERT INTO personen VALUES"
       "('Maier', 'Hans', 6714, 3500, '15.03.1962'),"
       "('Schmitz', 'Peter', 81343, 3750, '12.04.1958'),"
       "('Mertens', 'Julia', 2297, 3621.5, '30.12.1959')");

    // Schaltflächen verbinden
    connect(ui->CmdAlleSehen, SIGNAL(clicked()),
            SLOT(CmdAlleSehenClicked()));
    connect(ui->CmdEinfuegen, SIGNAL(clicked()),
            SLOT(CmdEinfuegenClicked()));
    connect(ui->CmdAendern, SIGNAL(clicked()),
            SLOT(CmdAendernClicked()));
    connect(ui->CmdLoeschen, SIGNAL(clicked()),
            SLOT(CmdLoeschenClicked()));
    connect(ui->CmdFiltern, SIGNAL(clicked()),
            SLOT(CmdFilternClicked()));

    // List Widget verbinden
    connect(ui->LstAnzeige, SIGNAL(itemSelectionChanged()),
            SLOT(LstAnzeigeSelectionChanged()));

    // Anfangszustand einstellen
    this->setWindowTitle("Personenverwaltung");
    AlleSehen();
}

MainWindow::~MainWindow()
{
    con.close();
    delete ui;
}

bool MainWindow::FehlerAnzeige()
{
    QSqlError fehler = sqlBefehl.lastError();
    if(fehler.isValid())
    {
        QMessageBox mb;
        mb.setText("Fehler: " + fehler.databaseText());
        mb.exec();
        return true;
    }
    return false;
}

void MainWindow::AlleSehen()
{
    ui->LstAnzeige->clear();
    sqlBefehl.exec("SELECT * FROM personen");
    FehlerAnzeige();
    while(sqlBefehl.next())
    {
        QString ausgabe;
        for(int i=0; i<5; i++)
            ausgabe += sqlBefehl.value(i).toString() + " # ";
        ui->LstAnzeige->addItem(ausgabe);
    }

    ui->EdtName->clear();
    ui->EdtVorname->clear();
    ui->EdtPersonalnummer->clear();
    ui->EdtGehalt->clear();
    ui->DatGeburtstag->setDate(QDate(2000,1,1));
}

void MainWindow::CmdAlleSehenClicked()
{
    AlleSehen();
}

void MainWindow::CmdEinfuegenClicked()
{
    if(ui->EdtPersonalnummer->text() == "")
    {
        QMessageBox mb;
        mb.setText("Bitte Personalnummer eingeben");
        mb.exec();
        return;
    }

    sqlBefehl.prepare("INSERT INTO personen VALUES(?, ?, ?, ?, ?)");
    sqlBefehl.addBindValue(ui->EdtName->text());
    sqlBefehl.addBindValue(ui->EdtVorname->text());
    sqlBefehl.addBindValue(ui->EdtPersonalnummer->text().toInt());
    sqlBefehl.addBindValue(ui->EdtGehalt->text().toDouble());
    sqlBefehl.addBindValue(ui->DatGeburtstag->
        date().toString("dd.MM.yyyy"));
    sqlBefehl.exec();
    if(FehlerAnzeige())
        return;
    AlleSehen();
}

void MainWindow::LstAnzeigeSelectionChanged()
{
    QString eintragText = ui->LstAnzeige->currentItem()->text();
    QStringList eintragListe = eintragText.split("#");

    ui->EdtName->setText(eintragListe.at(0).trimmed());
    ui->EdtVorname->setText(eintragListe.at(1).trimmed());
    ui->EdtPersonalnummer->setText(eintragListe.at(2).trimmed());
    ui->EdtGehalt->setText(eintragListe.at(3).trimmed());
    ui->DatGeburtstag->setDate(QDate::fromString(eintragListe.at(4).trimmed(), "dd.MM.yyyy"));
}

void MainWindow::CmdAendernClicked()
{
    if(ui->LstAnzeige->currentRow() == -1)
    {
        QMessageBox mb;
        mb.setText("Bitte Eintrag markieren");
        mb.exec();
        return;
    }

    QString eintragText = ui->LstAnzeige->currentItem()->text();
    QStringList eintragListe = eintragText.split("#");
    QString eintragPnr = eintragListe.at(2).trimmed();

    sqlBefehl.prepare("UPDATE personen SET name=?, "
        "vorname=?, personalnummer=?, gehalt=?, "
        "geburtstag=? WHERE personalnummer=" + eintragPnr);
    sqlBefehl.addBindValue(ui->EdtName->text());
    sqlBefehl.addBindValue(ui->EdtVorname->text());
    sqlBefehl.addBindValue(ui->EdtPersonalnummer->text().toInt());
    sqlBefehl.addBindValue(ui->EdtGehalt->text().toDouble());
    sqlBefehl.addBindValue(ui->DatGeburtstag->
        date().toString("dd.MM.yyyy"));
    sqlBefehl.exec();
    if(FehlerAnzeige())
        return;
    AlleSehen();
}

void MainWindow::CmdLoeschenClicked()
{
    if(ui->LstAnzeige->currentRow() == -1)
    {
        QMessageBox mb;
        mb.setText("Bitte Eintrag markieren");
        mb.exec();
        return;
    }

    QString eintragText = ui->LstAnzeige->currentItem()->text();
    QStringList eintragListe = eintragText.split("#");
    QString eintragPnr = eintragListe.at(2).trimmed();

    QMessageBox mb;
    mb.setText("Datensatz mit Personalnummer "
        + eintragPnr + " löschen?");
    mb.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    mb.setButtonText(QMessageBox::Yes, "Ja");
    mb.setButtonText(QMessageBox::No, "Nein");
    mb.setDefaultButton(QMessageBox::No);
    if(mb.exec() == QMessageBox::No)
        return;

    sqlBefehl.exec("DELETE FROM personen "
        "WHERE personalnummer=" + eintragPnr);
    AlleSehen();
}

void MainWindow::CmdFilternClicked()
{
    ui->LstAnzeige->clear();
    QString sqlCode = "SELECT * FROM personen WHERE 1=1";

    if(ui->EdtName->text() != "")
        sqlCode += " AND name LIKE ?";
    if(ui->EdtVorname->text() != "")
        sqlCode += " AND vorname LIKE ?";
    if(ui->EdtPersonalnummer->text() != "")
        sqlCode += " AND personalnummer = ?";
    if(ui->EdtGehalt->text() != "")
        sqlCode += " AND gehalt >= ? AND gehalt <= ?";
    sqlBefehl.prepare(sqlCode);

    if(ui->EdtName->text() != "")
        sqlBefehl.addBindValue("%" + ui->EdtName->text() + "%");
    if(ui->EdtVorname->text() != "")
        sqlBefehl.addBindValue("%" + ui->EdtVorname->text() + "%");
    if(ui->EdtPersonalnummer->text() != "")
        sqlBefehl.addBindValue(ui->EdtPersonalnummer->text().toInt());
    if(ui->EdtGehalt->text() != "")
    {
        sqlBefehl.addBindValue(ui->EdtGehalt->text().toDouble() * 0.9);
        sqlBefehl.addBindValue(ui->EdtGehalt->text().toDouble() * 1.1);
    }

    sqlBefehl.exec();
    FehlerAnzeige();
    while(sqlBefehl.next())
    {
        QString ausgabe;
        for(int i=0; i<5; i++)
            ausgabe += sqlBefehl.value(i).toString() + " # ";
        ui->LstAnzeige->addItem(ausgabe);
    }
}
