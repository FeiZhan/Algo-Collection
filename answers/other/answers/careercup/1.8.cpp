bool isRotation(string s1, string s2) {
	if (s1.length() == s2.length() && s1.length() > 0) {
		string s1s1 = s1 + s1;
		return isSubstring(s1s1, s2);
	}
	return false;
}