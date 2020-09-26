#include "mystringstream.h"

int main()
{
	std::string wap = "wa aiab		pop";
	std::string temp;
	int w = 0;
	mystringstream ss(wap);
	ss >> temp;
	return 0;
}