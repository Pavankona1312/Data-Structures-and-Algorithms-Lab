#include "common.h"

// Add two matrices
Matrix add(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, vector<int>(n));
  // TODO
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      C[i][j] = A[i][j]+B[i][j];
    }
  }
  return C;
}

// Subtract two matrices
Matrix subtract(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, vector<int>(n));
  // TODO
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      C[i][j] = A[i][j] - B[i][j];
    }
  }
  return C;
}

// Naive O(N^3) matrix multiplication
Matrix naiveMultiply(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, vector<int>(n));
  // TODO
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int num=0;
      for(int k=0;k<n;k++){
        num+=A[i][k]*B[k][j];
      }
      C[i][j]=num;
    }
  }
  return C;
}

// Strassen's matrix multiplication, use the reference for the algorithm
Matrix strassenMultiply(const Matrix &A, const Matrix &B, int threshold) {
  int n = A.size();
  Matrix C(n, vector<int>(n));
  // TODO
  if(n<=threshold){
    C=naiveMultiply(A,B);
    return C;
  }
  else{
    Matrix A12((n)/2,vector<int>((n)/2));
    Matrix A11((n)/2,vector<int>((n)/2));
    Matrix A21((n)/2,vector<int>((n)/2));
    Matrix A22((n)/2,vector<int>((n)/2));
    Matrix B11((n)/2,vector<int>((n)/2));
    Matrix B12((n)/2,vector<int>((n)/2));
    Matrix B21((n)/2,vector<int>((n)/2));
    Matrix B22((n)/2,vector<int>((n)/2));
    for(int i=0;i<n/2;i++){
      for(int j=0;j<n/2;j++){
        A11[i][j] = A[i][j];
        A12[i][j] = A[n/2+i][j];
        A21[i][j] = A[i][n/2+j];
        A11[i][j] = A[n/2+i][n/2+j];
        B11[i][j] = B[i][j];
        B12[i][j] = B[n/2+i][j];
        B21[i][j] = B[i][n/2+j];
        B11[i][j] = B[n/2+i][n/2+j];
      }
    }
    Matrix M1((n)/2,vector<int>((n)/2));
    Matrix M2((n)/2,vector<int>((n)/2));
    Matrix M3((n)/2,vector<int>((n)/2));
    Matrix M4((n)/2,vector<int>((n)/2));
    Matrix M5((n)/2,vector<int>((n)/2));
    Matrix M6((n)/2,vector<int>((n)/2));
    Matrix M7((n)/2,vector<int>((n)/2));
    M1 = strassenMultiply(add(A11,A12),add(B11,B12),threshold);
    M2 = strassenMultiply(add(A21,A22),B11,threshold);
    M5 = strassenMultiply(add(A11,A12),B22,threshold);
    M6 = strassenMultiply(subtract(A21,A11),add(B11,B12),threshold);
    M3 = strassenMultiply(A11,subtract(B12,B22),threshold);
    M4 = strassenMultiply(A22,subtract(B21,B11),threshold);
    M7 = strassenMultiply(subtract(A12,A22),add(B21,B22),threshold);
    for(int i=0;i<n/2;i++){
      for(int j=0;j<n/2;j++){
        C[i][j] = M1[i][j] + M4[i][j] + M7[i][j] - M5[i][j];
        C[i+n/2][j] = M3[i][j] + M5[i][j];
        C[i][j+n/2] = M2[i][j] + M4[i][j];
        C[i+n/2][j+n/2] = M1[i][j] + M3[i][j] + M6[i][j] - M2[i][j];
      }
    }
  }
  return C;
}



bool equal(const Matrix &A, const Matrix &B) {
    /*
        Returns True if the input matrices are equal and false otherwise
    */
    // TODO
 // Dummy return
    int n=A.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]!=B[i][j]) return false;
        }
    }
    return true;
}
