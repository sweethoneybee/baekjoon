#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    int pic[n+1][n+1] = {0};
    fill_n(pic[0], sizeof(pic), -1);
    
    int size = build_frame.size();
    for(int i = 0; i < size; i++)
    {
        vector<int>& input = build_frame[i];
        int x = input[0];
        int y = input[1];
        // 기둥
        if(input[2] == 0)
        {
            //기둥설치
            if(input[3] == 1)
            {
                // 바닥
                if(y == 0)
                {
                    pic[x][y] = 0;
                }
                //바닥이 아님
                else if(pic[x][y-1] == 0 || pic[x][y-1] == 1)
                {
                    pic[x][y] = 0;
                }
            }
            //기둥삭제
            else if(input[3] == 0)
            {
                //위에 보가 없는지
                if(pic[x][y+1] != 1)
                {
                    pic[x][y] = -1;
                }
                //위에 보가 있다면
                else if(pic[x][y+1] == 1)
                {
                    // 젤 왼쪽임
                    if(x == 0)
                    {
                        if(pic[x+1][y] == 0)
                        {
                            pic[x][y] = -1;
                        }
                    }
                    // 중간
                    else if(x > 0 && x < n)
                    {
                        if(pic[x-1][y+1] == 1)
                        {
                            pic[x][y] = -1;
                        }
                        else if(pic[x+1][y] == 0)
                        {
                            pic[x][y] = -1;
                        }
                    }
                    
                    // 마지막
                    else if( x == n)
                    {
                        
                    }
                }
            }
        }
        
        //보
        else if(input[2] == 1)
        {
            //보설치
            if(input[3] == 0)
            {
                
            }
            //보 삭제
            else if(input[3] == 0)
            {
                
            }
        }
    }
    return answer;
}