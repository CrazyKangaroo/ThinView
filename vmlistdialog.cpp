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
    widgetUser->move(1920 - 500, 30);


    QHBoxLayout * layout = new QHBoxLayout(widgetUser);

    lab_CurrenLoginUser = new QLabel(this);
    lab_CurrenLoginUser->setText(tr("Current logged in user:"));
    lab_CurrenLoginUser->setPalette(fontPalette);
    //lab_CurrenLoginUser->move(1920 - 500, 30);
    //qDebug()<<"lab_CurrenLoginUser"<<lab_CurrenLoginUser->width()<<lab_CurrenLoginUser->height();
    //lab_CurrenLoginUser->adjustSize();
    //qDebug()<<"lab_CurrenLoginUser"<<lab_CurrenLoginUser->width()<<lab_CurrenLoginUser->height();
    //AutoSize(lab_CurrenLoginUser, desktop->width(), desktop->height());

    lab_user = new QLabel(this);
    lab_user->setText("aaa");
    lab_user->setPalette(fontPalette);

    layout->addWidget(lab_CurrenLoginUser);
    layout->addWidget(lab_user);
    widgetUser->setLayout(layout);
    AutoMove(widgetUser, desktop->width(), desktop->height());
    //lab_user->move(1920 - 350, 30);
    //qDebug()<<"lab_user"<<lab_user->width()<<lab_user->height();
    //lab_user->adjustSize();
    //qDebug()<<"lab_user"<<lab_user->width()<<lab_user->height();
    //AutoSize(lab_user, desktop->width(), desktop->height());

    btn_exit = new QPushButton(this);
    btn_exit->resize(24, 24);
    btn_exit->setFlat(true);
    btn_exit->setStyleSheet("QPushButton{border-image:url(:/image/loginout_nor.png);}"
                            "QPushButton:hover{border-image:url(:/image/loginout_nor.png);}"
                            "QPushButton:pressed{border-image:url(:/image/loginout_press.png);}");
    btn_exit->move(1920 - 100, 25);
    AutoSize(btn_exit, desktop->width(), desktop->height());

    btn_shutDown = new QPushButton(this);
    btn_shutDown->resize(24, 24);
    btn_shutDown->setFlat(true);
    btn_shutDown->setStyleSheet("QPushButton{border-image:url(:/image/exit_nor.png);}"
                                "QPushButton:hover{border-image:url(:/image/exit_nor.png);}"
                                "QPushButton:pressed{border-image:url(:/image/exit_press.png);}");
    btn_shutDown->move(1920 - 50, 25);
    AutoSize(btn_shutDown, desktop->width(), desktop->height());

    lisv_vmList = new QListView(this);
    lisv_vmList->move(0, 80);
    lisv_vmList->resize(1920 - 430, 1080 - 80);
    AutoSize(lisv_vmList, desktop->width(), desktop->height());

    widget = new QWidget(this);
    widget->move(1920 - 430, 80);
    widget->resize(430, 1080 - 80);
    widget->setStyleSheet("background-color:white;");
    width = widget->width();
    height = widget->height();
    AutoSize(widget, desktop->width(), desktop->height());

    //QHBoxLayout * hLayout = new QHBoxLayout(widget);
    //QVBoxLayout * vLayout = new QVBoxLayout(widget);

    btn_run = new QPushButton(widget);
    btn_run->resize(18, 24);
    btn_run->setFlat(true);
    btn_run->setStyleSheet("QPushButton{border-image:url(:/image/start.png);}"
                           "QPushButton:hover{border-image:url(:/image/start.png);}"
                           "QPushButton:pressed{border-image:url(:/image/start_press.png);}");
    btn_run->move(20, 20);
    AutoSize(btn_run, widget->width(), widget->height(), width, height);

    lab_run = new QLabel(widget);
    lab_run->setText(tr("Start"));
    lab_run->move(45, 25);
    AutoMove(lab_run, widget->width(), widget->height(), width, height);


    btn_close = new QPushButton(widget);
    btn_close->resize(19, 19);
    btn_close->setFlat(true);
    btn_close->setStyleSheet("QPushButton{border-image:url(:/image/close.png);}"
                             "QPushButton:hover{border-image:url(:/image/close.png);}"
                             "QPushButton:pressed{border-image:url(:/image/close_press.png);}");
    btn_close->move(85, 22);
    AutoSize(btn_close, widget->width(), widget->height(), width, height);

    lab_close = new QLabel(widget);
    lab_close->setText(tr("Close"));
    lab_close->move(110, 25);
    AutoMove(lab_close, widget->width(), widget->height(), width, height);

    btn_reboot = new QPushButton(widget);
    btn_reboot->resize(23, 23);
    btn_reboot->setFlat(true);
    btn_reboot->setStyleSheet("QPushButton{border-image:url(:/image/restart.png);}"
                              "QPushButton:hover{border-image:url(:/image/restart.png);}"
                              "QPushButton:pressed{border-image:url(:/image/restart_press.png);}");
    btn_reboot->move(155, 20);
    AutoSize(btn_reboot, widget->width(), widget->height(), width, height);

    lab_reboot = new QLabel(widget);
    lab_reboot->setText(tr("Restart"));
    lab_reboot->move(185, 25);
    AutoMove(lab_reboot, widget->width(), widget->height(), width, height);

    btn_desktop = new QPushButton(widget);
    btn_desktop->resize(26, 24);
    btn_desktop->setFlat(true);
    btn_desktop->setStyleSheet("QPushButton{border-image:url(:/image/desktop.png);}"
                               "QPushButton:hover{border-image:url(:/image/desktop.png);}"
                               "QPushButton:pressed{border-image:url(:/image/desktop_press.png);}");
    btn_desktop->move(235, 20);
    AutoSize(btn_desktop, widget->width(), widget->height(), width, height);

    lab_desktop = new QLabel(widget);
    lab_desktop->setText(tr("Desktop"));
    lab_desktop->move(270, 25);
    AutoMove(lab_desktop, widget->width(), widget->height(), width, height);

    btn_refresh = new QPushButton(widget);
    btn_refresh->resize(30, 23);
    btn_refresh->setFlat(true);
    btn_refresh->setStyleSheet("QPushButton{border-image:url(:/image/sleep.png);}"
                               "QPushButton:hover{border-image:url(:/image/sleep.png);}"
                               "QPushButton:pressed{border-image:url(:/image/sleep_press.png);}");
    btn_refresh->move(330, 20);
    AutoSize(btn_refresh, widget->width(), widget->height(), width, height);

    lab_refresh = new QLabel(widget);
    lab_refresh->setText(tr("Refresh"));
    lab_refresh->move(365, 25);
    AutoMove(lab_refresh, widget->width(), widget->height(), width, height);

    /*
    hLayout->addWidget(btn_run);
    hLayout->addWidget(lab_run);
    hLayout->addWidget(btn_close);
    hLayout->addWidget(lab_close);
    hLayout->addWidget(btn_reboot);
    hLayout->addWidget(lab_reboot);
    hLayout->addWidget(btn_desktop);
    hLayout->addWidget(lab_desktop);
    hLayout->addWidget(btn_refresh);
    hLayout->addWidget(lab_refresh);
    vLayout->addLayout(hLayout);
    vLayout->addStretch();
    widget->setLayout(vLayout);
    */
}

void VmListDialog::AutoSize(QWidget *widget, int screenWidth, int screenHeight)
{
    int widgetX = widget->x();
    int widgetY = widget->y();
    int widgetWid = widget->width();
    int widgetHei = widget->height();

    double herizontalRatio = screenWidth / 1920.0;
    double verticalRatio = screenHeight / 1080.0;

    int newWidgetX = (int)(widgetX * herizontalRatio);
    int newWidgetY = (int)(widgetY * verticalRatio);

    int newWidgetWid = (int)(widgetWid * herizontalRatio);
    int newWidgetHei = (int)(widgetHei * verticalRatio);

    widget->setGeometry(newWidgetX, newWidgetY, newWidgetWid, newWidgetHei);
}

void VmListDialog::AutoMove(QWidget *widget, int screenWidth, int screenHeight)
{
    int widgetX = widget->x();
    int widgetY = widget->y();

    double herizontalRatio = screenWidth / 1920.0;
    double verticalRatio = screenHeight / 1080.0;

    int newWidgetX = (int)(widgetX * herizontalRatio);
    int newWidgetY = (int)(widgetY * verticalRatio);

    widget->move(newWidgetX, newWidgetY);
}

void VmListDialog::AutoSize(QWidget *widget, int screenWidth, int screenHeight, int baseWidth , int baseHeight)
{
    int widgetX = widget->x();
    int widgetY = widget->y();
    int widgetWid = widget->width();
    int widgetHei = widget->height();

    double herizontalRatio = screenWidth / (double)baseWidth;
    double verticalRatio = screenHeight / (double)baseHeight;

    int newWidgetX = (int)(widgetX * herizontalRatio);
    int newWidgetY = (int)(widgetY * verticalRatio);

    int newWidgetWid = (int)(widgetWid * herizontalRatio);
    int newWidgetHei = (int)(widgetHei * verticalRatio);

    widget->setGeometry(newWidgetX, newWidgetY, newWidgetWid, newWidgetHei);
}

void VmListDialog::AutoMove(QWidget *widget, int screenWidth, int screenHeight, int baseWidth , int baseHeight)
{
    int widgetX = widget->x();
    int widgetY = widget->y();

    double herizontalRatio = screenWidth / (double)baseWidth;
    double verticalRatio = screenHeight / (double)baseHeight;

    int newWidgetX = (int)(widgetX * herizontalRatio);
    int newWidgetY = (int)(widgetY * verticalRatio);

    widget->move(newWidgetX, newWidgetY);
}
