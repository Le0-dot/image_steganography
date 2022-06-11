#include "image_file.h"

#include "../../exceptions/exceptions.h"

filetypes::image_file::image_file(const std::string_view &filename) : filename(filename) {}

std::ofstream filetypes::image_file::copy_file(const std::string_view &destination) const
{
    std::ifstream in(filename.data(), std::ios_base::binary);
    if(!in)
        throw exceptions::read_error(filename);

    std::ofstream out(destination.data(), std::ios_base::binary);
    if(!out)
        throw exceptions::read_error(destination);

    out << in.rdbuf();

    return std::move(out);
}