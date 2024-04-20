#include<iostream>
using namespace std;
int arr[7] = { 5,2,1,8,3,9,7 };
int vect[100];
void bst(int value)
{
    int now = 1;
    while (1) {
        if (vect[now] == 0) {
            vect[now] = value;
        }
        if (vect[now] > value) {
            now *= 2;
        } else {
            now *= 2;
            now++;
        }
    }
}
bool search(int value)
{
    int now = 1;

    while (1) {
        if(now>100)return 0; //범위 밖
        if(vect[now]==value)return 1;
        if (vect[now] > value) {
            now *= 2;
        } else {
            now *= 2;
            now++;
        }
    }

}
int main()
{

    for (int x = 0; x < 7; x++)
    {
        bst(arr[x]);
    }
    if (search(4) == 1)cout << "존재";
    else cout << "없는 숫자";

    return 0;
}