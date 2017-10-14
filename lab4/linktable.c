
#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"

tLinkTable* CreatLinkTable()
{
    tLinkTable* pLinkTable=(tLinkTable*)malloc(sizeof(tLinkTable));
    if(pLinkTable==NULL)
        return NULL;
    pLinkTable->Head=NULL;
    pLinkTable->Tail=NULL;
    pLinkTable->SumOfNode=0;
    return pLinkTable;
}
int DelLinkTable(tLinkTable* pLinkTable)
{
    if(pLinkTable==NULL)
        return FAILURE;
    while(pLinkTable->Head!=NULL)
    {
        tLinkNode* pNode=pLinkTable->Head;
        pLinkTable->Head=pLinkTable->Head->Next;
        free(pNode);
        pLinkTable->SumOfNode--;
    } 
    pLinkTable->Head=NULL;
    pLinkTable->Tail=NULL;
    free(pLinkTable);
    return SUCCESS;
}
int AddLinkNode(tLinkTable* pLinkTable,tLinkNode* pNode)
{
    if(pLinkTable==NULL||pNode==NULL)
        return FAILURE;
    pNode->Next=NULL;
    if(pLinkTable->Head==NULL)
        pLinkTable->Head=pNode;
    else
    {
  	pLinkTable->Tail->Next=pNode;
        pLinkTable->Tail=pLinkTable->Tail->Next;
    }
    pLinkTable->SumOfNode++;
    return SUCCESS;
}
int DelLinkNode(tLinkTable* pLinkTable,tLinkNode* pNode)
{
    if(pLinkTable==NULL||pNode==NULL)
        return FAILURE;
    tLinkNode* p=pLinkTable->Head;
    if(pLinkTable->Head==pNode)
    {
        pLinkTable->Head=pLinkTable->Head->Next;
        free(p);
  	pLinkTable->SumOfNode--;
    if(pLinkTable->SumOfNode==0)
    {
        pLinkTable->Tail=NULL;
    }
    return SUCCESS;
    }
    while(p!=NULL)
    {
  	if(p->Next==pNode)
        {
	    tLinkNode* q=p->Next;
 	    p->Next=p->Next->Next;
	    free(q);
 	    pLinkTable->SumOfNode--;
 	    if(pLinkTable->SumOfNode==0)
	        pLinkTable->Tail=NULL;
 	    return SUCCESS;
	}
	p=p->Next;
    }
    return FAILURE;
}
tLinkNode* GetHeadNode(tLinkTable* pLinkTable)
{
    if(pLinkTable==NULL||pLinkTable->Head==NULL)
        return NULL;
    return pLinkTable->Head;
}
tLinkNode* GetTailNode(tLinkTable* pLinkTable)
{
    if(pLinkTable==NULL||pLinkTable->Tail==NULL)
        return NULL;
    return pLinkTable->Tail;
}
tLinkNode* GetNextNode(tLinkTable* pLinkTable,tLinkNode *pNode)
{
    if(pLinkTable==NULL||pNode==NULL)
        return NULL;
    tLinkNode* p=pLinkTable->Head;
    while(p!=NULL)
    {
        if(p==pNode)
	{
	    return p->Next;
  	}
        p=p->Next;
    }
    return NULL;
}









































