/*Write several utility functions to manipulate arrays. These will:
Populate an array with values provided by the user. After all values
have been inserted, the array may remain only partially filled.
Display the contents of a partially filled array.
Search for a user-specified value in an array using sequential search.
Reverse the values in an array.
Sort an array using selection sort*/

#include <iostream>
using namespace std;

int get_value (int arr[],int size);
void display (int arr[],int size);
int seq_search (int arr[],int size,int target);
void reverse (int arr[],int size);
void sel_sort (int arr[],int size);
void swap (int& a,int& b);
const int SIZE=20;

int main()
{
    int arr[SIZE];
    int target,used=0;

    used=get_value (arr,SIZE);
    display (arr,used);

    cout << "\nEnter search target value: ";
    cin >> target;
    int result=seq_search (arr,used,target);
    if ( result < 0 )
        cout << "\nTarget not found in array!" << endl;
    else
       cout << "\nTarget found at index " << result;

    reverse (arr,used);
    cout << "\nOrder reversed: " << endl;
    display (arr,used);

    sel_sort (arr,used);
    cout << "\nSorted array: " << endl;
    display (arr,used);

    return 0;
}

int get_value(int arr[], int size)
{
   cout << "Enter up to " << size << " non-negative numbers.\n"
        << "If entering fewer than " << size <<", enter -1 when done:\n"
        << endl;

   int index = 0;
   int value = 0;

   while (value >= 0)
   {
      cin >> value;
      if (value >= 0)
      {
         if (index < size)
         {
            arr[index] = value;
            ++index;
         }
         else
         {
            cout << "\nToo many values" << endl;
            return -1;
         }
      }
   }
   return index;
}

void display(int arr[],int size)
{
    cout << endl;
   for (int i=0; i<size; i++)
   {
      cout << arr[i] << " ";
    }
}

int seq_search(int arr[],int size,int target)
{
   for (int i=0; i<size; i++)
   {
      if (arr[i] == target)
         return i;
    }
return -1;
}

void reverse(int arr[],int size)
{
   for (int num=0; num < size/2; num++)
   {
      swap (arr[num],arr[size-1-num]);
    }
}

void sel_sort (int arr[],int size)
{
   int least_value=0;
   int least_value_index=0;

   for (int i=0; i<size-1; i++)
   {
      least_value=arr[i];
      least_value_index=i;
      for (int j=i+1; j<size; j++)
      {
         if (arr[j]<least_value)
         {
            least_value=arr[j];
            least_value_index=j;
        }
      }
      swap (arr[i],arr[least_value_index]);
    }
}

void swap(int& a,int& b)
{
   int temp=a;
   a=b;
   b=temp;
}
