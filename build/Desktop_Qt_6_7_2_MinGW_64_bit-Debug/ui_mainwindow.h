/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *valor;
    QLineEdit *motivo;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1890, 920);
        MainWindow->setStyleSheet(QString::fromUtf8("/*background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(0, 0, 0, 107), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));*/\n"
"\n"
"background-color: #1A1B1C;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(750, 60, 371, 311));
        label->setStyleSheet(QString::fromUtf8("background-color: transparent ;\n"
"border-image: url(:/new/1355772349a91d6fd6ea7ee29c9c5f50-a-cone-de-dinheiro-de-moeda-de-cifra-o.png);"));
        valor = new QLineEdit(centralwidget);
        valor->setObjectName("valor");
        valor->setGeometry(QRect(730, 550, 500, 50));
        valor->setStyleSheet(QString::fromUtf8("color: grey;\n"
"padding-left: 15px ; "));
        motivo = new QLineEdit(centralwidget);
        motivo->setObjectName("motivo");
        motivo->setGeometry(QRect(730, 630, 500, 50));
        motivo->setStyleSheet(QString::fromUtf8("color: grey;\n"
"padding-left: 15px ;"));
        motivo->setCursorMoveStyle(Qt::VisualMoveStyle);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(830, 720, 281, 61));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #453a38;\n"
"border-radius: 15px ;\n"
"font-size: 35px ;\n"
"font-weight: bold ;\n"
"color: white ;\n"
"}\n"
"QPushButton::hover{  \n"
"background-color: #f1632d;\n"
"border-radius: 15px ;\n"
"color: black ;\n"
"}\n"
"\n"
"QPushButton::pressed{  \n"
"border-radius: 15px ;\n"
"	background-color: rgb(246, 211, 45);\n"
"}\n"
""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(830, 220, 181, 41));
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent ; "));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(630, 560, 67, 21));
        label_3->setStyleSheet(QString::fromUtf8("background: transparent ;\n"
"font-size: 22px ;\n"
"color: white ;"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(630, 640, 81, 21));
        label_4->setStyleSheet(QString::fromUtf8("background: transparent ;\n"
"font-size: 22px ;\n"
"color: white ;"));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(1540, 20, 311, 61));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 29, 29); \n"
"font-size: 35px ;\n"
"font-weight: bold ;\n"
"color: #322886 ;\n"
"padding-left: 25px ;"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(920, 990, 151, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(26, 95, 180);"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(730, 710, 500, 50));
        lineEdit->setStyleSheet(QString::fromUtf8("color: grey;\n"
"padding-left: 15px ;"));
        lineEdit->setCursorMoveStyle(Qt::VisualMoveStyle);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(630, 720, 67, 21));
        label_6->setStyleSheet(QString::fromUtf8("background: transparent ;\n"
"font-size: 22px ;\n"
"color: white ;"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 20, 171, 121));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName("radioButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy);
        radioButton->setStyleSheet(QString::fromUtf8("background: transparent ;\n"
"font-size: 22px ;\n"
"font-weight: bold ;\n"
"color: white ;"));

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName("radioButton_2");
        sizePolicy.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy);
        radioButton_2->setStyleSheet(QString::fromUtf8("background: transparent ;\n"
"font-size: 22px ;\n"
"font-weight: bold ;\n"
"color: white ;"));

        verticalLayout->addWidget(radioButton_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        valor->setPlaceholderText(QCoreApplication::translate("MainWindow", "           Valor de pagamento", nullptr));
        motivo->setPlaceholderText(QCoreApplication::translate("MainWindow", "         Descri\303\247\303\243o de pagamento", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Enviar", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Value:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Explain:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Escolha", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Show", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Delete DataBase", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Sum", nullptr));

        label_5->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "                  DD/MM/YYYY", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Data:", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "D\303\255vida", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Gastos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
