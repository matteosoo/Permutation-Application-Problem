# Permutation-ApplicationProblem

## Catalog
> [TOC]

## Flowchart (or pseudo code)

0. global parameters:
```cpp=
int s; // s種元素
int sum; // 組合數
int a[50]; 
int iarr[1000000][5]; // 存放各物件之各元素的2維陣列
int maxE = 0; // 各行總能量
int result[10]; // 存放各行能量array
```

1. 主程式main (有稍微簡化I/O的程式碼)
```cpp=
int main()
{
    // 輸入test case數 （t）
    int t;
    // 作為最後result輸出loop長度
    int tt=t;
    
    // 進行t次 loop計算
    while(t>0)
    {
        // 輸入n, k, s
        int n, k s;
        
        // s為2時獨立計算
        if (s == 2)
        {
            // 輸入個別元素能量至iarr二維陣列
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < s; j++)
                    cin >> iarr[i][j];
            }
            
            // 獨立取行之最大值(max1、max2)作為融合元素最大能量
            int max1 = 0;
            int max2 = 0;
            for (int i = 0; i < n; i++)
            {
                if (max1 < iarr[i][0])
                    max1 = iarr[i][0];
                if (max2 < iarr[i][1])
                    max2 = iarr[i][1];
            }
            
            // 加總各行能量並存入result array中
            maxE = max1 + max2;
            result[t-1] = maxE;
            t = t-1;
        }
        // s不為2時
        else
        {
            // sum為計算n取k之組合數
            if (n == k)
                sum = 1;
            else
            {
                int a = factorial(n);
                int b = factorial(k);
                int c = factorial(n - k);
                sum = a / (b*c);
            }
            
            // 輸入個別元素能量至iarr二維陣列
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < s; j++)
                    cin >> iarr[i][j];
            }
            
            // 分別計算組合數下的各元素總和，並加總各行能量
            combination(n, k, 0);

            // 將總能量存入result array中
            result[t-1] = maxE;
            t = t-1;
        }
    }
    // 將result結果輸出
    for (int i=tt; i>0; i--)
    {
        cout << result[i-1];
        printf("\n");
    }
    return 0;
}
```
2. factorial (main的48行-50行)
```
C(n,m)=n!/[m!*(n-m!)]
```
為了避免在2 ≤ 𝐾 ≤ 𝑁 ≤10000 計算量大增，在此將元素種數𝑆=2時獨立運算，也就是𝑆=2 時，尋找最大值能以 O(n) 找到元素最大值。
```cpp=
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
```
3. combination （main的62行）

組合類型則是輸入，以n取k下，m為index起始開始。
以recursive進行每次迭代，將選定的n存入暫存空間a[] array直到k=0時，才進行取最大值加總。
```cpp=
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
```

## Analysis of time complexity
𝑆=2 時，combination的時間複雜度在為 O(n)。

𝑆!=2時，combinationT(n,k) = T(n-1,k) + T(n-1,k-1) + O(1)， 時間複雜度為O(2^n)。