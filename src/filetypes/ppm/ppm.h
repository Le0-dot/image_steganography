#ifndef PJC_PROJECT_PPM_H
#define PJC_PROJECT_PPM_H

#include <vector>
#include <string_view>
#include <sstream>
#include <fstream>

#include "../image_file/image_file.h"
#include "headers/ppm_file_header.h"
#include "ppm_pixel.h"

namespace filetypes {

    class ppm : public image_file {
    private:
        headers::ppm_headers::ppm_file_header file_header{};
        std::vector<ppm_pixel> data;
        long long start_of_data;

        std::stringstream read_header(std::ifstream &in);

    public:
        ppm(const std::string_view &filename);

        void read() override;

        bool check(const std::string_view &message) const override;

        void inject(const std::string_view &message) override;

        std::string extract() const override;

        void write(const std::string_view &destination) const override;

        std::pair<size_t, size_t> dimensions() const override;
    };

}

#endif //PJC_PROJECT_PPM_H
