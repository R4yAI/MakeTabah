#include "addrsrcdialog.h"
#include "ui_addrsrcdialog.h"

AddRsrcDialog::AddRsrcDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRsrcDialog)
{
    ui->setupUi(this);
}

AddRsrcDialog::~AddRsrcDialog()
{
    delete ui;
}
