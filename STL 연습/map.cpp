#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
using namespace std;


int main(void)
{
    map<int, string> temp;
    temp.insert(pair<int, string>(1, "wow"));
    temp[1] = "not wow";
    temp.insert(pair<int, string>(2, "Jeong"));
    temp.insert(pair<int, string>(3, "amazing"));
    temp.insert(pair<int, string>(6, "six"));
    temp.insert(pair<int, string>(7, "seven"));

    // for(map<int, string>::iterator i = temp.find(1); i != temp.upper_bound(7) ; i++)
    // {
    //     cout << i-> first << ", " << i->second << "\n";
    // }
    
    map<string, int> widget;
    widget.insert(make_pair("jeong", 1));
    widget.insert(make_pair("hyun", 2));

    // map 에서 없는 키값을 찾으려고 시도하면, 자동으로 밸류값에 int의 경우 0, string의 경우 ""을 넣고,
    // 키값이 map에 들어간 것으로 간주하는 듯 하다.
    // 그니깐 한마디로, 없으면 자동으로 map에다 넣는다는 뜻.
    cout << "없는 키의 밸류값 : " << widget["sibal"] << "\n";
    widget["sibal"]++;
    cout << "밸류값에 1 더한 것 : " << widget["sibal"] << "\n";
    system("pause");
    return 0;
}