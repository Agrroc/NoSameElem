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

//输入一串字符串，使其中没有相同元素，并打印
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
        p=head->next;   //每次输入节点，p都指向链表的第一个节点
        while (p!=NULL) {
            //遍历链表，p指针指向遍历到的当前节点位置，直到链表结束
            if (p->data==ch) {
                //从前往后遍历节点，当输入的字符和当前遍历的节点相同时，跳出循环
                break;
            }
            p=p->next;  //当两者不等时，后移一位
        }
        if (p==NULL) {
            //用头插的方式添加节点
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
