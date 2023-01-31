//**************************
// Author:  yh
// Time:    2022/1/6
//**************************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void _malloc() {
    int i, n;
    char *buffer;
    srand((unsigned)time(NULL));
    printf("how long do you want the string");
    scanf("%d", &i);
    buffer = (char *) malloc(i + 1);
    if (buffer == nullptr) { exit(1); }
    for(n = 0; n < i; ++n) {
        buffer[n] = rand() % 26 + 'a';
    }
    buffer[i] = '\0';

    printf("random string: %s\n", buffer);

    printf("1\n");
    buffer = (char *) realloc(buffer, 12 * sizeof (char *));
    printf("2\n");

    printf("3\n");
    buffer = (char *) realloc(buffer, 0);
    printf("4\n");

    free(buffer);
    return;
}

void _realloc() {
    int input, n;
    int count = 0;
    int* numbers = NULL;
    int* more_numbers = NULL;

    do {
        printf("enter an integer value (0 to end): ");
        scanf("%d", &input);
        count++;

        more_numbers = (int *) realloc(numbers, count * sizeof(int));

        if(more_numbers != NULL) {
            numbers = more_numbers;
            numbers[count - 1] = input;
        } else {
            free(numbers);
            puts("error realloc memory");
        }


    } while(input != 0);

    printf("numbers entered: ");
    for(n = 0; n < count; ++n) {
        printf("%d", numbers[n]);
    }
    free(numbers);
}

void _cmalloc() {
    int i,n;
    int * pData;

    printf ("Amount of numbers to be entered: ");
    scanf ("%d",&i);
    pData = (int*) calloc (i,sizeof(int));
    if (pData==NULL) {
        exit (1);
    }

    for (n=0;n<i;n++)
    {
        printf ("Enter number #%d: ",n+1);
        scanf ("%d",&pData[n]);
    }

    printf ("You have entered: ");

    for (n=0;n<i;n++) {
        printf ("%d ",pData[n]);
    }
    free (pData);
}

int main() {
    _malloc();
    //_realloc();
    //_cmalloc();
    return 0;
}
