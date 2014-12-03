/********************************************************************************
** Form generated from reading UI file 'qtproject.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTPROJECT_H
#define UI_QTPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTProjectClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTProjectClass)
    {
        if (QTProjectClass->objectName().isEmpty())
            QTProjectClass->setObjectName(QStringLiteral("QTProjectClass"));
        QTProjectClass->resize(600, 400);
        menuBar = new QMenuBar(QTProjectClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QTProjectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTProjectClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QTProjectClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QTProjectClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QTProjectClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QTProjectClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QTProjectClass->setStatusBar(statusBar);

        retranslateUi(QTProjectClass);

        QMetaObject::connectSlotsByName(QTProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *QTProjectClass)
    {
        QTProjectClass->setWindowTitle(QApplication::translate("QTProjectClass", "QTProject", 0));
    } // retranslateUi

};

namespace Ui {
    class QTProjectClass: public Ui_QTProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTPROJECT_H
