/******************************************************************************
 * Copyright (C) 2021 by Cindy Wang
 *****************************************************************************/
/**
 * @file data.h
 * @brief Abstraction of integer and ASCII conversion
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Cindy Wang
 * @date January 4, 2021
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdlib.h>

/**
 * @brief Convert an integer to an ASCII string
 * 
 * Convert data from a standard integer type into an ASCII string
 * 
 * @param data The integer data to convert
 * @param ptr The pointer to where the converted ASCII string should be stored
 * @param base An integer value of the radix of the converted ASCII string
 * 
 * @return The length of the converted data
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert an ASCII string to an integer
 * 
 * Convert data from an ASCII represented string into an integer type.
 * 
 * @param ptr A pointer to a ASCII character string
 * @param digits The number of digits in the character set
 * @param base An integer value of the radix of the ASCII string
 * 
 * @return 
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */