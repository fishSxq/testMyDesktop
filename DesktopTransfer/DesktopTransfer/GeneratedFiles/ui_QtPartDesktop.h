/********************************************************************************
** Form generated from reading UI file 'QtPartDesktop.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTPARTDESKTOP_H
#define UI_QTPARTDESKTOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtPartDesktop
{
public:
    QWidget *widget;

    void setupUi(QWidget *QtPartDesktop)
    {
        if (QtPartDesktop->objectName().isEmpty())
            QtPartDesktop->setObjectName(QStringLiteral("QtPartDesktop"));
        QtPartDesktop->resize(400, 300);
        widget = new QWidget(QtPartDesktop);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 401, 291));
        widget->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 224, 0);"));

        retranslateUi(QtPartDesktop);

        QMetaObject::connectSlotsByName(QtPartDesktop);
    } // setupUi

    void retranslateUi(QWidget *QtPartDesktop)
    {
        QtPartDesktop->setWindowTitle(QApplication::translate("QtPartDesktop", "QtPartDesktop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtPartDesktop: public Ui_QtPartDesktop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTPARTDESKTOP_H
