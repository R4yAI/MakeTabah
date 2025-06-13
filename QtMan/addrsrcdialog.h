#ifndef ADDRSRCDIALOG_H
#define ADDRSRCDIALOG_H

#include <QDialog>
#include "db_includes.h"

namespace Ui {
class AddRsrcDialog;
}

class AddRsrcDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRsrcDialog(QWidget *parent = nullptr);
    ~AddRsrcDialog();

private slots:
    void on_btnAddRsrc_clicked();

    void on_btnResetRsrc_clicked();

private:
    Ui::AddRsrcDialog *ui;
    QSqlDatabase database ;
};

#endif // ADDRSRCDIALOG_H
