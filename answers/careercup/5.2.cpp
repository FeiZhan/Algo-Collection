std::string printBinary(std::string n)
{
	int intpart = atoi(n.substr(0, n.find('.')).c_str());
	double decpart = atod(n.substr(n.find('.')).c_str());
	std::string int_string;
	while (intpart > 0)
	{
		int r = intpart % 2;
		intpart >>= 1;
		int_string = static_cast<char>(r + '0') + int_string;
	}
}
