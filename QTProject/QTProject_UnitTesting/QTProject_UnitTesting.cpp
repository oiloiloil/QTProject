// QTProject_UnitTesting.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <gtest\gtest.h>


int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}

