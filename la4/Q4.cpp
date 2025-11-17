#include <iostream>
#include <queue>
using namespace std;
int main(){
    string s;
  cout <<"Enter a string: ";
  cin>> s;

  queue<char> q;
  int freq[256] = {0};

  for(char ch : s)
  {
     freq[ch]++;
        q.push(ch);
    while (!q.empty() && freq[q.front()] > 1)
      q.pop();
    if (q.empty())
          cout <<*-1 << " ";
    else{
      cout << q.front() << " ";
    }
  }
  return 0;
}
