long nod1(long a, long b)	// алгоритм Евклида
{

    if (a == b) {
        return a;
    }
    if (a > b) {
        long tmp = a;
        a = b;
        b = tmp;
    }
    return gcd04(a, b - a);
}

/////////////////////////////////////////////

long nod2(long a, long b)	// алгоритм Евклида
{

    while (a != b) {
        if (a > b) {
            long tmp = a;
            a = b;
            b = tmp;
        }
        b = b - a;
    }
    return a;
}

////////////////////////////////////////////

long min(long a, long b)	// перебор от минимального числа
{
    return a > b ? b : a;
}

long nod3(long a, long b) {

    long nod = 1L;
    for (long i = min(a, b); i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            nod = i;
            break;
        }
    }
    return nod;
}