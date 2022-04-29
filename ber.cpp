#include<iostream>
#include <fstream>

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

    output.close();
    input1.close();
    input2.close();
    return 0;
}