#pragma once

#include <QWidget>
#include "ui_QtPreviewWidget.h"


class QtPreviewWidget : public QWidget
{
	Q_OBJECT

public:
	QtPreviewWidget(QWidget *parent = Q_NULLPTR);
	~QtPreviewWidget();

	void paintEvent(QPaintEvent *event);
	void drawPostText(bool bDraw,  const QColor& colorText, const QString& text);

private:
	Ui::QtPreviewWidget ui;
	bool m_bDrawText;
	QString m_strTextInfo;
	QColor  m_colorText;
	QString  m_strDate;
	QString  m_strTime;
};
