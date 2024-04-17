//pair 자료형
// 두개의 자료형을 하나로 묶는 것
// 장점 : sort 할 때 first 기준으로 정렬해줌
//구조체로 써도 가능

#include<iostream>
#include<utility> //헤더파일 불러와야 함 but algorithm이나 vector 있으면 안써도 됨
#include<algorithm>
#include<vector>
using namespace std;
struct node {
    int a;
    int b;
};
int main()
{
    node t = { 3,6 }; //구조체

    //1.
    pair<int, int> t1 = { 3,6 }; //pair 자료형 [앞에 거 : first & 뒤에 거: second]

    //출력
    cout << t1.first << t1.second;
    //입력
    cin >> t1.first >> t1.second;
    cout << t1.first << t1.second;


    //2.
    pair<int, char>t2;
    cin >> t2.first >> t2.second;

    //3.
    pair<int, int>t3;
    t3={ 3,7 };
    t3 = make_pair(3, 8);

    //4. 페어 안의 페어도 가능
    pair < int, pair<int, int>>r;
    r = { 3,{7,9} };
    cout << r.second.first; //7


    //5.
    vector<pair<int, char>>vect;
    vect.push_back({ 3,'T' });
    vect.push_back(make_pair(7, 'E'));
    vect.push_back({ 1,'T' });

    sort(vect.begin(), vect.end()); //first 기준으로 sort 1-3-7

    return 0;
}