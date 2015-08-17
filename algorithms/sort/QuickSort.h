/// \cite CLRS

#ifndef _QUICK_SORT_
#define _QUICK_SORT_

#include <vector>

namespace NsQuickSort
{
/*! \class QuickSort
 * \brief QuickSort class.
 *
 * Details about QuickSort.
 */
	class CQuickSort
	{
	public:
/*! \fn bool QSort(std::vector<int> &num_vec)
 *  \brief A member function.
 *  \param num_vec a std::vector<int>.
 *  \exception std::out_of_range parameter is out of range.
 *  \return a bool.
 */
		/// \complexity NlogN
		bool QuickSort(std::vector<int> &num_vec);
	protected:
		bool SubQuickSort(std::vector<int> &num_vec
			, const int begin
			, const int end);
		int Partition(std::vector<int> &num_vec
			, const std::vector<int>::size_type begin
			, const std::vector<int>::size_type end);
		bool Swap(int &a, int &b);
	};
}

#endif