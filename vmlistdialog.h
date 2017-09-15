#ifndef VMLISTDIALOG_H
#define VMLISTDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QDesktopWidget>
#include <QDebug>
#include <QTableView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "autosize.h"
#include <QStandardItemModel>
#include "customtableview.h"
#include "vmdata.h"

#define BASE_WIDTH  1920
#define BASE_HEIGHT 1080

#define WIDGETUSER_HORIZONTAL_OFFSET    500
#define WIDGETUSER_VERTICAL_OFFSET  30

#define BTN_EXIT_HORIZONTAL_OFFSET  100
#define BTN_EXIT_VERTICAL_OFFSET    25

#define BTN_SHUTDOWN_HORIZONTAL_OFFSET  50
#define BTN_SHUTDOWN_VERTICAL_OFFSET    25

#define LIST_VMLIST_HORIZONTAL_OFFSET   0
#define LIST_VMLIST_VERTICAL_OFFSET     80
#define LIST_VMLIST_SIZE_HORIZONTAL_OFFSET  430
#define LIST_VMLIST_SIZE_VERTICAL_OFFSET    80

#define BTN_RUN_HORIZONTAL_OFFSET   20
#define BTN_RUN_VERTICAL_OFFSET 20

#define LAB_RUN_HORIZONTAL_OFFSET   45
#define LAB_RUN_VERTICAL_OFFSET 25

#define BTN_CLOSE_HORIZONTAL_OFFSET 85
#define BTN_CLOEE_VERTICAL_OFFSET   22

#define LAB_CLOSE_HORIZONTAL_OFFSET 110
#define LAB_CLOSE_VERTICAL_OFFSET   25

#define BTN_REBOOT_HORIZONTAL_OFFSET    155
#define BTN_REBOOT_VERTICAL_OFFSET  20

#define LAB_REBOOT_HORIZONTAL_OFFSET    185
#define LAB_REBOOT_VERTICAL_OFFSET  25

#define BTN_DESKTOP_HORIZONTAL_OFFSET   235
#define BTN_DESKTOP_VERTICAL_OFFSET 20

#define LAB_DESKTOP_HORIZONTAL_OFFSET   270
#define LAB_DESKTOP_VERTICAL_OFFSET 25

#define BTN_REFRESH_HORIZONTAL_OFFSET   330
#define BTN_REFRESH_VERTICAL_OFFSET 20

#define LAB_REFRESH_HORIZONTAL_OFFSET   365
#define LAB_REFRESH_VERTICAL_OFFSET     25

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
    enum ColumnIndex{
        COLUMN_0 = 0,
        COLUMN_1,
        COLUMN_2,
        COLUMN_3,
        COLUMN_4,
        COLUMN_5,
        COLUMN_6,
        COLUMN_7,
        MAX_CULUMN_SIZE,
    };
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
    QTableView * tablev_vmList;
    QWidget * widget;
    QStandardItemModel * model;
    QList<VmData> vmList;
    int width;
    int height;
    void UIInit();
    void VmListInit();
    void TabViewModelInit();
    void TabViewInit();
public slots:
    void slot_GetVmList(QList<VmData> vmList);
};

#endif // VMLISTDIALOG_H
