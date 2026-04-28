#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int totalframes, windowsize;
    int i;

    printf("Enter total number of frames: ");
    scanf("%d", &totalframes);

    printf("Enter window size: ");
    scanf("%d", &windowsize);

    int received[100] = {0};   

    srand(time(0));

    int base = 0;

    while(base < totalframes)
    {
        printf("\nSending frames: ");

        
        for(i = base; i < base + windowsize && i < totalframes; i++)
        {
            if(received[i] == 0)
                printf("%d ", i);
        }

        printf("\n");

       
        for(i = base; i < base + windowsize && i < totalframes; i++)
        {
            if(received[i] == 0)
            {
                int lost = rand() % 2;

                if(lost)
                {
                    printf("Frame %d lost\n", i);
                }
                else
                {
                    printf("Frame %d received (ACK sent)\n", i);
                    received[i] = 1;
                }
            }
        }

       
        while(received[base] == 1 && base < totalframes)
        {
            base++;
        }
    }

    printf("\nAll frames transmitted successfully!\n");

    return 0;
}