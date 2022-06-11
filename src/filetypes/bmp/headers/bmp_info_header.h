#ifndef PJC_PROJECT_BMP_INFO_HEADER_H
#define PJC_PROJECT_BMP_INFO_HEADER_H

#include <cstdint>

namespace filetypes::headers::bitmap_headers {

#pragma pack(push, 1)

    /**
    * bitmap information header describing size of this header, width and height of image,
    * bit count of pixel's color. Other parameters are not used.
    */
    struct bmp_info_header {
        uint32_t size;
        int32_t width;
        int32_t height;
        uint16_t planes;
        uint16_t bit_count;
        // There are other values, but they are not used in this program
    };

#pragma pack(pop)

}

#endif