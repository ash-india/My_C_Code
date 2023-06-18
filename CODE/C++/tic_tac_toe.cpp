#include<iostream>
#include<cstdlib>  //for random numbers
#include<ctime>     //time(NULL) will be used as parameter in srand()

using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

char current_marker;
int current_player;

void drawBoard()
{
    cout<<endl;
    cout<<" "<<board[0][0]<<" | "<< board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"------------\n";
    cout<<" "<<board[1][0]<<" | "<< board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"------------\n";
    cout<<" "<<board[2][0]<<" | "<< board[2][1]<<" | "<<board[2][2]<<endl;
    cout<<endl;
}

bool placeMarker(int slot)
{
    int row,column;
    if(slot % 3 == 0)
    {
        row = (slot / 3) - 1;
        column = 2;
    }
    else
    {
        row = slot / 3;
        column = slot % 3 - 1;
    }

    if(board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column]=current_marker;
        return true;
    }
    return false;
}

int winner()
{
    for(int i = 0; i < 3; i++)
    {
        //rows
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;

        //columns
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
    }

    //diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;

    return 0;
}

void swap_player_and_marker()
{
    if(current_marker == 'X') current_marker = 'O';
    else current_marker = 'X';
    
    if(current_player == 1) current_player = 2;
    else current_player = 1;
}

void game()
{
    cout<<"Player one, choose your marker : ";
    char marker_pl;
    cin>>marker_pl;

    current_player = 1;
    current_marker = marker_pl;

    drawBoard();

    int player_won;

    for(int i = 0; i < 9; i++)
    {
        cout<<"It's player " << current_player <<"'s turn. Enter your slot : ";
        int slot;
        cin>>slot;
        if(slot<1 || slot>9)
        {
            cout << "OOPS! This slot is invalid. Try another slot!!\n";
            i--;
            continue;
        }
        if(!placeMarker(slot))
        {
            cout << "OOPS! This slot is already occupied. Try another slot!!\n";
            i--;
            continue;
        }

        drawBoard();

        player_won = winner();
        if(player_won == 1) { cout << "Hurrah! Player One Wins!!!"; break;}
        if(player_won == 2) { cout << "Hurrah! Player Two Wins!!!"; break;}

        swap_player_and_marker();
    }

    if(player_won == 0) cout << "Oh! It was a Tie game."; 
}

int main()
{
    cout<<endl;
    game();
}