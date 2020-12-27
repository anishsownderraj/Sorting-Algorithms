
#include "binary.h"
#include <math.h>

// BINARY SORT
// Finds the position of an item where it should it go
void binary_sort(uint32_t *array, uint32_t size, uint32_t *stats) {
  // Vars to keep track of
  uint32_t temp_val;
  uint32_t counter_moves = 0;
  uint32_t counter_comparisons = 0;

  // Loops amount of elements in array
  for (uint32_t i = 1; i < size; i++) {
    uint32_t value = array[i];
    uint32_t left = 0;
    uint32_t right = i;

    // Evaluates True when left is less than right
    while (left < right) {
      // Set the mid
      uint32_t mid = left + ((right - left) / 2);
      // Increment comparisons by 1
      counter_comparisons++;
      if (value >= array[mid]) {
        // Set left to mid + 1
        left = mid + 1;
      } else { // Set right to mid
        right = mid;
      }
    }
    for (uint32_t j = i; j > left; j--) {
      // Swap takes 3 moves
      counter_moves += 3;
      // Swap
      temp_val = array[j - 1];
      array[j - 1] = array[j];
      array[j] = temp_val;
    }
  }
  // Store moves and comparisons
  stats[0] = counter_moves;
  stats[1] = counter_comparisons;

  return;
}
