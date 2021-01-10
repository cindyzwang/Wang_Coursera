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
 * @file stats.c
 * @brief This file contains a data set and functions to analyze it.
 * 
 * This file contains an array of unsigned characters to use as a data set.
 * An analysis is run on this data set to find the mean, median, maximum, and minimum.
 * This information as well as the original data set and the processed data set are
 * then printed to the console.
 *
 * @author Cindy Wang
 * @date Dec 23, 2020
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

/* Add other Implementation File Code Here */
void print_statistics(unsigned char data[], unsigned int length) {
  sort_array(data, length);
  unsigned char median = find_median(data, length);
  unsigned char mean = find_mean(data, length);
  unsigned char maximum = find_maximum(data, length);
  unsigned char minimum = find_minimum(data, length);
  
  PRINTF("Median: %i\n", median);
  PRINTF("Mean: %i\n", mean);
  PRINTF("Maximum: %i\n", maximum);
  PRINTF("Minimum: %i\n", minimum);
};

void print_array(unsigned char data[], unsigned int length) {
  for (int i = 0; i < length - 1; i++) {
    PRINTF("%i, ", data[i]);
  }
  PRINTF("%i\n", data[length - 1]);
};

unsigned char find_median(unsigned char sorted_data[], unsigned int length) { 
  // Assumes that the data is already sorted
  unsigned int middle_index = length / 2;
  if (length % 2) {
    // The number of elements is odd, so the median is the average of the middle 2 elements
    // Use int in case the sum of the middle 2 elements is larger than a char
    unsigned int sum = sorted_data[middle_index] + sorted_data[middle_index + 1];
    return (unsigned char) (sum / 2);
  }

  return sorted_data[middle_index];
};

unsigned char find_mean(unsigned char data[], unsigned int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += data[i];
  }

  return sum / length;
};

unsigned char find_maximum(unsigned char sorted_data[], unsigned int length) {
  // Assumes the data is already sorted
  return sorted_data[0];
};

unsigned char find_minimum(unsigned char sorted_data[], unsigned int length) {
  // Assumes the data is already sorted
  return sorted_data[length - 1];
};

void sort_array(unsigned char data[], unsigned int length) {
  // An implementation of bubble sort
  for (int i = 0; i < length; i++) {
    unsigned char swapped = 0;
    for (int j = 1; j < length - i; j++) {
      if (data[j - 1] < data[j]) {
        // swap
        unsigned char temp = data[j];
        data[j] = data[j - 1];
        data[j - 1] = temp;
        if (!swapped) swapped = 1;
      }
    }
    // If no swap occured during this iteration, there the array is sorted
    if (!swapped) break;
  }
};
