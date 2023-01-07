
/**
 * Updates boolean container to mark non-prime numbers
 *
 * @param first iterator of the begining index of factor*factor
 * @param last iterator of the last index
 * @param factor the number which is used to sieve the primes
 */
template <class RandomAccessIterator, typename Number>
void mark_sieve(RandomAccessIterator first, RandomAccessIterator last, Number factor) {
    // assert(first != last)
    *first = false;
    while (last - first > factor) {
        first = first + factor;
        *first = false;
    }
}


inline int value(int i) { return i+i + 3; }
inline int index(int v) { return (v-3)/2; }



template <class RandomAccessIterator, typename Number>
void sift1(RandomAccessIterator first, Number n) {
    RandomAccessIterator last = first + n;
    std::fill(first, last, true);
    Number i(0);
    Number index_square(3);
    Number factor(3);
    while (index_square < n) {
        if(first[i]) {
            mark_sieve(first + index_square, last, factor);
        }
        ++i;
        factor = value(i);
        index_square = index(value(i)*value(i)); // index of the value squared at index i
    }
}

template <class RandomAccessIterator, typename Number>
void sift2(RandomAccessIterator first, Number n) {
    RandomAccessIterator last = first + n;
    std::fill(first, last, true);
    Number i(0);
    Number index_square(3);
    Number factor(3);
    while (index_square < n) {
        if(first[i]) {
            mark_sieve(first + index_square, last, factor);
        }
        ++i;
        // delta_factor = 2*(i+1) + 3 - (2*i + 3)
        // delta_index_square = factor(i) + factor(i+1)
        index_square += factor;
        factor += Number(2);
        index_square += factor; 
    }

}

