#include <iostream>

#include "handlers.h"
#include "../file_detector/file_detector.h"
#include "../../file_context/file_context.h"

namespace {

    void print_message(const char **argv, const std::string& msg) {
        std::cout << "File " << argv[2] << " contains message \"" << msg << "\"\n";
    }

}

void arguments::handlers::decrypt_handler(const int argc, const char **argv)
{
    if(argc != 3)
        throw exceptions::flag_usage_error(argc, argv);

    file_detector detector(argv[2], detector_command::only_type);
    switch(detector.mark()) {
        case filetypes::file_mark::BMP: {
            file_context<filetypes::bmp> file(argv[2]);
            print_message(argv, file.extract());
            break;
        }
        case filetypes::file_mark::PPM: {
            file_context<filetypes::ppm> file(argv[2]);
            print_message(argv, file.extract());
            break;
        }
        default:
            throw exceptions::unsupported_format_error(argv[2]);
    }
}