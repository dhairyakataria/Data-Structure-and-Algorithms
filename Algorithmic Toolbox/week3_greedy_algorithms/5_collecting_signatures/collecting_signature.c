#include<stdio.h>




void merge(int arr[], int l, int m, int r, int arr2[]) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2], L2[n1], R2[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
    {
        L[i] = arr[l + i]; 
        L2[i] = arr2[l + i];
    }
    for (j = 0; j < n2; j++) 
    {
        R[j] = arr[m + 1 + j]; 
        R2[j] = arr2[m + 1 +j];
    }
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i];
            arr2[k] = L2[i];
            i++; 
        } 
        else 
        { 
            arr[k] = R[j]; 
            arr2[k] = R2[j];
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i];
        arr2[k] = L2[i];
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        arr2[k] = R2[j];
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r, int arr2[]) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m, arr2); 
        mergeSort(arr, m + 1, r, arr2); 
  
        merge(arr, l, m, r, arr2); 
    } 
}







int main()
{
    int n;
    scanf("%d", &n);
    int start[n], end[n], i, common_points[n], var=0, count=1;
    
    for( i=0; i<n; i++)
    {
        scanf("%d %d", &start[i], &end[i]);
    }
    
    
    mergeSort(end, 0, n - 1, start);
    
    
    var = end[0];
    common_points[0] = end[0];
    
    for( i=0; i<n; i++)
    {
        if(var<start[i] || var>end[i])
        {
            var = end[i];
            common_points[count] = end[i];
            count++;
        }
    }
    
    printf("%d\n", count);
    for( i=0; i<count; i++)
    {
        printf("%d ",common_points[i]);
    }
}