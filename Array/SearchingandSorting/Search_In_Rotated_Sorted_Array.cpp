int search(int *arr, int n, int key)
{
 // Write your code here.
 int start = 0;
 int end = n - 1;

 // binary search
 while (start <= end)
 {
  int mid = start + (end - start) / 2;
  if (arr[mid] == key)
  {
   return mid;
  }

  // now we find out which halve is sorted

  // left halve is sorted
  else if (arr[mid] >= arr[start])
  {
   if (key >= arr[start] && key <= arr[mid])
   {
    end = mid - 1;
   }
   else
   {
    start = mid + 1;
   }
  }

  // right halve is sorted
  else if (arr[end] >= arr[mid])
  {
   if (key >= arr[mid] && key <= arr[end])
   {
    start = mid + 1;
   }
   else
   {
    end = mid - 1;
   }
  }
 }
 return -1;
}