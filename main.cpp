//	3
//	100 10 30 입력

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> vect(n);
    for (int x = 0; x < n; x++) {
        /*int k;
        cin >> k;
        vect.push_back(k);*/
        cin >> vect[x];
    }

    sort(vect.begin(), vect.end());

    int time=0;
    int remain = n - 1;
    int idx = 0;

    while (true) {
        time += (vect[idx++] * remain);
        remain--;
        if(idx==n)break;
    }
    cout << time;
    return 0;
}
