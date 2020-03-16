#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int tSize = truck_weights.size();
    queue<int> que;
    queue<int> in;
    queue<int> inTime;
    for(int i = 0; i < tSize; i++) que.push(truck_weights[i]);
    
    int time = 0;
    int can = weight;
    int index = 0;
    vector<int> cnt;
    
    inTime.push(++time);
    in.push(que.front());
    can -= que.front();
    que.pop();
    
    while(in.empty() != true)
    {
        int tempTime = time;
        if(can >= que.front() && que.empty() != true)
        {
            can-=que.front();
            in.push(que.front());
            inTime.push(time++);
            que.pop();
        }
        
        if(tempTime - inTime.front() == bridge_length)
        {
            can += in.front();
            in.pop();
            inTime.pop();
            
            if(can >= que.front() && que.empty() != true)
            {
                can -= que.front();
                in.push(que.front());
                inTime.push(time);
                que.pop();
            }
            time++;
        }
        
        if(tempTime == time) time++;
    }
    
    
    answer = time;
    return answer;
}

int main(void)
{
    vector<int> temp;
    temp.push_back(7);
    temp.push_back(4);
    temp.push_back(5);
    temp.push_back(6);
    solution(2, 10, temp);
    system("pause");

    return 0;
}