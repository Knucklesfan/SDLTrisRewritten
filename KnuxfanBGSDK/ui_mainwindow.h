/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "previewrenderer.h"
#include "texturepreview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Project;
    QAction *actionExit;
    QAction *actionLoad_Background;
    QAction *actionSave_XML;
    QAction *actionExport_KNBG;
    QAction *actionClose_2;
    QAction *actionModel_Converter;
    QAction *actionDeltatime_Calculator;
    QAction *actionAbout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *root;
    QHBoxLayout *upper;
    GLWidget *previewview;
    QTabWidget *toptabs;
    QWidget *animationtab;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_4;
    QHBoxLayout *animationbuttons;
    QPushButton *animationadd;
    QPushButton *animationdelete;
    QPushButton *animationup;
    QPushButton *animationdown;
    QWidget *optiontab;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *tableWidget_5;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_16;
    QPushButton *pushButton_15;
    QPushButton *pushButton_14;
    QWidget *debugcamera;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QDoubleSpinBox *camerax;
    QDoubleSpinBox *cameray;
    QDoubleSpinBox *cameraz;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QDoubleSpinBox *camerarx;
    QDoubleSpinBox *camerary;
    QDoubleSpinBox *camerarz;
    QVBoxLayout *lower;
    QTabWidget *bottomtabs;
    QWidget *layertab;
    QVBoxLayout *verticalLayout_4;
    QLabel *layerlabel;
    QTableWidget *layertable;
    QHBoxLayout *layerlayout;
    QPushButton *addlayer;
    QPushButton *editlayer;
    QPushButton *deletelayer;
    QPushButton *exportlayer;
    QWidget *tab_playback;
    QWidget *objecttab;
    QVBoxLayout *verticalLayout_5;
    QLabel *objectlabel;
    QHBoxLayout *objectlayout;
    QTableWidget *objecttable;
    QVBoxLayout *objectshaderholder;
    QOpenGLWidget *objectpreview;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QComboBox *objecttexturepreviewcombo;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QComboBox *objectshadercombo;
    QHBoxLayout *objectbuttons;
    QPushButton *addobject;
    QPushButton *deleteobject;
    QWidget *shaderstab;
    QVBoxLayout *verticalLayout_6;
    QLabel *shaderlabel;
    QTableWidget *shadertable;
    QHBoxLayout *objectbuttons_2;
    QPushButton *addshader;
    QPushButton *removeshader;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *texturetable;
    QVBoxLayout *verticalLayout_3;
    TexturePreview *texturepreview;
    QHBoxLayout *horizontalLayout_4;
    QLabel *texturecombolabel;
    QComboBox *texturecombo;
    QHBoxLayout *horizontalLayout;
    QPushButton *addtexture;
    QPushButton *deletetexture;
    QPushButton *refreshtexture;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSave_Background;
    QMenu *menuTools;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1259, 987);
        actionNew_Project = new QAction(MainWindow);
        actionNew_Project->setObjectName(QString::fromUtf8("actionNew_Project"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionLoad_Background = new QAction(MainWindow);
        actionLoad_Background->setObjectName(QString::fromUtf8("actionLoad_Background"));
        actionSave_XML = new QAction(MainWindow);
        actionSave_XML->setObjectName(QString::fromUtf8("actionSave_XML"));
        actionExport_KNBG = new QAction(MainWindow);
        actionExport_KNBG->setObjectName(QString::fromUtf8("actionExport_KNBG"));
        actionClose_2 = new QAction(MainWindow);
        actionClose_2->setObjectName(QString::fromUtf8("actionClose_2"));
        actionModel_Converter = new QAction(MainWindow);
        actionModel_Converter->setObjectName(QString::fromUtf8("actionModel_Converter"));
        actionDeltatime_Calculator = new QAction(MainWindow);
        actionDeltatime_Calculator->setObjectName(QString::fromUtf8("actionDeltatime_Calculator"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        root = new QVBoxLayout();
        root->setObjectName(QString::fromUtf8("root"));
        upper = new QHBoxLayout();
        upper->setObjectName(QString::fromUtf8("upper"));
        previewview = new GLWidget(centralwidget);
        previewview->setObjectName(QString::fromUtf8("previewview"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(previewview->sizePolicy().hasHeightForWidth());
        previewview->setSizePolicy(sizePolicy1);
        previewview->setMinimumSize(QSize(640, 480));
        previewview->setMaximumSize(QSize(640, 480));
        previewview->setSizeIncrement(QSize(0, 0));

        upper->addWidget(previewview);

        toptabs = new QTabWidget(centralwidget);
        toptabs->setObjectName(QString::fromUtf8("toptabs"));
        animationtab = new QWidget();
        animationtab->setObjectName(QString::fromUtf8("animationtab"));
        verticalLayout = new QVBoxLayout(animationtab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget_4 = new QTableWidget(animationtab);
        tableWidget_4->setObjectName(QString::fromUtf8("tableWidget_4"));

        verticalLayout->addWidget(tableWidget_4);

        animationbuttons = new QHBoxLayout();
        animationbuttons->setObjectName(QString::fromUtf8("animationbuttons"));
        animationadd = new QPushButton(animationtab);
        animationadd->setObjectName(QString::fromUtf8("animationadd"));

        animationbuttons->addWidget(animationadd);

        animationdelete = new QPushButton(animationtab);
        animationdelete->setObjectName(QString::fromUtf8("animationdelete"));

        animationbuttons->addWidget(animationdelete);

        animationup = new QPushButton(animationtab);
        animationup->setObjectName(QString::fromUtf8("animationup"));

        animationbuttons->addWidget(animationup);

        animationdown = new QPushButton(animationtab);
        animationdown->setObjectName(QString::fromUtf8("animationdown"));

        animationbuttons->addWidget(animationdown);


        verticalLayout->addLayout(animationbuttons);

        toptabs->addTab(animationtab, QString());
        optiontab = new QWidget();
        optiontab->setObjectName(QString::fromUtf8("optiontab"));
        verticalLayout_8 = new QVBoxLayout(optiontab);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        tableWidget_5 = new QTableWidget(optiontab);
        tableWidget_5->setObjectName(QString::fromUtf8("tableWidget_5"));

        verticalLayout_8->addWidget(tableWidget_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_16 = new QPushButton(optiontab);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));

        horizontalLayout_8->addWidget(pushButton_16);

        pushButton_15 = new QPushButton(optiontab);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        horizontalLayout_8->addWidget(pushButton_15);

        pushButton_14 = new QPushButton(optiontab);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        horizontalLayout_8->addWidget(pushButton_14);


        verticalLayout_8->addLayout(horizontalLayout_8);

        toptabs->addTab(optiontab, QString());
        debugcamera = new QWidget();
        debugcamera->setObjectName(QString::fromUtf8("debugcamera"));
        verticalLayout_9 = new QVBoxLayout(debugcamera);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(debugcamera);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        camerax = new QDoubleSpinBox(debugcamera);
        camerax->setObjectName(QString::fromUtf8("camerax"));
        camerax->setMinimum(-99.989999999999995);

        horizontalLayout_3->addWidget(camerax);

        cameray = new QDoubleSpinBox(debugcamera);
        cameray->setObjectName(QString::fromUtf8("cameray"));
        cameray->setMinimum(-99.989999999999995);

        horizontalLayout_3->addWidget(cameray);

        cameraz = new QDoubleSpinBox(debugcamera);
        cameraz->setObjectName(QString::fromUtf8("cameraz"));
        cameraz->setMinimum(-99.989999999999995);

        horizontalLayout_3->addWidget(cameraz);


        verticalLayout_9->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(debugcamera);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        camerarx = new QDoubleSpinBox(debugcamera);
        camerarx->setObjectName(QString::fromUtf8("camerarx"));
        camerarx->setMinimum(-360.000000000000000);
        camerarx->setMaximum(360.000000000000000);

        horizontalLayout_7->addWidget(camerarx);

        camerary = new QDoubleSpinBox(debugcamera);
        camerary->setObjectName(QString::fromUtf8("camerary"));
        camerary->setMinimum(-360.000000000000000);
        camerary->setMaximum(360.000000000000000);

        horizontalLayout_7->addWidget(camerary);

        camerarz = new QDoubleSpinBox(debugcamera);
        camerarz->setObjectName(QString::fromUtf8("camerarz"));
        camerarz->setMinimum(-360.000000000000000);
        camerarz->setMaximum(360.000000000000000);

        horizontalLayout_7->addWidget(camerarz);


        verticalLayout_9->addLayout(horizontalLayout_7);

        toptabs->addTab(debugcamera, QString());

        upper->addWidget(toptabs);


        root->addLayout(upper);

        lower = new QVBoxLayout();
        lower->setObjectName(QString::fromUtf8("lower"));
        bottomtabs = new QTabWidget(centralwidget);
        bottomtabs->setObjectName(QString::fromUtf8("bottomtabs"));
        layertab = new QWidget();
        layertab->setObjectName(QString::fromUtf8("layertab"));
        verticalLayout_4 = new QVBoxLayout(layertab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        layerlabel = new QLabel(layertab);
        layerlabel->setObjectName(QString::fromUtf8("layerlabel"));

        verticalLayout_4->addWidget(layerlabel);

        layertable = new QTableWidget(layertab);
        layertable->setObjectName(QString::fromUtf8("layertable"));

        verticalLayout_4->addWidget(layertable);

        layerlayout = new QHBoxLayout();
        layerlayout->setObjectName(QString::fromUtf8("layerlayout"));
        addlayer = new QPushButton(layertab);
        addlayer->setObjectName(QString::fromUtf8("addlayer"));

        layerlayout->addWidget(addlayer);

        editlayer = new QPushButton(layertab);
        editlayer->setObjectName(QString::fromUtf8("editlayer"));

        layerlayout->addWidget(editlayer);

        deletelayer = new QPushButton(layertab);
        deletelayer->setObjectName(QString::fromUtf8("deletelayer"));

        layerlayout->addWidget(deletelayer);

        exportlayer = new QPushButton(layertab);
        exportlayer->setObjectName(QString::fromUtf8("exportlayer"));

        layerlayout->addWidget(exportlayer);


        verticalLayout_4->addLayout(layerlayout);

        bottomtabs->addTab(layertab, QString());
        tab_playback = new QWidget();
        tab_playback->setObjectName(QString::fromUtf8("tab_playback"));
        bottomtabs->addTab(tab_playback, QString());
        objecttab = new QWidget();
        objecttab->setObjectName(QString::fromUtf8("objecttab"));
        verticalLayout_5 = new QVBoxLayout(objecttab);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        objectlabel = new QLabel(objecttab);
        objectlabel->setObjectName(QString::fromUtf8("objectlabel"));

        verticalLayout_5->addWidget(objectlabel);

        objectlayout = new QHBoxLayout();
        objectlayout->setObjectName(QString::fromUtf8("objectlayout"));
        objecttable = new QTableWidget(objecttab);
        objecttable->setObjectName(QString::fromUtf8("objecttable"));

        objectlayout->addWidget(objecttable);

        objectshaderholder = new QVBoxLayout();
        objectshaderholder->setObjectName(QString::fromUtf8("objectshaderholder"));
        objectpreview = new QOpenGLWidget(objecttab);
        objectpreview->setObjectName(QString::fromUtf8("objectpreview"));
        sizePolicy1.setHeightForWidth(objectpreview->sizePolicy().hasHeightForWidth());
        objectpreview->setSizePolicy(sizePolicy1);
        objectpreview->setMinimumSize(QSize(256, 256));
        objectpreview->setSizeIncrement(QSize(1, 1));

        objectshaderholder->addWidget(objectpreview);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(objecttab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        objecttexturepreviewcombo = new QComboBox(objecttab);
        objecttexturepreviewcombo->setObjectName(QString::fromUtf8("objecttexturepreviewcombo"));

        horizontalLayout_6->addWidget(objecttexturepreviewcombo);


        objectshaderholder->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(objecttab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        objectshadercombo = new QComboBox(objecttab);
        objectshadercombo->setObjectName(QString::fromUtf8("objectshadercombo"));

        horizontalLayout_5->addWidget(objectshadercombo);


        objectshaderholder->addLayout(horizontalLayout_5);


        objectlayout->addLayout(objectshaderholder);


        verticalLayout_5->addLayout(objectlayout);

        objectbuttons = new QHBoxLayout();
        objectbuttons->setObjectName(QString::fromUtf8("objectbuttons"));
        addobject = new QPushButton(objecttab);
        addobject->setObjectName(QString::fromUtf8("addobject"));

        objectbuttons->addWidget(addobject);

        deleteobject = new QPushButton(objecttab);
        deleteobject->setObjectName(QString::fromUtf8("deleteobject"));

        objectbuttons->addWidget(deleteobject);


        verticalLayout_5->addLayout(objectbuttons);

        bottomtabs->addTab(objecttab, QString());
        shaderstab = new QWidget();
        shaderstab->setObjectName(QString::fromUtf8("shaderstab"));
        verticalLayout_6 = new QVBoxLayout(shaderstab);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        shaderlabel = new QLabel(shaderstab);
        shaderlabel->setObjectName(QString::fromUtf8("shaderlabel"));

        verticalLayout_6->addWidget(shaderlabel);

        shadertable = new QTableWidget(shaderstab);
        if (shadertable->columnCount() < 3)
            shadertable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        shadertable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        shadertable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        shadertable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        shadertable->setObjectName(QString::fromUtf8("shadertable"));
        shadertable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        shadertable->horizontalHeader()->setCascadingSectionResizes(false);
        shadertable->horizontalHeader()->setDefaultSectionSize(200);
        shadertable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_6->addWidget(shadertable);

        objectbuttons_2 = new QHBoxLayout();
        objectbuttons_2->setObjectName(QString::fromUtf8("objectbuttons_2"));
        addshader = new QPushButton(shaderstab);
        addshader->setObjectName(QString::fromUtf8("addshader"));

        objectbuttons_2->addWidget(addshader);

        removeshader = new QPushButton(shaderstab);
        removeshader->setObjectName(QString::fromUtf8("removeshader"));

        objectbuttons_2->addWidget(removeshader);


        verticalLayout_6->addLayout(objectbuttons_2);

        bottomtabs->addTab(shaderstab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_2 = new QVBoxLayout(tab_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(tab_4);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        texturetable = new QTableWidget(tab_4);
        if (texturetable->columnCount() < 4)
            texturetable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        texturetable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        texturetable->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        texturetable->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        texturetable->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        texturetable->setObjectName(QString::fromUtf8("texturetable"));
        texturetable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        texturetable->setShowGrid(true);
        texturetable->setGridStyle(Qt::SolidLine);
        texturetable->setColumnCount(4);
        texturetable->horizontalHeader()->setVisible(true);
        texturetable->horizontalHeader()->setCascadingSectionResizes(false);
        texturetable->horizontalHeader()->setStretchLastSection(true);
        texturetable->verticalHeader()->setVisible(false);

        horizontalLayout_2->addWidget(texturetable);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        texturepreview = new TexturePreview(tab_4);
        texturepreview->setObjectName(QString::fromUtf8("texturepreview"));
        texturepreview->setMinimumSize(QSize(256, 256));
        texturepreview->setMaximumSize(QSize(256, 256));

        verticalLayout_3->addWidget(texturepreview);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        texturecombolabel = new QLabel(tab_4);
        texturecombolabel->setObjectName(QString::fromUtf8("texturecombolabel"));

        horizontalLayout_4->addWidget(texturecombolabel);

        texturecombo = new QComboBox(tab_4);
        texturecombo->setObjectName(QString::fromUtf8("texturecombo"));

        horizontalLayout_4->addWidget(texturecombo);


        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addtexture = new QPushButton(tab_4);
        addtexture->setObjectName(QString::fromUtf8("addtexture"));

        horizontalLayout->addWidget(addtexture);

        deletetexture = new QPushButton(tab_4);
        deletetexture->setObjectName(QString::fromUtf8("deletetexture"));

        horizontalLayout->addWidget(deletetexture);

        refreshtexture = new QPushButton(tab_4);
        refreshtexture->setObjectName(QString::fromUtf8("refreshtexture"));

        horizontalLayout->addWidget(refreshtexture);


        verticalLayout_2->addLayout(horizontalLayout);

        bottomtabs->addTab(tab_4, QString());

        lower->addWidget(bottomtabs);


        root->addLayout(lower);


        verticalLayout_7->addLayout(root);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1259, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSave_Background = new QMenu(menuFile);
        menuSave_Background->setObjectName(QString::fromUtf8("menuSave_Background"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew_Project);
        menuFile->addAction(actionLoad_Background);
        menuFile->addAction(menuSave_Background->menuAction());
        menuFile->addAction(actionClose_2);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuSave_Background->addAction(actionSave_XML);
        menuSave_Background->addAction(actionExport_KNBG);
        menuTools->addAction(actionModel_Converter);
        menuTools->addAction(actionDeltatime_Calculator);
        menuAbout->addAction(actionAbout);

        retranslateUi(MainWindow);

        toptabs->setCurrentIndex(2);
        bottomtabs->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew_Project->setText(QCoreApplication::translate("MainWindow", "New Background", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionLoad_Background->setText(QCoreApplication::translate("MainWindow", "Load Background", nullptr));
        actionSave_XML->setText(QCoreApplication::translate("MainWindow", "Save XML", nullptr));
        actionExport_KNBG->setText(QCoreApplication::translate("MainWindow", "Export KNBG", nullptr));
        actionClose_2->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        actionModel_Converter->setText(QCoreApplication::translate("MainWindow", "Model Converter", nullptr));
        actionDeltatime_Calculator->setText(QCoreApplication::translate("MainWindow", "Deltatime Calculator", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        animationadd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        animationdelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        animationup->setText(QCoreApplication::translate("MainWindow", "Move Up", nullptr));
        animationdown->setText(QCoreApplication::translate("MainWindow", "Move Down", nullptr));
        toptabs->setTabText(toptabs->indexOf(animationtab), QCoreApplication::translate("MainWindow", "Animation", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Add Property", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        toptabs->setTabText(toptabs->indexOf(optiontab), QCoreApplication::translate("MainWindow", "Layer Options", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Camera Position", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Camera Rotation", nullptr));
        toptabs->setTabText(toptabs->indexOf(debugcamera), QCoreApplication::translate("MainWindow", "Debug Camera", nullptr));
        layerlabel->setText(QCoreApplication::translate("MainWindow", "List of layers currently in background project. Please check your visibility settings before export, as the engine does NOT support BG visibility!", nullptr));
        addlayer->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        editlayer->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        deletelayer->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        exportlayer->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        bottomtabs->setTabText(bottomtabs->indexOf(layertab), QCoreApplication::translate("MainWindow", "Layers", nullptr));
        bottomtabs->setTabText(bottomtabs->indexOf(tab_playback), QCoreApplication::translate("MainWindow", "Playback", nullptr));
        objectlabel->setText(QCoreApplication::translate("MainWindow", "If you would like to use any models, they must be declared and decoded here. Uses KMF formatted models ONLY. Please use built-in tool to convert your model to KMF.", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Texture:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Shader:", nullptr));
        addobject->setText(QCoreApplication::translate("MainWindow", "Add Models", nullptr));
        deleteobject->setText(QCoreApplication::translate("MainWindow", "Delete Models", nullptr));
        bottomtabs->setTabText(bottomtabs->indexOf(objecttab), QCoreApplication::translate("MainWindow", "Models", nullptr));
        shaderlabel->setText(QCoreApplication::translate("MainWindow", "If you need to use any special shader slots, first open your current shader folder, and then add the new shader. DO NOT MAKE CHANGES TO THE SHADERS FOLDER IF INTENDING TO DISTRIBUTE!", nullptr));
        QTableWidgetItem *___qtablewidgetitem = shadertable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = shadertable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Vertex Path", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = shadertable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Fragment Path", nullptr));
        addshader->setText(QCoreApplication::translate("MainWindow", "Add Shader", nullptr));
        removeshader->setText(QCoreApplication::translate("MainWindow", "Remove Shader", nullptr));
        bottomtabs->setTabText(bottomtabs->indexOf(shaderstab), QCoreApplication::translate("MainWindow", "Shaders", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "If you're gonna need any textures, please declare them here. Standard file formats are supported.", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = texturetable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Texture ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = texturetable->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = texturetable->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Properties", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = texturetable->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Filepath", nullptr));
        texturecombolabel->setText(QCoreApplication::translate("MainWindow", "Background Texture", nullptr));
        addtexture->setText(QCoreApplication::translate("MainWindow", "Add Texture", nullptr));
        deletetexture->setText(QCoreApplication::translate("MainWindow", "Delete Texture", nullptr));
        refreshtexture->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        bottomtabs->setTabText(bottomtabs->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Textures", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuSave_Background->setTitle(QCoreApplication::translate("MainWindow", "Save Background", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
