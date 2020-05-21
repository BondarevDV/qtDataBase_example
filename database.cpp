#include "database.h"

CDataBase::CDataBase(QObject *parent) : QObject(parent)
{

}

CDataBase::~CDataBase()
{

}


void CDataBase::connectToDataBase()
{
    /* Перед подключением к базе данных производим проверку на её существование.
     * В зависимости от результата производим открытие базы данных или её восстановление
     * */
    QString path_db = QString("%1/%2").arg(QDir::currentPath()).arg(DATABASE_NAME);
    if(!QFile(path_db).exists()){
        //this->restoreDataBase();
        qDebug()<<"БД не существует";
    } else {
        this->openDataBase();
    }
}

bool CDataBase::inserIntoTable(const QVariantList &data)
{
    qDebug()<<data;
    return true;
}

bool CDataBase::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */
    QString path_db = QString("%1/%2").arg("./").arg(DATABASE_NAME);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(path_db);
    if(db.open()){
        QSqlQuery sql_q = QSqlQuery(db);
        for (const QString &tableName : db.tables()){
            qDebug()<< tableName;
        }
        return true;
    } else {
        return false;
    }
}

bool CDataBase::restoreDataBase()
{
    if(this->openDataBase()){
        qDebug() << "Восстановление базы данных";
//            if(!this->createTable()){
//                return false;
//            } else {
//                return true;
//            }
    } else {
            qDebug() << "Не удалось восстановить базу данных";
            return false;
    }
}

bool CDataBase::createTable()
{
    return false;
}
