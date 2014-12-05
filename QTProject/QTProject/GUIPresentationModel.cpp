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
	bool isOK = false;
	int y = 50;
	QString text = QInputDialog::getText(NULL, "Input Dialog",
		"Please input your root description",
		QLineEdit::Normal, "your comment", &isOK);

	string description = text.toStdString();

	if (isOK) {
		QMessageBox::information(NULL, "Information",
			"Your description is: <b>" + text + "</b>",
			QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}
	mapModel.createMinMap(description);
	painterWidgt->setNodeCoordinate(mapModel.returnRoot(), 50, y);

	painterWidgt->getModel(mapModel);
	painterWidgt->rootExist(true);

}

void GUIPresentationModel::openFile()
{
	int y = 50;
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
			painterWidgt->setNodeCoordinate(mapModel.returnRoot(), 50, y);
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
	QString text = QInputDialog::getText(NULL, "Input Dialog",
		"Please input your root description",
		QLineEdit::Normal, "your comment");

	string description = text.toStdString();
	int selectedNode = painterWidgt->getSelectedNode();

	if (selectedNode != -1)
		mapModel.editNodeDescription(selectedNode, description);
	else
		QMessageBox::warning(NULL, "Warning",
		QString::fromLocal8Bit("沒有選取node"),
		QMessageBox::Yes, QMessageBox::Yes);
}

void GUIPresentationModel::deleteNode()
{
	int y = 50;
	int selectedNode = painterWidgt->getSelectedNode();
	if (selectedNode != -1)
	{
		mapModel.editDeleteNode(selectedNode);
		painterWidgt->getModel(mapModel);
		painterWidgt->setNodeCoordinate(mapModel.returnRoot(), 50, y);
		painterWidgt->update();
	}
	else
		QMessageBox::warning(NULL, "Warning",
		QString::fromLocal8Bit("沒有選取node"),
		QMessageBox::Yes, QMessageBox::Yes);
}

void GUIPresentationModel::insertParentNode()
{
	int y = 50;
	int selectedNode = painterWidgt->getSelectedNode();
	if (selectedNode != -1)
	{
		QString text = QInputDialog::getText(NULL, "Input Dialog",
			"Please input your root description",
			QLineEdit::Normal, "your comment");

		string description = text.toStdString();

		mapModel.insertParentNode(selectedNode, mapModel.getGreatID() + 1, description);
		painterWidgt->getModel(mapModel);
		painterWidgt->setNodeCoordinate(mapModel.returnRoot(), 50, y);
		painterWidgt->update();
	}
	else
		QMessageBox::warning(NULL, "Warning",
		QString::fromLocal8Bit("沒有選取node"),
		QMessageBox::Yes, QMessageBox::Yes);
}

void GUIPresentationModel::insertChildNode()
{
	int y = 50;
	int selectedNode = painterWidgt->getSelectedNode();
	if (selectedNode != -1)
	{
		QString text = QInputDialog::getText(NULL, "Input Dialog",
			"Please input your root description",
			QLineEdit::Normal, "your comment");

		string description = text.toStdString();

		mapModel.insertChildNode(selectedNode, mapModel.getGreatID() + 1, description);
		painterWidgt->getModel(mapModel);
		painterWidgt->setNodeCoordinate(mapModel.returnRoot(), 50, y);
		painterWidgt->update();
	}
	else
		QMessageBox::warning(NULL, "Warning",
		QString::fromLocal8Bit("沒有選取node"),
		QMessageBox::Yes, QMessageBox::Yes);
}

void GUIPresentationModel::insertSiblingNode()
{
	int y = 50;
	int selectedNode = painterWidgt->getSelectedNode();
	if (selectedNode != -1)
	{
		QString text = QInputDialog::getText(NULL, "Input Dialog",
			"Please input your root description",
			QLineEdit::Normal, "your comment");

		string description = text.toStdString();

		mapModel.insertSiblingNode(selectedNode, mapModel.getGreatID() + 1, description);
		painterWidgt->getModel(mapModel);
		painterWidgt->setNodeCoordinate(mapModel.returnRoot(), 50, y);
		//painterWidgt->update();
	}
	else
		QMessageBox::warning(NULL, "Warning",
		QString::fromLocal8Bit("沒有選取node"),
		QMessageBox::Yes, QMessageBox::Yes);
}

void GUIPresentationModel::showAboutMessage()
{
	QMessageBox::about(NULL, "about", 
		QString::fromLocal8Bit("ID = 103598031 \n name = 歐陽騰 \n course name = 資工碩一 \n application name = MindMap \n Version = ?"));
}

void GUIPresentationModel::cutAction()
{

}

void GUIPresentationModel::copyAction()
{
	int selectedNode = painterWidgt->getSelectedNode();
	if (selectedNode != -1)
	{
		mapModel.copyNode(selectedNode);
	}
	else
		QMessageBox::warning(NULL, "Warning",
		QString::fromLocal8Bit("沒有選取node"),
		QMessageBox::Yes, QMessageBox::Yes);
	
}

void GUIPresentationModel::pasteAction()
{
	int y = 50;
	int selectedNode = painterWidgt->getSelectedNode();
	if (selectedNode != -1)
	{
		mapModel.pasteNode(selectedNode);
		painterWidgt->getModel(mapModel);
		painterWidgt->setNodeCoordinate(mapModel.returnRoot(), 50, y);
		painterWidgt->update();
	}
	else
		QMessageBox::warning(NULL, "Warning",
		QString::fromLocal8Bit("沒有選取node"),
		QMessageBox::Yes, QMessageBox::Yes);
}
