#include"Sudoku.h"
using namespace std;

Sudoku::Sudoku(){
	for(int i=0;i<sudokuSize;++i)
	map[i]=0;

}
Sudoku::Sudoku(const int init_map[]){
	for(int i=0;i<sudokuSize;++i)
	map[i]=init_map[i];
}

bool Sudoku::checkUnity(int *arr){
	int arr_unity[9]={0};
unsigned int i;
	for(i=0; i<9; ++i)
		if(arr[i]>0){
			if(++arr_unity[arr[i]-1]>1)return false;
	}
	return true;
}
void Sudoku::find0(){
	sol_num=0;
	for(int i=0;i<sudokuSize;++i)sol[i]=0;
	for(int i=0;i<sudokuSize;++i)
		if(map[i]==0){
		sol_0[sol_num]=i;
		++sol_num;
		}
}
int Sudoku::solve_one(int a){
	if(solveable()==false)return 0;
	int i=a-1;
	while(i<sol_num-1&&i>=-1){
			++i;
			++sol[sol_0[i]];
			if(sol[sol_0[i]]>=10){sol[sol_0[i]]=0;map[sol_0[i]]=0;i=i-2;continue;}
			map[sol_0[i]]=sol[sol_0[i]];
			if(check(sol_0[i])==false)--i;
	}
	if(i<0)return 0;
	else return 1;
}
void Sudoku::readIn(){
	int sudoku_in[sudokuSize];
        for(int i=0;i<sudokuSize;++i)
                {scanf("%d",&sudoku_in[i]);
		map[i]= sudoku_in[i];}
}
void Sudoku::printOut(bool isAns){
if(!isAns)
	for(int i=0;i<sudokuSize;++i){	
			if(i%9==0&&i!=0)printf("\n");
			printf("%d ",map[i]);
		}
else 	
	for(int i=0;i<sudokuSize;++i){	
			if(i%9==0&&i!=0)printf("\n");
			printf("%d ",ans[i]);
		}
}
bool Sudoku:: check(int n){
int check_arr[9],c=n%9,r=n/9;
unsigned int i,j;
	 		for(j=0; j<9; ++j)
			check_arr[j] = map[r*9+j];
		    if(checkUnity(check_arr) == false)return false;
						
	 		for(j=0; j<9; ++j)
			check_arr[j] = map[c+j*9];
			if(checkUnity(check_arr) == false)return false;
		
			for(i=0; i<3; ++i)
				for(j=0; j<3; ++j)
					check_arr[j+(i*3)] = map[(c/3)*3+(r/3)*27+j+i*9];
			if(checkUnity(check_arr) == false)return false;
 	return true;
}
bool Sudoku::solveable(){
	int check_arr[9];
	int location;
	for(int i=0; i<81; i+=9){
 		for(int j=0; j<9; ++j)
			check_arr[j] = map[i+j];
		if(checkUnity(check_arr)== false)return false;
	}

	for(int i=0; i<9; ++i){
		for(int j=0; j<9; ++j)
			check_arr[j] = map[i+9*j];
		if(checkUnity(check_arr) == false)
		return false;
	}
	for(int i=0; i<9; ++i){
		for(int j=0; j<9; ++j){
			location = 27*(i/3) + 3*(i%3)+9*(j/3) + (j%3);
			check_arr[j] = map[location];
		}
		if(checkUnity(check_arr) == false)
		return false;
	 }
 	return true;
}
void Sudoku::solve(){
	find0();
    	if(solve_one(0)==1||(solveable()&&sol_num==0)){
			for(int i=0;i<sudokuSize;i++){
				ans[i]=map[i];
			}
			if(solve_one(sol_num-1)==1)printf("2\n");
			else {printf("1\n");
			printOut(true);		
		 }
	}
	else printf("0\n");
}
void Sudoku::changeNum(int a,int b){
if(a<=9&&a>=1&&b<=9&&b>=1)
        for(int i=0;i<Sudoku::sudokuSize;i++)
                {if(map[i]==a){map[i]=b;continue;}
                if(map[i]==b)map[i]=a;}
}
void Sudoku::changeRow(int a,int b){
	int temp;
if(a<=2&&a>=0&&b<=2&&b>=0)
        for(int i=0;i<Sudoku::sudokuSize/3;i++)
                {temp=map[i+a*27];
		map[i+a*27]=map[i+b*27];
		map[i+b*27]=temp;}
}
void Sudoku::changeCol(int a,int b){
        int temp;
if(a<=2&&a>=0&&b<=2&&b>=0)
        for(int i=0;i<3;i++)
		for(int j=0;j<9;j++){
		temp=map[i+j*9+a*3];
                map[i+j*9+a*3]=map[i+j*9+b*3];
                map[i+j*9+b*3]=temp;
		}
}

void Sudoku::rotate(int n){
	int temp;
	int ss[Sudoku::sudokuSize];
if(n<=100&n>0){
	for(int x=0;x<n;x++)
		{for(int i=0;i<9;++i)
	                for(int j=0;j<9;++j){
			ss[i+j*9]=map[j+(8-i)*9];
			}	
        for(int i=0;i<9;++i)
		for(int j=0;j<9;++j)
			map[i+j*9]=ss[i+j*9];
		}
	}
}
void Sudoku::flip(int n){
	int ss[sudokuSize];
	if(n==1)                
		for(int i=0;i<9;++i)
                        for(int j=0;j<9;++j){
			ss[i+j*9]=map[8-i+j*9];
			}
	else if(n==0)
                for(int i=0;i<9;++i)
                        for(int j=0;j<9;++j)
                        ss[i+j*9]=map[i+(8-j)*9];
                        

                for(int i=0;i<9;++i)
                        for(int j=0;j<9;++j)
				map[i+j*9]=ss[i+j*9];

}
void Sudoku::change(){
srand(time(NULL));
changeNum(rand()%9+1,rand()%9+1);
changeRow(rand()%3,rand()%3);	
changeCol(rand()%3,rand()%3);
rotate(rand()%101);
flip(rand()%2);
}
void Sudoku::transform(){
change();
printOut(false);
}
void Sudoku::giveQuestion(){
srand(time(NULL));
int ques[sudokuSize]=
{
8,4,3,5,6,7,2,9,1, 
5,6,7,1,9,2,4,8,3,
2,9,1,4,8,3,7,6,5,
1,3,2,9,7,8,6,5,4,
9,7,6,3,4,5,8,1,2,
4,5,8,6,2,1,3,7,9,
7,8,5,2,3,9,1,4,6,
3,1,4,7,5,6,9,2,8, 
6,2,9,8,1,4,5,3,7};
for(int i=0;i<70;++i){
	ques[rand()%81]=0;
	}
for(int i=0;i<sudokuSize;++i)
	map[i]=ques[i];
change();
printOut(false);
}

