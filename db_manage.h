#ifndef DB_MANAGE_H
#define DB_MANAGE_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableWidget>
#include <QLCDNumber>


class db_manage
{
public:
    db_manage();
    void openDB( QString  Path_DB, QSqlDatabase& db ) ;
    void insert( QString valor, QString motivo);
    void Delete_db(QString path,  QSqlDatabase& db );
    void show_manager(QTableWidget *tableWidget, QSqlDatabase &db);
    void Sum( QSqlDatabase& db, QLCDNumber* lcdNumber );
    void insertDivida(QString valor, QString motivo, QString data);
    void show_managerDivida(QTableWidget *tableWidget, QSqlDatabase &db);

};

#endif // DB_MANAGE_H
