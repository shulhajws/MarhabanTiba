#ifndef _GRIDSTORAGE_HPP_
#define _GRIDSTORAGE_HPP_

#include <iostream>
#include <vector> //dynamic array
#include <string>
#include <map> //dictionary pairs

using namespace std;

// template<class T>
class Storage {
    private :
        //player storageOwner;
        int row;
        int col;
        vector<vector<int> > storageContent;
        map<string, int> store;
    public :
        Storage();
        ~Storage();
        void setItem(int row, int col, int content);
        int getItemInfo(int row, int col);
        int getItem(int row, int col);
        void printStorage();
};

// #define TWO_DIM_VEC vector< vector<string>>

// // this structure allow us to hold dimension for our matrix
// struct st_matrix_dim {
//     int rows, cols;
// };

// class Matrix {
//     public : 
//         Matrix();
//         ~Matrix();
//         void initialize(string var, int rowSize, int colSize, string strVal);
//         void setVal(string var, int rowNum, int colNum, string strVal);
//         string getVal(string var, int rowNum, int colNum);
//         int getRows(string var);
//         int getCols(string var);
//         void printMatrix(string var);
//     private :
//         map<string, TWO_DIM_VEC> store; // map to our two dimensional vector
//         map<string, bool> lookup; //apakah value ada di matrix
//         map<string, st_matrix_dim> matrix_dim; //store our structure which contain structure and column
// };

// Matrix::Matrix() {}
// Matrix::~Matrix() {}
// void Matrix::initialize(string var, int rowSize, int colSize, string strVal){
//     TWO_DIM_VEC vec_matrix;
//     vec_matrix.resize(rowSize+1);

//     for(int i = 0; i < vec_matrix.size(); i++){
//         vec_matrix[i].resize(colSize+1, strVal);
//     }
//     st_matrix_dim s;
//     s.cols = colSize;
//     s.rows = rowSize;

//     this->store[var] = vec_matrix;
//     this->matrix_dim[var] = s;
//     lookup[var] = true;
// }

// int Matrix::getRows(string var){
//     return this->matrix_dim[var].rows;
// }

// int Matrix::getCols(string var){
//     return this->matrix_dim[var].cols;
// }

// void Matrix::setVal(string var, int rowNum, int colNum, string strVal){
//     if(rowNum > getRows(var) || colNum > getCols(var)){
//         cout << "Cannot set data because it's outside the boundary of the array." << endl;
//         return;
//     }
//     this->store[var][rowNum][colNum] = strVal;
// }

// string Matrix::getVal(string var, int rowNum, int colNum){
//     if(rowNum > getRows(var) || colNum > getCols(var)){
//         cout << "Cannot set data because it's outside the boundary of the array." << endl;
//         return;
//     }
//     return this->store[var][rowNum][colNum];
// }

// void Matrix::printMatrix(string var){
//     if (lookup[var]){ //if it exist
//         int rows = this->getRows(var);
//         int cols = this->getCols(var);
//         cout << "Matrix: " << var << endl;
//         cout << "rows: " << rows << "cols: " << cols << endl;
//         for(int i = 0; i <= rows; i++){
//             for(int j = 0; j <= cols; j++) {
//                 cout << "[" << this->getVal(var, i, j) << "]";
//             }
//             cout << endl;
//         }
//     }
// }

// template<class T>
// class Storage {
//     private :
//         //player storageOwner;
//         int row;
//         int col;
//         vector<vector<T>> storageContent;
//     public :
//         GridStorage();
//         ~GridStorage();
//         void setItem(int row, int col, T content);
//         int getItemInfo(int row, int col);
//         int getItem(int row, int col);
//         virtual void printJudul();
//         void printStorage();
// };

#endif