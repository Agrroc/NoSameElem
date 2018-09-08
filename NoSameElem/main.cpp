//
//  main.cpp
//  NoSameElem
//
//  Created by Agrroc-mac on 2018/8/14.
//  Copyright © 2018年 Agrroc-mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>

typedef struct LNode{
    char data;
    struct LNode *next;
}LNode;

void creatNoSameElem(LNode *&head)
{
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;
    LNode *p;
    int n;
    char ch;
    printf("请输入字母的个数：");
//    scanf("%d\n",&n);
    std::cin>>n;
    for(int i=0; i<n; i++)
    {
        printf("请输入字母：");
//        scanf("%c",&ch);
        std::cin>>ch;
        p=head->next;
        while (p!=NULL) {
            if (p->data==ch) {
                break;
            }
            p=p->next;
        }
        if (p==NULL) {
            p=(LNode *)malloc(sizeof(LNode));
            p->data=ch;
            p->next=head->next;
            head->next=p;
        }
    }
}

void travelElem(LNode *head)
{
    LNode *tr=head->next;
    while (tr!=NULL) {
        printf("%c",tr->data);
        tr=tr->next;
    }
    printf("\n");
    return ;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    LNode *head=NULL;
    creatNoSameElem(head);
    travelElem(head);
    return 0;
}
