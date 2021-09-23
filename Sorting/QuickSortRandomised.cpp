#include<iostream>
using namespace std;

int partition(int *arr, int lo, int hi){
    int idx = lo;
    int pivot = hi;

    for(int i = lo; i < hi; i++){
        if(arr[i] < arr[pivot]){
            swap(arr[i], arr[idx]);
            idx++;
        }
    }
    swap(arr[idx], arr[pivot]);
    return pivot;
}

int randomPivotAlgo(int *arr, int lo, int hi){
    int n = rand();
    int pivot = lo + (n % (hi - lo + 1));
    swap(arr[pivot], arr[hi]);
    return partition(arr, lo, hi);
}

void QuickSort(int *arr, int lo, int hi){
    if(lo < hi){
        int pivot = randomPivotAlgo(arr, lo, hi);
        QuickSort(arr, lo, pivot - 1);
        QuickSort(arr,pivot + 1, hi);
    }
}
 
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    QuickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}