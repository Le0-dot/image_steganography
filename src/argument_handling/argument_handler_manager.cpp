#include <stdexcept>

#include "argument_handler_manager.h"
#include "../exceptions/exceptions.h"

arguments::argument_handler_manager::argument_handler_manager() noexcept
    : handlers{} {}

arguments::argument_handler_manager::argument_handler_manager(std::map<std::string_view, argument_handler_manager::func> &&handlers) noexcept
    : handlers(std::move(handlers)) {}

bool arguments::argument_handler_manager::add(std::string_view &&key, argument_handler_manager::func &&value)
{
    return handlers.insert({std::move(key), std::move(value)}).second;
}

void arguments::argument_handler_manager::handle(const int argc, const char **argv) const
{
    if (argc == 1) {
        handlers.at("")(argc, argv);
        return;
    }

    try {
        handlers.at(argv[1])(argc, argv);
    } catch (const std::out_of_range &e) {
        throw exceptions::flag_error(argv[1]);
    }
}
