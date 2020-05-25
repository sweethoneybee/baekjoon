#include <iostream>
#include <random>
using namespace std;

int main(void)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 99);
    cout << dis(gen);

    // random_device rd;
    // mt19937 gen(rd());
    // uniform_int_distribution<int> dis(0, 99);
    // cout << dis(gen);
    // system("pause");
    return 0;
}