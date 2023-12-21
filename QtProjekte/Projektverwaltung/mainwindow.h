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

private slots:
    void CmdEinfuegenClicked();
    void FehlerAnzeige();
    void CmdAuswahlClicked();
    void Ausgabe(int);
};

#endif // MAINWINDOW_H
