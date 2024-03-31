#include <iostream>
#include <random>

using namespace std;


template <typename T>
class Sort {
public:
    
    static int sift(T A[], int Ind[], int i, int m)
    {
        int j = i, k = i * 2 + 1, change = 0;
        while (k <= m)
        {
            if (k < m && A[Ind[k]] < A[Ind[k + 1]]) { k++; }
            change++;
            if (A[Ind[j]] < A[Ind[k]]){
                swap(Ind[j], Ind[k]);
                j = k;
                k = k * 2 + 1;
            }
            else break;
        }
        return change;
    }


    static int piramid(int n, T A[], int Ind[])
    {
        int  i, m, change = 0;

        for (i = n / 2; i >= 0; i--)
            change += sift(A, Ind, i, n - 1);

        for (m = n - 1; m >= 1; m--)
        {
            swap(Ind[0], Ind[m]);
            change += sift(A, Ind, 0, m - 1);
        }
        return change;
    }


    static int shell(int n, T A[], int Ind[])
    {
        int i, j, h, change = 0;
        for (h = 1; h <= n / 9; h = h * 3 + 1);
        while (h >= 1)
        {
            for (i = h; i < n; i++)
            {
                for (j = i - h; j >= 0; j -= h)
                {
                    change++;
                    if (A[Ind[j]] > A[Ind[j + h]]) {
                        swap(Ind[j], Ind[j + h]);
                    }
                    else {
                        break;
                    }
                }
            }
            h = (h - 1) / 3;
        }
        return change;
    }


    static int is_sorted(int n, T A[], int Ind[], char name)
    {
        for (int i = 0; i < n - 1; i++)
            if (A[Ind[i]] > A[Ind[i + 1]]) {
                cout << "Массив " << name << " не отсортирован" << endl;
                return -1;
            }
        cout << "Массив " << name << " отсортирован" << endl;
        return 0;
    };
};


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(42);
    
    int n;

    cin >> n;

    typedef int T;
    T *A, *B, *C;
    int *Ind_A, *Ind_B, *Ind_C;

    A = new T[n];
    B = new T[n];
    C = new T[n];

    Ind_A = new int[n];
    Ind_B = new int[n];
    Ind_C = new int[n];

    for (int i = 0; i < n; i++)
    {
        A[i] = T(i);
        B[i] = T(n - i);
        C[i] = T(rand() % 1000);
        Ind_A[i] = i;
        Ind_B[i] = i;
        Ind_C[i] = i;
    }

    Sort<T>::is_sorted(n, A, Ind_A, 'A');
    Sort<T>::is_sorted(n, B, Ind_B, 'B');
    Sort<T>::is_sorted(n, C, Ind_C, 'C');

    cout << "Обменов при сортировке А: " << Sort<T>::shell(n, A, Ind_A) << endl;
    cout << "Обменов при сортировке B: " << Sort<T>::shell(n, B, Ind_B) << endl;
    cout << "Обменов при сортировке C: " << Sort<T>::shell(n, C, Ind_C) << endl;

    Sort<T>::is_sorted(n, A, Ind_A, 'A');
    Sort<T>::is_sorted(n, B, Ind_B, 'B');
    Sort<T>::is_sorted(n, C, Ind_C, 'C');

    for (int i = 0; i < n; i++)
    {
        Ind_A[i] = i;
        Ind_B[i] = i;
        Ind_C[i] = i;
    }

    cout << "Обменов при сортировке А: " << Sort<T>::piramid(n, A, Ind_A) << endl;
    cout << "Обменов при сортировке B: " << Sort<T>::piramid(n, B, Ind_B) << endl;
    cout << "Обменов при сортировке C: " << Sort<T>::piramid(n, C, Ind_C) << endl;

    Sort<T>::is_sorted(n, A, Ind_A, 'A');
    Sort<T>::is_sorted(n, B, Ind_B, 'B');
    Sort<T>::is_sorted(n, C, Ind_C, 'C');

    return 0;
}
