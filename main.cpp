#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include<chrono>
#include<random>
#include <fstream>
using namespace std;
int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}
int** get_array(int n) {
    srand(std::time(nullptr));

    int** array = new int*[n];
    for (int i = 0; i < n; ++i) {
        array[i] = new int[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            array[i][j] = getRandomNumber(1, 100); 
        }
    }

    return array;
}

void free_array(int** array, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

void writePairsToFile(const vector<pair<int, long double>>& pairs, const string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return;
    }
    for (const auto& pair : pairs) {
        file << pair.first << " " << pair.second << std::endl;
    }
    file.close();

    std::cout << "Pairs have been written to " << filename << std::endl;
}


void transpose_new(int** matrix, int** result, int n) {
    // Copy elements from the original matrix to the result matrix with transposed indices
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[j][i] = matrix[i][j];
        }
    }
}

void transpose_swap(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Swap matrix[i][j] and matrix[j][i]
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}


int main(){
    vector<pair<int,long double>> v1;
    vector<pair<int,long double>> v2;
    vector<pair<int,long double>> v3;
    vector<pair<int,long double>> v4;
    vector<pair<int,long double>> v5;
    vector<pair<int,long double>> v6;
    vector<pair<int,long double>> v7;
    vector<pair<int,long double>> v8;
    vector<pair<int,long double>> v9;
    vector<pair<int,long double>> v10;
    vector<pair<int,long double>> v11;
    vector<pair<int,long double>> v12;

    for(int n=2;n<815;n+=10){
        int** A = get_array(n);
        int** B = get_array(n);
        int** C = get_array(n);
        cout<<n<<endl;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < n; j++) {
            C[i][j]=0; 
            for (int k = 0; k < n; k++) {
                C[i][j] += (A[i][k]) * (B[k][j]);
            }
        } 
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<long double> duration = end - start;
   // cout<<duration.count()<<endl;
    v1.push_back({n,duration.count()});
    free_array(A,n);
    free_array(B,n);
    free_array(C,n);

    }
    string filename = "ijk.txt";
    writePairsToFile(v1, filename);

    for(int n=2;n<815;n+=10){
        int** A = get_array(n);
        int** B = get_array(n);
        int** C = get_array(n);
        cout<<n<<endl;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < n; j++) {
            C[i][j]=0;}}
    for (int i = 0; i < n; i++){ 
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                C[i][j] += (A[i][k]) * (B[k][j]);
            }
        } 
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<long double> duration = end - start;
   // cout<<duration.count()<<endl;
    v2.push_back({n,duration.count()});
    free_array(A,n);
    free_array(B,n);
    free_array(C,n);

    }
    
    filename = "ikj.txt";
    writePairsToFile(v2, filename);


    for(int n=2;n<815;n+=10){
        int** A = get_array(n);
        int** B = get_array(n);
        int** C = get_array(n);
        cout<<n<<endl;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < n; j++) {
            C[i][j]=0;}}
    for (int j = 0; j < n; j++){ 
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += (A[i][k]) * (B[k][j]);
            }
        } 
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<long double> duration = end - start;
   // cout<<duration.count()<<endl;
    v3.push_back({n,duration.count()});
    free_array(A,n);
    free_array(B,n);
    free_array(C,n);

    }
    
    filename = "jik.txt";
    writePairsToFile(v3, filename);





    for(int n=2;n<815;n+=10){
        int** A = get_array(n);
        int** B = get_array(n);
        int** C = get_array(n);
        cout<<n<<endl;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < n; j++) {
            C[i][j]=0;}}
    for (int k = 0; k < n; k++){ 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C[i][j] += (A[i][k]) * (B[k][j]);
            }
        } 
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<long double> duration = end - start;
   // cout<<duration.count()<<endl;
    v4.push_back({n,duration.count()});
    free_array(A,n);
    free_array(B,n);
    free_array(C,n);

    }
    
    filename = "kij.txt";
    writePairsToFile(v4, filename);


    for(int n=2;n<815;n+=10){
        int** A = get_array(n);
        int** B = get_array(n);
        int** C = get_array(n);
        cout<<n<<endl;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < n; j++) {
            C[i][j]=0;}}
    for (int j = 0; j < n; j++){ 
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                C[i][j] += (A[i][k]) * (B[k][j]);
            }
        } 
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<long double> duration = end - start;
   // cout<<duration.count()<<endl;
    v5.push_back({n,duration.count()});
    free_array(A,n);
    free_array(B,n);
    free_array(C,n);

    }
    
    filename = "jki.txt";
    writePairsToFile(v5, filename);


    for(int n=2;n<815;n+=10){
        int** A = get_array(n);
        int** B = get_array(n);
        int** C = get_array(n);
        cout<<n<<endl;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < n; j++) {
            C[i][j]=0;}}
    for (int k = 0; k < n; k++){ 
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                C[i][j] += (A[i][k]) * (B[k][j]);
            }
        } 
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<long double> duration = end - start;
   // cout<<duration.count()<<endl;
    v6.push_back({n,duration.count()});
    free_array(A,n);
    free_array(B,n);
    free_array(C,n);

    }
    
    filename = "kji.txt";
    writePairsToFile(v6, filename);

  




    for(int n=2;n<5000;n+=100){
        int** A = get_array(n);
        cout<<n<<endl;
    auto start = chrono::high_resolution_clock::now();
    transpose_swap(A,n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<long double> duration = end - start;
   // cout<<duration.count()<<endl;
    v7.push_back({n,duration.count()});
    free_array(A,n);
    

    }
    
    filename = "transpose_swap.txt";
    writePairsToFile(v7, filename);


    


    for(int n=2;n<5000;n+=100){
        int** A = get_array(n);
        int** B = get_array(n);
        cout<<n<<endl;
    auto start = chrono::high_resolution_clock::now();
    transpose_new(A,B,n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<long double> duration = end - start;
   // cout<<duration.count()<<endl;
    v8.push_back({n,duration.count()});
    free_array(A,n);
    free_array(B,n);

    }
    
    filename = "transpose_new.txt";
    writePairsToFile(v8, filename);



}