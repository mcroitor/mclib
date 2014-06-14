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
    };
}
#endif	/* MATRIX_H */

