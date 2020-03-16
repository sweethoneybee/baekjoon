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

    // map ���� ���� Ű���� ã������ �õ��ϸ�, �ڵ����� ������� int�� ��� 0, string�� ��� ""�� �ְ�,
    // Ű���� map�� �� ������ �����ϴ� �� �ϴ�.
    // �״ϱ� �Ѹ����, ������ �ڵ����� map���� �ִ´ٴ� ��.
    cout << "���� Ű�� ����� : " << widget["sibal"] << "\n";
    widget["sibal"]++;
    cout << "������� 1 ���� �� : " << widget["sibal"] << "\n";
    system("pause");
    return 0;
}