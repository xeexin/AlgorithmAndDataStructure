/*
   정수 n,m을 입력받은 후
   n개의 대문자로 이루어진 한 문자열을 입력 받습니다.

   입력>
   12
   4
   ABBABQAADAAB

   연속된 m개의 구간중 A가 가장 많은 구간은
   A가 최대 몇개까지 등장 할까요?

   정답은 3개

*/

#include<iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    string str;
    cin >> str;

    int bucket[200] = {0};
    for (int x = 0; x < m; x++) {
        bucket[str[x]]++;
    }

    int MAX = bucket['A'];

    for (int x = 0; x < str.length() - m; x++) {
        bucket[str[x]]--;
        bucket[str[x + m]]++;

        if (MAX < bucket['A']) {
            MAX = bucket['A'];
        }
    }

    cout << MAX ;

    return 0;
}