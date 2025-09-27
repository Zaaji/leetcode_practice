#include <iostream>
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high]; // set partition to end of array arbitrarily
    int i = low - 1;       // set index to start of low side of array - 1
    // will become first element after entry to put in low array found

    for (int j = low; j < high; j++)
    { // j is the number we organize into lower array
        if (arr[j] <= pivot)
        {
            i++;                    // location of next available slot in low array
            swap(&arr[i], &arr[j]); // put current value in lowest available slot in low array
            // value of arr[i] is sent to arbitrary location that will get sorted later
        }
    }

    swap(&arr[i + 1], &arr[high]); // put pivot right after the end of the low array
    // everything after pivot will now be the high array and everything before the pivot will be the low array

    return (i + 1); // return location of pivot in order to organize the sub arrays
}

void quicksort(int *arr, int low, int high)
{
    if (low < high)
    { // while the array is not a single element
        int pi = partition(arr, low, high);

        // use recursion to sort low and high arrays
        quicksort(arr, low, pi - 1);  // sort low side (everythign before partition)
        quicksort(arr, pi + 1, high); // sort high side (everything after partition)
    }
}

int main()
{
    int array[] = {1, 6, 9, 7, 5, 8};
    int n = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    quicksort(array, 0, n - 1);

    for (int j = 0; j < n; j++)
    {
        std::cout << array[j] << " ";
    }
    std::cout << std::endl;
}