#ifndef ADDRSRCDIALOG_H
#define ADDRSRCDIALOG_H

#include <QDialog>

namespace Ui {
class AddRsrcDialog;
}

class AddRsrcDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRsrcDialog(QWidget *parent = nullptr);
    ~AddRsrcDialog();

private:
    Ui::AddRsrcDialog *ui;
};

#endif // ADDRSRCDIALOG_H
