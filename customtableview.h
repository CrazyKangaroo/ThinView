#ifndef CUSTOMTABLEVIEW_H
#define CUSTOMTABLEVIEW_H

#include <QTableView>
#include <QItemDelegate>
#include <QPixmap>
#include <QStandardItemModel>
#include <QPainter>
#include <QHeaderView>

class CustomTableView;
class CustomItemDelegate;
class CustomStandardItemModel;

class CustomTableView : public QTableView
{
public:
    CustomTableView(QWidget * parent);
private:
    CustomItemDelegate * delegate;
    CustomStandardItemModel * model;
    void ModelInit();
    void CustomTabViewInit();
};

class CustomItemDelegate : public QItemDelegate
{
public:
    CustomItemDelegate(QObject * parent = 0);
    virtual ~ CustomItemDelegate() {}
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
private:
    QPixmap pix;
};

class CustomStandardItemModel : public QStandardItemModel
{
public:
    CustomStandardItemModel(QObject * parent=0)
        :QStandardItemModel(parent){}
    virtual ~CustomStandardItemModel() {}
    //QVariant data(const QModelIndex &index, int role) const;
    //QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};



#endif // CUSTOMTABLEVIEW_H
