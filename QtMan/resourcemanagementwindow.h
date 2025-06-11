#ifndef RESOURCEMANAGEMENTWINDOW_H
#define RESOURCEMANAGEMENTWINDOW_H

#include <QWidget>
#include "addrsrcdialog.h"

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


private:
    Ui::ResourceManagementWindow *ui;
    AddRsrcDialog * ptrAddRsrcDialog;
};

#endif // RESOURCEMANAGEMENTWINDOW_H
