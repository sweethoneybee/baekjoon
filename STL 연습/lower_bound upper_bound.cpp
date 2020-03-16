#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<string> a;
    a.push_back("apple");
    a.push_back("banana");
    a.push_back("canada");
    //a.push_back("delta");
    //a.push_back("eagle");
    a.push_back("fox");
    a.push_back("golf");
    
    cout << (*lower_bound(a.begin(), a.end(), "apple")) << "\n";
    cout << (*upper_bound(a.begin(), a.end(), "delta")) << "\n";

    system("pause");
    return 0;
}