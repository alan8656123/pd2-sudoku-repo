#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
class Sudoku{
public:
	Sudoku();
	Sudoku(const int init_map[]);
/*2-1*/	void readIn();
	void printOut(bool isAns);
/*2-2*/	void solve();
	static const int sudokuSize=81;
/*3-1*/	void changeNum(int a,int b);
	void changeRow(int a,int b);	
	void changeCol(int a,int b);
	void rotate(int n);
	void flip(int n);
	void change();
/*3-2*/	void transform();
/*1*/	void giveQuestion();
	int sol_num;	
	int solve_one(int a);	    //find one solve if solvable
private:	
	int map[sudokuSize];	
	int sol[sudokuSize],sol_0[81],ans[81];//find 0,solve
	bool checkUnity(int arr[]); //used in solveable();
	void find0();               //used in solve,to find 0(blanks)
	bool solveable();	    //used in solve_one,to check if sudoku can solve
	bool check(int n);      //used in solve_one,to check if sudoku can solve	
};
