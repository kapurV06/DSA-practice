include <iostream>
#include <vector>
using namespace std;
int main()
{

  vector<int> v = {5, 3, 2, 1, 4};
  int n = v.size();

  for (int i = 1; i < n; i++)
  {
    int current = v[i];
    int j = i - 1;
    while (j >= 0 and v[j] > current)
    {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = current;
  }

  for (int ele : v)
  {
    cout << ele << " ";
  }

  return 0;
}
