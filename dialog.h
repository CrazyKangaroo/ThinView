#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "titlebar.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void SetInfo(QString info);

private:
    Ui::Dialog *ui;
private slots:
    void onBtnOKClick();
    void onBtnCancleClick();
};

#endif // DIALOG_H
