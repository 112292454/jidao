#include "dataStruct.h"
node* newNode(int value) {
    node* a;
    a = (node*)malloc(sizeof(node));
    a->next = null;
    a->value = value;
    return a;
}


// 下标从0开始 ,get(0)为首个元素，get(maxint)为最后一个元素
node* get(node* a, int index) {
    for (int i = 0; i <= index; i++) {
        if (a->next == null) {
            break;
        }
        if (i >= 10000) {
            printf("链表长度过万，可能存在环，请检查");
            return a;
        }
        a = a->next;
    }
    return a;
}
// 在index后插入 num；index从0开始 
void add(node* a, int index, int num) {
    a = get(a, index);
    node* temp = newNode(num);
    temp->next = a->next;
    a->next = temp;
}
// 修改a中index处的value
void set(node* a, int index, int value) {
    node* temp = get(a, index);
    temp->value = value;
}
// 删除a中index处元素
void removeNode(node* a, int index) {
    a = get(a, index - 1);
    node* temp = a->next->next;
    free(a->next); 
    a->next = temp;
}
// 释放a后空间
void freeNode(node* a) {
    node* temp;
    while (a->next != null) {
        temp = a->next;
        free(a);
        a = temp;
    }
    free(a);
}
