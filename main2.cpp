///	\file main.cpp
/// \brief main function in order to call and test all the algorithms.
///	\details

//#define _FILE_DEBUG_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include "../test/AllTest.h"
#include "gtest/gtest.h"
using namespace std;

/// \fn int main(int argc, char *argv[])
/// \brief main function in order to call and test all the algorithms.
/// \details
/// \param[in] argc
/// \param[in] argv
/// \return what RUN_ALL_TESTS() returns.
/// \bug

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("../input.txt");
	cin.rdbuf(fin.rdbuf());
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("../output.txt");
	cout.rdbuf(fout.rdbuf());
#endif

	testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    std::getchar();

	return ret;
}