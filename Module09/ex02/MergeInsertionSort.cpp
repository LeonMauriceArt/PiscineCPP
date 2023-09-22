#include "PmergeMe.hpp"
#include <iostream>
#include <vector>

#define THRESHOLD 2

// Function to perform insertion sort on a portion of the vector
void vectorInsertionSort(std::vector<unsigned int>& vector, int left, int right) 
{
    for (int i = left + 1; i <= right; ++i) 
	{
        unsigned int key = vector[i];
        int j = i - 1;

        while (j >= left && vector[j] > key) 
		{
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = key;
    }
}

// Function to merge two subarrays of arr[]
void vectorMerge(unIntVector &vector, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<unsigned int> L(n1);
    std::vector<unsigned int> R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = vector[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = vector[mid + 1 + i];

    // Merge the temporary vectorays back into vector[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vector[k] = L[i];
            i++;
        } else {
            vector[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        vector[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        vector[k] = R[j];
        j++;
        k++;
    }
}

// Merge-Insertion Sort function
void vectorAlgo(unIntVector &vector, unsigned int left, unsigned int right, unsigned int threshold) 
{
    if (left < right) 
	{
        // If the number of elements is less than or equal to the threshold,
        // use insertion sort for better performance on small arrays
        if (right - left <= threshold) 
		{
            vectorInsertionSort(vector, left, right);
        } else 
		{
            int mid = left + (right - left) / 2;
            // Recursively sort the first and second halves
            vectorAlgo(vector, left, mid, threshold);
            vectorAlgo(vector, mid + 1, right, threshold);
            // Merge the sorted halves
            vectorMerge(vector, left, mid, right);
        }
    }
}

// Wrapper function for mergeInsertionSort
void PmergeMe::vectorMergeInsertion(unIntVector &vector) 
{
    int n = vector.size();
    // Set a THRESHOLD for when to switch to insertion sort
    vectorAlgo(vector, 0, n - 1, THRESHOLD);
}

//
// SAME FUNCTIONS BUT FOR DEQUE
//

void dequeInsertionSort(unIntDeque &deque, int left, int right) 
{
    for (int i = left + 1; i <= right; ++i) 
	{
        unsigned int key = deque[i];
        int j = i - 1;

        while (j >= left && deque[j] > key) 
		{
            deque[j + 1] = deque[j];
            j--;
        }
        deque[j + 1] = key;
    }
}

// Function to merge two subarrays of arr[]
void dequeMerge(unIntDeque &deque, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<unsigned int> L(n1);
    std::vector<unsigned int> R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = deque[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = deque[mid + 1 + i];

    // Merge the temporary dequeays back into deque[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            deque[k] = L[i];
            i++;
        } else {
            deque[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        deque[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        deque[k] = R[j];
        j++;
        k++;
    }
}

// Merge-Insertion Sort function
void dequeAlgo(unIntDeque &deque, unsigned int left, unsigned int right, unsigned int threshold) 
{
    if (left < right) 
	{
        // If the number of elements is less than or equal to the threshold,
        // use insertion sort for better performance on small arrays
        if (right - left <= threshold) 
		{
            dequeInsertionSort(deque, left, right);
        } else 
		{
            int mid = left + (right - left) / 2;
            // Recursively sort the first and second halves
            dequeAlgo(deque, left, mid, threshold);
            dequeAlgo(deque, mid + 1, right, threshold);
            // Merge the sorted halves
            dequeMerge(deque, left, mid, right);
        }
    }
}

void PmergeMe::dequeMergeInsertion(unIntDeque &deque)
{
	int n = deque.size();
	dequeAlgo(deque, 0, n - 1, THRESHOLD);
}