#include "QtPreviewWidget.h"
#include <QPainter>
#include <QDateTime>


QtPreviewWidget::QtPreviewWidget(QWidget *parent)
	: QWidget(parent)
	, m_bDrawText(false)
	, m_colorText(Qt::green)
{
	ui.setupUi(this);
	m_strTextInfo.clear();

	QDateTime current_date_time = QDateTime::currentDateTime();
	m_strDate = current_date_time.toString("yyyy-MM-dd");
	m_strTime = current_date_time.toString("hh:mm:ss");
}

QtPreviewWidget::~QtPreviewWidget()
{
}

void QtPreviewWidget::paintEvent(QPaintEvent *event)
{
	if (!m_bDrawText)
	{
		return;
	}

	Q_UNUSED(event); 
	
	QPainter painter(this); 
	// ���û�����ɫ 
	painter.setPen(m_colorText);

	QFont fontT("����",16,QFont::Bold, false);
	painter.setFont(fontT);
	// ��������Ϊ��ǰ�������������Ĭ��-���Ͻǿ�ʼ��
	painter.drawText(2, 50, m_strTextInfo);
}

void QtPreviewWidget::drawPostText(bool bDraw, const QColor& colorText, const QString& text)
{
	m_bDrawText = bDraw;
	m_colorText = colorText;
	m_strTextInfo = text;

	this->update();
}
