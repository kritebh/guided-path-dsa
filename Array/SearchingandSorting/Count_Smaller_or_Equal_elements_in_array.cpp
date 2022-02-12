#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int firstOccurrenceOfEqualOrSmallerElement(int *b, int m, int target, int l, int r)
{
     while (l <= r)
     {
          int mid = l + (r - l) / 2;
          if (b[mid] <= target)
          {
               if (mid + 1 <= r && b[mid + 1] <= target)
               {
                    l = mid + 1;
               }
               else
               {
                    return mid;
               }
          }
          else if (target <= b[mid])
          {
               r = mid - 1;
          }
          else
          {
               l = mid + 1;
          }
     }
     return -1;
}

vector<int> countSmallerOrEqual(int *a, int *b, int n, int m)
{
     //  Write your code here
     vector<int> ans(n, 0);
     sort(b, b + m);
     for (int i = 0; i < n; i++)
     {
          int firstOcc = firstOccurrenceOfEqualOrSmallerElement(b, m, a[i], 0, m - 1);
          ans[i] = firstOcc + 1;
     }
     return ans;
}

/*
!Editorial Code

* Time Complexity: O((N + M) * log(M))
* Space complexity: O(1)
> where N and M are lengths of array A and B respectively

#include <algorithm>
vector<int> countSmallerOrEqual(int *a, int *b, int n, int m)
{

     //  Initiliazing answer vector arr
     vector<int> arr;

     // Sorting the array B
     sort(b, b + m);

     // Traversing the array A
     for (int i = 0; i < n; i++)
     {

          // Handling the case when all elements of array B are smaller
          if (a[i] >= b[m - 1])
          {
               arr.push_back(m);
          }

          // Finding the leftmost index having greater value than current element
          //* We will convert the iterator returned by upper bound to find the corresponding index - as iterator returned is int* and our variable is int so it's an invalid conversion
          // We will append that index to answer vector
          else
          {
               int idx = upper_bound(b, b + m, a[i]) - b;
               arr.push_back(idx);
          }
     }
     return arr;
}
*/