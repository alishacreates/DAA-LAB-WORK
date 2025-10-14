#include <iostream>
#include <algorithm>
using namespace std;
struct Item {
    float profit, weight, ratio;
};
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}
int main(){
    int n;
    float capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[100];

    for (int i = 0; i < n; i++) {
        cout << "Enter the profit of item " << i + 1 << ": ";
        cin >> items[i].profit;
        cout << "Enter the weight of item " << i + 1 << ": ";
        cin >> items[i].weight;
        items[i].ratio = items[i].profit / items[i].weight;
    }
    cout<<"Enterthecapacity of knapsack:";
    cin >> capacity;
    sort(items, items + n, compare);
    float totalProfit = 0.0;
    float remainingCapacity = capacity;

    cout << "\nItem\tProfit\tWeight\tProfit/Weight\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << items[i].profit << "\t" << items[i].weight 
             << "\t" << items[i].ratio << endl;
    }

    cout << "\nFilling process:\n"<<endl;
    for (int i = 0; i < n; i++){
        if (remainingCapacity == 0)
            break;
        if (items[i].weight <= remainingCapacity){
            totalProfit += items[i].profit;
            remainingCapacity -= items[i].weight;
            cout << "Took full item (Profit: " << items[i].profit 
                 << ", Weight: " << items[i].weight << ")\n";
        }else{
            float fraction = remainingCapacity / items[i].weight;
            totalProfit += items[i].profit * fraction;
            cout << "Took " << fraction * 100 << "% of item (theProfit: " 
                 << items[i].profit * fraction << ")\n";
            remainingCapacity = 0;
        }
    }
    cout << "Maximum Profit = " << totalProfit << endl;
    return 0;
}