#ifndef EXTALG_H
#define	EXTALG_H

/**
 * well known algorithms implementation
 */

namespace mc{
    /**
     * sorting algorithms
     */
    
    template<class iterator>
    void insertion_sort(iterator first, iterator last){
        iterator i = first, j, j_1;
        ++i;
        typename iterator::value_type key;
        while(i != last){
            key = *i;
            j = i;
            j_1 = i;
            --j_1;
            while(j_1 != first && *j_1 < *j){
                *j = *j_1;
                --j;
                --j_1;
            }
            *j_1 = key;
            ++i;
        }
    }
}

#endif	/* EXTALG_H */

