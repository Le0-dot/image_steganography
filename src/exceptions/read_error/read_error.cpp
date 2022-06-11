#include <string>

#include "read_error.h"

exceptions::read_error::read_error(const std::string_view &filename) noexcept
    : error{}
{
    static constexpr char error_template[] = "Unable to open or read file: ";

    error += error_template;
    error += filename;
}

const char * exceptions::read_error::what() const noexcept
{
    return error.data();
}