#ifndef sort_h
#define sort_h
#endif /* sort_h */

using namespace std;

template <typename T>
class Sort {
private:
    static void sift(T* A[], int i, int m) {
        int k = i * 2 + 1;
        while (k <= m) {
            if (k<m && *A[k] > *A[k + 1]) { k++; }
            if (*A[i] > *A[k]) {
                swap(A[i], A[k]);
                i = k;
                k = k * 2 + 1;
            }
            else break;
        }
    }

public:
    static void piramid(int n, T* A[]) {
        int  i, m;
        for (i = n / 2; i >= 0; i--) {
            sift(A, i, n - 1);
        }

        for (m = n - 1; m >= 1; m--) {
            swap(A[0], A[m]);
            sift(A, 0, m - 1);
        }
    }
};