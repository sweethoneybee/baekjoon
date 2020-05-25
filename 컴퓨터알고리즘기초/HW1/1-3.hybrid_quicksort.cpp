#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

void getInt(vector<int> &vec, const string &temp);
void quickSort(vector<int> &vec, int p, int r);
void hybridQuickSort(vector<int> &vec, int p, int r);
int partition(vector<int> &vec, int p, int r);
int getMedian(const vector<int> &vec, int p, int r);
void insertionSort(vector<int> &vec);
void insertionSortMedian(vector<pair<int, int>> &vec);
void swapInt(vector<int>& vec, int a, int b);
int main(void)
{
    clock_t start, end;
    float delay;
    srand((unsigned int)time(NULL));
    ifstream in("input1-3.txt");
    ofstream out("output1-3.txt");
    string input;
    vector<int> nums;
    while(getline(in, input))
    {
        getInt(nums, input);
    }

    // quickSort
    /*
    start = clock();
    quickSort(nums, 0, nums.size() - 1);
    end = clock();
    delay = (float)(end - start) / CLOCKS_PER_SEC;
    */
    
    // hybridQuickSort
    start = clock();
    hybridQuickSort(nums, 0, nums.size() - 1);
    end = clock();
    delay = (float)(end - start) / CLOCKS_PER_SEC;
    
    for ( int i = 0, size = nums.size(); i < size; i++ )
    {
        cout << nums[i] << " ";
        out << nums[i] << " ";
    }
    cout << endl << delay;
    out << endl << delay;
    system("pause");
    return 0;
}

void getInt(vector<int> &vec, const string &temp)
{
    int start, end;
    start = end = 0;
    int strSize = temp.length();
    while ( true )
    {
        end = temp.find(" ", start);
        vec.push_back(stoi(temp.substr(start, end - start)));
        if ( end == string::npos )
        {
            return;
        }

        start = end + 1;
    }
}

// r = size - 1
void quickSort(vector<int> &vec, int p, int r)
{
    if ( p < r )
    {
        int q = partition(vec, p, r);
        quickSort(vec, p, q - 1);
        quickSort(vec, q + 1, r);
    }
}
void hybridQuickSort(vector<int> &vec, int p, int r)
{
    if ( p < r )
    {
        if ( r - p + 1 > 10 )
        {
            int q = partition(vec, p, r);
            hybridQuickSort(vec, p, q - 1);
            hybridQuickSort(vec, q + 1, r);
        }
        else
        {
            insertionSort(vec);
        }
    }
}
int partition(vector<int> &vec, int p, int r)
{
    // for quickSort
    /*
    int pivot, pivotIndex;
    pivot = vec[r];
    pivotIndex = r;
    */

    // for hybridQuickSort
    int pivot, pivotIndex;
    pivotIndex = getMedian(vec, p, r);
    pivot = vec[pivotIndex];

    swapInt(vec, r, pivotIndex);
    pivotIndex = r;
    
    int i = p - 1;
    int j;
    for ( j = p; j < pivotIndex; j++ )
    {
        if ( vec[j] <= pivot )
        {
            i += 1;
            swapInt(vec, i, j);
        }
    }
    swapInt(vec, i + 1, j);

    return i + 1;
}
int getMedian(const vector<int> &vec, int p, int r)
{
    // first: value, second: index
    vector<pair<int, int>> temp;
    int ran = rand() % (r + 1);
    temp.push_back(make_pair(vec[ran], ran));

    do
    {
        ran = rand() % (r + 1);
    }
    while ( temp[0].first == vec[ran] && temp[0].second == ran );
    temp.push_back(make_pair(vec[ran], ran));
;   do
    {
        ran = rand() % (r + 1);
    }
    while ( (temp[0].first == vec[ran] && temp[0].second == ran)
           || (temp[1].first == vec[ran] && temp[1].second == ran) );
    temp.push_back(make_pair(vec[ran], ran));

    insertionSortMedian(temp);

    return temp[1].second;
}

void insertionSort(vector<int> &vec)
{
    for ( int i = 1, size = vec.size(); i < size; i++ )
    {
        int temp = vec[i];
        int pre = i - 1;
        while ( pre >= 0 && vec[pre] > temp )
        {
            vec[pre + 1] = vec[pre];
            pre--;
        }
        vec[pre + 1] = temp;
    }
}
void insertionSortMedian(vector<pair<int, int>> &vec)
{
    for ( int i = 1, size = vec.size(); i < size; i++ )
    {
        pair<int, int> temp = vec[i];
        int pre = i - 1;
        while ( pre >= 0 && vec[pre].first > temp.first )
        {
            vec[pre + 1] = vec[pre];
            pre--;
        }
        vec[pre + 1] = temp;
    }
}
void swapInt(vector<int>& vec, int a, int b)
{
    int temp = vec[a];
    vec[a] = vec[b];
    vec[b] = temp;
    return;
}