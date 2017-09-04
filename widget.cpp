#include "widget.h"
#include "ui_widget.h"
#include <qdesktopwidget.h>
#include <QDebug>
#include <QMenu>
#include <QTime>
#include "settingdialog.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QDesktopWidget * desktop = QApplication::desktop();
    this->resize(desktop->width(), desktop->height());
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/image/login.png").scaled(this->size())));
    this->setPalette(palette);

    QPalette fontPalette;
    fontPalette.setColor(QPalette::WindowText, Qt::white);
    QFont font;
    font.setPointSize(FONT_SIZE);

    QTime currentime = QTime::currentTime();
    QString time = currentime.toString("hh:mm");
    lab_time = new QLabel(this);
    lab_time->setText(time);
    lab_time->setPalette(fontPalette);
    lab_time->setFont(font);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            this,SLOT(slot_UpdateTime()));
    timer->start(1000);
    lab_time->move(BASE_WIDTH - LAB_TIME_HORIZONTAL_OFFSET, LAB_TIME_VERTICAL_OFFSET);
    AutoSize(lab_time, this->width(), this->height());

    QImage * image = new QImage(":/image/logo");
    lab_logo = new QLabel(this);
    lab_logo->resize(image->size());
    lab_logo->move(BASE_WIDTH / 2 - LINE_WIDTH / 2, BASE_HEIGHT / 2 - LAB_LOGO_VERTICAL_OFFSET);
    AutoSize(lab_logo, this->width(), this->height());
    lab_logo->setPixmap(QPixmap::fromImage(*image).scaled(lab_logo->size()));

    lab_userName = new QLabel(this);
    lab_userName->resize(70, 30);
    lab_userName->setText(tr("User"));
    lab_userName->setPalette(fontPalette);
    lab_userName->setFont(font);
    lab_userName->move(BASE_WIDTH / 2 - LINE_WIDTH / 2 + LABEL_HORIZONTAL_OFFSET, BASE_HEIGHT / 2 - LAB_USERNAME_VERTICAL_OFFSET);
    AutoSize(lab_userName, desktop->width(), desktop->height());

    lab_passWord = new QLabel(this);
    lab_passWord->resize(70, 30);
    lab_passWord->setText(tr("Password"));
    lab_passWord->setPalette(fontPalette);
    lab_passWord->setFont(font);
    lab_passWord->move(BASE_WIDTH / 2 - LINE_WIDTH / 2 + LABEL_HORIZONTAL_OFFSET, BASE_HEIGHT / 2 + LAB_PASSWORD_VERTICAL_OFFSET);
    AutoSize(lab_passWord, desktop->width(), desktop->height());

    cbo_userName = new QComboBox(this);
    cbo_userName->resize(190, 25);
    cbo_userName->setEditable(true);
    cbo_userName->setFont(font);
    cbo_userName->setStyleSheet("QComboBox{color:white;border:0px;}"
                                "QComboBox:editable{background:transparent;}"
                               );
    cbo_userName->move(BASE_WIDTH / 2 - LINE_WIDTH / 2 + LABEL_HORIZONTAL_OFFSET + CBO_USERNAME_HORIZONTAL_OFFSET, BASE_HEIGHT / 2 - LAB_USERNAME_VERTICAL_OFFSET);
    AutoSize(cbo_userName, this->width(), this->height());

    lei_passWord = new QLineEdit(this);
    lei_passWord->resize(190, 25);
    lei_passWord->setStyleSheet("background-color:transparent;"
                                "color:white;"
                                "border-style:none;");
    lei_passWord->setFont(font);
    lei_passWord->setEchoMode(QLineEdit::Password);
    lei_passWord->move(BASE_WIDTH / 2 - LINE_WIDTH / 2 + LABEL_HORIZONTAL_OFFSET + LEI_PASSWORD_HORIZONTAL_OFFSET, BASE_HEIGHT / 2 + LAB_PASSWORD_VERTICAL_OFFSET);
    AutoSize(lei_passWord, this->width(), this->height());

    cco_autoLogin = new QCheckBox(this);
    cco_autoLogin->setStyleSheet("QCheckBox::indicator:unchecked{image:url(:/image/checkbtn_nor.png);}"
                                 "QCheckBox::indicator:checked{image:url(:/image/checkbtn_press.png);}");
    cco_autoLogin->setText(tr("Auto login"));
    cco_autoLogin->setPalette(fontPalette);
    cco_autoLogin->move(BASE_WIDTH / 2 - LINE_WIDTH / 2 + LABEL_HORIZONTAL_OFFSET + CCO_AUTOLOGIN_HORIZONTAL_OFFSET, BASE_HEIGHT / 2 + LAB_PASSWORD_VERTICAL_OFFSET + CHECKBOX_VERTICAL_OFFSET);
    AutoSize(cco_autoLogin, this->width(), this->height());

    cco_keepPassword = new QCheckBox(this);
    cco_keepPassword->setStyleSheet("QCheckBox::indicator:unchecked{image:url(:/image/checkbtn_nor.png);}"
                                    "QCheckBox::indicator:checked{image:url(:/image/checkbtn_press.png);}");
    cco_keepPassword->setText(tr("Keep password"));
    cco_keepPassword->setPalette(fontPalette);
    cco_keepPassword->move(BASE_WIDTH / 2 - LINE_WIDTH / 2 + LABEL_HORIZONTAL_OFFSET + CCO_PASSWORD_HORIZONTAL_OFFSET, BASE_HEIGHT / 2 + LAB_PASSWORD_VERTICAL_OFFSET + CHECKBOX_VERTICAL_OFFSET);
    AutoSize(cco_keepPassword, this->width(), this->height());

    btn_login = new QPushButton(this);
    btn_login->resize(310, 54);
    btn_login->setFlat(true);
    btn_login->setStyleSheet("QPushButton{border-image:url(:/image/btnlogin_nor.png);}"
                             "QPushButton:hover{border-image:url(:/image/btnlogin_press.png);}"
                             "QPushButton:pressed{border-image:url(:/image/btnlogin_press.png);}"
                             );
    btn_login->move(BASE_WIDTH / 2 - LINE_WIDTH / 2, BASE_HEIGHT / 2 + LAB_PASSWORD_VERTICAL_OFFSET + CHECKBOX_VERTICAL_OFFSET + BTN_LOGIN_VERTICAL_OFFSET);
    AutoSize(btn_login, desktop->width(), desktop->height());

    QMenu * detailMenu = new QMenu;
    QAction * leftClick = new QAction(tr("Detail information"));
    detailMenu->addAction(leftClick);

    btn_detail = new QPushButton(this);
    btn_detail->resize(32, 26);
    btn_detail->setFlat(true);
    btn_detail->setMenu(detailMenu);
    btn_detail->setStyleSheet("QPushButton::menu-indicator{image:none}"
                              "QPushButton{border-image:url(:/image/netstatus_up.png);}"
                              "QPushButton:pressed{border-image:url(:/image/netstatus_up.png);}");
    btn_detail->move(BASE_WIDTH - BTN_DETAIL_HORIZONTAL_OFFSET, BASE_HEIGHT - BTN_DETAIL_VERTICAL_OFFSET);
    AutoSize(btn_detail, this->width(), this->height());

    btn_setting = new QPushButton(this);
    btn_setting->resize(80, 25);
    btn_setting->setFlat(true);
    btn_setting->setStyleSheet("QPushButton{border-image:url(:/image/set_nor.png);}"
                               "QPushButton:hover{border-image:url(:/image/set_press.png);}"
                               "QPushButton:pressed{border-image:url(:/image/set_press.png);}"
                               );
    btn_setting->move(BASE_WIDTH - BTN_SETTING_HORIZONTAL_OFFSET, BASE_HEIGHT - BTN_SETTING_VERTICAL_OFFSET);
    connect(btn_setting, SIGNAL(clicked(bool)),this, SLOT(slot_BtnSettingClick()));
    AutoSize(btn_setting, this->width(), this->height());

    btn_shutDown = new QPushButton(this);
    btn_shutDown->resize(24, 24);
    btn_shutDown->setFlat(true);
    btn_shutDown->setStyleSheet("QPushButton{border-image:url(:/image/exit_nor.png);}"
                                "QPushButton:hover{border-image:url(:/image/exit_press.png);}"
                                "QPushButton:pressed{border-image:url(:/image/exit_press.png);}"
                                );
    btn_shutDown->move(BASE_WIDTH - BTN_SHUTDOWN_HORIZONTAL_OFFSET, BASE_HEIGHT - BTN_SHUTDOWN_VERTICAL_OFFSET);
    AutoSize(btn_shutDown, this->width(), this->height());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_UpdateTime()
{
    QTime currentime = QTime::currentTime();
    QString time = currentime.toString("hh:mm");
    lab_time->setText(time);
}

void Widget::AutoSize(QWidget *widget, int screenWidth, int screenHeight)
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

void Widget::slot_BtnSettingClick()
{
    SettingDialog * dialog = new SettingDialog;

    int result = dialog->exec();

    if (result == QDialog::Accepted)
    {

    }
    else if (result == QDialog::Rejected)
    {

    }
}
