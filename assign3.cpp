#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int row, int col,vector<vector<int>>&board,int N)
{
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
            return false;
    }
    int i = row - 1;
    int j = col - 1;

    while(i >= 0 && j >= 0)
    {
        if(board[i][j] == 1)
            return false;

        i--;
        j--;
    }
    i = row - 1;
    j = col + 1;
    while(i >= 0 && j < N)
    {
        if(board[i][j] == 1)
            return false;

        i--;
        j++;
    }
    return true;
}
bool solve(int row,vector<vector<int>>&board,int N)
{
    if(row == N)
        return true;

    for(int col = 0; col < N; col++)
    {
        if(isSafe(row, col,board,N))
        {
            board[row][col] = 1;
            if(solve(row + 1,board,N))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}
void display(vector<vector<int>>&board,int N)
{
    cout << "\nN-Queens Solution:\n";
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[i][j] == 1)
                cout << " Q ";
            else
                cout << " . ";
        }
        cout << endl;
    }
}
int main()
{
    int N;
    cout << "Enter value of N: ";
    cin >> N;
    vector<vector<int>>board(N,vector<int>(N,0));
    if(N == 2 || N == 3)
    {
        cout << "No solution exists!\n";
        return 0;
    }
    if(solve(0,board,N))
        display(board,N);
    else
        cout << "No solution exists!\n";
    return 0;
}
