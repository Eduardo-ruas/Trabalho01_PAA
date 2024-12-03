#include <iostream>
#include <vector>
#include <algorithm> // Para lower_bound
#include <cstdio>   // Para scanf e printf

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, Q;
  scanf("%d %d", &N, &Q); 
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i < Q; ++i) {
    int query;
    scanf("%d", &query);
    auto it = lower_bound(arr.begin(), arr.end(), query); 
    if (it != arr.end() && *it == query) {
      printf("%ld\n", it - arr.begin()); 
    } else {
      printf("-1\n");
    }
  }

  return 0;
}