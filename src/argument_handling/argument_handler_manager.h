#ifndef PJC_PROJECT_ARGUMENT_HANDLER_H
#define PJC_PROJECT_ARGUMENT_HANDLER_H

#include <map>
#include <string_view>
#include <functional>

namespace arguments {

    /**
     * Handler class that encapsulates argument handler functions
     */
    class argument_handler_manager {
    public:
        using func = std::function<void(const int, const char **)>;

    private:
        std::map<std::string_view, func> handlers;

    public:
        argument_handler_manager() noexcept;
        argument_handler_manager(std::map<std::string_view, func> &&handlers) noexcept;

        /**
         * Adds handler function for specific argument
         * @param key Argument for which handler is being added
         * @param value Handler function
         * @return bool value of whether handler was added
         */
        bool add(std::string_view &&key, func &&value);

        /**
         * Handle command line arguments with previously added handlers
         * @param argc number of command line arguments
         * @param argv command lien arguments
         */
        void handle(const int argc, const char **argv) const;

    };

}

#endif