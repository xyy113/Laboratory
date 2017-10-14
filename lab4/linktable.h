#define LINKTABLE_H
#define SUCCESS 0
#define FAILURE -1

typedef struct LinkNode
{
    struct LinkNode *Next;
}tLinkNode;

typedef struct LinkTable
{
    tLinkNode *Head;
    tLinkNode *Tail;
    int SumOfNode;
}tLinkTable;

tLinkTable* CreatLinkTable();
int DelLinkTable(tLinkTable *pLinkTable);
int AddLinkNode(tLinkTable *pLinkTable,tLinkNode* pNode);
int DelLinkNode(tLinkTable *pLinkTable,tLinkNode* pNode);
tLinkNode* GetHeadNode(tLinkTable* pLinkTable);
tLinkNode* GetTailNode(tLinkTable* pLinkTable);
tLinkNode* GetNextNode(tLinkTable* pLinkTable,tLinkNode *pNode);

