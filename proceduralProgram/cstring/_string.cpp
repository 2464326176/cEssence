//**************************
// Author:  yh
// Time:    2022/1/3
//**************************
#include <stdio.h>
#include <string.h>
#include <errno.h>

struct {
    char name[40];
    int age;
}person, person_copy;

void _token() {


}

void _memcpy() {
    char myName[] = "pierre de fermat";

    memcpy(person.name, myName, strlen(myName) + 1);
    person.age = 46;

    memcpy(&person_copy, &person, sizeof(person));
}

void _memmove() {
    char str[] = "memmove can be very useful......";
    memmove(str+20, str+15, 11);
}

void _strerror ()
{
    FILE * pFile;
    pFile = fopen ("unexist.ent","r");
    if (pFile == NULL)
        printf ("Error opening file unexist.ent: %s\n",strerror(errno));
}

void _memchr() {
    char *pCh;
    char str[] = "example string";
    pCh = (char *)memchr(str, 'e', strlen(str));
    if(pCh != NULL) {
        printf("p fount at position %d\n", pCh - str + 1);
    } else {
        printf("p not found");
    }
}

void _strchr() {
    char str[] = "this is a string!";
    printf("s in %s position: \n", str);
    char *pCh;
    pCh = strchr(str, 's');
    while(pCh != NULL) {
        printf("p fount at position %d\n", pCh - str + 1);
        pCh = strchr(pCh + 1, 's');
    }
}

void _strstr() {
    char str[] ="This is a simple string";
    char * pch;
    pch = strstr (str,"simple");
    if (pch != NULL)
        strncpy (pch,"sample",6);
    puts (str);
}
int _strcspn ()
{
    char str[] = "fcba73";
    char keys[] = "1234567890";
    int i;
    i = strcspn (str,keys);
    printf ("The first number in str is at position %d.\n",i+1);
    return 0;
}

int _strspn ()
{
    int i;
    char strtext[] = "129th";
    char cset[] = "1234567890";

    i = strspn (strtext,cset);
    printf ("The initial number has %d digits.\n",i);
    return 0;
}

int _strpbrk ()
{
    char str[] = "This is a sample string";
    char key[] = "aeiou";
    char * pch;
    printf ("Vowels in '%s': ",str);
    pch = strpbrk (str, key);
    while (pch != NULL)
    {
        printf ("%c " , *pch);
        pch = strpbrk (pch+1,key);
    }
    printf ("\n");
    return 0;
}

int main() {
    //_strerror();
    //_memchr();
    //_strchr();
    _strstr();

    return 0;
}