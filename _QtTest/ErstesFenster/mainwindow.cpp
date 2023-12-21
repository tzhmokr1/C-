#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->CmdHallo, SIGNAL(clicked()),
        SLOT(CmdHalloClicked()) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CmdHalloClicked()
{
    ui->lblAnzeige->setText("Hallo");
}
