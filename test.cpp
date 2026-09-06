#include <vector>
#include <iostream>


int main()
{
	std::vector<float> dts =
	{
		1.0f/30, 
		1.0f/60, 
		1.0f/140, 
		1.0f/240
	};

	for (auto iter = dts.begin(); iter != dts.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}
}
