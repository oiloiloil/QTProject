#ifndef QTPROJECT_H
#define QTPROJECT_H

#include <QtWidgets/QMainWindow>
#include "ui_qtproject.h"

class QTProject : public QMainWindow
{
	Q_OBJECT

public:
	QTProject(QWidget *parent = 0);
	~QTProject();

private:
	Ui::QTProjectClass ui;
};

#endif // QTPROJECT_H
