#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n, a, sum, *d, min;
    cout << "Enter the size of a square matrix: " << endl;
    cin >> m;
    n=m;
    if (m > 10 || m < 1){
        cout << "Wrong size. Please, enter the number from 1 to 10. " << endl;
        exit(0);
    }
    vector<vector<int>> matrix(m);
    for (int i = 0; i < m; i+=1){
        matrix[i].resize(n);
        }
    for (int i = 0; i < m; i+=1) {
        for (int j=0; j < n;j+=1) {
            matrix[i][j]=rand()%1500-300;
        }
    }
    for (int i = m-2; i >= 0; i-=1) {
        for (int j=0; j < n-(i+1);j+=1) {
            matrix[i][j]=0;
        }
    }
    for (int i = 0; i < m; i+=1) {
        for (int j=0; j < n; j+=1) {
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
    //sum
    a=0;
    sum=0;
    for (int i = 0; i < m; i+=1) {
        for (int j=0; j < n; j+=1) {
            if (matrix[i][j]<0){
                a+=1;
            }
        }
        if (a == 0) {
            for (int k=0; k<n; k+=1){
                d=&matrix[i][k];
                sum+=*d;
            }
        }
        a=0;
    }
    cout << "The sum of the elements in those rows that do not contain negative elements:   " << sum << endl;
    //min
    min=0;
    for (int i = 1; i < m; i+=1) {
        for (int j=0; j < i;j+=1) {
            if (matrix[i][j]<min){
                min=matrix[i][j];
            }
        }
    }
    for (int i = m-2; i >= 0; i-=1) {
        for (int j=n-1; j > i; j-=1) {
            if (matrix[i][j]<min){
                min=matrix[i][j];
            }
        }
    }
    cout << "Minimum among elements of diagonals parallel to the main diagonal of the matrix, not including the main diagonal:   " << min;
    return 0;
}
