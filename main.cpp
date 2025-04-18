// 백준 S_5_5648

/**
모든 원소가 양의 정수인 집합이 있을 때, 원소를 거꾸로 뒤집고 그 원소를 오름차순으로 정렬하는 프로그램을 작성하세요.
단, 원소를 뒤집었을 때 0이 앞에 선행되는 경우는 0을 생략해야합니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long> v;

    for (int x = 0; x < n; x++) {
        string num;
        cin >> num;
        reverse(num.begin(), num.end());
        long long reverseNum = stoll(num);
        v.push_back(reverseNum);
    }

    sort(v.begin(), v.end());
    for (int x = 0; x < n; x++) {
        cout << v[x] << endl;
    }

    return 0;
}
