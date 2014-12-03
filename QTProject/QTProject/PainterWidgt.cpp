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

			painter.drawRect(x + 110 * j, y, w, h);
			painter.drawText(QPoint(x + 110 * j + 15, y + 15), text);

			j++;
		}
	}
}

void PainterWidgt::mousePressEvent(QMouseEvent *event) {
	QString msg;
	msg.sprintf("<center><h1>Press: (%d, %d)</h1></center>",
		event->x(), event->y());

	QMessageBox::information(NULL, "Information",
		"Your comment is: <b>" + msg + "</b>",
		QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	//this->setText(msg);
}

void PainterWidgt::checkNodeSelect()
{

}