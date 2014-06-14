#ifndef MATRIX_H
#define	MATRIX_H

#include "array.h"


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
        }
        ROW_TYPE& operator [](const size_t& index) {
            return elements[index];
        }
        const ROW_TYPE& operator [](const size_t& index) const {
            return elements[index];
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
}
#endif	/* MATRIX_H */

