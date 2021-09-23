#include<iostream>
using namespace std;

void merge(int *a, int s, int e){

    int mid = (s + e) / 2;

    int i = s, j = mid + 1, k = s;

    int temp[100];

    while(i <= mid && j <= e){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }

    while(i <= mid){
        temp[k++] = a[i++];
    }

    while(j <= e){
        temp[k++] = a[j++];
    }

    for(int x = s; x <= e; x++){
        a[x] = temp[x];
    }
}

void merge_sort(int *a, int s, int e){

    if(s >= e){
        return;
    } 

    int mid = (s + e) / 2;
    merge_sort(a, s, mid);
    merge_sort(a, mid + 1, e);

    merge(a, s, e);
}

int main(){
    int n;
    cout << "Enter Number of Elements\n";
    cin >> n;
    cout << "Enter Elements\n";
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    merge_sort(arr, 0, n - 1);

    cout << "Sorted Array\n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}