#ifndef PJC_PROJECT_READ_ERROR_H
#define PJC_PROJECT_READ_ERROR_H

#include <string>

#include "../application_error.h"

namespace exceptions {

    /**
     * Exception class thrown when occurs error in reading files
     */
    class read_error : public application_error {
    private:
        std::string error;

    public:
        read_error(const std::string_view &filename) noexcept;

        const char * what() const noexcept override;
    };

}

#endif