#include "ppm.h"

filetypes::ppm::ppm(const std::string_view &filename) : image_file(filename), start_of_data{0} {}

std::stringstream filetypes::ppm::read_header(std::ifstream &in)
{
    std::stringstream stream{};

    char ch;
    for(size_t counter = 0; counter < 3; stream << ch, ++start_of_data) {
        in.read(&ch, sizeof(char));
        counter += (ch == '\n' ? 1 : 0);
    }

    return stream;
}

void filetypes::ppm::read()
{
    std::ifstream in(filename.data(), std::ios_base::binary);
    if(!in)
        throw exceptions::read_error(filename);

    file_header = headers::ppm_headers::get_header(read_header(in), filename);

    data.resize(file_header.width * file_header.height);
    in.read(reinterpret_cast<char*>(data.data()), data.size());
}

bool filetypes::ppm::check(const std::string_view &message) const
{
    if(data.empty())
        throw std::runtime_error("Unable to check if message could be written until file is read");

    return file_header.max >= 'z' && message.size() <= data.size();
}

void filetypes::ppm::inject(const std::string_view &message)
{
    if(!check(message))
        throw exceptions::injection_error(filename, message);

    auto it = data.begin();
    for(const auto& msg_ch: message)
        it++->b = msg_ch;
    it->b = 0;
}

std::string filetypes::ppm::extract() const
{
    if(data.empty())
        throw std::runtime_error("Read file before extracting message");

    std::string message;
    auto it = data.begin();
    while(it->b != 0)
        message += it++->b;
    return message;
}

void filetypes::ppm::write(const std::string_view &destination) const
{
    if(data.empty())
        throw std::runtime_error("Read file before writing to the file");

    std::ofstream out;

    if(destination != filename)
        out = copy_file(destination);
    else
        out.open(destination.data());

    out.seekp(start_of_data, std::ifstream::beg);

    out.write(reinterpret_cast<const char*>(data.data()), data.size());

    out.close();
}

std::pair<size_t, size_t> filetypes::ppm::dimensions() const {
    return std::make_pair(file_header.width, file_header.height);
}
