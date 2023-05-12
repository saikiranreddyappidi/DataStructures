#include <stdio.h>
#include <limits.h>

#define MAX_N 100
#define MAX_L 1000

int C[MAX_N+1][MAX_L+1];
int cuts[MAX_N+1];


int solve(int n, int L) {
    int i, j, k, cost;

    for (i = 1; i <= n; i++) {
        cuts[i] = 0; /* initialize cuts array */
        C[i][0] = 0; /* base case */
    }
    for (j = 1; j <= L; j++) {
        C[1][j] = j; /* base case */
    }
    for (i = 2; i <= n; i++) {
        for (j = 1; j <= L; j++) {
            C[i][j] = INT_MAX;
            for (k = 1; k <= j; k++) {
                cost = k + C[i-1][j-k];
                if (cost < C[i][j]) {
                    C[i][j] = cost;
                    cuts[i] = k; /* update cuts array */
                }
            }
        }
    }
    return C[n][L];
}

void print_cuts(int n, int L, int *pieces) {
    int i, cut, remaining;

    printf("To cut a rod of length %d into %d pieces of lengths: ", L, n);
    for (i = 0; i < n; i++) {
        printf("%d ", pieces[i]);
    }
    printf("\n");

    printf("Make the following cuts to achieve the minimum cost of %d:\n", C[n][L]);
    for (i = n; i >= 1; i--) {
        cut = cuts[i];
        remaining = L - cut;
        printf("Cut %d: Length = %d, Cost = %d\n", n-i+1, cut, cut + C[i-1][remaining]);
        L = remaining; /* update remaining length */
    }
}

int main() {
    int n, L, i;
    int pieces[MAX_N];
    printf("Enter the length of the rod: ");
    scanf("%d", &L);

    printf("Enter the number of pieces: ");
    scanf("%d", &n);

    printf("Enter the lengths of the pieces:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pieces[i]);
    }

    int cost = solve(n, L),max=0;
    for(i=0;i<n;i++){
        if(pieces[i]>max){
            max=pieces[i];
        }
    }
    printf("\nMinimum cost: %d\n", cost-max);
    print_cuts(n, L, pieces);

    return 0;
}
