bool odd(int n) { return n & 0x1; }
int half(int n) { return n >> 1; }

// Tail recursive multiply hepler function
// the invariant r + na = r0 + n0a0 is held throughout the function call
int mult_acc1(int r, int n, int a) {
    if (odd(n)) {
        r = r + a;
        if (n == 1) return r;
    }
    return mult_acc1(r, half(n), a + a);
}

// Strictly tail recursive function, easier to convert it to iterative
int mult_acc2(int r, int n, int a) {
    if(odd(n)) {
        r = r + a;
        if(n == 1) return r;
    }
    n = half(n);
    a = a+a;
    return mult_acc2(r, n, a);
}

//Iterative call
int mult_acc3(int r, int n, int a) {
    while(true) {
        if(odd(n)) {
            r = r + a;
            if(n == 1) return r;
        }
        n = half(n);
        a = a + a;
    }
}


int multiply1(int n, int a) {
    if(n == 1) return a;
    return mult_acc3(a, n-1, a);
}

// If n is a power of 2, mult_acc4 will be called with a number whose binary
// representation is all 1s, worst case for mult_acc4
int multiply2(int n, int a) {
    while (!odd(n)) {
        a = a+a;
        n = half(n);
    }
    if (n==1) return a;
    return mult_acc3(a, half(n-1), a+a); // n-1 is even so skip extra odd check
}