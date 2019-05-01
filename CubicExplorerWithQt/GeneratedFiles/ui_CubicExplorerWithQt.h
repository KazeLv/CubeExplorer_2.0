/********************************************************************************
** Form generated from reading UI file 'CubicExplorerWithQt.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUBICEXPLORERWITHQT_H
#define UI_CUBICEXPLORERWITHQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QMyGraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_CubicExplorerWithQt
{
public:
    QAction *actSetBlock;
    QAction *actShowHSV;
    QAction *actCancel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_camera;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *vLay_cameraFR;
    QComboBox *comboBox_cameraFR;
    QMyGraphicsView *graView_cameraFR;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *vLay_cameraUB;
    QComboBox *comboBox_cameraUB;
    QMyGraphicsView *graView_cameraUB;
    QSpacerItem *horizontalSpacer_13;
    QVBoxLayout *vLay_cameraLD;
    QComboBox *comboBox_cameraLD;
    QMyGraphicsView *graView_cameraLD;
    QGroupBox *groupBox_result;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *hLay_resFR;
    QVBoxLayout *vLay_resF;
    QSpacerItem *verticalSpacer;
    QGraphicsView *graphicsView_F;
    QLabel *label_UI_F;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *vLay_resR;
    QSpacerItem *verticalSpacer_2;
    QGraphicsView *graphicsView_R;
    QLabel *label_UI_R;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *hLay_resUB;
    QVBoxLayout *vLay_resU;
    QSpacerItem *verticalSpacer_5;
    QGraphicsView *graphicsView_U;
    QLabel *label_UI_U;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *vLay_resB;
    QSpacerItem *verticalSpacer_6;
    QGraphicsView *graphicsView_B;
    QLabel *label_UI_B;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *hLay_resLD;
    QVBoxLayout *vLay_resL;
    QSpacerItem *verticalSpacer_10;
    QGraphicsView *graphicsView_L;
    QLabel *label_UI_L;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *vLay_resD;
    QSpacerItem *verticalSpacer_12;
    QGraphicsView *graphicsView_D;
    QLabel *label_UI_D;
    QSpacerItem *verticalSpacer_11;
    QGroupBox *groupBox_serialPort;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *hLay_portIni;
    QComboBox *comboBox_coms;
    QPushButton *btn_portRefresh;
    QPushButton *btn_portOpen_close;
    QLabel *label_portMessage;
    QHBoxLayout *hLay_portWrite;
    QPlainTextEdit *plainTextEdit_portWrite;
    QPushButton *btn_portSend;
    QLabel *label_UI_message;
    QVBoxLayout *vLay_btns;
    QSpacerItem *verticalSpacer_14;
    QPushButton *btn_camSwitch;
    QPushButton *btn_showSamRecs;
    QPushButton *btn_recog;
    QPushButton *btn_tightOrLoose;
    QPushButton *btn_reset;
    QPushButton *btn_debug;
    QPushButton *btn_setHSV;
    QSpacerItem *verticalSpacer_13;
    QPushButton *btn_sendSingle;
    QPushButton *btn_restore;

    void setupUi(QWidget *CubicExplorerWithQt)
    {
        if (CubicExplorerWithQt->objectName().isEmpty())
            CubicExplorerWithQt->setObjectName(QStringLiteral("CubicExplorerWithQt"));
        CubicExplorerWithQt->resize(1172, 752);
        CubicExplorerWithQt->setMinimumSize(QSize(1172, 680));
        actSetBlock = new QAction(CubicExplorerWithQt);
        actSetBlock->setObjectName(QStringLiteral("actSetBlock"));
        actShowHSV = new QAction(CubicExplorerWithQt);
        actShowHSV->setObjectName(QStringLiteral("actShowHSV"));
        actCancel = new QAction(CubicExplorerWithQt);
        actCancel->setObjectName(QStringLiteral("actCancel"));
        layoutWidget = new QWidget(CubicExplorerWithQt);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 1154, 734));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_camera = new QGroupBox(layoutWidget);
        groupBox_camera->setObjectName(QStringLiteral("groupBox_camera"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_camera);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        vLay_cameraFR = new QVBoxLayout();
        vLay_cameraFR->setSpacing(6);
        vLay_cameraFR->setObjectName(QStringLiteral("vLay_cameraFR"));
        comboBox_cameraFR = new QComboBox(groupBox_camera);
        comboBox_cameraFR->setObjectName(QStringLiteral("comboBox_cameraFR"));
        comboBox_cameraFR->setMaximumSize(QSize(160, 16777215));

        vLay_cameraFR->addWidget(comboBox_cameraFR);

        graView_cameraFR = new QMyGraphicsView(groupBox_camera);
        graView_cameraFR->setObjectName(QStringLiteral("graView_cameraFR"));
        graView_cameraFR->setMinimumSize(QSize(330, 250));
        graView_cameraFR->setMaximumSize(QSize(330, 250));

        vLay_cameraFR->addWidget(graView_cameraFR);


        horizontalLayout_2->addLayout(vLay_cameraFR);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_12);

        vLay_cameraUB = new QVBoxLayout();
        vLay_cameraUB->setSpacing(6);
        vLay_cameraUB->setObjectName(QStringLiteral("vLay_cameraUB"));
        comboBox_cameraUB = new QComboBox(groupBox_camera);
        comboBox_cameraUB->setObjectName(QStringLiteral("comboBox_cameraUB"));
        comboBox_cameraUB->setMaximumSize(QSize(160, 16777215));

        vLay_cameraUB->addWidget(comboBox_cameraUB);

        graView_cameraUB = new QMyGraphicsView(groupBox_camera);
        graView_cameraUB->setObjectName(QStringLiteral("graView_cameraUB"));
        graView_cameraUB->setMinimumSize(QSize(330, 250));
        graView_cameraUB->setMaximumSize(QSize(330, 250));

        vLay_cameraUB->addWidget(graView_cameraUB);


        horizontalLayout_2->addLayout(vLay_cameraUB);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_13);

        vLay_cameraLD = new QVBoxLayout();
        vLay_cameraLD->setSpacing(6);
        vLay_cameraLD->setObjectName(QStringLiteral("vLay_cameraLD"));
        comboBox_cameraLD = new QComboBox(groupBox_camera);
        comboBox_cameraLD->setObjectName(QStringLiteral("comboBox_cameraLD"));
        comboBox_cameraLD->setMaximumSize(QSize(160, 16777215));

        vLay_cameraLD->addWidget(comboBox_cameraLD);

        graView_cameraLD = new QMyGraphicsView(groupBox_camera);
        graView_cameraLD->setObjectName(QStringLiteral("graView_cameraLD"));
        graView_cameraLD->setMinimumSize(QSize(330, 250));
        graView_cameraLD->setMaximumSize(QSize(330, 250));

        vLay_cameraLD->addWidget(graView_cameraLD);


        horizontalLayout_2->addLayout(vLay_cameraLD);


        verticalLayout_2->addWidget(groupBox_camera);

        groupBox_result = new QGroupBox(layoutWidget);
        groupBox_result->setObjectName(QStringLiteral("groupBox_result"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_result);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        hLay_resFR = new QHBoxLayout();
        hLay_resFR->setSpacing(6);
        hLay_resFR->setObjectName(QStringLiteral("hLay_resFR"));
        vLay_resF = new QVBoxLayout();
        vLay_resF->setSpacing(6);
        vLay_resF->setObjectName(QStringLiteral("vLay_resF"));
        verticalSpacer = new QSpacerItem(140, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLay_resF->addItem(verticalSpacer);

        graphicsView_F = new QGraphicsView(groupBox_result);
        graphicsView_F->setObjectName(QStringLiteral("graphicsView_F"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView_F->sizePolicy().hasHeightForWidth());
        graphicsView_F->setSizePolicy(sizePolicy);
        graphicsView_F->setMinimumSize(QSize(150, 150));
        graphicsView_F->setMaximumSize(QSize(150, 150));
        graphicsView_F->setResizeAnchor(QGraphicsView::AnchorViewCenter);

        vLay_resF->addWidget(graphicsView_F);

        label_UI_F = new QLabel(groupBox_result);
        label_UI_F->setObjectName(QStringLiteral("label_UI_F"));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(20);
        label_UI_F->setFont(font);
        label_UI_F->setAlignment(Qt::AlignCenter);

        vLay_resF->addWidget(label_UI_F);

        verticalSpacer_3 = new QSpacerItem(140, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLay_resF->addItem(verticalSpacer_3);


        hLay_resFR->addLayout(vLay_resF);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLay_resFR->addItem(horizontalSpacer);

        vLay_resR = new QVBoxLayout();
        vLay_resR->setSpacing(6);
        vLay_resR->setObjectName(QStringLiteral("vLay_resR"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLay_resR->addItem(verticalSpacer_2);

        graphicsView_R = new QGraphicsView(groupBox_result);
        graphicsView_R->setObjectName(QStringLiteral("graphicsView_R"));
        graphicsView_R->setMinimumSize(QSize(150, 150));
        graphicsView_R->setMaximumSize(QSize(150, 150));

        vLay_resR->addWidget(graphicsView_R);

        label_UI_R = new QLabel(groupBox_result);
        label_UI_R->setObjectName(QStringLiteral("label_UI_R"));
        label_UI_R->setFont(font);
        label_UI_R->setAlignment(Qt::AlignCenter);

        vLay_resR->addWidget(label_UI_R);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLay_resR->addItem(verticalSpacer_4);


        hLay_resFR->addLayout(vLay_resR);


        horizontalLayout_3->addLayout(hLay_resFR);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        hLay_resUB = new QHBoxLayout();
        hLay_resUB->setSpacing(6);
        hLay_resUB->setObjectName(QStringLiteral("hLay_resUB"));
        vLay_resU = new QVBoxLayout();
        vLay_resU->setSpacing(6);
        vLay_resU->setObjectName(QStringLiteral("vLay_resU"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLay_resU->addItem(verticalSpacer_5);

        graphicsView_U = new QGraphicsView(groupBox_result);
        graphicsView_U->setObjectName(QStringLiteral("graphicsView_U"));
        graphicsView_U->setMinimumSize(QSize(150, 150));
        graphicsView_U->setMaximumSize(QSize(150, 150));

        vLay_resU->addWidget(graphicsView_U);

        label_UI_U = new QLabel(groupBox_result);
        label_UI_U->setObjectName(QStringLiteral("label_UI_U"));
        label_UI_U->setFont(font);
        label_UI_U->setAlignment(Qt::AlignCenter);

        vLay_resU->addWidget(label_UI_U);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLay_resU->addItem(verticalSpacer_7);


        hLay_resUB->addLayout(vLay_resU);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLay_resUB->addItem(horizontalSpacer_5);

        vLay_resB = new QVBoxLayout();
        vLay_resB->setSpacing(6);
        vLay_resB->setObjectName(QStringLiteral("vLay_resB"));
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLay_resB->addItem(verticalSpacer_6);

        graphicsView_B = new QGraphicsView(groupBox_result);
        graphicsView_B->setObjectName(QStringLiteral("graphicsView_B"));
        graphicsView_B->setMinimumSize(QSize(150, 150));
        graphicsView_B->setMaximumSize(QSize(150, 150));

        vLay_resB->addWidget(graphicsView_B);

        label_UI_B = new QLabel(groupBox_result);
        label_UI_B->setObjectName(QStringLiteral("label_UI_B"));
        label_UI_B->setFont(font);
        label_UI_B->setAlignment(Qt::AlignCenter);

        vLay_resB->addWidget(label_UI_B);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLay_resB->addItem(verticalSpacer_8);


        hLay_resUB->addLayout(vLay_resB);


        horizontalLayout_3->addLayout(hLay_resUB);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        hLay_resLD = new QHBoxLayout();
        hLay_resLD->setSpacing(6);
        hLay_resLD->setObjectName(QStringLiteral("hLay_resLD"));
        vLay_resL = new QVBoxLayout();
        vLay_resL->setSpacing(6);
        vLay_resL->setObjectName(QStringLiteral("vLay_resL"));
        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLay_resL->addItem(verticalSpacer_10);

        graphicsView_L = new QGraphicsView(groupBox_result);
        graphicsView_L->setObjectName(QStringLiteral("graphicsView_L"));
        graphicsView_L->setMinimumSize(QSize(150, 150));
        graphicsView_L->setMaximumSize(QSize(150, 150));

        vLay_resL->addWidget(graphicsView_L);

        label_UI_L = new QLabel(groupBox_result);
        label_UI_L->setObjectName(QStringLiteral("label_UI_L"));
        label_UI_L->setFont(font);
        label_UI_L->setAlignment(Qt::AlignCenter);

        vLay_resL->addWidget(label_UI_L);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLay_resL->addItem(verticalSpacer_9);


        hLay_resLD->addLayout(vLay_resL);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLay_resLD->addItem(horizontalSpacer_8);

        vLay_resD = new QVBoxLayout();
        vLay_resD->setSpacing(6);
        vLay_resD->setObjectName(QStringLiteral("vLay_resD"));
        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLay_resD->addItem(verticalSpacer_12);

        graphicsView_D = new QGraphicsView(groupBox_result);
        graphicsView_D->setObjectName(QStringLiteral("graphicsView_D"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView_D->sizePolicy().hasHeightForWidth());
        graphicsView_D->setSizePolicy(sizePolicy1);
        graphicsView_D->setMinimumSize(QSize(150, 150));
        graphicsView_D->setMaximumSize(QSize(150, 150));

        vLay_resD->addWidget(graphicsView_D);

        label_UI_D = new QLabel(groupBox_result);
        label_UI_D->setObjectName(QStringLiteral("label_UI_D"));
        label_UI_D->setFont(font);
        label_UI_D->setAlignment(Qt::AlignCenter);

        vLay_resD->addWidget(label_UI_D);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLay_resD->addItem(verticalSpacer_11);


        hLay_resLD->addLayout(vLay_resD);


        horizontalLayout_3->addLayout(hLay_resLD);


        verticalLayout_2->addWidget(groupBox_result);

        groupBox_serialPort = new QGroupBox(layoutWidget);
        groupBox_serialPort->setObjectName(QStringLiteral("groupBox_serialPort"));
        verticalLayout = new QVBoxLayout(groupBox_serialPort);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        hLay_portIni = new QHBoxLayout();
        hLay_portIni->setSpacing(6);
        hLay_portIni->setObjectName(QStringLiteral("hLay_portIni"));
        comboBox_coms = new QComboBox(groupBox_serialPort);
        comboBox_coms->setObjectName(QStringLiteral("comboBox_coms"));
        comboBox_coms->setMinimumSize(QSize(170, 25));
        comboBox_coms->setMaximumSize(QSize(170, 25));

        hLay_portIni->addWidget(comboBox_coms);

        btn_portRefresh = new QPushButton(groupBox_serialPort);
        btn_portRefresh->setObjectName(QStringLiteral("btn_portRefresh"));
        btn_portRefresh->setMinimumSize(QSize(100, 25));
        btn_portRefresh->setMaximumSize(QSize(100, 25));

        hLay_portIni->addWidget(btn_portRefresh);

        btn_portOpen_close = new QPushButton(groupBox_serialPort);
        btn_portOpen_close->setObjectName(QStringLiteral("btn_portOpen_close"));
        btn_portOpen_close->setMinimumSize(QSize(100, 25));
        btn_portOpen_close->setMaximumSize(QSize(100, 25));

        hLay_portIni->addWidget(btn_portOpen_close);

        label_portMessage = new QLabel(groupBox_serialPort);
        label_portMessage->setObjectName(QStringLiteral("label_portMessage"));

        hLay_portIni->addWidget(label_portMessage);


        verticalLayout->addLayout(hLay_portIni);

        hLay_portWrite = new QHBoxLayout();
        hLay_portWrite->setSpacing(6);
        hLay_portWrite->setObjectName(QStringLiteral("hLay_portWrite"));
        plainTextEdit_portWrite = new QPlainTextEdit(groupBox_serialPort);
        plainTextEdit_portWrite->setObjectName(QStringLiteral("plainTextEdit_portWrite"));
        plainTextEdit_portWrite->setMinimumSize(QSize(0, 80));

        hLay_portWrite->addWidget(plainTextEdit_portWrite);

        btn_portSend = new QPushButton(groupBox_serialPort);
        btn_portSend->setObjectName(QStringLiteral("btn_portSend"));
        btn_portSend->setMinimumSize(QSize(0, 80));

        hLay_portWrite->addWidget(btn_portSend);


        verticalLayout->addLayout(hLay_portWrite);


        verticalLayout_2->addWidget(groupBox_serialPort);

        label_UI_message = new QLabel(layoutWidget);
        label_UI_message->setObjectName(QStringLiteral("label_UI_message"));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(11);
        label_UI_message->setFont(font1);

        verticalLayout_2->addWidget(label_UI_message);


        horizontalLayout->addLayout(verticalLayout_2);

        vLay_btns = new QVBoxLayout();
        vLay_btns->setSpacing(6);
        vLay_btns->setObjectName(QStringLiteral("vLay_btns"));
        vLay_btns->setContentsMargins(0, -1, -1, -1);
        verticalSpacer_14 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        vLay_btns->addItem(verticalSpacer_14);

        btn_camSwitch = new QPushButton(layoutWidget);
        btn_camSwitch->setObjectName(QStringLiteral("btn_camSwitch"));
        btn_camSwitch->setMinimumSize(QSize(100, 30));
        btn_camSwitch->setMaximumSize(QSize(100, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("Adobe Arabic"));
        font2.setPointSize(14);
        btn_camSwitch->setFont(font2);

        vLay_btns->addWidget(btn_camSwitch);

        btn_showSamRecs = new QPushButton(layoutWidget);
        btn_showSamRecs->setObjectName(QStringLiteral("btn_showSamRecs"));
        btn_showSamRecs->setMinimumSize(QSize(100, 30));
        btn_showSamRecs->setMaximumSize(QSize(100, 30));
        btn_showSamRecs->setFont(font2);

        vLay_btns->addWidget(btn_showSamRecs);

        btn_recog = new QPushButton(layoutWidget);
        btn_recog->setObjectName(QStringLiteral("btn_recog"));
        btn_recog->setMinimumSize(QSize(100, 30));
        btn_recog->setMaximumSize(QSize(100, 30));
        btn_recog->setFont(font2);

        vLay_btns->addWidget(btn_recog);

        btn_tightOrLoose = new QPushButton(layoutWidget);
        btn_tightOrLoose->setObjectName(QStringLiteral("btn_tightOrLoose"));
        btn_tightOrLoose->setMinimumSize(QSize(100, 30));
        btn_tightOrLoose->setMaximumSize(QSize(100, 30));
        btn_tightOrLoose->setFont(font2);

        vLay_btns->addWidget(btn_tightOrLoose);

        btn_reset = new QPushButton(layoutWidget);
        btn_reset->setObjectName(QStringLiteral("btn_reset"));
        btn_reset->setMinimumSize(QSize(100, 30));
        btn_reset->setMaximumSize(QSize(100, 30));
        btn_reset->setFont(font2);

        vLay_btns->addWidget(btn_reset);

        btn_debug = new QPushButton(layoutWidget);
        btn_debug->setObjectName(QStringLiteral("btn_debug"));
        btn_debug->setMinimumSize(QSize(100, 30));
        btn_debug->setMaximumSize(QSize(100, 30));
        btn_debug->setFont(font2);

        vLay_btns->addWidget(btn_debug);

        btn_setHSV = new QPushButton(layoutWidget);
        btn_setHSV->setObjectName(QStringLiteral("btn_setHSV"));
        btn_setHSV->setMinimumSize(QSize(100, 30));
        btn_setHSV->setMaximumSize(QSize(100, 30));
        btn_setHSV->setFont(font2);

        vLay_btns->addWidget(btn_setHSV);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLay_btns->addItem(verticalSpacer_13);

        btn_sendSingle = new QPushButton(layoutWidget);
        btn_sendSingle->setObjectName(QStringLiteral("btn_sendSingle"));
        btn_sendSingle->setMinimumSize(QSize(100, 30));
        btn_sendSingle->setMaximumSize(QSize(100, 30));
        btn_sendSingle->setFont(font2);

        vLay_btns->addWidget(btn_sendSingle);

        btn_restore = new QPushButton(layoutWidget);
        btn_restore->setObjectName(QStringLiteral("btn_restore"));
        btn_restore->setMinimumSize(QSize(100, 30));
        btn_restore->setMaximumSize(QSize(100, 30));
        btn_restore->setFont(font2);

        vLay_btns->addWidget(btn_restore);


        horizontalLayout->addLayout(vLay_btns);


        retranslateUi(CubicExplorerWithQt);

        QMetaObject::connectSlotsByName(CubicExplorerWithQt);
    } // setupUi

    void retranslateUi(QWidget *CubicExplorerWithQt)
    {
        CubicExplorerWithQt->setWindowTitle(QApplication::translate("CubicExplorerWithQt", "QtGuiAppForCubicExplorer", Q_NULLPTR));
        actSetBlock->setText(QApplication::translate("CubicExplorerWithQt", "\350\256\276\347\275\256\345\217\226\350\211\262\345\235\227", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actSetBlock->setToolTip(QApplication::translate("CubicExplorerWithQt", "\345\260\206\346\211\200\351\200\211\345\214\272\345\237\237\350\256\276\347\275\256\344\270\272\345\217\226\350\211\262\345\235\227", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actShowHSV->setText(QApplication::translate("CubicExplorerWithQt", "\346\237\245\347\234\213HSV\346\225\260\346\215\256", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actShowHSV->setToolTip(QApplication::translate("CubicExplorerWithQt", "\346\230\276\347\244\272\346\211\200\351\200\211\345\214\272\345\237\237\347\232\204HSV\347\273\237\350\256\241\345\233\276\350\241\250", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actCancel->setText(QApplication::translate("CubicExplorerWithQt", "\345\217\226\346\266\210", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actCancel->setToolTip(QApplication::translate("CubicExplorerWithQt", "\344\270\215\345\201\232\344\273\273\344\275\225\346\223\215\344\275\234", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox_camera->setTitle(QApplication::translate("CubicExplorerWithQt", "\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        groupBox_result->setTitle(QApplication::translate("CubicExplorerWithQt", "\350\257\206\345\210\253\347\273\223\346\236\234", Q_NULLPTR));
        label_UI_F->setText(QApplication::translate("CubicExplorerWithQt", "F", Q_NULLPTR));
        label_UI_R->setText(QApplication::translate("CubicExplorerWithQt", "R", Q_NULLPTR));
        label_UI_U->setText(QApplication::translate("CubicExplorerWithQt", "U", Q_NULLPTR));
        label_UI_B->setText(QApplication::translate("CubicExplorerWithQt", "B", Q_NULLPTR));
        label_UI_L->setText(QApplication::translate("CubicExplorerWithQt", "L", Q_NULLPTR));
        label_UI_D->setText(QApplication::translate("CubicExplorerWithQt", "D", Q_NULLPTR));
        groupBox_serialPort->setTitle(QApplication::translate("CubicExplorerWithQt", "\344\270\262\345\217\243", Q_NULLPTR));
        btn_portRefresh->setText(QApplication::translate("CubicExplorerWithQt", "\345\210\267\346\226\260", Q_NULLPTR));
        btn_portOpen_close->setText(QApplication::translate("CubicExplorerWithQt", "\346\211\223\345\274\200/\345\205\263\351\227\255", Q_NULLPTR));
        label_portMessage->setText(QApplication::translate("CubicExplorerWithQt", "\346\234\252\346\211\223\345\274\200...", Q_NULLPTR));
        btn_portSend->setText(QApplication::translate("CubicExplorerWithQt", "\345\217\221\351\200\201", Q_NULLPTR));
        label_UI_message->setText(QApplication::translate("CubicExplorerWithQt", "message", Q_NULLPTR));
        btn_camSwitch->setText(QApplication::translate("CubicExplorerWithQt", "\346\221\204\345\203\217\345\244\264\345\274\200\345\205\263", Q_NULLPTR));
        btn_showSamRecs->setText(QApplication::translate("CubicExplorerWithQt", "\346\230\276\347\244\272\351\207\207\346\240\267\346\241\206", Q_NULLPTR));
        btn_recog->setText(QApplication::translate("CubicExplorerWithQt", "\350\257\206\345\210\253\350\211\262\345\235\227", Q_NULLPTR));
        btn_tightOrLoose->setText(QApplication::translate("CubicExplorerWithQt", "\346\235\276\345\274\200/\345\244\271\347\264\247", Q_NULLPTR));
        btn_reset->setText(QApplication::translate("CubicExplorerWithQt", "\347\210\252\345\244\215\344\275\215", Q_NULLPTR));
        btn_debug->setText(QApplication::translate("CubicExplorerWithQt", "\350\260\203\350\257\225", Q_NULLPTR));
        btn_setHSV->setText(QApplication::translate("CubicExplorerWithQt", "HSV\350\256\276\347\275\256", Q_NULLPTR));
        btn_sendSingle->setText(QApplication::translate("CubicExplorerWithQt", "\345\215\225\346\255\245\346\211\247\350\241\214", Q_NULLPTR));
        btn_restore->setText(QApplication::translate("CubicExplorerWithQt", "\345\274\200\345\247\213\345\244\215\345\216\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CubicExplorerWithQt: public Ui_CubicExplorerWithQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUBICEXPLORERWITHQT_H
