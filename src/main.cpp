#include <iostream>
#include <thread>

#include "filetypes/filetypes.h"
#include "file_context/file_context.h"
#include "exceptions/exceptions.h"
#include "argument_handling/argument_handler_manager.h"
#include "argument_handling/handlers/handlers.h"

int main(int argc, const char **argv)
{
    arguments::argument_handler_manager handler{};

    handler.add("", arguments::handlers::help_handler);
    handler.add("-h", arguments::handlers::help_handler);
    handler.add("--help", arguments::handlers::help_handler);
    handler.add("-i", arguments::handlers::info_handler);
    handler.add("--info", arguments::handlers::info_handler);
    handler.add("-c", arguments::handlers::check_handler);
    handler.add("--check", arguments::handlers::check_handler);
    handler.add("-d", arguments::handlers::decrypt_handler);
    handler.add("--decrypt", arguments::handlers::decrypt_handler);
    handler.add("-e", arguments::handlers::encrypt_handler);
    handler.add("--encrypt", arguments::handlers::encrypt_handler);

    handler.handle(argc, argv);
/*
    std::cout << "==========================BMP==========================\n";

    {

        file_context<filetypes::bmp> file(argv[1], argv[3]);

        file.inject("Hello, world!!!");

        std::cout << file.extract() << '\n';

    }

    {

        file_context<filetypes::bmp> file(argv[3]);

        std::cout << file.extract() << '\n';

    }

    try {
        file_context<filetypes::bmp>("123");
    } catch (const exceptions::application_error &e) {
        std::cerr << e.what() << '\n';
    }

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1ms);

    std::cout << "\n==========================PPM==========================\n";

    {

        file_context<filetypes::ppm> file(argv[2], argv[4]);

        file.inject("Hello, world!!!");

        std::cout << file.extract() << '\n';

    }

    {

        file_context<filetypes::ppm> file(argv[4]);

        std::cout << file.extract() << '\n';

    }
*/
    return 0;
}