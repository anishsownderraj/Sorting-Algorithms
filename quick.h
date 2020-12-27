#include <inttypes.h>

#include <math.h>
//printf,scanf
#include <stdio.h>
//math macros
#include <stdbool.h>
#include <stdlib.h>

int64_t partition(uint32_t *array, int64_t left, int64_t right, int64_t *stats,
    int64_t moves, int64_t comparisons);

void quick_sort(uint32_t *array, int64_t size, int64_t left, int64_t right,
    int64_t *stats, int64_t moves, int64_t comparisons);
