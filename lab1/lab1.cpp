#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


class Sort {
private:
    int* Ind;
    int* Array;
    int n, swaps_counter, sorted_flag;
    string sort_method;

public:
    Sort(int* arr, const int len) : Array(arr), n(len) {
        swaps_counter = 0;
        sorted_flag = -1;
        sort_method = "Unsorted";
        Ind = new int[n];
        for (int i = 0; i < n; ++i) Ind[i] = i;
    };


    void shell_sort() {
        int i, j, h;

        if (sorted_flag) reset_pointer();
        
        for (h = 1; h <= n / 9; h = h * 3 + 1);
        while (h >= 1)
        {
            for (i = h; i < n; ++i)
                for (j = i - h; j >= 0 && Array[Ind[j]] > Array[Ind[j + h]]; j -= h) {
                    swap(Ind[j], Ind[j + h]);
                    ++swaps_counter;
                }
            h = (h - 1) / 3;
        }
        sorted_flag = 1;
        sort_method = "Shell";
    };


    void reset_pointer() {
        for (int i = 0; i < n; ++i) Ind[i] = i;
        sorted_flag = 0;
        sort_method = "Unsorted";
        swaps_counter = 0;
    };


    void __sift(int i, int m) {
        int j = i, k = i * 2 + 1;
        while (k <= m) {
            if (k < m && Array[Ind[k]] < Array[Ind[k + 1]]) ++i;
            if (Array[Ind[j]] < Array[Ind[k]]) {
                swap(Ind[j], Ind[k]);
                ++swaps_counter;
                j = k; k = k * 2 + 1;
            }
            else break;
        }
    };


    void heap_sort() {
        int i, m;

        if (sorted_flag) reset_pointer();

        for (i = n / 2; i >= 0; --i) {
            __sift(i, n - 1);
        }
        for (m = n - 1; m >= 1; --m) {
            swap(Array[Ind[0]], Array[Ind[m]]);
            ++swaps_counter;
            __sift(0, m - 1);
        }
        sorted_flag = 1;
        sort_method = "Heap";
    };


    bool is_sorted() {
        for (int i = 0; i < n - 1; ++i) {
            if (Array[Ind[i]] > Array[Ind[i + 1]]) return false;
        }
        return true;
    };


    friend ostream& operator<<(ostream& stream, Sort& obj) {
        cout << "Lenght: " << obj.n << endl;
        cout << "Method: " << obj.sort_method << endl;
        cout << "Swaps counts: " << obj.swaps_counter << endl;
        cout << "Is Sorted?: " << obj.sorted_flag << endl;
        return stream;
    };
};

int main()
{
    srand(42);
    int n = rand() % 1000001 + 1000000;

    // First test
    cout << "First test" << endl;
    int* A;
    A = new int[n];
    
    for (int i = 0; i < n; ++i) {
        A[i] = i;
    };
    
    Sort Array_test_1(A, n);
    cout << Array_test_1.is_sorted() << endl; // Отсортирован массив или нет
    
    Array_test_1.shell_sort();
    cout << Array_test_1 << endl;

    Array_test_1.heap_sort();
    cout << Array_test_1 << endl;


    // Second Test
    cout << "Second test" << endl;
    
    int* B;
    B = new int[n];

    for (int i = 0; i < n; ++i) {
        B[i] = n - i;
    };

    Sort Array_test_2(B, n);
    cout << Array_test_2.is_sorted() << endl;

    Array_test_2.shell_sort();
    cout << Array_test_2 << endl;

    Array_test_2.heap_sort();
    cout << Array_test_2 << endl;


    // Third Test
    cout << "Second test" << endl;

    int* C;
    C = new int[n];

    for (int i = 0; i < n; ++i) {
        C[i] = rand();
    };

    Sort Array_test_3(C, n);
    cout << Array_test_3.is_sorted() << endl;

    Array_test_3.shell_sort();
    cout << Array_test_3 << endl;

    Array_test_3.heap_sort();
    cout << Array_test_3 << endl;
}