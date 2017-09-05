#ifndef CUSTOMTAB_H
#define CUSTOMTAB_H

#include <QWidget>

namespace Ui {
class CustomTab;
}

class CustomTab : public QWidget
{
    Q_OBJECT

public:
    explicit CustomTab(QWidget *parent = 0);
    ~CustomTab();

private:
    Ui::CustomTab *ui;
};

#endif // CUSTOMTAB_H
