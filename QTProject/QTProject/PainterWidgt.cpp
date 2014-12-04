#include <PainterWidgt.h>

QString PainterWidgt::s2q(const string &s)
{
	return QString(QString::fromLocal8Bit(s.c_str()));
}

void PainterWidgt::rootExist(bool input)
{
	isRootExist = input;
}

void PainterWidgt::getDescription(QString text)
{
	this->text = text;
}

void PainterWidgt::getModel(MindMapModel mapModel)
{
	this->mapModel = mapModel;
}

void PainterWidgt::paintEvent(QPaintEvent *event)
{
	Component *temp;
	list <Component *> tempList;
	list <Component *> resultList;
	list <Component *>::iterator i;
	int x = 50, y = 50, w = 80, h = 40, j = 0;

	if (isRootExist)
	{
		QPainter painter(this);

		temp = mapModel.returnRoot();
		tempList = temp->getNodeList();
		resultList.push_back(temp);
		mapModel.getNodeList(tempList, resultList);

		for (i = resultList.begin(); i != resultList.end(); ++i)
		{
			temp = *i;

			text = s2q(temp->getDescription());

			if (temp->isSelected())
				painter.setPen(QPen(Qt::red, 5));
			else
				painter.setPen(QPen(Qt::black, 4));


			painter.drawRect(temp->getX(), temp->getY(), w, h);
			painter.drawText(QPoint(temp->getX() + 15, temp->getY() + 15), text);

		}
	}
}

void PainterWidgt::mousePressEvent(QMouseEvent *event) {
	QString msg;
	msg.sprintf("<center><h1>Press: (%d, %d)</h1></center>",
		event->x(), event->y());
	checkNodeSelect(event->x(), event->y());

	QMessageBox::information(NULL, "Information",
		"Your nodeID is: <b>" + msg + "</b>",
		QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	//this->setText(msg);
	cout << selectedNode << endl;
}

void PainterWidgt::checkNodeSelect(int x, int y)
{
	Component *temp;
	list <Component *> tempList;
	list <Component *> resultList;
	list <Component *>::iterator i;
	int nodeX = 0, nodeY = 0;
	if (isRootExist)
	{
		temp = mapModel.returnRoot();
		tempList = temp->getNodeList();
		resultList.push_back(temp);
		mapModel.getNodeList(tempList, resultList);

		//setSelected reset false
		for (i = resultList.begin(); i != resultList.end(); ++i)
		{
			temp = *i;
			temp->setSelected(false);
		}

		for (i = resultList.begin(); i != resultList.end(); ++i)
		{
			temp = *i;
			nodeX = temp->getX();
			nodeY = temp->getY();
			if (x >= nodeX && y >= nodeY && x <= (nodeX + 80) && y <= (nodeY + 40))
			{
				temp->setSelected(true);
				selectedNode = temp->getID();
				break;
			}
			else
				selectedNode = -1;
		}
	}
}

//遞迴給每個node加上X Y值
void PainterWidgt::setNodeCoordinate(Component *node, int x, int &y)
{
	Component *temp;
	list <Component *> tempList;
	list <Component *>::iterator i;

	node->setCoordinate(x, y);
	tempList = node->getNodeList();
	for (i = tempList.begin(); i != tempList.end(); ++i)
	{
		temp = *i;
		setNodeCoordinate(temp, x + 110, y);

		y = y + 70;
	}
}

int PainterWidgt::getSelectedNode()
{
	return selectedNode;
}