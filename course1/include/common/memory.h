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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick, additions by Cindy Wang
 * @date April 1 2017, additions January 2 2021
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stddef.h>
#include <stdlib.h>
#include <inttypes.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves data from one address to another
 * 
 * Given a pointer to data, move the data to another location. Prevents data loss due
 * to overlapping memory by copying the data to the heap first, then moving the data
 * from the heap to the destination.
 * 
 * @param src Pointer to data to be moved
 * @param dst Pointer to location for data to be moved to
 * @param length Number of bytes of information to move
 * 
 * @return a pointer to the destination of the moved data
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies data from one address to another
 * 
 * Given a pointer to data, copy the data to another location. Does not handle overlapping
 * memory blocks
 * 
 * @param src Pointer to data to be copied
 * @param dst Pointer to location for data to be copied to
 * @param length Number of bytes of information to copy
 * 
 * @return a pointer to the destination of the copied data
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets a specified number of bytes to the same specified value
 * 
 * Given a pointer to a source location, length, and value, set all locations of the memory to the value.
 * 
 * @param src Pointer to data to be set
 * @param length Number of memory locations to set
 * @param value Value to set the memory locations to
 * 
 * @return a pointer to the data
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets a specified number of bytes to 0
 * 
 * Given a pointer to a source location and length, set all locations of the memory to 0.
 * 
 * @param src Pointer to data to be set
 * @param length Number of memory locations to set
 * 
 * @return a pointer to the data
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of bytes at a location
 * 
 * Given a pointer to a source location and length, reverse the bytes
 * 
 * @param src Pointer to data to be reversed
 * @param length Number of memory locations
 * 
 * @return a pointer to the data
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates space in dynamic memory
 * 
 * Given a length, reverse the bytes
 * 
 * @param length Number of words to allocate
 * 
 * @return a pointer to the data or a Null Pointer if memory allocation is unsuccessful
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Frees space in dynamic memory
 * 
 * Given a pointer to a source, free the space
 * 
 * @param src Pointer to the space to free
 * 
 * @return void
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
