#pragma once
#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <list>
#include "Component.h"
#include "MindMapModel.h"

class PainterWidgt : public QWidget
{
private:
	QString text;
	MindMapModel mapModel;
	bool isRootExist = false;
	int selectedNode = -1;
public:
	void getDescription(QString text);
	void getModel(MindMapModel mapModel);
	QString s2q(const string &s);
	void rootExist(bool input);
	void checkNodeSelect(int x, int y);
	void setNodeCoordinate(Component *node, int x, int &y);
	int getSelectedNode();
protected:
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
public slots :

signals :

};