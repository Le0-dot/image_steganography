#ifndef IMAGE_STENOGRAPHY_FILE_DETECTOR_H
#define IMAGE_STENOGRAPHY_FILE_DETECTOR_H

#include <string_view>
#include <string>
#include <utility>
#include <tuple>
#include <ctime>

#include "../../filetypes/filetypes.h"

namespace arguments {

    enum class detector_command {
        full = 0, only_type = 1
    };

    class file_detector {
    public:
        file_detector(std::string_view filename, detector_command command = detector_command::full);
        inline filetypes::file_mark mark() { return mark_; }
        inline std::string type() const { return type_; }
        inline size_t size() const { return size_; }
        inline std::pair<size_t, size_t> dimensions() const { return dim; }
        inline std::time_t modification_time() const { return mod_t; }

    private:
        const std::string_view filename;
        filetypes::file_mark mark_;
        std::string type_;
        size_t size_;
        std::pair<size_t, size_t> dim;
        time_t mod_t;

        void get_type_and_dim();
    };

}

#endif