// TLE because of cin
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
#include <vector>
#include <algorithm>
struct Student
{
	std::string id, name;
	int score;
	Student(const std::string &i, const std::string &n, const int s)
	: id(i), name(n), score(s)
	{}
};
// if C = 1 then the records must be sorted in increasing order according to ID's;
bool compare1(const Student &s0, const Student &s1)
{
	return s0.id < s1.id;
}
// if C = 2 then the records must be sorted in non-decreasing order according to names;
bool compare2(const Student &s0, const Student &s1)
{
	return s0.name < s1.name || (s0.name == s1.name && s0.id < s1.id);
}
// if C = 3 then the records must be sorted in non-decreasing order according to grades.
// If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.
bool compare3(const Student &s0, const Student &s1)
{
	return s0.score < s1.score || (s0.score == s1.score && s0.id < s1.id);
}

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

	int stu_num, sort_num, score;
	std::cin >> stu_num >> sort_num;
	std::string id, name;
	std::vector<Student> stu_list;
	for (int i = 0; i < stu_num; ++ i)
	{
		std::cin >> id >> name >> score;
		Student stu(id, name, score);
		stu_list.push_back(stu);
	}
	switch (sort_num)
	{
	case 1:
		std::sort(stu_list.begin(), stu_list.end(), compare1);
		break;
	case 2:
		std::sort(stu_list.begin(), stu_list.end(), compare2);
		break;
	case 3:
		std::sort(stu_list.begin(), stu_list.end(), compare3);
		break;
	default:
		std::sort(stu_list.begin(), stu_list.end(), compare1);
	}
	for (size_t i = 0; i < stu_list.size(); ++ i)
	{
		std::cout << stu_list[i].id << " " << stu_list[i].name << " " << stu_list[i].score << std::endl;
	}
	return 0;
}
