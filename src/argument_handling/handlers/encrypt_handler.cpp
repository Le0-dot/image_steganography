#include <iostream>

#include "handlers.h"
#include "../file_detector/file_detector.h"
#include "../../file_context/file_context.h"

namespace {

    void print_message(const char **argv) {
        std::cout << "Message \"" << argv[3] << "\" was successfully encrypted into file " << argv[2] << '\n';
    }

}

void arguments::handlers::encrypt_handler(const int argc, const char **argv)
{
    if(argc != 4)
        throw exceptions::flag_usage_error(argc, argv);

    file_detector detector(argv[2], detector_command::only_type);
    switch(detector.mark()) {
        case filetypes::file_mark::BMP: {
            file_context<filetypes::bmp> file(argv[2], {"backup.bmp"});
            file.inject(argv[3]);
            print_message(argv);
            break;
        }
        case filetypes::file_mark::PPM: {
            file_context<filetypes::ppm> file(argv[2], {"backup.ppm"});
            file.inject(argv[3]);
            print_message(argv);
            break;
        }
        default:
            throw exceptions::unsupported_format_error(argv[2]);
    }
}