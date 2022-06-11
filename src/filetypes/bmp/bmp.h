#ifndef PJC_PROJECT_BMP_H
#define PJC_PROJECT_BMP_H

#include <string>
#include <vector>

#include "../image_file/image_file.h"

#include "headers/bmp_file_header.h"
#include "headers/bmp_info_header.h"

namespace filetypes {

    /**
     * Class that implements work with .bmp files
     */
    class bmp : public image_file {
    private:
        headers::bitmap_headers::bmp_file_header file_header;
        headers::bitmap_headers::bmp_info_header info_header;
        std::vector<uint8_t> data;

    public:
        bmp(const std::string_view &filename);

        void read() override;

        bool check(const std::string_view &message) const override;

        void inject(const std::string_view &message) override;

        std::string extract() const override;

        void write(const std::string_view &destination) const override;

        std::pair<size_t, size_t> dimensions() const override;
    };

}

#endif