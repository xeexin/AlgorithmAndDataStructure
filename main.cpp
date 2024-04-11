#include<iostream>
using namespace std;

int main()
{

    int arr[8] = { 4,7,1,3,4,2,9,5 };
    int bucket[10] = { 0 };

    for (int x = 0; x < 8; x++)
    {
        bucket[arr[x]]++;
    }

    for (int x = 1; x < 10; x++)
    {
        bucket[x] += bucket[x - 1];
    }

    int result[10] = { 0 };
    for (int x = 0; x < 8; x++)
    {
        int index = arr[x];

        result[bucket[index]--] = index;
        // result[bucket[arr[x]]--] = arr[x];
    }


    return 0;
}