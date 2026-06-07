#include<stdio.h>
int main() {
    int bucketsize, outputrate, n, i;
    int input[20], bucket=0;
    printf("Enter bucket size: ");
    scanf("%d",&bucketsize);
    printf("Enter output rate: ");
    scanf("%d",&outputrate);
    printf("Enter number of inputs: ");
    scanf("%d",&n);
    printf("Enter input packets:\n");
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&input[i]);
    }
    printf("\ntime\tincoming\tbucket\toutgoing\tremaining\n");
    for(i=0; i<n; i++)
    {
        int incoming = input[i];
        int bucketbefore = bucket;
        if(bucket + incoming > bucketsize)
        {
            int accepted = bucketsize - bucket;
            int overflow = incoming - accepted;
            bucket = bucketsize;
            printf("%d\t%d\t\t%d\t\t-\t\t%d(overflow %d)\n", i+1, incoming, bucketbefore, bucket, overflow);
        }
        else
        {
            bucket += incoming;
            int outgoing = (bucket < outputrate)? bucket: outputrate;
            bucket -= outgoing;
            printf("%d\t%d\t\t%d\t\t %d\t\t%d\n", i+1, incoming, bucketbefore, outgoing, bucket);
        }
    }
    return 0;
}