#ifndef COMMONALGORITHMS_H
#define COMMONALGORITHMS_H
#include <iterator>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

struct EEA{
    int g;
    int s;
    int t;
};

template <typename BS>
int binary_search(BS *array, BS target, int array_size);

template <typename BFS>
BFS bfs(BFS graph, int v, std::vector<bool> discovered);
template <typename T>
void merge(T *array, size_t left, size_t mid, size_t right);

template <typename T>
void merge_sort(T *array, size_t begin, size_t end);

template <typename T>
size_t partition(T *arr, size_t start, size_t end);
template <typename T>
void quick_sort(T *arr, size_t start, size_t end);

long double binary_exponentiation(int base, int power);

struct EEA extended_euclidian_algorithm(int a,int b);

int inverse(int n, int modulo){
    return extended_euclidian_algorithm(n,modulo).t;
}

int gcd(int a, int b){ return extended_euclidian_algorithm(a,b).g;}

std::vector<int> kmp(std::string text, std::string pattern);

long int* dijkstra(long int** graph,int src,int size);

/*
    Depth First Search (DFS) Algorithm
    Kruskal’s Algorithm
    Floyd Warshall Algorithm
    Dijkstra’s Algorithm
    Bellman Ford Algorithm
    Kadane’s Algorithm
    Lee Algorithm
    Flood Fill Algorithm
    Floyd’s Cycle Detection Algorithm
    Union Find Algorithm
    Topological Sort Algorithm
    KMP Algorithm
    Insertion Sort Algorithm
    Selection Sort Algorithm
    Counting Sort Algorithm
    Heap Sort Algorithm
    Kahn’s Topological Sort Algorithm
    Huffman Coding Compression Algorithm
    Quickselect Algorithm
    Boyer–Moore Majority Vote Algorithm
    Euclid’s Algorithm
*/

#endif