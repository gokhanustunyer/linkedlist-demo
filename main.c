#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node{
    float     data;
    Node    * next;
    
};
typedef struct LinkedList{
    int        size;
    Node    * first;
} LinkedList;

void add_node(LinkedList *lst, float value);
void add_node_first(LinkedList *lst, float value);
void delete_node(LinkedList *lst, int index);

Node * allocate();
void print_node(LinkedList lst);

int main(int argc, int *args[]){
    LinkedList lst;
    lst.size = 0;
    lst.first = allocate();

    for (int i=11;i<=20;i++){
        add_node(&lst, i);
    }

    for (int i=10;i>-1;i--){
        add_node_first(&lst, i);
    }

    delete_node(&lst, 0);
    print_node(lst);

    return 0;
}

void add_node(LinkedList *lst, float value){
    Node *p;
    p = lst -> first;
    for (int i=0;i < lst -> size; i++){
        p = p -> next;
    }
    p -> data = value;
    p -> next = allocate();
    lst -> size ++;
}

void add_node_first(LinkedList *lst, float value){
    Node *temp;
    temp = lst -> first;
    lst -> first = allocate();
    lst -> first -> data = value;
    lst -> first -> next = temp;
    lst -> size ++;
}

void delete_node(LinkedList *lst, int index){
    Node *p, *temp;
    p = lst -> first;
    for (int i=1;i<index;i++){
        p = p -> next;
    }
    if (index == 0)
        lst -> first = lst -> first -> next;
    else
        p -> next = p -> next -> next;
    lst -> size --;
}

Node * allocate(){
    return (Node*)malloc(sizeof(Node));
}

void print_node(LinkedList lst){
    Node* p;
    p = lst.first;
    for (int i=0;i<lst.size;i++){
        printf("ELEMENT %d: %lf\n", i, p->data);
        p = p->next;
    }
}
