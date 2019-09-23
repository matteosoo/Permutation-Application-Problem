/* 107591501_hw1.cpp */
#include<stdio.h>
#include <iostream>
using namespace std;

int factorial(int n)
{
    if(n == 0)
        return 1;
    else
    {
        int s = 1;
        for (int i = 1; i <= n; i++)
            s = s*i;
        return s;
    }
}

int s; // s種元素
int sum; // 組合數
int a[50];
int iarr[300][5];
int maxE = 0;
int result[10];

void combination(int n,int k,int m) 
{
	int i;
	if (n<k) return ;

	if (k==0) 
    {
        int summax = 0;
        for (int j=0; j<s; j++)
        {
            int max = 0;
            for (i=0; i<m; i++) 
            {
                if (max < iarr[a[i]-1][j])
                    max = iarr[a[i]-1][j];
            }
            summax = summax + max;
            // printf("%d", summax);
        }
        if (maxE < summax)
            maxE = summax;
	} 
    else 
    {
		//選n
		a[m] = n;
		combination(n-1, k-1, m+1);
		//不選n
		combination(n-1, k, m);
	}
}

int main()
{
    cout << "Input" << "\n";
    int t;
    cin >> t;

    int tt = t;
    while(t>0)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        cin >> s;

        if (n == k)
            sum = 1;
        else
        {
            int a = factorial(n);
            int b = factorial(k);
            int c = factorial(n - k);
            sum = a / (b*c);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < s; j++)
                cin >> iarr[i][j];
        }

        combination(n, k, 0);

        // printf("%d", maxE);
        result[t-1] = maxE;
        t = t-1;
    }
    printf("Output\n");
    for (int i=tt; i>0; i--)
    {
        cout << result[i-1];
        printf("\n");
    }
    return 0;
}