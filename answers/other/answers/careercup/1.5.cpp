void replaceFun(char *str) {
	int length = strlen(str);
	int space_count = 0;
	for (int i = 0; i < length; ++ i) {
		if (' ' == str[i]) {
			++ space_count;
		}
	}
	int new_length = length + space_count * 2;
	str[new_length] = '\0';
	for (int i = length - 1; i >= 0; -- i) {
		if (' ' == str[i]) {
			str[new_length - 1] = '0';
			str[new_length - 2] = '2';
			str[new_length - 3] = '%';
			new_length -= 3;
		}
		else {
			str[new_length] = str[i];
			-- new_length;
		}
	}
}