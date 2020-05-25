#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QDir>

#define DATABASE_HOSTNAME   "ExampleDataBase"


class CDataBase : public QObject
{
    Q_OBJECT
public:
    explicit CDataBase(QObject *parent = nullptr);
    ~CDataBase();
    /* Методы для непосредственной работы с классом
     * Подключение к базе данных и вставка записей в таблицу
     * */
    void connectToDataBase(const QString file_name);
    bool inserIntoTable(const QVariantList &data);

    QStringList tables() const;

private:
    // Сам объект базы данных, с которым будет производиться работа
    QSqlDatabase    db;
    QStringList m_tables;
private:
    /* Внутренние методы для работы с базой данных
     * */
    bool openDataBase(const QString file_name);
    bool restoreDataBase(const QString file_name);
    void closeDataBase();
    bool createTable();

};

#endif // DATABASE_H
