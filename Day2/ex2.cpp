#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Please specify the path to the input file" << std::endl;
        std::exit(1);
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Cannot open file '" << argv[1] << "'" << std::endl;
        std::exit(1);
    }

    char critical;
    int pos1;
    int pos2;
    char dummy;
    std::string pw;
    std::size_t validCount = 0;
    while (file >> pos1 >> dummy >> pos2 >> critical >> dummy >> pw) {
        std::cout << pw << " " << critical << " [" << pos1 << ", " << pos2 << "]";
        if ((pw[pos1 - 1] == critical) != (pw[pos2 - 1] == critical)) {
            ++validCount;
            std::cout << " valid";
        } else {
            std::cout << " not valid";
        }

        std::cout << std::endl;
    }

    std::cout << "Total number valid: " << validCount << std::endl;
    return 0;
}
