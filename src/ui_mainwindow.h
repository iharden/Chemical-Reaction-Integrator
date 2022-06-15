/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCommandLinkButton *generate_system;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *rate_energies;
    QLineEdit *line1_2;
    QLineEdit *line2_2;
    QLineEdit *line3_2;
    QLineEdit *line4_2;
    QLineEdit *line5_2;
    QLineEdit *line6_2;
    QLineEdit *line7_2;
    QLineEdit *line8_2;
    QLineEdit *line9_2;
    QLineEdit *line10_2;
    QLineEdit *line11_2;
    QLineEdit *line12_2;
    QLineEdit *line13_2;
    QLineEdit *line14_2;
    QLineEdit *line15_2;
    QVBoxLayout *reaction_equations;
    QLineEdit *line1;
    QLineEdit *line2;
    QLineEdit *line3;
    QLineEdit *line4;
    QLineEdit *line5;
    QLineEdit *line6;
    QLineEdit *line7;
    QLineEdit *line8;
    QLineEdit *line9;
    QLineEdit *line10;
    QLineEdit *line11;
    QLineEdit *line12;
    QLineEdit *line13;
    QLineEdit *line14;
    QLineEdit *line15;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_37;
    QLineEdit *lineEdit_38;
    QLineEdit *lineEdit_39;
    QLineEdit *lineEdit_40;
    QLineEdit *lineEdit_41;
    QLineEdit *lineEdit_42;
    QLineEdit *lineEdit_43;
    QLineEdit *lineEdit_44;
    QLineEdit *lineEdit_45;
    QLineEdit *lineEdit_46;
    QLineEdit *lineEdit_47;
    QLineEdit *lineEdit_48;
    QLineEdit *lineEdit_49;
    QLineEdit *lineEdit_50;
    QLineEdit *lineEdit_51;
    QLabel *label;
    QCheckBox *boolactivation;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *all_energy_options;
    QCheckBox *kcal;
    QCheckBox *ev;
    QCheckBox *Hartree;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_23;
    QLineEdit *lineEdit_22;
    QLineEdit *lineEdit_21;
    QLineEdit *lineEdit_20;
    QLineEdit *lineEdit_19;
    QLineEdit *lineEdit_18;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_27;
    QLineEdit *lineEdit_30;
    QLineEdit *lineEdit_29;
    QLineEdit *lineEdit_28;
    QLineEdit *lineEdit_26;
    QLineEdit *lineEdit_25;
    QLineEdit *lineEdit_24;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_16;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_7;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_31;
    QLineEdit *lineEdit_32;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_33;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QCommandLinkButton *calculateButton;
    QCheckBox *xlog;
    QCheckBox *ylog;
    QLineEdit *lineEdit_34;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *lineEdit_35;
    QLineEdit *lineEdit_36;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *safeButton;
    QPushButton *loadButton;
    QPushButton *pushRawdata;
    QPushButton *pushPng;
    QLabel *label_17;
    QLabel *label_18;
    QChartView *chartview;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1578, 1001);
        MainWindow->setAcceptDrops(false);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(1578, 0));
        centralwidget->setAutoFillBackground(true);
        generate_system = new QCommandLinkButton(centralwidget);
        generate_system->setObjectName(QString::fromUtf8("generate_system"));
        generate_system->setGeometry(QRect(390, 430, 191, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(14);
        generate_system->setFont(font);
        generate_system->setAutoFillBackground(true);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 150, 371, 312));
        scrollArea->setMouseTracking(true);
        scrollArea->setLayoutDirection(Qt::LeftToRight);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 352, 434));
        scrollAreaWidgetContents->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rate_energies = new QVBoxLayout();
        rate_energies->setObjectName(QString::fromUtf8("rate_energies"));
        line1_2 = new QLineEdit(scrollAreaWidgetContents);
        line1_2->setObjectName(QString::fromUtf8("line1_2"));
        line1_2->setClearButtonEnabled(false);

        rate_energies->addWidget(line1_2);

        line2_2 = new QLineEdit(scrollAreaWidgetContents);
        line2_2->setObjectName(QString::fromUtf8("line2_2"));

        rate_energies->addWidget(line2_2);

        line3_2 = new QLineEdit(scrollAreaWidgetContents);
        line3_2->setObjectName(QString::fromUtf8("line3_2"));

        rate_energies->addWidget(line3_2);

        line4_2 = new QLineEdit(scrollAreaWidgetContents);
        line4_2->setObjectName(QString::fromUtf8("line4_2"));

        rate_energies->addWidget(line4_2);

        line5_2 = new QLineEdit(scrollAreaWidgetContents);
        line5_2->setObjectName(QString::fromUtf8("line5_2"));

        rate_energies->addWidget(line5_2);

        line6_2 = new QLineEdit(scrollAreaWidgetContents);
        line6_2->setObjectName(QString::fromUtf8("line6_2"));

        rate_energies->addWidget(line6_2);

        line7_2 = new QLineEdit(scrollAreaWidgetContents);
        line7_2->setObjectName(QString::fromUtf8("line7_2"));
        line7_2->setMaximumSize(QSize(126, 16777215));

        rate_energies->addWidget(line7_2);

        line8_2 = new QLineEdit(scrollAreaWidgetContents);
        line8_2->setObjectName(QString::fromUtf8("line8_2"));

        rate_energies->addWidget(line8_2);

        line9_2 = new QLineEdit(scrollAreaWidgetContents);
        line9_2->setObjectName(QString::fromUtf8("line9_2"));

        rate_energies->addWidget(line9_2);

        line10_2 = new QLineEdit(scrollAreaWidgetContents);
        line10_2->setObjectName(QString::fromUtf8("line10_2"));

        rate_energies->addWidget(line10_2);

        line11_2 = new QLineEdit(scrollAreaWidgetContents);
        line11_2->setObjectName(QString::fromUtf8("line11_2"));

        rate_energies->addWidget(line11_2);

        line12_2 = new QLineEdit(scrollAreaWidgetContents);
        line12_2->setObjectName(QString::fromUtf8("line12_2"));

        rate_energies->addWidget(line12_2);

        line13_2 = new QLineEdit(scrollAreaWidgetContents);
        line13_2->setObjectName(QString::fromUtf8("line13_2"));

        rate_energies->addWidget(line13_2);

        line14_2 = new QLineEdit(scrollAreaWidgetContents);
        line14_2->setObjectName(QString::fromUtf8("line14_2"));

        rate_energies->addWidget(line14_2);

        line15_2 = new QLineEdit(scrollAreaWidgetContents);
        line15_2->setObjectName(QString::fromUtf8("line15_2"));

        rate_energies->addWidget(line15_2);


        horizontalLayout->addLayout(rate_energies);

        reaction_equations = new QVBoxLayout();
        reaction_equations->setObjectName(QString::fromUtf8("reaction_equations"));
        line1 = new QLineEdit(scrollAreaWidgetContents);
        line1->setObjectName(QString::fromUtf8("line1"));
        line1->setClearButtonEnabled(false);

        reaction_equations->addWidget(line1);

        line2 = new QLineEdit(scrollAreaWidgetContents);
        line2->setObjectName(QString::fromUtf8("line2"));

        reaction_equations->addWidget(line2);

        line3 = new QLineEdit(scrollAreaWidgetContents);
        line3->setObjectName(QString::fromUtf8("line3"));

        reaction_equations->addWidget(line3);

        line4 = new QLineEdit(scrollAreaWidgetContents);
        line4->setObjectName(QString::fromUtf8("line4"));

        reaction_equations->addWidget(line4);

        line5 = new QLineEdit(scrollAreaWidgetContents);
        line5->setObjectName(QString::fromUtf8("line5"));

        reaction_equations->addWidget(line5);

        line6 = new QLineEdit(scrollAreaWidgetContents);
        line6->setObjectName(QString::fromUtf8("line6"));

        reaction_equations->addWidget(line6);

        line7 = new QLineEdit(scrollAreaWidgetContents);
        line7->setObjectName(QString::fromUtf8("line7"));

        reaction_equations->addWidget(line7);

        line8 = new QLineEdit(scrollAreaWidgetContents);
        line8->setObjectName(QString::fromUtf8("line8"));

        reaction_equations->addWidget(line8);

        line9 = new QLineEdit(scrollAreaWidgetContents);
        line9->setObjectName(QString::fromUtf8("line9"));

        reaction_equations->addWidget(line9);

        line10 = new QLineEdit(scrollAreaWidgetContents);
        line10->setObjectName(QString::fromUtf8("line10"));

        reaction_equations->addWidget(line10);

        line11 = new QLineEdit(scrollAreaWidgetContents);
        line11->setObjectName(QString::fromUtf8("line11"));

        reaction_equations->addWidget(line11);

        line12 = new QLineEdit(scrollAreaWidgetContents);
        line12->setObjectName(QString::fromUtf8("line12"));

        reaction_equations->addWidget(line12);

        line13 = new QLineEdit(scrollAreaWidgetContents);
        line13->setObjectName(QString::fromUtf8("line13"));

        reaction_equations->addWidget(line13);

        line14 = new QLineEdit(scrollAreaWidgetContents);
        line14->setObjectName(QString::fromUtf8("line14"));

        reaction_equations->addWidget(line14);

        line15 = new QLineEdit(scrollAreaWidgetContents);
        line15->setObjectName(QString::fromUtf8("line15"));

        reaction_equations->addWidget(line15);


        horizontalLayout->addLayout(reaction_equations);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lineEdit_37 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_37->setObjectName(QString::fromUtf8("lineEdit_37"));

        verticalLayout_3->addWidget(lineEdit_37);

        lineEdit_38 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_38->setObjectName(QString::fromUtf8("lineEdit_38"));

        verticalLayout_3->addWidget(lineEdit_38);

        lineEdit_39 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_39->setObjectName(QString::fromUtf8("lineEdit_39"));

        verticalLayout_3->addWidget(lineEdit_39);

        lineEdit_40 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_40->setObjectName(QString::fromUtf8("lineEdit_40"));

        verticalLayout_3->addWidget(lineEdit_40);

        lineEdit_41 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_41->setObjectName(QString::fromUtf8("lineEdit_41"));

        verticalLayout_3->addWidget(lineEdit_41);

        lineEdit_42 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_42->setObjectName(QString::fromUtf8("lineEdit_42"));

        verticalLayout_3->addWidget(lineEdit_42);

        lineEdit_43 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_43->setObjectName(QString::fromUtf8("lineEdit_43"));

        verticalLayout_3->addWidget(lineEdit_43);

        lineEdit_44 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_44->setObjectName(QString::fromUtf8("lineEdit_44"));

        verticalLayout_3->addWidget(lineEdit_44);

        lineEdit_45 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_45->setObjectName(QString::fromUtf8("lineEdit_45"));

        verticalLayout_3->addWidget(lineEdit_45);

        lineEdit_46 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_46->setObjectName(QString::fromUtf8("lineEdit_46"));

        verticalLayout_3->addWidget(lineEdit_46);

        lineEdit_47 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_47->setObjectName(QString::fromUtf8("lineEdit_47"));

        verticalLayout_3->addWidget(lineEdit_47);

        lineEdit_48 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_48->setObjectName(QString::fromUtf8("lineEdit_48"));

        verticalLayout_3->addWidget(lineEdit_48);

        lineEdit_49 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_49->setObjectName(QString::fromUtf8("lineEdit_49"));

        verticalLayout_3->addWidget(lineEdit_49);

        lineEdit_50 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_50->setObjectName(QString::fromUtf8("lineEdit_50"));

        verticalLayout_3->addWidget(lineEdit_50);

        lineEdit_51 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_51->setObjectName(QString::fromUtf8("lineEdit_51"));

        verticalLayout_3->addWidget(lineEdit_51);


        horizontalLayout->addLayout(verticalLayout_3);

        scrollArea->setWidget(scrollAreaWidgetContents);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 60, 221, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        font1.setBold(true);
        label->setFont(font1);
        boolactivation = new QCheckBox(centralwidget);
        boolactivation->setObjectName(QString::fromUtf8("boolactivation"));
        boolactivation->setGeometry(QRect(400, 150, 161, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 90, 111, 16));
        QFont font2;
        font2.setBold(true);
        label_2->setFont(font2);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(190, 80, 171, 31));
        QFont font3;
        font3.setBold(true);
        font3.setItalic(false);
        label_3->setFont(font3);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(400, 190, 160, 80));
        all_energy_options = new QVBoxLayout(verticalLayoutWidget);
        all_energy_options->setObjectName(QString::fromUtf8("all_energy_options"));
        all_energy_options->setContentsMargins(0, 0, 0, 0);
        kcal = new QCheckBox(verticalLayoutWidget);
        kcal->setObjectName(QString::fromUtf8("kcal"));
        kcal->setEnabled(true);

        all_energy_options->addWidget(kcal);

        ev = new QCheckBox(verticalLayoutWidget);
        ev->setObjectName(QString::fromUtf8("ev"));
        ev->setEnabled(true);

        all_energy_options->addWidget(ev);

        Hartree = new QCheckBox(verticalLayoutWidget);
        Hartree->setObjectName(QString::fromUtf8("Hartree"));
        Hartree->setEnabled(true);
        Hartree->setTristate(false);

        all_energy_options->addWidget(Hartree);

        scrollArea_2 = new QScrollArea(centralwidget);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(10, 530, 301, 184));
        scrollArea_2->setLayoutDirection(Qt::LeftToRight);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 282, 434));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit_6 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        verticalLayout->addWidget(lineEdit_6);

        lineEdit_5 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout->addWidget(lineEdit_5);

        lineEdit_23 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_23->setObjectName(QString::fromUtf8("lineEdit_23"));

        verticalLayout->addWidget(lineEdit_23);

        lineEdit_22 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_22->setObjectName(QString::fromUtf8("lineEdit_22"));

        verticalLayout->addWidget(lineEdit_22);

        lineEdit_21 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_21->setObjectName(QString::fromUtf8("lineEdit_21"));

        verticalLayout->addWidget(lineEdit_21);

        lineEdit_20 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));

        verticalLayout->addWidget(lineEdit_20);

        lineEdit_19 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_19->setObjectName(QString::fromUtf8("lineEdit_19"));

        verticalLayout->addWidget(lineEdit_19);

        lineEdit_18 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_18->setObjectName(QString::fromUtf8("lineEdit_18"));

        verticalLayout->addWidget(lineEdit_18);

        lineEdit_17 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));

        verticalLayout->addWidget(lineEdit_17);

        lineEdit_11 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        verticalLayout->addWidget(lineEdit_11);

        lineEdit_3 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout->addWidget(lineEdit_3);

        lineEdit_10 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        verticalLayout->addWidget(lineEdit_10);

        lineEdit_4 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout->addWidget(lineEdit_4);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        lineEdit = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(101, 0));

        verticalLayout->addWidget(lineEdit);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_8 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        verticalLayout_2->addWidget(lineEdit_8);

        lineEdit_27 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_27->setObjectName(QString::fromUtf8("lineEdit_27"));

        verticalLayout_2->addWidget(lineEdit_27);

        lineEdit_30 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_30->setObjectName(QString::fromUtf8("lineEdit_30"));

        verticalLayout_2->addWidget(lineEdit_30);

        lineEdit_29 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_29->setObjectName(QString::fromUtf8("lineEdit_29"));

        verticalLayout_2->addWidget(lineEdit_29);

        lineEdit_28 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_28->setObjectName(QString::fromUtf8("lineEdit_28"));

        verticalLayout_2->addWidget(lineEdit_28);

        lineEdit_26 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_26->setObjectName(QString::fromUtf8("lineEdit_26"));

        verticalLayout_2->addWidget(lineEdit_26);

        lineEdit_25 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_25->setObjectName(QString::fromUtf8("lineEdit_25"));

        verticalLayout_2->addWidget(lineEdit_25);

        lineEdit_24 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_24->setObjectName(QString::fromUtf8("lineEdit_24"));

        verticalLayout_2->addWidget(lineEdit_24);

        lineEdit_14 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));

        verticalLayout_2->addWidget(lineEdit_14);

        lineEdit_16 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));

        verticalLayout_2->addWidget(lineEdit_16);

        lineEdit_15 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));

        verticalLayout_2->addWidget(lineEdit_15);

        lineEdit_13 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));

        verticalLayout_2->addWidget(lineEdit_13);

        lineEdit_12 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));

        verticalLayout_2->addWidget(lineEdit_12);

        lineEdit_9 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        verticalLayout_2->addWidget(lineEdit_9);

        lineEdit_7 = new QLineEdit(scrollAreaWidgetContents_2);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        verticalLayout_2->addWidget(lineEdit_7);


        horizontalLayout_2->addLayout(verticalLayout_2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(320, 560, 71, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(320, 600, 81, 31));
        lineEdit_31 = new QLineEdit(centralwidget);
        lineEdit_31->setObjectName(QString::fromUtf8("lineEdit_31"));
        lineEdit_31->setGeometry(QRect(320, 580, 71, 21));
        lineEdit_32 = new QLineEdit(centralwidget);
        lineEdit_32->setObjectName(QString::fromUtf8("lineEdit_32"));
        lineEdit_32->setGeometry(QRect(320, 630, 71, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(400, 580, 47, 13));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(400, 630, 47, 13));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(400, 280, 81, 21));
        lineEdit_33 = new QLineEdit(centralwidget);
        lineEdit_33->setObjectName(QString::fromUtf8("lineEdit_33"));
        lineEdit_33->setGeometry(QRect(400, 300, 71, 21));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(480, 300, 47, 13));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 480, 291, 21));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        label_10->setFont(font4);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(60, 510, 47, 13));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(200, 510, 71, 16));
        calculateButton = new QCommandLinkButton(centralwidget);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setGeometry(QRect(320, 740, 141, 51));
        calculateButton->setFont(font);
        xlog = new QCheckBox(centralwidget);
        xlog->setObjectName(QString::fromUtf8("xlog"));
        xlog->setGeometry(QRect(1220, 730, 131, 19));
        ylog = new QCheckBox(centralwidget);
        ylog->setObjectName(QString::fromUtf8("ylog"));
        ylog->setGeometry(QRect(590, 80, 141, 19));
        lineEdit_34 = new QLineEdit(centralwidget);
        lineEdit_34->setObjectName(QString::fromUtf8("lineEdit_34"));
        lineEdit_34->setGeometry(QRect(320, 670, 71, 21));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(320, 650, 121, 16));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(400, 670, 47, 13));
        lineEdit_35 = new QLineEdit(centralwidget);
        lineEdit_35->setObjectName(QString::fromUtf8("lineEdit_35"));
        lineEdit_35->setGeometry(QRect(20, 750, 113, 21));
        lineEdit_36 = new QLineEdit(centralwidget);
        lineEdit_36->setObjectName(QString::fromUtf8("lineEdit_36"));
        lineEdit_36->setGeometry(QRect(160, 750, 113, 21));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(50, 730, 91, 16));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(190, 730, 91, 16));
        safeButton = new QPushButton(centralwidget);
        safeButton->setObjectName(QString::fromUtf8("safeButton"));
        safeButton->setGeometry(QRect(50, 10, 80, 21));
        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setGeometry(QRect(170, 10, 80, 21));
        pushRawdata = new QPushButton(centralwidget);
        pushRawdata->setObjectName(QString::fromUtf8("pushRawdata"));
        pushRawdata->setGeometry(QRect(1360, 100, 111, 21));
        pushPng = new QPushButton(centralwidget);
        pushPng->setObjectName(QString::fromUtf8("pushPng"));
        pushPng->setGeometry(QRect(1360, 140, 111, 21));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(140, 110, 101, 31));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(250, 110, 161, 31));
        chartview = new QChartView(centralwidget);
        chartview->setObjectName(QString::fromUtf8("chartview"));
        chartview->setGeometry(QRect(580, 120, 751, 601));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(generate_system, SIGNAL(clicked()), MainWindow, SLOT(my_slot()));
        QObject::connect(boolactivation, SIGNAL(clicked(bool)), MainWindow, SLOT(set_energyinput()));
        QObject::connect(kcal, SIGNAL(clicked(bool)), MainWindow, SLOT(set_energyunit()));
        QObject::connect(ev, SIGNAL(clicked(bool)), MainWindow, SLOT(set_energyunit()));
        QObject::connect(Hartree, SIGNAL(clicked(bool)), MainWindow, SLOT(set_energyunit()));
        QObject::connect(calculateButton, SIGNAL(clicked()), MainWindow, SLOT(do_calculation()));
        QObject::connect(xlog, SIGNAL(clicked(bool)), MainWindow, SLOT(set_xlog()));
        QObject::connect(ylog, SIGNAL(clicked(bool)), MainWindow, SLOT(set_ylog()));
        QObject::connect(safeButton, SIGNAL(clicked()), MainWindow, SLOT(safeFile()));
        QObject::connect(loadButton, SIGNAL(clicked()), MainWindow, SLOT(loadFile()));
        QObject::connect(pushRawdata, SIGNAL(clicked()), MainWindow, SLOT(export_raw()));
        QObject::connect(pushPng, SIGNAL(clicked()), MainWindow, SLOT(export_png()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        generate_system->setText(QCoreApplication::translate("MainWindow", "Read in System!", nullptr));
#if QT_CONFIG(accessibility)
        scrollArea->setAccessibleName(QCoreApplication::translate("MainWindow", "Reaction equations", nullptr));
#endif // QT_CONFIG(accessibility)
        label->setText(QCoreApplication::translate("MainWindow", "Set reaction equations here!", nullptr));
        boolactivation->setText(QCoreApplication::translate("MainWindow", "Put activation energies \n"
" instead of rate constants", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Reaction equation", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Actication energy \n"
" or rate constant", nullptr));
        kcal->setText(QCoreApplication::translate("MainWindow", "kcal/mol", nullptr));
        ev->setText(QCoreApplication::translate("MainWindow", "eV", nullptr));
        Hartree->setText(QCoreApplication::translate("MainWindow", "Hartree", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Starting time", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Ending time", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "s", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "s", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Temperature", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "K", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Set initial concentrations here!", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Species", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "c [mol/L]", nullptr));
        calculateButton->setText(QCoreApplication::translate("MainWindow", "Calculate!", nullptr));
        xlog->setText(QCoreApplication::translate("MainWindow", "logarithmic scale", nullptr));
        ylog->setText(QCoreApplication::translate("MainWindow", "logarithmic scale", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Initial  time intervall", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "s", nullptr));
        lineEdit_35->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "abs. error", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "rel. error", nullptr));
        safeButton->setText(QCoreApplication::translate("MainWindow", "Save...", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "Load...", nullptr));
        pushRawdata->setText(QCoreApplication::translate("MainWindow", "Export raw data", nullptr));
        pushPng->setText(QCoreApplication::translate("MainWindow", "Export png", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Forward reaction", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Backward reaction(optional)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
