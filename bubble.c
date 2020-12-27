#include "bubble.h"

// BUBBLE SORT
void bubble_sort(uint32_t *array, uint32_t size, uint32_t *stats) {
  // Vars to keep track of
  uint32_t temp_val;
  uint32_t counter_moves = 0;
  uint32_t counter_comparisons = 0;

  // Breaks when we reach the end index of our list
  for (uint32_t i = 0; i < size - 1; i++)

  {
    // Set j to last index
    uint32_t j = size - 1;
    // True when j has a greater index than i
    while (j > i) {
      // Increment comparisons by 1
      counter_comparisons++;
      // Swap if an element at a greater index is smaller than element at a lower index
      if (array[j] < array[j - 1]) {
        // Swap is 3 moves
        counter_moves += 3;

        // Swap
        temp_val = array[j];
        array[j] = array[j - 1];
        array[j - 1] = temp_val;
      }
      // Decrement j by 1
      j -= 1;
    }
  }
  // Store moves and comparisons
  stats[0] = counter_moves;
  stats[1] = counter_comparisons;
}
