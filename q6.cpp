#include <iostream>
using namespace std;

#define MAX_SIZE 100

struct MaxPriorityQueue {
    int arr[MAX_SIZE];
    int size;
};

void heapifyDown(MaxPriorityQueue* pq, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<pq->size&&pq->arr[left]>pq->arr[largest])
        largest = left;

    if(right<pq->size&&pq->arr[right]>pq->arr[largest])
        largest = right;

    if(largest!=i) {
        int temp = pq->arr[i];
        pq->arr[i] = pq->arr[largest];
        pq->arr[largest] = temp;
        heapifyDown(pq, largest);
    }
}

void insert(MaxPriorityQueue* pq, int key) {
    if(pq->size==MAX_SIZE) {
        cout<<"Overflow\n";
        return;
    }

    int i = pq->size;
    pq->arr[i] = key;
    pq->size++;

    while(i!=0&&pq->arr[(i-1)/2]<pq->arr[i]) {
        int parent = (i-1)/2;
        int temp = pq->arr[i];
        pq->arr[i] = pq->arr[parent];
        pq->arr[parent] = temp;
        i = parent;
    }
}

int extractMax(MaxPriorityQueue* pq) {
    if(pq->size<=0)
        return -1;

    if(pq->size==1) {
        pq->size--;
        return pq->arr[0];
    }

    int max = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size-1];
    pq->size--;
    heapifyDown(pq, 0);

    return max;
}

int getMax(MaxPriorityQueue* pq) {
    if(pq->size<=0)
        return -1;
    return pq->arr[0];
}

void printPQ(MaxPriorityQueue* pq) {
    cout<<"PQ elements: ";
    for(int i=0;i<pq->size;i++)
        cout<<pq->arr[i]<<" ";
    cout<<"\n";
}

int main() {
    MaxPriorityQueue pq;
    pq.size = 0;

    insert(&pq, 10);
    insert(&pq, 5);
    insert(&pq, 15);
    insert(&pq, 20);

    printPQ(&pq);
    
    cout<<"Max element: ";
    cout<<getMax(&pq);
    cout<<"\n";

    cout<<"Extract Max: ";
    cout<<extractMax(&pq);
    cout<<"\n";

    printPQ(&pq);
    
    cout<<"Extract Max: ";
    cout<<extractMax(&pq);
    cout<<"\n";
    
    printPQ(&pq);

    return 0;
}