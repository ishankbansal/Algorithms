#include<iostream>
using namespace std;

int partition(int *a,int s, int e){

    int i = s - 1;
    int j = s;
    int pivot  = a[e];
    for( ;j <= e - 1; j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}

void quick_sort(int *a,int s, int e){
   
    if(s >= e){
        return;
    }

    int p = partition(a, s, e);
    quick_sort(a, s, p - 1);
    quick_sort(a, p + 1, e);
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quick_sort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}