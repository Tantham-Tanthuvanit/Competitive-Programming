#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix add(Matrix A, Matrix B) {
    int n = A.size();
    Matrix res(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = A[i][j] + B[i][j];
    return res;
}

Matrix sub(Matrix A, Matrix B) {
    int n = A.size();
    Matrix res(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = A[i][j] - B[i][j];
    return res;
}

Matrix strassen(Matrix A, Matrix B) {
    int n = A.size();

    // Base Case
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int k = n / 2;
    Matrix a(k, vector<int>(k)), b(k, vector<int>(k)), c(k, vector<int>(k)), d(k, vector<int>(k));
    Matrix e(k, vector<int>(k)), f(k, vector<int>(k)), g(k, vector<int>(k)), h(k, vector<int>(k));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a[i][j] = A[i][j];
            b[i][j] = A[i][j + k];
            c[i][j] = A[i + k][j];
            d[i][j] = A[i + k][j + k];

            e[i][j] = B[i][j];
            f[i][j] = B[i][j + k];
            g[i][j] = B[i + k][j];
            h[i][j] = B[i + k][j + k];
        }
    }

    Matrix p1 = strassen(a, sub(f, h));
    Matrix p2 = strassen(add(a, b), h);
    Matrix p3 = strassen(add(c, d), e);
    Matrix p4 = strassen(d, sub(g, e));
    Matrix p5 = strassen(add(a, d), add(e, h));
    Matrix p6 = strassen(sub(b, d), add(g, h));
    Matrix p7 = strassen(sub(a, c), add(e, f));

    // Calculate Result Quadrants
    Matrix c11 = add(sub(add(p5, p4), p2), p6);
    Matrix c12 = add(p1, p2);
    Matrix c21 = add(p3, p4);
    Matrix c22 = sub(sub(add(p1, p5), p3), p7);

    // Combine into final Matrix
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = c11[i][j];
            C[i][j + k] = c12[i][j];
            C[i + k][j] = c21[i][j];
            C[i + k][j + k] = c22[i][j];
        }
    }
    return C;
}

int main() {
    int n; cin >> n;
    Matrix a(n,vector<int>(n));
    Matrix b(n,vector<int>(n));

    // input mat 1
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            cin >> a[i][v];
        }
    }

    // input mat 2
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            cin >> b[i][v];
        }
    }

    Matrix res = strassen(a,b);

    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            cout << res[i][v] << ' ';
        }
        cout << endl;
    }

    return 0;
}