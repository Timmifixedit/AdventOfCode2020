#include <iostream>
#include <fstream>
#include <vector>

unsigned int checkSlope(const std::vector<std::string> &field, unsigned int xInc, unsigned int yInc) {
    std::size_t x = xInc;
    unsigned int treeCount = 0;
    for (std::size_t y = yInc; y < field.size(); y += yInc) {
        if (field[y][x % field[y].size()] == '#') {
            ++treeCount;
        }

        x += xInc;
    }

    return treeCount;
}

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

    std::vector<std::string> field;
    std::string line;
    while (file >> line) {
        field.emplace_back(std::move(line));
    }

    // Ex1
    std::cout << "encountered " << checkSlope(field, 3, 1) << " trees in ex 1" << std::endl;

    // Ex2
    unsigned int treeCount = 1;
    treeCount *= checkSlope(field, 1, 1);
    treeCount *= checkSlope(field, 3, 1);
    treeCount *= checkSlope(field, 5, 1);
    treeCount *= checkSlope(field, 7, 1);
    treeCount *= checkSlope(field, 1, 2);
    std::cout << "product of trees is " << treeCount << std::endl;

    return 0;
}
