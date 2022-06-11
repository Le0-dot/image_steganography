#ifndef PJC_PROJECT_EXCEPTIONS_H
#define PJC_PROJECT_EXCEPTIONS_H

namespace exceptions {

    class application_error;

    class read_error;
    class injection_error;
    class flag_error;
    class flag_usage_error;
    class unsupported_format_error;

}

#include "application_error.h"
#include "read_error/read_error.h"
#include "injection_error/injection_error.h"
#include "flag_error/flag_error.h"
#include "flag_usage_error/flag_usage_error.h"
#include "unsupported_format_error/unsupported_format_error.h"

#endif