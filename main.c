#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE{
    char szData[64];

    struct NODE* next;

}NODE;

NODE* g_pHead = NULL;

void PrintList(){

    NODE* p_Head = g_pHead;

    while (p_Head != NULL){
        printf("[%p] %s,next[%p]\n",p_Head,p_Head->szData,p_Head->next);
        p_Head = p_Head->next;
    }

}

void InsertNewNodeAtsHead(char* pszData){

    NODE* pNode = (NODE*) malloc(sizeof(NODE));
    memset(pNode,0,sizeof (NODE));

    strcpy_s(pNode->szData,sizeof (pNode->szData),pszData);

    if(g_pHead == NULL){
        g_pHead = pNode;
    }else{
        pNode->next = g_pHead;
        g_pHead = pNode;
    }
}

void InsertNewNodeAtTail(char* pszData){
    NODE* pTmp = g_pHead;
    while (pTmp->next != NULL){
        pTmp = pTmp->next;
    }

    NODE* pNode = (NODE*) malloc(sizeof(NODE));
    memset(pNode,0,sizeof (NODE));
    strcpy_s(pNode->szData,sizeof (pNode->szData),pszData);

    pTmp->next = pNode;
};

void Delete(){
    
    NODE* p_Head = g_pHead;

    while (p_Head != NULL){
        NODE* pDelete = p_Head;
        p_Head = p_Head->next;

        printf("Delete: [%p] %s\n", pDelete, pDelete->szData);

        free(pDelete);
    }
}


int main() {

    InsertNewNodeAtsHead("TEST01");
    PrintList();

    InsertNewNodeAtsHead("TEST02");
    PrintList();

    InsertNewNodeAtTail("HI");
    PrintList();

    Delete();

    return 0;


}
