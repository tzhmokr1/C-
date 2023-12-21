#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    con = QSqlDatabase::addDatabase("QSQLITE");
    con.setDatabaseName("firma.db");
    if(!con.open())
    {
        ui->LstAusgabe->addItem("DB nicht geöffnet");
        return;
    }
    sqlBefehl = QSqlQuery(con);

    connect(ui->CmdEinfuegen, SIGNAL(clicked()),
            SLOT(CmdEinfuegenClicked()));
    connect(ui->CmdAnzeigenAlle, SIGNAL(clicked()),
            SLOT(CmdAnzeigenAlleClicked()));
    connect(ui->CmdAuswahl, SIGNAL(clicked()),
            SLOT(CmdAuswahlClicked()));
    connect(ui->CmdEingabe, SIGNAL(clicked()),
            SLOT(CmdEingabeClicked()));
    connect(ui->CmdAktion, SIGNAL(clicked()),
            SLOT(CmdAktionClicked()));
}

MainWindow::~MainWindow()
{
    con.close();
    delete ui;
}

void MainWindow::CmdEinfuegenClicked()
{
    ui->LstAusgabe->clear();
    sqlBefehl.exec("CREATE TABLE personen("
                   "name TEXT, "
                   "vorname TEXT, "
                   "personalnummer INTEGER PRIMARY KEY, "
                   "gehalt REAL, "
                   "geburtstag TEXT)");
    FehlerAnzeige();

    sqlBefehl.exec("INSERT INTO personen VALUES("
        "'Maier', 'Hans', 6714, 3500, '15.03.1962')");
    FehlerAnzeige();

    sqlBefehl.exec("INSERT INTO personen VALUES("
        "'Schmitz', 'Peter', 81343, 3750, '12.04.1958')");
    FehlerAnzeige();

    sqlBefehl.exec("INSERT INTO personen VALUES("
        "'Mertens', 'Julia', 2297, 3621.5, '30.12.1959')");
    FehlerAnzeige();
}

void MainWindow::FehlerAnzeige()
{
    QSqlError fehler = sqlBefehl.lastError();
    if(fehler.isValid())
        ui->LstAusgabe->addItem(
            "Fehler: " + fehler.databaseText());
}

void MainWindow::CmdAnzeigenAlleClicked()
{
    ui->LstAusgabe->clear();
    sqlBefehl.exec("SELECT * FROM personen");
    FehlerAnzeige();
    Ausgabe(5);
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

void MainWindow::CmdAuswahlClicked()
{
    ui->LstAusgabe->clear();
    // sqlBefehl.exec("SELECT personalnummer, name FROM personen");
    // sqlBefehl.exec("SELECT * FROM personen WHERE gehalt > 3600");
    // sqlBefehl.exec("SELECT * FROM personen WHERE name <> 'Schmitz'");
    // sqlBefehl.exec("SELECT * FROM personen WHERE gehalt >= 3600 AND gehalt <= 3650");
    // sqlBefehl.exec("SELECT * FROM personen WHERE name LIKE 'm%'");
    // sqlBefehl.exec("SELECT * FROM personen WHERE name LIKE '%i%'");
    // sqlBefehl.exec("SELECT * FROM personen WHERE name LIKE 'm__er'");
    // sqlBefehl.exec("SELECT * FROM personen ORDER BY gehalt DESC");
    sqlBefehl.exec("SELECT * FROM personen ORDER BY name, vorname");
    FehlerAnzeige();
    Ausgabe(5);
}

void MainWindow::CmdEingabeClicked()
{
    ui->LstAusgabe->clear();
    sqlBefehl.prepare("SELECT * FROM personen WHERE name LIKE ?");
    // sqlBefehl.addBindValue(ui->EdtEingabe->text());
    sqlBefehl.addBindValue("%" + ui->EdtEingabe->text() + "%");
    sqlBefehl.exec();
    FehlerAnzeige();
    Ausgabe(5);
}

void MainWindow::CmdAktionClicked()
{
    ui->LstAusgabe->clear();
    /* sqlBefehl.exec("UPDATE personen SET gehalt = gehalt / 1.1 "
        "WHERE personalnummer = 6714"); */
    sqlBefehl.exec("DELETE FROM personen WHERE personalnummer = 1234");
    FehlerAnzeige();
    ui->LstAusgabe->addItem(QString("Betroffen: %1").
        arg(sqlBefehl.numRowsAffected()));
}
