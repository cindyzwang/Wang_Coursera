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

/**
 * @brief Convert an integer to an ASCII string
 * 
 * Convert data from a standard integer type into an ASCII string
 * 
 * @param data
 * @param ptr
 * @param base
 * 
 * @return The length of the converted data
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert an ASCII string to an integer
 * 
 * Convert data back from an ASCII represented string into an integer type.
 * 
 * @param data
 * @param ptr
 * @param base
 * 
 * @return 
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */