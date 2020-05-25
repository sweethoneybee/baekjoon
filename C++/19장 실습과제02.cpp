#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


int main(void)
{
    ifstream fs;
    fs.open("input data.txt");
    vector<string> csv;
    vector<char> gaehang;
    if(fs.is_open())
    {
        string widget;
        while(getline(fs, widget))
        {
            csv.push_back(widget);
        }

        vector<char> word;
        for(int i = 0, end = widget.length(); i < end; i++)
        {
            if((widget[i] >= 'A' && widget[i] <= 'Z') || (widget[i] >='a' && widget[i] <= 'z') || widget[i] == ' ')
            {
            }
            else
            {
                word.push_back(widget[i]);
            }
        }

        for(int j = 0; j < csv.size(); j++)
        {
            cout << "what is gaehang among \"";
            for(int i = 0, end = word.size(); i < end; i++)
            {
                cout << "\'" << word[i] << "\'";
                if(i + 1 != end)
                {
                    cout << ", ";
                }
            }
            cout << endl;
            char input;
            cin >> input;

            gaehang.push_back(input);
        }
        fs.close();
    }

    for(int i = 0, end = csv.size(); i < end; i++)
    {
        int index = csv[i].find(gaehang[i], 0);
        csv[i].erase(index, 1);
    }

    for(int i = 0, end = csv.size(); i < end; i++)
    {
        cout << csv[i] << endl;
    }


    system("pause");
    return 0;
}