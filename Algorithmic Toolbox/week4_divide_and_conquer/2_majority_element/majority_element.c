
#include <stdio.h>


void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) { 
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
        int m = l + (r - l) / 2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 




int element_count(int arr[],int n)
{
    int i, count=1, max=0;
    for( i=0; i<n-1 ; i++)
    {
        if(arr[i]==arr[i+1])
        {
            count++;
        }
        else
        {
            if(max<=count)
                max = count;
            count=1;
        }
    }
    if(max<=count)
        max = count;
    if(max>n/2)
    {
        return 1;
    }
    else
        return 0;
}





int main()
{
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for( i=0; i<n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, n-1);
    printf("%d", element_count(arr, n));
    
        
    return 0;
}
