#include <iostream>
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int high, int low)
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

    swap(&arr[high], &arr[i + 1]); // put pivot right after the end of the low array
    // everything after pivot will now be the high array and everything before the pivot will be the low array

    return (i + 1); // return location of pivot in order to organize the sub arrays
}

void quicksort(int *arr, int high, int low)
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
    const int arr_size = 6;
    int array[arr_size] = {1, 6, 7, 7, 5, 8};

    for (int i = 0; i < arr_size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    quicksort(array, 0, arr_size);

    for (int i = 0; i < arr_size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}