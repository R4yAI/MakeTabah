#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "resourcemanagementwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_RsrcManWinBtn_3_clicked();

private:
    Ui::MainWindow *ui;
    ResourceManagementWindow * ptrRsrcManWin;
};
#endif // MAINWINDOW_H
