#include<iostream>
#include <fstream>
#include <chrono>

int main(int argc, char* argv[])
{
    std::cout << "Bit Error Rate " << std::endl;
    std::ofstream output ("log.txt");

     if(argc != 3) 
    {
        std::cout << "You must give two arguments!" << std::endl;
        return 1;
    }

    std::ifstream input1 (argv[1]);
    if(!input1.good())
    {   
        std::cout << "First input file isn't exist!" << std::endl;
        return 1;
    }

    std::ifstream input2 (argv[2]);
    if(!input2.good())
    {
        std::cout << "Second input file isn't exist!" << std::endl;
        return 1;
    }
    
    int counterBits{};
    int counterDiffBits{};
    auto timeCalStart = std::chrono::system_clock::now();

    while (!input1.eof())
    {
       // TO DO
       // compare of bits
    }

    auto timeCalEnd = std::chrono::system_clock::now();
    std::chrono::duration<double> diffTime = timeCalEnd - timeCalStart;

    std::cout << "Numbers of bits compared: " << counterBits << std::endl
              << "Number of different bits: " << counterDiffBits << std::endl
              << "BER: " << std::boolalpha << static_cast<bool>(!counterDiffBits) << std::endl
              << "Calculations time: " << diffTime.count() << " secund" << std::endl;


    output.close();
    input1.close();
    input2.close();
    return 0;
}