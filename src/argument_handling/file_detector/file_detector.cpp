#include <filesystem>
#include <chrono>
#include <fstream>

#include <iostream>

#include "file_detector.h"
#include "../../exceptions/exceptions.h"

arguments::file_detector::file_detector(std::string_view filename, detector_command command)
    : filename{filename}
    , mark_{0}
{
    using namespace std::filesystem;
    using namespace std::chrono;

    path p(filename);
    if(!exists(p) || !is_regular_file(p))
        throw exceptions::read_error(filename);

    {
        std::ifstream file(p);
        file.read(reinterpret_cast<char *>(&mark_), 2);
    }

    if(command == detector_command::only_type)
        return;

    get_type_and_dim();

    if(type_ == "UNKNOWN")
        throw exceptions::unsupported_format_error(filename);

    size_ = file_size(p);
    mod_t = system_clock::to_time_t(file_clock::to_sys(last_write_time(p)));

}

void arguments::file_detector::get_type_and_dim() {
    switch(mark_) {
        case filetypes::file_mark::BMP: {
            filetypes::bmp file(filename);
            file.read();
            dim = file.dimensions();
            type_ = "BMP";
            break;
        }
        case filetypes::file_mark::PPM: {
            filetypes::ppm file(filename);
            file.read();
            dim = file.dimensions();
            type_ = "PPM";
            break;
        }
        default:
            type_ = "UNKNOWN";
            dim = std::make_pair(0, 0);
            break;
    }
}
