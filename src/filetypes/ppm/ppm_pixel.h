#ifndef PJC_PROJECT_PPM_PIXEL_H
#define PJC_PROJECT_PPM_PIXEL_H

#include <cstdint>

#pragma pack(push, 1)

struct ppm_pixel {
    uint8_t r, g, b;
};

#pragma pack(pop)

#endif