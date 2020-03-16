#include <iostream>
using namespace std;

int main(void)
{
    string a;
    cin >> a;
    int alphabet[255] = {0};
    fill_n(alphabet, 255, -1);

    //baekjoon
    for(int i =0; i < a.length(); i++)
    {
        if(alphabet[int(a[i])] == -1)
            alphabet[int(a[i])] = i;
    }

    for(int i = 'a'; i < 'z' + 1; i++)
    {
        cout << alphabet[i] << ' ';
    }
    system("pause");
    return 0;
}