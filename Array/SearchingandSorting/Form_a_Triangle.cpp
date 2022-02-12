#include <algorithm>
#include <vector>
using namespace std;

bool possibleToMakeTriangle(vector<int> &arr)
{
 bool ans = false;
 sort(arr.begin(), arr.end());
 for (int i = 0; i < arr.size() - 2; i++)
 {
  if ((arr[i] + arr[i + 1] > arr[i + 2]) && (arr[i] + arr[i + 2] > arr[i + 1]) && (arr[i + 1] + arr[i + 2] > arr[i]))
  {
   ans = true;
  }
 }
 return ans;

 // bool ans = false;
 // for (int i = 0; i < arr.size(); i++)
 // {
 //     for (int j = i+1; j < arr.size(); j++)
 //     {
 //         for (int k = k+1; k < arr.size(); k++)
 //         {
 //             if (i != j && i != k && j != k)
 //             {
 //                 if ((arr[i] + arr[j] > arr[k]) && (arr[i] + arr[k] > arr[j]) && (arr[j] + arr[k] > arr[i]))
 //                 {
 //                     ans = true;
 //                 }
 //             }
 //         }
 //     }
 // }
 // return ans;
}