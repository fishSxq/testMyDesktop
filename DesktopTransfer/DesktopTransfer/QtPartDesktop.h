#pragma once

#include <QWidget>
#include "ui_QtPartDesktop.h"
#include <QMouseEvent>

enum ResizeRegion
{
	Default,
	North,
	NorthEast,
	East,
	SouthEast,
	South,
	SouthWest,
	West,
	NorthWest
};

class QtPartDesktop : public QWidget
{
	Q_OBJECT

public:
	QtPartDesktop(QWidget *parent = Q_NULLPTR);
	~QtPartDesktop();
	QRect GetCaptureArea();

private:
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent * event);
	void mouseReleaseEvent(QMouseEvent *event);
	void setResizeCursor(ResizeRegion region);
	ResizeRegion getResizeRegion(QPoint clientPos);
	void handleMove(QPoint pt);
	void handleResize();

private:
	Ui::QtPartDesktop ui;

	bool m_drag;
	bool m_move;
	QPoint dragPos;
	QPoint resizeDownPos;
	ResizeRegion resizeRegion;
	QRect mouseDownRect;
};
