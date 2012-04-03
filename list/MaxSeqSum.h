/// from DSAA

#ifndef _MAX_SEQ_SUM_
#define _MAX_SEQ_SUM_

#include <iostream>
#include <vector>

namespace NsMaxSeqSum
{
	class CMaxSeqSum
	{
	public:
		CMaxSeqSum &operator<< (const std::vector<int> &seq);
		int MaxSeqSumSimple(void);
		int MaxSeqSumRec(void);
		friend std::ostream &operator<< (std::ostream &os, const CMaxSeqSum &seq);
	protected:
		int MaxSeqSumRec1(const int left, const int right);
	private:
		std::vector<int> m_seq;
	};
}

#endif