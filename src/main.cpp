#include <iostream>

#include "format.h"

#include "boost/filesystem.hpp"
#include "csv.h"

csv::table get_table(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Using stdin for input." << std::endl;
        return csv::read(std::cin);
    } else {
        boost::filesystem::path p(argv[1]);
        if (!boost::filesystem::exists(p)) {
            std::cout << "File: " << argv[1] << "does not exist" << std::endl;
            std::exit(1);
        }
        std::ifstream input(argv[1]);
        return csv::read(input);
    }
}

int main(int argc, char *argv[]) {
    csv::table table = get_table(argc, argv);

    format_csv_table(table, std::cout);
    return 0;
}
