#include <iostream>

#include "handlers.h"
#include "../../exceptions/exceptions.h"

void arguments::handlers::help_handler(const int argc, const char **argv)
{
    static constexpr char msg1[] = "Usage: ",
                          msg2[] = " [OPTION] [FILE] [MESSAGE]\n"
                                   "Insert message into the image of supported file types\n"
                                   "Supported file types: ppm, bmp\n"
                                   "\n"
                                   "Arguments:\n"
                                   " -i, --info     FILE is checked whether it is supported\n"
                                   "                and show information about this file\n"
                                   " -e, --encrypt  MESSAGE is encrypted into FILE\n"
                                   " -d, --decrypt  extract message from FILE\n"
                                   " -c, --check    MESSAGE is being checked whether it could\n"
                                   "                be fit into FILE\n"
                                   " -h, --help     display this help text and exit\n"
                                   "\n"
                                   "Without options equivalent to -h\n";

    if(argc != 1 && argc != 2)
        throw exceptions::flag_usage_error(argc, argv);

    std::cout << msg1 << argv[0] << msg2;
}