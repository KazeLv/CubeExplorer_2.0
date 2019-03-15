/********************************************************************************
** Form generated from reading UI file 'HSVDataDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HSVDATADIALOG_H
#define UI_HSVDATADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HSVDataDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *HSVDataDialog)
    {
        if (HSVDataDialog->objectName().isEmpty())
            HSVDataDialog->setObjectName(QStringLiteral("HSVDataDialog"));
        HSVDataDialog->resize(555, 419);
        horizontalLayout = new QHBoxLayout(HSVDataDialog);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(HSVDataDialog);

        QMetaObject::connectSlotsByName(HSVDataDialog);
    } // setupUi

    void retranslateUi(QDialog *HSVDataDialog)
    {
        HSVDataDialog->setWindowTitle(QApplication::translate("HSVDataDialog", "HSVDataDialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HSVDataDialog: public Ui_HSVDataDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HSVDATADIALOG_H
