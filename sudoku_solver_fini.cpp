//                Source code   
//          "<<<<<SUDOKU SOLVER>>>>>"
#include <iostream>
#define N 9
using namespace std;

void print(int arr[9][9])
{
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
bool isSafe(int row,int col, int board[N][N],int val){
  for(int i=0;i<N;i++){

    //row check
    if(board[row][i]==val)
      return false;
  
     //col check
    if(board[i][col]==val)
    return false;

    //3*3 matrix check
    if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)
    return false;
  }
return true;
}

bool solve(int  board[N][N]){
  int n = 9;
  
  for(int row = 0; row < n; row++){
    for(int col = 0;col < n; col++){

      //cell empty
      if(board[row][col] == 0){
        for(int val = 1; val <= 9 ; val++){
          if(isSafe(row,col,board,val)){
            board[row][col] = val;
            //recurvise call
            bool solutionpossible = solve(board);
            if(solutionpossible)
              return true;
            else{
              //backtrack
              board[row][col] = 0;
            }
          }
        }
        return false;
      }
    }
  }
  return true;
}

int main()
{
    // 0 means unassigned cells
    int sudoku[N][N];
    cout<<"<_____PLEASE ENTER THE SUKODU_____>"<<endl;
    cout<<"( Enter 0 for unassigned cells  )"<<endl<<endl;
    for(int i=0 ;i<N;i++){
      for(int j=0;j<N;j++){
        cin>>sudoku[i][j];
      }
    }
  cout<<"_____________________________________"<<endl;
    if (solve(sudoku)){
    cout<<"<_____YOUR SOLVED SUKOKU_____>"<<endl<<endl;
        print(sudoku);
    }
    else
        cout << "no solution  exists " << endl;
  
    return 0;
}
