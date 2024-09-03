/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(611, 638);
        Form->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));
        tableWidget = new QTableWidget(Form);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(90, 120, 431, 441));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123);"));
        label = new QLabel(Form);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 40, 301, 51));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(-20, 560, 101, 71));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("border-radius: 18px ;\n"
"background-color: rgb(119, 118, 123);padding-left: 25px ;"));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "Show Manage D\303\255vidas", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
