bool anagram(string s, string t) {
	return sort(s) == sort(t);
}
bool anagram(string s, string t) {
	if (s.length() != t.length()) {
		return false;
	}
	int letters[256] = {0};
	int num_unique_chars = 0;
	int num_completed_t = 0;
	for (char c : s) {
		if (0 == letters[c]) {
			++ num_unique_chars;
		}
		++ letters[c];
	}
	for (char c : t) {
		if (0 == letters[c]) {
			return false;
		}
		-- letters[c];
		if (0 == letters[c]) {
			++ num_completed_t;
			if (num_completed_t == num_unique_chars) {
				return i == t.length() - 1;
			}
		}
	}
	return false;
}