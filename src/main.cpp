#include <iostream>
#include <fstream>

#include "format.h"

#include "csv.h"

csv::table get_table(int argc, char *argv[]) {
    if (argc < 2) {
        return csv::read(std::cin);
    } else {
        std::ifstream input(argv[1]);
        return csv::read(input);
    }
}

int main(int argc, char *argv[]) {
    csv::table table = get_table(argc, argv);

    format_csv_table(table, std::cout);
    return 0;
}
