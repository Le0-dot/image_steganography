#ifndef PJC_PROJECT_UTILS_H
#define PJC_PROJECT_UTILS_H

#include <fstream>
#include <cstdint>

namespace utils {

    /**
     * Swaps bytes in 2 byte variable
     * @return Variable with swapped bytes
     */
    uint16_t swap_bytes(uint16_t word) noexcept;

    /**
     * Reads one byte from input stream
     * @param in Input stream from which 1 byte will be read
     * @return Read byte
     */
    uint8_t read_byte(std::ifstream &in) noexcept;

    /**
     * Read two bytes from input stream, swaps them and create 2 byte variable
     * @param in Input stream from which 2 bytes will be read
     * @return 2 bytes that were read
     */
    uint16_t read_word(std::ifstream &in) noexcept;

}

#endif
