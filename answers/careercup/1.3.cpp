void removeDuplicates(char *str) {
	if (NULL == str || strlen(str) < 2) {
		return;
	}
	int tail = 1;
	for (size_t i = 1; i < strlen(str); ++ i) {
		size_t j;
		for (j = 0; j < tail; ++ j) {
			if (str[i] == str[j]) {
				break;
			}
		}
		if (j == tail) {
			str[tail] = str[i];
			++ tail;
		}
	}
	str[tail] = '\0';
}
void removeDuplicatesEff(char *str) {
	if (NULL == str || strlen(str) < 2) {
		return;
	}
	bool hit[256] = {false};
	hit[str[0]] = true;
	int tail = 1;
	for (size_t i = 1; i < strlen(str); ++ i) {
		if (! hit[str[i]]) {
			str[tail] = str[i];
			++ tail;
			hit[str[i]] = true;
		}
	}
	str[tail] = '\0';
}