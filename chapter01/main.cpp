#include <iostream>

using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

//初始化带头结点的单链表
void InitList(LinkList &L){
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
}

//头插法建立单链表
bool HeadInsert(LinkList &L){
    int num;
    cin >> num;
    while (num != -1){
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = num;
        s->next = L->next;
        L->next = s;
        cin >> num;
    }
    return true;
}

//尾插法建立单链表
bool RearInsert(LinkList &L) {
    LNode *p,*r = L;
    int num;
    cin >> num;
    while (num != -1){
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = num;
        s->next = r->next;
        r->next = s;
        r = r->next;
        cin >> num;
    }
    return true;
}

//按值查找节点
LNode *GetNode(LinkList &L,int e){
    LNode *s = L;
    while(s->next != NULL && s->data != e){
        s = s->next;
    }
    if (s->data = e){
        return s;
    }
    else
        return 0;
}

//按位查找节点
LNode *LocateNode(LinkList &L,int e){
    LNode *s = L;
    for (int i = 0; i < e; ++i) {
        s = s->next;
    }
    return s;
}

//删除节点
bool DeleteNode(LinkList &L,int i,int &e){
    LNode *s = L,*p;
    int j = 0;
    while(s != NULL && j < i - 1) {
        s = s->next;
        j++;
    }
    if (s == NULL || s->next == NULL){
        return false;
    }
    p = s->next;
    e = p->data;
    s->next = s->next->next;
    free(p);
    return true;
}

//插入节点
bool InsertNode(LinkList &L,int i,int e){
    LNode *s = L,*p;
    int j = 0;
    while(s != NULL && j < i - 1) {
        s = s->next;
        j++;
    }
    if (s == NULL){
        return false;
    }
    p = (LNode*) malloc(sizeof(LNode));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return true;
}

//求表长
int Length(LinkList &L){
    LNode *s = L;
    int i;
    for (i = 0; s->next !=NULL; ++i) {
        s = s->next;
    }
    return i;
}

int main() {
    LinkList L;
    InitList(L);
    HeadInsert(L);
//    RearInsert(L);
//    int e = 0;
//    DeleteNode(L,1,e);
//    cout << e;
    LNode *p = GetNode(L,2);
    cout << p->data << endl;
    p = LocateNode(L,3);
    cout << p->data << endl;
    InsertNode(L,1,222222);
    int length = Length(L);
    cout << length;
    return 0;
}
