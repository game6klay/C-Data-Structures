//
//  main.cpp
//  Stacks and Queues
//  Homework-3 Stacks and Queues
//  Jay A. Patel
//  N13380395
//  jap751
//  Created by Jay Patel on 10/1/15.
//  Copyright © 2015 Jay Patel. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
using namespace std;


class LinkedList{
public:
    struct Node{
        typedef int index;
        char data;
        Node * next;
    };
    typedef struct Node* nPointer;
    nPointer head;
    LinkedList(){
        head= NULL;
    }
    void insertFirst(char addData);
    nPointer removeFirst();
    void reverseList();
    void printList();
    int size();
    void clearList();
};

void LinkedList::clearList() {
    head= NULL;
}

void LinkedList::printList() {
    nPointer temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << "";
        temp=temp->next;
    }
    cout << endl;
}

void LinkedList::insertFirst(char addData){
    nPointer current = new Node;
    current->next= NULL;
    current->data= addData;
    if (head!= NULL){
        current -> next = head;
        head = current;
    } else {
        head = current;
    };
}

LinkedList::nPointer LinkedList::removeFirst() {
    if(head==NULL) {
        return NULL;
    }
    nPointer current = head;
    head = head -> next;
    return current;
}

/* To get the count of the list entered */
int LinkedList::size() {
    int count = 0;
    nPointer current = head;
    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

class Stack{
    
public:
    LinkedList list;
    void push(char a);
    char pop();
    char peek();
    bool isEmpty();
    void print();
    int size();
    
};

int Stack::size() {
    return list.size();
}

void Stack::print() {
    list.printList();
}

void Stack::push(char addData) {
    list.insertFirst(addData);
}

char Stack::pop() {
    LinkedList::nPointer node =  list.removeFirst();
    if(node!=NULL) {
        return node->data;
    }
    else {
        return NULL;
    }
}

char Stack::peek() {
    if(list.head != NULL) {
        return list.head -> data;
    }
    else {
        return NULL;
    }
}

bool Stack::isEmpty() {
    return list.head == NULL;
}

class Queue{
    
public:
    Stack s1, s2;
    void insert(char a);
    char getFront();
    bool isEmpty();
    int size();
    void print();
};

void Queue::insert(char ch) {
    s1.push(ch);
}

char Queue::getFront() {
    if (s2.isEmpty()) {
        while (!s1.isEmpty()) {
            s2.push(s1.pop());
        }
    }
    return s2.pop();
}

bool Queue::isEmpty() {
    return size() > 0 ? false : true;
}

int Queue::size() {
    int size = 0;
    size = s1.size() + s2.size();
    return size;
}

void reverseString(string str) {
    Stack temp;
    for (int i=0; i<=str.size(); i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            temp.push(str[i]);
        }
        else{
            while (!temp.isEmpty()) {
                cout << temp.pop();
            }
            cout << ' ';
        }
    }
    cout << endl;
}

int main()
{
    string sample1 = "doing homework is fun";
    string sample2 = "dorwering rwe is re";
    string sample3 = "zzzccc ee is re";
    reverseString(sample1);
    reverseString(sample2);
    reverseString(sample3);
    
    Queue queue;
    for(int i=0; i<sample1.size(); i++) {
        queue.insert(sample1[i]);
    }
    for(int i=0; i<sample1.size(); i++) {
        cout << queue.getFront();
    }

}