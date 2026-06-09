#include<stdio.h>
#include<string.h>
int main() {
    char data[50];
    printf("Enter data:");
    scanf("%s", data);

    printf("Stuffed Data: F");
    for(int i=0; data[i]!='\0'; i++)
    {
        if(data[i]=='E')
        {
            printf("E");
        }
        printf("%c", data[i]);
    }
    printf("F");
    return 0;
}