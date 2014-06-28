#ifndef MATRIX_H
#define	MATRIX_H

#include "array.h"
#include <iostream>

/**
 * an implementation of linnear algebra it provides.
 */
namespace mc {

    template<class TYPE, size_t NUM_ROWS, size_t NUM_COLS>
    class matrix {
    public:
        typedef mc::array<TYPE, NUM_COLS> ROW_TYPE;
    private:
        mc::array<ROW_TYPE, NUM_ROWS> elements;
    public:

        matrix() {
            size_t i, j;
            for(i = 0; i != NUM_ROWS; ++i){
                for(j = 0; j != NUM_COLS; ++j){
                    elements[i][j] = TYPE();
                }
            }
        }

        ROW_TYPE& operator[](const size_t& index) {
            return elements[index];
        }

        const ROW_TYPE& operator[](const size_t& index) const {
            return elements[index];
        }

        matrix<TYPE, NUM_ROWS, NUM_COLS>& operator=(const matrix<TYPE, NUM_ROWS, NUM_COLS>& m) {
            elements = m.elements;
            return * this;
        }

        bool operator==(const matrix<TYPE, NUM_ROWS, NUM_COLS>& m) const {
            return elements == m.elements;
        }

        void operator+=(const matrix<TYPE, NUM_ROWS, NUM_COLS>& m) {
            size_t i, j;
            for (i = 0; i != NUM_ROWS; ++i) {
                for (j = 0; j != NUM_COLS; ++j) {
                    elements[i][j] += m.elements[i][j];
                }
            }
        }

        void operator-=(const matrix<TYPE, NUM_ROWS, NUM_COLS>& m) {
            size_t i, j;
            for (i = 0; i != NUM_ROWS; ++i) {
                for (j = 0; j != NUM_COLS; ++j) {
                    elements[i][j] -= m.elements[i][j];
                }
            }
        }
        
        void swap_cols(size_t i, size_t j){
            size_t k;
            TYPE aux;
            for(k = 0; k != NUM_ROWS; ++k){
                aux = elements[k][i];
                elements[k][i] = elements[k][j];
                elements[k][j] = aux;
            }
        }
        void swap_rows(size_t i, size_t j){
            ROW_TYPE aux = elements[i];
            elements[i] = elements[j];
            elements[j] = aux;
        }
    };

    template<class TYPE, size_t NUM_ROWS, size_t NUM_COLS>
    matrix<TYPE, NUM_COLS, NUM_ROWS> transponate(const matrix<TYPE, NUM_ROWS, NUM_COLS>& p) {
        matrix<TYPE, NUM_COLS, NUM_ROWS> result;
        size_t i, j;
        for (i = 0; i != NUM_ROWS; ++i) {
            for (j = 0; j != NUM_COLS; ++j) {
                result[j][i] = p[i][j];
            }
        }
        return result;
    }

    template<class TYPE, size_t NUM_ROWS, size_t NUM_COLS>
    matrix<TYPE, NUM_ROWS, NUM_COLS> operator+(const matrix<TYPE, NUM_ROWS, NUM_COLS>& m1, const matrix<TYPE, NUM_ROWS, NUM_COLS>& m2) {
        matrix<TYPE, NUM_ROWS, NUM_COLS> tmp(m1);
        tmp += m2;
        return tmp;
    }

    template<class TYPE, size_t NUM_ROWS, size_t NUM_COLS>
    matrix<TYPE, NUM_ROWS, NUM_COLS> operator-(const matrix<TYPE, NUM_ROWS, NUM_COLS>& m1, const matrix<TYPE, NUM_ROWS, NUM_COLS>& m2) {
        matrix<TYPE, NUM_ROWS, NUM_COLS> tmp(m1);
        tmp -= m2;
        return tmp;
    }

    template<class TYPE1, class TYPE2, size_t NUM_ROWS, size_t NUM_COLS>
    matrix<TYPE1, NUM_ROWS, NUM_COLS> operator*(const matrix<TYPE1, NUM_ROWS, NUM_COLS>& m, const TYPE2& p) {
        matrix<TYPE1, NUM_ROWS, NUM_COLS> tmp;
        size_t i, j;
        for (i = 0; i != NUM_ROWS; ++i) {
            for (j = 0; j != NUM_COLS; ++j) {
                tmp[i][j] = m[i][j] * p;
            }
        }
        return tmp;
    }

    template<class TYPE1, class TYPE2, size_t NUM_ROWS, size_t NUM_COLS>
    matrix<TYPE1, NUM_ROWS, NUM_COLS> operator*(const TYPE2& p, const matrix<TYPE1, NUM_ROWS, NUM_COLS>& m) {
        matrix<TYPE1, NUM_ROWS, NUM_COLS> tmp;
        size_t i, j;
        for (i = 0; i != NUM_ROWS; ++i) {
            for (j = 0; j != NUM_COLS; ++j) {
                tmp[i][j] = p * m[i][j];
            }
        }
        return tmp;
    }
    
    template<class TYPE, size_t NUM_ROWS, size_t NUM_COLS>
    std::ostream& operator << (std::ostream& out, const matrix<TYPE, NUM_ROWS, NUM_COLS>& m){
        size_t i, j;
        for(i = 0; i != NUM_ROWS; ++i){
            out << m[i] << "\n";
        }
        return out;
    }
}
#endif	/* MATRIX_H */

