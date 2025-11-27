#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

int hash(int key){ return key % SIZE; }

void insert(int key){
    int idx = hash(key);
    while(hashTable[idx] != -1) idx = (idx + 1) % SIZE;
    hashTable[idx] = key;
}

int search(int key){
    int idx = hash(key), start = idx;
    while(hashTable[idx] != key){
        idx = (idx + 1) % SIZE;
        if(idx == start) return -1; // not found
    }
    return idx;
}

int main(){
    int rolls[] = {101, 112, 133, 145, 156};
    for(int i=0;i<SIZE;i++) hashTable[i]=-1;
    for(int i=0;i<5;i++) insert(rolls[i]);

    int r;
    printf("Enter Roll No: "); scanf("%d",&r);
    int idx = search(r);
    if(idx != -1) printf("Student Found at Index: %d\n", idx);
    else printf("Student Not Found\n");

    return 0;
}
