#include<stdio.h>
#include<stdlib.h>

int main()
{
    char cmd[128];
    while(1)
    {
        scanf("%s",cmd);
        if(!strcmp(cmd,"help"))
        {
            printf("This is a help file!");
        }
        else if(!strcmp(cmd,"hello"))
        {
            printf("Hello!");
        }
        else if(!strcmp(cmd,"phone"))
        {
            printf("You can call 010-82934932!");
        }
        else if(!strcmp(cmd,"mail"))
        {
            printf("You can send a mail!");
        }
        else if(!strcmp(cmd,"New"))
        {
            printf("You can new a file");
        }
        else if(!strcmp(cmd,"Delete"))
        {
            printf("You can delete a file");
        }
        else if(!strcmp(cmd,"Update"))
        {
            printf("You can update a file");
        }
        else if(!strcmp(cmd,"find"))
        {
            printf("You can find a file");
        }
        else
        {
            printf("WRONG");
        }
    }
    return 0;
}
