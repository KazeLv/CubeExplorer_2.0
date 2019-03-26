/********************************************************************************
** Form generated from reading UI file 'DebugWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGWIDGET_H
#define UI_DEBUGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DebugWidget
{
public:
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_cams;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_case1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView_case1_FR;
    QLabel *label_FR;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *graphicsView_case1_UB;
    QLabel *label_UB;
    QVBoxLayout *verticalLayout_3;
    QGraphicsView *graphicsView_case1_LD;
    QLabel *label_LD;
    QGroupBox *groupBox_case2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QGraphicsView *graphicsView_case2_FR;
    QLabel *label_FR_2;
    QVBoxLayout *verticalLayout_5;
    QGraphicsView *graphicsView_case2_UB;
    QLabel *label_UB_2;
    QVBoxLayout *verticalLayout_6;
    QGraphicsView *graphicsView_case2_LD;
    QLabel *label_LD_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_left;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_left_rotation;
    QGridLayout *gridLayout;
    QPushButton *btn_left_to90;
    QPushButton *btn_left_to180;
    QPushButton *btn_left_clockwise;
    QPushButton *btn_left_anticlockwise;
    QPushButton *btn_left_clockwise_small;
    QPushButton *btn_left_anticlockwise_small;
    QPushButton *btn_left_180;
    QPushButton *btn_left_5circle;
    QGroupBox *groupBox_left_open_close;
    QGridLayout *gridLayout_2;
    QPushButton *btn_left_open_small;
    QPushButton *btn_left_close_small;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_left_close;
    QPushButton *btn_left_open;
    QPushButton *btn_left_close_half;
    QPushButton *btn_left_open_all;
    QGroupBox *groupBox_right;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_right_rotation;
    QGridLayout *gridLayout_3;
    QPushButton *btn_right_to90;
    QPushButton *btn_right_to180;
    QPushButton *btn_right_clockwise;
    QPushButton *btn_right_anticlockwise;
    QPushButton *btn_right_clockwise_small;
    QPushButton *btn_right_anticlockwise_small;
    QPushButton *btn_right_180;
    QPushButton *btn_right_5circle;
    QGroupBox *groupBox_right_open_close;
    QGridLayout *gridLayout_4;
    QPushButton *btn_right_open;
    QPushButton *btn_right_close_small;
    QPushButton *btn_right_close;
    QPushButton *btn_right_open_small;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btn_right_open_all;
    QPushButton *btn_right_close_half;

    void setupUi(QWidget *DebugWidget)
    {
        if (DebugWidget->objectName().isEmpty())
            DebugWidget->setObjectName(QStringLiteral("DebugWidget"));
        DebugWidget->resize(1320, 534);
        verticalLayout_7 = new QVBoxLayout(DebugWidget);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        groupBox_cams = new QGroupBox(DebugWidget);
        groupBox_cams->setObjectName(QStringLiteral("groupBox_cams"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(10);
        groupBox_cams->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(groupBox_cams);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_case1 = new QGroupBox(groupBox_cams);
        groupBox_case1->setObjectName(QStringLiteral("groupBox_case1"));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(9);
        groupBox_case1->setFont(font1);
        horizontalLayout = new QHBoxLayout(groupBox_case1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView_case1_FR = new QGraphicsView(groupBox_case1);
        graphicsView_case1_FR->setObjectName(QStringLiteral("graphicsView_case1_FR"));
        graphicsView_case1_FR->setMinimumSize(QSize(200, 150));
        graphicsView_case1_FR->setMaximumSize(QSize(200, 150));

        verticalLayout->addWidget(graphicsView_case1_FR);

        label_FR = new QLabel(groupBox_case1);
        label_FR->setObjectName(QStringLiteral("label_FR"));
        QFont font2;
        font2.setFamily(QStringLiteral("Consolas"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        label_FR->setFont(font2);
        label_FR->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_FR);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        graphicsView_case1_UB = new QGraphicsView(groupBox_case1);
        graphicsView_case1_UB->setObjectName(QStringLiteral("graphicsView_case1_UB"));
        graphicsView_case1_UB->setMinimumSize(QSize(200, 150));
        graphicsView_case1_UB->setMaximumSize(QSize(200, 150));

        verticalLayout_2->addWidget(graphicsView_case1_UB);

        label_UB = new QLabel(groupBox_case1);
        label_UB->setObjectName(QStringLiteral("label_UB"));
        label_UB->setFont(font2);
        label_UB->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_UB);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        graphicsView_case1_LD = new QGraphicsView(groupBox_case1);
        graphicsView_case1_LD->setObjectName(QStringLiteral("graphicsView_case1_LD"));
        graphicsView_case1_LD->setMinimumSize(QSize(200, 150));
        graphicsView_case1_LD->setMaximumSize(QSize(200, 150));

        verticalLayout_3->addWidget(graphicsView_case1_LD);

        label_LD = new QLabel(groupBox_case1);
        label_LD->setObjectName(QStringLiteral("label_LD"));
        label_LD->setFont(font2);
        label_LD->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_LD);


        horizontalLayout->addLayout(verticalLayout_3);


        horizontalLayout_3->addWidget(groupBox_case1);

        groupBox_case2 = new QGroupBox(groupBox_cams);
        groupBox_case2->setObjectName(QStringLiteral("groupBox_case2"));
        groupBox_case2->setFont(font1);
        horizontalLayout_2 = new QHBoxLayout(groupBox_case2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        graphicsView_case2_FR = new QGraphicsView(groupBox_case2);
        graphicsView_case2_FR->setObjectName(QStringLiteral("graphicsView_case2_FR"));
        graphicsView_case2_FR->setMinimumSize(QSize(200, 150));
        graphicsView_case2_FR->setMaximumSize(QSize(200, 150));

        verticalLayout_4->addWidget(graphicsView_case2_FR);

        label_FR_2 = new QLabel(groupBox_case2);
        label_FR_2->setObjectName(QStringLiteral("label_FR_2"));
        label_FR_2->setFont(font2);
        label_FR_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_FR_2);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        graphicsView_case2_UB = new QGraphicsView(groupBox_case2);
        graphicsView_case2_UB->setObjectName(QStringLiteral("graphicsView_case2_UB"));
        graphicsView_case2_UB->setMinimumSize(QSize(200, 150));
        graphicsView_case2_UB->setMaximumSize(QSize(200, 150));

        verticalLayout_5->addWidget(graphicsView_case2_UB);

        label_UB_2 = new QLabel(groupBox_case2);
        label_UB_2->setObjectName(QStringLiteral("label_UB_2"));
        label_UB_2->setFont(font2);
        label_UB_2->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_UB_2);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        graphicsView_case2_LD = new QGraphicsView(groupBox_case2);
        graphicsView_case2_LD->setObjectName(QStringLiteral("graphicsView_case2_LD"));
        graphicsView_case2_LD->setMinimumSize(QSize(200, 150));
        graphicsView_case2_LD->setMaximumSize(QSize(200, 150));

        verticalLayout_6->addWidget(graphicsView_case2_LD);

        label_LD_2 = new QLabel(groupBox_case2);
        label_LD_2->setObjectName(QStringLiteral("label_LD_2"));
        label_LD_2->setFont(font2);
        label_LD_2->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_LD_2);


        horizontalLayout_2->addLayout(verticalLayout_6);


        horizontalLayout_3->addWidget(groupBox_case2);


        verticalLayout_7->addWidget(groupBox_cams);

        groupBox = new QGroupBox(DebugWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        groupBox_left = new QGroupBox(groupBox);
        groupBox_left->setObjectName(QStringLiteral("groupBox_left"));
        QFont font3;
        font3.setFamily(QStringLiteral("Agency FB"));
        font3.setPointSize(9);
        groupBox_left->setFont(font3);
        horizontalLayout_4 = new QHBoxLayout(groupBox_left);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox_left_rotation = new QGroupBox(groupBox_left);
        groupBox_left_rotation->setObjectName(QStringLiteral("groupBox_left_rotation"));
        gridLayout = new QGridLayout(groupBox_left_rotation);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_left_to90 = new QPushButton(groupBox_left_rotation);
        btn_left_to90->setObjectName(QStringLiteral("btn_left_to90"));
        btn_left_to90->setMinimumSize(QSize(100, 30));
        btn_left_to90->setMaximumSize(QSize(100, 30));
        QFont font4;
        font4.setFamily(QStringLiteral("Adobe Caslon Pro"));
        font4.setPointSize(10);
        btn_left_to90->setFont(font4);

        gridLayout->addWidget(btn_left_to90, 0, 0, 1, 1);

        btn_left_to180 = new QPushButton(groupBox_left_rotation);
        btn_left_to180->setObjectName(QStringLiteral("btn_left_to180"));
        btn_left_to180->setMinimumSize(QSize(100, 30));
        btn_left_to180->setMaximumSize(QSize(100, 30));
        btn_left_to180->setFont(font4);

        gridLayout->addWidget(btn_left_to180, 0, 1, 1, 1);

        btn_left_clockwise = new QPushButton(groupBox_left_rotation);
        btn_left_clockwise->setObjectName(QStringLiteral("btn_left_clockwise"));
        btn_left_clockwise->setMinimumSize(QSize(100, 30));
        btn_left_clockwise->setMaximumSize(QSize(100, 30));
        QFont font5;
        font5.setPointSize(10);
        btn_left_clockwise->setFont(font5);

        gridLayout->addWidget(btn_left_clockwise, 1, 0, 1, 1);

        btn_left_anticlockwise = new QPushButton(groupBox_left_rotation);
        btn_left_anticlockwise->setObjectName(QStringLiteral("btn_left_anticlockwise"));
        btn_left_anticlockwise->setMinimumSize(QSize(100, 30));
        btn_left_anticlockwise->setMaximumSize(QSize(100, 30));
        btn_left_anticlockwise->setFont(font5);

        gridLayout->addWidget(btn_left_anticlockwise, 1, 1, 1, 1);

        btn_left_clockwise_small = new QPushButton(groupBox_left_rotation);
        btn_left_clockwise_small->setObjectName(QStringLiteral("btn_left_clockwise_small"));
        btn_left_clockwise_small->setMinimumSize(QSize(100, 30));
        btn_left_clockwise_small->setMaximumSize(QSize(100, 30));
        btn_left_clockwise_small->setFont(font5);

        gridLayout->addWidget(btn_left_clockwise_small, 2, 0, 1, 1);

        btn_left_anticlockwise_small = new QPushButton(groupBox_left_rotation);
        btn_left_anticlockwise_small->setObjectName(QStringLiteral("btn_left_anticlockwise_small"));
        btn_left_anticlockwise_small->setMinimumSize(QSize(100, 30));
        btn_left_anticlockwise_small->setMaximumSize(QSize(100, 30));
        btn_left_anticlockwise_small->setFont(font5);

        gridLayout->addWidget(btn_left_anticlockwise_small, 2, 1, 1, 1);

        btn_left_180 = new QPushButton(groupBox_left_rotation);
        btn_left_180->setObjectName(QStringLiteral("btn_left_180"));
        btn_left_180->setMinimumSize(QSize(100, 30));
        btn_left_180->setMaximumSize(QSize(100, 30));
        btn_left_180->setFont(font4);

        gridLayout->addWidget(btn_left_180, 3, 0, 1, 1);

        btn_left_5circle = new QPushButton(groupBox_left_rotation);
        btn_left_5circle->setObjectName(QStringLiteral("btn_left_5circle"));
        btn_left_5circle->setMinimumSize(QSize(100, 30));
        btn_left_5circle->setMaximumSize(QSize(100, 30));
        btn_left_5circle->setFont(font5);

        gridLayout->addWidget(btn_left_5circle, 3, 1, 1, 1);


        horizontalLayout_4->addWidget(groupBox_left_rotation);

        groupBox_left_open_close = new QGroupBox(groupBox_left);
        groupBox_left_open_close->setObjectName(QStringLiteral("groupBox_left_open_close"));
        gridLayout_2 = new QGridLayout(groupBox_left_open_close);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btn_left_open_small = new QPushButton(groupBox_left_open_close);
        btn_left_open_small->setObjectName(QStringLiteral("btn_left_open_small"));
        btn_left_open_small->setMinimumSize(QSize(100, 30));
        btn_left_open_small->setMaximumSize(QSize(100, 30));
        btn_left_open_small->setFont(font5);

        gridLayout_2->addWidget(btn_left_open_small, 1, 0, 1, 1);

        btn_left_close_small = new QPushButton(groupBox_left_open_close);
        btn_left_close_small->setObjectName(QStringLiteral("btn_left_close_small"));
        btn_left_close_small->setMinimumSize(QSize(100, 30));
        btn_left_close_small->setMaximumSize(QSize(100, 30));
        btn_left_close_small->setFont(font5);

        gridLayout_2->addWidget(btn_left_close_small, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);

        btn_left_close = new QPushButton(groupBox_left_open_close);
        btn_left_close->setObjectName(QStringLiteral("btn_left_close"));
        btn_left_close->setMinimumSize(QSize(100, 30));
        btn_left_close->setMaximumSize(QSize(100, 30));
        btn_left_close->setFont(font4);

        gridLayout_2->addWidget(btn_left_close, 0, 1, 1, 1);

        btn_left_open = new QPushButton(groupBox_left_open_close);
        btn_left_open->setObjectName(QStringLiteral("btn_left_open"));
        btn_left_open->setMinimumSize(QSize(100, 30));
        btn_left_open->setMaximumSize(QSize(100, 30));
        btn_left_open->setFont(font4);

        gridLayout_2->addWidget(btn_left_open, 0, 0, 1, 1);

        btn_left_close_half = new QPushButton(groupBox_left_open_close);
        btn_left_close_half->setObjectName(QStringLiteral("btn_left_close_half"));
        btn_left_close_half->setMinimumSize(QSize(100, 30));
        btn_left_close_half->setMaximumSize(QSize(100, 30));
        btn_left_close_half->setFont(font5);

        gridLayout_2->addWidget(btn_left_close_half, 3, 1, 1, 1);

        btn_left_open_all = new QPushButton(groupBox_left_open_close);
        btn_left_open_all->setObjectName(QStringLiteral("btn_left_open_all"));
        btn_left_open_all->setMinimumSize(QSize(100, 30));
        btn_left_open_all->setMaximumSize(QSize(100, 30));
        btn_left_open_all->setFont(font5);

        gridLayout_2->addWidget(btn_left_open_all, 3, 0, 1, 1);


        horizontalLayout_4->addWidget(groupBox_left_open_close);


        horizontalLayout_5->addWidget(groupBox_left);

        groupBox_right = new QGroupBox(groupBox);
        groupBox_right->setObjectName(QStringLiteral("groupBox_right"));
        groupBox_right->setFont(font3);
        gridLayout_5 = new QGridLayout(groupBox_right);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox_right_rotation = new QGroupBox(groupBox_right);
        groupBox_right_rotation->setObjectName(QStringLiteral("groupBox_right_rotation"));
        gridLayout_3 = new QGridLayout(groupBox_right_rotation);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        btn_right_to90 = new QPushButton(groupBox_right_rotation);
        btn_right_to90->setObjectName(QStringLiteral("btn_right_to90"));
        btn_right_to90->setMinimumSize(QSize(100, 30));
        btn_right_to90->setMaximumSize(QSize(100, 30));
        btn_right_to90->setFont(font4);

        gridLayout_3->addWidget(btn_right_to90, 0, 0, 1, 1);

        btn_right_to180 = new QPushButton(groupBox_right_rotation);
        btn_right_to180->setObjectName(QStringLiteral("btn_right_to180"));
        btn_right_to180->setMinimumSize(QSize(100, 30));
        btn_right_to180->setMaximumSize(QSize(100, 30));
        btn_right_to180->setFont(font4);

        gridLayout_3->addWidget(btn_right_to180, 0, 1, 1, 1);

        btn_right_clockwise = new QPushButton(groupBox_right_rotation);
        btn_right_clockwise->setObjectName(QStringLiteral("btn_right_clockwise"));
        btn_right_clockwise->setMinimumSize(QSize(100, 30));
        btn_right_clockwise->setMaximumSize(QSize(100, 30));
        btn_right_clockwise->setFont(font5);

        gridLayout_3->addWidget(btn_right_clockwise, 1, 0, 1, 1);

        btn_right_anticlockwise = new QPushButton(groupBox_right_rotation);
        btn_right_anticlockwise->setObjectName(QStringLiteral("btn_right_anticlockwise"));
        btn_right_anticlockwise->setMinimumSize(QSize(100, 30));
        btn_right_anticlockwise->setMaximumSize(QSize(100, 30));
        btn_right_anticlockwise->setFont(font5);

        gridLayout_3->addWidget(btn_right_anticlockwise, 1, 1, 1, 1);

        btn_right_clockwise_small = new QPushButton(groupBox_right_rotation);
        btn_right_clockwise_small->setObjectName(QStringLiteral("btn_right_clockwise_small"));
        btn_right_clockwise_small->setMinimumSize(QSize(100, 30));
        btn_right_clockwise_small->setMaximumSize(QSize(100, 30));
        btn_right_clockwise_small->setFont(font5);

        gridLayout_3->addWidget(btn_right_clockwise_small, 2, 0, 1, 1);

        btn_right_anticlockwise_small = new QPushButton(groupBox_right_rotation);
        btn_right_anticlockwise_small->setObjectName(QStringLiteral("btn_right_anticlockwise_small"));
        btn_right_anticlockwise_small->setMinimumSize(QSize(100, 30));
        btn_right_anticlockwise_small->setMaximumSize(QSize(100, 30));
        btn_right_anticlockwise_small->setFont(font5);

        gridLayout_3->addWidget(btn_right_anticlockwise_small, 2, 1, 1, 1);

        btn_right_180 = new QPushButton(groupBox_right_rotation);
        btn_right_180->setObjectName(QStringLiteral("btn_right_180"));
        btn_right_180->setMinimumSize(QSize(100, 30));
        btn_right_180->setMaximumSize(QSize(100, 30));
        btn_right_180->setFont(font4);

        gridLayout_3->addWidget(btn_right_180, 3, 0, 1, 1);

        btn_right_5circle = new QPushButton(groupBox_right_rotation);
        btn_right_5circle->setObjectName(QStringLiteral("btn_right_5circle"));
        btn_right_5circle->setMinimumSize(QSize(100, 30));
        btn_right_5circle->setMaximumSize(QSize(100, 30));
        btn_right_5circle->setFont(font5);

        gridLayout_3->addWidget(btn_right_5circle, 3, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_right_rotation, 0, 0, 1, 1);

        groupBox_right_open_close = new QGroupBox(groupBox_right);
        groupBox_right_open_close->setObjectName(QStringLiteral("groupBox_right_open_close"));
        gridLayout_4 = new QGridLayout(groupBox_right_open_close);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        btn_right_open = new QPushButton(groupBox_right_open_close);
        btn_right_open->setObjectName(QStringLiteral("btn_right_open"));
        btn_right_open->setMinimumSize(QSize(100, 30));
        btn_right_open->setMaximumSize(QSize(100, 30));
        btn_right_open->setFont(font4);

        gridLayout_4->addWidget(btn_right_open, 0, 0, 1, 1);

        btn_right_close_small = new QPushButton(groupBox_right_open_close);
        btn_right_close_small->setObjectName(QStringLiteral("btn_right_close_small"));
        btn_right_close_small->setMinimumSize(QSize(100, 30));
        btn_right_close_small->setMaximumSize(QSize(100, 30));
        btn_right_close_small->setFont(font5);

        gridLayout_4->addWidget(btn_right_close_small, 1, 1, 1, 1);

        btn_right_close = new QPushButton(groupBox_right_open_close);
        btn_right_close->setObjectName(QStringLiteral("btn_right_close"));
        btn_right_close->setMinimumSize(QSize(100, 30));
        btn_right_close->setMaximumSize(QSize(100, 30));
        btn_right_close->setFont(font4);

        gridLayout_4->addWidget(btn_right_close, 0, 1, 1, 1);

        btn_right_open_small = new QPushButton(groupBox_right_open_close);
        btn_right_open_small->setObjectName(QStringLiteral("btn_right_open_small"));
        btn_right_open_small->setMinimumSize(QSize(100, 30));
        btn_right_open_small->setMaximumSize(QSize(100, 30));
        btn_right_open_small->setFont(font5);

        gridLayout_4->addWidget(btn_right_open_small, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 3, 0, 1, 1);

        btn_right_open_all = new QPushButton(groupBox_right_open_close);
        btn_right_open_all->setObjectName(QStringLiteral("btn_right_open_all"));
        btn_right_open_all->setMinimumSize(QSize(100, 30));
        btn_right_open_all->setMaximumSize(QSize(100, 30));
        btn_right_open_all->setFont(font5);

        gridLayout_4->addWidget(btn_right_open_all, 2, 0, 1, 1);

        btn_right_close_half = new QPushButton(groupBox_right_open_close);
        btn_right_close_half->setObjectName(QStringLiteral("btn_right_close_half"));
        btn_right_close_half->setMinimumSize(QSize(100, 30));
        btn_right_close_half->setMaximumSize(QSize(100, 30));
        btn_right_close_half->setFont(font5);

        gridLayout_4->addWidget(btn_right_close_half, 2, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_right_open_close, 0, 1, 1, 1);


        horizontalLayout_5->addWidget(groupBox_right);


        verticalLayout_7->addWidget(groupBox);


        retranslateUi(DebugWidget);

        QMetaObject::connectSlotsByName(DebugWidget);
    } // setupUi

    void retranslateUi(QWidget *DebugWidget)
    {
        DebugWidget->setWindowTitle(QApplication::translate("DebugWidget", "Form", Q_NULLPTR));
        groupBox_cams->setTitle(QApplication::translate("DebugWidget", "\346\234\200\350\277\221\346\213\215\346\221\204\347\205\247\347\211\207", Q_NULLPTR));
        groupBox_case1->setTitle(QApplication::translate("DebugWidget", "Case1", Q_NULLPTR));
        label_FR->setText(QApplication::translate("DebugWidget", "FR", Q_NULLPTR));
        label_UB->setText(QApplication::translate("DebugWidget", "UB", Q_NULLPTR));
        label_LD->setText(QApplication::translate("DebugWidget", "LD", Q_NULLPTR));
        groupBox_case2->setTitle(QApplication::translate("DebugWidget", "Case2", Q_NULLPTR));
        label_FR_2->setText(QApplication::translate("DebugWidget", "FR", Q_NULLPTR));
        label_UB_2->setText(QApplication::translate("DebugWidget", "UB", Q_NULLPTR));
        label_LD_2->setText(QApplication::translate("DebugWidget", "LD", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DebugWidget", "\346\234\272\346\242\260\347\210\252\346\223\215\344\275\234", Q_NULLPTR));
        groupBox_left->setTitle(QApplication::translate("DebugWidget", "\345\267\246\347\210\252", Q_NULLPTR));
        groupBox_left_rotation->setTitle(QApplication::translate("DebugWidget", "\346\227\213\350\275\254", Q_NULLPTR));
        btn_left_to90->setText(QApplication::translate("DebugWidget", "\350\207\26390\302\260", Q_NULLPTR));
        btn_left_to180->setText(QApplication::translate("DebugWidget", "\350\207\263180\302\260", Q_NULLPTR));
        btn_left_clockwise->setText(QApplication::translate("DebugWidget", "\351\241\272\346\227\266\351\222\210", Q_NULLPTR));
        btn_left_anticlockwise->setText(QApplication::translate("DebugWidget", "\351\200\206\346\227\266\351\222\210", Q_NULLPTR));
        btn_left_clockwise_small->setText(QApplication::translate("DebugWidget", "\351\241\272\346\227\266\351\222\210(\345\276\256\350\260\203)", Q_NULLPTR));
        btn_left_anticlockwise_small->setText(QApplication::translate("DebugWidget", "\351\200\206\346\227\266\351\222\210(\345\276\256\350\260\203)", Q_NULLPTR));
        btn_left_180->setText(QApplication::translate("DebugWidget", "180\302\260", Q_NULLPTR));
        btn_left_5circle->setText(QApplication::translate("DebugWidget", "\350\277\236\347\273\255\344\272\224\345\234\210", Q_NULLPTR));
        groupBox_left_open_close->setTitle(QApplication::translate("DebugWidget", "\345\274\200\345\220\210", Q_NULLPTR));
        btn_left_open_small->setText(QApplication::translate("DebugWidget", "\346\211\223\345\274\200(\345\276\256\350\260\203)", Q_NULLPTR));
        btn_left_close_small->setText(QApplication::translate("DebugWidget", "\345\220\210\344\270\212(\345\276\256\350\260\203)", Q_NULLPTR));
        btn_left_close->setText(QApplication::translate("DebugWidget", "\345\220\210\344\270\212", Q_NULLPTR));
        btn_left_open->setText(QApplication::translate("DebugWidget", "\346\211\223\345\274\200", Q_NULLPTR));
        btn_left_close_half->setText(QApplication::translate("DebugWidget", "\345\215\212\345\220\210", Q_NULLPTR));
        btn_left_open_all->setText(QApplication::translate("DebugWidget", "\345\205\250\345\274\200", Q_NULLPTR));
        groupBox_right->setTitle(QApplication::translate("DebugWidget", "\345\217\263\347\210\252", Q_NULLPTR));
        groupBox_right_rotation->setTitle(QApplication::translate("DebugWidget", "\346\227\213\350\275\254", Q_NULLPTR));
        btn_right_to90->setText(QApplication::translate("DebugWidget", "\350\207\26390\302\260", Q_NULLPTR));
        btn_right_to180->setText(QApplication::translate("DebugWidget", "\350\207\263180\302\260", Q_NULLPTR));
        btn_right_clockwise->setText(QApplication::translate("DebugWidget", "\351\241\272\346\227\266\351\222\210", Q_NULLPTR));
        btn_right_anticlockwise->setText(QApplication::translate("DebugWidget", "\351\200\206\346\227\266\351\222\210", Q_NULLPTR));
        btn_right_clockwise_small->setText(QApplication::translate("DebugWidget", "\351\241\272\346\227\266\351\222\210(\345\276\256\350\260\203)", Q_NULLPTR));
        btn_right_anticlockwise_small->setText(QApplication::translate("DebugWidget", "\351\200\206\346\227\266\351\222\210(\345\276\256\350\260\203)", Q_NULLPTR));
        btn_right_180->setText(QApplication::translate("DebugWidget", "180\302\260", Q_NULLPTR));
        btn_right_5circle->setText(QApplication::translate("DebugWidget", "\350\277\236\347\273\255\344\272\224\345\234\210", Q_NULLPTR));
        groupBox_right_open_close->setTitle(QApplication::translate("DebugWidget", "\345\274\200\345\220\210", Q_NULLPTR));
        btn_right_open->setText(QApplication::translate("DebugWidget", "\346\211\223\345\274\200", Q_NULLPTR));
        btn_right_close_small->setText(QApplication::translate("DebugWidget", "\345\220\210\344\270\212(\345\276\256\350\260\203)", Q_NULLPTR));
        btn_right_close->setText(QApplication::translate("DebugWidget", "\345\220\210\344\270\212", Q_NULLPTR));
        btn_right_open_small->setText(QApplication::translate("DebugWidget", "\346\211\223\345\274\200(\345\276\256\350\260\203)", Q_NULLPTR));
        btn_right_open_all->setText(QApplication::translate("DebugWidget", "\345\205\250\345\274\200", Q_NULLPTR));
        btn_right_close_half->setText(QApplication::translate("DebugWidget", "\345\215\212\345\220\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DebugWidget: public Ui_DebugWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGWIDGET_H
