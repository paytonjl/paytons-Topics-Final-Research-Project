/* MDH WCET BENCHMARK SUITE. */

/* 2012/09/28, Jan Gustafsson <jan.gustafsson@mdh.se>
 * Changes:
 *  - This program redefines the C standard function sqrt. Therefore, this function has been renamed to sqrtfcn.
 *  - qrt.c:79:15: warning: explicitly assigning a variable of type 'float' to itself: fixed
 */

/*************************************************************************/
/*                                                                       */
/*   SNU-RT Benchmark Suite for Worst Case Timing Analysis               */
/*   =====================================================               */
/*                              Collected and Modified by S.-S. Lim      */
/*                                           sslim@archi.snu.ac.kr       */
/*                                         Real-Time Research Group      */
/*                                        Seoul National University      */
/*                                                                       */
/*                                                                       */
/*        < Features > - restrictions for our experimental environment   */
/*                                                                       */
/*          1. Completely structured.                                    */
/*               - There are no unconditional jumps.                     */
/*               - There are no exit from loop bodies.                   */
/*                 (There are no 'break' or 'return' in loop bodies)     */
/*          2. No 'switch' statements.                                   */
/*          3. No 'do..while' statements.                                */
/*          4. Expressions are restricted.                               */
/*               - There are no multiple expressions joined by 'or',     */
/*                'and' operations.                                      */
/*          5. No library calls.                                         */
/*               - All the functions needed are implemented in the       */
/*                 source file.                                          */
/*                                                                       */
/*                                                                       */
/*************************************************************************/
/*                                                                       */
/*  FILE: sqrt.c                                                         */
/*  SOURCE : Public Domain Code                                          */
/*                                                                       */
/*  DESCRIPTION :                                                        */
/*                                                                       */
/*     Square root function implemented by Taylor series.                */
/*                                                                       */
/*  REMARK :                                                             */
/*                                                                       */
/*  EXECUTION TIME :                                                     */
/*                                                                       */
/*                                                                       */
/*************************************************************************/

/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
  
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
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
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
  
/* Driver code */
int main()
{
    int arr[] = {35,58,78,39,54,9,47,72,28,74,34,27,48,64,67,18,72,26,3,22,93,6,97,53,15,77,96,59,100,40,6,42,10,53,47,71,92,35,39,80,58,66,9,65,72,77,95,26,32,89,98,56,38,76,18,80,30,69,24,25,37,34,9,29,79,74,65,96,74,54,7,93,54,6,28,39,17,30,37,63,54,63,50,68,2,83,45,18,42,28,67,58,4,25,39,10,33,91,38,62,35,58,78,39,54,9,47,72,28,74,34,27,48,64,67,18,72,26,3,22,93,6,97,53,15,77,96,59,100,40,6,42,10,53,47,71,92,35,39,80,58,66,9,65,72,77,95,26,32,89,98,56,38,76,18,80,30,69,24,25,37,34,9,29,79,74,65,96,74,54,7,93,54,6,28,39,17,30,37,63,54,63,50,68,2,83,45,18,42,28,67,58,4,25,39,10,33,91,38,62,35,58,78,39,54,9,47,72,28,74,34,27,48,64,67,18,72,26,3,22,93,6,97,53,15,77,96,59,100,40,6,42,10,53,47,71,92,35,39,80,58,66,9,65,72,77,95,26,32,89,98,56,38,76,18,80,30,69,24,25,37,34,9,29,79,74,65,96,74,54,7,93,54,6,28,39,17,30,37,63,54,63,50,68,2,83,45,18,42,28,67,58,4,25,39,10,33,91,38,62,35,58,78,39,54,9,47,72,28,74,34,27,48,64,67,18,72,26,3,22,93,6,97,53,15,77,96,59,100,40,6,42,10,53,47,71,92,35,39,80,58,66,9,65,72,77,95,26,32,89,98,56,38,76,18,80,30,69,24,25,37,34,9,29,79,74,65,96,74,54,7,93,54,6,28,39,17,30,37,63,54,63,50,68,2,83,45,18,42,28,67,58,4,25,39,10,33,91,38,62,35,58,78,39,54,9,47,72,28,74,34,27,48,64,67,18,72,26,3,22,93,6,97,53,15,77,96,59,100,40,6,42,10,53,47,71,92,35,39,80,58,66,9,65,72,77,95,26,32,89,98,56,38,76,18,80,30,69,24,25,37,34,9,29,79,74,65,96,74,54,7,93,54,6,28,39,17,30,37,63,54,63,50,68,2,83,45,18,42,28,67,58,4,25,39,10,33,91,38,62,35,58,78,39,54,9,47,72,28,74,34,27,48,64,67,18,72,26,3,22,93,6,97,53,15,77,96,59,100,40,6,42,10,53,47,71,92,35,39,80,58,66,9,65,72,77,95,26,32,89,98,56,38,76,18,80,30,69,24,25,37,34,9,29,79,74,65,96,74,54,7,93,54,6,28,39,17,30,37,63,54,63,50,68,2,83,45,18,42,28,67,58,4,25,39,10,33,91,38,62,35,58,78,39,54,9,47,72,28,74,34,27,48,64,67,18,72,26,3,22,93,6,97,53,15,77,96,59,100,40,6,42,10,53,47,71,92,35,39,80,58,66,9,65,72,77,95,26,32,89,98,56,38,76,18,80,30,69,24,25,37,34,9,29,79,74,65,96,74,54,7,93,54,6,28,39,17,30,37,63,54,63,50,68,2,83,45,18,42,28,67,58,4,25,39,10,33,91,38,62,35,58,78,39,54,9,47,72,28,74,34,27,48,64,67,18,72,26,3,22,93,6,97,53,15,77,96,59,100,40,6,42,10,53,47,71,92,35,39,80,58,66,9,65,72,77,95,26,32,89,98,56,38,76,18,80,30,69,24,25,37,34,9,29,79,74,65,96,74,54,7,93,54,6,28,39,17,30,37,63,54,63,50,68,2,83,45,18,42,28,67,58,4,25,39,10,33,91,38,62,35,58,78,39,54,9,47,72,28,74,34,27,48,64,67,18,72,26,3,22,93,6,97,53,15,77,96,59,100,40,6,42,10,53,47,71,92,35,39,80,58,66,9,65,72,77,95,26,32,89,98,56,38,76,18,80,30,69,24,25,37,34,9,29,79,74,65,96,74,54,7,93,54,6,28,39,17,30,37,63,54,63,50,68,2,83,45,18,42,28,67,58,4,25,39,10,33,91,38,62,35,58,78,39,54,9,47,72,28,74,34,27,48,64,67,18,72,26,3,22,93,6,97,53,15,77,96,59,100,40,6,42,10,53,47,71,92,35,39,80,58,66,9,65,72,77,95,26,32,89,98,56,38,76,18,80,30,69,24,25,37,34,9,29,79,74,65,96,74,54,7,93,54,6,28,39,17,30,37,63,54,63,50,68,2,83,45,18,42,28,67,58,4,25,39,10,33,91,38,62};
    
    int arr_size = sizeof(arr) / sizeof(arr[0]);
  
  
    mergeSort(arr, 0, arr_size - 1);
  
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
