#include <string>

#include "ppm_file_header.h"

namespace filetypes::headers::ppm_headers {

    ppm_file_header get_header(std::stringstream input, const std::string_view &filename) {

        std::string str;
        std::getline(input, str);

        if(str != "P6")
            throw exceptions::read_error(filename);

        ppm_file_header header{};
        header.file_format = PPM;

        std::getline(input, str, ' ');
        header.width = std::stoi(str);

        std::getline(input, str);
        header.height = std::stoi(str);

        std::getline(input, str);
        header.max = std::stoi(str);

        return header;
    }

}