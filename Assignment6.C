// C++ script to solve the assignment 6
#include"MainLibrary.h"
using namespace std;

const int npts=9;
void Laplace_Solver(double** pot, int npts_, int iter);
void PrintGrid(double** pot, int npts, string fname);

void Question1();
void Question2();
void Question3();
void Question3b();

int main()
{
  Question1();
  Question2();
  Question3();
  Question3b();
  return 0;
}

void Laplace_Solver(double** pot, int npts_, int iter)
{
  for(int n=0;n<iter;n++){
    for(int i=1;i<npts_;i++){
      for(int j=1;j<npts_;j++){
	pot[i][j]=(
		   pot[i-1][j]+
		   pot[i+1][j]+
		   pot[i][j-1]+
		   pot[i][j+1])/4;
      }
    }
  }
}

void PrintGrid(double** pot, int npts,string fname)
{
  FILE* pfile;
  pfile = fopen(fname.c_str(),"w");
  for(int i=0;i<npts+1;i++){
    for(int j=0;j<npts+1;j++){
      // printf("%.4f\t",pot[i][j]);
      fprintf(pfile,"%.4f\t",pot[i][j]);
    }
    fprintf(pfile,"\n");
    // cout<<endl;
  }
  fclose(pfile);
}

void Question1()
{
  double** potential = new double*[npts+2];
  for(int i=0;i<npts+2;i++)
    potential[i] = new double[npts+2];

  for(int i=0;i<npts+1;i++){
    for(int j=0;j<npts+1;j++){
      potential[i][j]=0.0;
    }
  }
  for(int i=0;i<npts+1;i++){
    potential[i][0] = 10.0;
    potential[i][npts] = 10.0;
    potential[0][i] = 10.0;
    potential[npts][i] = 10.0;
  }

  Laplace_Solver(&potential[0],npts,1000);
  PrintGrid(potential,npts,"TXT_OUT/A6Q1.txt");
}

void Question2()
{
  double** potential = new double*[npts+2];
  for(int i=0;i<npts+2;i++)
    potential[i] = new double[npts+2];

  for(int i=0;i<npts+1;i++){
    for(int j=0;j<npts+1;j++){
      potential[i][j]=0.0;
    }
  }
  for(int i=0;i<npts+1;i++){
    potential[i][0] = 10.0;
    potential[i][npts] = 10.0;
    potential[0][i] = 10.0;
    potential[npts][i] = 10.0;
  }
  potential[6][6] = 4.0;
  
  Laplace_Solver(&potential[0],npts,1000);
  PrintGrid(potential,npts,"TXT_OUT/A6Q2.txt");
}

void Question3()
{
  double** potential = new double*[npts+2];
  for(int i=0;i<npts+2;i++)
    potential[i] = new double[npts+2];
  
  for(int i=0;i<npts+1;i++){
    for(int j=0;j<npts+1;j++){
      potential[i][j]=0.0;
    }
  }
  for(int i=0;i<npts+2;i++){
    potential[i][0] = 10.0;
    potential[0][i] = 5.0;
    potential[i][npts+1] = 10.0;
    potential[npts+1][i] = 5.0;
  }

  Laplace_Solver(potential,npts+1,1000);
  PrintGrid(potential,npts+1,"TXT_OUT/A6Q3.txt");
}

void Question3b()
{
  double** potential = new double*[npts+2];
  for(int i=0;i<npts+2;i++)
    potential[i] = new double[npts+2];
  
  for(int i=0;i<npts+1;i++){
    for(int j=0;j<npts+1;j++){
      potential[i][j]=0.0;
    }
  }
  for(int i=0;i<npts+2;i++){
    potential[i][0] = 10.0;
  }

  Laplace_Solver(potential,npts+1,1000);
  PrintGrid(potential,npts+1,"TXT_OUT/A6Q3b.txt");
}
