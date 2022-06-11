#include <string>

#include "injection_error.h"

exceptions::injection_error::injection_error(const std::string_view &filename, const std::string_view &message)
    : error{}
{
    static constexpr char error_template1[] = "Unable to inject ", error_template2[] = " with message: ";

    error += error_template1;
    error += filename;
    error += error_template2;
    error += message;
}


const char * exceptions::injection_error::what() const noexcept
{
    return error.data();
}
