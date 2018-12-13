#include "QtCaptureWnd.h"
#include <QPainter>

QtCaptureWnd::QtCaptureWnd(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(this->windowFlags() | Qt::Dialog | Qt::FramelessWindowHint | Qt::SubWindow | Qt::WindowStaysOnTopHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);
}

QtCaptureWnd::~QtCaptureWnd()
{
}

void QtCaptureWnd::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	//painter.fillRect(this->rect(), QColor(120, 120, 20));

	QPixmap bg;
	bg.load(":/DesktopTransfer/Resources/image/lt_cap.png");
	if (!bg.isNull())
	{
		QPoint ptLogo(0, 0);
		QApplication::style()->drawItemPixmap(&painter, QRect(ptLogo, bg.size()), Qt::AlignCenter, bg);
	}
	bg.load(":/DesktopTransfer/Resources/image/rt_cap.png");
	if (!bg.isNull())
	{
		QRect rc = this->geometry();
		QPoint ptLogo(rc.width() - bg.size().width(), 0);
		QApplication::style()->drawItemPixmap(&painter, QRect(ptLogo, bg.size()), Qt::AlignCenter, bg);
	}
	bg.load(":/DesktopTransfer/Resources/image/lb_cap.png");
	if (!bg.isNull())
	{
		QRect rc = this->geometry();
		QPoint ptLogo(0, rc.height() - bg.size().height());
		QApplication::style()->drawItemPixmap(&painter, QRect(ptLogo, bg.size()), Qt::AlignCenter, bg);
	}
	bg.load(":/DesktopTransfer/Resources/image/rb_cap.png");
	if (!bg.isNull())
	{
		QRect rc = this->geometry();
		QPoint ptLogo(rc.width() - bg.size().width(), rc.height() - bg.size().height());
		QApplication::style()->drawItemPixmap(&painter, QRect(ptLogo, bg.size()), Qt::AlignCenter, bg);
	}
}
