#ifndef SETTING_H
#define SETTING_H

#include <QDialog>

namespace Ui {
class settingDialog;
}

class settingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit settingDialog(QWidget *parent = 0);
    ~settingDialog();

private:
    Ui::settingDialog *ui;
};

#endif // SETTING_H
