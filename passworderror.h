#ifndef PASSWORDERROR_H
#define PASSWORDERROR_H

#include <QDialog>

namespace Ui {
class PasswordError;
}

class PasswordError : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordError(QWidget *parent = 0);
    ~PasswordError();

private:
    Ui::PasswordError *ui;
    void UIInit();
};

#endif // PASSWORDERROR_H
