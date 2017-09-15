#include "customtableview.h"

CustomTableView::CustomTableView(QWidget * parent = 0) :
QTableView(parent)
{
    delegate = new CustomItemDelegate(this);
    this->setItemDelegate(delegate);
    //ModelInit();
    //CustomTabViewInit();
}

void CustomItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() != 0)
    {
        QItemDelegate::paint(painter, option, index);
        return;
    }
    //const QAbstractItemModel * model = index.model();
    /*
    QVariant var = model->data(index, Qt::CheckStateRole);
    if (var.isNull())
    {
       var = false;
    }*/
    const QPixmap & star = pix;

    int width = star.width();
    int height = star.height();
    QRect rect = option.rect;
    int x = rect.x() + rect.width() / 2 - width / 2;
    int y = rect.y() + rect.height() / 2 - height / 2;

    painter->drawPixmap(x, y, star);
}

CustomItemDelegate::CustomItemDelegate(QObject * parent)
    :QItemDelegate(parent)
{
    pix = QPixmap(":/image/vm_icon.png");
}
/*
void CustomTableView::ModelInit()
{
    model = new CustomStandardItemModel(this);
    model->setRowCount(6);
    model->setColumnCount(8);

    model->setHorizontalHeaderItem(ColumnIndex::COLUMN_0, new QStandardItem(QObject::tr("virtual machine")));
    model->setHorizontalHeaderItem(ColumnIndex::COLUNN_1, new QStandardItem(QObject::tr("OS")));
    model->setHorizontalHeaderItem(ColumnIndex::COLUMN_2, new QStandardItem(QObject::tr("state")));
    model->setHorizontalHeaderItem(ColumnIndex::COLUMN_3, new QStandardItem(QObject::tr("vCpu")));
    model->setHorizontalHeaderItem(ColumnIndex::COLUMN_4, new QStandardItem(QObject::tr("memory")));
    model->setHorizontalHeaderItem(ColumnIndex::COLUMN_5, new QStandardItem(QObject::tr("host address")));
    model->setHorizontalHeaderItem(ColumnIndex::COLUMN_6, new QStandardItem(QObject::tr("USB policy")));
    this->setModel(model);
}*/

/*
void CustomTableView::CustomTabViewInit()
{
    this->setShowGrid(false);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setColumnWidth(ColumnIndex::COLUMN_0, 200);
    this->horizontalHeader()->setResizeContentsPrecision(QHeaderView::Stretch);
    this->verticalHeader()->hide();

}*/

/*
QVariant CustomStandardItemModel::data(const QModelIndex &index, int role) const
{

    int column = index.column();

    if (role == Qt::DisplayRole && column == 0)
    {
        return column + 1;
    }
    if (role == Qt::ToolTipRole && column == 0)
    {
        return tr("love");
    }

    return QStandardItemModel::data(index, role);
}*/

/*
QVariant CustomStandardItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (section == 0 && orientation == Qt::Horizontal)
    {
        if (role == Qt::DecorationRole)
        {
            return QIcon(":/image/vm_icon.png");
        }
        if (role == Qt::DisplayRole)
        {
            return "";
        }
        if (role == Qt::ToolTipRole)
        {
            return tr("love");
        }
    }

    return QStandardItemModel::headerData(section, orientation, role);
}*/
