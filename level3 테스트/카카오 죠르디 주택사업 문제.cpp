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
        // ���
        if(input[2] == 0)
        {
            //��ռ�ġ
            if(input[3] == 1)
            {
                // �ٴ�
                if(y == 0)
                {
                    pic[x][y] = 0;
                }
                //�ٴ��� �ƴ�
                else if(pic[x][y-1] == 0 || pic[x][y-1] == 1)
                {
                    pic[x][y] = 0;
                }
            }
            //��ջ���
            else if(input[3] == 0)
            {
                //���� ���� ������
                if(pic[x][y+1] != 1)
                {
                    pic[x][y] = -1;
                }
                //���� ���� �ִٸ�
                else if(pic[x][y+1] == 1)
                {
                    // �� ������
                    if(x == 0)
                    {
                        if(pic[x+1][y] == 0)
                        {
                            pic[x][y] = -1;
                        }
                    }
                    // �߰�
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
                    
                    // ������
                    else if( x == n)
                    {
                        
                    }
                }
            }
        }
        
        //��
        else if(input[2] == 1)
        {
            //����ġ
            if(input[3] == 0)
            {
                
            }
            //�� ����
            else if(input[3] == 0)
            {
                
            }
        }
    }
    return answer;
}