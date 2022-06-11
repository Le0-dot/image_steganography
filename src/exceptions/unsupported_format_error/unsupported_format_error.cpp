#include "unsupported_format_error.h"

exceptions::unsupported_format_error::unsupported_format_error(const std::string_view &filename) noexcept {
    static constexpr char error_template[] = "File type is not supported: ";

    error += error_template;
    error += filename;
}

const char *exceptions::unsupported_format_error::what() const noexcept {
    return error.data();
}
