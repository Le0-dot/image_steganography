#ifndef IMAGE_STENOGRAPHY_UNSUPPORTED_FORMAT_ERROR_H
#define IMAGE_STENOGRAPHY_UNSUPPORTED_FORMAT_ERROR_H

#include <string>

#include "../application_error.h"

namespace exceptions {

    /**
     * Exception class thrown when input file has format that is not supported by application
     */
    class unsupported_format_error : public application_error {
    private:
        std::string error;

    public:
        unsupported_format_error(const std::string_view &filename) noexcept;

        const char * what() const noexcept override;
    };

}

#endif