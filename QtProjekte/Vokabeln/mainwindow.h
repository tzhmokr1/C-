#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSqlDatabase con;
    QSqlQuery sqlBefehl;
    int richtung;
    QVector<QString> frage;
    QVector<QString> antwort;
    int zufallszahl;
    QVector<int> idFeld;

private slots:
    void AuswahlInit();
    void TestInit();
    void FehlerAnzeige();
    void NaechsteVokabel();
    void TabelleAnzeigen();

    void CmbRichtungCurrentIndexChanged(int);
    void LstDeuItemSelectionChanged();

    void CmdTestStartenClicked();
    void CmdPruefenClicked();
    void CmdTestBeendenClicked();
    void CmdNeuEingabeStartenClicked();
    void CmdNeuEingabeSpeichernClicked();
    void CmdAuswahlLoeschenClicked();
    void CmdNeuEingabeBeendenClicked();
};

#endif // MAINWINDOW_H
