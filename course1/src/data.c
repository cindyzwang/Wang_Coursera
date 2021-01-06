/******************************************************************************
 * Copyright (C) 2021 - Cindy Wang
 *****************************************************************************/
/**
 * @file data.c
 * @brief Integer and ASCII string conversions
 *
 * This implementation file provides an abstraction of converting data between integers an ASCII strings
 *
 * @author Cindy Wang
 * @date January 4 2021
 *
 */
#include "data.h"
#include "memory.h"
#include <math.h>
#include <stdio.h>  // Remove (printf)
#include <stdlib.h>  // Remove

int main() {
  int32_t data = -255;
  uint8_t ptr[20];
  uint8_t length = my_itoa(data, ptr, 10);

  for (int i = 0; i < length; i++) {
    printf("%c", *(ptr + i));
  }

  printf("\n%u\n", length);

  return 0;
}

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  uint8_t * ptr_start = ptr;
  uint32_t length = 0;

  unsigned char is_negative = (data < 0) ? 1 : 0;
  uint16_t unsigned_data = abs(data);

  while (unsigned_data != 0) {
    uint8_t r = unsigned_data % base;

    if (r < 10) {
      *ptr = r + '0';
    } else {
      *ptr = (r - 10) + 'A';
    }

    unsigned_data /= base;
    ptr++;
    length++;
  }

  if (is_negative) {
    *ptr = '-';
    ptr++;
    length++;
  }

  my_reverse(ptr_start, length);

  *ptr = '\0';  // Null terminator
  length++;

  return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  return (int32_t) digits;
}
