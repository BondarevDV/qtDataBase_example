#ifndef TABLEMODELSQL_H
#define TABLEMODELSQL_H
#include <QObject>
#include <QSqlTableModel>
#include <QColor>
#include <QDebug>
#include <QDateTime>

class TableModelSql : public QSqlTableModel
{
    Q_OBJECT
public:
    explicit TableModelSql(QObject *parent);
    QVariant data(const QModelIndex &idx, int role) const;
};

#endif // TABLEMODELSQL_H
