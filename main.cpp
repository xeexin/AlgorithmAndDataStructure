#include<iostream>
#include<string>
using namespace std;

int main()
{
    string arr = "abcdefghijk";
    int index = arr.find("f", 0);
    cout << index << endl;

    // find 메소드 사용시 0(n) 1중 for문의 속도로 찾기
    // 변수이름.find(찾을문자 또는 문자열, 시작 index)
    //찾는 문자열에 해당하는 index반환 없으면 -1반환

    //첫번째 f가 아니라 2번째 f를 찾으려면
    //arr.find(찾을 것, 시작)
    int index2 = arr.find('i', index + 1);
    cout << index2 << endl;
    
    //arr.substr(시작, 개수)
    string result = arr.substr(index + 1, index2 - index - 1);
    cout << result;
}