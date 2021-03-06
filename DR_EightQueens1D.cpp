#include <iostream>
using namespace std;
int main() {
  int solutions=0;
  int q[8],c=0;
  q[0]=0;

nc: 
  c++;
  if (c==8) goto print;
  q[c] = -1;

nr: 
  q[c]++;
  if (q[c] == 8) goto backtrack;

//Queen Test | Row Test, Up Diagonal Test, Down Diagonal Test
  for(int i=0; i < c; i++){
    if(q[i] == q[c] || c-i == abs(q[c]-q[i])) goto nr;
  }
  goto nc;

backtrack:
  c--;
  if(c == -1) return 0;
  goto nr;

print:
  cout<<"Solution #"<< ++solutions << ": ";
  for(int i=0; i< c ;i++){
    cout << q[i];
  }
  cout << endl;
  for(int i=0; i< 8 ;i++){
    for(int j=0; j < 8 ; j++){
      if (i == q[j]) cout << 1 << " "; 
       else cout << 0 << " ";
    }
    cout << endl;
  }
  goto backtrack;
}