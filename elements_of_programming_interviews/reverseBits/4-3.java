private long swapBits(long x, int i, int j) {
    if (((x >>> i) & 1) != ((x >>> j) & 1)) {
        long mask = (1L << i) | (1L << j);
        x ^= mask;
    }
    return x;
}


public long reverseBits(long x) {
    for (int i = 0; i < 64; i++) {
        x = swapBits(x, i, 63-i);
    }
    return x;
}
