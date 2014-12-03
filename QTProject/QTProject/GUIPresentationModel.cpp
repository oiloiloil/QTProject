#include <iostream>
#include "GUIPresentationModel.h"

using namespace std;

void GUIPresentationModel::init(PainterWidgt *painterWidgt)
{
	this->painterWidgt = painterWidgt;
}

void GUIPresentationModel::showMessage()
{
	bool isOK;

	QString text = QInputDialog::getText(NULL, "Input Dialog",
		"Please input your comment",
		QLineEdit::Normal, "your comment", &isOK);

	if (isOK) {
		QMessageBox::information(NULL, "Information",
			"Your comment is: <b>" + text + "</b>",
			QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}

}

void GUIPresentationModel::getCreateMindMap()
{
	bool isOK;
	QString text = QInputDialog::getText(NULL, "Input Dialog",
		"Please input your description",
		QLineEdit::Normal, "your comment", &isOK);

	string description = text.toStdString();

	if (isOK) {
		QMessageBox::information(NULL, "Information",
			"Your description is: <b>" + text + "</b>",
			QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}
	mapModel.createMinMap(description);

	painterWidgt->getModel(mapModel);
	painterWidgt->rootExist(true);

}

void GUIPresentationModel::openFile()
{
	try
	{
		bool isOK;
		QString text = QFileDialog::getOpenFileName(NULL, "Open Image",
			"C:\\");

		string path = text.toStdString();

		if (isOK) {
			QMessageBox::information(NULL, "Information",
				"Your path is: <b>" + text + "</b>",
				QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		}

		if (path != "")
		{
			mapModel.readFile(path);

			painterWidgt->getModel(mapModel);
			painterWidgt->rootExist(true);
		}
		else 
			throw path;
	}
	catch (string err)
	{
		QMessageBox::warning(NULL, "Warning",
			"No open file",
			QMessageBox::Yes, QMessageBox::Yes);
	}
	
}

void GUIPresentationModel::saveFile()
{
	mapModel.saveMindMap();
}

void GUIPresentationModel::editNode()
{

}

void GUIPresentationModel::insertNode()
{

}
