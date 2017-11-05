#include<stdio.h>
#include<stdlib.h>
#include"menu.c"

int Quit(int argc,char *argv[])
{
    exit(0);
}
int main(int argc,char *argv[])
{
    MenuConfig("version","XXX V1.0",NULL);
    MenuConfig("quit","Quit from XXX",Quit);

    ExecuteMenu();
}
