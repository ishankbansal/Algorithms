#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& arr, int idx, int n){
	int left = 2 * idx;
	int right = left + 1;

	int min_idx = idx;

	if(left < n && arr[min_idx] < arr[left]){
		min_idx = left;
	}
	if(right < n && arr[min_idx] < arr[right]){
		min_idx = right;
	}

	if(min_idx != idx){
		swap(arr[min_idx], arr[idx]);
		heapify(arr, min_idx, n);
	}
}

void buildHeap(vector<int>& arr){
	for(int i = arr.size() / 2; i >= 1; i--){
		heapify(arr, i, arr.size());
	}
}

void heapSort(vector<int>& arr){
	buildHeap(arr);

	int n = arr.size();
	while(n > 2){
		swap(arr[1], arr[n - 1]);
		n--;
		heapify(arr, 1, n);
	}
}

int main(){
	vector<int> arr;
    arr.push_back(-1);
    
	int n;
	cin >> n;

	int num;

	for(int i = 0; i < n; i++){
		cin >> num;
		arr.push_back(num);
	}

	heapSort(arr);

	for(int i = 1; i <= n; i++){
		cout << arr[i] << " ";
	}
}