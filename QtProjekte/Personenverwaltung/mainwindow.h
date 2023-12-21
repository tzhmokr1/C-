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
    bool FehlerAnzeige();
    void AlleSehen();
    void CmdAlleSehenClicked();
    void CmdEinfuegenClicked();
    void LstAnzeigeSelectionChanged();
    void CmdAendernClicked();
    void CmdLoeschenClicked();
    void CmdFilternClicked();
};

#endif // MAINWINDOW_H
