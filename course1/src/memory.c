/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  uint8_t src[] = {0, 1, 2, 3, 4};
  uint8_t dest[5];
  my_memmove(src, dest, 5);
  return 0;
}

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
  // handle overlap by placing src data in temporary place first
  uint8_t *src_start = src;
  uint8_t *src_copy = (uint8_t*) malloc(sizeof(uint8_t) * length);
  while (src < src_start + length) {
    *src_copy = *src;
    src++;
    src_copy++;
  }

  uint8_t *src_copy_start = src_copy;
  while (src_copy < src_copy_start + length) {
    *dst = *src_copy;
    src_copy++;
    dst++;
  }

  return dst;
}

