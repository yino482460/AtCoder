#define swap(a, b) (a+=b, b=a-b, a-=b)
// ソート
void quicksort (int left, int right, long a[]) {
    long pivot = a[(left+right)/2];
    int i = left, j = right;
    // ソート
    while (1) {
        while (a[i]  > pivot ) { i++; }
        while (a[j] < pivot ) { j--; }
        if (i >= j) {
            break;
        }
        swap(a[i], a[j]);
        i++; j--;
    }
    if (left < i-1) {
        quicksort(left, i-1, a);
    }
    if (j+1 < right) {
        quicksort(j+1, right, a);
    }
}
