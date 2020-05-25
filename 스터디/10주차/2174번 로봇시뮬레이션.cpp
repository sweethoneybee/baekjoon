#include <iostream>
#include <queue>
using namespace std;

int tcount = 0;
int A, B, N, M;
int isOk = 1;
pair<int, int> number;
bool is_here[101][101] = {0};
int dir[101][101] = {0};
int robot_num[101][101] = {0};
int robot_x[101] = {0};
int robot_y[101] = {0};
 // E, N, W, S
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
// int dx[] = {0, -1, 0, 1};
// int dy[] = {1, 0, -1, 0};
void rotate(int robot, char ins);
void changeDir(int robot, char ins, int how_many);
void moveRobot(int robot, int how_many);
int main(void)
{
    cin >> A >> B; // A : x, B : y
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        int x, y;
        char d;
        cin >> x >> y >> d;
        is_here[x][y] = 1;
        if(d == 'E') d = 0;
        else if(d == 'N') d = 1;
        else if(d == 'W') d = 2;
        else if(d == 'S') d = 3;
        dir[x][y] = d;
        robot_num[x][y] = i;
        robot_x[i] = x;
        robot_y[i] = y;
    }

    
    queue<int> a;
    queue<char> b;
    queue<int> c;
    for(int i = 0; i < M; i++)
    {
        int robot, how_many;
        char ins;
        cin >> robot >> ins >> how_many;

        a.push(robot);
        b.push(ins);
        c.push(how_many);
    }   
    for(int i = 0; i < M; i++)
    {
        int robot, how_many;
        char ins;
        
        robot = a.front(); a.pop();
        ins = b.front(); b.pop();
        how_many = c.front(); c.pop();

        if(ins == 'R' || ins == 'L')
        {
            changeDir(robot, ins, how_many);
        }
        else if(ins == 'F')
        {
            moveRobot(robot, how_many);
        }

        if(isOk == 0)
        {
            break;
        }
    }   

    if(isOk == 1)
    {
        cout << "OK";
    }
    else
    {
        if(number.second == 0)
        {
            cout << "Robot " << number.first << " crashes into the wall";
        }
        else
        {
            cout << "Robot " << number.first << " crashes into robot " << number.second;
        }
    }
    
    system("pause");
    return 0;
}
void rotate(int robot, char ins)
{
    int x = robot_x[robot];
    int y = robot_y[robot];

    if(ins == 'L')
    {
        if(dir[x][y] < 3)
        {
            dir[x][y]++;
        }
        else
        {
            dir[x][y] = 0;
        }
        return;
    }

    // ins == 'R'
    if(dir[x][y] > 0)
    {
        dir[x][y]--;
    }
    else
    {
        dir[x][y] = 3;
    }
}
void changeDir(int robot, char ins, int how_many)
{
    for(int i = 0; i < how_many; i++)
    {
        rotate(robot, ins);
    }
}
void moveRobot(int robot, int how_many)
{
    for(int i = 0; i < how_many; i++)
    {
        int x = robot_x[robot];
        int y = robot_y[robot];
        int d = dir[x][y];
        
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx < 1 || nx > A || ny < 1 || ny > B)
        {
            isOk = 0;
            number.first = robot_num[x][y];
            number.second = 0;
            break;
        }

        if(is_here[nx][ny] == 1)
        {
            isOk = 0;
            number.first = robot_num[x][y];
            number.second = robot_num[nx][ny];
            break;
        }

        is_here[nx][ny] = is_here[x][y];
        dir[nx][ny] = dir[x][y];
        robot_num[nx][ny] = robot_num[x][y];
        robot_x[robot] = nx;
        robot_y[robot] = ny;

        is_here[x][y] = 0;
        dir[x][y] = 0;
        robot_num[x][y] = 0;
    }
}