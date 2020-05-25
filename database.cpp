#include "database.h"

CDataBase::CDataBase(QObject *parent) : QObject(parent)
{

}

CDataBase::~CDataBase()
{

}


void CDataBase::connectToDataBase(const QString file_name)
{
    /* Перед подключением к базе данных производим проверку на её существование.
     * В зависимости от результата производим открытие базы данных или её восстановление
     * */
    if(!QFile(file_name).exists()){
        //this->restoreDataBase();
        qDebug()<<"БД не существует";
    } else {
        this->openDataBase(file_name);
    }
}

bool CDataBase::inserIntoTable(const QVariantList &data)
{
    qDebug()<<data;
    return true;
}

QStringList CDataBase::tables() const
{
    return m_tables;
}

bool CDataBase::openDataBase(const QString file_name)
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(file_name);
    if(db.open()){
        QSqlQuery sql_q = QSqlQuery(db);
        for (const QString &tableName : db.tables()){
            qDebug()<< tableName;
            m_tables.append(tableName);
        }
        return true;
    } else {
        return false;
    }
}

bool CDataBase::restoreDataBase(const QString file_name)
{
    if(this->openDataBase(file_name)){
        qDebug() << "Восстановление базы данных";
            if(!this->createTable()){
                return false;
            } else {
                return true;
            }
    } else {
            qDebug() << "Не удалось восстановить базу данных";
            return false;
    }
}

void CDataBase::closeDataBase()
{
    db.close();
}

bool CDataBase::createTable()
{
    return false;
}
