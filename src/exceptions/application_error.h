#ifndef PJC_PROJECT_APPLICATION_ERROR_H
#define PJC_PROJECT_APPLICATION_ERROR_H

#include <stdexcept>
#include <cstring>

namespace exceptions {

    /**
     * Abstract exception class of application
     */
    class application_error : public std::exception {
    public:
        virtual const char * what() const noexcept = 0;
    };

}

#endif