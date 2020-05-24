#include "tablemodelsql.h"

DataTableModel::DataTableModel(QObject *parent) : QSqlTableModel(parent)
{

}

QVariant DataTableModel::data(const QModelIndex &index, int role) const
{
    auto getDate = [](uint timestamp)
    {
        return QDateTime::fromTime_t(timestamp).toString("dd-MM-yyyy hh:mm:ss");
    };
    switch (role) {
        case Qt::DisplayRole:
          if (index.column() == 0) {
              return getDate(QSqlTableModel::data(this->index(index.row(), 0)).toUInt());
          }
          if (index.column() > 0) return QSqlTableModel::data(index);
          break;
        case Qt::EditRole:
            //qDebug()<< "EditRole";
            if (index.column() == 0) {
                return getDate(QSqlTableModel::data(this->index(index.row(), 0)).toUInt());
            }
            if (index.column() > 0) return QSqlTableModel::data(index);
          break;

    default:
        return  QVariant();
    }
    return QVariant();
}
