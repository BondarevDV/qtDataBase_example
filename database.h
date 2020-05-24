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

/* Директивы имен таблицы, полей таблицы и базы данных */
#define DATABASE_HOSTNAME   "ExampleDataBase"
#define DATABASE_NAME       "sample.db"

#define TABLE                   "data12"
#define TABLE_DATE              "Date"
#define TABLE_TIME              "Time"
#define TABLE_MESSAGE           "Message"
#define TABLE_RANDOM            "Random"

class CDataBase : public QObject
{
    Q_OBJECT
public:
    explicit CDataBase(QObject *parent = nullptr);
    ~CDataBase();
    /* Методы для непосредственной работы с классом
     * Подключение к базе данных и вставка записей в таблицу
     * */
    void connectToDataBase();
    bool inserIntoTable(const QVariantList &data);

    QStringList tables() const;

private:
    // Сам объект базы данных, с которым будет производиться работа
    QSqlDatabase    db;
    QStringList m_tables;
private:
    /* Внутренние методы для работы с базой данных
     * */
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();

};

#endif // DATABASE_H
