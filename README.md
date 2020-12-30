# Sorting Analyzer
Implemented the four sorting algorithms Bubble Sort, Shell Sort, Quicksort, and Binary Insertion Sort. Gathered statistics about each sort and its performance such as the size of the array, the number of moves required, and the number of comparisons required(comparisons for elements, not for the logic). User can compare between sorts.
## Getting Started
## Requirements
* C Compiler

## Instructions
1. Clone the Repository using the URL
```sh
$ git clone https://github.com/anishsownderraj/Sorting-Analyzer
```
## Compiling the Program
### Using the Makefile


By typing `make` or `make all` both commands will compile the program.
```sh
$ make
```
`make clean` will clear out any executables or object files in your current working directory.

## Executing the Program
After compiling the program run:

```sh
$ ./sorting -[Absqi] -[p:(number of elements to be printed)] -[n:(array size) -[r:(seed value)]]
```
Inputting -p -(elements to be printed) will specify the number of elements to be printed, default val is 100

Inputting -n -(array_size) will specify the size of the array to be sorted, default val is 100

Inputting -r -(seed value) specifies the seed value to our random number generator, default val is 8222022

Inputting -A will run all sorts

Inputting -i will run binary insertion sort

Inputting -q will run quick sort

Inputting -s will run shell sort

Inputting -b will run bubble sort
## NOTE
Due to the nature of the seed value on different systems, output might be altered slightly.
## Tests

### Sample Input #1
```sh
./sorting -b -n 100
```
### Sample Output #1

![alt text](https://user-images.githubusercontent.com/47997330/103385372-ef085e00-4aae-11eb-9db5-9023c243fbbf.png)


### Sample Input #2
```sh
./sorting -n 1000 -p 10 -r 1 -A
```
### Sample Output #2

![alt text](https://user-images.githubusercontent.com/47997330/103385479-7786fe80-4aaf-11eb-8bab-efd7a81c27cd.png)






