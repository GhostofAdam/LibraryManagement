/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(480, 640);
        buttonBox = new QDialogButtonBox(Register);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(390, 10, 81, 621));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Register);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 30, 72, 15));
        lineEdit = new QLineEdit(Register);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 70, 113, 21));
        lineEdit_2 = new QLineEdit(Register);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 130, 113, 21));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        lineEdit_3 = new QLineEdit(Register);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 190, 113, 21));
        lineEdit_3->setEchoMode(QLineEdit::Password);
        lineEdit_4 = new QLineEdit(Register);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(130, 250, 113, 21));
        lineEdit_5 = new QLineEdit(Register);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(130, 310, 113, 21));
        label_2 = new QLabel(Register);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 72, 15));
        label_3 = new QLabel(Register);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 130, 72, 15));
        label_4 = new QLabel(Register);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 190, 72, 15));
        label_5 = new QLabel(Register);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 250, 72, 15));
        label_6 = new QLabel(Register);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 310, 72, 15));

        retranslateUi(Register);
        QObject::connect(buttonBox, SIGNAL(accepted()), Register, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Register, SLOT(reject()));

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Register", "\346\263\250\345\206\214", Q_NULLPTR));
        label_2->setText(QApplication::translate("Register", "\350\264\246\345\217\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("Register", "\345\257\206\347\240\201", Q_NULLPTR));
        label_4->setText(QApplication::translate("Register", "\345\257\206\347\240\201\347\241\256\350\256\244", Q_NULLPTR));
        label_5->setText(QApplication::translate("Register", "\346\200\247\345\210\253", Q_NULLPTR));
        label_6->setText(QApplication::translate("Register", "\345\255\246\345\217\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
