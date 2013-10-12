// actually I don't think it is correct
class Question
{
public:
	void findMaxSeq(void)
	{
		// sort by height and then weight
		std::sort(items);
		int currentUnfit = 0;
		while (currentUnfit < items.size())
		{
			std::vector<Person> nextSeq;
			int nextUnfit = fillNextSeq(currentUnfit, nextSeq);
			maxSeq = seqWithMaxLen(maxSeq, nextSeq);
			if (nextUnfit == currentUnfit)
			{
				break;
			} else
			{
				currentUnfit = nextUnfit;
			}
		}
	}
private:
	std::vector<Person> seqWithMaxLen(const std::vector<Person> &seq1, const std::vector<Person> &seq2)
	{
		return seq1.size() > seq2.size() ? seq1 : seq2;
	}
	int fillNextSeq(int startFrom, std::vector<Person> &seq)
	{
		int firstUnfit = startFrom;
		if (startFrom < items.size())
		{
			for (int i = 0; i < items.size(); ++ i)
			{
				Person item = items[i];
				// confusing
				if (0 == i || items[i - 1].isBefore(item))
				{
					seq.push_back(item);
				} else
				{
					firstUnfit = i;
				}
			}
		}
		return firstUnfit;
	}
	std::vector<Person> items;
	std::vector<Person> lastFoundSeq;
	std::vector<Person> maxSeq;
}
