/*
[UNION FIND]_자료구조
-독립된 데이터들을 그룹화할 때 사용하는 자료구조
-BOSS : 일단  보스는 자기자신임
        setunion('a','b'); // a b 그룹화하는 함수 만들기 (그룹장은 a)
setunion('c','d'); // c와 d는 하나의 그룹 (그룹장은 c)
setunion('d','e'); // 보스가 다를 경우 그룹화 가능. (그룹장은 c)(d라고 적어도 상관 없음) (d의 보스는 c이기 때문에)
setunion('c','e'); // 이미 같은 그룹임으로 그룹화 X
setunion('b','e'); // b의 보스 a ,  e의 보스 c로 그룹화 하면 BOSS=a

*/

//a~f 사이의 문자 입력
//입력받은 두 문자가 같은 그룹인지 아닌지 판단하는 문제

#include<iostream>
using namespace std;
int arr[200];
char findboss(char member)
{
    if (arr[member] == 0) return member; //자기자신이 보스인 경우
    char ret = findboss(arr[member]);
    arr[member] = ret; // 경로 압축
    return ret; //보스를 찾아서 리턴
}
void setunion(char a, char b)
{
    if (findboss(a) == findboss(b)) return; //보스가 같으면 끄기
    arr[findboss(b)] = findboss(a);

}
int main()
{
    setunion('a', 'b');
    setunion('c', 'd');
    setunion('d', 'e');
    setunion('c', 'e');
    setunion('b', 'e');

    char y, x;
    cin >> y >> x;

    if (findboss(y) == findboss(x)) cout << "같은 그룹";
    else cout << "다른 그룹";

    return 0;
}