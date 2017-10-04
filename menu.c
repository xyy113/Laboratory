#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include"linklist.h"

int Help();
int Addition();
int Fact();
int SleepCmd();
int EchoCmd();
int TimeCmd();
int Quit();

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

static tDataNode head[] =
{
    {"help","This is a help cmd.",Help,&head[0]},
    {"version","Menu program v1.0",NULL,&head[1]},
    {"add","Addition for two integer.",Addition,&head[2]},
    {"author","The author of this program is Furson.",NULL,&head[3]},
    {"fact","Factorial for one integer.",Fact,&head[4]},
    {"sleep","Sleep several seconds by input value",SleepCmd,&head[5]},
    {"echo","Show what you input in the command line.",EchoCmd,&head[6]},
    {"time","Show the system time.",TimeCmd,&head[7]},
    {"quit","Quit from menu",Quit,NULL}
};

int main()
{
    char cmd[CMD_MAX_LEN];
   
    while(1)
    {
        Help();
        printf("\n");
        printf("Please input a cmd:\n");
        scanf("%s",cmd);
        tDataNode *p=FindCmd(head,cmd);
        if(p==NULL)
        {
            printf("You hava entered a wrong cmd.\n");
            printf("Please use 'help' to get the help!\n");
            continue;
        }
        printf("%s-%s\n",p->cmd,p->desc);
        if(p->handler!=NULL)
            p->handler();
        printf("\n");
    }
    return 0;
}

int Help()
{
    ShowAllCmd(head);
    return 0;
}

int Addition()
{
    int addnum1,addnum2;
    printf("Please input two numbers.\n");
    printf("Use 'Black' or 'Enter' to divide the two numbers.\n");
    scanf("%d",&addnum1);
    scanf("%d",&addnum2);
    printf("The answer of these two numbers is %d.\n",addnum1+addnum2);
 
    return 0;
}

int Fact()
{
    int factnum,factans;
    factans=1;
    printf("Please input a number you want to compute factorial(less than 31).\n");
    scanf("%d",&factnum);
    if(factnum<0)
        printf("Wrong input,abort!\n");
    else
    {
        while(factnum>=1)
        {
            factans *=factnum;
            --factnum;
        }
    }
    printf("The answer is %d.\n",factans);
    return 0; 
}
int SleepCmd()
{
    int i,sleeptime;
    printf("Pleasen input the time you want to sleep(better smaller one):\n");
    scanf("%d",&sleeptime);
    for(i=0;i<sleeptime;++i)
    {
        printf("I hava slept %d seconds.\n",i);
        sleep(1);
    }
    printf("Time to wake up.\n");
    return 0;
}

int EchoCmd()
{
    char ch;
    printf("Please end you input with'CTRL'+'D'(means EOF in UNIX/LINUX).\n");
    while((ch=getchar())!=EOF)
        printf("%c",ch);
    printf("\n");
    return 0;
}

int TimeCmd()
{
    ShowLocalTime();
    return 0;
}

int Quit()
{
    printf("Bye,see you!\n");
    exit(0);
}




















