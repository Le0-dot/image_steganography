#ifndef PJC_PROJECT_INJECTION_ERROR_H
#define PJC_PROJECT_INJECTION_ERROR_H

#include <string_view>

#include "../application_error.h"

namespace exceptions {

    /**
     * Exception class thrown when occurs error in injecting message into file
     */
    class injection_error : public application_error {
    private:
        std::string error;

    public:
        injection_error(const std::string_view &filename, const std::string_view &message);

        const char * what() const noexcept override;
    };

}

#endif