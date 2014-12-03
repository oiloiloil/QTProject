#include "SetTestData.h"

using namespace std;

void SetTestData::init()
{
	data = "0 \"Computer\" 2 7\n" 
		"1 \"windows\" 5 6\n"  
		"2 \"OS\" 1 3 4\n"
		"3 \"IOS\"\n"
		"4 \"Linux\"\n"
		"5 \"DirectX\"\n"
		"6 \"Microsoft Office\"\n"
		"7 \"Network\" 8 9\n"
		"8 \"Wireless\"\n"
		"9 \"Cable\"\n";
}

string SetTestData::getData()
{
	init();
	return data;
}