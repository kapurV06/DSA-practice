#include <iostream>
#include <vector>
using namespace std;
int main()
{

  vector<int> v = {5, 8, 4, 9, 2};

  for (int i = 0; i < v.size() - 1; i++)
  {
    int min_index = i;
    for (int j = i + 1; j < v.size(); j++)
    {
      if (v[j] < v[min_index])
      {
        min_index = j;
      }
    }
    if (min_index != i)
    {
      swap(v[i], v[min_index]);
    }
  }
  for (int ele : v)
  {
    cout << ele << " ";
  }

  return 0;
}
