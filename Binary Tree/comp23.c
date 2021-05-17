#include<stdio.h>
#include<string.h>
main()
{
    char n1[20],n2[20];
    printf("enter the word: ");
    gets(n1);
    strcpy(n2,n1);
    strrev(n2);
    if(strcmp(n1,n2)==0)
    printf("the word is a palindrome");
    else
    printf("the word is not a palindrome");

}
