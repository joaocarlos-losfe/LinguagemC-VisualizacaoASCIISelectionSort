#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


#include "./HeaderFiles/FrameRender.h"

int main()
{
    Frame frame;
    frame.width = 145;
    frame.heigth = 30;

    int array[145];

    int i, j;
    int k = array[0];

    for(i=0; i<140; i++)
    {
        array[i] = 1 + ( rand() % 25);
    }

    frameCreation(&frame);
    frameUpdate(&frame, false);

    framedrawHorizontalLine(&frame, 28, 2, 140);

    for(j=2; j<140; j++)
    {
        system("clear");
        printf("Array value: %d\n", array[j]);
        for(i=27; i> 27 - array[j]; i--)
        {
            //frame.window[i][j] = '|';

           	framedrawChar(&frame, i,j, '|');
        }

        frameShow(&frame);
        usleep(100 * 1000);  
    }
    
    return 0;
}
