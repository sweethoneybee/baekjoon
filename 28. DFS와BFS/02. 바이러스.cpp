#include <iostream>
#include <list>
#include <queue>
using namespace std;

int infectedCount = 0;
class computer
{
public:
    int number;
    list<computer*> adj;
    bool isInfected;
    computer();
    
    void spreadingVirus(queue<int> &number);
};
void VirusProcess(computer* com, queue<int> &number);
void PrintInfectedNumber();
int main(void)
{
    int NUM, edge;
    cin >> NUM >> edge;
    computer com[NUM+1];
    for(int i = 1; i <= NUM; i++)
    {
        com[i].number = i;
        com[i].isInfected = false;
    }

    for(int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;

        com[a].adj.push_back(&com[b]);
        com[b].adj.push_back(&com[a]);
    }

    com[1].isInfected = true;
    queue<int> virusQue;
    virusQue.push(1);
    VirusProcess(com, virusQue);

    PrintInfectedNumber();
    system("pause");
    return 0;
}


computer::computer() : number(0), isInfected(false) {}
void computer::spreadingVirus(queue<int> &number)
{
    for(auto i = adj.begin(); i != adj.end(); i++)
    {
        if((*i)->isInfected == false)
        {
            (*i)->isInfected = true;
            number.push((*i)->number);
            infectedCount++;
        }    
    }
    return;
}
void VirusProcess(computer* com, queue<int> &number)
{
    while(number.empty() != true)
    {
        int infected = number.front();
        number.pop();
        com[infected].spreadingVirus(number);
    }
    return;
}

void PrintInfectedNumber()
{
    cout << infectedCount;
}