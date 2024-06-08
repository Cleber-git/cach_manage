#include <QDebug>
#include <map>
#include<QApplication>
#include <QTableWidget>
#include "mainwindow.h"

int db_manage::countInstance = 0;
db_manage::db_manage()
{

    m_db = QSqlDatabase::addDatabase("QSQLITE");

    m_path =  qApp->applicationDirPath() ;
    m_path +=  "/cach.db";
    qDebug()<<m_path;
    openDB( m_path, m_db );
    countInstance++;
//    qDebug() << "Número de instâncias da classe db_manage: " << QString::number(countInstance);

}

db_manage::~db_manage(){
    countInstance--;
}

void db_manage::openDB( QString  Path_DB, QSqlDatabase& db )  {

    db.setDatabaseName( Path_DB );
    if (!db.open()) {
        qDebug() << "Falha ao tentar acessar a base de dados";
    }else{
        qDebug() << "Tenho acesso a sua Base de dados !";
    }
}

void db_manage::insertDivida(QString valor, QString motivo, QString data){

//    qDebug() << "[insertDivida]";

    QSqlQuery query;
    QString sql;


//    qDebug() << "Valor" << valor;
//    qDebug() << "Motivo" << motivo;
//    qDebug() << "Divida" << data;

    sql = "INSERT INTO dividas (valor, motivo, data) VALUES (:valor, :motivo, :data)";

    query.prepare(sql);


    query.bindValue(":valor", valor);
    query.bindValue(":motivo", motivo);
    query.bindValue(":data", data);



    if ( !query.exec() ) {

        qDebug() << "Falha ao executar a query";

    }else{

        qDebug() << "Executado com sucesso!";
//        m_db.close();

    }
}

void db_manage::insert( QString valor, QString motivo){
//    qDebug() << "[insert]";

    QSqlQuery query;
    QString sql;

    sql = "INSERT INTO gastos (valor, motivo) VALUES (:valor, :motivo)";

    query.prepare(sql);

    qDebug() << "Valor" << valor;
    qDebug() << "Motivo" << motivo;

    query.bindValue(":valor", valor);
    query.bindValue(":motivo", motivo);


    if ( !query.exec() ) {

        qDebug() << "Falha ao executar a query:: Insert";

    }else{

        qDebug() << "Executado com sucesso! :: insert";

    }
}

void db_manage::show_managerDivida(QTableWidget *tableWidget, QSqlDatabase &db){

        tableWidget->setColumnCount(3);
        tableWidget->setColumnWidth(0, 250);
        tableWidget->setColumnWidth(1,  62);
        tableWidget->setColumnWidth(2, 117);

        QSqlQuery query;
        QString sql;

        sql = "SELECT valor, motivo, data FROM dividas";

        query.prepare(sql);

        if(!query.exec()){

            qDebug() << "Falha ao abrir a base de dados!";
            return;

        }

        int count = 0;
        tableWidget->clear();
        tableWidget->setRowCount(0);
        int row = 1;

        while(query.next()){


            //        qDebug() << row;
            tableWidget->setRowCount(row);
            row++;

            QString valor1 = query.value(1).toString();
            QString valor2= query.value(0).toString();
            QString valor3 = query.value(2).toString();


            tableWidget->setItem(count, 0, new QTableWidgetItem(valor1));
            tableWidget->setItem(count, 1, new QTableWidgetItem(valor2));
            tableWidget->setItem(count, 2, new QTableWidgetItem(valor3));
            //        qDebug() << valor1 << valor2;
            count++;


        }

}




void db_manage::show_manager(QTableWidget *tableWidget, QSqlDatabase &db){

//    openDB(m_path, m_db);


    tableWidget->clear();
    tableWidget->setRowCount(0);

    tableWidget->setColumnCount(2);
    tableWidget->setColumnWidth(0, 250);
    tableWidget->setColumnWidth(1,  62);


    QSqlQuery query(m_db);
    QString sql;

    sql = "SELECT valor, motivo FROM gastos";

    query.prepare(sql);

    if(!query.exec()){

        qDebug()<< "Falha ao abrir a base de dados!";
        return;
    }

    int count = 0;

    int row = tableWidget->rowCount();
    while(query.next()){

        row++;
        qDebug() << row;
        tableWidget->setRowCount(row);

        QString valor1 = query.value(1).toString();
        QString valor2= query.value(0).toString();


        tableWidget->setItem(count, 0, new QTableWidgetItem(valor1));
        tableWidget->setItem(count, 1, new QTableWidgetItem(valor2));
//        qDebug() << valor1 << valor2;
        count++;


    }


}

void db_manage::Sum( QSqlDatabase& db, QLCDNumber* lcdNumber, QString mode ){

    int valor = 0;

    QString sql = QString( "SELECT valor FROM %1" ).arg( mode );
    QSqlQuery query;
    query.prepare( sql );
    if( !query.exec() ){

        qDebug()<<"Falha na execução da query!";
        return;

    }

    while(query.next()){

        valor += query.value(0).toDouble();
        qDebug()<<valor;


    }
    lcdNumber->display(valor);
}



void db_manage::Delete_db( QString path, QSqlDatabase& db, QString mode ){

//    qDebug() << "delete db";
    QSqlQuery query;
    QString sql;



    sql = "DELETE FROM gastos";

    if( mode == "divida" ){
        sql =  "DELETE FROM dividas";

    }

    query.prepare( sql );
    if ( query.exec() ) {
        qDebug()<<"BASE DE DADOS DELETADA COM SUCESSO!";
    }else{
        qDebug()<<"NÃO FOI POSSÍVEL DELETAR A BASE DE DADOS!";

    }
}

QSqlDatabase db_manage::getMDB(){
    return m_db;
}
QString db_manage::getPath(){
    return m_path;
}

