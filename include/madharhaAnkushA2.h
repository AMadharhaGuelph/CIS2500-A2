/* 
  Student Name: Ankush Madharha
  Student ID: 1172859
  Due Date: March 6, 2022 
  Course: CIS*2500 
 
  I have exclusive control over this submission via my password. 
  By including this header comment, I certify that: 
   1) I have read and understood the policy on academic integrity. 
   2) I have completed Moodle's module on academic integrity. 
   3) I have achieved at least 80% on the academic integrity quiz 
  I assert that this work is my own. I have appropriate acknowledged 
  any and all material that I have used, be it directly quoted or 
  paraphrased. Furthermore, I certify that this assignment was written 
  by me in its entirety. 
*/

#ifndef MADHARHAANKUSH_H
#define MADHARHAANKUSH_H

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// MACROS
#define MAX_LENGTH 20
#define MAX_WORDS 50

// FUNCTION DECLARATIONS
char *readFile(char *filename);

char *stretchMe(char *aStringToStretch);

int splitMe(char *aStringToSplit, char static2D[MAX_WORDS][MAX_LENGTH]);

int shrinkMe (char *aStringToShrink);

bool isItAPalindrome (char *aString);

void printSuffixes(char *aString, int whichWord, char *desiredSuffix);

#endif

/*
Code to allocate an array if strings

char** sptr; 
int num = 3; 
int i; 
sptr = malloc(sizeof(char*) * num); 
for(i = 0; i < num; i++) { 
     sptr[i] = malloc(sizeof(char) * 4); 
     strcpy(sptr[i], "cat"); 
}

for(i = 0; i < num; i++) { 
     printf("%s\n", sptr[i]); 
}
*/

/*
2D array
int** iptr;
int i, j;

iptr = malloc(sizeof(int*) * 10);

for(i = 0; i < 10; i++) {
    iptr[i] = malloc(sizeof(int) * 15);
}

for(i = 0; i < 10; i++) {
    for(j = 0; j < 15; j++) {
        iptr[i][j] = i + j;
        printf("%02d", iptr[i][j]);
    }
    printf("\n");
}
*/

/*
Dynamically allocates truct

int main()
{
    struct data {
        int count;
        float total;
    }
    struct data *aPtr;    // pointer to structure of type struct data
    aPtr = malloc(sizeof(struct data));    // allocate enough memory to hold a structure of type data

    // Pointer references element in structure
    aPtr -> count = 10;
    aPtr -> total = 3.5;

    printf("%d %f\n", aPtr->count, aPtr->total);
}
*/
