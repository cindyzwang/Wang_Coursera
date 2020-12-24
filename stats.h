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
 * @file stats.h
 * @brief Prototypes of methods to analyze an array of unsigned characters
 *
 * Prototypes of methods to analyze an array of unsigned characters. Analysis methods are
 * print_statistics, print_array, find_median, find_mean, find_maximum, find_minumum, and sort_array.
 *
 * @author Cindy Wang
 * @date Dec 23, 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Prints statistics of an array of unsigned character
 *
 * This function takes as input a reference to an array of unsigned characters
 * and the number of elements contained in the array. 
 * This will calculate the following statistics, rounded down to the nearest integer:
 * median, mean, maximum, and minimum. This will then print out those calculated 
 * statistics to the console and returns no value
 *
 * @param data The reference to an array of unsigned characters to analyze
 * @param length The number of elements in the parameter "data"
 *
 * @return void
 */
void print_statistics(unsigned char data[], unsigned int length);

/**
 * @brief Prints an array of unsigned characters
 *
 * This function takes as input a reference to an array of unsigned characters
 * and the number of elements contained in the array. 
 * This will print out all elements to the console.
 *
 * @param data The reference to an array of unsigned characters to analyze
 * @param length The number of elements in the parameter "data"
 *
 * @return void
 */
void print_array(unsigned char data[], unsigned int length);

/**
 * @brief Evaluates the median for an array of unsigned characters
 *
 * This function takes as input a reference to an array of unsigned characters
 * and the number of elements contained in the array. 
 * This will evaluate the median, rounded down to the nearest integer.
 *
 * @param data The reference to an array of unsigned characters to analyze
 * @param length The number of elements in the parameter "data"
 *
 * @return The median of the parameter "data"
 */
unsigned char find_median(unsigned char data[], unsigned int length);

/**
 * @brief Evaluates the mean for an array of unsigned characters
 *
 * This function takes as input a reference to an array of unsigned characters
 * and the number of elements contained in the array. 
 * This will evaluate the mean, rounded down to the nearest integer.
 *
 * @param data The reference to an array of unsigned characters to analyze
 * @param length The number of elements in the parameter "data"
 *
 * @return The mean (average) of the parameter "data"
 */
unsigned char find_mean(unsigned char data[], unsigned int length);

/**
 * @brief Evaluates the maximum for an array of unsigned characters
 *
 * This function takes as input a reference to an array of unsigned characters
 * and the number of elements contained in the array. 
 * This will evaluate the maximum.
 *
 * @param data The reference to an array of unsigned characters to analyze
 * @param length The number of elements in the parameter "data"
 *
 * @return The maximum of the parameter "data"
 */
unsigned char find_maximum(unsigned char data[], unsigned int length);

/**
 * @brief Evaluates the minimum for an array of unsigned characters
 *
 * This function takes as input a reference to an array of unsigned characters
 * and the number of elements contained in the array. 
 * This will evaluate the minimum.
 *
 * @param data The reference to an array of unsigned characters to analyze
 * @param length The number of elements in the parameter "data"
 *
 * @return The minimum of the parameter "data"
 */
unsigned char find_minimum(unsigned char data[], unsigned int length);

/**
 * @brief Sorts an array of unsigned characters in descending order
 *
 * This function takes as input a reference to an array of unsigned characters
 * and the number of elements contained in the array. 
 * This will sort the elements in descending order by implementing bubble sort.
 *
 * @param data The reference to an array of unsigned characters to analyze
 * @param length The number of elements in the parameter "data"
 *
 * @return void, but the array passed in as the parameter "data" will be sorted in descending order
 */
void sort_array(unsigned char data[], unsigned int length);

#endif /* __STATS_H__ */
