#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    
    int width;
    int height;

    if(x - 0 < w - x) width = x-0;
    else width = w - x;

    if(y - 0 < h - y) height = y - 0;
    else height = h - y;

    if(width < height) cout << width;
    else cout << height;

    system("pause");
    return 0;
}