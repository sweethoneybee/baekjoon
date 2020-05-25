#include <iostream>
#include <fstream>
#include <queue>
#include <string>
using namespace std;

int min(int x, int y);
void swap(pair<int, int> heap[], int a, int b);
void minHeapify(pair<int, int> heap[], int i);
void buildMinHeap(pair<int, int> heap[]);
pair<int, int> pop(pair<int, int> heap[]);
int leftChild(int i);
int rightChild(int i);
int parent(int i);

// new oper
void push(pair<int, int> heap[], pair<int, int> e);
void getInt(queue<int> &que, const string &temp);
void changeKey(pair<int, int> heap[], int i);

int main(void)
{
    ifstream in("input1-2.txt");
    ofstream out("output1-2.txt");

    string firstLine;
    int k, n; n = 0;
    getline(in, firstLine);
    k = stoi(firstLine);

    queue<int> *que = new queue<int>[k];
    for ( int i = 0; i < k; i++ )
    {
        string temp;
        getline(in, temp);
        getInt(que[i], temp);
        n += que[i].size();
    }

    pair<int, int> *heap = new pair<int, int>[k + 1];
    heap[0].second = 0;
    int *answer = new int[n];

    // get k elements
    for ( int i = 0; i < k; i++ )
    {
        heap[++heap[0].second].first = que[i].front();
        heap[heap[0].second].second = i;
        que[i].pop();
    }
    buildMinHeap(heap);


    int answerIndex = 0;
    for ( int i = 0; i < n; i++ )
    {
        pair<int, int> temp = pop(heap);
        answer[answerIndex++] = temp.first;

        if ( que[temp.second].empty() != true )
        {
            temp.first = que[temp.second].front();
            que[temp.second].pop();

            push(heap, temp);
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << answer[i] << " ";
        out << answer[i] << " ";
    }


    delete[] heap;
    delete[] answer;
    delete[] que;
    system("pause");
    return 0;
}

int min(int x, int y)
{
    if ( x < y ) return x;
    else return y;
}
void swap(pair<int, int> heap[], int a, int b)
{
    pair<int, int> temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
    return;
}
void minHeapify(pair<int, int> heap[], int i)
{
    while ( true )
    {
        int temp = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if(left <= heap[0].second && heap[temp].first > heap[left].first)
        {
            temp = left;
        }

        if(right <= heap[0].second && heap[temp].first > heap[right].first)
        {
            temp = right;
        }

        if(temp == i)
        {
            break;
        }
        swap(heap, temp, i);
        i = temp;
    }
}
void buildMinHeap(pair<int, int> heap[])
{
    for ( int i = (heap[0].second / 2); i >= 1; --i )
    {
        minHeapify(heap, i);
    }
}
pair<int, int> pop(pair<int, int> heap[])
{
    pair<int, int> value;
    value.first = heap[1].first;
    value.second = heap[1].second;

    swap(heap, 1, heap[0].second);
    heap[0].second--;
    minHeapify(heap, 1);
    return value;
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


void push(pair<int, int> heap[], pair<int, int> e)
{
    heap[++heap[0].second] = e;
    changeKey(heap, heap[0].second);
    return;
}
void getInt(queue<int> &que, const string &temp)
{
    int start, end;
    start = end = 0;
    int strSize = temp.length();
    while ( true )
    {
        end = temp.find(" ", start);
        que.push(stoi(temp.substr(start, end - start)));
        if ( end == string::npos )
        {
            return;
        }

        start = end + 1;
    }
}
void changeKey(pair<int, int> heap[], int i)
{
    while ( i != 1 && heap[parent(i)].first > heap[i].first )
    {
        swap(heap, parent(i), i);
        i = parent(i);
    }
}