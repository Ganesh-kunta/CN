#include<stdio.h>

int main() {
    int bucket=0, size, rate, n, input;

    printf("Enter bucket size: ");
    scanf("%d",&size);

    printf("Enter output rate: ");
    scanf("%d",&rate);

    printf("Enter number of inputs: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        printf("Enter packet size: ");
        scanf("%d",&input);

        bucket += input;

        if(bucket > size) {
            printf("Overflow!\n");
            bucket = size;
        }

        printf("Bucket content: %d\n", bucket);

        bucket -= rate;
        if(bucket < 0) bucket = 0;
    }
    return 0;
}