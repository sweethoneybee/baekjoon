#include <iostream>
using namespace std;

int main(void)
{

    cin.tie(NULL);
    ios::sync_with_stdio(false);    
    int T, result, A, B;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cin >> A >> B;
        result = A+B;
        cout << result << "\n";
    }
    system("pause");
    return 0;
}