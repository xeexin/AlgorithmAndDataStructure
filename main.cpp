#include<iostream>
using namespace std;
char name[6] = "ABCDE";
char path[10];
void abc(int level,int start) // 0
{
    if (level == 3)
    {
        cout << path << endl;
        return;
    }
    for (int x = start; x < 5; x++)
    {
        path[level] = name[x];
        abc(level + 1, x + 1);
        path[level] = 0;


    }
}
int main()
{
    abc(0,0); // level start


    return 0;
}