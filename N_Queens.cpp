
// N Queen Problem using backtracking */

#include<bits/stdc++.h>
using namespace std;

#define MAX 64

class NQueen {

	public:

		int N, counter, counter2; // dimension of the chessboard
		int board[MAX][MAX]; // chess board
		int solution_matrix[8];
		int ld[MAX] = { 0 };	// Left Diagonal
		int rd[MAX] = { 0 }; // Right Diagonal
		int cl[MAX] = { 0 }; // Check rows for each column

		void printSolution() {
			int k=0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cout<<" "<< board[i][j]<<" ";
					if (board[j][i] == 1) {
						solution_matrix[k] = j+1;
						//cout<<"  "<<solution_matrix[k];
						k++;
					}
				}
				cout<<endl;
			}
			cout<<"\n  Columns-wise Positions of Queens in chessboard ----> [  ";
			for (int i=0; i<k; i++) {
				cout<<solution_matrix[i]<<"  ";
			}
			cout<<"]"<<endl;
		}


		// A recursive backtracking function to solve N Queen problem
		bool solveNQUtil(int col) {
			// If all queens are placed correctly then return true
			if (col >= N) {
				cout<<"\nSolution : "<<counter2++<<" ---------> \n\n";
				printSolution();
				counter = 1;
				//return true;
			}
			// Consider this column and try placing the queen in all rows one by one
			for (int i = 0; i < N; i++) {
				// check the left and right diagonals
				if ((ld[i - col + N - 1] != 1 && rd[i + col] != 1) && cl[i] != 1) {
					// Place this queen on board[i][col]
					board[i][col] = 1;
					ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;
					// place rest of the queens
					if (solveNQUtil(col + 1))
						return true;
					// Remove queen from the board if it is wrongly placed
					board[i][col] = 0; // backtracking
					ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
				}
			}

			/* If the queen cannot be placed in any row in
				this column col then return false */
			return false;
		}

		bool solveNQueens() {

			counter = 1;
			counter2 = 1;
			cout<<"\n\nInitial Chessboard ---------> \n\n";
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					board[i][j] = 0;
					cout<<"  "<<board[i][j];
				}
				cout<<endl;
			}
			cout<<"\n\nThe solution to the "<<N<<"-Queens problem --------> \n\n";
			if (solveNQUtil(0) == false) {
				if (counter2==1) {
					cout<<"\n\nSolution does not exist for given chess board\n\n";
					return false;
				}
			}

			//printSolution();
			/*there may be more than one solutions,
				this function prints one of the feasible solutions.*/
			return true;
		}

};


int main()
{
	char x;
	NQueen NQ1;
	cout<<"\nEnter the dimensions of  the chessboard ----------> ";
	cin>>NQ1.N>>x>>NQ1.N;
	NQ1.solveNQueens();
	return 0;
}

