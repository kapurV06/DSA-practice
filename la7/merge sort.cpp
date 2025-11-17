#include <iostream>
#include <vector>
using namespace std;
void merge(int arr[], int low, int mid, int high)
{
  vector<int> v;
  int left = low;
  int right = mid + 1;
  while (left <= mid && right <= high)
  {
    if (arr[left] <= arr[right])
    {
      v.push_back(arr[left++]);
    }
    else
    {
      v.push_back(arr[right++]);
    }
  }
  while (left <= mid)
  {
    v.push_back(arr[left++]);
  }
  while (right <= high)
  {
    v.push_back(arr[right++]);
  }
  for (int i = low; i <= high; i++)
  {
    arr[i] = v[i - low];
  }
}
void mergeSort(int arr[], int low, int high)
{
  if (low >= high)
  {
    return;
  }
  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);
  merge(arr, low, mid, high);
}
int main()
{
  int arr[] = {3, 2, 4, 1, 3};
  int n = (sizeof(arr) / sizeof(arr[0])) - 1;
  mergeSort(arr, 0, n);
  for (int i = 0; i <= n; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}
