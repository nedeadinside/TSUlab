#pragma warning( disable: 6386 )

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;


class SList {
    const char** list;
    int cap;
    int size;
    int comparisons;

public:
    SList(int tcap = 10) {
        cap = tcap;
        size = 0;
        comparisons = 0;
        list = new const char* [cap];
    }

    SList(const SList& B) {
        cap = B.cap;
        size = B.size;
        comparisons = B.comparisons;
        for (int i = 0; i < size; i++) {
            list[i] = B.list[i];
        }
    }

    ~SList() {
        delete[] list;
    }

    SList& operator=(const SList& B) {
        if (this != &B) {
            delete[]list;
            cap = B.cap;
            size = B.size;
            comparisons = B.comparisons;
            list = new const char* [cap];
            for (int i = 0; i < size; i++)
                list[i] = B.list[i];
        }
        return *this;
    }

    bool contains(const char* str) {
        comparisons = 0;
        for (int i = 0; i < size; i++) {
            comparisons++;
            if (strcmp(list[i], str) == 0)
                return true;
        }
        return false;
    }

    void add(const char* str) {
        if (size == cap) {
            cap++;
            const char** newList = new const char* [cap];
            
            for (int i = 0; i < size; i++)
                newList[i] = list[i];
            
            delete[] list;
            list = newList;
        }
        list[size++] = str;
    }

    void addUniq(const char* str) {
        if (!contains(str)) {
            insert(str);
        }
    }

    void merge(const SList& other) {
        for (int i = 0; i < other.size; i++) {
            add(other.list[i]);
        }
    }

    int getSize() {
        return size;
    }

    int getComparisons() {
        return comparisons;
    }

    void insert(const char* str) {
        int i = 0;
        for (i = 0; ((i < size) && (strcmp(list[i], str) < 0)); i++) { ;;;;;;;;;;; }
        //cout << i << endl;
        if (i == size) {
            add(str);
        }
        else {
            // size++;
            //cout << size << " " << cap << endl;
            const char* temps = list[size - 1];
            for (int j = size - 1; j > i; j--) {
                list[j] = list[j - 1];
            }
            list[i] = str;
            add(temps);
        }
    }

    void printlst() {
        for (int i = 0; i < size; i++) {
            cout << list[i] << endl;
        }
    }
};


class HashTable {
    int q;
    SList* table;

    int hashFunction(char* str) {
        int hash = 0;
        int len = strlen(str);
        for (int i = 0; i < len; i++)
            hash = (hash * 31 + str[i]) % q;
        return hash;
    }

public:
    HashTable(int qn) {
        q = qn;
        table = new SList[q];
    }

    ~HashTable() {
        delete[] table;
    }

    void add(char* str) {
        int index = hashFunction(str);
        table[index].addUniq(str);
    }

    void mergeAll() {
        int allsize = 0;
        for (int i = 0; i < q; i++)
            allsize += table[i].getSize();
        SList alltable(allsize);
        for (int i = 0; i < q; i++) {
            alltable.merge(table[i]);
        }
        table[0] = alltable;
    }

    int getTotalComparisons() {
        int totalComparisons = 0;
        for (int i = 0; i < q; i++)
            totalComparisons += table[i].getComparisons();
        return totalComparisons;
    }

    int getUniqueStrings() {
        return table[0].getSize();
    }
};


int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int n, q;
    int minStringLength, maxStringLength;
    char** arraystr;

    cout << "Введите n: ";
    cin >> n;
    cout << "Введите q: ";
    cin >> q;

    HashTable hashTable(q);
    // arraystr = new char* [n];

    for (int i = 0; i < n; i++) {
        int length = 1 + rand() % 11;
        char* str = new char[length + 1];

        for (int j = 0; j < length; j++) {
            str[j] = 'a' + rand() % 26;
        }

        str[length] = '\0';

        // arraystr[i] = str;
        hashTable.add(str);
    }

    hashTable.mergeAll();

    cout << "Количество сравнений: " << hashTable.getTotalComparisons() << endl;
    cout << "Уникальных строк: " << hashTable.getUniqueStrings() << endl;

    /*
            for (int i = 0; i < n; i++) {
            cout << arraystr[i] << endl;
        }
    
        for (int i = 0; i < n; i++) {
            delete[]arraystr[i];
        }
        delete[]arraystr;
    */

/*

    SList test(0);
    for (int i = 5; i >= 0; i--) {
        char* str = new char[2];
        str[0] = 'a' + i;
        str[1] = '\0';
        test.insert(str);
    }

    test.insert("foo");
    test.insert("bar");
    test.insert("baz");
    test.printlst();


*/
    return 0;
}
