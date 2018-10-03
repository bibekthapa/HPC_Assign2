#include <iostream>
#include<ctime>

using namespace std;
const int m=10,n=10;
int comparisonArray[m][n];


class Point
{
private:
	int x1,y1;

public:
	Point(){}

	Point(int x,int y)
	{
		x1=x;
		y1=y;
	}
	int getX()
	{
		return x1;
	}

	int getY()
	{

		return y1;
	}
};

bool isMovable(int x, int y){
	bool isMovable = false;
	int xmin = x - 1;
	int ymin = y - 1;
	int xmax = x + 1;
	int ymax = y + 1;
	if (xmin < 0) {xmin = 0;}
	if (ymin < 0) {ymin = 0;}
	if (xmax > m - 1) {xmax = m - 1;}
	if (ymax > m - 1) {ymax = m - 1;}

	for (int i = xmin; i <= xmax; i++){
		for (int j = ymin; j <= ymax; j++ ){
			if (comparisonArray[i][j] == 1){
				isMovable = true;
			}
		}
	}
	return isMovable;
}


bool comparison(int row,int column)
{
	if(comparisonArray[row+1][column]==1)
	{
		return true;
	}
	else if(comparisonArray[row-1][column]==1)
	{
		return true;
	}
	else if(comparisonArray[row][column+1]==1)
	{
		return  true;
	}
	else if(comparisonArray[row][column-1]==1)
	{
		return  true;
	}
	else if(comparisonArray[row+1][column-1]==1)
	{
		return  true;
	}

	else if(comparisonArray[row-1][column+1]==1)
	{
		return  true;
	}
	else if(comparisonArray[row-1][column-1]==1)
	{
		return  true;
	}
	else if(comparisonArray[row+1][column+1]==1)
	{
		return  true;
	}
	else
	{
		return  false;

	}


};

int update(int x)
{
	int max=1;
	int min=-1;

	int randNum = rand()%(max-min + 1) + min;
	int result;
	result =randNum+x;
	if (result<0)
	{
		return 0;
	}
	else if(result>m-1)
	{
		return m-1;
	}
	else
		return result;
}



int main()
{

	int number_of_particles=1000;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			comparisonArray[i][j]=0;
		}
		cout<<"\n";
	}

	int centerX=(m/2);
	int centerY=(n/2);
	comparisonArray[centerX][centerY]=1;
    ////        srand(seed);
	int random_integer = 1+rand()%m;
	int tempX,tempY;

	for(int i=0;i<number_of_particles;i++){
    //            seed=i+1;
		Point p(2,0);
		tempX=p.getX();
		tempY=p.getY();
		int flag=0;

		while(flag!=1){

			if(isMovable(tempX,tempY)==true)
			{
				comparisonArray[tempX][tempY]=1;
				flag=1;
			}
			else
			{
				tempX=update(tempX);
				tempY=update(tempY);

			}

		}

	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<comparisonArray[i][j]<<"\t";
		}
		cout<<"\n";
	}

	return 0;
}
