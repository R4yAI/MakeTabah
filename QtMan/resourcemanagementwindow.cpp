#include "resourcemanagementwindow.h"
#include "ui_resourcemanagementwindow.h"

#include<QMessageBox>

ResourceManagementWindow::ResourceManagementWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ResourceManagementWindow)
{
    ui->setupUi(this);

    connect(ui->btnAddRsrc, &QRadioButton::toggled, this, &ResourceManagementWindow::on_btnAddRsrc_clicked);
    ptrAddRsrcDialog = new AddRsrcDialog();


}

ResourceManagementWindow::~ResourceManagementWindow()
{
    delete ptrAddRsrcDialog;
    delete ui;
}




void ResourceManagementWindow::on_btnAddRsrc_clicked()
{
    ptrAddRsrcDialog->show();
}


void ResourceManagementWindow::on_btnApplyRsrc_clicked()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/home/romeo-alpha/School/OOP/MakeTabah/QtMan/Database/resources.db");

    if(QFile::exists("/home/romeo-alpha/School/OOP/MakeTabah/QtMan/Database/resources.db")){
        qDebug() << "database exists";
    }
    else{
        qDebug() << "database doesn't exist"<<database.lastError().text();
        return;
    }

    if(!database.open()){
        qDebug() << "failed to open database"<<database.lastError().text();
        return;
    }
    else
    {
        qDebug() << "Database opened successfully..";
    }

    bookModel = new QSqlTableModel(this, database);
    bookModel->setTable("Books");
    bookModel->select();

    bookModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    ui->tableView->setModel(bookModel);

    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);


}


void ResourceManagementWindow::on_btnDelete_clicked()
{
    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    bookModel = new QSqlTableModel(this, database);
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Delete Book", "Please select a book to delete.");
        return;
    }

    int row = selected.first().row();

    if (QMessageBox::question(this, "Confirm Delete", "Are you sure you want to delete this book?") == QMessageBox::Yes) {
        if (!bookModel->removeRow(row)) {
            QMessageBox::critical(this, "Delete Failed", "Could not remove the row from the bookModel.");
            return;
        }

        if (!bookModel->submitAll()) {
            QMessageBox::critical(this, "Database Error", bookModel->lastError().text());
            bookModel->revertAll();
        } else {
            QMessageBox::information(this, "Deleted", "Book deleted successfully.");
        }
    }
}

