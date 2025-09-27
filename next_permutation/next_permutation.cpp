#include <iostream>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *arr, int low, int high)
{
    int pivot = arr[high]; // set last element as pivot

    int i = low - 1; // start of low array

    for (int j = low; j < high; j++)
    { // look for number lower than pivot for lower array
        if (arr[j] < pivot)
        {
            i++;                    // go to the next available slot in low array
            swap(&arr[j], &arr[i]); // put smaller value in lower array
        }
    }

    swap(&arr[high], &arr[i + 1]); // put pivot at the end of the lower array
    return (i + 1);                // return pivot position
}
void quicksort(int *arr, int low, int high)
{
    int pi = partition(arr, low, high);

    if (low < high)
    {                                 // while array is > length 1
        quicksort(arr, low, pi - 1);  // low half
        quicksort(arr, pi + 1, high); // high half
    }
}

int main()
{
    int sample_array[] = {1, 2, 3};
    int size_of_array = sizeof(sample_array) / sizeof(sample_array[0]);
    int pivot_index = 0;
    int successor_index;

    // find pivot (right most ascending pair)
    for (int i = size_of_array - 2; i > 0; i--)
    {
        if (sample_array[i] < sample_array[i + 1])
        {
            pivot_index = i;
            break;
        }
    }

    // find right most # greater than pivot
    for (int j = size_of_array - 1; j > 0; j--)
    {
        if (sample_array[j] > sample_array[pivot_index])
        {
            successor_index = j;
            break;
        }
    }

    // swap values
    swap(&sample_array[pivot_index], &sample_array[successor_index]);

    // sort values after pivot location
    quicksort(sample_array, pivot_index, size_of_array - 1);

    for (int k = 0; k < size_of_array; k++)
    {
        std::cout << sample_array[k] << " ";
    }
    std::cout << std::endl;
}