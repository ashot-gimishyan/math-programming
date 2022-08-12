#include "Stack.h"

int isEmpty()
{
    if (top == 0)
        return 1;
    else
        return 0;
}

void Push(int elem)
{
    Node* ptr = (Node*)malloc(1);
    ptr->data = elem;
    ptr->next = top;
    top = ptr;
}

int Pop()
{
    int elem;
    if (isEmpty()) {
        puts("Stack is empty");
    }
    else {
        Node* ptr = top;
        elem = top->data;
        top = top->next;
        free(ptr);
        return elem;
    }
}
