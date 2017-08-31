#include "widget.h"
#include "ui_widget.h"
#include <qdesktopwidget.h>
#include <QDebug>
#include <QMenu>

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
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/image/login.png")));
    this->setPalette(palette);

    QPalette fontPalette;
    fontPalette.setColor(QPalette::WindowText, Qt::white);
    QFont font;
    font.setPointSize(11);

    QImage * image = new QImage(":/image/logo");
    lab_logo = new QLabel(this);
    lab_logo->setPixmap(QPixmap::fromImage(*image));
    lab_logo->move(this->width() / 2 - LINE_WIDTH / 2, this->height() / 2 - LAB_LOGO_VERTICAL_OFFSET);

    lab_userName = new QLabel(this);
    lab_userName->resize(70, 30);
    lab_userName->setText("User");
    lab_userName->setPalette(fontPalette);
    lab_userName->setFont(font);
    lab_userName->move(this->width() / 2 - LINE_WIDTH / 2 + LABEL_HORIZONTAL_OFFSET, this->height() / 2 - LAB_USERNAME_VERTICAL_OFFSET);

    lab_passWord = new QLabel(this);
    lab_passWord->resize(70, 30);
    lab_passWord->setText("Password");
    lab_passWord->setPalette(fontPalette);
    lab_passWord->setFont(font);
    lab_passWord->move(this->width() / 2 - LINE_WIDTH / 2 + LABEL_HORIZONTAL_OFFSET, this->height() / 2 + LAB_PASSWORD_VERTICAL_OFFSET);

    cbo_userName = new QComboBox(this);
    cbo_userName->resize(190, 20);
    cbo_userName->setEditable(true);
    cbo_userName->setStyleSheet("color:white;"
                                );
    cbo_userName->move(lab_userName->x() + lab_userName->width(), lab_userName->y());

    lei_passWord = new QLineEdit(this);
    lei_passWord->resize(190, 20);
    lei_passWord->setStyleSheet("background-color:transparent;"
                                "color:white;"
                                "border-style:none;");
    lei_passWord->setFont(font);
    lei_passWord->setEchoMode(QLineEdit::Password);
    lei_passWord->move(lab_passWord->x() + lab_passWord->width(), lab_passWord->y());

    cco_autoLogin = new QCheckBox(this);
    cco_autoLogin->setStyleSheet("QCheckBox::indicator:unchecked{image:url(:/image/checkbtn_nor.png);}"
                                 "QCheckBox::indicator:checked{image:url(:/image/checkbtn_press.png);}");
    cco_autoLogin->setText("Auto login");
    cco_autoLogin->setPalette(fontPalette);
    cco_autoLogin->move(lab_passWord->x() + CCO_AUTOLOGIN_HORIZONTAL_OFFSET, lab_passWord->y() + CHECKBOX_VERTICAL_OFFSET);

    cco_keepPassword = new QCheckBox(this);
    cco_keepPassword->setStyleSheet("QCheckBox::indicator:unchecked{image:url(:/image/checkbtn_nor.png);}"
                                    "QCheckBox::indicator:checked{image:url(:/image/checkbtn_press.png);}");
    cco_keepPassword->setText("Keep password");
    cco_keepPassword->setPalette(fontPalette);
    cco_keepPassword->move(lab_passWord->x() + CCO_PASSWORD_HORIZONTAL_OFFSET, lab_passWord->y() + CHECKBOX_VERTICAL_OFFSET);

    btn_login = new QPushButton(this);
    btn_login->resize(310, 54);
    btn_login->setFlat(true);
    btn_login->setStyleSheet("QPushButton{border-image:url(:/image/btnlogin_nor.png);}"
                             "QPushButton:hover{border-image:url(:/image/btnlogin_press.png);}"
                             "QPushButton:pressed{border-image:url(:/image/btnlogin_press.png);}"
                             );
    btn_login->move(this->width() / 2 - LINE_WIDTH / 2, cco_keepPassword->y() + BTN_LOGIN_VERTICAL_OFFSET);

    QMenu * detailMenu = new QMenu;
    QAction * leftClick = new QAction("Detail information");
    detailMenu->addAction(leftClick);

    btn_detail = new QPushButton(this);
    btn_detail->resize(32, 26);
    btn_detail->setFlat(true);
    btn_detail->setMenu(detailMenu);
    btn_detail->setStyleSheet("QPushButton::menu-indicator{image:none}"
                              "QPushButton{border-image:url(:/image/netstatus_up.png);}"
                              "QPushButton:pressed{border-image:url(:/image/netstatus_up.png);}");
    btn_detail->move(this->width() - BTN_DETAIL_HORIZONTAL_OFFSET, this->height() - BTN_DETAIL_VERTICAL_OFFSET);

    btn_setting = new QPushButton(this);
    btn_setting->resize(80, 25);
    btn_setting->setFlat(true);
    btn_setting->setStyleSheet("QPushButton{border-image:url(:/image/set_nor.png);}"
                               "QPushButton:hover{border-image:url(:/image/set_press.png);}"
                               "QPushButton:pressed{border-image:url(:/image/set_press.png);}"
                               );
    btn_setting->move(this->width() - BTN_SETTING_HORIZONTAL_OFFSET, btn_detail->y());

    btn_shutDown = new QPushButton(this);
    btn_shutDown->resize(24, 24);
    btn_shutDown->setFlat(true);
    btn_shutDown->setStyleSheet("QPushButton{border-image:url(:/image/exit_nor.png);}"
                                "QPushButton:hover{border-image:url(:/image/exit_press.png);}"
                                "QPushButton:pressed{border-image:url(:/image/exit_press.png);}"
                                );
    btn_shutDown->move(this->width() - BTN_SHUTDOWN_HORIZONTAL_OFFSET, btn_detail->y());
}

Widget::~Widget()
{
    delete ui;
}
