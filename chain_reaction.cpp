#include <bits/stdc++.h>
using namespace std;
#define input 5
#define a 9 
#define b 6
//#define a^^b  a ? !b : b
static int board[a][b]={0};
int mv = 0;
bool finished=false;

bool valid_input( int i, int j)
{
    if(i>=0&&i<a&&j>=0&&j<b)
        return  true;
    return false;
}

bool check_red()
{
    int sum = 0;
    for (auto &i : board) {
        for (int j : i)
        {
           if( j >= 0)
               sum+=j;
        }
    }
    if(sum>0)
        return true;
    return false;
}
bool check_green()
{
    int sum = 0;
    for (auto &i : board) {
        for (int j : i)
        {
            if( j <= 0)
                sum+=j;
        }
    }
    if(sum<0)
        return true;
    return false;
}

int limit (int i, int j)
{
    if( i == 0 || i == a-1)
    {
        if(j == 0 || j == b-1)
            return 2;
        else
            return 3;
    } else
    {
        if(j == 0 || j == b-1)
            return 3;
        else
            return 4;
    }
}
void printArr()
{
    for (auto &i : board) {
        for (int j : i)
        {
            printf("%d  ", j);
        }
        printf("\n");
    }
    printf("%d\n",mv);
}

int  update_board(int i, int j, bool chance)
{
    int l = limit(i,j);

        if (chance)
           {   
            if(board[i][j]>0)
               board[i][j] = -board[i][j];
                 board[i][j] -= 1;
                if (abs(board[i][j]) == l)
                {
                    board[i][j] = 0;
                    if (l == 2) {
                       
                         return  update_board(min(i + 1, a - 2), j, chance) + update_board(i, min(j + 1, b - 2), chance);

                    } else if (l == 3)
                    {
                        if (i == 0 || i == a-1)
                        {
                           return update_board(i,j+1,chance)+update_board(i,j-1,chance)+update_board(min(i+1,a-2),j,chance);
                        
                        } else
                        {
                             return  update_board(i+1,j,chance)+update_board(i-1,j,chance)+update_board(i,min(j+1,b-2),chance);;
                        }

                    } else if (l == 4)
                    {
                        // printf("REACHED!!!!");
                      return update_board(i+1, j, chance)+update_board(i-1, j, chance)+update_board(i, j+1, chance)+update_board(i, j-1, chance);
            
                    }
                }
        }
        else
        {
                board[i][j] = abs(board[i][j]);
                board[i][j] += 1;
                if (abs(board[i][j]) == l)
                {
                    board[i][j] = 0;
                    if (l == 2) {
                       return update_board(min(i + 1, a - 2), j, chance)+update_board(i, min(j + 1, b - 2), chance);
                        
                    } else if (l == 3)
                    {
                        if (i == 0 || i == a-1)
                        {
                            return update_board(i,j+1,chance)+update_board(i,j-1,chance)+update_board(min(i+1,a-2),j,chance);
                            
                        } else
                        {
                            return update_board(i+1,j,chance)+update_board(i-1,j,chance)+update_board(i,min(j+1,b-2),chance);
                        }

                    } else if (l == 4)
                    {
                        // printf("REACHED!!!!");
                       return update_board(i+1, j, chance)+update_board(i-1, j, chance)+update_board(i, j+1, chance)+update_board(i, j-1, chance);
                        
                    }
                }

        }
         bool x = check_green()^check_red();
         if(x&&mv>=2)
        return 0;
    
        return 0;
}

void move(int i, int j)
{   
    //int i,j;
    bool  chance= (mv%2);
   // cin>>i>>j;
    if(valid_input(i,j))
    {
        if(chance)
        {
            if(board[i][j]<=0)
            {
                    update_board(i,j,chance);
            } else
            {
                printf("ILLEGAL_MOVE\n");
              //  move();
                return;
            }
           // count_red++;
        } else
            {
                if(board[i][j]>=0)
                {
                    update_board(i,j,chance);

                } else
                    {
                        printf("ILLEGAL_MOVE\n");
                      return;///  move();
                    }
             //  count_green++;
        }
        mv++;
        printArr();
        printf("%d\n",chance);

    }
    else
        printf("ILLEGAL_MOVE\n");
        
       // move();
           
    return;
}

int main()
{
    printArr();

    while(true)
 {   
   bool x = check_red()^check_green();  
   if(x&&(mv>=2))
  { 
    printf("EXIT_SUCCESS\n");
    break;
  } 
    int i,j;
    cin>>i;
    if(i == -1)
        break;
    else
        cin>>j;
     move(i,j);
 }
     
//    int x=1,y=5;
// printf("%d\n",limit(2,3));
    return 0;
}