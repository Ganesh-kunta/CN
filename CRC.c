#include<stdio.h>
#include<string.h>
int main(){
    char data[100], gen[100];
    int i,j,g,d;
    printf("enter the data:");
    scanf("%s",data);
    printf("enter the gen:");
    scanf("%s",gen);
    char original[100];
    strcpy(original, data);
    g = strlen(gen);
    d = strlen(data);
    for(i=0;i<g-1;i++){
        data[d+i] = '0';
    }
    data[d+g-1] = '\0';
    for(i=0;i<d;i++){
        if(data[i]=='1'){
            for(j=0;j<g;j++){
                data[i+j] = (data[i+j]==gen[j]) ? '0' : '1';
            }
        }
    }
    printf("crc:");
    for(i=d;i<d+g-1;i++){
        printf("%c",data[i]);
    }
    printf("\nTransmitted frame: ");
    printf("%s", original);   
    for(i = d; i < d + g - 1; i++){
    printf("%c", data[i]);
}
    return 0;
}