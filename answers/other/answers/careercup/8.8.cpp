int columnForRow[8];
bool check(int row)
{
	for (int i = 0; i < row; ++ i)
	{
		int diff = std::abs(columnForRow[i] - columnForRow[row]);
		if (diff == 0				// same column
			|| diff == row - i)		// same diagonal
		{
			return false;
		}
	}
	return true;
}
void placeQueen(int row)
{
	if (8 == row)
	{
		printBoard();
		return;
	}
	for (int i = 0; i < 8; ++ i)
	{
		// place on each column in this row
		columnForRow[row] = i;
		if (check(row))
		{
			placeQueen(row + 1);
		}
	}
}
