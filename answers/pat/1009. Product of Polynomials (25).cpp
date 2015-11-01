//
#include <iostream>
using namespace std;

#include <iomanip>
#include <vector>

int main (int argc, char *argv[])
{
	size_t poly_num[2] = {0, 0};
	size_t max_expo[2] = {0, 0};
	vector<double> coef_list[2];
	for (size_t i = 0; i < 2; ++ i) {
		cin >> poly_num[i];
		coef_list[i].resize(10000, 0);
		for (size_t j = 0; j < poly_num[i]; ++ j) {
			size_t expo(0);
			double coef(0.0);
			cin >> expo >> coef;
			max_expo[i] = std::max(max_expo[i], expo);
			//cout << "input " << expo << " " << coef << " " << max_expo[i] << endl;
			coef_list[i][expo] = coef;
		}
	}
	vector<double> multiply_list(10000, 0);
	for (size_t i = 0; i <= max_expo[0]; ++ i) {
		for (size_t j = 0; j <= max_expo[1]; ++ j) {
			multiply_list[i + j] += coef_list[0][i] * coef_list[1][j];
			//cout << "test " << i << " " << j << " " << multiply_list[i + j] << endl;
		}
	}
	vector<size_t> expo_list;
	vector<double> result_list;
	for (size_t i = max_expo[0] + max_expo[1] + 10; i <= max_expo[0] + max_expo[1] + 10; -- i) {
		if (multiply_list[i] != 0) {
			expo_list.push_back(i);
			result_list.push_back(multiply_list[i]);
		}
	}
	cout << expo_list.size();
	for (size_t i = 0; i < expo_list.size(); ++ i) {
		cout << " " << expo_list[i] << " " << setiosflags(ios::fixed) << setprecision(1) << result_list[i];
	}
	cout << endl;

	return 0;
}