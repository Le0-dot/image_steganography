#ifndef PJC_PROJECT_BMP_FILE_HEADER_H
#define PJC_PROJECT_BMP_FILE_HEADER_H

#include <cstdint>

namespace filetypes::headers::bitmap_headers {

    constexpr uint16_t BM = 0x4D42;

#pragma pack(push, 1)

    /**
    * bmp file main header describing bmp file type, size and offset to the pixel array
    */
    struct bmp_file_header {
        uint16_t file_type;
        uint32_t file_size;
        uint16_t reserved1;
        uint16_t reserved2;
        uint32_t offset;
    };

#pragma pack(pop)

}

#endif