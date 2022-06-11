#include <fstream>
#include <stdexcept>

#include "bmp.h"

#include "../../exceptions/exceptions.h"

filetypes::bmp::bmp(const std::string_view &filename) : image_file(filename), data{} {}

#include <iostream>

void filetypes::bmp::read()
{
    std::ifstream in(filename.data(), std::ios_base::binary);
    if(!in)
        throw exceptions::read_error(filename);

    in.read(reinterpret_cast<char*>(&file_header), sizeof(file_header));
    if(file_header.file_type != headers::bitmap_headers::BM)
        throw exceptions::read_error(std::string("Unrecognized file format: ").append(filename));

    in.read(reinterpret_cast<char*>(&info_header), sizeof(info_header));
    in.seekg(file_header.offset, std::ifstream::beg);

    data.resize(info_header.width * info_header.height * info_header.bit_count / 8);
    in.read(reinterpret_cast<char*>(data.data()), data.size());
}

bool filetypes::bmp::check(const std::string_view &message) const
{
    if(data.empty())
        throw std::runtime_error("Unable to check if message could be written until file is read");

    return message.size() <= data.size() / (info_header.bit_count / 8);
}

void filetypes::bmp::inject(const std::string_view &message)
{
    if(!check(message))
        throw exceptions::injection_error(filename, message);

    auto it = data.begin() + info_header.bit_count / 8 - 1;
    for(const auto& msg_ch: message) {
        *it = msg_ch;
        it += info_header.bit_count / 8;
    }
    *it = 0;
}

std::string filetypes::bmp::extract() const
{
    if(data.empty())
        throw std::runtime_error("Read file before extracting message");

    std::string message;
    auto it = data.begin() + info_header.bit_count / 8 - 1;
    while(*it != 0) {
        message += *it;
        it += info_header.bit_count / 8;
    }
    return message;
}

void filetypes::bmp::write(const std::string_view &destination) const
{
    if(data.empty())
        throw std::runtime_error("Read file before writing to the file");

    std::ofstream out;

    if(destination != filename)
        out = copy_file(destination);
    else
        out.open(destination.data());

    out.seekp(file_header.offset, std::ifstream::beg);

    out.write(reinterpret_cast<const char*>(data.data()), data.size());

    out.close();
}

std::pair<size_t, size_t> filetypes::bmp::dimensions() const {
    return std::make_pair(info_header.width, info_header.height);
}
