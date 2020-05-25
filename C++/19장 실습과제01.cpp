#include <iostream>
#include <string>
using namespace std;


int countNeedle(const string& haystack, const string& needle)
{
    int count = 0;
    for(int i = haystack.find(needle, 0); i != string::npos; i = haystack.find("cat", i))
    {
        count++;
        i++;
    }

    return count;
}
int main(void)
{
    string needle = "cat";
    string haystack = "This cat is bigger than that cat. Is it right, my cat?";

    int result = countNeedle(haystack, needle);
    cout << result << endl;
    system("pause");
    return 0;
}