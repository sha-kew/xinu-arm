/**
 * Header for display.c
 * Author: Owen Royall-Kahin
 */

#include <stdio.h>

typedef struct pixel {
    uint8_t r, g, b;
} pixel_t;

void display_init();

void clear_buffer();
void setPixel(int, int, pixel_t);
void setPixel2(int, int, uint8_t, uint8_t, uint8_t);