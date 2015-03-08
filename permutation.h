#ifndef PERMUTATION_H
#define	PERMUTATION_H

#include <cstdlib>
#include <ctime>
#include <iostream>

namespace mc {

    template<size_t SIZE>
    class permutation {
        size_t val[SIZE];
    public:

        permutation() {
            size_t i;
            for (i = 0; i != SIZE; ++i) {
                val[i] = i + 1;
            }
        }

        permutation(const permutation<SIZE>& p) {
            size_t i;
            for (i = 0; i != SIZE; ++i) {
                val[i] = p.val[i];
            }
        }

        permutation(const size_t* p) {
            size_t i;
            for (i = 0; i != SIZE; ++i) {
                val[i] = *(p + i);
            }
        }

        static permutation<SIZE> generate() {
            permutation<SIZE> result;
            size_t repeat = 2 * SIZE,
                    i, j;
            srand(time(0));
            while (repeat > 0) {
                --repeat;
                result.permutate(rand() % SIZE + 1, rand() % SIZE + 1);
            }
            return result;
        }

        permutation<SIZE> operator =(const permutation<SIZE>& p) {
            size_t i;
            for (i = 0; i != SIZE; ++i) {
                val[i] = p.val[i];
            }
            return *this;
        }

        void permutate(const size_t& i, const size_t& j) {
            size_t tmp;
            tmp = val[i - 1];
            val[i - 1] = val[j - 1];
            val[j - 1] = tmp;
        }

        bool operator ==(const permutation<SIZE>& p) const {
            size_t i;
            for (i = 0; i != SIZE; ++i) {
                if (val[i] != p.val[i])
                    return false;
            }
            return true;
        }

        const size_t operator [](const size_t& index) const {
            return val[index - 1];
        }

        bool inverted(const size_t& i, const size_t& j) const {
            return (i < j && val[i - 1] > val[j - 1]) || ((i > j && val[i - 1] < val[j - 1]));
        }

        size_t inversion(size_t index) {
            size_t i = 0, count = 0;
            while (val[i] != index) {
                if (val[i] > index) ++count;
                ++i;
            }
            return count;
        }
    };

    template<size_t SIZE>
    std::ostream& operator <<(std::ostream& out, const permutation<SIZE>& p) {
        size_t i = 0;
        out << "( ";
        while (i != SIZE) {
            out << p[i + 1];
            ++i;
            if (i != SIZE)
                out << ", ";
        }
        out << " )";
        return out;
    }
}

#endif	/* PERMUTATION_H */

