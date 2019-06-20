#include "SLL.hpp"

int at(int index){
    
}

void push_front(int data){
    Node* front = new Node(data);
    if (!head)
        head = front;
    else{
        front->next = head;
        head = front;
    }
    ++len;
}
void push_back(int data){
    Node* back = new Node(data);
    if (!tail)
        tail = back;
    else{
        tail->next = back;
        back = tail;
    }
    ++len;
}
void push(int data, int index){
    Node* mid = new Node(data);
    Node* bef = head;
    for (int k = 0; k < index - 1; k++){
        bef = bef->next;
    }
    mid->next = bef->next;
    bef->next = mid;
}