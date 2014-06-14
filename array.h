#ifndef MC_ARRAY_H
#define	MC_ARRAY_H
#include "defines.h"
namespace mc {

/**
     * This class represents an array with static numbre of elements.
     * It is compatible with STL (in a most parts).
     */
    template <typename TYPE, size_t SIZE>
    class array {
        TYPE el[SIZE];
    public:
        typedef TYPE value_type;
        typedef TYPE& reference;
        typedef const TYPE& const_reference;
        typedef TYPE* pointer;
        typedef const TYPE* const_pointer;
        typedef TYPE* iterator;
        typedef const TYPE* const_iterator;

        array() {
        }

        array(TYPE* p, size_t s) {
            size_t i;
            for (i = 0; i != s && i != SIZE; ++i) {
                el[i] = p[i];
            }
        }

        array(const array<TYPE, SIZE>& a) {
            size_t i;
            for (i = 0; i != SIZE; ++i) {
                el[i] = a.el[i];
            }
        }

        ~array() {
        }

        array<TYPE, SIZE> operator =(const array<TYPE, SIZE>& a) {
            size_t i;
            for (i = 0; i != SIZE; ++i) {
                el[i] = a.el[i];
            }
            return *this;
        }
        TYPE& operator [](const size_t& i) {
            if (i > SIZE) throw BOUND_ERROR;
            return el[i];
        }
        const TYPE& operator [](const size_t& i) const{
            if (i > SIZE) throw BOUND_ERROR;
            return el[i];
        }

        iterator begin() {
            return el;
        }

        const_iterator begin() const {
            return el;
        }

        iterator end() {
            return el + SIZE;
        }

        const_iterator end() const {
            return el + SIZE;
        }

        bool operator ==(const array<TYPE, SIZE>& a) {
            size_t i;
            for (i = 0; i != SIZE; ++i) {
                if (el[i] != a.el[i]) return false;
            }
            return true;
        }

        size_t size() const {
            return SIZE;
        }

        size_t max_size() const {
            return SIZE;
        }

        bool empty() const {
            return false;
        }

        void swap(array<TYPE, SIZE>& a) {
            array<TYPE, SIZE> tmp = a;
            a = *this;
            *this = tmp;
        }
    };
}

#endif	/* ARRAY_H */

