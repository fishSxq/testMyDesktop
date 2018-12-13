#include "QtPartDesktop.h"
#include <QPainter>
#include <QDesktopWidget>

#pragma execution_character_set("utf-8")
const int resizeBorderWidth = 5;

QtPartDesktop::QtPartDesktop(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(this->windowFlags() | Qt::Dialog | Qt::FramelessWindowHint | Qt::SubWindow | Qt::WindowStaysOnTopHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);
}

QtPartDesktop::~QtPartDesktop()
{
}

QRect QtPartDesktop::GetCaptureArea()
{
	QRect rc = this->geometry();
	QRect capRc;
	capRc.setX(rc.x() + 4);
	capRc.setY(rc.y() + 20);
	capRc.setWidth(rc.width() - 8);
	capRc.setHeight(rc.height() - 24);
	return capRc;
}

void QtPartDesktop::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	//painter.fillRect(this->rect(), QColor(120, 120, 20));
	// 反走样 
	painter.setRenderHint(QPainter::Antialiasing, true);
	// 设置画笔颜色、宽度
	painter.setPen(QPen(QColor(194, 195, 201), 4));
	painter.drawRect(0, 0, this->width(), this->height());

	painter.setPen(QPen(QColor(206, 220, 233), 4));
	painter.setBrush(QColor(206, 220, 233));
	painter.drawRect(0, 0, this->width(), 20);

	painter.setPen(QPen(Qt::black , 2));
	QFont fontT("宋体", 10, QFont::Bold, false);
	painter.setFont(fontT);
	painter.drawText(4,16, "采集区域");

}

void QtPartDesktop::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) 
	{
		this->m_drag = true;
		this->dragPos = event->pos();
		this->resizeDownPos = event->globalPos();
		this->mouseDownRect = this->rect();
	}
}

void QtPartDesktop::mouseMoveEvent(QMouseEvent * event)
{
	if (resizeRegion != Default)
	{
		handleResize();
		return;
	}

	if (m_move) 
	{
		move(event->globalPos() - dragPos);
		return;
	}

	QPoint clientCursorPos = event->pos();
	QRect r = this->rect();
	QRect resizeInnerRect(resizeBorderWidth, resizeBorderWidth, r.width() - 2 * resizeBorderWidth, r.height() - 2 * resizeBorderWidth);
	if (r.contains(clientCursorPos) && !resizeInnerRect.contains(clientCursorPos)) 
	{ 
		//调整窗体大小
		ResizeRegion resizeReg = getResizeRegion(clientCursorPos);
		setResizeCursor(resizeReg);
		if (m_drag && (event->buttons() & Qt::LeftButton)) 
		{
			resizeRegion = resizeReg;
			handleResize();
		}
	}
	else { //移动窗体
		setCursor(Qt::ArrowCursor);
		if (m_drag && (event->buttons() & Qt::LeftButton)) 
		{
			m_move = true;
			move(event->globalPos() - dragPos);
		}
	}
}

void QtPartDesktop::mouseReleaseEvent(QMouseEvent *event)
{
	m_drag = false;
	if (m_move) 
	{
		m_move = false;
		handleMove(event->globalPos()); //鼠标放开后若超出屏幕区域自动吸附于屏幕顶部/左侧/右侧
	}
	resizeRegion = Default;
	setCursor(Qt::ArrowCursor);
}

void QtPartDesktop::setResizeCursor(ResizeRegion region)
{
	switch (region)
	{
	case North:
	case South:
		setCursor(Qt::SizeVerCursor);
		break;
	case East:
	case West:
		setCursor(Qt::SizeHorCursor);
		break;
	case NorthWest:
	case SouthEast:
		setCursor(Qt::SizeFDiagCursor);
		break;
	default:
		setCursor(Qt::SizeBDiagCursor);
		break;
	}
}

ResizeRegion QtPartDesktop::getResizeRegion(QPoint clientPos)
{
	if (clientPos.y() <= resizeBorderWidth) 
	{
		if (clientPos.x() <= resizeBorderWidth)
			return NorthWest;
		else if (clientPos.x() >= this->width() - resizeBorderWidth)
			return NorthEast;
		else
			return North;
	}
	else if (clientPos.y() >= this->height() - resizeBorderWidth) {
		if (clientPos.x() <= resizeBorderWidth)
			return SouthWest;
		else if (clientPos.x() >= this->width() - resizeBorderWidth)
			return SouthEast;
		else
			return South;
	}
	else {
		if (clientPos.x() <= resizeBorderWidth)
			return West;
		else
			return East;
	}
}

void QtPartDesktop::handleMove(QPoint pt)
{
	QDesktopWidget *  desktop = QApplication::desktop();
	QPoint currentPos = pt - dragPos;
	if (currentPos.x() < desktop->x()) { //吸附于屏幕左侧
		currentPos.setX(desktop->x());
	}
	else if (currentPos.x() + this->width() > desktop->width()) { //吸附于屏幕右侧
		currentPos.setX(desktop->width() - this->width());
	}
	if (currentPos.y() < desktop->y()) { //吸附于屏幕顶部
		currentPos.setY(desktop->y());
	}
	move(currentPos);
}

void QtPartDesktop::handleResize()
{
	int xdiff = QCursor::pos().x() - resizeDownPos.x();
	int ydiff = QCursor::pos().y() - resizeDownPos.y();
	switch (resizeRegion)
	{
	case East:
	{
		resize(mouseDownRect.width() + xdiff, this->height());
		break;
	}
	case West:
	{
		resize(mouseDownRect.width() - xdiff, this->height());
		move(resizeDownPos.x() + xdiff, this->y());
		break;
	}
	case South:
	{
		resize(this->width(), mouseDownRect.height() + ydiff);
		break;
	}
	case North:
	{
		resize(this->width(), mouseDownRect.height() - ydiff);
		move(this->x(), resizeDownPos.y() + ydiff);
		break;
	}
	case SouthEast:
	{
		resize(mouseDownRect.width() + xdiff, mouseDownRect.height() + ydiff);
		break;
	}
	case NorthEast:
	{
		resize(mouseDownRect.width() + xdiff, mouseDownRect.height() - ydiff);
		move(this->x(), resizeDownPos.y() + ydiff);
		break;
	}
	case NorthWest:
	{
		resize(mouseDownRect.width() - xdiff, mouseDownRect.height() - ydiff);
		move(resizeDownPos.x() + xdiff, resizeDownPos.y() + ydiff);
		break;
	}
	case SouthWest:
	{
		resize(mouseDownRect.width() - xdiff, mouseDownRect.height() + ydiff);
		move(resizeDownPos.x() + xdiff, this->y());
		break;
	}
	}
}