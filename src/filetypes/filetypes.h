#ifndef PJC_PROJECT_FILETYPES_H
#define PJC_PROJECT_FILETYPES_H

namespace filetypes {

    class image_file;
    class bmp;
    class ppm;

    namespace headers {

        namespace bitmap_headers {

            struct bmp_file_header;
            struct bmp_info_header;

        }

        namespace ppm_headers {

            struct ppm_file_header;

        }

    }

    enum class file_mark {
        BMP = 0x4D42,
        PPM = 0x3650
    };

}

#include "image_file/image_file.h"
#include "bmp/bmp.h"
#include "bmp/headers/bmp_file_header.h"
#include "bmp/headers/bmp_info_header.h"
#include "ppm/ppm.h"
#include "ppm/headers/ppm_file_header.h"

#endif