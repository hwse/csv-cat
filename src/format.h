#ifndef CSV_CAT_FORMAT_H
#define CSV_CAT_FORMAT_H

#include <ostream>

#include "csv.h"

struct formatting_info {
    std::vector<int> column_sizes;
    unsigned int table_width;
};

formatting_info build_formatting_info(const csv::table &table);

void format_csv_table(const csv::table& table, std::ostream& out_stream);

#endif //CSV_CAT_FORMAT_H
