#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int totalframes, i, loss;
    printf("Enter total number of frames: ");
    scanf("%d", &totalframes);
    srand(time(0));
    for(i = 0; i < totalframes; i++)
    {
        printf("\nSending Frame %d\n", i);
        loss = rand() % 2;
        if(loss)
        {
            printf("Frame %d Lost\n", i);
            printf("Retransmitting Frame %d\n", i);
        }
        printf("ACK received for Frame %d\n", i);
    }
    printf("\nAll Frames Transmitted Successfully!\n");
    return 0;
}