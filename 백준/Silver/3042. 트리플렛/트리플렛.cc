/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int n;
char grid[10001];

double cal(int a,int b){
    int ay = a/n;
    int ax = a%n;
    
    int by = b / n;
    int bx = b % n;

    double dy = ay - by;
    double dx = ax - bx;

    if (dx)
    {
        return dy / dx;
    }
    else
    {
        return 1;
    }
}

int main()
{
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>> grid[n*i+j];
        }
    }
    int answer=0;
    for(int i=0;i<n*n;i++){
        if(grid[i]=='.')
            continue;
        for(int j= i+1;j<n*n;j++){
            if(grid[j]=='.')
                continue;
            double g = cal(i,j);
            for(int k= j+1;k<n*n;k++){
                if(grid[k]=='.')
                    continue;
                else{
                    if(g==cal(i,k) && g == cal(j,k))
                        answer++;
                }
                
            }
        }
    }
    
    cout<<answer;
    return 0;
}