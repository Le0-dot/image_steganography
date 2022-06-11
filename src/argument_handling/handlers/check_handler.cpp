#include <iostream>

#include "handlers.h"
#include "../file_detector/file_detector.h"
#include "../../file_context/file_context.h"

namespace {

    void print_message(const char **argv, bool can) {
        std::cout << "File " << argv[2] << " " << (can ? "can" : "can not") << " contain message \"" << argv[3] << "\"\n";
    }

}

void arguments::handlers::check_handler(const int argc, const char **argv)
{
    if(argc != 4)
        throw exceptions::flag_usage_error(argc, argv);

    file_detector detector(argv[2], detector_command::only_type);
    switch(detector.mark()) {
        case filetypes::file_mark::BMP: {
            file_context<filetypes::bmp> file(argv[2]);
            print_message(argv, file.check(argv[3]));
            break;
        }
        case filetypes::file_mark::PPM: {
            file_context<filetypes::ppm> file(argv[2]);
            print_message(argv, file.check(argv[3]));
            break;
        }
        default:
            throw exceptions::unsupported_format_error(argv[2]);
    }
}