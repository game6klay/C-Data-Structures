//
//  main.cpp
//  MergeSort
//  Jay A. Patel
//  13380395
//  jap751
//  Copyright © 2015 Jay Patel. All rights reserved.
//

#include <iostream>

using namespace std;

void mergeSort(int data[], int arraySize, bool asc, int &counter);
void merge(int data[], int leftSize, int rightSize, bool asc, int &counter);
char getUserInput();
void printArray(int a[]);

int main(int argc, const char * argv[]) {
    while (getUserInput()!='E');
    return 0;
}

char getUserInput() {
    cout << "A)\tSort ascending." << endl;
    cout << "D)\tSort descending." << endl;
    cout << "E)\tExit." << endl;
    char c;
    cin >> c;
    int counter = 0;
    int a[100];
    for (int i=0; i<100; i++) {
        a[i] = -2;
    }
    switch (c) {
        case 'A': {
            puts("Please enter values to sort in ascending order, -1 to end list.");
            int i, tempCounter;
            for(int j=0; j< 100; j++) {
                cin >> i;
                if(i==-1)
                    break;
                a[j] = i;
                tempCounter++;
            }
            mergeSort(a, tempCounter, true, counter);
            cout << "-----------------------------------" << endl ;
            printArray(a);
            cout << "-----------------------------------" << endl  ;
            cout << "Items copied: " << counter << endl;
            cout << endl;
            return c;
        }
        case 'D': {
            puts("Please enter values to sort in descending order, -1 to end list.");
            int i, tempCounter;
            for(int j=0; j< 100; j++) {
                cin >> i;
                if(i==-1)
                    break;
                a[j] = i;
                tempCounter++;
            }
            mergeSort(a, tempCounter, false, counter);
            cout << "-----------------------------------" << endl ;
            printArray(a);
            cout << "-----------------------------------" << endl  ;
            cout << "Items copied: " << counter << endl;
            cout << endl;
            return c;
        }
        case 'E': {
            return c;
        }
        default: {
            puts("Invalid Input!");
        }
    }
    
    return c;
}

void mergeSort(int data[], int arraySize, bool asc, int &counter) {
    int leftSize;
    int rightSize;
    if(arraySize > 1) {
        leftSize = arraySize/2;
        rightSize = arraySize - leftSize;
        mergeSort(data, leftSize, asc, counter);
        mergeSort((data+leftSize), rightSize, asc, counter);
        merge(data, leftSize, rightSize, asc, counter);
    }
}

void merge(int data[], int leftSize, int rightSize, bool asc, int &counter) {
    int copiedLeft = 0;
    int copiedRight = 0;
    int copied = 0;
    int temp[leftSize + rightSize];
    while((copiedLeft < leftSize) && (copiedRight < rightSize)) {
        if (asc) {
            if(data[copiedLeft] < (data+leftSize)[copiedRight]) {
                temp[copied++] = data[copiedLeft++];
                counter++;
            }
            else {
                temp[copied++] = (data+leftSize)[copiedRight++];
                counter++;
            }
        } else {
            if(data[copiedLeft] > (data+leftSize)[copiedRight]) {
                temp[copied++] = data[copiedLeft++];
                counter++;
            }
            else {
                temp[copied++] = (data+leftSize)[copiedRight++];
                counter++;
            }
        }
    }
    while(copiedLeft < leftSize) {
        temp[copied++] = data[copiedLeft++];
        counter++;
    }
    
    while(copiedRight < rightSize) {
        temp[copied++] = (data+copiedLeft)[copiedRight++];
        counter++;
    }
    
    for(size_t i = 0; i < leftSize+rightSize; i++)
        data[i] = temp[i];
    
}

void printArray(int a[]){
    for (int i=0; i< 100; i++) {
        if(a[i]!=-2) {
            cout << a[i] << "\t";
        }
    }
    cout << endl;
}
