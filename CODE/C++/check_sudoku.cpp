#include<iostream>
using namespace std;

bool fun()
{
    char board[9][9]={{'8','3','.','.','7','.','.','.','.'},
                      {'6','.','.','1','9','5','.','.','.'},
                      {'.','9','8','.','.','.','.','6','.'},
                      {'8','.','.','.','6','.','.','.','3'},
                      {'4','.','.','8','.','3','.','.','1'},
                      {'7','.','.','.','2','.','.','.','6'},
                      {'.','6','.','.','.','.','2','8','.'},
                      {'.','.','.','4','1','9','.','.','5'},
                      {'.','.','.','.','8','.','.','7','9'}};
        int row[10][10]={0};
        int col[10][10]={0};
        int diag[10][10]={0};
        int temprow,tempcol,i,j;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                temprow=board[i][j] - '0';
                tempcol=board[j][i] - '0';
                if(board[i][j]!='.')
                    row[i+1][temprow]++;
                if(board[j][i]!='.')
                    col[i+1][tempcol]++;
            }
        }
        int r=3,c=3;
        i=0;
        j=0;
        for(int x=0;x<9;x++)
        {
            for(i=r-3;i<r;i++)
            {
                for(j=c-3;j<c;j++)
                {
                    int temp=board[i][j]-'0';
                    if(board[i][j]!='.')
                        diag[x+1][temp]++;
                }
            }
            c=(c+3);
            if(c==12)
            {
                c=3;
                r=r+3;
            }
        }
        for(i=1;i<10;i++)
        {
            for(j=1;j<10;j++)
            {
                if(row[i][j]>1 || col[i][j]>1 || diag[i][j]>1)
                    return false;
            }
        }
        return true;
}

int main(){
    cout<<fun();
}