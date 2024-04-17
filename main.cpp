#include<iostream>
using namespace std;
int main()
{
    int arr[7] = { 4,7,1,3,5,2,9 };
    int result[7];
    
    for (int y = 0; y < 7; y++)
    {
        result[y] = arr[y];
        for (int x = y; x > 0; x--)
        {
            if (result[x - 1] > result[x])
            {
                swap(result[x - 1], result[x]);
            }
            else break;
        }
    }
    for (int x = 0; x < 9; x++)cout << result[x] << " ";

    return 0;
}