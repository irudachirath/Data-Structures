#include <iostream>
#include <vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int left = 2*root + 1;
   int right = 2*root + 2;
   int max;
   if (left<n && arr[left]>arr[root]) {
      max = left;
   } else {
      max = root;
   }
   if (right<n && arr[right]>arr[max]) {
      max = right;
   }
   if (max != root){
      int temp = arr[root];
      arr[root] = arr[max];
      arr[max] = temp;
      heapify(arr, n, max);
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   for (int i=(n/2)-1; i>=0; i--) {
      heapify(arr, n, i);
   }
   for (int j=n-1; j>0; j--) {
      int temp = arr[0];
      arr[0] = arr[j];
      arr[j] = temp;
      n--;
      heapify(arr, n, 0);
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   vector<int> heap_vec;
   cout<<"If you want to stop giving inputs to the array Enter -1"<<endl;
   int i = 0;
   int n = 0;
   while (true) {
      cin >> i;
      if (i==-1) break;
      heap_vec.push_back(i);
      n++;
   }
   int heap_arr[n];
   for(int i = 0; i < n; i++) 
      {
         heap_arr[i] = heap_vec[i];
      }
   
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}