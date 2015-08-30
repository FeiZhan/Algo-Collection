//
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <string>
#include <map>
struct student
{
	std::string name, id;
};

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("../input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("../input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("../output.txt");
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	int stu_num;
	cin >> stu_num;
	int tmp1;
	std::string tmp2, tmp3, tmp4;
	std::map<int, student> m_map, f_map;
	for (int i = 0; i < stu_num; ++ i)
	{
		cin >> tmp2 >> tmp3 >> tmp4 >> tmp1;
		student s;
		s.name = tmp2;
		s.id = tmp4;
		if ("M" == tmp3)
		{
			m_map.insert(std::make_pair(tmp1, s));
		} else
		{
			f_map.insert(std::make_pair(tmp1, s));
		}
	}
	int diff = 0;
	if (f_map.size())
	{
		diff = f_map.rbegin()->first;
		std::cout << f_map.rbegin()->second.name << " " << f_map.rbegin()->second.id << std::endl;
	} else
	{
		std::cout << "Absent" << std::endl;
	}
	if (m_map.size())
	{
		diff -= m_map.begin()->first;
		std::cout << m_map.begin()->second.name << " " << m_map.begin()->second.id << std::endl;
	} else
	{
		std::cout << "Absent" << std::endl;
	}
	if (0 == f_map.size() || 0 == m_map.size())
	{
		std::cout << "NA" << std::endl;
	} else
	{
		std::cout << diff << std::endl;
	}

	return 0;
}
