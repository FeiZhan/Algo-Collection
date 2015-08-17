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

#include <cstring>
#include <algorithm>

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("output.txt");
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("output.txt", "w", stdout);
#endif
#endif

	char word0[1010], word1[1010];
	while (gets(word0) && gets(word1)) {
		sort(word0, word0 + strlen(word0));
		sort(word1, word1 + strlen(word1));
		for (int i = 0, j = 0; i < strlen(word0) && j < strlen(word1);) {
			if (word0[i] == word1[j]) {
				printf("%c", word0[i]);
				++ i;
				++ j;
			}
			else if (word0[i] > word1[j]) {
				++ j;
			} else {
				++ i;
			}
		}
		printf("\n");
	}

	return 0;
}
















