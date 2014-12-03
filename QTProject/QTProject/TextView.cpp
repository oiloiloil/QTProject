#include "TextView.h"

using namespace std;

TextView::TextView()
{
	chooseOperation();
}

void TextView::chooseOperation()
{
	int number;
	do
	{
		menu();
		presentationModel.menuInput(number);
		presentationModel.didUserSelect(number);
	} while (!presentationModel.endedInput(number));
}

void TextView::display(string output)
{
	cout << output << endl;
}

void TextView::menu()
{
	cout << "Please enter your choice:" << endl;
	cout << "1.Create a new mind map" << endl;
	cout << "2.Insert a new node" << endl;
	cout << "3.Edit a node" << endl;
	cout << "4.Display mind map" << endl;
	cout << "5.Save mind map" << endl;
	cout << "6.Load a mind map" << endl;
	cout << "7.Redo" << endl;
	cout << "8.Undo" << endl;
	cout << "9.Exit" << endl;
	cout << ">";
}

/*
void TextView::createMindMapView()
{
	cout << "Enter the node name:" << endl;
	cout << ">";
}

void TextView::insertNodeIDView()
{
	cout << "Enter the node ID:" << endl;//Enter the node ID you want to do operation
	cout << ">";
}

void TextView::insertNodeView()
{
	cout << "a.Insert a parent node" << endl;
	cout << "b.Insert a child node" << endl;
	cout << "c.Insert a sibling node" << endl;
	cout << ">";
}

void TextView::showEditMenu()
{
	cout << "a.Edit the description of a node" << endl;
	cout << "b.Change the parent of a node" << endl;
	cout << "c.Delete a node" << endl;
	cout << ">";
}

void TextView::inputDescription()
{
	cout << "Enter the node name" << endl;
	cout << ">";
}

void TextView::commandError()
{
	cout << "The command is not found" << endl;
}
*/