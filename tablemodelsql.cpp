#include "tablemodelsql.h"

DataTableModel::DataTableModel(QObject *parent) : QSqlTableModel(parent)
{

}

QVariant DataTableModel::data(const QModelIndex &idx, int role) const
{
    QVariant v = QSqlTableModel::data(this->index(idx.row(), 0));
    if(role == Qt::DisplayRole){
        QString fmt = "dd-MM-yyyy hh:mm:ss";
        uint time_stamp = QSqlTableModel::data(this->index(idx.row(), 0)).toUInt();
        QString date = QDateTime::fromTime_t(time_stamp).toString(fmt);
        QVariant v = QSqlTableModel::data(idx);
        if(idx.column() == 0){
            v.setValue(date);
        }
        return v;
    }
    return QVariant();
}
