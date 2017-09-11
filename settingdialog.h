#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include "titlebar.h"

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

private:
    Ui::SettingDialog *ui;
    void UIInit();
    void TitleBarInit();

public slots:
    void onBtn_OKClick();
};

#endif // SETTINGDIALOG_H
