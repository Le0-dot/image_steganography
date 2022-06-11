#include <iostream>

#include "handlers.h"
#include "../file_detector/file_detector.h"
#include "../../exceptions/exceptions.h"

void arguments::handlers::info_handler(const int argc, const char **argv)
{
    if(argc != 3)
        throw exceptions::flag_usage_error(argc, argv);

    file_detector detector(argv[2]);
    const auto [w, h] = detector.dimensions();
    time_t mod_t = detector.modification_time();
    std::cout << argv[2] << ": " << detector.type() << " file. File size " << detector.size()
        << " bytes. Dimensions " << w << 'x' << h << ". Modification date " << std::asctime(std::localtime(&mod_t)) << '\n';
}
