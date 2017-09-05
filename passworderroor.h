#ifndef PASSWORDERROOR_H
#define PASSWORDERROOR_H

#include <QDialog>

namespace Ui {
class PasswordErroor;
}

class PasswordErroor : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordErroor(QWidget *parent = 0);
    ~PasswordErroor();

private:
    Ui::PasswordErroor *ui;
};

#endif // PASSWORDERROOR_H
