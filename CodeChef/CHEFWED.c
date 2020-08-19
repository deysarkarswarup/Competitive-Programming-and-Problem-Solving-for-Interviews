// Chef and Wedding Arrangements Problem Code: CHEFWED
There are N guests (numbered 1 through N) coming to Chef's wedding. Each guest is part of a family; for each valid i, the i-th guest is part of family Fi. You need to help Chef find an optimal seating arrangement.

// Chef may buy a number of tables, which are large enough for any number of guests, but the people sitting at each table must have consecutive numbers ― for any two guests i and j (i<j) sitting at the same table, guests i+1,i+2,…,j−1 must also sit at that table. Chef would have liked to seat all guests at a single table; however, he noticed that two guests i and j are likely to get into an argument if Fi=Fj and they are sitting at the same table.

// Each table costs K rupees. Chef defines the inefficiency of a seating arrangement as the total cost of tables plus the number of guests who are likely to get into an argument with another guest. Tell Chef the minimum possible inefficiency which he can achieve.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains two space-separated integers N and K.
// The second line contains N space-separated integers F1,F2,…,FN.
// Output
// For each test case, print a single line containing one integer ― the smallest possible inefficiency.

// Constraints
// 1≤T≤100
// 1≤N≤1,000
// 1≤K≤1,000
// 1≤Fi≤100 for each valid i
// The sum of N across test cases is ≤5,000
// Subtasks
// Subtask #1 (20 points): K=1
// Subtask #2 (80 points): original constraints
// Example Input
// 3
// 5 1
// 5 1 3 3 3
// 5 14
// 1 4 2 4 4
// 5 2
// 3 5 4 5 1
// Example Output
// 3
// 17
// 4
// Explanation
// Example case 1: The optimal solution is to use three tables with groups of guests [1,2,3], [4] and [5]. None of the tables have any guests that are likely to get into an argument, so the inefficiency is 3⋅K=3.

// Example case 2: The optimal solution is to seat all guests at one table. Then, guests 2, 4 and 5 are likely to get into an argument with each other, so the inefficiency is K+3=17.


//Solution
  #include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>> n>>k;
        int arr[n+1];
        map<int, int>mp;
        int res =0, vc =0, t=1;
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout << arr[i];
        // }
        int column[n+1][n+1] = {0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                column[i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            mp.clear();
            for(int j=i; j<n; j++)
            {
                column[i][j] = (j==0)?0:column[i][j-1];
                if(mp.count(arr[j]))
                {
                    if(mp[arr[j]]==1)
                    {
                        column[i][j]++;
                    }
                    column[i][j]++;
                }
                mp[arr[j]]++;
            }
        }
        res = 10000;
        int flag =100;
        int newarr[101][1001] = {0};
        for(int i=0;i<=flag;i++)
        {
            for(int j=0;j<=flag;j++)
            {
                newarr[i][j]=0;
            }
        }
        for(int i=0;i<n+1;i++)
        {
            newarr[1][i] = column[0][i-1];
        }
        for(int i=2;i<=flag;i++)
        {
            newarr[i][1]=0;
        }
        for(int i=2; i<=flag;i++)
        {
            for(int j=2;j<=n;j++)
            {
                int best = 10000;
                for(int p=1; p<j;p++)
                {
                    best = min(best,newarr[i-1][p]+column[p][j-1]);
                    //cout<<best
                }
                //cout<<best
                newarr[i][j]=best;
            }
        }
        for(flag=1;flag<=100;flag++)
        {
            res = min(flag*k+newarr[flag][n],res);
            //cout<<res
        }
        cout<< res << endl;
    }

    return 0;
}

