#ifndef SORTINGALGORITHMS_HPP
#define SORTINGALGORITHMS_HPP
#include <thread>
#include <chrono>
#include <vector>


template <class T>
void BubbleSort(T& arr, unsigned int elementCount){
    unsigned int i, j;
    for (i = 0; i < elementCount-1; ++i)
        for (j = 0; j < elementCount-i-1; ++j)
            if (arr[j] > arr[j+1])
               std::swap(arr[j], arr[j+1]);
}

template <class T>
void InsertionSort(T& arr)
{
    if(arr.begin() == arr.end())
        return;
    for(auto i = arr.begin() + 1; i < arr.end(); ++i)
    {
        auto k = *i;
        auto j = i - 1;
        while(j >= arr.begin() && *j > k)
        {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = k;
    }
}

template <class T>
void SelectionSort(T& arr, unsigned int n)
{
    unsigned int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
        std::swap(arr[min_idx], arr[i]);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

template <class T>
void merge(std::vector<T>& arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    T L[n1], R[n2];
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];
    int i = 0,j = 0,k = l;
    while (i < n1 && j < n2) {
        if (L[i] < R[j])
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
        ++k;
    }
    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

template <class T>
void MergeSort(T& arr, int l, int r){
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    if(l>=r){
        return;
    }
    int m = (l+r-1)/2;
    MergeSort(arr,l,m);
    MergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

template <class T>
void shuffle(T& arr, unsigned int n){
    for (unsigned int i = 0; i < n; i++)
       std::swap(arr[i], arr[rand() % n]);
}

#endif
