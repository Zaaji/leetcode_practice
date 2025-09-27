#include <iostream>
void quicksort(int pivot, int size, int *array)
{
}

int main()
{
    const int size_of_array = 6;
    int sample_array[size_of_array] = {1, 2, 3, 4, 5, 6};
    int pivot_index;
    int successor_index;

    // find pivot
    for (int i = size_of_array - 2; i > 0; i--)
    { //-2 so that we can compare to # after pointer
        if (sample_array[i] < sample_array[i + 1])
        {
            pivot_index = i;
            break;
        }
    }

    // find right most # greater than pivot
    for (int j = size_of_array; j > 0; j--)
    {
        if (j > sample_array[pivot_index])
        {
            successor_index = j;
            break;
        }
    }

    // swap values
    int temp = sample_array[pivot_index];
    sample_array[pivot_index] = sample_array[successor_index];
    sample_array[successor_index] = temp;

    // sort values after pivot location
    quicksort(size_of_array - 1, size_of_array, sample_array);

    for (int k = 0; k < size_of_array; k++)
    {
        std::cout << sample_array[k] << " ";
    }
    std::cout << std::endl;
}