#include "cont_all.h"
#include "ui_cont_all.h"
#include "db_manage.h"
#include "mainwindow.h"
#include <QDebug>
#include <QTimer>

cont_all::cont_all(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cont_all)
{
    ui->setupUi(this);
    MainWindow mw;
    this->setWindowTitle("TOTAL");

//    QTimer* timer;

//    timer = new QTimer(this);
//    timer->setSingleShot(true);

//    connect(timer, SIGNAL(timeout()), this, SLOT(Slot_execute(QString)));
//    timer->start(10000);


}



cont_all::~cont_all()
{
    delete ui;
}


void cont_all::Slot_execute(QString name){
    qDebug()<<"Nome in slot: " << name;
//    MainWindow mw;
//    QString modeSum = mw.getActiveRadio();
//    qDebug() << modeSum;

    QSqlDatabase db;
    QString path = qApp->applicationDirPath() + "/cach.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db_manage db_m;
    db_m.openDB(path, db);
    db_m.Sum(db, ui->lcdNumber, name);
}

void cont_all::ChangeSum(bool mode){
    //pass
}


void cont_all::on_pushButton_clicked()
{
    MainWindow *mw = new MainWindow();
    mw->show();
    hide();
}

