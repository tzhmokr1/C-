#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    con = QSqlDatabase::addDatabase("QSQLITE");
    con.setDatabaseName("projektverwaltung.db");
    if(!con.open())
    {
        ui->LstAusgabe->addItem("DB nicht geöffnet");
        return;
    }
    sqlBefehl = QSqlQuery(con);

    connect(ui->CmdEinfuegen, SIGNAL(clicked()),
            SLOT(CmdEinfuegenClicked()));
    connect(ui->CmdAuswahl, SIGNAL(clicked()),
            SLOT(CmdAuswahlClicked()));
}

MainWindow::~MainWindow()
{
    con.close();
    delete ui;
}

void MainWindow::CmdEinfuegenClicked()
{
    ui->LstAusgabe->clear();

    sqlBefehl.exec("CREATE TABLE kunde(ku_id INTEGER PRIMARY KEY, ku_name TEXT, ku_ort TEXT)");
    FehlerAnzeige();
    sqlBefehl.exec("INSERT INTO kunde VALUES"
                   "(1, 'Schmidt', 'Hamburg'),"
                   "(2, 'Weber', 'Frankfurt'),"
                   "(3, 'Murchel', 'Dortmund')");
    FehlerAnzeige();

    sqlBefehl.exec("CREATE TABLE projekt(pr_id INTEGER PRIMARY KEY, pr_ku_id INTEGER, pr_bezeichnung TEXT)");
    FehlerAnzeige();
    sqlBefehl.exec("INSERT INTO projekt VALUES"
                   "(1, 1, 'Alexanderstrasse'),"
                   "(2, 1, 'Peterstrasse'),"
                   "(3, 2, 'Jahnplatz'),"
                   "(4, 2, 'Lindenplatz'),"
                   "(5, 3, 'Nordbahnhof'),"
                   "(6, 3, 'Westbahnhof')");
    FehlerAnzeige();

    sqlBefehl.exec("CREATE TABLE mitarbeiter(mi_id INTEGER PRIMARY KEY, mi_nachname TEXT, mi_vorname TEXT)");
    FehlerAnzeige();
    sqlBefehl.exec("INSERT INTO mitarbeiter VALUES"
                   "(1, 'Mohr', 'Hans'),"
                   "(2, 'Berger', 'Stefan'),"
                   "(3, 'Suhren', 'Marion')");
    FehlerAnzeige();

    sqlBefehl.exec("CREATE TABLE projekt_mitarbeiter(pm_id INTEGER PRIMARY KEY, pm_pr_id INTEGER, pm_mi_id INTEGER, pm_datum TEXT, pm_zeit REAL)");
    FehlerAnzeige();
    sqlBefehl.exec("INSERT INTO projekt_mitarbeiter VALUES"
                   "(1, 1, 1, '01.08.2017', 3.5),"
                   "(2, 1, 3, '01.08.2017', 4),"
                   "(3, 4, 1, '01.08.2017', 3),"
                   "(4, 4, 2, '01.08.2017', 6.5),"
                   "(5, 4, 2, '02.08.2017', 7.3),"
                   "(6, 4, 3, '02.08.2017', 4)");
    FehlerAnzeige();
}

void MainWindow::FehlerAnzeige()
{
    QSqlError fehler = sqlBefehl.lastError();
    if(fehler.isValid())
        ui->LstAusgabe->addItem(
            "Fehler: " + fehler.databaseText());
}

void MainWindow::CmdAuswahlClicked()
{
    ui->LstAusgabe->clear();

    ui->LstAusgabe->addItem("Alle Kunden:");
    sqlBefehl.exec("SELECT * FROM kunde");
    FehlerAnzeige();
    Ausgabe(3);

    ui->LstAusgabe->addItem("");
    ui->LstAusgabe->addItem("Alle Projekte:");
    sqlBefehl.exec("SELECT * FROM projekt");
    FehlerAnzeige();
    Ausgabe(3);

    ui->LstAusgabe->addItem("");
    ui->LstAusgabe->addItem("Alle Mitarbeiter:");
    sqlBefehl.exec("SELECT * FROM mitarbeiter");
    FehlerAnzeige();
    Ausgabe(3);

    ui->LstAusgabe->addItem("");
    ui->LstAusgabe->addItem("Alle Arbeitseinsätze:");
    sqlBefehl.exec("SELECT * FROM projekt_mitarbeiter");
    FehlerAnzeige();
    Ausgabe(5);

    ui->LstAusgabe->addItem("");
    ui->LstAusgabe->addItem("Anzahl der Kunden:");
    sqlBefehl.exec("SELECT COUNT(ku_id) AS count_ku_id FROM kunde");
    FehlerAnzeige();
    Ausgabe(1);

    ui->LstAusgabe->addItem("");
    ui->LstAusgabe->addItem("Alle Kunden mit allen Projekten:");
    sqlBefehl.exec("SELECT ku_name, ku_ort, pr_bezeichnung"
                   " FROM kunde INNER JOIN projekt ON kunde.ku_id = projekt.pr_ku_id"
                   " ORDER BY ku_name, ku_ort, pr_bezeichnung");
    FehlerAnzeige();
    Ausgabe(3);

    ui->LstAusgabe->addItem("");
    ui->LstAusgabe->addItem("Alle Mitarbeiter mit allen Projektzeiten:");
    sqlBefehl.exec("SELECT mi_nachname, pr_bezeichnung, pm_datum, pm_zeit"
                   " FROM projekt INNER JOIN(mitarbeiter INNER JOIN projekt_mitarbeiter"
                   "    ON mitarbeiter.mi_id = projekt_mitarbeiter.pm_mi_id)"
                   "    ON projekt.pr_id = projekt_mitarbeiter.pm_pr_id"
                   " ORDER BY mi_nachname, pr_bezeichnung, pm_datum");
    FehlerAnzeige();
    Ausgabe(4);

    ui->LstAusgabe->addItem("");
    ui->LstAusgabe->addItem("Alle Mitarbeiter mit Zeitsumme:");
    sqlBefehl.exec("SELECT mi_nachname, SUM(pm_zeit) AS sum_pm_zeit"
                   " FROM mitarbeiter INNER JOIN projekt_mitarbeiter"
                   "    ON mitarbeiter.mi_id = projekt_mitarbeiter.pm_mi_id"
                   " GROUP BY mitarbeiter.mi_id"
                   " ORDER BY mi_nachname");
    FehlerAnzeige();
    Ausgabe(2);
}

void MainWindow::Ausgabe(int feldAnzahl)
{
    QString ausgabe;
    while(sqlBefehl.next())
    {
        ausgabe = "";
        for(int i=0; i<feldAnzahl; i++)
            ausgabe += sqlBefehl.value(i).toString() + " # ";
        ui->LstAusgabe->addItem(ausgabe);
    }
}
