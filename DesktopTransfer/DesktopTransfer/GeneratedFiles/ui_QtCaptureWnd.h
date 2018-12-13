/********************************************************************************
** Form generated from reading UI file 'QtCaptureWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCAPTUREWND_H
#define UI_QTCAPTUREWND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtCaptureWnd
{
public:

    void setupUi(QWidget *QtCaptureWnd)
    {
        if (QtCaptureWnd->objectName().isEmpty())
            QtCaptureWnd->setObjectName(QStringLiteral("QtCaptureWnd"));
        QtCaptureWnd->resize(400, 300);
        QtCaptureWnd->setStyleSheet(QStringLiteral(""));

        retranslateUi(QtCaptureWnd);

        QMetaObject::connectSlotsByName(QtCaptureWnd);
    } // setupUi

    void retranslateUi(QWidget *QtCaptureWnd)
    {
        QtCaptureWnd->setWindowTitle(QApplication::translate("QtCaptureWnd", "QtCaptureWnd", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtCaptureWnd: public Ui_QtCaptureWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCAPTUREWND_H
