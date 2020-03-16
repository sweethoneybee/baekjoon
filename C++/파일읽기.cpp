#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
    ofstream myfile;
    myfile.open("example.txt");
    myfile << "Wow.\n";
    myfile << "Writing this to a file.\n";

    myfile.open("example2.txt");
    myfile << "not good\n";
    myfile << "I said, not gooood\n";


    // string line;
    // ifstream myfile;
    // myfile.open("example");
    // if(myfile.is_open())
    // {
    //     while(getline(myfile, line))
    //     {
    //         cout << line << "\n";
    //     }
    //     myfile.close();
    // }
    // else cout << "Unable to open file\n";

    system("pause");
    return 0;
}