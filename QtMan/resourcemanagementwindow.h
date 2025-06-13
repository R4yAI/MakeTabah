#ifndef RESOURCEMANAGEMENTWINDOW_H
#define RESOURCEMANAGEMENTWINDOW_H

#include <QWidget>
#include "addrsrcdialog.h"
#include <QtSql/QSqlTableModel>

namespace Ui {
class ResourceManagementWindow;
}

class ResourceManagementWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ResourceManagementWindow(QWidget *parent = nullptr);
    ~ResourceManagementWindow();

private slots:




    void on_btnAddRsrc_clicked();

    void on_btnApplyRsrc_clicked();

    void on_btnDelete_clicked();

private:
    Ui::ResourceManagementWindow *ui;
    AddRsrcDialog * ptrAddRsrcDialog;
    QSqlTableModel * bookModel;
    QSqlDatabase database ;
};

#endif // RESOURCEMANAGEMENTWINDOW_H
