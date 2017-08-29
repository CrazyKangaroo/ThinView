#include "widget.h"
#include "ui_widget.h"
#include <qdesktopwidget.h>

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
    Lab_Logo = new QLabel(this);
    Lab_Logo->setPixmap(QPixmap::fromImage(*image));
    Lab_Logo->move(this->width() / 2 - LINE_WIDTH / 2, this->height() / 2 - LAB_LOGO_VERTICAL_OFFSET);

    Lab_userName = new QLabel(this);
    Lab_userName->setText("User");
    Lab_userName->setPalette(fontPalette);
    Lab_userName->move(this->width() / 2 - LINE_WIDTH / 2 + LABEL_HORIZONTAL_OFFSET, this->height() / 2 - LAB_USERNAME_VERTICAL_OFFSET);

    Lab_passWord = new QLabel(this);
    Lab_passWord->setText("Password");
    Lab_passWord->setPalette(fontPalette);
    Lab_passWord->move(this->width() / 2 - LINE_WIDTH / 2 + LABEL_HORIZONTAL_OFFSET, this->height() / 2 + LAB_PASSWORD_VERTICAL_OFFSET);
}

Widget::~Widget()
{
    delete ui;
}
