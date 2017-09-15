#include "vmlistdialog.h"
#include "ui_vmlistdialog.h"

VmListDialog::VmListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VmListDialog)
{
    ui->setupUi(this);

    UIInit();
}

VmListDialog::~VmListDialog()
{
    delete ui;
}

void VmListDialog::UIInit()
{
    //qDebug()<<this->width()<<this->height();
    QDesktopWidget * desktop = QApplication::desktop();
    this->resize(desktop->width(), desktop->height());
    this->setWindowFlags(Qt::FramelessWindowHint);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QImage(":/image/vmlistwindow_sh.png").scaled(this->size())));
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    QPalette fontPalette;
    fontPalette.setColor(QPalette::WindowText, Qt::white);

    QWidget * widgetUser = new QWidget(this);
    widgetUser->move(BASE_WIDTH - WIDGETUSER_HORIZONTAL_OFFSET, WIDGETUSER_VERTICAL_OFFSET);

    QHBoxLayout * layout = new QHBoxLayout(widgetUser);

    lab_CurrenLoginUser = new QLabel(this);
    lab_CurrenLoginUser->setText(tr("Current logged in user:"));
    lab_CurrenLoginUser->setPalette(fontPalette);

    lab_user = new QLabel(this);
    //lab_user->setText("aaa");
    lab_user->setPalette(fontPalette);

    layout->addWidget(lab_CurrenLoginUser);
    layout->addWidget(lab_user);
    widgetUser->setLayout(layout);
    AutoSize::AutoMove(widgetUser, desktop->width(), desktop->height(), BASE_WIDTH, BASE_HEIGHT);

    btn_exit = new QPushButton(this);
    btn_exit->resize(24, 24);
    btn_exit->setFlat(true);
    btn_exit->setStyleSheet("QPushButton{border-image:url(:/image/loginout_nor.png);}"
                            "QPushButton:hover{border-image:url(:/image/loginout_nor.png);}"
                            "QPushButton:pressed{border-image:url(:/image/loginout_press.png);}");
    btn_exit->move(BASE_WIDTH - BTN_EXIT_HORIZONTAL_OFFSET, BTN_EXIT_VERTICAL_OFFSET);
    AutoSize::AutoChangeSize(btn_exit, desktop->width(), desktop->height(), BASE_WIDTH, BASE_HEIGHT);

    btn_shutDown = new QPushButton(this);
    btn_shutDown->resize(24, 24);
    btn_shutDown->setFlat(true);
    btn_shutDown->setStyleSheet("QPushButton{border-image:url(:/image/exit_nor.png);}"
                                "QPushButton:hover{border-image:url(:/image/exit_nor.png);}"
                                "QPushButton:pressed{border-image:url(:/image/exit_press.png);}");
    btn_shutDown->move(BASE_WIDTH - BTN_SHUTDOWN_HORIZONTAL_OFFSET, BTN_SHUTDOWN_VERTICAL_OFFSET);
    AutoSize::AutoChangeSize(btn_shutDown, desktop->width(), desktop->height(), BASE_WIDTH, BASE_HEIGHT);

    tablev_vmList = new CustomTableView(this);
    tablev_vmList->move(LIST_VMLIST_HORIZONTAL_OFFSET, LIST_VMLIST_VERTICAL_OFFSET);
    tablev_vmList->resize(BASE_WIDTH - LIST_VMLIST_SIZE_HORIZONTAL_OFFSET, BASE_HEIGHT - LIST_VMLIST_SIZE_VERTICAL_OFFSET);
    AutoSize::AutoChangeSize(tablev_vmList, desktop->width(), desktop->height(), BASE_WIDTH, BASE_HEIGHT);

    widget = new QWidget(this);
    widget->move(BASE_WIDTH - LIST_VMLIST_SIZE_HORIZONTAL_OFFSET, LIST_VMLIST_SIZE_VERTICAL_OFFSET);
    widget->resize(430, 1080 - 80);
    widget->setStyleSheet("background-color:white;");
    width = widget->width();
    height = widget->height();
    AutoSize::AutoChangeSize(widget, desktop->width(), desktop->height(), BASE_WIDTH, BASE_HEIGHT);

    //QHBoxLayout * hLayout = new QHBoxLayout(widget);
    //QVBoxLayout * vLayout = new QVBoxLayout(widget);

    btn_run = new QPushButton(widget);
    btn_run->resize(18, 24);
    btn_run->setFlat(true);
    btn_run->setStyleSheet("QPushButton{border-image:url(:/image/start.png);}"
                           "QPushButton:hover{border-image:url(:/image/start.png);}"
                           "QPushButton:pressed{border-image:url(:/image/start_press.png);}");
    btn_run->move(BTN_RUN_HORIZONTAL_OFFSET, BTN_RUN_VERTICAL_OFFSET);
    AutoSize::AutoChangeSize(btn_run, widget->width(), widget->height(), width, height);

    lab_run = new QLabel(widget);
    lab_run->setText(tr("Start"));
    lab_run->move(LAB_RUN_HORIZONTAL_OFFSET, LAB_RUN_VERTICAL_OFFSET);
    AutoSize::AutoMove(lab_run, widget->width(), widget->height(), width, height);


    btn_close = new QPushButton(widget);
    btn_close->resize(19, 19);
    btn_close->setFlat(true);
    btn_close->setStyleSheet("QPushButton{border-image:url(:/image/close.png);}"
                             "QPushButton:hover{border-image:url(:/image/close.png);}"
                             "QPushButton:pressed{border-image:url(:/image/close_press.png);}");
    btn_close->move(BTN_CLOSE_HORIZONTAL_OFFSET, BTN_CLOEE_VERTICAL_OFFSET);
    AutoSize::AutoChangeSize(btn_close, widget->width(), widget->height(), width, height);

    lab_close = new QLabel(widget);
    lab_close->setText(tr("Close"));
    lab_close->move(LAB_CLOSE_HORIZONTAL_OFFSET, LAB_CLOSE_VERTICAL_OFFSET);
    AutoSize::AutoMove(lab_close, widget->width(), widget->height(), width, height);

    btn_reboot = new QPushButton(widget);
    btn_reboot->resize(23, 23);
    btn_reboot->setFlat(true);
    btn_reboot->setStyleSheet("QPushButton{border-image:url(:/image/restart.png);}"
                              "QPushButton:hover{border-image:url(:/image/restart.png);}"
                              "QPushButton:pressed{border-image:url(:/image/restart_press.png);}");
    btn_reboot->move(BTN_REBOOT_HORIZONTAL_OFFSET, BTN_REBOOT_VERTICAL_OFFSET);
    AutoSize::AutoChangeSize(btn_reboot, widget->width(), widget->height(), width, height);

    lab_reboot = new QLabel(widget);
    lab_reboot->setText(tr("Restart"));
    lab_reboot->move(LAB_REBOOT_HORIZONTAL_OFFSET, LAB_REBOOT_VERTICAL_OFFSET);
    AutoSize::AutoMove(lab_reboot, widget->width(), widget->height(), width, height);

    btn_desktop = new QPushButton(widget);
    btn_desktop->resize(26, 24);
    btn_desktop->setFlat(true);
    btn_desktop->setStyleSheet("QPushButton{border-image:url(:/image/desktop.png);}"
                               "QPushButton:hover{border-image:url(:/image/desktop.png);}"
                               "QPushButton:pressed{border-image:url(:/image/desktop_press.png);}");
    btn_desktop->move(BTN_DESKTOP_HORIZONTAL_OFFSET, BTN_DESKTOP_VERTICAL_OFFSET);
    AutoSize::AutoChangeSize(btn_desktop, widget->width(), widget->height(), width, height);

    lab_desktop = new QLabel(widget);
    lab_desktop->setText(tr("Desktop"));
    lab_desktop->move(LAB_DESKTOP_HORIZONTAL_OFFSET, LAB_DESKTOP_VERTICAL_OFFSET);
    AutoSize::AutoMove(lab_desktop, widget->width(), widget->height(), width, height);

    btn_refresh = new QPushButton(widget);
    btn_refresh->resize(30, 23);
    btn_refresh->setFlat(true);
    btn_refresh->setStyleSheet("QPushButton{border-image:url(:/image/sleep.png);}"
                               "QPushButton:hover{border-image:url(:/image/sleep.png);}"
                               "QPushButton:pressed{border-image:url(:/image/sleep_press.png);}");
    btn_refresh->move(BTN_REFRESH_HORIZONTAL_OFFSET, BTN_REFRESH_VERTICAL_OFFSET);
    AutoSize::AutoChangeSize(btn_refresh, widget->width(), widget->height(), width, height);

    lab_refresh = new QLabel(widget);
    lab_refresh->setText(tr("Refresh"));
    lab_refresh->move(LAB_REFRESH_HORIZONTAL_OFFSET, LAB_REFRESH_VERTICAL_OFFSET);
    AutoSize::AutoMove(lab_refresh, widget->width(), widget->height(), width, height);
}

void VmListDialog::VmListInit()
{
    TabViewModelInit();
    TabViewInit();
}

void VmListDialog::TabViewModelInit()
{
    model = new QStandardItemModel(this);
    model->setRowCount(vmList.size());
    model->setColumnCount(MAX_CULUMN_SIZE);
    model->setHorizontalHeaderItem(ColumnIndex::COLUMN_0, new QStandardItem(QObject::tr("")));
    model->setHorizontalHeaderItem(ColumnIndex::COLUMN_1, new QStandardItem(QObject::tr("virtual machine")));
    model->setHorizontalHeaderItem(ColumnIndex::COLUMN_2, new QStandardItem(QObject::tr("OS")));
    model->setHorizontalHeaderItem(ColumnIndex::COLUMN_3, new QStandardItem(QObject::tr("state")));
    model->setHorizontalHeaderItem(ColumnIndex::COLUMN_4, new QStandardItem(QObject::tr("vCpu")));
    model->setHorizontalHeaderItem(ColumnIndex::COLUMN_5, new QStandardItem(QObject::tr("memory")));
    model->setHorizontalHeaderItem(ColumnIndex::COLUMN_6, new QStandardItem(QObject::tr("host address")));
    model->setHorizontalHeaderItem(ColumnIndex::COLUMN_7, new QStandardItem(QObject::tr("USB policy")));

    for (int i = 0; i < vmList.size(); i++)
    {
        //QStandardItem * item = new QStandardItem;
        model->setItem(i, COLUMN_1, new QStandardItem(vmList[i].name));
        model->setItem(i, COLUMN_2, new QStandardItem(vmList[i].os));
        model->setItem(i, COLUMN_3, new QStandardItem(vmList[i].state));
        model->setItem(i, COLUMN_4, new QStandardItem(QString::number(vmList[i].vCpu)));
        model->setItem(i, COLUMN_5, new QStandardItem(QString::number(vmList[i].memory) + "GB"));
        model->setItem(i, COLUMN_6, new QStandardItem(vmList[i].address));
        model->setItem(i, COLUMN_7, new QStandardItem(vmList[i].usbEnable));
    }
}

void VmListDialog::TabViewInit()
{
    tablev_vmList->setModel(model);
    tablev_vmList->setShowGrid(false);
    tablev_vmList->setSelectionBehavior(QAbstractItemView::SelectRows);
    tablev_vmList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tablev_vmList->setColumnWidth(ColumnIndex::COLUMN_0, 100);
    tablev_vmList->setColumnWidth(ColumnIndex::COLUMN_1, 200);
    tablev_vmList->setColumnWidth(ColumnIndex::COLUMN_2, 200);
    tablev_vmList->setColumnWidth(ColumnIndex::COLUMN_3, 200);
    tablev_vmList->setColumnWidth(ColumnIndex::COLUMN_4, 200);
    tablev_vmList->setColumnWidth(ColumnIndex::COLUMN_5, 200);
    tablev_vmList->setColumnWidth(ColumnIndex::COLUMN_6, 200);
    tablev_vmList->setColumnWidth(ColumnIndex::COLUMN_7, 200);
    tablev_vmList->horizontalHeader()->setResizeContentsPrecision(QHeaderView::Stretch);
    tablev_vmList->verticalHeader()->hide();
}

void VmListDialog::slot_GetVmList(QList<VmData> vmList)
{
    this->vmList = vmList;
    VmListInit();
}
