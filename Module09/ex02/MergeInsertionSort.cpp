#include "PmergeMe.hpp"

#define THRESHOLD 2

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

void vectorMerge(unIntVector &vector, int left, int mid, int right) 
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    std::vector<unsigned int> L(leftSize);
    std::vector<unsigned int> R(rightSize);

    for (int i = 0; i < leftSize; i++)
        L[i] = vector[left + i];
    for (int i = 0; i < rightSize; i++)
        R[i] = vector[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (L[i] <= R[j]) {
            vector[k] = L[i];
            i++;
        } else {
            vector[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < leftSize) {
        vector[k] = L[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        vector[k] = R[j];
        j++;
        k++;
    }
}

void vectorAlgo(unIntVector &vector, unsigned int left, unsigned int right, unsigned int threshold) 
{
    if (left < right) 
	{
        if (right - left <= threshold) 
		{
            vectorInsertionSort(vector, left, right);
        } else 
		{
            int mid = left + (right - left) / 2;
            vectorAlgo(vector, left, mid, threshold);
            vectorAlgo(vector, mid + 1, right, threshold);
            vectorMerge(vector, left, mid, right);
        }
    }
}

void PmergeMe::vectorMergeInsertion(unIntVector &vector) 
{
    int n = vector.size();
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

void dequeMerge(unIntDeque &deque, int left, int mid, int right) 
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    std::vector<unsigned int> L(leftSize);
    std::vector<unsigned int> R(rightSize);

    for (int i = 0; i < leftSize; i++)
        L[i] = deque[left + i];
    for (int i = 0; i < rightSize; i++)
        R[i] = deque[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (L[i] <= R[j]) {
            deque[k] = L[i];
            i++;
        } else {
            deque[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < leftSize) {
        deque[k] = L[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        deque[k] = R[j];
        j++;
        k++;
    }
}

void dequeAlgo(unIntDeque &deque, int left, int right, int threshold) 
{
    if (left < right) 
	{
        if (right - left <= threshold) 
		{
            dequeInsertionSort(deque, left, right);
        } else 
		{
            int mid = left + (right - left) / 2;
            dequeAlgo(deque, left, mid, threshold);
            dequeAlgo(deque, mid + 1, right, threshold);
            dequeMerge(deque, left, mid, right);
        }
    }
}

void PmergeMe::dequeMergeInsertion(unIntDeque &deque)
{
	int n = deque.size();
	dequeAlgo(deque, 0, n - 1, THRESHOLD);
}