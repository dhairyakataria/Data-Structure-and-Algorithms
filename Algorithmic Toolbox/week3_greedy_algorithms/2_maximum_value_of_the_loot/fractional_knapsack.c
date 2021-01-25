
#include <stdio.h>

void merge(double arr[], int l, int m, int r, double arr2[]) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    double L[n1], R[n2], L2[n1], R2[n2]; 
  
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
void mergeSort(double arr[], int l, int r, double arr2[]) 
{ 
    if (l < r) { 
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
    int n, w, i;
    scanf("%d %d", &n, &w);
    double value[n], weights[n], value_per_weight[n], ans=0, count=0, var=0;
    
    for( i=0; i<n; i++)
    {
        scanf("%lf %lf", &value[i], &weights[i]);
        value_per_weight[i] = value[i]/weights[i];
    }
    
    mergeSort(value_per_weight, 0, n - 1, weights);
    
    for( i=n-1; i>=0; i--)
    {
        if(count<w)
        {
            var = w-count;
            if(var>=weights[i])
            {
                ans += value_per_weight[i] * weights[i];
                count += weights[i];
            }
            else
            {
                ans += value_per_weight[i] * var;
                break;
            }
        }
        else
        {
            break;
        }
    }
    printf("%.4lf\n", ans);
}
