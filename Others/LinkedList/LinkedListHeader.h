//
//  LinkedListHeader.h
//  linkedlistTest
//
//  Created by MAC on 2022/11/07.
//  Copyright © 2022 MAC. All rights reserved.
//

#ifndef LinkedListHeader_h
#define LinkedListHeader_h

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node *next;
    int value;
}Node;

int isEmpty(Node *N);
void showListItem(Node *head);
Node AddItem(Node *head, int value);
void AddItematLast(Node *head, int value);
Node FindItem(Node *head, int item);
void DeleteFirstItem(Node *head);
void DeleteItem(Node *head, int item);
void MakeListEmpty(Node *head);



#endif /* LinkedListHeader_h */
