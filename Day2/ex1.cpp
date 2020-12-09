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
    int min;
    int max;
    char dummy;
    std::string pw;
    std::size_t validCount = 0;
    while (file >> min >> dummy >> max >> critical >> dummy >> pw) {
        std::cout << pw << " " << critical << " [" << min << ", " << max << "]";
        unsigned int cCount = 0;
        bool tooMany = false;
        for (char c : pw) {
            if (c == critical && ++cCount > max) {
                tooMany = true;
                break;
            }
        }

        if (!tooMany && cCount >= min) {
            ++validCount;
            std::cout << " valid" << std::endl;
        } else {
            std::cout << " not valid" << std::endl;
        }
    }

    std::cout << "Total number valid: " << validCount << std::endl;
    return 0;
}
