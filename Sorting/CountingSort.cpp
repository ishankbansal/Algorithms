// This sorting algorithm is used only for small range of numbers
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());

    int range = max_val - min_val + 1;
    vector<int> count(range), output(n);

    for(int i = 0; i < n; i++){
        count[arr[i] - min_val]++;
    }
    
    for(int i = 1; i < range; i++){
        count[i] += count[i - 1];
    }

    for(int i = n - 1; i >= 0; i--){
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }

    arr = output;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}
