#include<bits/stdc++.h>
using namespace std;

class Helper {
public:
    Helper() {}

    void run() {
        char s[100010];
        gets(s);
        int n = strlen(s);
        int res = 0;

        int C[300] = {0};
        for(int i=0;i<n;++i) C[s[i]]++;

        int a[300][300] = {0};
        for(int i=0,j=n-1;i<j;++i,--j) a[s[i]][s[j]] = a[s[j]][s[i]] = 1;

        bool vs[300] = {false};
        for(int i=0;i<300;++i) {
            if(!vs[i]) {
                int total = 0;
                int cmax = 0;
                dfs(i, C, a, vs, total, cmax);
                res += total - cmax;
            }
        }

        printf("%d\n", res);
    }

private:
    void dfs(int i, int C[], int a[][300], bool vs[], int& total, int& cmax) {
        vs[i] = true;
        total += C[i];
        cmax = max(cmax, C[i]);
        for(int j=0;j<300;++j) {
            if(!vs[j] && a[i][j]) {
                dfs(j, C, a, vs, total, cmax);
            }
        }
    }
};

int main() {
    Helper helper;
    helper.run();
    return 0;
}
