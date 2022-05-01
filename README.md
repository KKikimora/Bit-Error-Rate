# Bit-Error-Rate
This console program calculates the BER (Bit Error Rate) for any two files.
It takes two arguments - the paths of two files, for which it calculates the BER.
The result of the program's work is:
- number of compared bits
- number of different bits
- BER result
- calculation time
Additionally, the program generates a log.txt file, where are saved logs describing the program's flow.
=======================================================================================================================
Additional program test.cpp is responsible for generating files that can be used to run the main program.
Its invocation triggers the launch of the constructor of the Test class responsible for creating files. 
He may accept other arguments, depending on the needs, in accordance with the constructor's declarations listed below:

--> Test (long long int size, int val1, bool ber, std :: string nam1, std :: string nam2)
- size - size of the created files
- val1 - value with which files will be filled
- ber - boolean value determining the existence of differences between files (10 bits)
- nam1 - name of the first file
- nam2 - name of the second file

--> Test (long long int size, int val1, bool ber, int val2, std :: string nam1, std :: string nam2)
- size - size of the created files
- val1 - value with which the first file will be filled
- ber - boolean value determining the existence of differences between files (10 bits) - irrelevant in this call
- val2 - value with which the second file will be filled
- nam1 - name of the first file
- nam2 - name of the second file