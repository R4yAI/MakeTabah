#include "addrsrcdialog.h"
#include "ui_addrsrcdialog.h"
#include <QDebug>


AddRsrcDialog::AddRsrcDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRsrcDialog)
{
    ui->setupUi(this);
    // connect(ui->btnAddRsrc, &QPushButton::clicked, this, &AddRsrcDialog::on_btnAddRsrc_clicked);


}

AddRsrcDialog::~AddRsrcDialog()
{
    delete ui;
}

void AddRsrcDialog::on_btnAddRsrc_clicked()
{
    QString title = ui->txtBookTitle->text();
    QString author = ui->txtBookAuthor->text();
    int pages = ui->spinBookPages->value();
    QString category = ui->comboBoxCategory->currentText();
    // QString year = ui->dateEditBookPY->text();
    QString edition = ui->txtEDH->text();
    int availability = ui->checkBoxAvailable->isChecked() ? 1 : 0;


    // qDebug() << "Title : "<< title << "Author : "<<author << "Edition House : " << edition;


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

    QSqlQuery query(database);

    query.prepare("INSERT INTO Books (Title, Author, Pages, Category, PublishingYear, EditionHouse, Availability) "
                  "VALUES (:title, :author, :pages, :category, :year, :edition, :availability)");
    query.bindValue(":title", title);
    query.bindValue(":author", author);
    query.bindValue(":pages", pages);
    query.bindValue(":category", category);
    // query.bindValue(":year", year);
    query.bindValue(":edition", edition);
    query.bindValue(":availability", availability);

    if (!query.exec()) {
        qDebug() << "Insert error: " << query.lastError().text();
    } else {
        qDebug() << "Book inserted successfully!";
    }

    // bookModel->select(); // Refresh the data


}


void AddRsrcDialog::on_btnResetRsrc_clicked()
{
    ui->txtBookTitle->clear();
    ui->txtBookAuthor->clear();
    ui->spinBookPages->setValue(0);
    ui->comboBoxCategory->setCurrentIndex(0);
    ui->txtEDH->clear();
    ui->checkBoxAvailable->setChecked(false);
}

