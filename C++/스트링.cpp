#include <iostream>
#include <string>
using namespace std;

//["<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"]

string temp = "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>";
int main(void)
{
    int from = temp.find("content=");
    int end = temp.find("\n", from);
    from += 9;

    string k = temp.substr(from, end-from -3 );

    int chk = 1;
    int outCount = 0;
    int linkFrom = 1;
    // while(chk == 1)
    // {
    //     cout << "wow\n";
    //     linkFrom = temp.find("a href=");
    //     if(linkFrom != string::npos)
    //     {   
    //         outCount++;
    //         linkFrom += 8;
    //     }
    //     else
    //     {
    //         chk = 0;
    //     }
        
    // }

    linkFrom = temp.find("dfdfdfdfdf");
    if(linkFrom != string::npos)
    {
        cout << "linkFrom : " << linkFrom << "\n";
        cout << "npos : " << string::npos << "\n";
    }
    else
    {
        cout << "NO! \n"; 
    }
    
    system("pause");
    return 0;
}