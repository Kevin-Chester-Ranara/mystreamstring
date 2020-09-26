#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

class mystringstream
{
public:
	mystringstream(std::string& str)
		:
		str(str)
	{
		typedef std::string::iterator iter;
		std::string temp;
		for (iter p = str.begin(); p != str.end(); p++)
		{
			if (*p >= ' ')
			{
				temp.push_back(*p);
			}
			else
			{
				newstring.emplace_back(temp);
				temp.clear();
				while (*p < ' ')
				{
					p++;
				}
				p--;
			}
		}
		newstring.emplace_back(temp);
	}

	template<typename T>
	mystringstream& operator>>(T& container)
	{
		std::string temp = *newstring.begin();
		std::remove_if(newstring.begin(), newstring.end(), []() {return temp == newstring; })
		ss >> container;
		newstring.erase(newstring.begin());
		return ss;
	}
private:
	std::string str;
	std::vector<std::string> newstring;
};