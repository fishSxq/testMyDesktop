/********************************************************************************
** Form generated from reading UI file 'DesktopTransfer.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESKTOPTRANSFER_H
#define UI_DESKTOPTRANSFER_H

#include <QtCore/QVariant>
#include <QtPreviewWidget.h>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DesktopTransferClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widgetLeft;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelResolution;
    QComboBox *comBoxResolution;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelAudioType;
    QComboBox *comBoxAudioType;
    QSpacerItem *verticalSpacer_3;
    QtPreviewWidget *widgetPreview;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolBtnPreview;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolBtnStart;
    QLabel *label;
    QWidget *widgetRight;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelServerAddr;
    QLineEdit *lineServerAddr;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_6;
    QRadioButton *radioBtnDesktop;
    QSpacerItem *verticalSpacer_7;
    QRadioButton *radioBtnWindow;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *toolButtonSelWnd;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelSelWndTitle;
    QSpacerItem *verticalSpacer_8;
    QRadioButton *radioBtnPartDesktop;
    QLabel *labelWinArea;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelPublishUrl;
    QLineEdit *linePublishUrl;

    void setupUi(QMainWindow *DesktopTransferClass)
    {
        if (DesktopTransferClass->objectName().isEmpty())
            DesktopTransferClass->setObjectName(QStringLiteral("DesktopTransferClass"));
        DesktopTransferClass->resize(448, 290);
        DesktopTransferClass->setStyleSheet(QLatin1String("QWidget{\n"
"rgb(176, 204, 238);\n"
"}"));
        centralWidget = new QWidget(DesktopTransferClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("QWidget{\n"
"background-color:rgb(227,237,247);\n"
"}"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        widgetLeft = new QWidget(centralWidget);
        widgetLeft->setObjectName(QStringLiteral("widgetLeft"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetLeft->sizePolicy().hasHeightForWidth());
        widgetLeft->setSizePolicy(sizePolicy);
        widgetLeft->setMinimumSize(QSize(200, 0));
        verticalLayout = new QVBoxLayout(widgetLeft);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(4, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelResolution = new QLabel(widgetLeft);
        labelResolution->setObjectName(QStringLiteral("labelResolution"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelResolution->sizePolicy().hasHeightForWidth());
        labelResolution->setSizePolicy(sizePolicy1);
        labelResolution->setMinimumSize(QSize(55, 20));
        labelResolution->setMaximumSize(QSize(55, 16777215));

        horizontalLayout_2->addWidget(labelResolution);

        comBoxResolution = new QComboBox(widgetLeft);
        comBoxResolution->setObjectName(QStringLiteral("comBoxResolution"));
        comBoxResolution->setMinimumSize(QSize(0, 20));
        comBoxResolution->setMaximumSize(QSize(16777215, 20));
        comBoxResolution->setMaxVisibleItems(4);
        comBoxResolution->setMaxCount(4);

        horizontalLayout_2->addWidget(comBoxResolution);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelAudioType = new QLabel(widgetLeft);
        labelAudioType->setObjectName(QStringLiteral("labelAudioType"));
        sizePolicy1.setHeightForWidth(labelAudioType->sizePolicy().hasHeightForWidth());
        labelAudioType->setSizePolicy(sizePolicy1);
        labelAudioType->setMinimumSize(QSize(55, 20));
        labelAudioType->setMaximumSize(QSize(55, 16777215));

        horizontalLayout_3->addWidget(labelAudioType);

        comBoxAudioType = new QComboBox(widgetLeft);
        comBoxAudioType->setObjectName(QStringLiteral("comBoxAudioType"));
        comBoxAudioType->setMinimumSize(QSize(0, 20));
        comBoxAudioType->setMaximumSize(QSize(16777215, 20));
        comBoxAudioType->setMaxVisibleItems(4);
        comBoxAudioType->setMaxCount(4);

        horizontalLayout_3->addWidget(comBoxAudioType);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_3);

        widgetPreview = new QtPreviewWidget(widgetLeft);
        widgetPreview->setObjectName(QStringLiteral("widgetPreview"));
        sizePolicy.setHeightForWidth(widgetPreview->sizePolicy().hasHeightForWidth());
        widgetPreview->setSizePolicy(sizePolicy);
        widgetPreview->setMinimumSize(QSize(180, 0));
        widgetPreview->setStyleSheet(QLatin1String("QWidget#widgetPreview{\n"
"background-color:rgb(187, 195, 203);\n"
"}"));

        verticalLayout->addWidget(widgetPreview);

        verticalSpacer_4 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        toolBtnPreview = new QToolButton(widgetLeft);
        toolBtnPreview->setObjectName(QStringLiteral("toolBtnPreview"));
        toolBtnPreview->setMinimumSize(QSize(50, 22));
        toolBtnPreview->setMaximumSize(QSize(50, 22));

        horizontalLayout_4->addWidget(toolBtnPreview);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        toolBtnStart = new QToolButton(widgetLeft);
        toolBtnStart->setObjectName(QStringLiteral("toolBtnStart"));
        toolBtnStart->setMinimumSize(QSize(70, 22));
        toolBtnStart->setMaximumSize(QSize(70, 22));

        horizontalLayout_4->addWidget(toolBtnStart);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout->addWidget(widgetLeft);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(2, 0));
        label->setMaximumSize(QSize(2, 16777215));
        label->setStyleSheet(QStringLiteral("background-color: rgb(172,197,224);"));

        horizontalLayout->addWidget(label);

        widgetRight = new QWidget(centralWidget);
        widgetRight->setObjectName(QStringLiteral("widgetRight"));
        verticalLayout_2 = new QVBoxLayout(widgetRight);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_5 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelServerAddr = new QLabel(widgetRight);
        labelServerAddr->setObjectName(QStringLiteral("labelServerAddr"));

        horizontalLayout_7->addWidget(labelServerAddr);

        lineServerAddr = new QLineEdit(widgetRight);
        lineServerAddr->setObjectName(QStringLiteral("lineServerAddr"));

        horizontalLayout_7->addWidget(lineServerAddr);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_9);

        verticalSpacer_6 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_2->addItem(verticalSpacer_6);

        radioBtnDesktop = new QRadioButton(widgetRight);
        radioBtnDesktop->setObjectName(QStringLiteral("radioBtnDesktop"));

        verticalLayout_2->addWidget(radioBtnDesktop);

        verticalSpacer_7 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_7);

        radioBtnWindow = new QRadioButton(widgetRight);
        radioBtnWindow->setObjectName(QStringLiteral("radioBtnWindow"));

        verticalLayout_2->addWidget(radioBtnWindow);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        toolButtonSelWnd = new QToolButton(widgetRight);
        toolButtonSelWnd->setObjectName(QStringLiteral("toolButtonSelWnd"));
        toolButtonSelWnd->setMinimumSize(QSize(30, 30));
        toolButtonSelWnd->setMaximumSize(QSize(30, 30));
        toolButtonSelWnd->setFocusPolicy(Qt::TabFocus);
        toolButtonSelWnd->setStyleSheet(QStringLiteral(""));
        toolButtonSelWnd->setIconSize(QSize(30, 30));

        horizontalLayout_5->addWidget(toolButtonSelWnd);

        horizontalSpacer_2 = new QSpacerItem(8, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        labelSelWndTitle = new QLabel(widgetRight);
        labelSelWndTitle->setObjectName(QStringLiteral("labelSelWndTitle"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelSelWndTitle->sizePolicy().hasHeightForWidth());
        labelSelWndTitle->setSizePolicy(sizePolicy3);
        labelSelWndTitle->setMinimumSize(QSize(120, 30));
        labelSelWndTitle->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_5->addWidget(labelSelWndTitle);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalSpacer_8 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_8);

        radioBtnPartDesktop = new QRadioButton(widgetRight);
        radioBtnPartDesktop->setObjectName(QStringLiteral("radioBtnPartDesktop"));

        verticalLayout_2->addWidget(radioBtnPartDesktop);

        labelWinArea = new QLabel(widgetRight);
        labelWinArea->setObjectName(QStringLiteral("labelWinArea"));
        sizePolicy3.setHeightForWidth(labelWinArea->sizePolicy().hasHeightForWidth());
        labelWinArea->setSizePolicy(sizePolicy3);
        labelWinArea->setMinimumSize(QSize(120, 60));
        labelWinArea->setMaximumSize(QSize(16777212, 80));

        verticalLayout_2->addWidget(labelWinArea);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        labelPublishUrl = new QLabel(widgetRight);
        labelPublishUrl->setObjectName(QStringLiteral("labelPublishUrl"));

        horizontalLayout_8->addWidget(labelPublishUrl);

        linePublishUrl = new QLineEdit(widgetRight);
        linePublishUrl->setObjectName(QStringLiteral("linePublishUrl"));
        linePublishUrl->setReadOnly(true);

        horizontalLayout_8->addWidget(linePublishUrl);


        verticalLayout_2->addLayout(horizontalLayout_8);

        labelWinArea->raise();
        radioBtnDesktop->raise();
        radioBtnWindow->raise();
        radioBtnPartDesktop->raise();

        horizontalLayout->addWidget(widgetRight);

        DesktopTransferClass->setCentralWidget(centralWidget);

        retranslateUi(DesktopTransferClass);

        comBoxResolution->setCurrentIndex(-1);
        comBoxAudioType->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(DesktopTransferClass);
    } // setupUi

    void retranslateUi(QMainWindow *DesktopTransferClass)
    {
        DesktopTransferClass->setWindowTitle(QApplication::translate("DesktopTransferClass", "\346\241\214\351\235\242\345\210\206\344\272\253", nullptr));
        labelResolution->setText(QApplication::translate("DesktopTransferClass", "\345\210\206\350\276\250\347\216\207:", nullptr));
        labelAudioType->setText(QApplication::translate("DesktopTransferClass", "\351\237\263\351\242\221\346\240\274\345\274\217:", nullptr));
        toolBtnPreview->setText(QApplication::translate("DesktopTransferClass", "\351\242\204\350\247\210", nullptr));
        toolBtnStart->setText(QApplication::translate("DesktopTransferClass", "\344\277\235\345\255\230\345\271\266\345\220\257\345\212\250", nullptr));
        label->setText(QString());
        labelServerAddr->setText(QApplication::translate("DesktopTransferClass", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        radioBtnDesktop->setText(QApplication::translate("DesktopTransferClass", "\345\205\250\346\241\214\351\235\242\351\207\207\351\233\206", nullptr));
        radioBtnWindow->setText(QApplication::translate("DesktopTransferClass", "\346\214\207\345\256\232\347\252\227\345\217\243\351\207\207\351\233\206", nullptr));
        toolButtonSelWnd->setText(QString());
        labelSelWndTitle->setText(QString());
        radioBtnPartDesktop->setText(QApplication::translate("DesktopTransferClass", "\346\214\207\345\256\232\350\214\203\345\233\264\351\207\207\351\233\206", nullptr));
        labelWinArea->setText(QApplication::translate("DesktopTransferClass", "x:0<br/>y:0<br/>w:0<br/>h:0<br>", nullptr));
        labelPublishUrl->setText(QApplication::translate("DesktopTransferClass", "\345\217\221\345\270\203url:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DesktopTransferClass: public Ui_DesktopTransferClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESKTOPTRANSFER_H
