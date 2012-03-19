#include "OpenHash.h"

namespace NsOpenHash
{
	COpenHash::COpenHash(const int size)
	{
		this->Init(size);
	}
	COpenHash::~COpenHash(void)
	{
		/// \todo
	}
	bool COpenHash::Init(int size)
	{
		if (size < MIN_TBL_SIZE)
		{
			size = MIN_TBL_SIZE;
		}
		size = this->NextPrime(size);
		this->hash_tbl.resize(size);
		for (int i = 0; i < size; ++ i)
		{
			this->hash_tbl.at(i).state = Empty;
		}
		return true;
	}
	int COpenHash::NextPrime(const int num)
	{
		/// \todo
		return num;
	}
	int COpenHash::Find(const int key)
	{
		int col_num = 0, now = this->Hash(key);
		while (this->hash_tbl.at(now).state != Empty
			&& this->hash_tbl.at(now).key != key)
		{
			++ col_num;
			now += 2 * col_num - 1;
			if (now >= this->hash_tbl.size())
			{
				now %= this->hash_tbl.size();
			}
		}
		return now;
	}
	int COpenHash::Hash(const int key)
	{
		return key % this->hash_tbl.size();
	}
	bool COpenHash::Insert(const int key)
	{
		int pos = this->Find(key);
		if (this->hash_tbl.at(pos).state != Legit)
		{
			this->hash_tbl.at(pos).key = key;
			this->hash_tbl.at(pos).state = Legit;
		}
		return true;
	}
	std::ostream &operator<< (std::ostream &os, const COpenHash &hash)
	{
		os << "OpenHash ";
		for (int i = 0; i < hash.hash_tbl.size(); ++ i)
		{
			os <<"hash " << i << " ";
			if (hash.hash_tbl.at(i).state == Empty)
				os << "empty ";
			else
				os <<"key " << hash.hash_tbl.at(i).key << " state "
					<< hash.hash_tbl.at(i).state << " ";
		}
		return os;
	}
}