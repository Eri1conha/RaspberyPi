#include <stdio.h>
#include <stdlib.h>



typedef struct box{

    int data;
    struct box *next;

}block;

typedef struct fila{

    int counter;
    block* head;
    block* rear;

}queue;


block* create_block(int data){

    block* new_block = (block*) malloc(sizeof(block));
    new_block->next=NULL;
    new_block->data=data;
    return new_block;
}


queue* create_queue(){

    queue* new_queue = (queue*) malloc(sizeof(queue));
    new_queue->counter=0;
    new_queue->head=NULL;
    new_queue->rear=NULL;
    return new_queue;
}


void enqueue(int data,queue* que){

    block* new = create_block(data);

    if(que->head==NULL && que->rear==NULL){
        que->rear = que->head = new;
    }

    else {
        que->rear->next = new;
        que->rear=new;
    }

    que->counter++;
}



int dequeue(queue*que){

    block* temp=que->head;
    que->head=que->head->next;
    int data=temp->data;
    free(temp);
    que->counter--;

    if(que->head==NULL){
        que->rear=NULL;
    }
    return data;
}


void printar(queue que){

    while(que.head!=NULL){
        printf("%d->",que.head->data);
        que.head=que.head->next;
    }
    printf("\n\n");
}



void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[largest])
        largest = left;

    if (right < n && arr[right] < arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}



void priority(queue *que){

    int size=que->counter;

    int array[size];

    for (int i = 0; i < size ; ++i) {
        array[i] = dequeue(que);
    }

    heapSort(array,size);

    for (int i = 0; i < size; ++i) {
        enqueue(array[i],que);
    }
}







int main() {

    return 0;
}
