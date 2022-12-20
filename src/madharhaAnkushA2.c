#include "../include/madharhaAnkushA2.h"

char *readFile(char *filename) {
    // Declare and Intialize Variables
    FILE *fptr = fopen(filename, "r");
    int i = 0;
    char *str = NULL;
    
    // Iterate through file storing individuals characters
    for(char c = getc(fptr); c != EOF; c = getc(fptr)) {
        if(str == NULL) {
            str = malloc(sizeof(char));
            str[0] = c;
        }
        else {
            str = realloc(str, (i + 2) * sizeof(char));
            str[i] = c;
        }
        i++;
    }
    str[i] = '\0';
    // Close file
    fclose(fptr);

    return str;
}

char *stretchMe(char *aStringToStretch) {
    // Declare and/or Initalize variables
    char *stretchedString;
    int *values;
    int i = 0;
    int sum = 0;

    // Allocate aStringToStretch amount of elements
    values = malloc(sizeof(int) * strlen(aStringToStretch)+1);
    // Iterate aStringToStretch length # of times for input
    for(int j = 0; j < strlen(aStringToStretch); j++) {
        // Verify input
        do {
            scanf("%d", &values[i]);
        } while(values[i] <= 0);
        i++;
    }

    // Iterate through values to obtain sum
    for(int j = 0; j < strlen(aStringToStretch); j++) {
        sum += values[j];
    }

    // Allocate sum amount of elements +1 for null character
    stretchedString = malloc(sizeof(char) * sum+1);
    i = 0;
    // Iterate through aStringToStretch characters
    for(int j = 0; j < strlen(aStringToStretch); j++) {
        // Iterate through current element in values array
        for(int k = 0; k < values[j]; k++) {
            // Add the current character to stretchedString
            stretchedString[i] = aStringToStretch[j];
            i++;
        }
    }
    stretchedString[sum] = '\0';

    // Free values array
    free(values);

    return stretchedString;
}

int splitMe(char *aStringToSplit, char static2D[MAX_WORDS][MAX_LENGTH]) {
    // Declare and Initalize variables
    char *temp;
    char *token;
    int i = 0;

    temp = malloc(strlen(aStringToSplit) + 1);
    strcpy(temp, aStringToSplit);

    // Split string
    token = strtok(temp, " \n");
    // Iterate through tokens storing each word in statis2D
    while(token != NULL) {
        strcpy(static2D[i], token);
        i++;
        token = strtok(NULL, " \n");
    }

    free(temp);

    return i;
}

int shrinkMe (char *aStringToShrink) {
    // Declare and Initalize Variables
    int punctCount = 0;
    char *strNoPunct = NULL;
    int j = 0;

    // Allocate one character 
    strNoPunct = malloc(sizeof(char));

    // Iterate through each character 
    for(int i = 0; i < strlen(aStringToShrink); i++) {
        // If current character is puncuation iterate punctCount
        if(aStringToShrink[i] == '.' || aStringToShrink[i] == ':' || \
        aStringToShrink[i] == ';' || aStringToShrink[i] == '?' || aStringToShrink[i] == '!') {
            punctCount++;
        }
        // otherwise add character to strNoPunct
        else {
            if(strNoPunct == NULL) {
                strNoPunct = malloc(sizeof(char));
                strNoPunct[0] = aStringToShrink[i];
            }
            else {
                strNoPunct = realloc(strNoPunct, (j + 2) * sizeof(char));
                strNoPunct[j] = aStringToShrink[i];
            }
            j++;
        }
    }
    // Add null character to end of string
    strNoPunct[j] = '\0';
    // Copy string without punctuation to original string
    strcpy(aStringToShrink, strNoPunct);

    free(strNoPunct);

    return punctCount;
}

bool isItAPalindrome (char *aString) {
    // Declare and Initalize variables
    char *temp;
    char *token;
    char *dst = NULL;
    int j = 0;

    // Allocate memory to temp
    temp = malloc(strlen(aString) + 1);
    strcpy(temp, aString);
    // Convert temp to lowercase
    for(int i = 0; i < strlen(temp); i++) {
        temp[i] = tolower(temp[i]);
    }

    // Split temp into token
    token = strtok(temp, " \n");

    // Iterate through tokens
    while(token != NULL) {
        // Remove punctuation
        shrinkMe(token);
        if(dst == NULL) {
            dst = malloc(strlen(token) + 1);
            dst[strlen(token)] = '\0';
        }
        else {
            dst = realloc(dst, strlen(token) + 1);
            dst[strlen(token)] = '\0';
        }
        
        // Iterate through current token backwards, storing the characters to dst
        for(int i = strlen(token) - 1; i >= 0; i--) {
            dst[j] = token[i];
            j++;
        }
        // Check if dst and current token are the same, return false
        if(strcmp(token, dst) != 0) {
            return false;
        }
        token = strtok(NULL, " \n");
        j = 0;
    }

    // Free memory
    free(temp);
    free(dst);

    // Return true if every word is a palindrome
    return true;
}

void printSuffixes(char *aString, int whichWord, char *desiredSuffix) {
    // Declare and Initalize variables
    char *token;
    char *temp;
    int i = 1;

    // Allocate memory
    temp = malloc(strlen(aString)+1);
    strcpy(temp, aString);

    // Split temp into tokens
    token = strtok(temp, " \n");
    // Iterate through tokens
    while(token != NULL) {
        if(i == whichWord) {
            // Remove punctuation
            shrinkMe(token);
            // Print letters with suffix
            for(int j = 0; j < strlen(token); j++) {
                printf("%c%s\n", token[j], desiredSuffix);
            }
        }
        i++;
        token = strtok(NULL, " \n");
    }
    // Free memory
    free(temp);
}
