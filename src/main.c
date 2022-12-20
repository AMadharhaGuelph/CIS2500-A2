#include "../include/madharhaAnkushA2.h"

#define FUN1 1
#define FUN2 1
#define FUN3 1
#define FUN4 1
#define FUN5 1
#define FUN6 1

int main(int argc, char * argv[]) {
    char *fileStr;
    char *stretched;
    char static2D[MAX_WORDS][MAX_LENGTH];
    int wordCount;
    int puncCount;

    #if FUN1
    fileStr = readFile(argv[1]);
    printf("%s\n\n", fileStr);
    #endif

    #if FUN2
    stretched = stretchMe("hello");
    printf("%s\n\n", stretched);
    #endif

    #if FUN3
    wordCount = splitMe(fileStr, static2D);
    for(int i = 0; i < wordCount; i++) {
        printf("%s\n", static2D[i]);
    }
    printf("%d\n\n", wordCount);
    #endif

    #if FUN4
    puncCount = shrinkMe(fileStr);
    printf("%s\n%d\n\n", fileStr, puncCount);
    #endif

    #if FUN5
    printf("%d\n\n", isItAPalindrome("Mom!;: SIs... ,MaDAm,!!!"));
    #endif

    #if FUN6
    printSuffixes("tho,se, are the mans", 1, "otter");
    #endif

    free(fileStr);
    free(stretched);
    return 0;
}