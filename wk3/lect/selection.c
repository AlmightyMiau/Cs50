#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int arr[] =
    int n = arr.length
    for (int i = 0; i < n - 1; i++) {
        int n;
        int m;
        for (int j = i; j < n - 1; j++) {
            if (arr[j] < n || n === undefined) {
                n = arr[j];
                m = j;
            }
        }
        int k = arr[i];
        arr[i] = n;
        arr[m] = k;
    }
}


/*
    grab the first value and record it
    go throught each value and record the smallest
    swap the 1st value and the smallest value
    repeat

    O(n^2)
    Q(n^2)  Omega
    0(n^2)
*/
