#include <iostream>
#include <fstream>
using namespace std;

int max(int x, int y);
void swap(int &x, int &y);
void maxHeapify(int heap[], int i);
void buildMaxHeap(int heap[]);
void heapSort(int heap[]);
int pop(int heap[]);
void popAll(int heap[]);
int leftChild(int i);
int rightChild(int i);
int parent(int i);

int main(void)
{
    int heap[101] = {0};
    int input, index;
    int size = 0;
    heap[0] = 0; // heap size;

    while(cin >> input && input != -1)
    {
        heap[++heap[0]] = input;
        size++;
    }

    heapSort(heap);
    for(int i = size; i >= 1; i--)
    {
        cout << heap[i] << " ";
    }

    system("pause");
    return 0;
}

int max(int x, int y)
{
    if(x > y) return x;
    else return y;
}
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
    return;
}
void maxHeapify(int heap[], int i)
{
    while(true)
    {
        int temp = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if(left <= heap[0] && heap[temp] < heap[left])
        {
            temp = left;
        }

        if(right <= heap[0] && heap[temp] < heap[right])
        {
            temp = right;
        }

        if(temp == i)
        {
            break;
        }
        swap(heap[temp], heap[i]);
        i = temp;
        // int leftChildValue = -1;
        // int rightChildValue = -1;
        // if(leftChild(i) <= heap[0])
        //     leftChildValue = heap[leftChild(i)];
        // if(rightChild(i) <= heap[0])
        //     rightChildValue = heap[rightChild(i)];
        // if(heap[i] >= leftChildValue && heap[i] >= rightChildValue) break;
        
        // if(heap[i] < leftChildValue && heap[i] < rightChildValue)
        // {
        //     if(leftChildValue > rightChildValue)
        //     {
        //         swap(heap[i], heap[leftChild(i)]);
        //         i = leftChild(i);
        //     }
        //     else
        //     {
        //         swap(heap[i], heap[rightChild(i)]);
        //         i = rightChild(i);
        //     }
        // }
        // else if(heap[i] < leftChildValue)
        // {
        //     swap(heap[i], heap[leftChild(i)]);
        //     i = leftChild(i);
        // }
        // else if(heap[i] < rightChildValue)
        // {
        //     swap(heap[i], heap[rightChild(i)]);
        //     i = rightChild(i);
        //}
    }

}
void buildMaxHeap(int heap[])
{
    for(int i = (heap[0] / 2); i >= 1; --i)
    {
        maxHeapify(heap, i);
    }
}

void heapSort(int heap[])
{
    buildMaxHeap(heap);
    for(int i = heap[0]; i >= 2; i--)
    {
        swap(heap[1], heap[i]);
        heap[0] -= 1;
        maxHeapify(heap, 1);
    }
}
int leftChild(int i)
{
    return i * 2;
}
int rightChild(int i)
{
    return i * 2 + 1;
}
int parent(int i)
{
    return i / 2;
}
