#ifndef PJC_PROJECT_FLAG_USAGE_ERROR_H
#define PJC_PROJECT_FLAG_USAGE_ERROR_H

#include "../application_error.h"

namespace exceptions {

    class flag_usage_error : public application_error {
    private:
        std::string error;

    public:
        flag_usage_error(const int argc, const char **argv);

        const char * what() const noexcept override;
    };

}

#endif