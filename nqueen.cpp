//Implement a solution for a Constraint Satisfaction Problem using Branch and Bound and
// Backtracking for n-queens problem or a graph coloring problem.
#include<iostream>
#include<cstdlib>
using namespace std;

int count = 0;
int x[20];

bool place(int r, int c);
void NQueen(int r, int n);
void print(int n);

bool place(int r, int c) {
    for (int j = 1; j <= r - 1; j++) {
        if (x[j] == c || abs(x[j] - c) == abs(j - r)) {
            return false;
        }
    }
    return true;
}

void print(int n) {
    cout << "\nSolution " << ++count << "\n\n";
    for (int i = 1; i <= n; i++) {
        cout << "\t" << i;
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << i;
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                cout << "\tQ";
            else
                cout << "\t-";
        }
        cout << endl;
    }
}

void NQueen(int r, int n) {
    for (int c = 1; c <= n; c++) {
        if (place(r, c)) {
            x[r] = c;
            if (r == n) {
                print(n);
            } else {
                NQueen(r + 1, n);
            }
        }
    }
}

int main() {
    int n;
    cout << " -------- N-Queen Problem --------\n";
    cout << "Enter number of queens: ";
    cin >> n;
    NQueen(1, n);
    return 0;
}
/*Output:
 -------- N-Queen Problem --------
Enter number of queens: 4

Solution 1

        1       2       3       4
1       -       Q       -       -
2       -       -       -       Q
3       Q       -       -       -
4       -       -       Q       -

Solution 2	

        1       2       3       4
1       -       -       Q       -
2       Q       -       -       -
3       -       -       -       Q
4       -       Q       -       -

-------------------------------- */
