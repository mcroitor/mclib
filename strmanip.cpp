#include "strmanip.h"
#include "./algebra/matrix.h"


namespace mc {

    size_t _test(char p1, char p2) {
        return p1 == p2 ? 0 : 1;
    }

    /**
     * delete symbol at index from str
     * @param - initioal string
     * @param - position of symbol
     * @return - modified string
     */
    std::string _D(std::string str, size_t index) {
        return str.erase(index);
    }

    /**
     * insert symbol chr at index from str
     * @param - initioal string
     * @param - position of symbol
     * @param - new symbol
     * @return - modified string 
     */
    std::string _I(std::string str, size_t index, char chr) {
        return str.insert(index, 1, chr);
    }

    /**
     * replace symbol chr at index from str
     * @param - initial string
     * @param - position of symbol
     * @param - new symbol
     * @return - modified string
     */
    std::string _R(std::string str, size_t index, char chr) {
        return str.replace(index, 1, 1, chr);
    }

    /**
     * calculate Levenshtein distance from 2 strings
     * @param 
     * @param 
     * @return 
     */
    size_t distLevenshtein(std::string str1, std::string str2) {
        size_t i, j, N = str1.size(), M = str2.size(), result = 0;
        typedef size_t* size_t_ptr;

        size_t_ptr* D = new size_t_ptr[N + 1];
        for (i = 0; i <= N; ++i) {
            D[i] = new size_t[M + 1];
        }
        /*
         * TODO# : implement this!
         */
        D[0][0] = 0;
        for (j = 1; j <= N; ++j) {
            D[0][j] = D[0][j - 1] + 1; //
        }
        for (i = 1; i <= M; ++i) {
            D[i][0] = D[i - 1][0] + 1; //
            for (j = 1; j <= N; ++j) {
                D[i][j] = min(D[i - 1][j] + 1, D[i][j - 1] + 1, D[i - 1] [j - 1] + _test(str1[i - 1], str2[j - 1]));
            }
        }
        result = D[M][N];
        for (i = 0; i <= N; ++i) {
            delete[] D[i];
        }
        delete[] D;
        
        return result;
    }
}