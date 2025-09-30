#include <iostream>
#include <algorithm>
using namespace std;
struct Activity {
    int start, finish, index;
};
bool activityCompare(Activity a, Activity b){
    return a.finish < b.finish;
}
int main() {
    int n;
    cout << "Enter number of activities: \n";
    cin >> n;
    Activity activities[100]; 
    cout << "Enter start and finish times of activities:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
        activities[i].index = i + 1; 
    }
    sort(activities, activities + n, activityCompare);
    int S[100], k = 0;  
    S[k++] = activities[0].index;
    int previous = 0;
    for (int current = 1; current < n; current++) {
        if (activities[current].start >= activities[previous].finish) {
            S[k++] = activities[current].index;
            previous = current;
        } else {
            cout << "Activity " << activities[current].index << " is not possible\n";
        }
    }
    cout << "\nOptimal set of activities: ";
    for (int i = 0; i < k; i++) {
        cout << "A" << S[i] << " ";
    }
    cout << endl;
    return 0;
}
