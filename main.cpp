/*
2. sum 매개변수 (들어가며 누적합 출력)
*/

#include<iostream>
using namespace std;
int arr[5] = { 4,7,3,6,5 };

void abc(int level,int sum)  // 0 4
{
    if(level==5)return;

    cout << sum << endl;
    
    abc(level + 1, sum + arr[level + 1]);

}
int main()
{

    abc(0, arr[0]);


    return 0;
}

