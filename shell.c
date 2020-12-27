#include "shell.h"
#include <string.h>
//math macros
#include <math.h>

// SHELL SORT
void shell_sort(uint32_t *array, uint32_t size, uint32_t *stats) {
  // Vars to keep track of
  uint32_t temp_val;
  uint32_t counter_moves = 0;
  uint32_t counter_comparisons = 0;
  uint32_t static_size = size;
  // Create an array to store our gap values
  uint32_t gap[sizeof(uint32_t) * size];
  memset(gap, 0, sizeof(uint32_t) * size);
  uint32_t index_array = 0;

  // Evaluates true as long as our array size is greater than 1
  while (size > 1) {

    // Calculates gap
    if (size <= 2) {
      // Set size to 1
      size = 1;
    } else {
      // Formula used to calculate gap
      size = (5 * size) / 11;
    }
    // Store our gap value into the array
    gap[index_array] = size;
    // Increment our index by 1
    index_array++;
  }

  // SHELL FUNCTION

  // Loops based off how many gaps we have
  for (uint32_t start = 0; start < index_array + 1; start++) {
    // Sets step to the current gap
    uint32_t step = gap[start];

    // Loops off initial size of the array
    for (uint32_t i = step; i < static_size; i++) {
      // Loops for the amount of comparisons we can do with current gap
      for (uint32_t j = i; j > step - 1; j = j - step) {
        // Increment comparisons by 1
        counter_comparisons++;
        // Swap if an element at a greater index is smaller than element at a lower index
        if (array[j] < array[j - step]) {
          // Swap is 3 moves
          counter_moves += 3;
          // Swap
          temp_val = array[j];
          array[j] = array[j - step];
          array[j - step] = temp_val;
        }
      }
    }
  }
  // Store moves and comparisons
  stats[0] = counter_moves;
  stats[1] = counter_comparisons;
}
