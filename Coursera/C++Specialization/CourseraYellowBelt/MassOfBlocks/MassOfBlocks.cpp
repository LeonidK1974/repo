// MassOfBlocks.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
	uint32_t num_blocks;
	uint16_t density;
	cin >> num_blocks >> density;	
	uint64_t mass = 0;
	for (uint32_t i = 0; i < num_blocks; i++)
	{
		uint16_t  x, y, z;
		cin  >> x >> y >> z;
		mass += static_cast<uint64_t>(x) * y * z;
	}
	mass *= density;
	cout << mass << endl;
}

