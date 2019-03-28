#include <iostream>
using namespace std;

int BinarySearch(int* s, int key, int low, int high)
{
   if (low >= high)
   {
       return -1;
   }

   int mid = low + ((high - low) >> 2);

   if (s[mid] < key)
   {
       return BinarySearch(s, key, mid+1, high);
   }
   else if (s[mid] > key)
   {
       return BinarySearch(s, key, low, mid);
   }

   return mid;
}

void PrintArry(int*s, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}

void BubbleSort(int* s, int n)
{
    bool flag = true;

    for(int i = 0; (i < n)&&flag; i++)
    {
        flag = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if ( s[j] > s[j+1])
            {
                std::swap(s[j], s[j+1]);
                flag = true;
            }
        }
    }
}

void SelectSort(int* s, int n)
{
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        tmp = i;

        for (int j = i+1; j < n; j++)
        {
            if(s[tmp] > s[j])
            {
                tmp = j;
            }
        }

        if (tmp != i)
        {
            std::swap(s[i], s[tmp]);
        }
    }
}

void InsertSort(int* s, int n)
{
    int tmp = 0;
    int i = 0;
    int j = 0;

    for (i = 1; i < n ; i++)
    {
        if (s[i] < s[i-1])
        {
            tmp = s[i];

            for (j = i -1; (j >=0) && (s[j] > tmp); j--)
            {
                s[j+1] = s[j];
            }
            s[j+1] = tmp;
        }
    }
}

int pration(int* s, int low, int high)
{
   int mid = s[low];

   while(low < high)
   {
        while ((low < high)&& (s[high] >= mid))
            high--;

        std::swap(s[high], s[low]);

        while((low < high)&& (s[low] <= mid))
            low++;

        std::swap(s[low], s[high]);
   }
   return low;
}

void QuickSortLogic(int *s, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int pos = pration(s, low , high-1);

    QuickSortLogic(s,low, pos-1);
    QuickSortLogic(s,pos+1, high);
}

void QuickSort(int*s, int n)
{
    QuickSortLogic(s, 0, n);
}

int main()
{
    //Binary Search
    int a[] = {0,1,2,3,4,5,6,7};
    cout << BinarySearch(a,7,0,sizeof(a)/sizeof(int)) <<endl;

    //Bubble Sort
    int s[] = {3,2,7,9,0,3};
    BubbleSort(s, sizeof(s)/sizeof(int));
    PrintArry(s, sizeof(s)/sizeof(int));

    //Select Sort
    int c[] = {3,2,7,9,0,3};
    SelectSort(c, sizeof(c)/sizeof(int));
    PrintArry(c, sizeof(c)/sizeof(int));

    //Insert Sort
    int d[] = {3,2,7,9,0,3};
    InsertSort(d, sizeof(d)/sizeof(int));
    PrintArry(d, sizeof(d)/sizeof(int));

    //Quic Sort
    int e[] = {3,2,7,9,0,3};
    QuickSort(e, sizeof(e)/sizeof(int));
    PrintArry(e, sizeof(e)/sizeof(int));


    return 0;
}
