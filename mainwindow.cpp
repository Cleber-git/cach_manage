#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "db_manage.h"
#include <QDebug>
#include "form.h"
#include "cont_all.h"
#include <QFile>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)) ,this, SLOT(ChangeModeLabel(QString)) );
    this->setWindowTitle("Banc Manage");
    QString version = read_version();
    ui->label_5->setText(version);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if( !ui->motivo->text().isEmpty() && !ui->valor->text().isEmpty()){
        db_manage C_db;
        QSqlDatabase db;
        QString path;

        db = QSqlDatabase::addDatabase("QSQLITE");

        path =  qApp->applicationDirPath() ;
        path +=  "/cach.db";
        qDebug()<<path;

        C_db.openDB( path, db );

        QString preço = ui->valor->text();
        QString motivo = ui->motivo->text();

        C_db.insert(preço, motivo);

        ui->motivo->clear();
        ui->valor->clear();
    }
    if (ui->comboBox->currentText() == "Show") {
        on_pushButton_2_clicked();
        }

    else if(ui->comboBox->currentText() == "Delete DataBase" ){
        on_b_deleteDB_clicked();
        }
        else if(ui->comboBox->currentText() == "Sum"){
        on_cont_all_clicked();
    }

}

void MainWindow::ChangeModeLabel(QString name){
    qDebug()<< name;
    if(name != "Escolha"){
        ui->valor->setEnabled(false);
        ui->motivo->setEnabled(false);
        return;
    }
    ui->valor->setEnabled(true);
    ui->motivo->setEnabled(true);



}


void MainWindow::on_b_deleteDB_clicked()
{
    db_manage C_db;
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");

    QString path;
    path =  qApp->applicationDirPath() ;
    path +=  "/cach.db";

    C_db.Delete_db( path, db );
}


void MainWindow::on_pushButton_2_clicked()
{
    hide();
    Form *form= new Form;
    form->show();
}


void MainWindow::
    on_cont_all_clicked()
{
    cont_all *c_a = new cont_all();
    c_a->show();
    hide();
}


void MainWindow::on_place_button_clicked()
{
//    ui->b_deleteDB->setEnabled(true);
//    ui->place_button->hide();
}

QString MainWindow::read_version(){

    QFile f(qApp->applicationDirPath() + "/version");

    if(!f.open(QIODevice::ReadOnly)){
        qDebug() << "Erro ao tentar ler arquivo!";
        return "";
    }
    QTextStream read(&f);

    QString version = read.readAll();

    return version;
}
