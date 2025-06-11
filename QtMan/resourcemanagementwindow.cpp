#include "resourcemanagementwindow.h"
#include "ui_resourcemanagementwindow.h"

ResourceManagementWindow::ResourceManagementWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ResourceManagementWindow)
{
    ui->setupUi(this);

    ptrAddRsrcDialog = new AddRsrcDialog();


}

ResourceManagementWindow::~ResourceManagementWindow()
{
    delete ptrAddRsrcDialog;
    delete ui;
}


