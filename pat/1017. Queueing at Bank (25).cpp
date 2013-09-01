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
#include <vector>
#include <map>

typedef struct Time
{
	Time() : hour(0), minute(0), second(-1) {}
	Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
	int hour, minute, second;
	bool operator> (Time t2)
	{
		return (this.hour > t2.hour) || (this.hour == t2.hour && ) || (this.hour == t2.hour)
	}
} STime;
class compare_1
{ // simple comparison function
public:
	bool operator() (const STime x,const STime y)
	{
		return (x.hour > y.hour) || (x.hour == y.hour && x.minute > y.minute) || (x.hour == y.hour && x.minute == y.minute && x.second > y.second);
	} // returns x>y
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

	int customers, windows;
	cin >> customers >> windows;
	std::vector<int> hours, minutes, seconds, proc_times;
	std::map<STime, int, compare_1> proc;
	for (int i = 0; i < customers; ++ i)
	{
		char tmp1;
		int hour, minute, second, tmp2;
		cin >> hour >> tmp1 >> minute >> tmp1 >> second >> tmp2;
		if ( hour < 17 || (hour == 17 && minute == 0 && second == 0) )
		{
			proc.insert(std::make_pair(STime(hour, minute, second), tmp2));
		}
	}
	std::vector<std::map<STime, int, compare_1>::iterator> win_it;
	STime now(0, 0, 0);
	int wait = 0;
	for (std::map<STime, int, compare_1>::iterator it = proc.begin(); it != proc.end(); ++ it)
	{
		int min_proc;
		
		for (int i = 0; i < win_it.size(); ++ i)
		{
			
		}
		while (windows > win_it.size() && it != proc.end())
		{
			win_it.push_back(it);
			++ it;
		}
	}

	return 0;
}
