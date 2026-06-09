#include<stdio.h>
#include<string.h>
int main() {
    char data[50];
    int count=0;
    printf("Enter bit string: ");
    scanf("%s", data);
    for(int i=0; data[i]!='\0'; i++)
    {
        printf("%c", data[i]);
        if(data[i]=='1')
        {
            count++;
            if(count==5)
            {
                printf("0");
                count=0;
            }
        } 
        else count=0;
    }
    return 0;
}