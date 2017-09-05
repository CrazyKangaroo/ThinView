#include "customtab.h"
#include "ui_customtab.h"

CustomTab::CustomTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomTab)
{
    ui->setupUi(this);
}

CustomTab::~CustomTab()
{
    delete ui;
}
