#include <iostream>
#include <string>
#include "PresentationModel.h"

using namespace std;

class TextView
{
private:
	PresentationModel presentationModel;
public:
	TextView();
	void chooseOperation();
	void display(string output);
	void menu();
	
};