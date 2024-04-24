#include<iostream>
using namespace std;
int vect[20] = { 1,3,-1,6,-3,-1,5,100,3,2,5,1 };
int arr[3] = { 2,3,5 };
int Max = -21e8;
void abc(int level, int now, int sum)
{
    if (now > 11)
    {
        // sum의 맥스값 갱신
        if (sum > Max)
        {
            Max = sum;
        }
        return;
    }
    for (int x = 0; x < 3; x++)
    {
        abc(level + 1, now + arr[x], sum + vect[now + arr[x]]);
    }

}
int main()
{

    abc(0, 0, vect[0]);
    cout << Max;

    return 0;
}



