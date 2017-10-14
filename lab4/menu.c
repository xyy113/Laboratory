#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "linktable.h"
#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10
int ShowAllCmd();
int Help();
int Add();
int Sub();
int Multi();
int Divide();
int Time();
int Power();
int Quit();
typedef struct DataNode
{
    tLinkNode * pNext;
    char* cmd;
    char* desc;
    int (*handler)();
}tDataNode;
tDataNode * FindCmd(tLinkTable *head,char *cmd)
{
    tDataNode *pNode=(tDataNode*)GetHeadNode(head);
    while(pNode!=NULL)
    {
	if(strcmp(pNode->cmd,cmd)==0)
    	{
	    return pNode;
 	}
   	pNode=(tDataNode*)GetNextNode(head,(tLinkNode*)pNode);
    }
    return NULL;
}
int ShowAllCmd(tLinkTable *head)
{
    tDataNode *pNode=(tDataNode*)GetHeadNode(head);
    while(pNode!=NULL)
    {
        printf("%s----%s\n",pNode->cmd,pNode->desc);
        pNode=(tDataNode*)GetNextNode(head,(tLinkNode*)pNode);

    }
    return 0;
}
static tDataNode menu[]=
{
    {(tLinkNode*)&menu[1],"version","menu program v2.5",NULL},
    {(tLinkNode*)&menu[2],"help","this is help cmd!",Help},
    {(tLinkNode*)&menu[3],"add","this is add cmd!",Add},
    {(tLinkNode*)&menu[4],"sub","this is sub cmd",Sub},
    {(tLinkNode*)&menu[5],"mul","this is multi cmd",Multi},
    {(tLinkNode*)&menu[6],"div","this is divide cmd",Divide},
    {(tLinkNode*)&menu[7],"pow","this is power cmd",Power},
    {(tLinkNode*)&menu[8],"time","this is time cmd",Time},
    {(tLinkNode*)NULL,"quit","this is quit cmd",Quit}
};
int InitMenuData(tLinkTable **ppLinkTable)
{
    *ppLinkTable = CreatLinkTable();
    (*ppLinkTable)->Head=(tLinkNode*)&menu[0];
    (*ppLinkTable)->Tail=(tLinkNode*)&menu[8];
    (*ppLinkTable)->SumOfNode=9;
}
tLinkTable *head=NULL;
int main()
{
    InitMenuData(&head);
    printf("Welcome!Use 'help' to get how to use this system.\n");
    while(1)
    {
     	char cmd[CMD_MAX_LEN];
        printf("input a cmd");
        scanf("%s",cmd);
        tDataNode *p=FindCmd(head,cmd);
        printf("%d\n",head->SumOfNode);
        if(p==NULL)
	{
    	    printf("Wrong");
     	    continue;
	}
        printf("%s---%s\n",p->cmd,p->desc);
	if(p->handler!=NULL)
        {
	    p->handler();
	}
    }
}
int Help()
{
    ShowAllCmd(head);
}
int Add()
{
    int a,b;
    printf("input two number:\n");
    scanf("%d%d",&a,&b);
    int c=a+b;
    printf("result is %d+%d=%d",a,b,c);
    return 0;
}
int Sub()
{  
    int a,b;
    printf("input two number:\n");
    scanf("%d%d",&a,&b);
    int c=a-b;
    printf("result is %d-%d=%d",a,b,c);
    return 0;
}
int Multi()
{
    int a,b;
    printf("input two number:\n");
    scanf("%d%d",&a,&b);
    int c=a*b;
    printf("result is %d*%d=%d",a,b,c);
    return 0;
}
int Divide()
{
    int a,b;
    printf("input two number:\n");
    scanf("%d%d",&a,&b);
    int c=a/b;
    printf("result is %d/%d=%d",a,b,c);
    return 0;
}
int Power()
{
    return 0;
}
int Time()
{
    time_t t=time(0);
    char temp[64];
    strftime(temp,sizeof(temp),"%Y%m%d %X %A",localtime(&t));
    puts(temp);
    return 0;
}
int Quit()
{
    exit(0);
}

































































