#include <iostream>
#include "GUIView.h"
#include "TextView.h"

using namespace std;


int main(int argc, char *argv[]) {
	int number;
	
	cout << "Choose a UI to do" << endl;
	cout << "1. TextUI" << endl;
	cout << "2. GUI" << endl;
	cout << ">";

	cin >> number;

	if (number == 1)
		TextView *textview = new TextView();
	else if (number == 2)
		GUIView *gui = new GUIView(argc, argv);

	system("pause");

	
}