#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

// Function to compute minimum number of multiplications
int matrixChainMultiplication(vector<int>& d) {
    int n = d.size() - 1;  // Number of matrices (length of d - 1)
    
    // Create DP table: m[i][j] stores min multiplications to multiply Ai..Aj
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));

    // Cost of multiplying a single matrix is 0 (already initialized)
    
    // len = current chain length (from 2 to n)
    for (int len = 2; len <= n; len++) {
        // i = starting index of chain
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;  // j = ending index of chain
            m[i][j] = INT_MAX;    // Initialize with infinity
            
            // Try all possible split positions k between i and j
            for (int k = i; k <= j - 1; k++) {
                // Cost = cost of multiplying first part + cost of second part + cost of final multiplication
                int q = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
                
                // Update minimum cost if current split gives smaller cost
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    // Minimum cost to multiply entire chain A1..An is stored in m[1][n]
    return m[1][n];
}

int main() {
    // Example: matrices A1:10x30, A2:30x5, A3:5x60
    vector<int> dimensions = {10, 30, 5, 60};

    // Call function to compute minimum multiplications
    int minCost = matrixChainMultiplication(dimensions);

    // Print result
    cout << "Minimum number of multiplications: " << minCost << endl;

    return 0;
}
