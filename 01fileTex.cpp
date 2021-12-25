#include <iostream>
#include <fstream>
#include <string>
std::string decToHex(int num)
{
	std::string str;
	int interim = num;
	int d1 = 0;
	while ((interim /= 16) != 0) ++d1;
	int d2 = 1 << 4 * d1;
	while (d2 > 0) {
		int modifier = num / d2;
		if (modifier > 9) str += (char)(modifier + 55);
		else str += (char)(modifier + 48);
		num %= d2;
		d2 >>= 4;
	}
	return str;
}
int main()
{
	std::ifstream fin("input.txt", std::ifstream::binary);
	int count = 0;
	fin.seekg(0, fin.end);
	int length = fin.tellg();
	fin.seekg(0, fin.beg);

	char* interim = new char[length];
	fin.read(interim, length);
	size_t line_num = 0;
	for (int i = 0; i < 10; ++i) std::cout << '0';
	std::cout << ": ";
	for (size_t idx = 0; idx <= length; ++idx)
	{
		if (idx == length)
		{
			int diff;
			if (count > 8) diff = 16 - count;
			else diff = 17 - count;
			for (size_t spaces = 0; spaces < diff; ++spaces) std::cout << "   ";
			for (size_t c = idx - count; c < idx; ++c) std::cout << interim[c];
			std::cout << std::endl;
			break;
		}
		else
		{
			int temp = (int)interim[idx];
			if (temp < 32) temp = 46;
			std::string current_char = decToHex(temp);
			for (size_t i = 0; i < current_char.length(); ++i) std::cout << current_char[i];
			std::cout << " ";
			++count;
			if (count == 8) std::cout << "|";
			if (count == 16)
			{
				count = 0;
				++line_num;
				for (int c = idx - 15; c <= idx; ++c)
				{
					if ((int)interim[c] < 32) std::cout << (char)46;
					else std::cout << interim[c];
				}
				std::cout << std::endl;
				std::string hex_line_num = decToHex(line_num);
				int diff = 9 - (int)hex_line_num.length();
				for (size_t i = 0; i < diff; ++i) std::cout << 0;
				std::cout << hex_line_num << "0: ";
			}
		}
	}
	delete[] interim;
	fin.close();
}
