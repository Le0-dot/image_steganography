cmake_minimum_required(VERSION 3.21)
project(image_steganography)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(image_steganography
        main.cpp
        filetypes/bmp/bmp.cpp filetypes/bmp/bmp.h
        filetypes/bmp/headers/bmp_file_header.h
        filetypes/bmp/headers/bmp_info_header.h
        filetypes/image_file/image_file.h filetypes/image_file/image_file.cpp
        filetypes/filetypes.h
        exceptions/read_error/read_error.cpp exceptions/read_error/read_error.h
        exceptions/injection_error/injection_error.cpp exceptions/injection_error/injection_error.h
        exceptions/application_error.h
        exceptions/exceptions.h
        filetypes/ppm/ppm.cpp filetypes/ppm/ppm.h
        filetypes/ppm/ppm_pixel.h
        filetypes/ppm/headers/ppm_file_header.h filetypes/ppm/headers/ppm_file_header.cpp
        file_context/file_context.h
        argument_handling/argument_handler_manager.cpp argument_handling/argument_handler_manager.h
        exceptions/flag_error/flag_error.cpp exceptions/flag_error/flag_error.h
        argument_handling/handlers/handlers.h argument_handling/handlers/info_handler.cpp
        argument_handling/handlers/encrypt_handler.cpp argument_handling/handlers/decrypt_handler.cpp
        argument_handling/handlers/check_handler.cpp argument_handling/handlers/help_handler.cpp
        exceptions/flag_usage_error/flag_usage_error.cpp exceptions/flag_usage_error/flag_usage_error.h
        argument_handling/file_detector/file_detector.cpp argument_handling/file_detector/file_detector.h
        exceptions/unsupported_format_error/unsupported_format_error.cpp
        exceptions/unsupported_format_error/unsupported_format_error.h)
