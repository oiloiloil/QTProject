#pragma once
#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QDockWidget>
#include <QMessageBox>  
#include <QLabel>
#include <QPixmap>
#include <QFile> 
#include <QFileDialog>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>
#include <QString>
#include <string>
#include "GUIPresentationModel.h"
#include "PainterWidgt.h"

class GUIView : public QObject
{
	Q_OBJECT;
private:
	
public:
	PainterWidgt *painterWidgt;
	GUIView();
	GUIView(int argc, char *argv[]);
public slots :

signals:
	
};