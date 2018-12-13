/********************************************************************************
** Form generated from reading UI file 'QtPreviewWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTPREVIEWWIDGET_H
#define UI_QTPREVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtPreviewWidget
{
public:

    void setupUi(QWidget *QtPreviewWidget)
    {
        if (QtPreviewWidget->objectName().isEmpty())
            QtPreviewWidget->setObjectName(QStringLiteral("QtPreviewWidget"));
        QtPreviewWidget->resize(477, 396);
        QtPreviewWidget->setStyleSheet(QLatin1String("QWidget{\n"
"background-color:rgb(227,237,247);\n"
"}"));

        retranslateUi(QtPreviewWidget);

        QMetaObject::connectSlotsByName(QtPreviewWidget);
    } // setupUi

    void retranslateUi(QWidget *QtPreviewWidget)
    {
        QtPreviewWidget->setWindowTitle(QApplication::translate("QtPreviewWidget", "QtPreviewWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtPreviewWidget: public Ui_QtPreviewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTPREVIEWWIDGET_H
