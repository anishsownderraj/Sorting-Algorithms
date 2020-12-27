Directions to use my program:

To compile the program run `clang -Wall -Wpedantic -Wextra -Werror sorting.c -o sorting`
To run the program run `./sorting -[Absqi] -[p:(n elements to be printed)] -[n:(array size) -[r:(seed value)]]`

Inputting -p -(elements to be printed) will specify the number of elements to be printed, default val is 100
Inputting -n -(array_size) will specify the size of the array to be sorted, default val is 100
Inputting -r -(seed value) specifies the seed value to our random number generator, default val is 8222022
Inputting -A will run all sorts
Inputting -i will run binary insertion sort
Inputting -q will run quick sort
Inputting -s will run shell sort
Inputting -b will run bubble sort

Using Makefile to run the program:

By typing make or make all both commands `clang -Wall -Wpedantic -Wextra -Werror sorting.c -o sorting`
and `./sorting -[absqi] -[p:(n elements to be printed)] -[n:() -[r:(seed value)]]` will compile and run the program. `make clean` will clear out any executables or object files in your current working directory.

No Make Infer Errors
