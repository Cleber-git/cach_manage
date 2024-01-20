#include "db_manage.h"
#include <QDebug>
#include <map>
#include<QApplication>
#include <QTableWidget>
db_manage::db_manage()
{


}

void db_manage::openDB( QString  Path_DB, QSqlDatabase& db )  {

    db.setDatabaseName( Path_DB );
    if (!db.open()) {
        qDebug() << "Falha ao tentar acessar a base de dados";
    }else{
        qDebug() << "Tenho acesso a sua Base de dados !";
    }
}

void db_manage::insert( QString valor, QString motivo){

    QSqlQuery query;
    QString sql;

    sql = "INSERT INTO mes (valor, motivo) VALUES (:valor, :motivo)";
    query.prepare(sql);
    query.bindValue(":valor", valor);
    query.bindValue(":motivo", motivo);


    if ( !query.exec() ) {

        qDebug() << "Falha ao executar a query";

    }else{

        qDebug() << "Executado com sucesso!";

    }
}





void db_manage::show_manager(QTableWidget *tableWidget, QSqlDatabase &db){

    tableWidget->setColumnCount(2);
    tableWidget->setColumnWidth(0, 250);
    tableWidget->setColumnWidth(1,  62);
    QString path  = qApp->applicationDirPath() + "/cach.db";
    openDB(path, db);

    QSqlQuery query;
    QString sql;

    sql = "SELECT valor, motivo FROM mes";

    query.prepare(sql);

    if(!query.exec()){

        qDebug() << "Falha ao abrir a base de dados!";
        return;
    }

//    qDebug() <<"passei";
    int count = 0;
    while(query.next()){

        int row = tableWidget->rowCount();
        row++;
//        qDebug() << row;
        tableWidget->setRowCount(row);

        QString valor1 = query.value(1).toString();
        QString valor2= query.value(0).toString();


        tableWidget->setItem(count, 0, new QTableWidgetItem(valor1));
        tableWidget->setItem(count, 1, new QTableWidgetItem(valor2));
//        qDebug() << valor1 << valor2;
        count++;


    }


}

void db_manage::Sum( QSqlDatabase& db, QLCDNumber* lcdNumber ){

    int valor = 0;

    QSqlQuery query;
    QString sql = "SELECT valor FROM mes";
    QString path = qApp->applicationDirPath() + "/cach.db";
    openDB(path, db);

    query.prepare(sql);

    if(!query.exec()){

        qDebug()<<"Falha na execução da query!";
        return;

    }

    while(query.next()){

        valor += query.value(0).toDouble();
        qDebug()<<valor;


    }
    lcdNumber->display(valor);





}






void db_manage::Delete_db( QString path, QSqlDatabase& db ){

    openDB( path ,db);
    QSqlQuery query;
    QString sql;

    sql = "DELETE FROM mes";
    query.prepare(sql);
    if (query.exec()) {
        qDebug()<<"BASE DE DADOS DELETADA COM SUCESSO!";
    }else{
        qDebug()<<"NÃO FOI POSSÍVEL DELETAR A BASE DE DADOS!";
    }
}
