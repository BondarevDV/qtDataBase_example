#ifndef TABLEMODELSQL_H
#define TABLEMODELSQL_H
#include <QObject>
#include <QSqlTableModel>
#include <QColor>
#include <QDebug>
#include <QDateTime>


class DataTableModel : public QSqlTableModel
{
    Q_OBJECT
public:

    explicit DataTableModel(QObject *parent);
    QVariant data(const QModelIndex &idx, int role) const override;
};

#endif // TABLEMODELSQL_H
