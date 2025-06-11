#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QLabel>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrRsrcManWin = new ResourceManagementWindow();
    ui->stackedWidget->addWidget(ptrRsrcManWin);

}

MainWindow::~MainWindow()
{

    delete ui;
}











void MainWindow::on_RsrcManWinBtn_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ptrRsrcManWin);
}

