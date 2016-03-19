#ifndef EXTALG_H
#define EXTALG_H

/**
 * well known algorithms implementation
 */

namespace mc {

    /**
     * sorting algorithms
     */

    template<class iterator>
    void insertion_sort(iterator first, iterator last) {
        iterator i = first, j, j_1;
        ++i;
        typename iterator::value_type key;
        while (i != last) {
            key = *i;
            j = i;
            j_1 = i;
            --j_1;
            while (j_1 != first && *j_1 < *j) {
                *j = *j_1;
                --j;
                --j_1;
            }
            *j_1 = key;
            ++i;
        }
    }

    template<class element>
    void bubble_sort(element* ar, size_t size) {
        size_t i, j;
        for (i = 0; i != size - 1; ++i) {
            for (j = i + 1; j != size; ++j) {
                if (ar[i] > ar[j]) {
                    element tmp = ar[i];
                    ar[i] = ar[j];
                    ar[j] = tmp;
                }
            }
        }
    }

    template<class iterator>
    void bubble_sort(iterator first, iterator last) {
        iterator i, j;
        iterator::value_type tmp;
        for (i = first; i != last - 1; ++i) {
            for (j = i + 1; j != last; ++j) {
                if (*i > *j) {
                    tmp = *i;
                    *i = *j;
                    *j = tmp;
                }
            }
        }
    }
}

#endif /* EXTALG_H */

