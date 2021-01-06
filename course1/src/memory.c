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
 * @author Alex Fosdick, additions by Cindy Wang
 * @date April 1 2017, additions January 4 2021
 *
 */
#include "memory.h"
#include <stdio.h>  // Remove (printf)
#include <stdlib.h>  // Remove

// gcc -o main.out src/memory.c -I include/common/ -DHOST

// int main() {
//   uint8_t src[] = {0, 1, 2, 3, 4};
//   uint8_t dest[5];
//   // my_memmove(src, dest, 5);
//   // my_memcopy(src, &src[4], 5);
//   // my_memset(src, 5, 1);
//   // my_memzero(src, 2);
//   uint8_t *ptr = my_reverse(src, 5);
  
//   for (int i = 0; i < 5; i++) {
//     printf("%hhu", *(ptr + i));
//   }

//   int32_t *p = reserve_words(4);
//   free_words(p);

//   return 0;
// }

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
  uint8_t *src_copy_start = src_copy;

  while (src < src_start + length) {
    *src_copy = *src;
    src++;
    src_copy++;
  }
  
  uint8_t *src_copy_start_start = src_copy_start;
  while (src_copy_start < src_copy_start_start + length) {
    *dst = *src_copy_start;
    src_copy_start++;
    dst++;
  }

  return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
  uint8_t *src_start = src;
  while (src < src_start + length) {
    *dst = *src;
    src++;
    dst++;
  }

  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
  uint8_t *src_start = src;

  while (src < src_start + length) {
    *src = value;
    src++;
  }

  return src_start;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
  uint8_t *src_start = src;
  while (src < src_start + length) {
    *src = 0;
    src++;
  }

  return src_start;
}

uint8_t * my_reverse(uint8_t * src, size_t length) {
  uint8_t *src_start_start = src;
  uint8_t *src_start = src;
  uint8_t *src_end = src + length - 1;

  while (src_start < src_end) {
    uint8_t temp = *src_end;
    *src_end = *src_start;
    *src_start = temp;
    src_start++;
    src_end--;
  }

  return src_start_start;
}

int32_t * reserve_words(size_t length) {
  // if malloc fails, it will return a Null pointer
  return (int32_t*) malloc(sizeof(int32_t) * length);
}

void free_words(int32_t * src) {
  free(src);
}