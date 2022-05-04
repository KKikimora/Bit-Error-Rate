#include <iostream>
#include <fstream>
#include <chrono>
#include <bitset>
#include <ctime>
#include <string>
#include <iomanip> 

void compareOfBits(std::bitset<8>& a, std::bitset<8>& b, long long int& counterBits, long long int& counterDiffBits)
{
    for (int i = 0; i < 8; ++i)
    {
        counterBits++;
        if (a[i] != b[i]) counterDiffBits++;
    }
};

void addLog(std::string&& msg)
{
    std::ofstream output;
    output.open("log.txt", std::ios_base::app);
    output << "D: ";
    std::time_t now = time(NULL);
    output << asctime(gmtime(&now)) << "M: " << msg << std::endl;
    output.close();
}

int main(int argc, char* argv[])
{
    std::cout << "Bit Error Rate" << std::endl;

    addLog("correct start of the program");

     if (argc != 3) 
    {
        addLog("wrong number of parameters");
        std::cout << "You must give two arguments!" << std::endl;
        return 1;
    }
    
    std::ifstream input1 (argv[1]);
    if (!input1.good())
    {   
        addLog("don't find first file");
        std::cout << "First input file isn't exist!" << std::endl;
        return 1;
    }

    addLog("correct open first file");

    std::ifstream input2 (argv[2]);
    if (!input2.good())
    {
        addLog("don't find second file");
        std::cout << "Second input file isn't exist!" << std::endl;
        return 1;
    }

    addLog("correct open second file");

    long long int counterBits{-8};
    long long int counterDiffBits{};
    auto timeCalStart = std::chrono::system_clock::now();

    while (!input1.eof())
    {   
        if (input2.eof())
        {
            addLog("second file is too short");
            std::cout << "Second file is too short!" << std::endl;
            return 1;
        }

        std::bitset<8> a, b;
        input1 >> a;
        input2 >> b;
        compareOfBits(a, b, counterBits, counterDiffBits);
    }

    if (!input2.eof())
    {
        addLog("first file is too short");
        std::cout << "First file is too short!" << std::endl;
        return 1;
    }

    addLog("correct file compares");

    auto timeCalEnd = std::chrono::system_clock::now();
    std::chrono::duration<double> diffTime = timeCalEnd - timeCalStart;

    double ber = static_cast<double>(counterDiffBits) / counterBits;

    std::cout << "Numbers of bits compared: " << counterBits << std::endl
              << "Number of different bits: " << counterDiffBits << std::endl
              << "BER: " << std::setprecision(5) << ber << std::endl
              << "Calculations time: " << diffTime.count() << " secund" << std::endl;

    addLog("Output: " + std::to_string(counterBits) + ", " + std::to_string(counterDiffBits) + ", " + std::to_string(ber) + ", " + std::to_string(diffTime.count()) + "s");

    input1.close();
    addLog("correct close first file");
    input2.close();
    addLog("correct close second file");
    addLog("correct end of the program");
    return 0;
}