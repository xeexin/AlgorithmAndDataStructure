// 백준 S_1_1992

#include<iostream>
using namespace std;
int map[80][80];
int n;
string str;
void solve(int yy, int xx, int size){

  for(int y=yy; y<yy+size; y++){
    for(int x=xx; x<xx+size; x++){
      if(map[y][x] != map[yy][xx]){
        cout << "(";
        solve(yy, xx,size/2);
        solve(yy, xx+size/2, size/2);
        solve(yy+size/2, xx, size/2);
        solve(yy+size/2, xx+size/2, size/2);
        cout<<")";
        return;
      }
    }
  }
  cout << map[yy][xx];
}
int main() {
  cin>>n;

  for(int y=0; y<n; y++){
    cin >>str;
    for(int x=0; x<n; x++){
      map[y][x]=str[x]-'0';
    }
  }


  solve(0,0,n);



  return 0;

}

