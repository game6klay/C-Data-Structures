//
//  main.cpp
//  BinaryTree
//  Jay A. Patel
//  Homework-5
//  jap751
//  N13380395
//  Created by Jay Patel on 11/09/15.
//  Copyright © 2015 Jay Patel. All rights reserved.
//

#include <iostream>
#include <sstream>
using namespace std;

class Node {
public:
    Node (int data) {
        value = data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    int value;
    Node * left;
    Node * right;
    Node * parent;
};

class BinaryTree {
public:
    Node* root;
    void generateEmptyTreeWithSize(int size);
    void printTreeInOrder(Node* node);
    void printTreePostOrder(Node* node);
    void printTreePreOrder(Node* node);
    void saveTreeInOrder(Node* node, int data[]);
    void saveTreePostOrder(Node* node, int data[]);
    void saveTreePreOrder(Node* node, int data[]);
    Node* insertTreeNode(Node* root, int data);
};

char getUserInput(BinaryTree *tree, int tempData[]);
char getUserInput2();

char getUserInput(BinaryTree *tree, int tempData[]) {
    
    cout << "C)\tCreate tree." << endl;
    cout << "P)\tPrint tree." << endl;
    cout << "E)\tEnd." << endl;
    
    char c;
    cin >> c;
    switch (c) {
        case 'C': {
            puts("Create:");
            char ch = getUserInput2();
            int i, size = 0;
            puts("Please enter values for tree, -1 to end list.");
            while(true) {
                cin >> i;
                if(i==-1)
                    break;
                tempData[size] = i;
                size++;
                if(size>100) {
                    puts("Size exceeded!");
                    return c;
                }
            }
            tree->generateEmptyTreeWithSize(size);
            cout << endl;
            switch (ch) {
                case 'I':
                    tree->saveTreeInOrder(tree->root, tempData);
                    break;
                case '-':
                    tree->saveTreePreOrder(tree->root, tempData);
                    break;
                case '+':
                    tree->saveTreePostOrder(tree->root, tempData);
                    break;
            }
            return c;
        }
        case 'P': {
            if(tree->root == NULL) {
                cout << "Please create a tree to print." << endl;
                return c;
            }
            puts("Print:");
            char ch = getUserInput2();
            switch (ch) {
                case 'I':
                    cout << "InOrder Traversal:" << endl;
                    tree->printTreeInOrder(tree->root);
                    cout << endl;
                    cout << endl;
                    break;
                case '-':
                    cout << "PreOrder Traversal:" << endl;
                    tree->printTreePreOrder(tree->root);
                    cout << endl;
                    cout << endl;
                    break;
                case '+':
                    cout << "PostOrder Traversal:" << endl;
                    tree->printTreePostOrder(tree->root);
                    cout << endl;
                    cout << endl;
                    break;
            }
            return c;
        }
        case 'E': {
            puts("End.");
            return c;
        }
        default: {
            puts("Invalid Input!");
            return c;
        }
    }
}

char getUserInput2() {
    
    cout << "I)\tInOrder." << endl;
    cout << "-)\tPreOrder." << endl;
    cout << "+)\tPostOrder." << endl;
    
    char c;
    cin >> c;
    
    return c;
    
}

int main(int argc, const char * argv[]) {
    
    BinaryTree *tree = new BinaryTree();
    
    // int demoSet[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int size = sizeof(demoSet) / sizeof(demoSet[0]);
    
    // tree->generateEmptyTreeWithSize(size);
    // tree->saveTreePostOrder(tree->root, demoSet);
    // tree->printTreePostOrder(tree->root);
    // cout << endl;
    
    int tempData[100];
    
    while (getUserInput(tree, tempData)!='E');
    
    return 0;
}

void BinaryTree::generateEmptyTreeWithSize(int size) {
    for (int i=0; i<size; i++) {
        insertTreeNode(root, i);
    }
}

Node* BinaryTree::insertTreeNode(Node* tempRoot, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }
    if(tempRoot == NULL)  {
        tempRoot = new Node(data);
        return tempRoot;
    }
    if(data <= tempRoot->value ) {
        tempRoot->left = insertTreeNode(tempRoot->left,data);
    }
    else {
        tempRoot->right = insertTreeNode(tempRoot->right,data);
    } 
    return tempRoot;
}

void BinaryTree::printTreeInOrder(Node* node) {
    if(node == NULL)
        return;
    printTreeInOrder(node->left);
    cout << node->value << " ";
    printTreeInOrder(node->right);
}

void BinaryTree::printTreePreOrder(Node* node) {
    if(node == NULL)
        return;
    cout << node->value << " ";
    printTreePreOrder(node->left);
    printTreePreOrder(node->right);
}

void BinaryTree::printTreePostOrder(Node* node) {
    if(node == NULL)
        return;
    printTreePostOrder(node->left);
    printTreePostOrder(node->right);
    cout << node->value << " ";
}


void BinaryTree::saveTreeInOrder(Node* node, int data[]) {
    if(node == NULL)
        return;
    saveTreeInOrder(node->left, data);
    node->value = data[node->value];
    saveTreeInOrder(node->right, data);
}

void BinaryTree::saveTreePreOrder(Node* node, int data[]) {
    if(node == NULL)
        return;
    node->value = data[node->value];
    saveTreePreOrder(node->left, data);
    saveTreePreOrder(node->right, data);
}

void BinaryTree::saveTreePostOrder(Node* node, int data[]) {
    if(node == NULL)
        return;
    saveTreePostOrder(node->left, data);
    saveTreePostOrder(node->right, data);
    node->value = data[node->value];
}