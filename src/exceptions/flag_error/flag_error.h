#ifndef PJC_PROJECT_FLAG_ERROR_H
#define PJC_PROJECT_FLAG_ERROR_H

#include <string_view>

#include "../application_error.h"

namespace exceptions {

    /**
     * Exception that is thrown when input flag is not correct
     */
    class flag_error : public application_error {
    private:
        std::string error;

    public:
        flag_error(const std::string_view &flag) noexcept;

        const char *what() const noexcept override;
    };

}

#endif