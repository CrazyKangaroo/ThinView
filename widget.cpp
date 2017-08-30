#include "widget.h"
#include "ui_widget.h"
#include <qdesktopwidget.h>
#include <QDebug>

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

    QImage * image = new QImage(":/image/logo");
    lab_logo = new QLabel(this);
    lab_logo->setPixmap(QPixmap::fromImage(*image));
    lab_logo->move(this->width() / 2 - LINE_WIDTH / 2, this->height() / 2 - LAB_LOGO_VERTICAL_OFFSET);

    lab_userName = new QLabel(this);
    lab_userName->resize(70, 30);
    lab_userName->setText("User");
    lab_userName->setPalette(fontPalette);
    lab_userName->move(this->width() / 2 - LINE_WIDTH / 2 + LABEL_HORIZONTAL_OFFSET, this->height() / 2 - LAB_USERNAME_VERTICAL_OFFSET);

    lab_passWord = new QLabel(this);
    lab_passWord->resize(70, 30);
    lab_passWord->setText("Password");
    lab_passWord->setPalette(fontPalette);
    lab_passWord->move(this->width() / 2 - LINE_WIDTH / 2 + LABEL_HORIZONTAL_OFFSET, this->height() / 2 + LAB_PASSWORD_VERTICAL_OFFSET);

    cbo_userName = new QComboBox(this);
    cbo_userName->resize(190, 20);
    cbo_userName->setEditable(true);
    //cbo_userName->setStyleSheet("QComboBox{background:transparent;}"
    //                            "QComboBox::drop-down{background:transparent}");
    cbo_userName->move(lab_userName->x() + lab_userName->width(), lab_userName->y());

    lei_passWord = new QLineEdit(this);
    lei_passWord->resize(190, 20);
    lei_passWord->setStyleSheet("background-color:transparent;"
                                "border-style:none");
    lei_passWord->setEchoMode(QLineEdit::Password);
    lei_passWord->move(lab_passWord->x() + lab_passWord->width(), lab_passWord->y());

    cco_autoLogin = new QCheckBox(this);
    cco_autoLogin->setStyleSheet("QCheckBox::indicator:unchecked{image:url(:/image/checkbtn_nor.png)};"
                                 "QCheckBox::indicator:checked{image:url(:/image/checkbtn_press.png)};");
    cco_autoLogin->move(lab_passWord->x() + CCO_AUTOLOGIN_HORIZONTAL_OFFSET, lab_passWord->y() + CHECKBOX_VERTICAL_OFFSET);

    lab_autoLogin = new QLabel(this);
    lab_autoLogin->setText("Auto login");
    lab_autoLogin->setPalette(fontPalette);
    lab_autoLogin->move(lab_passWord->x() + CCO_AUTOLOGIN_HORIZONTAL_OFFSET + LAB_AUTOLOGIN_HORIZONTAL_OFFSET, lab_passWord->y() + CHECKBOX_VERTICAL_OFFSET);

    cco_keepPassword = new QCheckBox(this);
    cco_keepPassword->setStyleSheet("QCheckBox::indicator:unchecked{image:url(:/image/checkbtn_nor.png)};"
                                 "QCheckBox::indicator:checked{image:url(:/image/checkbtn_press.png)};");
    cco_keepPassword->move(lab_passWord->x() + CCO_PASSWORD_HORIZONTAL_OFFSET, lab_passWord->y() + CHECKBOX_VERTICAL_OFFSET);

    lab_keepPassword = new QLabel(this);
    lab_keepPassword->setText("Keep password");
    lab_keepPassword->setPalette(fontPalette);
    lab_keepPassword->move(cco_keepPassword->x() + LAB_KEEPPASSWORD_HORIZONTAL_OFFSET, lab_passWord->y() + CHECKBOX_VERTICAL_OFFSET);


    //qDebug()<<Lab_userName->width()<<" "<<Lab_passWord->width();
    //qDebug()<<Lab_userName->height()<<" "<<Lab_passWord->height();
}

Widget::~Widget()
{
    delete ui;
}
