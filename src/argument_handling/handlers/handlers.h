#ifndef PJC_PROJECT_HANDLERS_H
#define PJC_PROJECT_HANDLERS_H

namespace arguments::handlers {

    void info_handler(const int argc, const char **argv);
    void encrypt_handler(const int argc, const char **argv);
    void decrypt_handler(const int argc, const char **argv);
    void check_handler(const int argc, const char **argv);
    void help_handler(const int argc, const char **argv);

}

#endif