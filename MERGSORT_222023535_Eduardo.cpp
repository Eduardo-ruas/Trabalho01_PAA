#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Função para mesclar duas metades do array
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Função recursiva do Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    string line;
    vector<int> arr;

    // Lê a entrada como uma única linha
    getline(cin, line);
    stringstream ss(line);
    int num;

    while (ss >> num) {
        arr.push_back(num);
    }

    // Ordena os números
    mergeSort(arr, 0, arr.size() - 1);

    // Imprime os números ordenados
    for (size_t i = 0; i < arr.size(); i++) {
        if (i > 0) cout << " ";
        cout << arr[i];
    }
    cout << endl;

    return 0;
}
