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

    lei_password = new QLineEdit(this);
    lei_password->resize(190, 20);
    lei_password->setStyleSheet("background-color:transparent;"
                                "border-style:none");
    lei_password->setEchoMode(QLineEdit::Password);
    lei_password->move(lab_passWord->x() + lab_passWord->width(), lab_passWord->y());

    //qDebug()<<Lab_userName->width()<<" "<<Lab_passWord->width();
    //qDebug()<<Lab_userName->height()<<" "<<Lab_passWord->height();
}

Widget::~Widget()
{
    delete ui;
}
