#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <getopt.h>
#include <stdio.h>



int num = -1;
bool is_beep = false;
float sigma = 2.034;
std::string write_file = "default_file.txt";



//using namespace std;




const char* const short_options = "n:bs:w:h";
const option long_options[] = {
            {"num",         required_argument,  nullptr, 'n'},
            {"beep",        no_argument,        nullptr, 'b'},
            {"sigma",       required_argument,  nullptr, 's'},
            {"writeFile",   required_argument,  nullptr, 'w'},
            {"help",        no_argument,        nullptr, 'h'},
            {nullptr, no_argument, nullptr, 0}
    };


void PrintHelp()
{
    std::cout <<
            "--num <n>:           Set number of program\n"
            "--beep:              Beep the user\n"
            "--sigma <val>:       Set sigma of program\n"
            "--writeFile <fname>: File to write to\n"
            "--help:              Show help\n";
    exit(1);
}


int main(int argc, char **argv)
{

    while(true){
        const auto Parameter = getopt_long (argc, argv, short_options, long_options, nullptr);
        if (Parameter == -1){
            break;
        }
        switch(Parameter){
            case 'n':
                num = std::stoi(optarg);
                std::cout << "Num set to: " << num << std::endl;
                break;

            case 'b':
                is_beep = true;
                std::cout << "Beep is set to true\n";
                break;

            case 's':
                sigma = std::stof(optarg);
                std::cout << "Sigma set to: " << sigma << std::endl;
                break;
            case 'w':
                write_file = std::string(optarg);
                std::cout << "Write file set to: " << write_file << std::endl;
                break;

            case 'h': // -h or --help
            case '?': // Unrecognized option
            default:
                PrintHelp();
                break;
        }
    }
    std::cout << "Hello world!" << std::endl;
    return 0;
}
