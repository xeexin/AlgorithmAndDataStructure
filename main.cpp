#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int f, int b)
{
    return f > b;
}

int main()
{
    vector<int>vect = { 3,56,1,2,34,5 };
    sort(vect.begin(), vect.end()); // 디폴트 less (오름차순)
    sort(vect.begin(), vect.end(), greater<int>()); // 내림차순

    sort(vect.begin(), vect.end(),compare); // 내림차순 조건을 직접 부여

    for (int x = 0; x < vect.size(); x++) {
        cout << vect[x]<<" ";
    }





    /*
    int len = vect.size();
    for (int x = 0; x < len; x++) {
        cout << vect[x] << " ";
    }

     end() 는 마지막 원소가 아니라 마지막 다음칸..
    for (auto x = vect.begin(); x != vect.end(); ++x)
    {
        cout << *x;
    }

     auto
     변수 선언시 반드시 값 초기화 해야 함
     매개변수 사용 불가 (단 리턴값의 자료형으로 사용은 가능)
     구조체 맴버변수로 사용 불가능
     */



    return 0;
}