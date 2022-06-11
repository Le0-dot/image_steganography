#include <string>

#include "flag_error.h"

exceptions::flag_error::flag_error(const std::string_view &flag) noexcept
    : error{}
{
    static constexpr char error_template1[] = "Unsupported flag: ",
                          error_template2[] = "\nTry -h/--help for more information";

    error += error_template1;
    error += flag;
    error += error_template2;
}

const char * exceptions::flag_error::what() const noexcept
{
    return error.data();
}
