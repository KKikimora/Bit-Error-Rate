#include <iostream>
#include <fstream>
#include <bitset>

class Test
{	
	private:
	long long int sizeOfFile {};
	int fillingValue1 {};
	int fillingValue2 {};
	bool bitErrorRate {};
	std::ofstream file1;
	std::ofstream file2;
	std::string name1{};
	std::string name2{};

	public:
	Test(long long int size, int val1, bool ber, std::string nam1, std::string nam2): 
	sizeOfFile(size), fillingValue1(val1), bitErrorRate(ber), name1(nam1), name2(nam2)
	{
		filingOneValue();
	}

	Test(long long int size, int val1, bool ber, int val2, std::string nam1, std::string nam2): 
	sizeOfFile(size), fillingValue1(val1), bitErrorRate(ber), fillingValue2(val2),  name1(nam1), name2(nam2)
	{
		filingTwoValue();
	}

	void filingOneValue()
	{
		file1.open(name1, std::ios_base::binary);
		file2.open(name2, std::ios_base::binary);
		
		if (bitErrorRate)
		{
            //TO DO
		}
		else
		{
			for (int i = 0; i < sizeOfFile; ++i) 
			{
				file1 << std::bitset<8>{fillingValue1};
				file2 << std::bitset<8>{fillingValue1};
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
			file1 << std::bitset<8>{fillingValue1};
			file2 << std::bitset<8>{fillingValue2};
		}
		file1.close();
		file2.close();
	}
};

int main (int argc, char * argv[])
{
    Test(400000000, 85, 0, "file1.bin", "file2.bin");
}
