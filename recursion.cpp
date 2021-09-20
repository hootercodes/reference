#include <stdio.h>

int findMultiple(int A[], int n)

{

if(n==0)

return 0;

if (A[n] % 3 == 0)

return (findMultiple(A, n-1))+1;

else

return(findMultiple(A,n-1));

}

int main()

{

int i;

int n;

scanf("%d", &n);

int A[n];

for (i = 0; i < n; i++)

{

scanf("%d", &A[i]);

}

printf("%d", findMultiple(A, n));

return 0;

}
