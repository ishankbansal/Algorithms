#include<iostream>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;

const ll N = 1000006;
bool sieve[N + 1];

void createSieve(){
    for(ll i = 2; i <= N; i++){
        sieve[i] = true;
    }

    for(ll i = 2; i * i <= N; i++){
        if(sieve[i]){
            for(ll j = i * i; j <= N; j++){
                sieve[j] = false;
            }
        }
    }
}

vector<ll> generatePrimes(ll n){
    vector<ll> v;
    for(ll i = 2; i <= n; i++){
        if(sieve[i]){
            v.push_back(i);
        }
    }

    return v;
}

int main(){
    int t;
    cin >> t;
    createSieve();
    while(t--){
        ll l, r;
        cin >> l >> r;

        //Step - 1 : Generate all primes
        vector<ll> primes = generatePrimes(sqrt(r));

        //Step - 2 : Create an array of size of r - l + 1 and make everyone as 1
        vector<ll> dummy(r - l + 1, 1);
    
        //Step - 3 : For all prime numbers, mark its mutiples as false
        for(ll i = 0; i < (ll)primes.size(); i++){
            
            ll firstMultilple = (l / primes[i]) * primes[i];
            if(firstMultilple < l){
                firstMultilple += primes[i];
            }

            for(ll j = max(firstMultilple, primes[i] * primes[i]); j <= r; j += primes[i]){
                dummy[j - l] = 0;
            }
        }

        //Step - 4 : Get all the prime numbers;
        for(ll i = l; i <= r; i++){
            if(dummy[i - l] == 1 && i > 1){
                cout << (i) << endl;
            }
        }
        cout << endl;
    }
    return 0;
}