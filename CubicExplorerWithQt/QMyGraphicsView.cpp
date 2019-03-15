#include "QMyGraphicsView.h"

QMyGraphicsView::QMyGraphicsView(QWidget *parent)
	: QGraphicsView(parent)
{
}

QMyGraphicsView::~QMyGraphicsView()
{
}

void QMyGraphicsView::mousePressEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton) {	//���������������¼�
		QPoint point = event->pos();			//��ȡ����¼��������View����ϵ����
		rec_select.setX(point.x());				//����ѡȡ�����Ͻ�x������
		rec_select.setY(point.y());				//����ѡȡ�����Ͻ�y������
	}
	QGraphicsView::mousePressEvent(event);
}

void QMyGraphicsView::mouseReleaseEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {	//�����������ɿ��¼�
		QPoint point = event->pos();			//��ȡ����¼��������View����ϵ����
		int w = abs(point.x() - rec_select.x());		
		int h = abs(point.y() - rec_select.y());		
		if (point.x() < rec_select.x()) rec_select.setX(point.x());	//ȷ��ѡȡ�����Ͻ�x������
		if (point.y() < rec_select.y()) rec_select.setY(point.y());	//ȷ��ѡȡ�����Ͻ�y������
		rec_select.setWidth(w);					
		rec_select.setHeight(h);				

		emit mouseReleased(rec_select);
	}
	QGraphicsView::mouseReleaseEvent(event);
}

