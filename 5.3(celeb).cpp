#include <iostream>
using namespace std;
bool knows(int a, int b, int matrix[][4]) {
    return matrix[a][b];
}
int findCelebrityBruteForce(int n, int matrix[][4]) {
    for (int i = 0; i < n; i++) {
        bool isCelebrity = true;
        for (int j = 0; j < n; j++) {
            if (i != j && knows(i, j, matrix)) {
                isCelebrity = false; 
                break;
            }
        }

        if (isCelebrity) {
            for (int j = 0; j < n; j++) {
                if (i != j && !knows(j, i, matrix)) {
                    isCelebrity = false; 
                    break;
                }
            }
        }

        if (isCelebrity) return i; 
    }
    return -1; 
}
int main() {
    int n = 4;
    int matrix[4][4] = {
        {0, 1, 1, 0}, 
        {0, 0, 1, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 1, 0}  
    };

    int celeb = findCelebrityBruteForce(n, matrix);
    if (celeb == -1) {
        cout << "No celebrity exists\n";
    } else {
        cout << "Celebrity is person " << celeb << "\n";
    }

    return 0;
}

