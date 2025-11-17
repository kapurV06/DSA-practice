#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues
{
  queue<int> q1,q2;

public:
  void push(int x)
     {
         q2.push(x);
        while (!q1.empty())
    {
      q2.push(q1.front());
          q1.pop();
    }
    swap(q1, q2);
  }

  void pop()
  {
         if (!q1.empty())
      q1.pop();
  }

  int top()
  {
    if (q1.empty())
      return -1;
    return q1.front();
  }

  bool empty()
  {
    return q1.empty();
  }
};

class StackOneQueue
{
  queue<int> q;

public:
  void push(int x)
  {
    q.push(x);
    int sz = q.size();
        for (int i =0; i< sz - 1; i++)
    {
      q.push(q.front());
      q.pop();
    }
  }
      void pop()
  {
    if (!q.empty())
      q.pop();
  }   
    
     int top()
     {
    if (q.empty())
      return -1;
         return q.front();
  }

  bool empty()
  {
    return q.empty();
  }
};

int main()
{
  StackTwoQueues st2;
  st2.push(10);
  st2.push(20);
  st2.push(30);
  cout << st2.top() << endl;
  st2.pop();
  cout << st2.top() << endl;

  StackOneQueue st1;
  st1.push(10);
  st1.push(20);
  st1.push(30);
  cout << st1.top() << endl;
  st1.pop();
  cout << st1.top() << endl;

  return 0;
}
