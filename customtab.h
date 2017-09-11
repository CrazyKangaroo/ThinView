#ifndef CUSTOMTAB_H
#define CUSTOMTAB_H

#include <QWidget>

enum PageIndex
{
    page0 = 0,
    page1,
    page2,
};

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
    void UIIint();
};

#endif // CUSTOMTAB_H
