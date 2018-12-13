#pragma once

#include <QWidget>
#include "ui_QtCaptureWnd.h"

class QtCaptureWnd : public QWidget
{
	Q_OBJECT

public:
	QtCaptureWnd(QWidget *parent = Q_NULLPTR);
	~QtCaptureWnd();

private:
	void paintEvent(QPaintEvent *event);

private:
	Ui::QtCaptureWnd ui;
};
