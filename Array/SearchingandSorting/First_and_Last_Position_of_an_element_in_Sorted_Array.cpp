#include <bits/stdc++.h>
#include <vector>
using namespace std;

int findFirstPosition(vector<int> &arr, int n, int x, int l, int r)
{
 while (l <= r)
 {
  int mid = l + (r - l) / 2;
  if (arr[mid] == x)
  {
   if (mid - 1 >= l && arr[mid - 1] == x)
   {
    r = mid - 1;
   }
   else
   {
    return mid;
   }
  }
  else if (x <= arr[mid])
  {
   r = mid - 1;
  }
  else if (x > arr[mid])
  {
   l = mid + 1;
  }
 }
 return -1;
}

int findLastPosition(vector<int> &arr, int n, int x, int l, int r)
{
 while (l <= r)
 {
  int mid = l + (r - l) / 2;
  if (arr[mid] == x)
  {
   if (mid + 1 <= r && arr[mid + 1] == x)
   {
    l = mid + 1;
   }
   else
   {
    return mid;
   }
  }
  else if (x <= arr[mid])
  {
   r = mid - 1;
  }
  else if (x > arr[mid])
  {
   l = mid + 1;
  }
 }
 return -1;
}

pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
 // Write your code here.
 pair<int, int> position;
 position.first = findFirstPosition(arr, n, x, 0, n - 1);
 position.second = findLastPosition(arr, n, x, 0, n - 1);
 return position;
}
