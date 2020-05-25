#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool visited[51] = {0};
vector<int> whereAt[51];
vector<int> partyPeople[51];
queue<int> que;
void bfs(vector<int> &party);
int N, M;

int main(void)
{
    cin >> N >> M;
    int truth = 0;
    cin >> truth;
    vector<int> party(M + 1, 1); 
    vector<int> knowTruth(N+1, 0);
    for(int i = 0; i < truth; i++)
    {
        int temp;
        cin >> temp;
        knowTruth[temp] = 1;
    }

    int answer = 0;
    for(int i = 0; i < M; i++)
    {
        int howCome = 0;
        bool canTalk = 1;
        cin >> howCome;
        if(howCome == 0) continue;

        for(int j = 0; j < howCome; j++)
        {
            int temp;
            cin >> temp;
            partyPeople[i+1].push_back(temp);
            whereAt[temp].push_back(i + 1);

            if(knowTruth[temp] == 1 && visited[temp] == 0)
            {
                visited[temp] = 1;
                que.push(temp);
            }
        }
    }

    bfs(party);

    for(auto &n : party)
    {
        if(n == 1)
            answer++;
    }
    cout << --answer;
    system("pause");
    return 0;
}
void bfs(vector<int> &party)
{
    while(que.empty() != true)
    {
        int temp = que.front(); que.pop();
        for(auto &n : whereAt[temp])
        {
            for(auto &m : partyPeople[n])
            {
                if(visited[m] == 0)
                {
                    que.push(m);
                    visited[m] = 1;
                }
            }
            party[n] = 0;
        }
    }
}