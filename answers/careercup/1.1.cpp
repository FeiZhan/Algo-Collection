bool isUniqueChars2(string str) {
	bool char_set[256] = {false};
	for (size_t i = 0; i < str.length(); ++ i) {
		char val = str[i];
		if (char_set[val]) {
			return false;
		}
		char_set[val] = true;
	}
	return true;
}
bool isUniqueChars(string str) {
	int checker = 0;
	for (size_t i = 0; i < str.length(); ++ i) {
		int val = str[i] - 'a';
		if ((checker & (1 << val)) > 0) {
			return false;
		}
		checker |= (1 << val);
	}
	return true;
}