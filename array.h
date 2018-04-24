#ifndef MC_ARRAY_H
#define	MC_ARRAY_H
#include "defines.h"
#include <iostream>

namespace mc {

    /**
     * This class represents an array with static numbre of elements.
     * It is compatible with STL (in a most parts).
     * standard C++11 contains this class
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
            size_t i;
            for (i = 0; i != SIZE; ++i) {
                el[i] = TYPE();
            }
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

        array<TYPE, SIZE> operator=(const array<TYPE, SIZE>& a) {
            size_t i;
            for (i = 0; i != SIZE; ++i) {
                el[i] = a.el[i];
            }
            return *this;
        }

        TYPE& operator[](const size_t& i) {
            if (i > SIZE) throw BOUND_ERROR;
            return el[i];
        }

        const TYPE& operator[](const size_t& i) const {
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

        bool operator==(const array<TYPE, SIZE>& a) const {
            size_t i;
            for (i = 0; i != SIZE; ++i) {
                if (el[i] != a.el[i]) return false;
            }
            return true;
        }

        static size_t size() const {
            return SIZE;
        }

        static size_t max_size() const {
            return SIZE;
        }

        static bool empty() const {
            return false;
        }

        void swap(array<TYPE, SIZE>& a) {
            array<TYPE, SIZE> tmp = a;
            a = *this;
            *this = tmp;
        }
    };

    template<class TYPE, size_t SIZE>
    std::ostream& operator<<(std::ostream& out, const array<TYPE, SIZE>& a) {
        size_t i;
        for (i = 0; i != SIZE; ++i) {
            out << a[i] << " ";
        }
        return out;
    }
}

#endif	/* ARRAY_H */

