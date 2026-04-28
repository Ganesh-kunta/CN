#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int totalframes, windowsize;
    int base=0, i, lossflag, loss, ack;
    printf("Enter total no.of frames:");
    scanf("%d", &totalframes);
    printf("Enter window size:");
    scanf("%d", &windowsize);
    srand(time(0));
    while(base < totalframes)
    {
        printf("\nSending frames:");
        for(i < base; i < base + windowsize && i < totalframes; i++)
        {
            printf("%d ", i);
        }
        int lossflag = rand()%2;
        if(lossflag)
        {
            int loss = rand() % windowsize + base;
            if(loss < totalframes)
            {
                printf("\nframe %d lost", loss);
                printf("\nResending from frame %d\n", loss);
                base = loss;
                continue;
            }
        }
        int ack = base + windowsize - 1;
        if(ack >= totalframes)
        {
            ack = totalframes - 1;
        }
        printf("\n ACK received up to frame %d\n", ack);
        base = ack + 1;
    }
    printf("\n all frames transmitted successfully\n");
    return 0;
}