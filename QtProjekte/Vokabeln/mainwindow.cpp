#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand((unsigned)time(NULL));

    // Datenbankverbindung erstellen
    con = QSqlDatabase::addDatabase("QSQLITE");
    con.setDatabaseName("vokabeln.db");
    if(!con.open())
    {
        ui->LblFrage->setText("DB nicht geöffnet");
        return;
    }
    sqlBefehl = QSqlQuery(con);

    // Datenbank erzeugen und füllen
    sqlBefehl.exec("CREATE TABLE vokabeln"
        "(id INTEGER PRIMARY KEY, deu TEXT, eng TEXT, fra TEXT)");
    sqlBefehl.exec("INSERT INTO vokabeln VALUES"
        "(1, 'Bedingung', 'condition', 'condition'),"
        "(2, 'suchen', 'to look for', 'chercher'),"
        "(3, 'Werbeanzeige', 'advertisement', 'publicité'),"
        "(4, 'abkürzen', 'to abbreviate', 'raccourcir'),"
        "(5, 'nützlich', 'useful', 'utile'),"
        "(6, 'Wirkung', 'effect', 'effet'),"
        "(7, 'beraten', 'to advise', 'conseiller'),"
        "(8, 'übersetzen', 'to translate', 'traduire'),"
        "(9, 'einfach', 'easy', 'simple'),"
        "(10, 'ankündigen', 'to announce', 'annoncer')");

    // Schaltflächen verbinden
    connect(ui->CmdTestStarten, SIGNAL(clicked()),
            SLOT(CmdTestStartenClicked()));
    connect(ui->CmdPruefen, SIGNAL(clicked()),
            SLOT(CmdPruefenClicked()));
    connect(ui->CmdTestBeenden, SIGNAL(clicked()),
            SLOT(CmdTestBeendenClicked()));
    connect(ui->CmdNeuEingabeStarten, SIGNAL(clicked()),
            SLOT(CmdNeuEingabeStartenClicked()));
    connect(ui->CmdNeuEingabeSpeichern, SIGNAL(clicked()),
            SLOT(CmdNeuEingabeSpeichernClicked()));
    connect(ui->CmdAuswahlLoeschen, SIGNAL(clicked()),
            SLOT(CmdAuswahlLoeschenClicked()));
    connect(ui->CmdNeuEingabeBeenden, SIGNAL(clicked()),
            SLOT(CmdNeuEingabeBeendenClicked()));

    // Combo Box Widget und List Widget verbinden
    connect(ui->CmbRichtung, SIGNAL(currentIndexChanged(int)),
            SLOT(CmbRichtungCurrentIndexChanged(int)));
    connect(ui->LstDeu, SIGNAL(itemSelectionChanged()),
            SLOT(LstDeuItemSelectionChanged()));

    // Combo Box Widget füllen
    ui->CmbRichtung->addItem("(Sprachauswahl treffen)");
    ui->CmbRichtung->addItem("Deutsch - Englisch");
    ui->CmbRichtung->addItem("Englisch - Deutsch");
    ui->CmbRichtung->addItem("Deutsch - Französisch");
    ui->CmbRichtung->addItem("Französisch - Deutsch");
    ui->CmbRichtung->addItem("Englisch - Französisch");
    ui->CmbRichtung->addItem("Französisch - Englisch");

    // Anfangszustand einstellen
    this->resize(330, 165);
    this->setWindowTitle("Vokabeln");
    AuswahlInit();
}

MainWindow::~MainWindow()
{
    con.close();
    delete ui;
}

void MainWindow::AuswahlInit()
{
    // Umschalten in Auswahlmodus
    ui->CmbRichtung->setEnabled(true);
    ui->CmbRichtung->setCurrentIndex(0);
    ui->CmdTestStarten->setEnabled(false);
    ui->CmdTestBeenden->setEnabled(false);
    ui->LblFrage->clear();
    ui->EdtAntwort->setEnabled(false);
    ui->CmdPruefen->setEnabled(false);
    ui->CmdNeuEingabeStarten->setEnabled(true);
}

void MainWindow::TestInit()
{
    // Vorbereiten des Testmodus
    ui->CmbRichtung->setEnabled(false);
    ui->CmdTestStarten->setEnabled(true);
    ui->CmdTestBeenden->setEnabled(true);
    ui->CmdNeuEingabeStarten->setEnabled(false);
}

void MainWindow::CmbRichtungCurrentIndexChanged(int index)
{
    // Falls Sprachauswahl getroffen
    if(index != 0)
    {
        // Vorbereiten des Testmodus
        TestInit();

        // Datensätze der ausgewählten Felder holen
        QString sqlCode;
        if(index == 1)
            sqlCode = "SELECT deu, eng FROM vokabeln";
        else if(index == 2)
            sqlCode = "SELECT eng, deu FROM vokabeln";
        else if(index == 3)
            sqlCode = "SELECT deu, fra FROM vokabeln";
        else if(index == 4)
            sqlCode = "SELECT fra, deu FROM vokabeln";
        else if(index == 5)
            sqlCode = "SELECT eng, fra FROM vokabeln";
        else if(index == 6)
            sqlCode = "SELECT fra, eng FROM vokabeln";
        sqlBefehl.exec(sqlCode);
        FehlerAnzeige();

        // QVector-Objekte leeren, mit Datensätzen füllen
        frage.clear();
        antwort.clear();
        while(sqlBefehl.next())
        {
            frage.append(sqlBefehl.value(0).toString());
            antwort.append(sqlBefehl.value(1).toString());
        }
    }
}

void MainWindow::FehlerAnzeige()
{
    QSqlError fehler = sqlBefehl.lastError();
    if(fehler.isValid())
        ui->LblFrage->setText("Fehler: "
            + fehler.databaseText());
}

void MainWindow::CmdTestStartenClicked()
{
    // Umschalten in Testmodus
    ui->CmdTestStarten->setEnabled(false);
    ui->EdtAntwort->setEnabled(true);
    ui->CmdPruefen->setEnabled(true);
    NaechsteVokabel();
}

void MainWindow::NaechsteVokabel()
{
    // Falls alle Vokabeln geschafft
    if(frage.count() < 1)
    {
        QMessageBox mb;
        mb.setText("Gratuliere! Alles geschafft.");
        mb.exec();

        AuswahlInit();
    }

    // Nächste Vokabel auswählen und anzeigen
    else
    {
        zufallszahl = rand() % frage.count();
        ui->LblFrage->setText(frage.at(zufallszahl));
    }
}

void MainWindow::CmdPruefenClicked()
{
    // Antwort prüfen
    QString kommentar;
    if(ui->EdtAntwort->text() == antwort.at(zufallszahl))
    {
        kommentar = "Richtig: " + frage.at(zufallszahl)
                + " = " + antwort.at(zufallszahl);
        frage.remove(zufallszahl);
        antwort.remove(zufallszahl);
    }
    else
        kommentar = "Falsch: " + frage.at(zufallszahl)
                + " = " + antwort.at(zufallszahl);

    // Kommentar anzeigen
    QMessageBox mb;
    mb.setText(kommentar);
    mb.exec();

    // Eingabe löschen, nächste Vokabel
    ui->EdtAntwort->clear();
    NaechsteVokabel();
}

void MainWindow::CmdTestBeendenClicked()
{
    QMessageBox mb;
    mb.setText("Test beenden?");
    mb.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    mb.setButtonText(QMessageBox::Yes, "Ja");
    mb.setButtonText(QMessageBox::No, "Nein");
    mb.setDefaultButton(QMessageBox::No);
    if(mb.exec() == QMessageBox::Yes)
        AuswahlInit();
}

void MainWindow::CmdNeuEingabeStartenClicked()
{
    // Anwendungsfenster vergrößern, List Widgets füllen
    ui->CmbRichtung->setEnabled(false);
    ui->CmdNeuEingabeStarten->setEnabled(false);
    this->resize(490, 420);
    TabelleAnzeigen();
}

void MainWindow::TabelleAnzeigen()
{
    // Alle Datensätze holen
    sqlBefehl.exec("SELECT * FROM vokabeln ORDER BY deu");
    FehlerAnzeige();

    // QVector und List Widgets löschen
    idFeld.clear();
    ui->LstDeu->clear();
    ui->LstEng->clear();
    ui->LstFra->clear();

    // QVector und List Widgets füllen
    while(sqlBefehl.next())
    {
        idFeld.append(sqlBefehl.value(0).toInt());
        ui->LstDeu->addItem(sqlBefehl.value(1).toString());
        ui->LstEng->addItem(sqlBefehl.value(2).toString());
        ui->LstFra->addItem(sqlBefehl.value(3).toString());
    }
}

void MainWindow::LstDeuItemSelectionChanged()
{
    int nummer = ui->LstDeu->currentRow();
    ui->LstEng->setCurrentRow(nummer);
    ui->LstFra->setCurrentRow(nummer);
}

void MainWindow::CmdNeuEingabeSpeichernClicked()
{
    // Alle Eingabefelder gefüllt?
    if(ui->EdtDeu->text() == "" ||
       ui->EdtEng->text() == "" ||
       ui->EdtFra->text() == "")
    {
        QMessageBox mb;
        mb.setText("Alle drei Eingabefelder füllen");
        mb.exec();
        return;
    }

    // Nächste freie ID suchen
    sqlBefehl.exec("SELECT * FROM vokabeln"
        " ORDER BY id DESC LIMIT 1");
    FehlerAnzeige();
    sqlBefehl.next();
    int idNeu = sqlBefehl.value(0).toInt() + 1;

    // Datensatz einfügen
    sqlBefehl.exec("INSERT INTO vokabeln VALUES("
        + QString::number(idNeu) + ", '"
        + ui->EdtDeu->text() + "', '"
        + ui->EdtEng->text() + "', '"
        + ui->EdtFra->text() + "')");
    FehlerAnzeige();

    // Eingabefelder löschen, List Widgets neu füllen
    ui->EdtDeu->clear();
    ui->EdtEng->clear();
    ui->EdtFra->clear();
    TabelleAnzeigen();
}

void MainWindow::CmdAuswahlLoeschenClicked()
{
    // ID ermitteln
    int zeile = ui->LstDeu->currentRow();
    if(zeile == -1)
    {
        QMessageBox mb;
        mb.setText("Eintrag zum Löschen markieren");
        mb.exec();
        return;
    }
    int id = idFeld.at(zeile);

    // Datensatz löschen, List Widgets neu füllen
    sqlBefehl.exec("DELETE FROM vokabeln WHERE id = "
                   + QString::number(id));
    FehlerAnzeige();
    TabelleAnzeigen();
}

void MainWindow::CmdNeuEingabeBeendenClicked()
{
    // Anwendungsfenster verkleinern
    this->resize(330, 165);
    ui->CmbRichtung->setEnabled(true);
    ui->CmdNeuEingabeStarten->setEnabled(true);
}
