void setZeros(int matrix[][]) {
	int row[matrix.length];
	int column[matrix[0].length];
	for (size_t i = 0; i < matrix.length(); ++ j) {
		for (size_t j = 0; j < matrix[0].length(); ++ j) {
			if (0 == matrix[i][j]) {
				row[i] = true;
				column[j] = true;
			}
		}
	}
	for (size_t i = 0; i < matrix.length(); ++ i) {
		for (size_t j = 0; j < matrix[0].length(); ++ j) {
			if (row[i] || column[j]) {
				matrix[i][j] = 0;
			}
		}
	}
}