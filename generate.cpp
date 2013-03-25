#include <iostream>
#include <vector>

#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

using namespace std;

void populateMatrix (int **matrix, int n, int edges) {
    while (edges > 0) {
        int i = rand() % n;
        int j = rand() % n;
        if (!matrix[i][j]) {
            matrix[i][j] = 1;
            --edges;
        }
    }
}

int main (int argc, char **argv) {

    srand (time(NULL));

    int n = 1000;
    int m = 1000;
    if (argc > 2) {
        n = atoi(argv[1]);
        m = atoi(argv[2]);
    }

    int **array = new int*[n]();
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

    populateMatrix(array, n, m);
    
    cout << n << " " << m << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j]) {
                cout << i << " " << j << endl;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        delete[] array[i];
    }
    delete[] array;

}
