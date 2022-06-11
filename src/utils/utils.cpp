#include "utils.h"

namespace utils {

    uint16_t swap_bytes(uint16_t word) noexcept
    {
        return (word >> 8) | (word << 8);
    }

    uint8_t read_byte(std::ifstream &in) noexcept
    {
        uint8_t byte;
        in.read((char *) &byte, 1);
        return byte;
    }

    uint16_t read_word(std::ifstream &in) noexcept
    {
        uint8_t byte1 = read_byte(in), byte2 = read_byte(in);
        return (static_cast<uint16_t>(byte1) << 8) | byte2;
    }

}