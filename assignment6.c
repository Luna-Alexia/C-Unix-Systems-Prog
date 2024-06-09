#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 



// fxn to reverse elements within array
void PrintArray(int *array, int size) {
    printf("Array elements: ");
    for (int i = size - 1; i >= 0; i--) { //prints elements from minus increments
        printf("%d ", array[i]);
    }
    printf("\n");
}

// fxn to add up all the numbers in array
int CalcSum(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i ++){
        sum += array[i];
    }
    return sum;

}

// fxn to find max
int Max(int *array, int size){// iterates through elements
    int maxNum  = array[0];
    for (int i = 1; i < size; i++){ // starts at second element, then continues
        if (array[i] > maxNum){
            maxNum = array[i];
        }
    }
}

// prime fxn
bool Prime(int n) {
    if (n <= 1) { //checks for base case
        return false;
    }
    for (int i = 2; i * i <= n; i++) {// decided to use "trial division" (seen in geeks for geeks website) 
        if (n % i == 0) {// trial = see if divisbile without any remainder, divsion = proccess of dividing the number by each divisor. trial divsion
            return false;
        }
    }
    return true;
}


int main(int argc, char *argv[]) {
    if (argc < 4) {        // menu
        printf("Options: \n     -p: Print array elements\n     -s: Calculate the sum of array elements\n     -m: Find the maximum value in the array\n     -c: Print the prime numbers in the array\n\n");
        return 1; //exit
    }

    char *option = argv[1];
    int size = atoi(argv[2]);

    // memory allocation
   int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("malloc failed\n");
        return 1; // exit
    }


    // intitliaze array
     for (int i = 0; i < size; i++) {
        if (i + 3 < argc) {
            array[i] = atoi(argv[i + 3]);
        } else {
            array[i] = 0;
        }
    }
    
    // calls -p optoin
   if (strcmp(option, "-p") == 0) {
        PrintArray(array, size);
    } 


    // calls -s optoin
    else if (strcmp(option, "-s") == 0){
        int sum = CalcSum(array, size);
        printf("Sum of array elements: %d\n", sum);
    }
    

    // find max -m
    else if (strcmp(option, "-m") == 0){
        int num = Max(array, size);
        printf(" Maximum value in the array: %d\n", num);
    }

 // calls in prime, sorts through the array and calls in boolian fxn
  else if (strcmp(option, "-c") == 0) {
        printf("Prime numbers in the array: ");
        for (int i = 0; i < size; i++) {
            if (Prime(array[i])) {
                printf("%d ", array[i]);
            }
        }
        printf("\n");
    }

    free(array); // frees dynmaic memory

    return 0;
}