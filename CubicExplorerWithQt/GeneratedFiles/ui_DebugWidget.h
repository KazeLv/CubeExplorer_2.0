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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DebugWidget
{
public:
    QGroupBox *groupBox_cams;
    QGroupBox *groupBox_case1;
    QGraphicsView *graphicsView_case1_FR;
    QGraphicsView *graphicsView_case1_UB;
    QGraphicsView *graphicsView_case1_LD;
    QLabel *label_FR;
    QLabel *label_UB;
    QLabel *label_LD;
    QGroupBox *groupBox_case2;
    QGraphicsView *graphicsView_case2_LD;
    QGraphicsView *graphicsView_case2_UB;
    QLabel *label_LD_2;
    QLabel *label_FR_2;
    QGraphicsView *graphicsView_case2_FR;
    QLabel *label_UB_2;
    QGroupBox *groupBox;
    QGroupBox *groupBox_left;
    QGroupBox *groupBox_left_rotation;
    QPushButton *btn_left_to90;
    QPushButton *btn_left_to180;
    QPushButton *btn_left_clockwise;
    QPushButton *btn_left_anticlockwise;
    QPushButton *btn_left_clockwise_small;
    QPushButton *btn_left_anticlockwise_small;
    QPushButton *btn_left_180;
    QPushButton *btn_left_5circle;
    QGroupBox *groupBox_left_open_close;
    QPushButton *btn_left_open_small;
    QPushButton *btn_left_open_all;
    QPushButton *btn_left_open;
    QPushButton *btn_left_close_half;
    QPushButton *btn_left_close;
    QPushButton *btn_left_close_small;
    QGroupBox *groupBox_right;
    QGroupBox *groupBox_right_rotation;
    QPushButton *btn_right_to90;
    QPushButton *btn_right_to180;
    QPushButton *btn_right_clockwise;
    QPushButton *btn_right_anticlockwise;
    QPushButton *btn_right_clockwise_small;
    QPushButton *btn_right_anticlockwise_small;
    QPushButton *btn_right_180;
    QPushButton *btn_right_5circle;
    QGroupBox *groupBox_right_open_close;
    QPushButton *btn_right_open_small;
    QPushButton *btn_right_open_all;
    QPushButton *btn_right_open;
    QPushButton *btn_right_close_half;
    QPushButton *btn_right_close;
    QPushButton *btn_right_close_small;

    void setupUi(QWidget *DebugWidget)
    {
        if (DebugWidget->objectName().isEmpty())
            DebugWidget->setObjectName(QStringLiteral("DebugWidget"));
        DebugWidget->resize(1519, 844);
        groupBox_cams = new QGroupBox(DebugWidget);
        groupBox_cams->setObjectName(QStringLiteral("groupBox_cams"));
        groupBox_cams->setGeometry(QRect(20, 30, 1471, 291));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(14);
        groupBox_cams->setFont(font);
        groupBox_case1 = new QGroupBox(groupBox_cams);
        groupBox_case1->setObjectName(QStringLiteral("groupBox_case1"));
        groupBox_case1->setGeometry(QRect(20, 40, 681, 231));
        graphicsView_case1_FR = new QGraphicsView(groupBox_case1);
        graphicsView_case1_FR->setObjectName(QStringLiteral("graphicsView_case1_FR"));
        graphicsView_case1_FR->setGeometry(QRect(20, 30, 200, 150));
        graphicsView_case1_UB = new QGraphicsView(groupBox_case1);
        graphicsView_case1_UB->setObjectName(QStringLiteral("graphicsView_case1_UB"));
        graphicsView_case1_UB->setGeometry(QRect(240, 30, 200, 150));
        graphicsView_case1_LD = new QGraphicsView(groupBox_case1);
        graphicsView_case1_LD->setObjectName(QStringLiteral("graphicsView_case1_LD"));
        graphicsView_case1_LD->setGeometry(QRect(460, 30, 200, 150));
        label_FR = new QLabel(groupBox_case1);
        label_FR->setObjectName(QStringLiteral("label_FR"));
        label_FR->setGeometry(QRect(80, 200, 81, 18));
        label_FR->setAlignment(Qt::AlignCenter);
        label_UB = new QLabel(groupBox_case1);
        label_UB->setObjectName(QStringLiteral("label_UB"));
        label_UB->setGeometry(QRect(300, 200, 81, 18));
        label_UB->setAlignment(Qt::AlignCenter);
        label_LD = new QLabel(groupBox_case1);
        label_LD->setObjectName(QStringLiteral("label_LD"));
        label_LD->setGeometry(QRect(510, 200, 81, 18));
        label_LD->setAlignment(Qt::AlignCenter);
        groupBox_case2 = new QGroupBox(groupBox_cams);
        groupBox_case2->setObjectName(QStringLiteral("groupBox_case2"));
        groupBox_case2->setGeometry(QRect(770, 40, 681, 231));
        graphicsView_case2_LD = new QGraphicsView(groupBox_case2);
        graphicsView_case2_LD->setObjectName(QStringLiteral("graphicsView_case2_LD"));
        graphicsView_case2_LD->setGeometry(QRect(460, 30, 200, 150));
        graphicsView_case2_UB = new QGraphicsView(groupBox_case2);
        graphicsView_case2_UB->setObjectName(QStringLiteral("graphicsView_case2_UB"));
        graphicsView_case2_UB->setGeometry(QRect(240, 30, 200, 150));
        label_LD_2 = new QLabel(groupBox_case2);
        label_LD_2->setObjectName(QStringLiteral("label_LD_2"));
        label_LD_2->setGeometry(QRect(510, 200, 81, 18));
        label_LD_2->setAlignment(Qt::AlignCenter);
        label_FR_2 = new QLabel(groupBox_case2);
        label_FR_2->setObjectName(QStringLiteral("label_FR_2"));
        label_FR_2->setGeometry(QRect(70, 200, 81, 18));
        label_FR_2->setAlignment(Qt::AlignCenter);
        graphicsView_case2_FR = new QGraphicsView(groupBox_case2);
        graphicsView_case2_FR->setObjectName(QStringLiteral("graphicsView_case2_FR"));
        graphicsView_case2_FR->setGeometry(QRect(20, 30, 200, 150));
        label_UB_2 = new QLabel(groupBox_case2);
        label_UB_2->setObjectName(QStringLiteral("label_UB_2"));
        label_UB_2->setGeometry(QRect(290, 200, 81, 18));
        label_UB_2->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(DebugWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 340, 1471, 481));
        groupBox->setFont(font);
        groupBox_left = new QGroupBox(groupBox);
        groupBox_left->setObjectName(QStringLiteral("groupBox_left"));
        groupBox_left->setGeometry(QRect(20, 40, 711, 421));
        groupBox_left_rotation = new QGroupBox(groupBox_left);
        groupBox_left_rotation->setObjectName(QStringLiteral("groupBox_left_rotation"));
        groupBox_left_rotation->setGeometry(QRect(20, 50, 321, 351));
        btn_left_to90 = new QPushButton(groupBox_left_rotation);
        btn_left_to90->setObjectName(QStringLiteral("btn_left_to90"));
        btn_left_to90->setGeometry(QRect(20, 60, 130, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Caslon Pro"));
        font1.setPointSize(10);
        btn_left_to90->setFont(font1);
        btn_left_to180 = new QPushButton(groupBox_left_rotation);
        btn_left_to180->setObjectName(QStringLiteral("btn_left_to180"));
        btn_left_to180->setGeometry(QRect(170, 60, 130, 40));
        btn_left_to180->setFont(font1);
        btn_left_clockwise = new QPushButton(groupBox_left_rotation);
        btn_left_clockwise->setObjectName(QStringLiteral("btn_left_clockwise"));
        btn_left_clockwise->setGeometry(QRect(20, 130, 130, 40));
        QFont font2;
        font2.setPointSize(10);
        btn_left_clockwise->setFont(font2);
        btn_left_anticlockwise = new QPushButton(groupBox_left_rotation);
        btn_left_anticlockwise->setObjectName(QStringLiteral("btn_left_anticlockwise"));
        btn_left_anticlockwise->setGeometry(QRect(170, 130, 130, 40));
        btn_left_anticlockwise->setFont(font2);
        btn_left_clockwise_small = new QPushButton(groupBox_left_rotation);
        btn_left_clockwise_small->setObjectName(QStringLiteral("btn_left_clockwise_small"));
        btn_left_clockwise_small->setGeometry(QRect(20, 200, 130, 40));
        btn_left_clockwise_small->setFont(font2);
        btn_left_anticlockwise_small = new QPushButton(groupBox_left_rotation);
        btn_left_anticlockwise_small->setObjectName(QStringLiteral("btn_left_anticlockwise_small"));
        btn_left_anticlockwise_small->setGeometry(QRect(170, 200, 130, 40));
        btn_left_anticlockwise_small->setFont(font2);
        btn_left_180 = new QPushButton(groupBox_left_rotation);
        btn_left_180->setObjectName(QStringLiteral("btn_left_180"));
        btn_left_180->setGeometry(QRect(20, 270, 130, 40));
        btn_left_180->setFont(font1);
        btn_left_5circle = new QPushButton(groupBox_left_rotation);
        btn_left_5circle->setObjectName(QStringLiteral("btn_left_5circle"));
        btn_left_5circle->setGeometry(QRect(170, 270, 130, 40));
        btn_left_5circle->setFont(font2);
        groupBox_left_open_close = new QGroupBox(groupBox_left);
        groupBox_left_open_close->setObjectName(QStringLiteral("groupBox_left_open_close"));
        groupBox_left_open_close->setGeometry(QRect(370, 50, 321, 351));
        btn_left_open_small = new QPushButton(groupBox_left_open_close);
        btn_left_open_small->setObjectName(QStringLiteral("btn_left_open_small"));
        btn_left_open_small->setGeometry(QRect(20, 130, 130, 40));
        btn_left_open_small->setFont(font2);
        btn_left_open_all = new QPushButton(groupBox_left_open_close);
        btn_left_open_all->setObjectName(QStringLiteral("btn_left_open_all"));
        btn_left_open_all->setGeometry(QRect(170, 200, 130, 40));
        btn_left_open_all->setFont(font2);
        btn_left_open = new QPushButton(groupBox_left_open_close);
        btn_left_open->setObjectName(QStringLiteral("btn_left_open"));
        btn_left_open->setGeometry(QRect(20, 60, 130, 40));
        btn_left_open->setFont(font1);
        btn_left_close_half = new QPushButton(groupBox_left_open_close);
        btn_left_close_half->setObjectName(QStringLiteral("btn_left_close_half"));
        btn_left_close_half->setGeometry(QRect(20, 200, 130, 40));
        btn_left_close_half->setFont(font2);
        btn_left_close = new QPushButton(groupBox_left_open_close);
        btn_left_close->setObjectName(QStringLiteral("btn_left_close"));
        btn_left_close->setGeometry(QRect(170, 60, 130, 40));
        btn_left_close->setFont(font1);
        btn_left_close_small = new QPushButton(groupBox_left_open_close);
        btn_left_close_small->setObjectName(QStringLiteral("btn_left_close_small"));
        btn_left_close_small->setGeometry(QRect(170, 130, 130, 40));
        btn_left_close_small->setFont(font2);
        groupBox_right = new QGroupBox(groupBox);
        groupBox_right->setObjectName(QStringLiteral("groupBox_right"));
        groupBox_right->setGeometry(QRect(750, 40, 701, 421));
        groupBox_right_rotation = new QGroupBox(groupBox_right);
        groupBox_right_rotation->setObjectName(QStringLiteral("groupBox_right_rotation"));
        groupBox_right_rotation->setGeometry(QRect(20, 50, 321, 351));
        btn_right_to90 = new QPushButton(groupBox_right_rotation);
        btn_right_to90->setObjectName(QStringLiteral("btn_right_to90"));
        btn_right_to90->setGeometry(QRect(20, 60, 130, 40));
        btn_right_to90->setFont(font1);
        btn_right_to180 = new QPushButton(groupBox_right_rotation);
        btn_right_to180->setObjectName(QStringLiteral("btn_right_to180"));
        btn_right_to180->setGeometry(QRect(170, 60, 130, 40));
        btn_right_to180->setFont(font1);
        btn_right_clockwise = new QPushButton(groupBox_right_rotation);
        btn_right_clockwise->setObjectName(QStringLiteral("btn_right_clockwise"));
        btn_right_clockwise->setGeometry(QRect(20, 130, 130, 40));
        btn_right_clockwise->setFont(font2);
        btn_right_anticlockwise = new QPushButton(groupBox_right_rotation);
        btn_right_anticlockwise->setObjectName(QStringLiteral("btn_right_anticlockwise"));
        btn_right_anticlockwise->setGeometry(QRect(170, 130, 130, 40));
        btn_right_anticlockwise->setFont(font2);
        btn_right_clockwise_small = new QPushButton(groupBox_right_rotation);
        btn_right_clockwise_small->setObjectName(QStringLiteral("btn_right_clockwise_small"));
        btn_right_clockwise_small->setGeometry(QRect(20, 200, 130, 40));
        btn_right_clockwise_small->setFont(font2);
        btn_right_anticlockwise_small = new QPushButton(groupBox_right_rotation);
        btn_right_anticlockwise_small->setObjectName(QStringLiteral("btn_right_anticlockwise_small"));
        btn_right_anticlockwise_small->setGeometry(QRect(170, 200, 130, 40));
        btn_right_anticlockwise_small->setFont(font2);
        btn_right_180 = new QPushButton(groupBox_right_rotation);
        btn_right_180->setObjectName(QStringLiteral("btn_right_180"));
        btn_right_180->setGeometry(QRect(20, 270, 130, 40));
        btn_right_180->setFont(font1);
        btn_right_5circle = new QPushButton(groupBox_right_rotation);
        btn_right_5circle->setObjectName(QStringLiteral("btn_right_5circle"));
        btn_right_5circle->setGeometry(QRect(170, 270, 130, 40));
        btn_right_5circle->setFont(font2);
        groupBox_right_open_close = new QGroupBox(groupBox_right);
        groupBox_right_open_close->setObjectName(QStringLiteral("groupBox_right_open_close"));
        groupBox_right_open_close->setGeometry(QRect(360, 50, 321, 351));
        btn_right_open_small = new QPushButton(groupBox_right_open_close);
        btn_right_open_small->setObjectName(QStringLiteral("btn_right_open_small"));
        btn_right_open_small->setGeometry(QRect(20, 130, 130, 40));
        btn_right_open_small->setFont(font2);
        btn_right_open_all = new QPushButton(groupBox_right_open_close);
        btn_right_open_all->setObjectName(QStringLiteral("btn_right_open_all"));
        btn_right_open_all->setGeometry(QRect(170, 200, 130, 40));
        btn_right_open_all->setFont(font2);
        btn_right_open = new QPushButton(groupBox_right_open_close);
        btn_right_open->setObjectName(QStringLiteral("btn_right_open"));
        btn_right_open->setGeometry(QRect(20, 60, 130, 40));
        btn_right_open->setFont(font1);
        btn_right_close_half = new QPushButton(groupBox_right_open_close);
        btn_right_close_half->setObjectName(QStringLiteral("btn_right_close_half"));
        btn_right_close_half->setGeometry(QRect(20, 200, 130, 40));
        btn_right_close_half->setFont(font2);
        btn_right_close = new QPushButton(groupBox_right_open_close);
        btn_right_close->setObjectName(QStringLiteral("btn_right_close"));
        btn_right_close->setGeometry(QRect(170, 60, 130, 40));
        btn_right_close->setFont(font1);
        btn_right_close_small = new QPushButton(groupBox_right_open_close);
        btn_right_close_small->setObjectName(QStringLiteral("btn_right_close_small"));
        btn_right_close_small->setGeometry(QRect(170, 130, 130, 40));
        btn_right_close_small->setFont(font2);

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
        label_LD_2->setText(QApplication::translate("DebugWidget", "LD", Q_NULLPTR));
        label_FR_2->setText(QApplication::translate("DebugWidget", "FR", Q_NULLPTR));
        label_UB_2->setText(QApplication::translate("DebugWidget", "UB", Q_NULLPTR));
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
        btn_left_open_all->setText(QApplication::translate("DebugWidget", "\345\205\250\345\274\200", Q_NULLPTR));
        btn_left_open->setText(QApplication::translate("DebugWidget", "\346\211\223\345\274\200", Q_NULLPTR));
        btn_left_close_half->setText(QApplication::translate("DebugWidget", "\345\215\212\345\220\210", Q_NULLPTR));
        btn_left_close->setText(QApplication::translate("DebugWidget", "\345\220\210\344\270\212", Q_NULLPTR));
        btn_left_close_small->setText(QApplication::translate("DebugWidget", "\345\220\210\344\270\212(\345\276\256\350\260\203)", Q_NULLPTR));
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
        btn_right_open_small->setText(QApplication::translate("DebugWidget", "\346\211\223\345\274\200(\345\276\256\350\260\203)", Q_NULLPTR));
        btn_right_open_all->setText(QApplication::translate("DebugWidget", "\345\205\250\345\274\200", Q_NULLPTR));
        btn_right_open->setText(QApplication::translate("DebugWidget", "\346\211\223\345\274\200", Q_NULLPTR));
        btn_right_close_half->setText(QApplication::translate("DebugWidget", "\345\215\212\345\220\210", Q_NULLPTR));
        btn_right_close->setText(QApplication::translate("DebugWidget", "\345\220\210\344\270\212", Q_NULLPTR));
        btn_right_close_small->setText(QApplication::translate("DebugWidget", "\345\220\210\344\270\212(\345\276\256\350\260\203)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DebugWidget: public Ui_DebugWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGWIDGET_H
