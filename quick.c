#include "quick.h"
// math macros
#include <math.h>

// FUNCTION PARTITION
// Picks a pivot and divides elements into two sub-arrays around the pivot
int64_t partition(uint32_t *array, int64_t left, int64_t right, int64_t *stats,
    int64_t moves, int64_t comparisons) {
  // Vars to keep track of
  int64_t temp_val;
  int64_t pivot = array[left];
  int64_t low = left + 1;
  int64_t high = right;

  // Evaluate True all the time
  while (true) {
    // Evaluates true when  both conditions are satisfied

    while ((low <= high) && (array[high] >= pivot)) {
      // Increment comparisons by 1
      comparisons++;
      // Decrement high by 1
      high -= 1;
    }
    // Evaluates true when both conditions are satisfied

    while ((low <= high) && (array[low] <= pivot)) {
      // Increment comparisons by 1
      comparisons++;
      // Decrement low by 1
      low += 1;
    }
    // Increment comparisons by 1
    comparisons++;
    if (low <= high) {
      // Swap takes 3 moves
      moves += 3;
      // Swap
      temp_val = array[low];
      array[low] = array[high];
      array[high] = temp_val;
    } else {

      break;
    }
  }
  // Swap
  temp_val = array[left];
  array[left] = array[high];
  array[high] = temp_val;
  // Swap takes 3 moves
  moves += 3;

  // Store moves and comparisons
  // Values are updated
  stats[0] = stats[0] + moves;
  stats[1] = stats[1] + comparisons;
  // Return the index of high
  return high;
}

// FUNCTION QUICK SORT
// Calls partition and itself, so its a recursive function which ends once left >= right
void quick_sort(uint32_t *array, int64_t size, int64_t left, int64_t right,
    int64_t *stats, int64_t moves, int64_t comparisons) {
  if (left < right) {
    // Calls partition
    int64_t index = partition(array, left, right, stats, moves, comparisons);
    // Calls quicksort with index - 1
    quick_sort(array, size, left, index - 1, stats, moves, comparisons);
    // Calls quicksort with index + 1
    quick_sort(array, size, index + 1, right, stats, moves, comparisons);
  }

  return;
}
