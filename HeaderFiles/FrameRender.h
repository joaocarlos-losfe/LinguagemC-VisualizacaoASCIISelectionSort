#ifndef FrameRender
#define FrameRender

#include <stdbool.h>

typedef struct 
{
    int width;
    int heigth;
    char **window;

}Frame;


void frameCreation(Frame *frame);
void frameShow(Frame *frame);
void frameUpdate(Frame *frame, bool clear_data);
void frameDrawGeometricObject(Frame *frame, int object);
void framedrawHorizontalLine(Frame *frame, int ls, int cs, int line_length);
void framedrawVerticalLine(Frame *frame, int ls, int cs, int length_height);
void framedrawChar(Frame *frame, int ls, int cs, char ch);

void frameCreation(Frame *frame)
{
	int i = 0;
    int j = 0;

    frame->window = malloc(sizeof(char*) * frame->heigth);

    for(i=0; i< frame->heigth; i++)
        frame->window[i] = malloc(sizeof(char) * frame->width);
    
   for ( i = 0; i < frame->heigth; i++)
   {
       for ( j = 0; j < frame->width; j++)
       {
           frame->window[i][j] = ' ';
       }
   }
   
}

void frameShow(Frame *frame)
{
    int i = 0;
    int j = 0;
    int k = 0;
    for ( i = 0; i < frame->heigth; i++)
    {
        if (i==0 || i== frame->heigth-1)
        {
            for(k=0; k<frame->width; k++)
            {
                printf("%c", '_');
            }

            printf("\n");
        }
        else
        {
            for ( j = 0; j < frame->width; j++)
            {
                if(j==0 || j == frame->width-1)
                {
                    printf("%c", '*');
                }

                printf("%c", frame->window[i][j]);
            }
            printf("\n");
        }
    }
}

void frameUpdate(Frame *frame, bool clear_data)
{
    int i = 0;
    int j = 0;

    if (clear_data)
    {
        for ( i = 0; i < frame->heigth; i++)
        {
            for ( j = 0; j < frame->width; j++)
            {
                frame->window[i][j] = ' ';
            }
        }
    }

}

void framedrawHorizontalLine(Frame *frame, int ls, int cs, int line_length)
{
    int i,j;

    for(j = cs; j< line_length + cs; j++)
    {
        frame->window[ls][j] = '_';
    }

}

void framedrawVerticalLine(Frame *frame, int ls, int cs, int length_height)
{
    int i,j;

    for(i = ls; i< length_height + ls; i++)
    {
        frame->window[i][cs] = '|';
    }

}

void framedrawChar(Frame *frame, int ls, int cs, char ch)
{
    frame->window[ls][cs] = ch;
}

#endif
