/********************************************************************************
** Form generated from reading UI file 'LastSampleDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASTSAMPLEDIALOG_H
#define UI_LASTSAMPLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LastSampleDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioBtn_f;
    QRadioButton *radioBtn_r;
    QRadioButton *radioBtn_u;
    QRadioButton *radioBtn_b;
    QRadioButton *radioBtn_l;
    QRadioButton *radioBtn_d;
    QGridLayout *gridLayout;
    QPushButton *btn_sample7;
    QPushButton *btn_sample8;
    QPushButton *btn_sample5;
    QPushButton *btn_sample3;
    QPushButton *btn_sample6;
    QPushButton *btn_sample0;
    QPushButton *btn_sample1;
    QPushButton *btn_sample4;
    QPushButton *btn_sample2;

    void setupUi(QDialog *LastSampleDialog)
    {
        if (LastSampleDialog->objectName().isEmpty())
            LastSampleDialog->setObjectName(QStringLiteral("LastSampleDialog"));
        LastSampleDialog->resize(332, 378);
        verticalLayout = new QVBoxLayout(LastSampleDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(LastSampleDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 40));
        groupBox->setMaximumSize(QSize(16777215, 40));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioBtn_f = new QRadioButton(groupBox);
        radioBtn_f->setObjectName(QStringLiteral("radioBtn_f"));

        horizontalLayout->addWidget(radioBtn_f);

        radioBtn_r = new QRadioButton(groupBox);
        radioBtn_r->setObjectName(QStringLiteral("radioBtn_r"));

        horizontalLayout->addWidget(radioBtn_r);

        radioBtn_u = new QRadioButton(groupBox);
        radioBtn_u->setObjectName(QStringLiteral("radioBtn_u"));

        horizontalLayout->addWidget(radioBtn_u);

        radioBtn_b = new QRadioButton(groupBox);
        radioBtn_b->setObjectName(QStringLiteral("radioBtn_b"));

        horizontalLayout->addWidget(radioBtn_b);

        radioBtn_l = new QRadioButton(groupBox);
        radioBtn_l->setObjectName(QStringLiteral("radioBtn_l"));

        horizontalLayout->addWidget(radioBtn_l);

        radioBtn_d = new QRadioButton(groupBox);
        radioBtn_d->setObjectName(QStringLiteral("radioBtn_d"));

        horizontalLayout->addWidget(radioBtn_d);


        verticalLayout->addWidget(groupBox);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_sample7 = new QPushButton(LastSampleDialog);
        btn_sample7->setObjectName(QStringLiteral("btn_sample7"));
        btn_sample7->setMinimumSize(QSize(100, 100));
        btn_sample7->setMaximumSize(QSize(100, 100));
        btn_sample7->setIconSize(QSize(100, 100));
        btn_sample7->setFlat(false);

        gridLayout->addWidget(btn_sample7, 2, 1, 1, 1);

        btn_sample8 = new QPushButton(LastSampleDialog);
        btn_sample8->setObjectName(QStringLiteral("btn_sample8"));
        btn_sample8->setMinimumSize(QSize(100, 100));
        btn_sample8->setMaximumSize(QSize(100, 100));
        btn_sample8->setIconSize(QSize(100, 100));
        btn_sample8->setFlat(false);

        gridLayout->addWidget(btn_sample8, 2, 2, 1, 1);

        btn_sample5 = new QPushButton(LastSampleDialog);
        btn_sample5->setObjectName(QStringLiteral("btn_sample5"));
        btn_sample5->setMinimumSize(QSize(100, 100));
        btn_sample5->setMaximumSize(QSize(100, 100));
        btn_sample5->setIconSize(QSize(100, 100));
        btn_sample5->setFlat(false);

        gridLayout->addWidget(btn_sample5, 1, 2, 1, 1);

        btn_sample3 = new QPushButton(LastSampleDialog);
        btn_sample3->setObjectName(QStringLiteral("btn_sample3"));
        btn_sample3->setMinimumSize(QSize(100, 100));
        btn_sample3->setMaximumSize(QSize(100, 100));
        btn_sample3->setIconSize(QSize(100, 100));
        btn_sample3->setFlat(false);

        gridLayout->addWidget(btn_sample3, 1, 0, 1, 1);

        btn_sample6 = new QPushButton(LastSampleDialog);
        btn_sample6->setObjectName(QStringLiteral("btn_sample6"));
        btn_sample6->setMinimumSize(QSize(100, 100));
        btn_sample6->setMaximumSize(QSize(100, 100));
        btn_sample6->setIconSize(QSize(100, 100));
        btn_sample6->setFlat(false);

        gridLayout->addWidget(btn_sample6, 2, 0, 1, 1);

        btn_sample0 = new QPushButton(LastSampleDialog);
        btn_sample0->setObjectName(QStringLiteral("btn_sample0"));
        btn_sample0->setMinimumSize(QSize(100, 100));
        btn_sample0->setMaximumSize(QSize(100, 100));
        btn_sample0->setIconSize(QSize(100, 100));
        btn_sample0->setFlat(false);

        gridLayout->addWidget(btn_sample0, 0, 0, 1, 1);

        btn_sample1 = new QPushButton(LastSampleDialog);
        btn_sample1->setObjectName(QStringLiteral("btn_sample1"));
        btn_sample1->setMinimumSize(QSize(100, 100));
        btn_sample1->setMaximumSize(QSize(100, 100));
        btn_sample1->setIconSize(QSize(100, 100));
        btn_sample1->setFlat(false);

        gridLayout->addWidget(btn_sample1, 0, 1, 1, 1);

        btn_sample4 = new QPushButton(LastSampleDialog);
        btn_sample4->setObjectName(QStringLiteral("btn_sample4"));
        btn_sample4->setMinimumSize(QSize(100, 100));
        btn_sample4->setMaximumSize(QSize(100, 100));
        btn_sample4->setIconSize(QSize(100, 100));
        btn_sample4->setFlat(false);

        gridLayout->addWidget(btn_sample4, 1, 1, 1, 1);

        btn_sample2 = new QPushButton(LastSampleDialog);
        btn_sample2->setObjectName(QStringLiteral("btn_sample2"));
        btn_sample2->setMinimumSize(QSize(100, 100));
        btn_sample2->setMaximumSize(QSize(100, 100));
        btn_sample2->setIconSize(QSize(100, 100));
        btn_sample2->setFlat(false);

        gridLayout->addWidget(btn_sample2, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(LastSampleDialog);

        QMetaObject::connectSlotsByName(LastSampleDialog);
    } // setupUi

    void retranslateUi(QDialog *LastSampleDialog)
    {
        LastSampleDialog->setWindowTitle(QApplication::translate("LastSampleDialog", "LastSampleDialog", Q_NULLPTR));
        groupBox->setTitle(QString());
        radioBtn_f->setText(QApplication::translate("LastSampleDialog", "F", Q_NULLPTR));
        radioBtn_r->setText(QApplication::translate("LastSampleDialog", "R", Q_NULLPTR));
        radioBtn_u->setText(QApplication::translate("LastSampleDialog", "U", Q_NULLPTR));
        radioBtn_b->setText(QApplication::translate("LastSampleDialog", "B", Q_NULLPTR));
        radioBtn_l->setText(QApplication::translate("LastSampleDialog", "L", Q_NULLPTR));
        radioBtn_d->setText(QApplication::translate("LastSampleDialog", "D", Q_NULLPTR));
        btn_sample7->setText(QString());
        btn_sample8->setText(QString());
        btn_sample5->setText(QString());
        btn_sample3->setText(QString());
        btn_sample6->setText(QString());
        btn_sample0->setText(QString());
        btn_sample1->setText(QString());
        btn_sample4->setText(QString());
        btn_sample2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LastSampleDialog: public Ui_LastSampleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASTSAMPLEDIALOG_H
