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
#include <stdlib.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  uint8_t * ptr_start = ptr;
  uint32_t length = 0;

  unsigned char is_negative = (data < 0) ? 1 : 0;  
  uint32_t unsigned_data = abs(data);

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
  // exclude the negative sign and null terminator from the digits parameter
  if (*ptr == '-') {
    digits -= 2;
  } else {
    digits -= 1;
  }

  unsigned char is_negative = (*ptr == '-') ? 1 : 0;
  if (is_negative) {
    ptr++;
  }

  uint32_t multiplier = base;
  for (uint8_t i = 0; i < digits - 2; i++) {
    multiplier *= base;
  }

  int32_t sum = 0;
  while (*ptr != '\0') {
    uint8_t val;
    if (*ptr >= 'A') {
      val = *ptr + 10 - 'A';
    } else {
      val = *ptr - '0';
    }

    sum += val * multiplier;

    ptr++;
    digits--;
    multiplier /= base;
  }

  if (is_negative) {
    sum *= -1;
  }

  return sum;
}
