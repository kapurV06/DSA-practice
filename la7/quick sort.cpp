#include <iostream>
#include <algorithm>
using namespace std;
int pivot(int arr[], int first, int last)
{
  int i = first - 1;
  int pi = arr[last];
  for (int j = first; j < last; j++)
  {
    if (arr[j] < pi)
    {
      i++;
      swap(arr[j], arr[i]);
    }
  }
  swap(arr[last], arr[i + 1]);
  return i + 1;
}
void quickSort(int arr[], int first, int last)
{
  if (first >= last)
  {
    return;
  }

  int pi = pivot(arr, first, last);
  quickSort(arr, first, pi - 1);
  quickSort(arr, pi + 1, last);
}

int main()
{

  int arr[] = {34, 12, 5, 6, 71, 10, 11, 53, 25, 31};
  int n = sizeof(arr) / sizeof(arr[0]);

  quickSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}
