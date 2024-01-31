#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "db_manage.h"
#include <QDebug>
#include "form.h"
#include "cont_all.h"
#include "choose.h"
#include <QFile>
#include <QComboBox>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // conecting sinais and slots

    connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)) ,this, SLOT(ChangeModeLabel(QString)) );
    connect(ui->radioButton, SIGNAL(clicked(bool)), this, SLOT(radio_change(bool)));
    connect(ui->radioButton_2, SIGNAL(clicked(bool)), this, SLOT(radio_change1(bool)));


    this->setWindowTitle("Banc Manage");
    QString version = read_version();
    ui->label_5->setText(version);
    ui->lineEdit->hide();
    ui->label_6->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{


    db_manage C_db;


    qDebug()<<ui->lineEdit->text();

    QString preço = ui->valor->text();
    QString motivo = ui->motivo->text();
    QString divida = ui->lineEdit->text();

    if( !ui->motivo->text().isEmpty() && !ui->valor->text().isEmpty() && ui->lineEdit->isHidden() ){
        C_db.insert(preço, motivo);
    }else if( !ui->motivo->text().isEmpty() && !ui->valor->text().isEmpty() && !ui->lineEdit->isHidden() && !ui->lineEdit->text().isEmpty()){
        C_db.insertDivida(preço, motivo, divida);
    }
    ui->motivo->clear();
    ui->valor->clear();
    ui->lineEdit->clear();

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
    if(name != "Escolha" ){
        ui->valor->setEnabled(false);
        ui->motivo->setEnabled(false);
        return;
    }
    ui->valor->setEnabled(true);
    ui->motivo->setEnabled(true);



}



QString MainWindow::getCombobox(){
    return ui->comboBox->currentText();
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

void MainWindow::on_cont_all_clicked()
{
    cont_all *c_a = new cont_all();
    c_a->show();
    hide();
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

void MainWindow::radio_change(bool is_active){
    if(is_active){
            // get position of last widgets

            int posx_button = ui->pushButton->geometry().x();
            int posy_button = ui->pushButton->geometry().y();
            int height_button = ui->pushButton->geometry().height();
            int width_button = ui->pushButton->geometry().width();

            //////////////////////////////////////////////////////

            ui->pushButton->setGeometry(posx_button, 480, width_button, height_button);

            ui->label_6->setHidden(false);
            ui->lineEdit->setHidden(false);

        }
}

void MainWindow::radio_change1(bool is_active){
        if(is_active){
            ui->label_6->hide();
            ui->lineEdit->hide();
            ui->pushButton->setGeometry(130, 430, 150, 51);
        }
}

QString MainWindow::getDivida(){
        return divida;
}
void MainWindow::on_pushButton_2_clicked()
{
        hide();
        choose *c = new choose();
        c->show();

}

bool MainWindow::getDivida_IsHiden(){
        return ui->lineEdit->isHidden();
}
