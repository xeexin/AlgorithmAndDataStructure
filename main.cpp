/*
string class를 이용하여 문자열 다루기
Parcing(파싱): 예) 고객 정보 - 이름 - 나이 - 전번 - 성별 있을 때, 원하는 이름 - 나이 - 전번만 추출
-> 파싱 문제 코테에서 많이 나옴 (금융권, 뱅킹)
*/


#include<iostream>
#include<string>
using namespace std;
int main()
{
    string userID = "KFC";
    string userPW = "BBQMC";

    string ID, PW;
    cin >> ID >> PW;

    if ((userID == ID) && (userPW == PW)) cout << "로그인성공";
    else if (userID == ID && userPW != PW) cout << "비번오류";
    else if (userID != ID && userPW != PW) cout << "없는 ID";
    else cout << "다시 로그인";


}
