#ifndef VMLISTDIALOG_H
#define VMLISTDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QDesktopWidget>
#include <QDebug>
#include <QListView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace Ui {
class VmListDialog;
}

class VmListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VmListDialog(QWidget *parent = 0);
    ~VmListDialog();

private:
    Ui::VmListDialog *ui;
    QLabel * lab_CurrenLoginUser;
    QLabel * lab_user;
    QLabel * lab_run;
    QLabel * lab_close;
    QLabel * lab_reboot;
    QLabel * lab_desktop;
    QLabel * lab_refresh;
    QPushButton * btn_run;
    QPushButton * btn_close;
    QPushButton * btn_reboot;
    QPushButton * btn_desktop;
    QPushButton * btn_refresh;
    QPushButton * btn_exit;
    QPushButton * btn_shutDown;
    QListView * lisv_vmList;
    QWidget * widget;
    int width;
    int height;
    void UIInit();
    void AutoSize(QWidget *widget, int screenWidth, int screenHeight, int baseWidth, int baseHeight);
    void AutoSize(QWidget *widget, int screenWidth, int screenHeight);
    void AutoMove(QWidget *widget, int screenWidth, int screenHeight);
    void AutoMove(QWidget *widget, int screenWidth, int screenHeight, int baseWidth , int baseHeight);
};

#endif // VMLISTDIALOG_H
