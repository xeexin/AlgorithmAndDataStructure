#include<iostream>
#include<algorithm> // sort
#include<string> // string
#include<vector> // vector
using namespace std;
int main()
{
    char aaq[10] = "asdfzxcv";


    string bbq = "asdfzxcv";
    sort(bbq.begin(), bbq.end());

    string arr[5] = { "INC","JFK","HND","ATL","PVG" };
    sort(arr, arr + 5, greater<string>());

    vector<string>ar = { "INC","JFK","HND","ATL","PVG" };
    sort(ar.begin(), ar.end());

    vector<vector<string>>aaa = { {"JFK","INC"},{"HND","ATL"} };
    sort(aaa.begin(), aaa.end());

    vector<vector<string>>aaaa = { {"JFK","INC"},{"HND","ATL"} };
    for (int x = 0; x < 2; x++)
    {
        sort(aaaa[x].begin(), aaaa[x].end());
    }


    return 0;
}
