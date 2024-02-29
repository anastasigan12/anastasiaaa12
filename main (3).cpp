#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    // Checking the correctness of the entered dimensions
    if (m <= 0 || n <= 0 || n % 2 != 0) {
        cerr << "Error: Invalid input for dimensions." << endl;
        return 1;
    }

    vector<vector<int>> matrix(m, vector<int>(n));

    // Reading matrix elements
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int last_even_row = 0; // Change to save the number of the remaining row with the same numbers

    // Search for the number of the remaining row with the guys' numbers
    for (int i = 0; i < m; i++) {
        bool is_even_row = true; // Ensign, which means, and to place a row of just a few numbers
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] % 2 == 1) { // If the wrong number is found, then the row does not fit
                is_even_row = false;
                break;
            }
        }
        if (is_even_row) { // If the row contains only a few numbers, it is updated last_even_row
            last_even_row = i + 1;
        }
    }

    // Shown the numbers of the remaining row with the same numbers
    cout << "The index of the last row with all even elements: " << last_even_row << endl;

    // Reverse the left and right halves of the matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = temp;
        }
    }

    // Display of the matrix after the exchange of the left and right halves
    cout << "Matrix after swapping left and right halves:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}