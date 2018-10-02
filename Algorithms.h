#ifndef ALGORITHMS_H_INCLUDED
#define ALGORITHMS_H_INCLUDED

void bubble_sort(int* & arr, int arr_size)
{
    bool changed = true;
    int top = arr_size;

    while(changed == true)
    {
        changed = false;
        for(int i = 0; i < top - 1 ; i++)
        {
            if(arr[i] > arr[i+1])
            {
                int tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                changed = true;
            }
        }
        top--;
    }
}

void insertion_sort(int* & arr, int arr_size)
{
    for(int sorted_i = 1; sorted_i < arr_size; sorted_i++)
    {
        int j = sorted_i;
        while(j > 0 && arr[j] < arr[j-1])
        {
            int tmp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = tmp;
            j--;
        }
    }
}

void selection_sort(int* & arr, int arr_size)
{
    for(int sorted_i = 0; sorted_i < arr_size; sorted_i++)
    {
        int min_i = sorted_i;
        for (int j = sorted_i + 1; j < arr_size; j++)
        {
            if(arr[j] < arr[min_i])
            {
                min_i = j;
            }
        }
        if(arr[sorted_i] != arr[min_i])
        {
            int tmp = arr[sorted_i];
            arr[sorted_i] = arr[min_i];
            arr[min_i] = tmp;
        }

    }
}

//======Quick sort=======

int partition(int* & arr, int lo, int hi)
{
    int pivot = arr[hi];
    int i = lo - 1;
    for(int j = lo; j <= hi - 1; ++j)
    {
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[hi]);
    return (i + 1);
}

void quick_sort(int* &arr, int lo, int hi)
{
    if (lo < hi)
    {
        int pi = partition(arr, lo, hi);
        
        quick_sort(arr, lo, pi - 1);
        quick_sort(arr, pi + 1, hi);
    } 
}
//======Merge sort=======
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  

    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
       
        int m = l+(r-l)/2; 
  
    
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  

//Adapted algorithm from Cosmos by OpenGenus Foundation
//=======================

#endif // ALGORITHMS_H_INCLUDED
