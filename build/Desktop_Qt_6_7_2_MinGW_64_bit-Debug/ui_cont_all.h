/********************************************************************************
** Form generated from reading UI file 'cont_all.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONT_ALL_H
#define UI_CONT_ALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cont_all
{
public:
    QLCDNumber *lcdNumber;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *cont_all)
    {
        if (cont_all->objectName().isEmpty())
            cont_all->setObjectName("cont_all");
        cont_all->resize(400, 300);
        lcdNumber = new QLCDNumber(cont_all);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(80, 90, 241, 121));
        label = new QLabel(cont_all);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 20, 241, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("LM Roman Unslanted 10")});
        font.setBold(true);
        label->setFont(font);
        pushButton = new QPushButton(cont_all);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(-20, 220, 88, 51));
        pushButton->setStyleSheet(QString::fromUtf8("border-radius: 15px ;\n"
"background-color: white ; "));

        retranslateUi(cont_all);

        QMetaObject::connectSlotsByName(cont_all);
    } // setupUi

    void retranslateUi(QWidget *cont_all)
    {
        cont_all->setWindowTitle(QCoreApplication::translate("cont_all", "Form", nullptr));
        label->setText(QCoreApplication::translate("cont_all", "VALOR TOTAL DOS GASTOS", nullptr));
        pushButton->setText(QCoreApplication::translate("cont_all", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cont_all: public Ui_cont_all {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONT_ALL_H
