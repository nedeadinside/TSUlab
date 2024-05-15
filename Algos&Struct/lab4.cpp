#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


class Thing {
public:
    int weight;
    int price;

    Thing() {
        weight = rand() % 100 + 1; 
        price = rand() % 100 + 1;
    }
};


bool compare(Thing a, Thing b) {
    double r1 = (double)a.price / a.weight;
    double r2 = (double)b.price / b.weight;
    return r1 > r2;
}


int greedybag(vector<Thing>& items, int W) {
    sort(items.begin(), items.end(), compare);

    int currentWeight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < items.size(); i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            finalvalue += items[i].price;
        }
    }

    return finalvalue;
}


int backtrack(vector<Thing>& items, int currentWeight, int currentValue, int& bestValue, int W, int index) {
    if (currentWeight > W) {
        return -1;
    }

    if (index >= items.size()) {
        return -1;
    }

    if (currentValue > bestValue) {
        bestValue = currentValue;
    }

    backtrack(items, currentWeight + items[index].weight, currentValue + items[index].price, bestValue, W, index + 1);
    backtrack(items, currentWeight, currentValue, bestValue, W, index + 1);
}


int backtrackbag(vector<Thing>& items, int W) {
    int n = items.size();
    int currentWeight = 0;
    int currentValue = 0;
    int bestValue = 0;
    int index = 0;

    backtrack(items, currentWeight, currentValue, bestValue, W, index);

    return bestValue;
}


int dynamicbag(int W, vector<int> weights, vector<int> prices, int n) {
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(prices[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}


int main() {
    srand(time(0));
    int n = 3;
    int totalWeight = 0;


    vector<Thing> items;
    for (int i = 0; i < n; i++) {
        Thing item;
        totalWeight += item.weight;
        items.push_back(item);
    }

    int W = totalWeight / 2;


    if (n <= 10) {
        cout << "Items:" << endl;
        for (const auto& item : items) {
            cout << "Weight: " << item.weight << ", Price: " << item.price << endl;
            }
    }

    
    vector<int> weights(n);
    vector<int> prices(n);


    for (int i = 0; i < n; i++) {
        weights[i] = items[i].weight;
        prices[i] = items[i].price;
    }


    cout << "Greedy algorithm: " << greedybag(items, W) << endl;
    cout << "Backtrack algorithm: " << backtrackbag(items, W) << endl;
    cout << "Dynamic programming: " << dynamicbag(W, weights, prices, n) << endl;

    return 0;
}