#pragma once
#include <QObject>
#include <QWidget>
#include <QInputDialog>
#include <QTextEdit>
#include <QMessageBox>
#include <QPainter>
#include "MindMapModel.h"
#include "GUIView.h"
#include "PainterWidgt.h"

class GUIPresentationModel : public QObject {
	Q_OBJECT;
private:
	MindMapModel mapModel;
	PainterWidgt *painterWidgt;
public:
	void init(PainterWidgt *painterWidgt);
public slots :
		void showMessage();
	void getCreateMindMap();
		void openFile();
		void saveFile();
		void editNode();
		void insertNode();
signals:
		void sendMessage(QString);

};

