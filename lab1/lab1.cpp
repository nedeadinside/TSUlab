#include <iostream>

using namespace std;


class Sort {
private:
    int* Ind;
    int* Array;
    int n;

public:
    Sort(int* arr, const int len) : n(len), Array(arr) {
        Ind = new int[n];
        for (int i = 0; i < n; i++) Ind[i] = i;
    }


    void shell_sort() {
        int i, j, h;
        for (h = 1; h <= n / 9; h = h * 3 + 1);
        while (h >= 1)
        {
            for (i = h; i < n; i++)
                for (j = i - h; j >= 0 && Array[Ind[j]] > Array[Ind[j + h]]; j -= h)
                    swap(Ind[j], Ind[j + h]);
            h = (h - 1) / 3;
        }
    };


    void reset_pointer() {
        for (int i = 0; i < n; i++) Ind[i] = i;
    }


    void __sift(int i, int m) {
        int j = i, k = i * 2 + 1;
        while (k <= m) {
            if (k < m && Array[Ind[k]] < Array[Ind[k + 1]]) k++;
            if (Array[Ind[j]] < Array[Ind[k]]) {
                swap(Ind[j], Ind[k]);
                j = k; k = k * 2 + 1;
            }
            else break;
        }
    }


    void heap_sort() {
        int i, m;
        for (i = n / 2; i >= 0; i--) {
            __sift(i, n - 1);
        }
        for (m = n - 1; m >= 1; --m) {
            swap(Array[Ind[0]], Array[Ind[m]]);
            __sift(0, m - 1);
        }
    }


    bool is_sorted() {
        for (int i = 0; i < n - 1; i++) {
            if (Array[Ind[i]] > Array[Ind[i + 1]]) return false;
        }
        return true;
    }


    friend ostream& operator<<(ostream& stream, Sort& obj) {
        for (int i =0; i < obj.n; i++)
            stream << obj.Array[obj.Ind[i]]<< ' ';
        return stream;
    }
};

int main()
{
    // Тесты пока не написал, впадлу
}
