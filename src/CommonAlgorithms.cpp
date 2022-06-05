#include "CommonAlgorithms.hpp"
#include <iterator>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include <limits>


template <typename BS>
int binary_search(BS* array,BS target, int array_size){
    for(int i = array_size>>1, differencer = array_size>>2;differencer>=0;differencer= differencer>>1){    
        if(array[i] == target)
            return i;
        if(array[i] > target)
            i -= differencer;
        else
            i += differencer;
    }
    return -1;
}

template <typename BFS>
BFS bfs(BFS graph, int v, std::vector<bool> discovered)
{
    std::queue<int> q;
 
    discovered[v] = true;
    q.push(v);
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (int u: graph.adjList[v])
        {
            if (!discovered[u])
            {
                discovered[u] = true;
                q.push(u);
            }
        }
    }
}


template <typename T>
void merge(T* array, size_t left,size_t mid, size_t right)
{
    size_t const Aone = mid - left + 1;
    size_t const Atwo = right - mid;
    size_t i = 0;
    size_t i_left = 0;
    size_t i_right = 0;
  

    std::unique_ptr<T[]> left_array (new T[Aone]) ;
    std::unique_ptr<T[]> right_array (new T[Atwo]) ;

    // fill copy
    for (i = 0; i < Aone; i++)
        left_array[i] = array[left + i];
    for (i = 0; i < Atwo; i++)
        right_array[i] = array[mid + 1 + i];
  
    i = left;
  
    // build back
    while (i_left < Aone && i_right < Atwo) {
        if (left_array[i_left] <= right_array[i_right]) {
            array[i] = left_array[i_left];
            i_left++;
        }
        else {
            array[i] = right_array[i_right];
            i_right++;
        }
        i++;
    }
    // leftovers from left array
    while (i_left < Aone) {
        array[i] = left_array[i_left];
        i_left++;
        i++;
    }
    // leftovers from right array
    while (i_right < Atwo) {
        array[i] = right_array[i_right];
        i_right++;
        i++;
    }
    left_array.reset();
    right_array.reset();
}
  

template <typename T>
void merge_sort(T* array, size_t begin, size_t end){
    if (begin >= end)
        return;
  
    size_t mid = begin + (end - begin) / 2;
    merge_sort(array, begin, mid);
    merge_sort(array, mid + 1, end);
    merge(array, begin, mid, end);
}


template <typename T>
size_t partition(T* arr, size_t start, size_t end){
 
    T pivot = arr[start],tmp;
 
    size_t count = 0;
    for (size_t i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 

    size_t pivotIndex = start + count;
    tmp = arr[pivotIndex];
    arr[pivotIndex] = arr[start];
    arr[start] = tmp;

    // Sorting left and right parts of the pivot element
    size_t i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    return pivotIndex;
}
 
template <typename T>
void quick_sort(T* arr, size_t start, size_t end){

    if (start >= end)
        return;

    size_t p = partition(arr, start, end);

    quick_sort(arr, start, p - 1);
    quick_sort(arr, p + 1, end);
}

long double  binaryExponentiation(int base, int power){
    long double result = 1;
    int p=power;
    if(p<0)
        p*=-1;

    while(p>0){
        if(p&1)
            result*=base;
        base*=base;
        p=p>>1;
    }
    if(power<0)
        return 1/result;

    return result;

}


struct EEA extended_euclidian_algorithm(int a,int b){
    if(a<b){
        a+=b;
        b=a-b;
        a-=b;
    }
    int s1 =0,s2=0,t1=0,t2=1,r=0,q=0,t=0,s=0;
    while (true){
        if(a%b==0)
            break;
        r = a % b;
        q = (a-r)/b;
        s=s1-s2*q;
        t=t1-t2*q;
        a=b;
        b=r;
        s1=s2;
        s2=s;
        t1=t2;
        t2=t;
    }
    struct EEA res;
    res.g=r;
    res.s=s;
    res.t=t;
    return res;

}

std::vector<int> kmp(std::string text, std::string pattern){
    int i=1,j=0;
    auto l = new int[pattern.length()];
    std::vector<int> sol;

    l[0]=0;
    while(i<int(pattern.length())){
        if(pattern[i]==pattern[j])
            l[i++]= ++j;
        else{
            if(j != 0)
                j=l[j-1];
            else
                l[i++] = 0;
        }
    }
    i=0;
    j=0;
    while (i<int(text.length())){
        if (text[i]==pattern[j]){
            i++;
            j++;
        }
        if(j == int(pattern.length())){
            sol.push_back(i-j);
            j = l[j-1];
        }
        else if (i<int(text.length())&&pattern[j]!=text[i]){
            if(j!=0)
                j= l[j-1];
            else
                i++;
        }
        
    }
    delete[] l;
    return sol;
}


long int* dijkstra(long int** graph,int src,int size){
    auto distance= new long int[size];                             
    auto set= new bool[size];
    int i, j;
    long int mind,mini;
     
    for(i = 0; i<size; i++){
        distance[i] = std::numeric_limits<long int>::max();
        set[i] = false;    
    }
    
    distance[src] = 0;               
    
    for(i = 0; i<size; i++){
        mini=std::numeric_limits<long int>::max();
              
        for(int k=0;k<size;k++) {
            if(set[k]==false && distance[k]<=mini){
            mini=distance[k];
            mind=k;
            }
        }

        set[mind]=true;
        for(j = 0; j<size; j++)
            if(set[j]==false && graph[mind][j]!=0 && distance[mind]!=std::numeric_limits<long int>::max() && distance[mind]+graph[mind][j]<distance[j])
                distance[j]=distance[mind]+graph[mind][j];
    }
    return distance;
}
