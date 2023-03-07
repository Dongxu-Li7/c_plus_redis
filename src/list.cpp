#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

//创建一个不包含任何结点的新链表
list *listCreate(void) {
    list* l = (list*)malloc(sizeof(list));
    //没有结点
    l->head = NULL;
    l->tail = NULL;
    l->len = 0;
    l->dup = NULL;
    l->free = NULL;
    l->match = NULL;
    return l;
}

//释放给定链表，以及链表中的所有结点
void listRelease(list *l) {
    if(l == NULL) {
        return ;
    }
    //没有head(没有结点)
    if(l->head == NULL) {
        return ;
    }
    //保证了链表是有结点存在的
    //用来移动的指针，指向第一个结点
    listNode*temp = l->head;
    while(temp->next != NULL) {
        temp = temp->next;
        //使用链表对应释放value的free来释放value的值
        if(l->free != NULL) {
            l->free(temp->value);
        }else {
            printf("PIG Redis WARNING : List->free is not define.\n");
        }
        free(temp->prev);
    }
    free(temp);
    l->head = NULL;
    l->tail = NULL;
    free(l);
    l = NULL;
    return;
}


