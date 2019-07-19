#include <stdio.h> 
  
int a[100][100];  
void spiralPrint(int m, int n, int a[100][100]) 
{ 
    int i, k = 0, l = 0; 
  
    while (k < m && l < n) { 
        for (i = l; i < n; ++i) { 
            printf("%d ", a[k][i]); 
        } 
        k++; 
  
        for (i = k; i < m; ++i) { 
            printf("%d ", a[i][n - 1]); 
        } 
        n--; 
  
        if (k < m) { 
            for (i = n - 1; i >= l; --i) { 
                printf("%d ", a[m - 1][i]); 
            } 
            m--; 
        } 
        if (l < n) { 
            for (i = m - 1; i >= k; --i) { 
                printf("%d ", a[i][l]); 
            } 
            l++; 
        } 
    } 
} 

int main() 
{ 
    int m, n, i, j;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%d",&a[i][j]);
      }
    }
    spiralPrint(n,m,a); 
    return 0; 
} 