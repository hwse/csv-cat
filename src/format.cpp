#include <algorithm>
#include <numeric>
#include "format.h"

constexpr char ROW_SEPARATOR = '=';
constexpr char CELL_SEPARATOR = '|';

unsigned int calculate_table_width(std::vector<int> column_widths) {
    // width needed for separators between values
    return column_widths.size() + 1 +
            // sum of column sizes
            std::accumulate(column_widths.begin(), column_widths.end(), 0);

}

formatting_info build_formatting_info(const csv::table &table) {
    if (table.rows.empty()) {
        throw std::runtime_error("Cant calculate format of empty tables");
    }
    formatting_info result;
    std::vector<int> &sizes = result.column_sizes;
    for (const auto &cell: table.rows.at(0)) {
        sizes.push_back(cell.size());
    }

    for (int row_nr = 1; row_nr < table.rows.size(); row_nr++) {
        auto row = table.rows.at(row_nr);
        int max_row_index = std::max(row.size(), sizes.size());
        for (int cell_nr = 0; cell_nr < max_row_index; cell_nr++) {
            int cell_size = row.at(cell_nr).size();
            if (cell_size > sizes.at(cell_nr)) {
                sizes.at(cell_nr) = cell_size;
            }
        }
    }

    result.table_width = calculate_table_width(sizes);

    return result;
}

void format_csv_table(const csv::table &table, std::ostream &out_stream) {
    if (table.rows.empty()) {
        out_stream << "table is empty" << std::endl;
        return;
    }
    auto formatting_info = build_formatting_info(table);
    std::string row_separator(formatting_info.table_width, ROW_SEPARATOR);

    out_stream << row_separator << std::endl;
    for (const auto& row: table.rows) {
        out_stream << CELL_SEPARATOR;
        for (int i = 0; i < row.size(); i++) {
            const auto& cell = row.at(i);
            auto padding_size = formatting_info.column_sizes.at(i) - cell.size();
            out_stream << std::string(padding_size,' ') << cell << CELL_SEPARATOR;
        }
        out_stream << std::endl;
        out_stream << row_separator << std::endl;
    }
}



