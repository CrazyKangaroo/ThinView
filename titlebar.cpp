#include "titlebar.h"
#include "ui_titlebar.h"

TitleBar::TitleBar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TitleBar)
{
    ui->setupUi(this);
}

TitleBar::~TitleBar()
{
    delete ui;
}
