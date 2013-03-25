#include <iostream>
#include <vector>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int n = 0, m = 0;
int* discovered;



int main () {

    srand (time(NULL));
    //cin >> n;
    //cin >> m;


    n = 10000;

    int** array = new int*[n]();
    for (int i = 0; i < n; i++) {
        array[i] = new int[n]();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // random number between 0 and 1
            int random = rand() % 5000;
            if (!random) {
                array[i][j] = 1;
            }
        }
    }
    
    int totalEdges = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j]) {
                totalEdges++;
            }
        }
    }

    cout << n << " " << totalEdges << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j]) {
                cout << i << " " << j << endl;
            }
        }
    }

}
