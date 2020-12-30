//header files
#include "binary.h"
#include "bubble.h"
#include "quick.h"
#include "shell.h"
//getopt
#include <getopt.h>
//uint32_t
#include <inttypes.h>
////math macros
#include <math.h>
//printf,scanf
#include <stdio.h>
//calloc
#include <stdlib.h>
//true,false
#include <stdbool.h>
// Options for getop
#define OPTIONS "n:r:p:Absqi"
// -a means all algorithms
// -b bubble
// -s shell
// -q quick
// -i BI
// -p n prints n elements of array
// -r s seed value
// -n c sets array size

// Prototyping
void array_of_random(uint32_t *random, uint32_t size);
void array_of_elements(uint32_t *array, uint32_t *random, uint32_t size);
void *array_create(uint32_t size);

int main(int argc, char **argv) {

  // DEFAULT VALS
  uint32_t print = 100;
  uint32_t array_size = 100;
  uint32_t seed = 8222022;

  bool a_flag = false;
  bool b_flag = false;
  bool s_flag = false;
  bool q_flag = false;
  bool i_flag = false;

  int c = 0;
  // While Loop will terminate once it reaches NULL giving a value of 0
  while ((c = getopt(argc, argv, OPTIONS)) != -1) {
    switch (c) {
    // CASE A
    case 'A':
      a_flag = true;
      break;
    // CASE B
    case 'b':

      b_flag = true;
      break;
    // CASE S
    case 's':
      s_flag = true;
      break;
    // CASE Q
    case 'q':
      q_flag = true;
      break;
    // CASE I
    case 'i':
      i_flag = true;
      break;
    //OPTARGS
    //CASE P
    case 'p':
      print = atoi(optarg);
      break;
    // CASE R
    case 'r':
      seed = atoi(optarg);
      break;
    // CASE N
    case 'n':
      array_size = atoi(optarg);
      break;
    }
  }

  // SEED
  srand(seed);

  if (array_size < print) {
    print = array_size;
  }

  // Initialize random array
  uint32_t *ra = array_create(array_size);
  array_of_random(ra, array_size);

  // ALL SORTS
  if (a_flag) {
    // Set all sorts to true
    i_flag = true;
    q_flag = true;
    s_flag = true;
    b_flag = true;
  }

  // BINARY INSERTION SORT
  if (i_flag) {
    // Case where array size is 0
    if (array_size == 0) {
      printf("Binary Insertion Sort\n");
      printf("%d elements, %d moves, %d compares\n", array_size, 0, 0);
    } else {
      // Initialize array to store moves and comparisons
      uint32_t stats[3];
      // Create Pointer to an array
      uint32_t *ia = array_create(array_size);
      // Stores unsorted numbers in array
      array_of_elements(ia, ra, array_size);
      // Binary Sort called
      binary_sort(ia, array_size, stats);
      // Print Sort name and Stats
      printf("Binary Insertion Sort\n");
      printf(
          "%d elements, %d moves, %d compares", array_size, stats[0], stats[1]);
      for (uint32_t index = 0; index < print; index++) {
        if (index % 7 == 0) {
          printf("\n");
        }
        printf("%13" PRIu32, ia[index]);
      }
      printf("\n");
      // Free memory
      free(ia);
    }
  }
  // QUICK SORT
  if (q_flag) {
    // Case where array size is 0
    if (array_size == 0) {
      printf("Quick Sort\n");
      printf("%d elements, %d moves, %d compares\n", array_size, 0, 0);
    } else {
      // Vars passed into quick sort function
      int64_t moves = 0;
      int64_t comparisons = 0;
      int64_t zero = 0;
      // Initialize array to store moves and comparisons
      int64_t stats[3];
      stats[0] = 0;
      stats[1] = 0;
      // Create Pointer to an array
      uint32_t *qa = array_create(array_size);
      // Stores unsorted numbers in array;
      array_of_elements(qa, ra, array_size);
      // Quick Sort called
      quick_sort(
          qa, array_size, zero, array_size - 1, stats, moves, comparisons);
      // Print Sort name and Stats
      printf("Quick Sort\n");
      printf("%d elements, %lld moves, %lld compares", array_size, stats[0],
          stats[1]);
      for (uint32_t index = 0; index < print; index++) {
        if (index % 7 == 0) {
          printf("\n");
        }
        printf("%13" PRIu32, qa[index]);
      }
      printf("\n");
      // Free memory
      free(qa);
    }
  }
  // SHELL SORT
  if (s_flag) {
    // Case where array size is 0
    if (array_size == 0) {
      printf("Shell Sort\n");
      printf("%d elements, %d moves, %d compares\n", array_size, 0, 0);
    } else {
      // Initialize array to store moves and comparisons
      uint32_t stats[3];
      // Create Pointer to an array
      uint32_t *sa = array_create(array_size);
      // Stores unsorted numbers in array
      array_of_elements(sa, ra, array_size);
      // Shell Sort called
      shell_sort(sa, array_size, stats);
      // Print Sort name and Stats
      printf("Shell Sort\n");
      printf(
          "%d elements, %d moves, %d compares", array_size, stats[0], stats[1]);
      for (uint32_t index = 0; index < print; index++) {
        if (index % 7 == 0) {
          printf("\n");
        }
        printf("%13" PRIu32, sa[index]);
      }
      printf("\n");
      // Free memory
      free(sa);
    }
  }
  // BUBBLE SORT
  if (b_flag) {
    // Case where array size is 0
    if (array_size == 0) {
      printf("Bubble Sort\n");
      printf("%d elements, %d moves, %d compares\n", array_size, 0, 0);
    } else {
      // Initialize array to store moves and comparisons
      uint32_t stats[3];
      // Create Pointer to an array
      uint32_t *ba = array_create(array_size);
      // Stores unsorted numbers in array
      array_of_elements(ba, ra, array_size);
      // Bubble Sort called
      bubble_sort(ba, array_size, stats);
      // Print Sort name and Stats
      printf("Bubble Sort\n");
      printf(
          "%d elements, %d moves, %d compares", array_size, stats[0], stats[1]);
      for (uint32_t inde = 0; inde < print; inde++) {
        if (inde % 7 == 0) {
          printf("\n");
        }
        printf("%13" PRIu32, ba[inde]);
      }
      printf("\n");
      // Free memory
      free(ba);
    }
  }
  // Free memory
  free(ra);
  return 0;
}

// FUNCTION ARRAY CREATE
// returns a pointer to an array we can store elements in
void *array_create(uint32_t size) {
  // Allocate memory for the struct BitVector
  uint32_t *m = (uint32_t *)calloc(size, sizeof(uint32_t));
  // Checks if memory address is valid
  if (!m) {
    exit(0);
  }
  // Return pointer
  return m;
}
// FUNCTION ARRAY OF RANDOM
// Generates an array of random numbers according to our seed value
void array_of_random(uint32_t *random, uint32_t size) {
  for (uint32_t index = 0; index < size; index++) {
    // Genrates a random number
    uint32_t num = rand();
    // Bitmasking with AND
    uint32_t element = (num & 0x3FFFFFFF);
    // Puts random number into array
    random[index] = element;
  }
}
// FUNCTION ARRAY OF ELEMENTS
// Stores the random numbers generated into the array created by array create
void array_of_elements(uint32_t *array, uint32_t *random, uint32_t size) {

  for (uint32_t index = 0; index < size; index++) {
    // Sets the array equal to the random number
    array[index] = random[index];
  }
}
