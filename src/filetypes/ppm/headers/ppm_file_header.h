#ifndef PJC_PROJECT_PPM_FILE_HEADER_H
#define PJC_PROJECT_PPM_FILE_HEADER_H

#include <cstdint>
#include <string_view>
#include <sstream>

#include "../../../exceptions/exceptions.h"

namespace filetypes::headers::ppm_headers {

    constexpr uint16_t PPM = 0x5036;

    struct ppm_file_header {
        uint16_t file_format;
        uint16_t width;
        uint16_t height;
        uint8_t max;
    };

    /**
     * Takes part of ppm file and coverts it to the header
     * @param input, filename input from file that was separated by LF and filename of file required for error
     * @return ppm_file_header that was create from input
     */
    ppm_file_header get_header(std::stringstream input, const std::string_view &filename);

}

#endif