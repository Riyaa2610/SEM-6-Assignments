#include<bits/stdc++.h>
using namespace std;

class NQueens{
private:
    int N;
    vector<int> queens;
    
    bool BoundingCondn(int row, int col)
    {
        for (int i = 0; i < row;i++)
        {
            if(queens[i] == col || abs(row-i) == abs(col-queens[i]))
            //ans(row-i) == abs(col-queens[i]) checks for diagonal
            return false;
        }
        return true;
    }

    bool SolveUtil(int row)
    {
        if(row == N)
        {
            return true;
        }

        for (int col = 0; col < N;col++)
        {
            if(BoundingCondn(row,col))
            {
                queens[row] = col;
                if(SolveUtil(row+1))
                {
                    return true;
                }
                queens[row] = -1;
            }
            cout << endl;
            Solution();
        }
        return false;
    }
public:
    NQueens(int n) : N(n)
    {
        queens.resize(N, -1);
    }

    void solve()
    {
        if(SolveUtil(0))
        {
            cout << "Solution found: " << endl;
            Solution();
        }
        else
        {
            cout << "No solution exists" << endl;
        }
    }

    void Solution()
    {
        for (int i = 0; i < N;i++)
        {
            for (int j = 0; j < N;j++)
            {
                if(queens[i]==j)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << ". ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the no. of queens: ";
    cin >> n;

    NQueens nQueens(n);
    nQueens.solve();

    return 0;
}