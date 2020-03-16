#include <iostream>
#include <vector>
using namespace std;

vector<int> A;
int max1 = 0;
int N;

void Find(vector<int> save, vector<int> temp);

int main(void)
{
    cin >> N;

    int a;
    for(int i = 0; i < N; i++)
    {
        cin >> a;
        A.push_back(a);
    }



    for(int i = 0; i < N; i++)
    {
        vector<int> temp = A;
        vector<int> save;
        
        save.push_back(A[i]);
        temp.erase(temp.begin() + i);
        Find(save, temp);
    }

    cout << max1;
    system("pause");
    return 0;
}

void Find(vector<int> save, vector<int> temp)
{
    if(save.size() == N)
    {
        int sum = 0;

        for(int i = 0; i < save.size()-1; i++)
        {
            sum += abs(save[i] - save[i+1]);
        }
        if(max1 < sum)
        {
            max1 = sum;
        }
        
    }
    else
    {
        for(int i = 0; i < temp.size(); i++)
        {
            vector<int> t_save = save;
            vector<int> t_temp = temp;

            t_save.push_back(temp[i]);
            t_temp.erase(t_temp.begin() + i);
            Find(t_save, t_temp);
        }
    }
    
}
