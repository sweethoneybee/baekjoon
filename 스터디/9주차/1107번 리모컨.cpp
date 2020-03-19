#include <iostream>
#include <vector>
using namespace std;

bool available_button[10] = {0};
int N, M;
int just_push_count = 0;
int smart_count = 0;
const int SUBIN = 100;

int makeCloseChannel(int N, bool available_button[]);
int countChannelDigit(int close_channel);

int main(void)
{
    fill_n(available_button, 10, 1);
    cin >> N >> M;
    if(M != 0)
    {
        int widget;
        for(int i = 0; i < M; i++)
        {
            cin >> widget;
            available_button[widget] = 0;
        }
    }

    just_push_count = abs(N - SUBIN);
    if(M != 10)
    {
        smart_count = makeCloseChannel(N, available_button);
    }
    else
    {
        smart_count = 1000000;
    }
    
    if(just_push_count < smart_count)
    {
        cout << just_push_count;
    }
    else
    {
        cout << smart_count;
    }
    system("pause");
    return 0;
}

int makeCloseChannel(int N, bool available_button[])
{
    int biggest_num = 0;
    int smallest_num = 0;
    for(int i = 0; i < 10; i++)
    {
        if(available_button[i] == 1)
        {
            smallest_num = i;
            break;
        }
    }
    for(int i = 9; i >= 0; i--)
    {
        if(available_button[i] == 1)
        {
            biggest_num = i;
            break;
        }
    }

    vector<int> temp;
    int mod = 10;
    int temp_N = N;
    if(temp_N != 0)
    {
        while(temp_N >= 1)
        {
            int oneDigit = temp_N % mod;
            temp.push_back(oneDigit);
            temp_N /= mod;
        }
    }
    else
    {
        temp.push_back(0);
    }
    

    vector<int> small_one;
    vector<int> big_one;
    int j = temp.size() - 1;
    for( ; j >= 0; j--)
    {
        bool small_chk = 0;
        bool big_chk = 0;
        int i = 1;
        for(; i <= 9; i++)
        {
            if(available_button[temp[j]] == 1)
            {
                small_one.push_back(temp[j]);
                big_one.push_back(temp[j]);
                cout << "temp[j] : " << temp[j] << endl;
                break;
            }

            if(big_chk == 0 && temp[j] + i <= 9 && available_button[temp[j] + i] == 1)
            {
                big_one.push_back(temp[j] + i);
                big_chk = 1;
            }

            if(small_chk == 0 && temp[j] - i >= 0 && available_button[temp[j] - i] == 1)
            {
                small_one.push_back(temp[j] - i);
                small_chk = 1;
            }
        }

        if(small_chk == 0 && big_chk == 1)
        {
            for(int i = 0; i < 10; i++)
            {
                if(available_button[i] == 1)
                {
                    small_one.push_back(i);
                    break;
                }
            }
        }
        if(big_chk == 0 && small_chk == 1)
        {
            for(int i = 9; i >= 0; i--)
            {
                if(available_button[i] == 1)
                {
                    big_one.push_back(i);
                    break;
                }
            }
        }

        if(big_chk == 1 && small_chk == 1)
        {
            break;
        }
    }

    for(int i = 0; i < j; i++)
    {
        big_one.push_back(smallest_num);
        small_one.push_back(biggest_num);
    }

    int big_channel = 0;
    int small_channel = 0;
    int digit = 1;
    for(int i = big_one.size() - 1; i >= 0; i--)
    {
        big_channel += big_one[i] * digit;
        small_channel += small_one[i] * digit;
        digit *= 10;
    }

    cout << "big_channel : " << big_channel << endl;
    cout << "small_channel : " << small_channel << endl;
    int big_num = abs(N - big_channel) + countChannelDigit(big_channel);
    int small_num = abs(N - small_channel) + countChannelDigit(small_channel);
    cout << "big_num : " << big_num << endl;
    cout << "small_num : " << small_num << endl;
    int close_channel;
  
    if(small_num <= big_num)
    {
        close_channel = small_num;
    }
    else
    {
        close_channel = big_num;
    }
    
    cout << "close_channel : " << close_channel << endl;
    return close_channel;
}
int countChannelDigit(int close_channel)
{
    if(close_channel == 0)
    {
        return 1;
    }
    int digit = 0;
    while(close_channel > 0)
    {
        close_channel /= 10;
        digit += 1;
    }

    return digit;
}
