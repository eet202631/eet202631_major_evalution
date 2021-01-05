#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

char SUDOKU[9][9];

int isSudoku(char SUDOKU[9][9],int row,int column)
{
	
	int A=0;
	char VALUE;
	if(SUDOKU[row][column] == '_')
	{
		cout << "\nEnter the Number You Want to Fill: ";
    		cin >> VALUE; 
		for(int x=0; x<9; x++)
		{
			if(SUDOKU[row][x] == '_'){
				continue;
			}
			else if(SUDOKU[row][x] == VALUE){
				cout << "\nError!!! Not a valid number!\n";
				A++;
				return 1;
			}
		}
		
		if(A == 0){
			cout<<"\nyou enterd right number \n";
		}
	}
	else
	{
		cout << "\nSelected Box is Not Empty!\n\n";
		return 1;
	}

return 0;
}

int main()
{
    
    ifstream in;
    in.open("test.txt");
    if(!in)
    {
        cout<<"File not FOUND";
        exit(0);
    }
    int rw,col;
    in>>rw;
    in>>col;
    for(int x=0;x<rw;x++)
    {
        for(int y=0;y<col;y++)
        {
            in>>SUDOKU[x][y];
        }
    }
    cout<<"MAZE"<<endl;
    for(int x=0;x<rw;x++)
    {
        for(int y=0;y<col;y++)
        {
                cout<<SUDOKU[x][y]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    int row, column;
    cout << "\nSelect The Empty Box row, column: " ;
    cin >> row;
    cin >> column;
    
    while(isSudoku(SUDOKU,row,column) == 1){
	    cout << "\nAgain Select The Empty Box row, column: " ;
	    cin >> row;
	    cin >> column;
    }

}
