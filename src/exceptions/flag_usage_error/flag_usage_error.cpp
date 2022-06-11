#include "flag_usage_error.h"

exceptions::flag_usage_error::flag_usage_error(const int argc, const char **argv)
    : error{}
{
    static constexpr char error_template1[] = "Unsupported usage of option: ",
                          error_template2[] = "\nTry -h/--help for more information";

    error += error_template1;

    error += argv[0];
    for(int i = 1; i < argc; ++i) {
        error += ' ';
        error += argv[i];
    }

    error += error_template2;
}

const char * exceptions::flag_usage_error::what() const noexcept
{
    return error.data();
}
