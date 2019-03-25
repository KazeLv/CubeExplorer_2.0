/********************************************************************************
** Form generated from reading UI file 'HSVThresholdDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HSVTHRESHOLDDIALOG_H
#define UI_HSVTHRESHOLDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HSVThresholdDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_face;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioBtn_f;
    QRadioButton *radioBtn_r;
    QRadioButton *radioBtn_u;
    QRadioButton *radioBtn_b;
    QRadioButton *radioBtn_l;
    QRadioButton *radioBtn_d;
    QHBoxLayout *hLay_hsv;
    QGroupBox *groupBox_color;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_25;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QGroupBox *groupBox_H;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spin_redH_h_min;
    QLabel *label_2;
    QSpinBox *spin_redH_h_max;
    QHBoxLayout *horizontalLayout_21;
    QSpinBox *spin_redL_h_min;
    QLabel *label_26;
    QSpinBox *spin_redL_h_max;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *spin_orange_h_min;
    QLabel *label_10;
    QSpinBox *spin_orange_h_max;
    QHBoxLayout *horizontalLayout_7;
    QSpinBox *spin_blue_h_min;
    QLabel *label_11;
    QSpinBox *spin_blue_h_max;
    QHBoxLayout *horizontalLayout_8;
    QSpinBox *spin_green_h_min;
    QLabel *label_12;
    QSpinBox *spin_green_h_max;
    QHBoxLayout *horizontalLayout_9;
    QSpinBox *spin_yellow_h_min;
    QLabel *label_13;
    QSpinBox *spin_yellow_h_max;
    QHBoxLayout *horizontalLayout_10;
    QSpinBox *spin_white_h_min;
    QLabel *label_14;
    QSpinBox *spin_white_h_max;
    QGroupBox *groupBox_S;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *spin_redH_s_min;
    QLabel *label_3;
    QSpinBox *spin_redH_s_max;
    QHBoxLayout *horizontalLayout_22;
    QSpinBox *spin_redL_s_min;
    QLabel *label_27;
    QSpinBox *spin_redL_s_max;
    QHBoxLayout *horizontalLayout_11;
    QSpinBox *spin_orange_s_min;
    QLabel *label_15;
    QSpinBox *spin_orange_s_max;
    QHBoxLayout *horizontalLayout_12;
    QSpinBox *spin_blue_s_min;
    QLabel *label_16;
    QSpinBox *spin_blue_s_max;
    QHBoxLayout *horizontalLayout_13;
    QSpinBox *spin_green_s_min;
    QLabel *label_17;
    QSpinBox *spin_green_s_max;
    QHBoxLayout *horizontalLayout_14;
    QSpinBox *spin_yellow_s_min;
    QLabel *label_18;
    QSpinBox *spin_yellow_s_max;
    QHBoxLayout *horizontalLayout_15;
    QSpinBox *spin_white_s_min;
    QLabel *label_19;
    QSpinBox *spin_white_s_max;
    QGroupBox *groupBox_V;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *spin_redH_v_min;
    QLabel *label_4;
    QSpinBox *spin_redH_v_max;
    QHBoxLayout *horizontalLayout_23;
    QSpinBox *spin_redL_v_min;
    QLabel *label_28;
    QSpinBox *spin_redL_v_max;
    QHBoxLayout *horizontalLayout_16;
    QSpinBox *spin_orange_v_min;
    QLabel *label_20;
    QSpinBox *spin_orange_v_max;
    QHBoxLayout *horizontalLayout_17;
    QSpinBox *spin_blue_v_min;
    QLabel *label_21;
    QSpinBox *spin_blue_v_max;
    QHBoxLayout *horizontalLayout_18;
    QSpinBox *spin_green_v_min;
    QLabel *label_22;
    QSpinBox *spin_green_v_max;
    QHBoxLayout *horizontalLayout_19;
    QSpinBox *spin_yellow_v_min;
    QLabel *label_23;
    QSpinBox *spin_yellow_v_max;
    QHBoxLayout *horizontalLayout_20;
    QSpinBox *spin_white_v_min;
    QLabel *label_24;
    QSpinBox *spin_white_v_max;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_reset;
    QPushButton *btn_apply;
    QPushButton *btn_cancel;

    void setupUi(QDialog *HSVThresholdDialog)
    {
        if (HSVThresholdDialog->objectName().isEmpty())
            HSVThresholdDialog->setObjectName(QStringLiteral("HSVThresholdDialog"));
        HSVThresholdDialog->resize(624, 323);
        verticalLayout_2 = new QVBoxLayout(HSVThresholdDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_face = new QGroupBox(HSVThresholdDialog);
        groupBox_face->setObjectName(QStringLiteral("groupBox_face"));
        groupBox_face->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_3 = new QHBoxLayout(groupBox_face);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        radioBtn_f = new QRadioButton(groupBox_face);
        radioBtn_f->setObjectName(QStringLiteral("radioBtn_f"));
        radioBtn_f->setProperty("tag_face", QVariant(QChar(102)));

        horizontalLayout_3->addWidget(radioBtn_f);

        radioBtn_r = new QRadioButton(groupBox_face);
        radioBtn_r->setObjectName(QStringLiteral("radioBtn_r"));
        radioBtn_r->setProperty("tag_face", QVariant(QChar(114)));

        horizontalLayout_3->addWidget(radioBtn_r);

        radioBtn_u = new QRadioButton(groupBox_face);
        radioBtn_u->setObjectName(QStringLiteral("radioBtn_u"));
        radioBtn_u->setProperty("tag_face", QVariant(QChar(117)));

        horizontalLayout_3->addWidget(radioBtn_u);

        radioBtn_b = new QRadioButton(groupBox_face);
        radioBtn_b->setObjectName(QStringLiteral("radioBtn_b"));
        radioBtn_b->setProperty("tag_face", QVariant(QChar(98)));

        horizontalLayout_3->addWidget(radioBtn_b);

        radioBtn_l = new QRadioButton(groupBox_face);
        radioBtn_l->setObjectName(QStringLiteral("radioBtn_l"));
        radioBtn_l->setProperty("tag_face", QVariant(QChar(108)));

        horizontalLayout_3->addWidget(radioBtn_l);

        radioBtn_d = new QRadioButton(groupBox_face);
        radioBtn_d->setObjectName(QStringLiteral("radioBtn_d"));
        radioBtn_d->setProperty("tag_face", QVariant(QChar(100)));

        horizontalLayout_3->addWidget(radioBtn_d);


        verticalLayout_2->addWidget(groupBox_face);

        hLay_hsv = new QHBoxLayout();
        hLay_hsv->setSpacing(6);
        hLay_hsv->setObjectName(QStringLiteral("hLay_hsv"));
        groupBox_color = new QGroupBox(HSVThresholdDialog);
        groupBox_color->setObjectName(QStringLiteral("groupBox_color"));
        groupBox_color->setMaximumSize(QSize(50, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_color);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox_color);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_25 = new QLabel(groupBox_color);
        label_25->setObjectName(QStringLiteral("label_25"));

        verticalLayout->addWidget(label_25);

        label_5 = new QLabel(groupBox_color);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(groupBox_color);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(groupBox_color);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(groupBox_color);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(groupBox_color);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout->addWidget(label_9);


        hLay_hsv->addWidget(groupBox_color);

        groupBox_H = new QGroupBox(HSVThresholdDialog);
        groupBox_H->setObjectName(QStringLiteral("groupBox_H"));
        groupBox_H->setMinimumSize(QSize(180, 0));
        verticalLayout_5 = new QVBoxLayout(groupBox_H);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        spin_redH_h_min = new QSpinBox(groupBox_H);
        spin_redH_h_min->setObjectName(QStringLiteral("spin_redH_h_min"));
        spin_redH_h_min->setMaximum(180);
        spin_redH_h_min->setProperty("min", QVariant(true));
        spin_redH_h_min->setProperty("tag_hsv", QVariant(QChar(104)));

        horizontalLayout_2->addWidget(spin_redH_h_min);

        label_2 = new QLabel(groupBox_H);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(false);

        horizontalLayout_2->addWidget(label_2);

        spin_redH_h_max = new QSpinBox(groupBox_H);
        spin_redH_h_max->setObjectName(QStringLiteral("spin_redH_h_max"));
        spin_redH_h_max->setMaximum(180);
        spin_redH_h_max->setProperty("min", QVariant(false));
        spin_redH_h_max->setProperty("tag_hsv", QVariant(QChar(104)));

        horizontalLayout_2->addWidget(spin_redH_h_max);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        spin_redL_h_min = new QSpinBox(groupBox_H);
        spin_redL_h_min->setObjectName(QStringLiteral("spin_redL_h_min"));
        spin_redL_h_min->setMaximum(180);
        spin_redL_h_min->setProperty("min", QVariant(true));
        spin_redL_h_min->setProperty("tag_hsv", QVariant(QChar(104)));

        horizontalLayout_21->addWidget(spin_redL_h_min);

        label_26 = new QLabel(groupBox_H);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setScaledContents(true);
        label_26->setAlignment(Qt::AlignCenter);
        label_26->setWordWrap(false);

        horizontalLayout_21->addWidget(label_26);

        spin_redL_h_max = new QSpinBox(groupBox_H);
        spin_redL_h_max->setObjectName(QStringLiteral("spin_redL_h_max"));
        spin_redL_h_max->setMaximum(180);
        spin_redL_h_max->setProperty("min", QVariant(false));
        spin_redL_h_max->setProperty("tag_hsv", QVariant(QChar(104)));

        horizontalLayout_21->addWidget(spin_redL_h_max);


        verticalLayout_5->addLayout(horizontalLayout_21);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        spin_orange_h_min = new QSpinBox(groupBox_H);
        spin_orange_h_min->setObjectName(QStringLiteral("spin_orange_h_min"));
        spin_orange_h_min->setMaximum(180);
        spin_orange_h_min->setProperty("min", QVariant(true));
        spin_orange_h_min->setProperty("tag_hsv", QVariant(QChar(104)));

        horizontalLayout_6->addWidget(spin_orange_h_min);

        label_10 = new QLabel(groupBox_H);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setScaledContents(true);
        label_10->setAlignment(Qt::AlignCenter);
        label_10->setWordWrap(false);

        horizontalLayout_6->addWidget(label_10);

        spin_orange_h_max = new QSpinBox(groupBox_H);
        spin_orange_h_max->setObjectName(QStringLiteral("spin_orange_h_max"));
        spin_orange_h_max->setMaximum(180);
        spin_orange_h_max->setProperty("min", QVariant(false));
        spin_orange_h_max->setProperty("tag_hsv", QVariant(QChar(104)));

        horizontalLayout_6->addWidget(spin_orange_h_max);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        spin_blue_h_min = new QSpinBox(groupBox_H);
        spin_blue_h_min->setObjectName(QStringLiteral("spin_blue_h_min"));
        spin_blue_h_min->setMaximum(180);
        spin_blue_h_min->setProperty("min", QVariant(true));
        spin_blue_h_min->setProperty("tag_hsv", QVariant(QChar(104)));

        horizontalLayout_7->addWidget(spin_blue_h_min);

        label_11 = new QLabel(groupBox_H);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setScaledContents(true);
        label_11->setAlignment(Qt::AlignCenter);
        label_11->setWordWrap(false);

        horizontalLayout_7->addWidget(label_11);

        spin_blue_h_max = new QSpinBox(groupBox_H);
        spin_blue_h_max->setObjectName(QStringLiteral("spin_blue_h_max"));
        spin_blue_h_max->setMaximum(180);
        spin_blue_h_max->setProperty("min", QVariant(false));
        spin_blue_h_max->setProperty("tag_hsv", QVariant(QChar(104)));

        horizontalLayout_7->addWidget(spin_blue_h_max);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        spin_green_h_min = new QSpinBox(groupBox_H);
        spin_green_h_min->setObjectName(QStringLiteral("spin_green_h_min"));
        spin_green_h_min->setMaximum(180);
        spin_green_h_min->setProperty("min", QVariant(true));
        spin_green_h_min->setProperty("tag_hsv", QVariant(QChar(104)));

        horizontalLayout_8->addWidget(spin_green_h_min);

        label_12 = new QLabel(groupBox_H);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setScaledContents(true);
        label_12->setAlignment(Qt::AlignCenter);
        label_12->setWordWrap(false);

        horizontalLayout_8->addWidget(label_12);

        spin_green_h_max = new QSpinBox(groupBox_H);
        spin_green_h_max->setObjectName(QStringLiteral("spin_green_h_max"));
        spin_green_h_max->setMaximum(180);
        spin_green_h_max->setProperty("min", QVariant(false));
        spin_green_h_max->setProperty("tag_hsv", QVariant(QChar(104)));

        horizontalLayout_8->addWidget(spin_green_h_max);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        spin_yellow_h_min = new QSpinBox(groupBox_H);
        spin_yellow_h_min->setObjectName(QStringLiteral("spin_yellow_h_min"));
        spin_yellow_h_min->setMaximum(180);
        spin_yellow_h_min->setProperty("min", QVariant(true));
        spin_yellow_h_min->setProperty("tag_hsv", QVariant(QChar(104)));

        horizontalLayout_9->addWidget(spin_yellow_h_min);

        label_13 = new QLabel(groupBox_H);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setScaledContents(true);
        label_13->setAlignment(Qt::AlignCenter);
        label_13->setWordWrap(false);

        horizontalLayout_9->addWidget(label_13);

        spin_yellow_h_max = new QSpinBox(groupBox_H);
        spin_yellow_h_max->setObjectName(QStringLiteral("spin_yellow_h_max"));
        spin_yellow_h_max->setMaximum(180);
        spin_yellow_h_max->setProperty("min", QVariant(false));
        spin_yellow_h_max->setProperty("tag_hsv", QVariant(QChar(104)));

        horizontalLayout_9->addWidget(spin_yellow_h_max);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        spin_white_h_min = new QSpinBox(groupBox_H);
        spin_white_h_min->setObjectName(QStringLiteral("spin_white_h_min"));
        spin_white_h_min->setMaximum(180);
        spin_white_h_min->setProperty("min", QVariant(true));
        spin_white_h_min->setProperty("tag_hsv", QVariant(QChar(104)));

        horizontalLayout_10->addWidget(spin_white_h_min);

        label_14 = new QLabel(groupBox_H);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setScaledContents(true);
        label_14->setAlignment(Qt::AlignCenter);
        label_14->setWordWrap(false);

        horizontalLayout_10->addWidget(label_14);

        spin_white_h_max = new QSpinBox(groupBox_H);
        spin_white_h_max->setObjectName(QStringLiteral("spin_white_h_max"));
        spin_white_h_max->setMaximum(180);
        spin_white_h_max->setProperty("min", QVariant(false));
        spin_white_h_max->setProperty("tag_hsv", QVariant(QChar(104)));

        horizontalLayout_10->addWidget(spin_white_h_max);


        verticalLayout_5->addLayout(horizontalLayout_10);


        hLay_hsv->addWidget(groupBox_H);

        groupBox_S = new QGroupBox(HSVThresholdDialog);
        groupBox_S->setObjectName(QStringLiteral("groupBox_S"));
        groupBox_S->setMinimumSize(QSize(180, 0));
        verticalLayout_6 = new QVBoxLayout(groupBox_S);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        spin_redH_s_min = new QSpinBox(groupBox_S);
        spin_redH_s_min->setObjectName(QStringLiteral("spin_redH_s_min"));
        spin_redH_s_min->setMaximum(255);
        spin_redH_s_min->setProperty("min", QVariant(true));
        spin_redH_s_min->setProperty("tag_hsv", QVariant(QChar(115)));

        horizontalLayout_4->addWidget(spin_redH_s_min);

        label_3 = new QLabel(groupBox_S);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setScaledContents(true);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(false);

        horizontalLayout_4->addWidget(label_3);

        spin_redH_s_max = new QSpinBox(groupBox_S);
        spin_redH_s_max->setObjectName(QStringLiteral("spin_redH_s_max"));
        spin_redH_s_max->setMaximum(255);
        spin_redH_s_max->setProperty("min", QVariant(false));
        spin_redH_s_max->setProperty("tag_hsv", QVariant(QChar(115)));

        horizontalLayout_4->addWidget(spin_redH_s_max);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        spin_redL_s_min = new QSpinBox(groupBox_S);
        spin_redL_s_min->setObjectName(QStringLiteral("spin_redL_s_min"));
        spin_redL_s_min->setMaximum(255);
        spin_redL_s_min->setProperty("min", QVariant(true));
        spin_redL_s_min->setProperty("tag_hsv", QVariant(QChar(115)));

        horizontalLayout_22->addWidget(spin_redL_s_min);

        label_27 = new QLabel(groupBox_S);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setScaledContents(true);
        label_27->setAlignment(Qt::AlignCenter);
        label_27->setWordWrap(false);

        horizontalLayout_22->addWidget(label_27);

        spin_redL_s_max = new QSpinBox(groupBox_S);
        spin_redL_s_max->setObjectName(QStringLiteral("spin_redL_s_max"));
        spin_redL_s_max->setMaximum(255);
        spin_redL_s_max->setProperty("min", QVariant(false));
        spin_redL_s_max->setProperty("tag_hsv", QVariant(QChar(115)));

        horizontalLayout_22->addWidget(spin_redL_s_max);


        verticalLayout_6->addLayout(horizontalLayout_22);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        spin_orange_s_min = new QSpinBox(groupBox_S);
        spin_orange_s_min->setObjectName(QStringLiteral("spin_orange_s_min"));
        spin_orange_s_min->setMaximum(255);
        spin_orange_s_min->setProperty("min", QVariant(true));
        spin_orange_s_min->setProperty("tag_hsv", QVariant(QChar(115)));

        horizontalLayout_11->addWidget(spin_orange_s_min);

        label_15 = new QLabel(groupBox_S);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setScaledContents(true);
        label_15->setAlignment(Qt::AlignCenter);
        label_15->setWordWrap(false);

        horizontalLayout_11->addWidget(label_15);

        spin_orange_s_max = new QSpinBox(groupBox_S);
        spin_orange_s_max->setObjectName(QStringLiteral("spin_orange_s_max"));
        spin_orange_s_max->setMaximum(255);
        spin_orange_s_max->setProperty("min", QVariant(false));
        spin_orange_s_max->setProperty("tag_hsv", QVariant(QChar(115)));

        horizontalLayout_11->addWidget(spin_orange_s_max);


        verticalLayout_6->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        spin_blue_s_min = new QSpinBox(groupBox_S);
        spin_blue_s_min->setObjectName(QStringLiteral("spin_blue_s_min"));
        spin_blue_s_min->setMaximum(255);
        spin_blue_s_min->setProperty("min", QVariant(true));
        spin_blue_s_min->setProperty("tag_hsv", QVariant(QChar(115)));

        horizontalLayout_12->addWidget(spin_blue_s_min);

        label_16 = new QLabel(groupBox_S);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setScaledContents(true);
        label_16->setAlignment(Qt::AlignCenter);
        label_16->setWordWrap(false);

        horizontalLayout_12->addWidget(label_16);

        spin_blue_s_max = new QSpinBox(groupBox_S);
        spin_blue_s_max->setObjectName(QStringLiteral("spin_blue_s_max"));
        spin_blue_s_max->setMaximum(255);
        spin_blue_s_max->setProperty("min", QVariant(false));
        spin_blue_s_max->setProperty("tag_hsv", QVariant(QChar(115)));

        horizontalLayout_12->addWidget(spin_blue_s_max);


        verticalLayout_6->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        spin_green_s_min = new QSpinBox(groupBox_S);
        spin_green_s_min->setObjectName(QStringLiteral("spin_green_s_min"));
        spin_green_s_min->setMaximum(255);
        spin_green_s_min->setProperty("min", QVariant(true));
        spin_green_s_min->setProperty("tag_hsv", QVariant(QChar(115)));

        horizontalLayout_13->addWidget(spin_green_s_min);

        label_17 = new QLabel(groupBox_S);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setScaledContents(true);
        label_17->setAlignment(Qt::AlignCenter);
        label_17->setWordWrap(false);

        horizontalLayout_13->addWidget(label_17);

        spin_green_s_max = new QSpinBox(groupBox_S);
        spin_green_s_max->setObjectName(QStringLiteral("spin_green_s_max"));
        spin_green_s_max->setMaximum(255);
        spin_green_s_max->setProperty("min", QVariant(false));
        spin_green_s_max->setProperty("tag_hsv", QVariant(QChar(115)));

        horizontalLayout_13->addWidget(spin_green_s_max);


        verticalLayout_6->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        spin_yellow_s_min = new QSpinBox(groupBox_S);
        spin_yellow_s_min->setObjectName(QStringLiteral("spin_yellow_s_min"));
        spin_yellow_s_min->setMaximum(255);
        spin_yellow_s_min->setProperty("min", QVariant(true));
        spin_yellow_s_min->setProperty("tag_hsv", QVariant(QChar(115)));

        horizontalLayout_14->addWidget(spin_yellow_s_min);

        label_18 = new QLabel(groupBox_S);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setScaledContents(true);
        label_18->setAlignment(Qt::AlignCenter);
        label_18->setWordWrap(false);

        horizontalLayout_14->addWidget(label_18);

        spin_yellow_s_max = new QSpinBox(groupBox_S);
        spin_yellow_s_max->setObjectName(QStringLiteral("spin_yellow_s_max"));
        spin_yellow_s_max->setMaximum(255);
        spin_yellow_s_max->setProperty("min", QVariant(false));
        spin_yellow_s_max->setProperty("tag_hsv", QVariant(QChar(115)));

        horizontalLayout_14->addWidget(spin_yellow_s_max);


        verticalLayout_6->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        spin_white_s_min = new QSpinBox(groupBox_S);
        spin_white_s_min->setObjectName(QStringLiteral("spin_white_s_min"));
        spin_white_s_min->setMaximum(255);
        spin_white_s_min->setProperty("min", QVariant(true));
        spin_white_s_min->setProperty("tag_hsv", QVariant(QChar(115)));

        horizontalLayout_15->addWidget(spin_white_s_min);

        label_19 = new QLabel(groupBox_S);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setScaledContents(true);
        label_19->setAlignment(Qt::AlignCenter);
        label_19->setWordWrap(false);

        horizontalLayout_15->addWidget(label_19);

        spin_white_s_max = new QSpinBox(groupBox_S);
        spin_white_s_max->setObjectName(QStringLiteral("spin_white_s_max"));
        spin_white_s_max->setMaximum(255);
        spin_white_s_max->setProperty("min", QVariant(false));
        spin_white_s_max->setProperty("tag_hsv", QVariant(QChar(115)));

        horizontalLayout_15->addWidget(spin_white_s_max);


        verticalLayout_6->addLayout(horizontalLayout_15);


        hLay_hsv->addWidget(groupBox_S);

        groupBox_V = new QGroupBox(HSVThresholdDialog);
        groupBox_V->setObjectName(QStringLiteral("groupBox_V"));
        groupBox_V->setMinimumSize(QSize(180, 0));
        verticalLayout_7 = new QVBoxLayout(groupBox_V);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        spin_redH_v_min = new QSpinBox(groupBox_V);
        spin_redH_v_min->setObjectName(QStringLiteral("spin_redH_v_min"));
        spin_redH_v_min->setMaximum(255);
        spin_redH_v_min->setProperty("min", QVariant(true));
        spin_redH_v_min->setProperty("tag_hsv", QVariant(QChar(118)));

        horizontalLayout_5->addWidget(spin_redH_v_min);

        label_4 = new QLabel(groupBox_V);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setScaledContents(true);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(false);

        horizontalLayout_5->addWidget(label_4);

        spin_redH_v_max = new QSpinBox(groupBox_V);
        spin_redH_v_max->setObjectName(QStringLiteral("spin_redH_v_max"));
        spin_redH_v_max->setMaximum(255);
        spin_redH_v_max->setProperty("min", QVariant(false));
        spin_redH_v_max->setProperty("tag_hsv", QVariant(QChar(118)));

        horizontalLayout_5->addWidget(spin_redH_v_max);


        verticalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        spin_redL_v_min = new QSpinBox(groupBox_V);
        spin_redL_v_min->setObjectName(QStringLiteral("spin_redL_v_min"));
        spin_redL_v_min->setMaximum(255);
        spin_redL_v_min->setProperty("min", QVariant(true));
        spin_redL_v_min->setProperty("tag_hsv", QVariant(QChar(118)));

        horizontalLayout_23->addWidget(spin_redL_v_min);

        label_28 = new QLabel(groupBox_V);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setScaledContents(true);
        label_28->setAlignment(Qt::AlignCenter);
        label_28->setWordWrap(false);

        horizontalLayout_23->addWidget(label_28);

        spin_redL_v_max = new QSpinBox(groupBox_V);
        spin_redL_v_max->setObjectName(QStringLiteral("spin_redL_v_max"));
        spin_redL_v_max->setMaximum(255);
        spin_redL_v_max->setProperty("min", QVariant(false));
        spin_redL_v_max->setProperty("tag_hsv", QVariant(QChar(118)));

        horizontalLayout_23->addWidget(spin_redL_v_max);


        verticalLayout_7->addLayout(horizontalLayout_23);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        spin_orange_v_min = new QSpinBox(groupBox_V);
        spin_orange_v_min->setObjectName(QStringLiteral("spin_orange_v_min"));
        spin_orange_v_min->setMaximum(255);
        spin_orange_v_min->setProperty("min", QVariant(true));
        spin_orange_v_min->setProperty("tag_hsv", QVariant(QChar(118)));

        horizontalLayout_16->addWidget(spin_orange_v_min);

        label_20 = new QLabel(groupBox_V);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setScaledContents(true);
        label_20->setAlignment(Qt::AlignCenter);
        label_20->setWordWrap(false);

        horizontalLayout_16->addWidget(label_20);

        spin_orange_v_max = new QSpinBox(groupBox_V);
        spin_orange_v_max->setObjectName(QStringLiteral("spin_orange_v_max"));
        spin_orange_v_max->setMaximum(255);
        spin_orange_v_max->setProperty("min", QVariant(false));
        spin_orange_v_max->setProperty("tag_hsv", QVariant(QChar(118)));

        horizontalLayout_16->addWidget(spin_orange_v_max);


        verticalLayout_7->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        spin_blue_v_min = new QSpinBox(groupBox_V);
        spin_blue_v_min->setObjectName(QStringLiteral("spin_blue_v_min"));
        spin_blue_v_min->setMaximum(255);
        spin_blue_v_min->setProperty("min", QVariant(true));
        spin_blue_v_min->setProperty("tag_hsv", QVariant(QChar(118)));

        horizontalLayout_17->addWidget(spin_blue_v_min);

        label_21 = new QLabel(groupBox_V);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setScaledContents(true);
        label_21->setAlignment(Qt::AlignCenter);
        label_21->setWordWrap(false);

        horizontalLayout_17->addWidget(label_21);

        spin_blue_v_max = new QSpinBox(groupBox_V);
        spin_blue_v_max->setObjectName(QStringLiteral("spin_blue_v_max"));
        spin_blue_v_max->setMaximum(255);
        spin_blue_v_max->setProperty("min", QVariant(false));
        spin_blue_v_max->setProperty("tag_hsv", QVariant(QChar(118)));

        horizontalLayout_17->addWidget(spin_blue_v_max);


        verticalLayout_7->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        spin_green_v_min = new QSpinBox(groupBox_V);
        spin_green_v_min->setObjectName(QStringLiteral("spin_green_v_min"));
        spin_green_v_min->setMaximum(255);
        spin_green_v_min->setProperty("min", QVariant(true));
        spin_green_v_min->setProperty("tag_hsv", QVariant(QChar(118)));

        horizontalLayout_18->addWidget(spin_green_v_min);

        label_22 = new QLabel(groupBox_V);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setScaledContents(true);
        label_22->setAlignment(Qt::AlignCenter);
        label_22->setWordWrap(false);

        horizontalLayout_18->addWidget(label_22);

        spin_green_v_max = new QSpinBox(groupBox_V);
        spin_green_v_max->setObjectName(QStringLiteral("spin_green_v_max"));
        spin_green_v_max->setMaximum(255);
        spin_green_v_max->setProperty("min", QVariant(false));
        spin_green_v_max->setProperty("tag_hsv", QVariant(QChar(118)));

        horizontalLayout_18->addWidget(spin_green_v_max);


        verticalLayout_7->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        spin_yellow_v_min = new QSpinBox(groupBox_V);
        spin_yellow_v_min->setObjectName(QStringLiteral("spin_yellow_v_min"));
        spin_yellow_v_min->setMaximum(255);
        spin_yellow_v_min->setProperty("min", QVariant(true));
        spin_yellow_v_min->setProperty("tag_hsv", QVariant(QChar(118)));

        horizontalLayout_19->addWidget(spin_yellow_v_min);

        label_23 = new QLabel(groupBox_V);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setScaledContents(true);
        label_23->setAlignment(Qt::AlignCenter);
        label_23->setWordWrap(false);

        horizontalLayout_19->addWidget(label_23);

        spin_yellow_v_max = new QSpinBox(groupBox_V);
        spin_yellow_v_max->setObjectName(QStringLiteral("spin_yellow_v_max"));
        spin_yellow_v_max->setMaximum(255);
        spin_yellow_v_max->setProperty("min", QVariant(false));
        spin_yellow_v_max->setProperty("tag_hsv", QVariant(QChar(118)));

        horizontalLayout_19->addWidget(spin_yellow_v_max);


        verticalLayout_7->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        spin_white_v_min = new QSpinBox(groupBox_V);
        spin_white_v_min->setObjectName(QStringLiteral("spin_white_v_min"));
        spin_white_v_min->setMaximum(255);
        spin_white_v_min->setProperty("min", QVariant(true));
        spin_white_v_min->setProperty("tag_hsv", QVariant(QChar(118)));

        horizontalLayout_20->addWidget(spin_white_v_min);

        label_24 = new QLabel(groupBox_V);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setScaledContents(true);
        label_24->setAlignment(Qt::AlignCenter);
        label_24->setWordWrap(false);

        horizontalLayout_20->addWidget(label_24);

        spin_white_v_max = new QSpinBox(groupBox_V);
        spin_white_v_max->setObjectName(QStringLiteral("spin_white_v_max"));
        spin_white_v_max->setMaximum(255);
        spin_white_v_max->setProperty("min", QVariant(false));
        spin_white_v_max->setProperty("tag_hsv", QVariant(QChar(118)));

        horizontalLayout_20->addWidget(spin_white_v_max);


        verticalLayout_7->addLayout(horizontalLayout_20);


        hLay_hsv->addWidget(groupBox_V);


        verticalLayout_2->addLayout(hLay_hsv);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_reset = new QPushButton(HSVThresholdDialog);
        btn_reset->setObjectName(QStringLiteral("btn_reset"));
        btn_reset->setMinimumSize(QSize(100, 25));

        horizontalLayout->addWidget(btn_reset);

        btn_apply = new QPushButton(HSVThresholdDialog);
        btn_apply->setObjectName(QStringLiteral("btn_apply"));
        btn_apply->setMinimumSize(QSize(100, 25));

        horizontalLayout->addWidget(btn_apply);

        btn_cancel = new QPushButton(HSVThresholdDialog);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));
        btn_cancel->setMinimumSize(QSize(100, 25));

        horizontalLayout->addWidget(btn_cancel);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(HSVThresholdDialog);

        QMetaObject::connectSlotsByName(HSVThresholdDialog);
    } // setupUi

    void retranslateUi(QDialog *HSVThresholdDialog)
    {
        HSVThresholdDialog->setWindowTitle(QApplication::translate("HSVThresholdDialog", "HSVThresholdDialog", Q_NULLPTR));
        radioBtn_f->setText(QApplication::translate("HSVThresholdDialog", "F", Q_NULLPTR));
        radioBtn_r->setText(QApplication::translate("HSVThresholdDialog", "R", Q_NULLPTR));
        radioBtn_u->setText(QApplication::translate("HSVThresholdDialog", "U", Q_NULLPTR));
        radioBtn_b->setText(QApplication::translate("HSVThresholdDialog", "B", Q_NULLPTR));
        radioBtn_l->setText(QApplication::translate("HSVThresholdDialog", "L", Q_NULLPTR));
        radioBtn_d->setText(QApplication::translate("HSVThresholdDialog", "D", Q_NULLPTR));
        groupBox_color->setTitle(QApplication::translate("HSVThresholdDialog", "\351\242\234\350\211\262", Q_NULLPTR));
        label->setText(QApplication::translate("HSVThresholdDialog", "\347\272\242H", Q_NULLPTR));
        label_25->setText(QApplication::translate("HSVThresholdDialog", "\347\272\242L", Q_NULLPTR));
        label_5->setText(QApplication::translate("HSVThresholdDialog", "\346\251\231", Q_NULLPTR));
        label_6->setText(QApplication::translate("HSVThresholdDialog", "\350\223\235", Q_NULLPTR));
        label_7->setText(QApplication::translate("HSVThresholdDialog", "\347\273\277", Q_NULLPTR));
        label_8->setText(QApplication::translate("HSVThresholdDialog", "\351\273\204", Q_NULLPTR));
        label_9->setText(QApplication::translate("HSVThresholdDialog", "\347\231\275", Q_NULLPTR));
        groupBox_H->setTitle(QApplication::translate("HSVThresholdDialog", "H (0-180)", Q_NULLPTR));
        spin_redH_h_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "red_h", Q_NULLPTR)));
        label_2->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_redH_h_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "red_h", Q_NULLPTR)));
        spin_redL_h_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "red_l", Q_NULLPTR)));
        label_26->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_redL_h_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "red_l", Q_NULLPTR)));
        spin_orange_h_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "orange", Q_NULLPTR)));
        label_10->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_orange_h_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "orange", Q_NULLPTR)));
        spin_blue_h_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "blue", Q_NULLPTR)));
        label_11->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_blue_h_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "blue", Q_NULLPTR)));
        spin_green_h_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "green", Q_NULLPTR)));
        label_12->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_green_h_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "green", Q_NULLPTR)));
        spin_yellow_h_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "yellow", Q_NULLPTR)));
        label_13->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_yellow_h_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "yellow", Q_NULLPTR)));
        spin_white_h_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "white", Q_NULLPTR)));
        label_14->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_white_h_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "white", Q_NULLPTR)));
        groupBox_S->setTitle(QApplication::translate("HSVThresholdDialog", "S (0-255)", Q_NULLPTR));
        spin_redH_s_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "red_h", Q_NULLPTR)));
        label_3->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_redH_s_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "red_h", Q_NULLPTR)));
        spin_redL_s_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "red_l", Q_NULLPTR)));
        label_27->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_redL_s_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "red_l", Q_NULLPTR)));
        spin_orange_s_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "orange", Q_NULLPTR)));
        label_15->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_orange_s_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "orange", Q_NULLPTR)));
        spin_blue_s_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "blue", Q_NULLPTR)));
        label_16->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_blue_s_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "blue", Q_NULLPTR)));
        spin_green_s_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "green", Q_NULLPTR)));
        label_17->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_green_s_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "green", Q_NULLPTR)));
        spin_yellow_s_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "yellow", Q_NULLPTR)));
        label_18->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_yellow_s_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "yellow", Q_NULLPTR)));
        spin_white_s_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "white", Q_NULLPTR)));
        label_19->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_white_s_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "white", Q_NULLPTR)));
        groupBox_V->setTitle(QApplication::translate("HSVThresholdDialog", "V (0-255)", Q_NULLPTR));
        spin_redH_v_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "red_h", Q_NULLPTR)));
        label_4->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_redH_v_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "red_h", Q_NULLPTR)));
        spin_redL_v_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "red_l", Q_NULLPTR)));
        label_28->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_redL_v_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "red_l", Q_NULLPTR)));
        spin_orange_v_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "orange", Q_NULLPTR)));
        label_20->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_orange_v_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "orange", Q_NULLPTR)));
        spin_blue_v_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "blue", Q_NULLPTR)));
        label_21->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_blue_v_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "blue", Q_NULLPTR)));
        spin_green_v_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "green", Q_NULLPTR)));
        label_22->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_green_v_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "green", Q_NULLPTR)));
        spin_yellow_v_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "yellow", Q_NULLPTR)));
        label_23->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_yellow_v_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "yellow", Q_NULLPTR)));
        spin_white_v_min->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "white", Q_NULLPTR)));
        label_24->setText(QApplication::translate("HSVThresholdDialog", "--", Q_NULLPTR));
        spin_white_v_max->setProperty("tag_color", QVariant(QApplication::translate("HSVThresholdDialog", "white", Q_NULLPTR)));
        btn_reset->setText(QApplication::translate("HSVThresholdDialog", "\351\207\215\347\275\256", Q_NULLPTR));
        btn_apply->setText(QApplication::translate("HSVThresholdDialog", "\345\272\224\347\224\250", Q_NULLPTR));
        btn_cancel->setText(QApplication::translate("HSVThresholdDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HSVThresholdDialog: public Ui_HSVThresholdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HSVTHRESHOLDDIALOG_H
