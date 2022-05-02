#include <iostream>
#include <fstream>
#include <bitset>

class Test
{	
	private:
	long long int sizeOfFile {};
	std::bitset<8> fillingValue1 {};
	std::bitset<8> fillingValue2 {};
	bool bitErrorRate {};
	std::ofstream file1;
	std::ofstream file2;
	std::string name1{};
	std::string name2{};

	public:
	Test(long long int size, int val1, bool ber, std::string nam1, std::string nam2): 
	sizeOfFile(size), fillingValue1(std::bitset<8> {val1}), bitErrorRate(ber), name1(nam1), name2(nam2)
	{
		filingOneValue();
	}

	Test(long long int size, int val1, bool ber, int val2, std::string nam1, std::string nam2): 
	sizeOfFile(size), fillingValue1(std::bitset<8> {val1}), bitErrorRate(ber), fillingValue2(std::bitset<8> {val2}),  name1(nam1), name2(nam2)
	{
		filingTwoValue();
	}

	void filingOneValue()
	{
		file1.open(name1, std::ios_base::binary);
		file2.open(name2, std::ios_base::binary);
		
		if (bitErrorRate)
		{
			file1 << fillingValue1;
			file2 << fillingValue1.flip();		
			
			file1 << fillingValue1;	

			auto temp = fillingValue1;
			temp.flip(1);
			temp.flip(2);

			file2 << temp;
			
			for (int i = 2; i < sizeOfFile; ++i) 
			{
				file1 << fillingValue1;
				file2 << fillingValue1;
			}
		}
		else
		{
			for (int i = 0; i < sizeOfFile; ++i) 
			{
				file1 << fillingValue1;
				file2 << fillingValue1;
			}
		}

		file1.close();
		file2.close();
	}

	void filingTwoValue()
	{
		file1.open(name1, std::ios_base::binary);
		file2.open(name2, std::ios_base::binary);
		for (int i = 0; i < sizeOfFile; ++i) 
		{
			file1 << fillingValue1;
			file2 << fillingValue2;
		}
		file1.close();
		file2.close();
	}
};

int main (int argc, char * argv[])
{
	if (argc == 6)
	{
		Test(std::stoi(argv[1]), std::stoi(argv[2]), std::stoi(argv[3]), argv[4], argv[5]);
		return 0;
	}
	
	if (argc == 7)
	{	
		Test(std::stoi(argv[1]), std::stoi(argv[2]), std::stoi(argv[3]), std::stoi(argv[4]), argv[5], argv[6]);
		return 0;
	}
  
    std::cout << "Given wrong arguments!" << std::endl;
	return 1;
}