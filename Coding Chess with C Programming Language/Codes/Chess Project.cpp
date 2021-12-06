#include <stdio.h>
#include <graphics.h>

using namespace std;

int Maximum[3];
int Reverse;
int Tah=0,A=0;
int Elephant=0;
int ElephantX;
int Kish,KishX,KishY;
int ElephantY;
int Board[8][8]={{10,11,12,13,14,12,11,10},{15,15,15,15,15,15,15,15},{},{},{},{},{5,5,5,5,5,5,5,5},{0,1,2,3,4,2,1,0}};
int RA=0,NA=0,BA=0,SA=0;
int ScoreI[16][9][16]={0};
int ValidPathWhite[16][9][16];
int ValidPathBlack[16][9][16];
int Score[16][9][16];
int Mohre[16]={5,5,6,6,6,6,10,0,3,3,3,3,3,3,3,3};

	int IsCheckMateWhite() //Sefid siaho  mat mikone
{

	int i,j,k,m,n,ii,jj,nn,mm,counter=0,counter2=0;

	for(i=1;i<9;i++) //shah mitune dar bere ya na
	{
	    counter=0;
			if(ValidPathBlack[7][i][0]!=-2 && ValidPathBlack[7][i][1]!=-2)
			{
                    counter2++;

                for(k=0;k<16;k++)
                {

                    for(m=1;m<9;m++)
                    {
                        for(n=0;n<16;n+=2)
                            {
                            if(ValidPathBlack[7][i][0]!=ValidPathWhite[k][m][n] || ValidPathBlack[7][i][1]!=ValidPathWhite[k][m][n+1] )
                            counter++;
                            }
                    }

                }

                if(counter==1024 && Board[ValidPathBlack[7][i][1]+1][ValidPathBlack[7][i][0]+1]!=5 &&  Board[ValidPathBlack[7][i][1]+1][ValidPathBlack[7][i][0]-1]!=5 )
                    {

                    return 0;
                    }
			}

	}




	if(counter2==0) //asb kish dade
	{
	    for(i=2;i<4;i++)
		{
				for(j=1;j<8;j++)
				{
					if(ValidPathWhite[i][j][0]==ValidPathBlack[7][0][0] && ValidPathWhite[i][j][1]==ValidPathBlack[7][0][1])//kodom asb?
					{

                        for(k=0;k<16;k++)
                            {
                                for(m=1;m<8;m++)
                                {
                                    for(n=0;n<16;n+=2)
                                    {
                                        if(ValidPathBlack[k][m][n]==ValidPathWhite[i][j][0] && ValidPathBlack[k][m][n+1]==ValidPathWhite[i][j][1])
                                        {

                                            return 0;
                                        }
                                    }
                                }
                            }
                    }
                }
		}
	}


							counter=0;
							int SH=0,CN=0;
                            for(i=0;i<16;i++)
                            {
                                for(j=1;j<8;j++)
                                {
                                    for(k=0;k<16;k+=2)
                                    {

                                        if(ValidPathWhite[i][j][k]==ValidPathBlack[7][0][0] && ValidPathWhite[i][j][k+1]==ValidPathBlack[7][0][1])
                                        {
                                        	counter++;
                                            for(ii=0;ii<16;ii++)
                                                {
                                                    for(jj=1;jj<8;jj++)
                                                        {
                                                            for(mm=0;mm<16;mm+=2)
                                                                {
                                                                    if(ValidPathBlack[ii][jj][mm]==ValidPathWhite[i][0][0] && ValidPathBlack[ii][jj][mm+1]==ValidPathWhite[i][0][1])
                                                                        {
                                                                        SH++;
                                                                        }
                                                                    for(nn=0;nn<k;nn+=2)
                                                                    {

                                            if(ValidPathBlack[ii][jj][mm]==ValidPathWhite[i][j][nn] && ValidPathBlack[ii][jj][mm+1]==ValidPathWhite[i][j][nn+1])
                                                {
                                                    CN++;
                                                }

                                                                    }


                                                                }

                                                        }
                                                }
                                        }
                                        if(counter==1 && (SH!=0 || CN!=0))
                                        return 0;
                                    }
                                }
                            }




	Elephant=1;
	return 1;


}


	int IsCheckMateW() //Sefid siaho  mat mikone
{

	int i,j,k,m,n,ii,jj,nn,mm,counter=0,counter2=0;

	for(i=1;i<9;i++) //shah mitune dar bere ya na
	{
	    counter=0;
			if(ValidPathBlack[7][i][0]!=-2 && ValidPathBlack[7][i][1]!=-2)
			{
                    counter2++;

                for(k=0;k<16;k++)
                {

                    for(m=1;m<9;m++)
                    {
                        for(n=0;n<16;n+=2)
                            {
                            if(ValidPathBlack[7][i][0]!=ValidPathWhite[k][m][n] || ValidPathBlack[7][i][1]!=ValidPathWhite[k][m][n+1] )
                            counter++;
                            }
                    }

                }
                if(counter==1024 && Board[ValidPathBlack[7][i][1]+1][ValidPathBlack[7][i][0]+1]!=5 &&  Board[ValidPathBlack[7][i][1]+1][ValidPathBlack[7][i][0]-1]!=5 )
                    {
                    return 0;
                    }
			}

	}




	if(counter2==0) //asb kish dade
	{
	    for(i=2;i<4;i++)
		{
				for(j=1;j<8;j++)
				{
					if(ValidPathWhite[i][j][0]==ValidPathBlack[7][0][0] && ValidPathWhite[i][j][1]==ValidPathBlack[7][0][1])//kodom asb?
					{

                        for(k=0;k<16;k++)
                            {
                                for(m=1;m<8;m++)
                                {
                                    for(n=0;n<16;n+=2)
                                    {
                                        if(ValidPathBlack[k][m][n]==ValidPathWhite[i][j][0] && ValidPathBlack[k][m][n+1]==ValidPathWhite[i][j][1])
                                        {
                                            return 0;
                                        }
                                    }
                                }
                            }
                    }
                }
		}
	}


							counter=0;
							int SH=0,CN=0;
                            for(i=0;i<16;i++)
                            {
                                for(j=1;j<8;j++)
                                {
                                    for(k=0;k<16;k+=2)
                                    {

                                        if(ValidPathWhite[i][j][k]==ValidPathBlack[7][0][0] && ValidPathWhite[i][j][k+1]==ValidPathBlack[7][0][1])
                                        {
                                        	counter++;
                                            for(ii=0;ii<16;ii++)
                                                {
                                                    for(jj=1;jj<8;jj++)
                                                        {
                                                            for(mm=0;mm<16;mm+=2)
                                                                {
                                                                    if(ValidPathBlack[ii][jj][mm]==ValidPathWhite[i][0][0] && ValidPathBlack[ii][jj][mm+1]==ValidPathWhite[i][0][1])
                                                                        {
                                                                        SH++;
                                                                        }
                                                                    for(nn=0;nn<k;nn+=2)
                                                                    {

                                            if(ValidPathBlack[ii][jj][mm]==ValidPathWhite[i][j][nn] && ValidPathBlack[ii][jj][mm+1]==ValidPathWhite[i][j][nn+1])
                                                {
                                                    CN++;
                                                }

                                                                    }


                                                                }

                                                        }
                                                }
                                        }
                                        if(counter==1 && (SH!=0 || CN!=0))
                                        return 0;
                                    }
                                }
                            }




	Elephant=1;
	return 1;


}



	int IsCheckWhite()//sefid kish shode
{
    int A,B,C;
    for(A=0;A<16;A++)
    {
        for(B=1;B<9;B++)
        {
            for(C=0;C<16;C+=2)
            {
                if(ValidPathBlack[A][B][C]==ValidPathWhite[7][0][0] && ValidPathBlack[A][B][C+1]==ValidPathWhite[7][0][1])
                {
                    return 1;
                }
            }
        }
    }

	return 0;
}


		int IsCheckBlack()//siyah kish shode
{
    int A,B,C;
    for(A=0;A<16;A++)
    {
        for(B=1;B<9;B++)
        {
            for(C=0;C<16;C+=2)
            {
                if(ValidPathWhite[A][B][C]==ValidPathBlack[7][0][0] && ValidPathWhite[A][B][C+1]==ValidPathBlack[7][0][1])
                {
                    return 1;
                }
            }
        }
    }

	return 0;
}







	int IsCheckMateBlack() //siah Sefido mat mikone
{

	int i,j,k,m,n,ii,jj,nn,mm,counter=0,counter2=0;

	for(i=1;i<9;i++) //shah mitune dar bere ya na
	{
	    counter=0;
			if(ValidPathWhite[7][i][0]!=-2 && ValidPathWhite[7][i][1]!=-2)
			{
                    counter2++;

                for(k=0;k<16;k++)
                {

                    for(m=1;m<9;m++)
                    {
                        for(n=0;n<16;n+=2)
                            {
                            if(ValidPathWhite[7][i][0]!=ValidPathBlack[k][m][n] || ValidPathWhite[7][i][1]!=ValidPathBlack[k][m][n+1] )
                            counter++;
                            }
                    }

                }
                if(counter==1024 && Board[ValidPathWhite[7][i][1]-1][ ValidPathWhite[7][i][0]-1] !=15 && Board[ValidPathWhite[7][i][1]-1][ ValidPathWhite[7][i][0]+1] !=15    )//mitone dar bere
                    {
                    return 0;
                    }
			}

	}




	if(counter2==0) //shah validpath nadashte pas asb kish dade
	{
	    for(i=2;i<4;i++)
		{
				for(j=1;j<8;j++)
				{
					if(ValidPathBlack[i][j][0]==ValidPathWhite[7][0][0] && ValidPathBlack[i][j][1]==ValidPathWhite[7][0][1])//kodom asb?
					{

                        for(k=0;k<16;k++)
                            {
                                for(m=1;m<8;m++)
                                {
                                    for(n=0;n<16;n+=2)
                                    {
                                        if(ValidPathWhite[k][m][n]==ValidPathBlack[i][j][0] && ValidPathWhite[k][m][n+1]==ValidPathBlack[i][j][1])
                                        {
                                            return 0;
                                        }
                                    }
                                }
                            }
                    }
                }
		}
	}


							int SH=0,CN=0;
							counter=0;
                            for(i=0;i<16;i++)//zadane mohre kish dahande ya dar masir qarar gereftan
                            {
                                for(j=1;j<8;j++)
                                {
                                    for(k=0;k<16;k+=2)
                                    {

                                        if(ValidPathBlack[i][j][k]==ValidPathWhite[7][0][0] && ValidPathBlack[i][j][k+1]==ValidPathWhite[7][0][1])//kodom mohre kish dade
                                        {
                                        	counter++;//chandta mohre kish dadan

                                            for(ii=0;ii<16;ii++)
                                                {
                                                    for(jj=1;jj<8;jj++)
                                                        {
                                                            for(mm=0;mm<16;mm+=2)
                                                                {
                                                                    if(ValidPathWhite[ii][jj][mm]==ValidPathBlack[i][0][0] && ValidPathWhite[ii][jj][mm+1]==ValidPathBlack[i][0][1])//zadanemohre kish dahande
                                                                        {
                                                                        SH++;
                                                                        }
                                                                    for(nn=0;nn<k;nn+=2)
                                                                    {

                                        						    if(ValidPathWhite[ii][jj][mm]==ValidPathBlack[i][j][nn] && ValidPathWhite[ii][jj][mm+1]==ValidPathBlack[i][j][nn+1]) //mohre mohre ei dar masir qarar begire
                                                						{
                                                  						  CN++;
                                            						    }

                                                                    }


                                                                }

                                                        }
                                                }
                                        }
                                        if(counter==1 && (SH!=0 || CN!=0))
                                        return 0;
                                    }
                                }
                            }




	Elephant=1;
	return 1;


}

	void ZERO_VALID()
	{
		int i,j,k;
		for(i=0;i<16;i++)
		{
			for(j=0;j<9;j++)
			{
				for(k=0;k<16;k++)
				{
				Score[i][j][k]=-20;
				ScoreI[i][j][k]=0;
				ValidPathBlack[i][j][k]=-2;
				ValidPathWhite[i][j][k]=-2;
				}


			}

		}
	}





		int ValidP(int CRNTX,int CRNTY,int TYPE,int dstx,int dsty)
	{
		int counter=0,X=CRNTX,Y=CRNTY,i,j;
		switch (TYPE)
		{

			case  10:


				ValidPathBlack[RA][0][0]=CRNTX;
				ValidPathBlack[RA][0][1]=CRNTY;
				ValidPathBlack[RA][0][2]=TYPE;

				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{
                ValidPathBlack[RA][1][i]=X;
				ValidPathBlack[RA][1][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X--,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{

				ValidPathBlack[RA][2][i]=X;
				ValidPathBlack[RA][2][j]=Y;
				 }
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{

				ValidPathBlack[RA][3][i]=X;
				ValidPathBlack[RA][3][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y--,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{

				ValidPathBlack[RA][4][i]=X;
				ValidPathBlack[RA][4][j]=Y;
				}
				if(counter==2)
				break;

				}
							for(j=1;j<5;j++)//yaftane maqsade motabar
		{

			for(i=0;i<16;i+=2)
			{

				if(dstx==ValidPathBlack[RA][j][i])
				{
					if(dsty==ValidPathBlack[RA][j][i+1])
					{
					return 1;
					}
				}

			}
		}

				break;

			case  11:

				ValidPathBlack[NA+2][0][0]=CRNTX;
				ValidPathBlack[NA+2][0][1]=CRNTY;
				ValidPathBlack[NA+2][0][2]=TYPE;
		if(X+2<8 && X+2>=0 && Y-1>=0 && Y-1<8 && Board[Y-1][X+2]<10)
		{

		ValidPathBlack[NA+2][1][0]=X+2;
		ValidPathBlack[NA+2][1][1]=Y-1;
		}
		if(X-1<8 && X-1>=0 && Y+2<8 && Y+2>=0 && Board[Y+2][X-1]<10)
		{
		ValidPathBlack[NA+2][2][0]=X-1;
		ValidPathBlack[NA+2][2][1]=Y+2;
		}
		if(X+1<8 && X+1>=0 && Y+2<8 && Y+2>=0 && Board[Y+2][X+1]<10)
		{
			ValidPathBlack[NA+2][3][0]=X+1;
			ValidPathBlack[NA+2][3][1]=Y+2;
		}
		if(X-2<8 && X-2>=0 && Y+1<8 && Y+1>=0 && Board[Y+1][X-2]<10)
		{
			ValidPathBlack[NA+2][4][0]=X-2;
			ValidPathBlack[NA+2][4][1]=Y+1;
		}
		if(X+2<8 && X+2>=0 && Y+1<8 && Y+1>=0 && Board[Y+1][X+2]<10)
		{
			ValidPathBlack[NA+2][5][0]=X+2;
			ValidPathBlack[NA+2][5][1]=Y+1;
		}
		if(X-1<8 && X-1>=0 && Y-2<8 && Y-2>=0 && Board[Y-2][X-1]<10)
		{
			ValidPathBlack[NA+2][6][0]=X-1;
			ValidPathBlack[NA+2][6][1]=Y-2;
		}

		if(X+1<8 && X+1>=0 && Y-2<8 && Y-2>=0 && Board[Y-2][X+1]<10)
		{
			ValidPathBlack[NA+2][7][0]=X+1;
			ValidPathBlack[NA+2][7][1]=Y-2;
		}
		if(X-2<8 && X-2>=0 && Y-1<8 && Y-1>=0 && Board[Y-1][X-2]<10)
		{
			ValidPathBlack[NA+2][8][0]=X-2;
			ValidPathBlack[NA+2][8][1]=Y-1;
		}

		for(j=1;j<9;j++)
		{
				if(dstx==ValidPathBlack[NA+2][j][0])
				{
					if(dsty==ValidPathBlack[NA+2][j][1])
					{
					return 1;
					}
				}
		}


				break;


			case  12:

				ValidPathBlack[BA+4][0][0]=CRNTX;
				ValidPathBlack[BA+4][0][1]=CRNTY;
				ValidPathBlack[BA+4][0][2]=TYPE;

				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X++,Y++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{

				ValidPathBlack[BA+4][1][i]=X;
				ValidPathBlack[BA+4][1][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X--,Y++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{

				ValidPathBlack[BA+4][2][i]=X;
				ValidPathBlack[BA+4][2][j]=Y;
				 }
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y--,X++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{

				ValidPathBlack[BA+4][3][i]=X;
				ValidPathBlack[BA+4][3][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y--,X--,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{

				ValidPathBlack[BA+4][4][i]=X;
				ValidPathBlack[BA+4][4][j]=Y;
				}
				if(counter==2)
				break;

				}


				for(j=1;j<5;j++)
		{

			for(i=0;i<16;i+=2)
			{

				if(dstx==ValidPathBlack[BA+4][j][i])
				{
					if(dsty==ValidPathBlack[BA+4][j][i+1])
					{
					return 1;
					}
				}

			}
		}



				break;


			case  13:

				ValidPathBlack[6][0][0]=CRNTX;
				ValidPathBlack[6][0][1]=CRNTY;
				ValidPathBlack[6][0][2]=TYPE;

				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1)
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{

				ValidPathBlack[6][1][i]=X;
				ValidPathBlack[6][1][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X--,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{

				ValidPathBlack[6][2][i]=X;
				ValidPathBlack[6][2][j]=Y;
				 }
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{

				ValidPathBlack[6][3][i]=X;
				ValidPathBlack[6][3][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y--,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{

				ValidPathBlack[6][4][i]=X;
				ValidPathBlack[6][4][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X++,Y++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{

				ValidPathBlack[6][5][i]=X;
				ValidPathBlack[6][5][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X--,Y++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{

				ValidPathBlack[6][6][i]=X;
				ValidPathBlack[6][6][j]=Y;
				 }
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y--,X++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{

				ValidPathBlack[6][7][i]=X;
				ValidPathBlack[6][7][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y--,X--,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]<10)
				{

				ValidPathBlack[6][8][i]=X;
				ValidPathBlack[6][8][j]=Y;
				}
				if(counter==2)
				break;

				}


		for(j=1;j<9;j++)
		{

			for(i=0;i<16;i+=2)
			{

				if(dstx==ValidPathBlack[6][j][i])
				{
					if(dsty==ValidPathBlack[6][j][i+1])
					{
					return 1;
					}
				}

			}
		}


				break;


			case  14:

				ValidPathBlack[7][0][0]=CRNTX;
				ValidPathBlack[7][0][1]=CRNTY;
				ValidPathBlack[7][0][2]=TYPE;

		if(X+1<8 && X+1>=0 && Y-1>=0 && Y-1<8 && Board[Y-1][X+1]<10)
		{

		ValidPathBlack[7][1][0]=X+1;
		ValidPathBlack[7][1][1]=Y-1;
		}
		if(X-1<8 && X-1>=0 && Y+1<8 && Y+1>=0 && Board[Y+1][X-1]<10)
		{
		ValidPathBlack[7][2][0]=X-1;
		ValidPathBlack[7][2][1]=Y+1;
		}
		if(X+1<8 && X+1>=0 && Y+1<8 && Y+1>=0 && Board[Y+1][X+1]<10)
		{
			ValidPathBlack[7][3][0]=X+1;
			ValidPathBlack[7][3][1]=Y+1;
		}
		if(X-1<8 && X-1>=0 && Y-1<8 && Y-1>=0 && Board[Y-1][X-1]<10)
		{
			ValidPathBlack[7][4][0]=X-1;
			ValidPathBlack[7][4][1]=Y-1;
		}
		if(Y+1<8 && Y+1>=0 && Board[Y+1][X]<10)
		{
			ValidPathBlack[7][5][0]=X;
			ValidPathBlack[7][5][1]=Y+1;
		}
		if(X-1<8 && X-1>=0  && Board[Y][X-1]<10)
		{
			ValidPathBlack[7][6][0]=X-1;
			ValidPathBlack[7][6][1]=Y;
		}

		if(X+1<8 && X+1>=0  && Board[Y][X+1]<10)
		{
			ValidPathBlack[7][7][0]=X+1;
			ValidPathBlack[7][7][1]=Y;
		}
		if( Y-1<8 && Y-1>=0 && Board[Y-1][X]<10)
		{
			ValidPathBlack[7][8][0]=X;
			ValidPathBlack[7][8][1]=Y-1;
		}


		for(j=1;j<9;j++)
		{
				if(dstx==ValidPathBlack[7][j][0])
				{
					if(dsty==ValidPathBlack[7][j][1])
					{
					return 1;
					}
				}
		}



				break;


			case  15:
				ValidPathBlack[SA+8][0][0]=CRNTX;
				ValidPathBlack[SA+8][0][1]=CRNTY;
				ValidPathBlack[SA+8][0][2]=TYPE;

			if(X+1<8 && X+1>=0 && Y+1<8 && Y+1>=0 && Board[Y+1][X+1]<10 && Board[Y+1][X+1]!=-1 )
		{
			ValidPathBlack[SA+8][1][0]=X+1;
			ValidPathBlack[SA+8][1][1]=Y+1;
		}

		if(X-1<8 && X-1>=0 && Y+1<8 && Y+1>=0 && Board[Y+1][X-1]<10 && Board[Y+1][X-1]!=-1)
		{
			ValidPathBlack[SA+8][2][0]=X-1;
			ValidPathBlack[SA+8][2][1]=Y+1;
		}


		if(X<8 && X>=0 && Y+1<8 && Y+1>=0 && Board[Y+1][X]==-1 )
		{
			ValidPathBlack[SA+8][3][0]=X;
			ValidPathBlack[SA+8][3][1]=Y+1;

			if(Y==1 && Board[Y+2][X]==-1 )
			{
			ValidPathBlack[SA+8][3][2]=X;
			ValidPathBlack[SA+8][3][3]=Y+2;
			}
		}
			for(j=1;j<4;j++)
		{

			for(i=0;i<4;i+=2)
			{

				if(dstx==ValidPathBlack[SA+8][j][i])
				{
					if(dsty==ValidPathBlack[SA+8][j][i+1])
					{
					return 1;
					}
				}

			}
		}





				break;

			case  0:


				ValidPathWhite[RA][0][0]=CRNTX;
				ValidPathWhite[RA][0][1]=CRNTY;
				ValidPathWhite[RA][0][2]=TYPE;


				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

				ValidPathWhite[RA][1][i]=X;
				ValidPathWhite[RA][1][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X--,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

				ValidPathWhite[RA][2][i]=X;
				ValidPathWhite[RA][2][j]=Y;
				 }
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

				ValidPathWhite[RA][3][i]=X;
				ValidPathWhite[RA][3][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y--,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

				ValidPathWhite[RA][4][i]=X;
				ValidPathWhite[RA][4][j]=Y;
				}
				if(counter==2)
				break;

				}

				for(j=1;j<5;j++)
		{

			for(i=0;i<16;i+=2)
			{

				if(dstx==ValidPathWhite[RA][j][i])
				{
					if(dsty==ValidPathWhite[RA][j][i+1])
					{
					return 1;
					}
				}

			}
		}

				break;

			case  1:


				ValidPathWhite[NA+2][0][0]=CRNTX;
				ValidPathWhite[NA+2][0][1]=CRNTY;
				ValidPathWhite[NA+2][0][2]=TYPE;

		if(X+2<8 && X+2>=0 && Y-1>=0 && Y-1<8 && (Board[Y-1][X+2]>=10 || Board[Y-1][X+2]==-1))
		{

		ValidPathWhite[NA+2][1][0]=X+2;
		ValidPathWhite[NA+2][1][1]=Y-1;
		}
		if(X-1<8 && X-1>=0 && Y+2<8 && Y+2>=0 && (Board[Y+2][X-1]>=10 || Board[Y+2][X-1]==-1))
		{
		ValidPathWhite[NA+2][2][0]=X-1;
		ValidPathWhite[NA+2][2][1]=Y+2;
		}
		if(X+1<8 && X+1>=0 && Y+2<8 && Y+2>=0 && (Board[Y+2][X+1]>=10 || Board[Y+2][X+1]==-1))
		{
			ValidPathWhite[NA+2][3][0]=X+1;
			ValidPathWhite[NA+2][3][1]=Y+2;
		}
		if(X-2<8 && X-2>=0 && Y+1<8 && Y+1>=0 &&(Board[Y+1][X-2]>=10 || Board[Y+1][X-2]==-1))
		{
			ValidPathWhite[NA+2][4][0]=X-2;
			ValidPathWhite[NA+2][4][1]=Y+1;
		}
		if(X+2<8 && X+2>=0 && Y+1<8 && Y+1>=0 &&(Board[Y+1][X+2]>=10 || Board[Y+1][X+2]==-1))
		{
			ValidPathWhite[NA+2][5][0]=X+2;
			ValidPathWhite[NA+2][5][1]=Y+1;
		}
		if(X-1<8 && X-1>=0 && Y-2<8 && Y-2>=0 && (Board[Y-2][X-1]>=10 || Board[Y-2][X-1]==-1))
		{
			ValidPathWhite[NA+2][6][0]=X-1;
			ValidPathWhite[NA+2][6][1]=Y-2;
		}

		if(X+1<8 && X+1>=0 && Y-2<8 && Y-2>=0 && (Board[Y-2][X+1]>=10 || Board[Y-2][X+1]==-1))
		{
			ValidPathWhite[NA+2][7][0]=X+1;
			ValidPathWhite[NA+2][7][1]=Y-2;
		}
		if(X-2<8 && X-2>=0 && Y-1<8 && Y-1>=0 &&(Board[Y-1][X-2]>=10 || Board[Y-1][X-2]==-1))
		{
			ValidPathWhite[NA+2][8][0]=X-2;
			ValidPathWhite[NA+2][8][1]=Y-1;
		}


				for(j=1;j<9;j++)
		{
				if(dstx==ValidPathWhite[NA+2][j][0])
				{
					if(dsty==ValidPathWhite[NA+2][j][1])
					{
					return 1;
					}
				}
		}
				break;


			case  2:

				ValidPathWhite[BA+4][0][0]=CRNTX;
				ValidPathWhite[BA+4][0][1]=CRNTY;
				ValidPathWhite[BA+4][0][2]=TYPE;

				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X++,Y++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

					ValidPathWhite[BA+4][1][i]=X;
					ValidPathWhite[BA+4][1][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X--,Y++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

					ValidPathWhite[BA+4][2][i]=X;
					ValidPathWhite[BA+4][2][j]=Y;
				 }
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y--,X++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

					ValidPathWhite[BA+4][3][i]=X;
					ValidPathWhite[BA+4][3][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y--,X--,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

					ValidPathWhite[BA+4][4][i]=X;
					ValidPathWhite[BA+4][4][j]=Y;
				}
				if(counter==2)
				break;

				}

				for(j=1;j<5;j++)
		{

			for(i=0;i<16;i+=2)
			{

				if(dstx==ValidPathWhite[BA+4][j][i])
				{
					if(dsty==ValidPathWhite[BA+4][j][i+1])
					{
					return 1;
					}
				}

			}
		}

				break;


			case  3:

				ValidPathWhite[6][0][0]=CRNTX;
				ValidPathWhite[6][0][1]=CRNTY;
				ValidPathWhite[6][0][2]=TYPE;

				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1)
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

				ValidPathWhite[6][1][i]=X;
				ValidPathWhite[6][1][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X--,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

				ValidPathWhite[6][2][i]=X;
				ValidPathWhite[6][2][j]=Y;
				 }
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

				ValidPathWhite[6][3][i]=X;
				ValidPathWhite[6][3][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y--,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

				ValidPathWhite[6][4][i]=X;
				ValidPathWhite[6][4][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X++,Y++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

				ValidPathWhite[6][5][i]=X;
				ValidPathWhite[6][5][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;X--,Y++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

				ValidPathWhite[6][6][i]=X;
				ValidPathWhite[6][6][j]=Y;
				 }
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y--,X++,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

				ValidPathWhite[6][7][i]=X;
				ValidPathWhite[6][7][j]=Y;
				}
				if(counter==2)
				break;

				}
				X=CRNTX;
				Y=CRNTY;
				counter=0;
				for(i=0,j=1;0<=X && X<8 && 0<=Y &&Y<8 ;Y--,X--,i+=2,j+=2)
				{

				if(Board[Y][X]!=-1 )
				counter++;
				if(Board[Y][X]==-1 || Board[Y][X]>=10)
				{

				ValidPathWhite[6][8][i]=X;
				ValidPathWhite[6][8][j]=Y;
				}
				if(counter==2)
				break;

				}

				for(j=1;j<9;j++)
		{

			for(i=0;i<16;i+=2)
			{

				if(dstx==ValidPathWhite[6][j][i])
				{
					if(dsty==ValidPathWhite[6][j][i+1])
					{
					return 1;
					}
				}

			}
		}
				break;

			case  4:

				ValidPathWhite[7][0][0]=CRNTX;
				ValidPathWhite[7][0][1]=CRNTY;
				ValidPathWhite[7][0][2]=TYPE;
		if(X+1<8 && X+1>=0 && Y-1>=0 && Y-1<8 && (Board[Y-1][X+1]>=10 || Board[Y-1][X+1]==-1))
		{

		ValidPathWhite[7][1][0]=X+1;
		ValidPathWhite[7][1][1]=Y-1;
		}
		if(X-1<8 && X-1>=0 && Y+1<8 && Y+1>=0 && (Board[Y+1][X-1]>=10 || Board[Y+1][X-1]==-1))
		{
		ValidPathWhite[7][2][0]=X-1;
		ValidPathWhite[7][2][1]=Y+1;
		}
		if(X+1<8 && X+1>=0 && Y+1<8 && Y+1>=0 && (Board[Y+1][X+1]>=10 || Board[Y+1][X+1]==-1))
		{
			ValidPathWhite[7][3][0]=X+1;
			ValidPathWhite[7][3][1]=Y+1;
		}
		if(X-1<8 && X-1>=0 && Y-1<8 && Y-1>=0 && (Board[Y-1][X-1]>=10 || Board[Y-1][X-1]==-1) )
		{
			ValidPathWhite[7][4][0]=X-1;
			ValidPathWhite[7][4][1]=Y-1;
		}
		if(Y+1<8 && Y+1>=0 && (Board[Y+1][X]>=10 || Board[Y+1][X]==-1))
		{
			ValidPathWhite[7][5][0]=X;
			ValidPathWhite[7][5][1]=Y+1;
		}
		if(X-1<8 && X-1>=0  && (Board[Y][X-1]>=10 || Board[Y][X-1]==-1))
		{
			ValidPathWhite[7][6][0]=X-1;
			ValidPathWhite[7][6][1]=Y;
		}

		if(X+1<8 && X+1>=0  && (Board[Y][X+1]>=10 || Board[Y][X+1]==-1))
		{
			ValidPathWhite[7][7][0]=X+1;
			ValidPathWhite[7][7][1]=Y;
		}
		if( Y-1<8 && Y-1>=0 && (Board[Y-1][X]>=10 || Board[Y-1][X]==-1))
		{
			ValidPathWhite[7][8][0]=X;
			ValidPathWhite[7][8][1]=Y-1;
		}

				for(j=1;j<9;j++)
		{
				if(dstx==ValidPathWhite[7][j][0])
				{
					if(dsty==ValidPathWhite[7][j][1])
					{
					return 1;
					}
				}
		}
				break;


			case  5:

				ValidPathWhite[SA+8][0][0]=CRNTX;
				ValidPathWhite[SA+8][0][1]=CRNTY;
				ValidPathWhite[SA+8][0][2]=TYPE;

			if(X+1<8 && X+1>=0 && Y-1<8 && Y-1>=0 && Board[Y-1][X+1]>=10 )
		{
			ValidPathWhite[SA+8][1][0]=X+1;
			ValidPathWhite[SA+8][1][1]=Y-1;
		}
		if(X-1<8 && X-1>=0 && Y-1<8 && Y-1>=0 && Board[Y-1][X-1]>=10 )
		{
			ValidPathWhite[SA+8][2][0]=X-1;
			ValidPathWhite[SA+8][2][1]=Y-1;
		}
		if(X<8 && X>=0 && Y-1<8 && Y-1>=0 && Board[Y-1][X]==-1 )
		{
			ValidPathWhite[SA+8][3][0]=X;
			ValidPathWhite[SA+8][3][1]=Y-1;
			if(Y==6 && Board[Y-2][X]==-1 )
			{
			ValidPathWhite[SA+8][3][2]=X;
			ValidPathWhite[SA+8][3][3]=Y-2;
			}

		}
		for(j=1;j<4;j++)
		{

			for(i=0;i<4;i+=2)
			{

				if(dstx==ValidPathWhite[SA+8][j][i])
				{
					if(dsty==ValidPathWhite[SA+8][j][i+1])
					{
					return 1;
					}
				}

			}
		}
				break;
		}
		return 0;
	}

void update()
				 {

                RA=0,BA=0,SA=0,NA=0;
                int CRNTX,CRNTY;
                ZERO_VALID();
				for(CRNTY=0;CRNTY<8;CRNTY++)
				{
					for(CRNTX=0;CRNTX<8;CRNTX++)
					{
						if(Board[CRNTY][CRNTX]==5)
						{

						ValidP(CRNTX,CRNTY,5,-10,-10);
						SA++;
						}
						if(Board[CRNTY][CRNTX]==4)
						{

						ValidP(CRNTX,CRNTY,4,-10,-10);
						}
						if(Board[CRNTY][CRNTX]==3)
						{

						ValidP(CRNTX,CRNTY,3,-10,-10);
						}
						if(Board[CRNTY][CRNTX]==2)
						{

						ValidP(CRNTX,CRNTY,2,-10,-10);
						BA++;
						}
						if(Board[CRNTY][CRNTX]==1)
						{

						ValidP(CRNTX,CRNTY,1,-10,-10);
						NA++;
						}
						if(Board[CRNTY][CRNTX]==0)
						{

						ValidP(CRNTX,CRNTY,0,-10,-10);
						RA++;
						}

					}
				}


				RA=0,BA=0,SA=0,NA=0;
				for(CRNTY=0;CRNTY<8;CRNTY++)
				{
					for(CRNTX=0;CRNTX<8;CRNTX++)
					{
						if(Board[CRNTY][CRNTX]==15)
						{

						ValidP(CRNTX,CRNTY,15,0,0);
						SA++;
						}
						if(Board[CRNTY][CRNTX]==14)
						{

						ValidP(CRNTX,CRNTY,14,0,0);
						}
						if(Board[CRNTY][CRNTX]==13)
						{

						ValidP(CRNTX,CRNTY,13,0,0);
						}
						if(Board[CRNTY][CRNTX]==12)
						{

						ValidP(CRNTX,CRNTY,12,0,0);
						BA++;
						}
						if(Board[CRNTY][CRNTX]==11)
						{

						ValidP(CRNTX,CRNTY,11,0,0);
						NA++;
						}
						if(Board[CRNTY][CRNTX]==10)
						{

						ValidP(CRNTX,CRNTY,10,0,0);
						RA++;
						}

					}
				}
			RA=0,NA=0,SA=0,BA=0;}

void update_II()
				 {

                RA=0,BA=0,SA=0,NA=0;
                int CRNTX,CRNTY;
				for(CRNTY=0;CRNTY<8;CRNTY++)
				{
					for(CRNTX=0;CRNTX<8;CRNTX++)
					{
						if(Board[CRNTY][CRNTX]==5)
						{

						ValidP(CRNTX,CRNTY,5,-10,-10);
						SA++;
						}
						if(Board[CRNTY][CRNTX]==4)
						{

						ValidP(CRNTX,CRNTY,4,-10,-10);
						}
						if(Board[CRNTY][CRNTX]==3)
						{

						ValidP(CRNTX,CRNTY,3,-10,-10);
						}
						if(Board[CRNTY][CRNTX]==2)
						{

						ValidP(CRNTX,CRNTY,2,-10,-10);
						BA++;
						}
						if(Board[CRNTY][CRNTX]==1)
						{

						ValidP(CRNTX,CRNTY,1,-10,-10);
						NA++;
						}
						if(Board[CRNTY][CRNTX]==0)
						{

						ValidP(CRNTX,CRNTY,0,-10,-10);
						RA++;
						}

					}
				}


				RA=0,BA=0,SA=0,NA=0;
				for(CRNTY=0;CRNTY<8;CRNTY++)
				{
					for(CRNTX=0;CRNTX<8;CRNTX++)
					{
						if(Board[CRNTY][CRNTX]==15)
						{

						ValidP(CRNTX,CRNTY,15,0,0);
						SA++;
						}
						if(Board[CRNTY][CRNTX]==14)
						{

						ValidP(CRNTX,CRNTY,14,0,0);
						}
						if(Board[CRNTY][CRNTX]==13)
						{

						ValidP(CRNTX,CRNTY,13,0,0);
						}
						if(Board[CRNTY][CRNTX]==12)
						{

						ValidP(CRNTX,CRNTY,12,0,0);
						BA++;
						}
						if(Board[CRNTY][CRNTX]==11)
						{

						ValidP(CRNTX,CRNTY,11,0,0);
						NA++;
						}
						if(Board[CRNTY][CRNTX]==10)
						{

						ValidP(CRNTX,CRNTY,10,0,0);
						RA++;
						}

					}
				}
			RA=0,NA=0,SA=0,BA=0;}




	int NoeMohre(int i,int j,int k)
	{

		int TypeMohre=Board[ValidPathBlack[i][j][k+1]][ValidPathBlack[i][j][k]];

		if(TypeMohre==0)
		return 5;
		if(TypeMohre==1)
		return 6;
		if(TypeMohre==2)
		return 6;
		if(TypeMohre==3)
		return 10;
		if(TypeMohre==5)
		return 3;

	}




int IsSafe(int BlackDstx,int BlackDsty)
{

		int i,j,k;
		for(i=0;i<16;i++)
		{
			for(j=1;j<9;j++)
			{
				for(k=0;k<16;k+=2)
				{

				if(ValidPathWhite[i][j][k]==BlackDstx && ValidPathWhite[i][j][k+1]==BlackDsty)
                {

				return 1;
                }
				}
			}

		}


	return 0;
}


int IsCheck(int i,int BlackDstx,int BlackDsty,int TYPE,int BlackCntx,int BlackCnty)
{

    int j,k,ii,iii;

		for(ii=0;ii<9;ii++)
				{
					for(iii=0;iii<16;iii++)
					{
						ValidPathBlack[i][ii][iii]=-2;
					}
				}

		ValidP(BlackDstx,BlackDsty,TYPE,0,0);
		for(j=1;j<9;j++)
        {

				for(k=0;k<16;k+=2)
				{
				if(ValidPathWhite[7][0][0]==ValidPathBlack[i][j][k] && ValidPathWhite[7][0][1]==ValidPathBlack[i][j][k+1])
				{

				for(ii=0;ii<9;ii++)
				{
					for(iii=0;iii<16;iii++)
					{
						ValidPathBlack[i][ii][iii]=-2;

					}
				}
				ValidP(BlackCntx,BlackCnty,TYPE,0,0);
				return 1;
				}
				}
        }

	for(ii=0;ii<9;ii++)
				{
					for(iii=0;iii<16;iii++)
					{
						ValidPathBlack[i][ii][iii]=-2;
					}
				}

	ValidP(BlackCntx,BlackCnty,TYPE,0,0);
	return 0;
}


int IsCheckMateB(int ii,int jj) //siah Sefido mat mikone //ye nafare
{

	int i,j,k,m,n,counter=0,counter2=0;

	for(i=1;i<9;i++) //shah mitune dar bere ya na
	{
	    counter=0;
			if(ValidPathWhite[7][i][0]!=-2 && ValidPathWhite[7][i][1]!=-2)
			{
                    counter2++;
                for(k=0;k<16;k++)
                {

                    for(m=1;m<9;m++)
                    {
                        for(n=0;n<16;n+=2)
                            {
                            if(ValidPathWhite[7][i][0]!=ValidPathBlack[k][m][n] || ValidPathWhite[7][i][1]!=ValidPathBlack[k][m][n+1] )
                            counter++;
                            }
                    }

                }
                if(counter==1024)
                    {

                    return 0;
                    }
			}

	}

	if(counter2==0) //asb kish dade
	{
		for(i=0;i<16;i++)
		{
				for(j=1;j<8;j++)
				{
					for(m=0;m<16;m++)
					{
						if(ValidPathWhite[i][j][m]==ValidPathBlack[ii][0][0] && ValidPathWhite[i][j][m]==ValidPathBlack[ii][0][1])
						{

						return 0;
						}
					}
				}
		}
	}
	for(k=0;ValidPathWhite[7][0][0]!=ValidPathBlack[ii][jj][k] && ValidPathWhite[7][0][1]!=ValidPathBlack[ii][jj][k+1];k++ )
	{
		for(i=0;i<16;i++)
		{
			for(j=1;j<8;j++)
			{
				for(m=0;m<16;m+=2)
				{
					if(ValidPathWhite[i][j][m]==ValidPathBlack[ii][jj][k] && ValidPathWhite[i][j][m+1]==ValidPathBlack[ii][jj][k+1])
					{
					return 0;
					}
					if(ValidPathWhite[i][j][m]==ValidPathBlack[ii][0][0] && ValidPathWhite[i][j][m]==ValidPathBlack[ii][0][1])
					{
					return 0;
					}
				}
			}
		}



	}

	Elephant=1;
	return 1;


}




	void SCORE()
	{

		int I,j,k,V=0;
		RA=0,BA=0,NA=0;
		SA=0;

		for(I=0;I<16;I++)
		{



			AVAL :
			    int EE;

			for(j=1;j<9;j++)
			{
                printf("i = %d j = %d k = %d \n",I,j,k);

				for(k=0;k<16;k+=2)
				{



                    if(I==7)
					{
                    for(j=1;j<9;j++)
                    {

                    for(k=0;k<16;k+=2)
                    {

                    if( ValidPathBlack[I][j][k]!=-2&& ValidPathBlack[I][j][k+1]!=-2)
					Score[I][j][k]=0+ScoreI[I][j][k];
                    }
                    }
					I++;
					V=5;
					goto AVAL;
					}
				if( ValidPathBlack[I][j][k]!=-2&& ValidPathBlack[I][j][k+1]!=-2)
				{





						if(Board[ ValidPathBlack[I][j][k+1]  ] [ ValidPathBlack[I][j][k] ]==-1 ) //harekate khali
						{

							if(IsSafe(ValidPathBlack[I][j][k],ValidPathBlack[I][j][k+1])==1 || (Board[ ValidPathBlack[I][j][k+1] +1 ] [ ValidPathBlack[I][j][k] +1]==5 && (ValidPathBlack[I][j][k] +1<8)) ||  (Board[ ValidPathBlack[I][j][k+1]+1 ] [ ValidPathBlack[I][j][k]-1]==5 && ValidPathBlack[I][j][k]-1>-1) ) //dar khatare
							{


						if( IsCheck(I,ValidPathBlack[I][j][k],ValidPathBlack[I][j][k+1],V+10,ValidPathBlack[I][0][0],ValidPathBlack[I][0][1])==0)
								{


                                Score[I][j][k]=3-3-Mohre[I]+ScoreI[I][j][k];


								}
                            else
								{


									if(IsCheckMateB(I,j)==0)
								{

									Score[I][j][k]=9-3-Mohre[I]+ScoreI[I][j][k];
                                    printf("SCOREEEEA = %d \n",Score[I][j][k]);
								}
								else
								{
									Score[I][j][k]=25-3-Mohre[I]+ScoreI[I][j][k];

								}
								}


							}
							else
                        {

						if(  IsCheck(I,ValidPathBlack[I][j][k],ValidPathBlack[I][j][k+1],V+10,ValidPathBlack[I][0][0],ValidPathBlack[I][0][1])==0 )
								{


                                    Score[I][j][k]=3-Mohre[I]+ScoreI[I][j][k];

								}
                            else
								{

                                    if(IsCheckMateB(I,j)==0)
								{
									Score[I][j][k]=9-Mohre[I]+ScoreI[I][j][k];
									printf("SCOREEEEA = %d \n",Score[I][j][k]);

								}
								else
								{

									Score[I][j][k]=25-Mohre[I]+ScoreI[I][j][k];

								}


								}




						}




					}
						else if(Board[ ValidPathBlack[I][j][k+1]  ] [ ValidPathBlack[I][j][k] ]!=-1 && Board[ ValidPathBlack[I][j][k+1]  ] [ ValidPathBlack[I][j][k] ]!=4 ) //zadan
						{

					int ScoreMohre=NoeMohre(I,j,k);


							if(IsSafe(ValidPathBlack[I][j][k],ValidPathBlack[I][j][k+1])==1 || (Board[ ValidPathBlack[I][j][k+1] +1 ] [ ValidPathBlack[I][j][k] +1]==5 && (ValidPathBlack[I][j][k] +1!=8)) ||  (Board[ ValidPathBlack[I][j][k+1]+1 ] [ ValidPathBlack[I][j][k]-1]==5 && ValidPathBlack[I][j][k]-1!=-1) )
                                {


						if(  IsCheck(I,ValidPathBlack[I][j][k],ValidPathBlack[I][j][k+1],V+10,ValidPathBlack[I][0][0],ValidPathBlack[I][0][1])==0 )
								{
										Score[I][j][k]=9+ScoreMohre-3-Mohre[I]+ScoreI[I][j][k];



								}
						else
                            {

									if(IsCheckMateB(I,j)==0)
								{
									Score[I][j][k]=9+9+ScoreMohre-3-Mohre[I]+ScoreI[I][j][k];
									printf("SCOREEEEA = %d \n",Score[I][j][k]);

								}
							else
								{
									Score[I][j][k]=25+9+ScoreMohre-3-Mohre[I]+ScoreI[I][j][k];
									printf("SCOREEEEA = %d \n",Score[I][j][k]);

								}
								}



							}
                                else
                                    {

							if(  IsCheck(I,ValidPathBlack[I][j][k],ValidPathBlack[I][j][k+1],V+10,ValidPathBlack[I][0][0],ValidPathBlack[I][0][1])==0 )
								{

                                    Score[I][j][k]=9+ScoreMohre-Mohre[I]+ScoreI[I][j][k];


								}
						else
								{

									if(IsCheckMateB(I,j)==0)
								{
									Score[I][j][k]=9+9+ScoreMohre-Mohre[I]+ScoreI[I][j][k];

								}
								else
								{
									Score[I][j][k]=25+9+ScoreMohre-Mohre[I]+ScoreI[I][j][k];

								}

								}


							}

						}




				}

				}
			}

			if(I<5)
			{

		if(I%2!=0)
		{
			V++;
			RA=0;
			BA=0;
			NA=0;
		}
		else if(I%2==0)
		{
			RA++;
			BA++;
			NA++;
		}
			}
		if(I==5 || I==6)
		V++;
		if(I<15 && I>7)
		{

		V=5;
		SA++;
		}

	}

}


void MaxScore()
{
	int i,j,k;
	int MAX;
    sar:
	MAX=Score[0][0][0];
	for(i=0;i<16;i++)
		{
			for(j=1;j<9;j++)
			{
				for(k=0;k<16;k+=2)
				{
					if(MAX<=Score[i][j][k])
					{

						if(Board[ValidPathWhite[i][j][k+1]][ValidPathWhite[i][j][k]]==4)
						continue;

						MAX=Score[i][j][k];
						Maximum[0]=i;
						Maximum[1]=j;
						Maximum[2]=k;

					}

				}
			}
		}

		if(Maximum[0]==7)
        {

        Kish=Board[ ValidPathBlack[Maximum[0]][Maximum[1]][Maximum[2]+1]][ ValidPathBlack[Maximum[0]][Maximum[1]][Maximum[2]] ];
        KishX=ValidPathBlack[7][0][0];
        KishY=ValidPathBlack[7][0][1];
        Board[ValidPathBlack[7][0][1]][ValidPathBlack[7][0][0]]=-1;
        Board[ ValidPathBlack[Maximum[0]][Maximum[1]][Maximum[2]+1]][ ValidPathBlack[Maximum[0]][Maximum[1]][Maximum[2]] ]=-1;

        update_II();

    for(j=0;j<16;j++)
      {


        for(i=1;i<9;i++)
            {


            for(k=0;k<16;k+=2)
            {
                    if((ValidPathWhite[j][i][k+1]==ValidPathBlack[7][Maximum[1]][Maximum[2]+1] && ValidPathWhite[j][i][k]==ValidPathBlack[7][Maximum[1]][Maximum[2]]) || (Board[ValidPathBlack[7][Maximum[1]][Maximum[2]+1]+1][ValidPathBlack[7][Maximum[1]][Maximum[2]]+1]==5) || (Board[ValidPathBlack[7][Maximum[1]][Maximum[2]+1]+1][ValidPathBlack[7][Maximum[1]][Maximum[2]]-1]==5)       )
                       {

                           Board[ ValidPathBlack[Maximum[0]][Maximum[1]][Maximum[2]+1]][ ValidPathBlack[Maximum[0]][Maximum[1]][Maximum[2]] ]=Kish;
                            Board[KishY][KishX]=14;
                           update_II();
                           Score[7][Maximum[1]][Maximum[2]]+=-200;
                           goto sar;
                       }
            }

            }
      }
        Board[ ValidPathBlack[Maximum[0]][Maximum[1]][Maximum[2]+1]][ ValidPathBlack[Maximum[0]][Maximum[1]][Maximum[2]] ]=Kish;
        Board[KishY][KishX]=14;
        update_II();
    }
    if(A==1)
    {
        if(MAX<80)
            Elephant=1;
    }

}


void Set()
	{
		int i,j;
		for(j=2;j<6;j++)
		{

		for(i=0;i<8;i++)
		{
			Board[j][i]=-1;
		}
		}
	}




void pawnpat(char c,int i,int j){

    if(c=='b') {
            setfillstyle(1,4);
            setcolor(4);
    }
    if(c=='w') {
            setfillstyle(1,1);
            setcolor(1);
    }
    line(i+10,j+45,i+30+10,j+45);
    line(i+30+10,j+45,i+15+10,j-30+45);
    line(i+15+10,j+45-30,i+10,j+45);
    fillellipse(i+15+10,j-30+45,10,10);
    if(c=='b') floodfill(i+15+10,j-10+45,4);
    if(c=='w') floodfill(i+15+10,j-10+45,1);
    }

    void rookpat(char c,int i,int j){
    if(c=='b') setfillstyle(1,4);
    if(c=='w') setfillstyle(1,1);
    bar(i+5,j+5,i+10+5,j+5+5);
    bar(i+15+5,j+5,i+25+5,j+5+5);
    bar(i+30+5,j+5,i+40+5,j+5+5);
    bar(i+5,j+5+5,i+40+5,j+40+5);
    }
void horsepat(char c,int i,int j){
    if(c=='b') setfillstyle(1,4);
    if(c=='w') setfillstyle(1,1);
    bar(i+10,j+5,i+5+10,j+5+5+5);
    bar(i+10,j+40+5,i+20+10,j+25+5);
    bar(i+10,j+5+5,i+35+10,j+25+5);
    bar(i-5+10,j+40+5,i+10,j+35+5);
    bar(i-5+10,j+30+5,i+10,j+25+5);
    bar(i-5+10,j+20+5,i+10,j+15+5);
    }
void bishoppat(char c,int i,int j){
    if(c=='b') {
            setfillstyle(1,4);
            setcolor(4);
    }
    if(c=='w') {
            setfillstyle(1,1);
            setcolor(1);
    }
    bar(i+5,j+45,i+40+5,j-15+45);
    fillellipse(i+20+5,j-15+45,20,15);
    fillellipse(i+20+5,j-32+45,5,5);
    }
void quinpat(char c,int i,int j){
    if(c=='b') {
            setfillstyle(1,4);
            setcolor(4);
    }
    if(c=='w') {
            setfillstyle(1,1);
            setcolor(1);
    }
    fillellipse(i+25,j+25,10,10);
    fillellipse(i-10+25,j+25,10,10);
    fillellipse(i+10+25,j+25,10,10);
    fillellipse(i+25,j-15+25,5,5);
    fillellipse(i-10+25,j-15+25,5,5);
    fillellipse(i+10+25,j-15+25,5,5);
    bar(i-20+25,j+25,i+20+25,j+20+25);
    }
void kingpat(char c,int i,int j){
    if(c=='b') setfillstyle(1,4);
    if(c=='w') setfillstyle(1,1);
    bar(i+5,j+15,i+45,j+45);
    bar(i+23,j+5,i+26,j+15);
    bar(i+20,j+8,i+29,j+11);
    }

void SetGraphic(){

    int i;
    setlinestyle(0,0,0);
    setcolor(-1);
    rookpat('b',100,100);
    rookpat('b',450,100);
    horsepat('b',150,100);
    horsepat('b',400,100);
    bishoppat('b',200,100);
    bishoppat('b',350,100);
    quinpat('b',250,100);
    kingpat('b',300,100);
    for(i=0;i<=7;i++) pawnpat('b',100+i*50,150);
    rookpat('w',100,450);
    rookpat('w',450,450);
    horsepat('w',150,450);
    horsepat('w',400,450);
    bishoppat('w',200,450);
    bishoppat('w',350,450);
    quinpat('w',250,450);
    kingpat('w',300,450);
    for(i=0;i<=7;i++) pawnpat('w',100+i*50,400);
    }


void Avaz(int o,int dstx,int dsty,int cntx,int cnty)
{


    char w='w',b='b';
	if((dstx%2==0 && dsty%2==0) || (dstx%2!=0 && dsty%2!=0))
	{

		setfillstyle(1,15);
	}
	else if((dstx%2==0 && dsty%2!=0) || (dstx%2!=0 && dsty%2==0))
	{

		setfillstyle(1,0);
	}
	bar(dstx*50+100,dsty*50+100,dstx*50+100+50,dsty*50+100+50);
	if((cntx%2==0 && cnty%2==0) || (cntx%2!=0 && cnty%2!=0))
	{

		setfillstyle(1,15);
	}
	else if((cntx%2==0 && cnty%2!=0) || (cntx%2!=0 && cnty%2==0))
	{

		setfillstyle(1,0);
	}
	bar(cntx*50+100,cnty*50+100,cntx*50+100+50,cnty*50+100+50);

	if(o==0)
	{

		if(Board[cnty][cntx]==0)
		{
			rookpat(w,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==1)
		{
			horsepat(w,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==2)
		{
			bishoppat(w,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==3)
		{
			quinpat(w,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==4)
		{
			kingpat(w,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==5)
		{
			pawnpat(w,dstx*50+100,dsty*50+100);
		}
	}

	if(o==1)
	{

		if(Board[cnty][cntx]==10)
		{
			rookpat(b,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==11)
		{
			horsepat(b,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==12)
		{
			bishoppat(b,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==13)
		{
			quinpat(b,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==14)
		{
			kingpat(b,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==15)
		{
			pawnpat(b,dstx*50+100,dsty*50+100);
		}


	}
    Reverse=Board[dsty][dstx];
	Board[dsty][dstx]=Board[cnty][cntx];
	Board[cnty][cntx]=-1;

}

void Reverse_Avaz(int o,int dstx,int dsty,int cntx,int cnty)//ye nafare
{
    char w='w',b='b';
	if((dstx%2==0 && dsty%2==0) || (dstx%2!=0 && dsty%2!=0))
	{

		setfillstyle(1,15);
	}
	else if((dstx%2==0 && dsty%2!=0) || (dstx%2!=0 && dsty%2==0))
	{

		setfillstyle(1,0);
	}
	bar(dstx*50+100,dsty*50+100,dstx*50+100+50,dsty*50+100+50);
	if((cntx%2==0 && cnty%2==0) || (cntx%2!=0 && cnty%2!=0))
	{

		setfillstyle(1,15);
	}
	else if((cntx%2==0 && cnty%2!=0) || (cntx%2!=0 && cnty%2==0))
	{

		setfillstyle(1,0);
	}
	bar(cntx*50+100,cnty*50+100,cntx*50+100+50,cnty*50+100+50);

	if(o==0)
	{

		if(Board[cnty][cntx]==0)
		{
			rookpat(w,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==1)
		{
			horsepat(w,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==2)
		{
			bishoppat(w,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==3)
		{
			quinpat(w,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==4)
		{
			kingpat(w,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==5)
		{
			pawnpat(w,dstx*50+100,dsty*50+100);
		}


		if(Reverse==10)
		{
			rookpat(b,cntx*50+100,cnty*50+100);
		}
		if(Reverse==11)
		{
			horsepat(b,cntx*50+100,cnty*50+100);
		}
		if(Reverse==12)
		{
			bishoppat(b,cntx*50+100,cnty*50+100);
		}
		if(Reverse==13)
		{
			quinpat(b,cntx*50+100,cnty*50+100);
		}
		if(Reverse==14)
		{
			kingpat(b,cntx*50+100,cnty*50+100);
		}
		if(Reverse==15)
		{
			pawnpat(b,cntx*50+100,cnty*50+100);
		}


	}
	if(o==1)
	{

		if(Board[cnty][cntx]==10)
		{
			rookpat(b,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==11)
		{
			horsepat(b,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==12)
		{
			bishoppat(b,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==13)
		{
			quinpat(b,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==14)
		{
			kingpat(b,dstx*50+100,dsty*50+100);
		}
		if(Board[cnty][cntx]==15)
		{
			pawnpat(b,dstx*50+100,dsty*50+100);
		}


		if(Reverse==0)
		{
			rookpat(w,cntx*50+100,cnty*50+100);
		}
		if(Reverse==1)
		{
			horsepat(w,cntx*50+100,cnty*50+100);
		}
		if(Reverse==2)
		{
			bishoppat(w,cntx*50+100,cnty*50+100);
		}
		if(Reverse==3)
		{
			quinpat(w,cntx*50+100,cnty*50+100);
		}
		if(Reverse==4)
		{
			kingpat(w,cntx*50+100,cnty*50+100);
		}
		if(Reverse==5)
		{
			pawnpat(w,cntx*50+100,cnty*50+100);
		}


	}

	Board[dsty][dstx]=Board[cnty][cntx];
    Board[cnty][cntx]=Reverse;





}








	int main()
{
	int i=0,j=0,P,TYPE1,Numb,cntx,cnty,dstx,dsty;
	int AS,AD,AE,SH=1;
	int iiii,ii,iii,jj,jjj,kk,kkk,kkkk,jjjj;
	int p,q,k,o;
    int counter=0,X,Y;
    int color,l,temp,Decide,pattern,colour;
    printf("Choose Game Mode\n");
    printf("One player : Press 1\n");
    printf("Two player : Press 2\n");
    scanf("%d",&Decide);
    printf("choose your background color\n");
    printf("enter a number from 1 to 14\n");
    scanf("%d",&color);
    printf("choose your background pattern\n");
    printf("enter a number from 1 to 11\n");
    scanf("%d",&pattern);

        initwindow(800,600);
        setfillstyle(pattern,color);
        bar(0,0,800,600);
        setcolor(9);
        settextstyle(1,0,20);
        outtextxy(70,110,"1");
        outtextxy(70,160,"2");
        outtextxy(70,210,"3");
        outtextxy(70,260,"4");
        outtextxy(70,310,"5");
        outtextxy(70,360,"6");
        outtextxy(70,410,"7");
        outtextxy(70,460,"8");
        outtextxy(120,510,"a");
        outtextxy(170,510,"b");
        outtextxy(220,510,"c");
        outtextxy(270,510,"d");
        outtextxy(320,510,"e");
        outtextxy(370,510,"f");
        outtextxy(420,510,"g");
        outtextxy(470,510,"h");
        setcolor(14);
        settextstyle(1,0,26);
        outtextxy(163,30,"Chess Elephant");
        setcolor(14);
        settextstyle(9,0,1);
        outtextxy(10,578,"[A]trin *** Elahe");
        outtextxy(600,150,"single player");
        outtextxy(600,100,"double player");
        setfillstyle(1,0);
        bar(750,570,790,590);
        outtextxy(750,570,"Exit");



//safe shatranj
    for(i=0,l=0,P=15,k=0;k<8;i+=2)
    {
        setfillstyle(1,P);
        bar(100+50*i,100+50*k,100+50*(i+1),100+50*(k+1));
        setfillstyle(1,l);
        bar(100+50*(i+1),100+50*k,100+50*(i+2),100+50*(k+1));
        if(i%6==0 && i!=0)
      {
        k++;
        i=-2;
        temp=l;
        l=P;
        P=temp;
      }
    }

    Set();
    SetGraphic();
    update();

    //bazi yenafare
 if(Decide==1)
    {
        setfillstyle(1,14);
        fillellipse(570,160,10,10);
        Set();
        SetGraphic();
        update();
	while (1)
{
	Start:
	if(Tah==1)
	break;
    //board
    for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			printf("%2d  ",Board[i][j]);
		}
		printf("\n");
	}



        AGAIN:
        getch();
		if(ismouseclick(WM_LBUTTONDOWN) )
        {
       	 	X=mousex();
        	Y=mousey();
        	if( X >750 && X<790 && Y > 570 && Y <590 )
                    goto exit;
        	if( X>=500 || X<100 || Y>=500 || Y<100)
                goto AGAIN;

        clearmouseclick(WM_LBUTTONDOWN);
        }

        if(counter!=0)
        {
            dstx=X;
            dsty=Y;
            dstx=(dstx-100)/50;
        	dsty=(dsty-100)/50;

        }
        if(counter==0)
        {
            cntx=X;
            cnty=Y;
            cntx=(cntx-100)/50;
        	cnty=(cnty-100)/50;
        	counter++;

        	goto AGAIN;
        }
        counter=0;


        if(Board[dsty][dstx]==14 )
            goto AGAIN;

	typedef struct Turns{

	int cntx;
	int cnty;
	int dstx;
	int dsty;
	char checkmate;
	char piece;
	char iscatch;
	}Turn;
	Turn White;
	if(Board[cnty][cntx]==0){
							White.piece='R';
							TYPE1=0;
							}
	if(Board[cnty][cntx]==1)
	{
							White.piece='N';
							TYPE1=1;
							}
	if(Board[cnty][cntx]==2)
	{
							White.piece='B';
							TYPE1=2;
							}
	if(Board[cnty][cntx]==3)
	{
							White.piece='Q';
							TYPE1=3;
							}
	if(Board[cnty][cntx]==4)
	{
							White.piece='K';
							TYPE1=4;
							}
	if(Board[cnty][cntx]==5)
	{
							White.piece='S';
							TYPE1=5;
							}
	White.cntx=cntx;
	White.cnty=cnty;
	White.dstx=dstx;
	White.dsty=dsty;

	if(Board[dsty][dstx]>=10)
	White.iscatch='x';
	else if (Board[dsty][dstx]==-1)
	White.iscatch='-';
	for(o=0;o<2;o++)
	{


	switch (o)
	{

		case 0:
        A=0;

            if(Board[White.cnty][White.cntx]!=(10*o)+TYPE1 )
		{


					o++;
					goto Start;
		}


	switch (White.piece)
	{

		case 'R':

			if(ValidP(White.cntx,White.cnty,0,White.dstx,White.dsty)==0 ||  (White.iscatch=='-' && Board[White.dsty][White.dstx]!=-1))
			{
			o++;
			goto end;
			}
			else
			{

				Avaz(o,White.dstx,White.dsty,White.cntx,White.cnty);
				update();
                if(IsCheckWhite()==1)
                {



                    Reverse_Avaz(o,White.cntx,White.cnty,White.dstx,White.dsty);
                    o++;
                    goto end;
                }
				if(ValidP(White.dstx,White.dsty,0,ValidPathBlack[7][0][0],ValidPathBlack[7][0][1])==1 )
				{
                 A=1;

				for(iiii=0;iiii<16;iiii++)
				{
					for(ii=1;ii<9;ii++)
					{
						for(iii=0;iii<16;iii+=2)
						{
							if(ValidPathBlack[iiii][ii][iii]==White.dstx && ValidPathBlack[iiii][ii][iii+1]==White.dsty) //zadane mohre kish dahande
							ScoreI[iiii][ii][iii]=100;
						}
					}
				}
							if(White.dstx==ValidPathWhite[0][0][0] && White.dsty==ValidPathWhite[0][0][1]) //kodom rokhe?
							{
								for(jj=1;jj<9;jj++)
								{
									for(jjj=0;jjj<16;jjj+=2)
									{

										if(ValidPathBlack[7][0][0]==ValidPathWhite[0][jj][jjj] && ValidPathBlack[7][0][1]==ValidPathWhite[0][jj][jjj+1] )
										{
										    for(jjjj=0;jjjj<jjj;jjjj+=2)
                                            {


											for(kk=0;kk<16;kk++)
											{

											     if(kk==7)
                                                        {
                                                                      for(kkk=1;kkk<9;kkk++)
												{
												    SH=0;

                                                            for(AS=0;AS<16;AS++)
                                                            {
                                                                for(AD=1;AD<9;AD++)
                                                                {
                                                                    for(AE=0;AE<16;AE+=2)
                                                                    {
                                                                        if(ValidPathBlack[7][kkk][0]!=ValidPathWhite[AS][AD][AE] || ValidPathBlack[7][kkk][1]!=ValidPathWhite[AS][AD][AE+1])
                                                                            SH++;
                                                                    }
                                                                }

                                                            }
                                                            if(SH==1024)
                                                            ScoreI[7][kkk][0]=100;
												}

                                                        }
                                                        else if(kk!=7)
                                                        {


												for(kkk=1;kkk<9;kkk++)
												{

													for(kkkk=0;kkkk<16;kkkk+=2)
                                                        {

														if(ValidPathBlack[kk][kkk][kkkk]==ValidPathWhite[0][jj][jjjj] && ValidPathBlack[kk][kkk][kkkk+1]==ValidPathWhite[0][jj][jjjj+1])
														ScoreI[kk][kkk][kkkk]=100;


                                                        }
                                                    }
                                                        }
                                                }
                                            }
                                  break;}
									}

            }
							}

							else if(White.dstx==ValidPathWhite[1][0][0] && White.dsty==ValidPathWhite[1][0][1]) //on yeki rokhe
							{
								for(jj=1;jj<9;jj++)
								{
									for(jjj=0;jjj<16;jjj+=2)
									{
										if(ValidPathBlack[7][0][0]==ValidPathWhite[1][jj][jjj] && ValidPathBlack[7][0][1]==ValidPathWhite[1][jj][jjj+1] )
										{
										    for(jjjj=0;jjjj<jjj;jjjj+=2)
                                            {


											for(kk=0;kk<16;kk++)
											{

											     if(kk==7)
                                                        {
                                                                      for(kkk=1;kkk<9;kkk++)
                                                            {
                                                                SH=0;

                                                            for(AS=0;AS<16;AS++)
                                                            {
                                                                for(AD=1;AD<9;AD++)
                                                                {
                                                                    for(AE=0;AE<16;AE+=2)
                                                                    {
                                                                        if(ValidPathBlack[7][kkk][0]!=ValidPathWhite[AS][AD][AE] || ValidPathBlack[7][kkk][1]!=ValidPathWhite[AS][AD][AE+1])
                                                                            SH++;
                                                                    }
                                                                }

                                                            }
                                                            if(SH==1024)
                                                            ScoreI[7][kkk][0]=100;
                                                            }

                                                        }
                                                        else if(kk!=7)
                                                        {


												for(kkk=1;kkk<9;kkk++)
												{

													for(kkkk=0;kkkk<16;kkkk+=2)
                                                        {

														if(ValidPathBlack[kk][kkk][kkkk]==ValidPathWhite[1][jj][jjjj] && ValidPathBlack[kk][kkk][kkkk+1]==ValidPathWhite[1][jj][jjjj+1])
														ScoreI[kk][kkk][kkkk]=100;


                                                        }
                                                    }
                                                        }
                                                }
                                            }
                                    break;}
									}
								}

							}




			}
			}
			break;
		case 'N':
			if(ValidP(White.cntx,White.cnty,1,White.dstx,White.dsty)==0 ||  (White.iscatch=='-' && Board[White.dsty][White.dstx]!=-1) )
				{

						o++;
					goto end;
				}
			else
			{

				Avaz(o,White.dstx,White.dsty,White.cntx,White.cnty);

				update();
				if(IsCheckWhite()==1)
                {


                    Reverse_Avaz(o,White.cntx,White.cnty,White.dstx,White.dsty);
                    o++;
                    goto end;
                }

				if(ValidP(White.dstx,White.dsty,1,ValidPathBlack[7][0][0],ValidPathBlack[7][0][1])==1 )
				{
                A=1;

				for(iiii=0;iiii<16;iiii++)
				{
					for(ii=1;ii<9;ii++)
					{
						for(iii=0;iii<16;iii+=2)
						{
							if(ValidPathBlack[iiii][ii][iii]==White.dstx && ValidPathBlack[iiii][ii][iii+1]==White.dsty)
							ScoreI[iiii][ii][iii]=100;
						}
					}
				}
							if(White.dstx==ValidPathWhite[2][0][0] && White.dsty==ValidPathWhite[2][0][1])
							{
								for(jj=1;jj<9;jj++)
								{


										if(ValidPathBlack[7][0][0]==ValidPathWhite[2][jj][0] && ValidPathBlack[7][0][1]==ValidPathWhite[2][jj][1] )
										{



                                                            for(kkk=1;kkk<9;kkk++)
                                                            {

												    SH=0;

                                                            for(AS=0;AS<16;AS++)
                                                            {
                                                                for(AD=1;AD<9;AD++)
                                                                {
                                                                    for(AE=0;AE<16;AE+=2)
                                                                    {
                                                                        if(ValidPathBlack[7][kkk][0]!=ValidPathWhite[AS][AD][AE] || ValidPathBlack[7][kkk][1]!=ValidPathWhite[AS][AD][AE+1])
                                                                            SH++;
                                                                    }
                                                                }

                                                            }


                                                            if(SH==1024)
                                                            ScoreI[7][kkk][0]=100;
												}





										break;
										}

								}


							}
							else if(White.dstx==ValidPathWhite[3][0][0] && White.dsty==ValidPathWhite[3][0][1])
							{
								for(jj=1;jj<9;jj++)
								{


										if(ValidPathBlack[7][0][0]==ValidPathWhite[3][jj][0] && ValidPathBlack[7][0][1]==ValidPathWhite[3][jj][1] )
										{




                                                        for(kkk=1;kkk<9;kkk++)
                                                    {
                                                        SH=0;
                                        for(AS=0;AS<16;AS++)
                                            {
                                        for(AD=1;AD<9;AD++)
                                                {
                                        for(AE=0;AE<16;AE+=2)
                                                {
                                            if(ValidPathBlack[7][kkk][0]!=ValidPathWhite[AS][AD][AE] || ValidPathBlack[7][kkk][1]!=ValidPathWhite[AS][AD][AE+1])
                                                    SH++;
                                            }
                                                }

                                        }

                                            if(SH==1024)
                                            ScoreI[7][kkk][0]=100;
                                                }




										break;
										}

								}

							}









				}


			}
			break;
		case 'B':
			if(ValidP(White.cntx,White.cnty,2,White.dstx,White.dsty)==0 ||  (White.iscatch=='-' && Board[White.dsty][White.dstx]!=-1))
			{


				o++;
			goto end;
			}

			else
			{

				Avaz(o,White.dstx,White.dsty,White.cntx,White.cnty);

				update();
                if(IsCheckWhite()==1)
                {


                    Reverse_Avaz(o,White.cntx,White.cnty,White.dstx,White.dsty);
                    o++;
                    goto end;
                }

				if(ValidP(White.dstx,White.dsty,2,ValidPathBlack[7][0][0],ValidPathBlack[7][0][1])!=0 )
				{
                    A=1;

				for(iiii=0;iiii<16;iiii++)
				{
					for(ii=1;ii<9;ii++)
					{
						for(iii=0;iii<16;iii+=2)
						{
							if(ValidPathBlack[iiii][ii][iii]==White.dstx && ValidPathBlack[iiii][ii][iii+1]==White.dsty)
							ScoreI[iiii][ii][iii]=100;
						}
					}
				}
							if(White.dstx==ValidPathWhite[4][0][0] && White.dsty==ValidPathWhite[4][0][1])
							{
								for(jj=1;jj<9;jj++)
								{
									for(jjj=0;jjj<16;jjj+=2)
									{
										if(ValidPathBlack[7][0][0]==ValidPathWhite[4][jj][jjj] && ValidPathBlack[7][0][1]==ValidPathWhite[4][jj][jjj+1] )
										{
										    for(jjjj=0;jjjj<jjj;jjjj+=2)
                                            {


											for(kk=0;kk<16;kk++)
											{

											     if(kk==7)
                                                        {
                                                            for(kkk=1;kkk<9;kkk++)
                                                            {
                                                            SH=0;
                                                            for(AS=0;AS<16;AS++)
                                                            {
                                                                for(AD=1;AD<9;AD++)
                                                                {
                                                                    for(AE=0;AE<16;AE+=2)
                                                                    {
                                                                        if(ValidPathBlack[7][kkk][0]!=ValidPathWhite[AS][AD][AE] || ValidPathBlack[7][kkk][1]!=ValidPathWhite[AS][AD][AE+1])
                                                                            SH++;
                                                                    }
                                                                }

                                                            }

                                                            if(SH==1024)
                                                            ScoreI[7][kkk][0]=100;
                                                            }

                                                        }
                                                        else if(kk!=7)
                                                        {


												for(kkk=1;kkk<9;kkk++)
												{

													for(kkkk=0;kkkk<16;kkkk+=2)
                                                        {

														if(ValidPathBlack[kk][kkk][kkkk]==ValidPathWhite[4][jj][jjjj] && ValidPathBlack[kk][kkk][kkkk+1]==ValidPathWhite[4][jj][jjjj+1])
														ScoreI[kk][kkk][kkkk]=100;


                                                        }
                                                    }
                                                        }
                                                }
                                            }
										break;}
									}
								}


            	}
							else if(White.dstx==ValidPathWhite[5][0][0] && White.dsty==ValidPathWhite[5][0][1])
							{
								for(jj=1;jj<9;jj++)
								{
									for(jjj=0;jjj<16;jjj+=2)
									{
										if(ValidPathBlack[7][0][0]==ValidPathWhite[5][jj][jjj] && ValidPathBlack[7][0][1]==ValidPathWhite[5][jj][jjj+1] )
										{
										    for(jjjj=0;jjjj<jjj;jjjj+=2)
                                            {


											for(kk=0;kk<16;kk++)
											{

											     if(kk==7)
                                                        {
                                                                      for(kkk=1;kkk<9;kkk++)
												{SH=0;

                                                            for(AS=0;AS<16;AS++)
                                                            {
                                                                for(AD=1;AD<9;AD++)
                                                                {
                                                                    for(AE=0;AE<16;AE+=2)
                                                                    {
                                                                        if(ValidPathBlack[7][kkk][0]!=ValidPathWhite[AS][AD][AE] || ValidPathBlack[7][kkk][1]!=ValidPathWhite[AS][AD][AE+1])
                                                                            SH++;
                                                                    }
                                                                }

                                                            }
                                                            if(SH==1024)
                                                            ScoreI[7][kkk][0]=100;
												}

                                                        }
                                                        else if(kk!=7)
                                                        {


												for(kkk=1;kkk<9;kkk++)
												{

													for(kkkk=0;kkkk<16;kkkk+=2)
                                                        {

														if(ValidPathBlack[kk][kkk][kkkk]==ValidPathWhite[5][jj][jjjj] && ValidPathBlack[kk][kkk][kkkk+1]==ValidPathWhite[5][jj][jjjj+1])
														ScoreI[kk][kkk][kkkk]=100;


                                                        }
                                                    }
                                                        }
                                                }
                                            }
										break;}
									}
								}


						}





				}

			}
			break;
		case 'Q':
				if(ValidP(White.cntx,White.cnty,3,White.dstx,White.dsty)==0 ||  (White.iscatch=='-' && Board[White.dsty][White.dstx]!=-1))
				{


						o++;
					goto end;
				}
			else
			{

				Avaz(o,White.dstx,White.dsty,White.cntx,White.cnty);

				update();
                if(IsCheckWhite()==1)
                {


                    Reverse_Avaz(o,White.cntx,White.cnty,White.dstx,White.dsty);
                    o++;
                    goto end;
                }
				if(ValidP(White.dstx,White.dsty,3,ValidPathBlack[7][0][0],ValidPathBlack[7][0][1])!=0 )
				{
				    A=1;


				for(iiii=0;iiii<16;iiii++)
				{
					for(ii=1;ii<9;ii++)
					{
						for(iii=0;iii<16;iii+=2)
						{

							if(ValidPathBlack[iiii][ii][iii]==White.dstx && ValidPathBlack[iiii][ii][iii+1]==White.dsty && iiii!=7)
							{

							ScoreI[iiii][ii][iii]=100;
							}
                        }
                    }
                }

								for(jj=1;jj<9;jj++)
								{
									for(jjj=0;jjj<16;jjj+=2)
									{
									    if(ValidPathBlack[7][0][0]==ValidPathWhite[6][jj][jjj] && ValidPathBlack[7][0][1]==ValidPathWhite[6][jj][jjj+1] )
										{

                                       for(jjjj=0;jjjj<jjj;jjjj+=2)
                                        {
											for(kk=0;kk<16;kk++)
											{
												for(kkk=1;kkk<9;kkk++)
												{
												    SH=0;
												     if(kk==7)
                                                        {

                                                            for(AS=0;AS<16;AS++)
                                                            {
                                                                for(AD=1;AD<9;AD++)
                                                                {
                                                                    for(AE=0;AE<16;AE+=2)
                                                                    {
                                                                        if(ValidPathBlack[7][kkk][0]!=-2 && ValidPathBlack[7][kkk][1]!=-2)
                                                                        {


                                                                        if(ValidPathBlack[7][kkk][0]!=ValidPathWhite[AS][AD][AE] || ValidPathBlack[7][kkk][1]!=ValidPathWhite[AS][AD][AE+1])
                                                                            SH++;
                                                                         }
                                                                    }
                                                                }

                                                            }

                                                            if(SH==1024)
                                                            {


                                                            ScoreI[7][kkk][0]=100;
                                                            }

                                                        }
                                                        else if(kk!=7)
                                                        {


													for(kkkk=0;kkkk<16;kkkk+=2)
                                                        {


														if(ValidPathBlack[kk][kkk][kkkk]==ValidPathWhite[6][jj][jjjj] && ValidPathBlack[kk][kkk][kkkk+1]==ValidPathWhite[6][jj][jjjj+1] )
														ScoreI[kk][kkk][kkkk]=100;



                                                        }
                                                    }
												}
											}
										}
										break;}

									}

							}





				}

			}
			break;
		case 'K':
			if(ValidP(White.cntx,White.cnty,4,White.dstx,White.dsty)==0 ||  (White.iscatch=='-' && Board[White.dsty][White.dstx]!=-1))
			{


						o++;
					goto end;
			}

			Avaz(o,White.dstx,White.dsty,White.cntx,White.cnty);
				update();
				if(IsCheckWhite()==1)
                {
                    Reverse_Avaz(o,White.cntx,White.cnty,White.dstx,White.dsty);
                    o++;
                    goto end;
                }
			break;





		case 'S':
		if(ValidP(White.cntx,White.cnty,5,White.dstx,White.dsty)==0 )
			{


						o++;
					goto end;
				}
			else
			{

				Avaz(o,White.dstx,White.dsty,White.cntx,White.cnty);

				update();
                if(IsCheckWhite()==1)
                {


                    Reverse_Avaz(o,White.cntx,White.cnty,White.dstx,White.dsty);
                    o++;
                    goto end;
                }



				if(Board[White.dsty-1][White.dstx+1]==14 || Board[White.dsty-1][White.dstx-1]==14 )
				{
                A=1;

				for(iiii=0;iiii<16;iiii++)
				{
					for(ii=1;ii<9;ii++)
					{
						for(iii=0;iii<16;iii+=2)
						{
							if(ValidPathBlack[iiii][ii][iii]==White.dstx && ValidPathBlack[iiii][ii][iii+1]==White.dsty)
							ScoreI[iiii][ii][iii]=100;
						}
					}
				}

							if(White.dstx==ValidPathWhite[8][0][0] && White.dsty==ValidPathWhite[8][0][1])
							{
								for(jj=1;jj<3;jj++)
								{


										if(ValidPathBlack[7][0][0]==ValidPathWhite[8][jj][0] && ValidPathBlack[7][0][1]==ValidPathWhite[8][jj][1] )
										{

                                                for(kkk=1;kkk<9;kkk++)
												{
												    SH=0;

                                                            for(AS=0;AS<16;AS++)
                                                            {
                                                                for(AD=1;AD<9;AD++)
                                                                {
                                                                    for(AE=0;AE<16;AE+=2)
                                                                    {
                                                                        if(ValidPathBlack[7][kkk][0]!=ValidPathWhite[AS][AD][AE] || ValidPathBlack[7][kkk][1]!=ValidPathWhite[AS][AD][AE+1])
                                                                            SH++;
                                                                    }
                                                                }

                                                            }
                                                            if(SH==1024)
                                                            ScoreI[7][kkk][0]=100;
												}



                                            }
										}
									}




                                    	if(White.dstx==ValidPathWhite[9][0][0] && White.dsty==ValidPathWhite[9][0][1])
							{
								for(jj=1;jj<3;jj++)
								{


										if(ValidPathBlack[7][0][0]==ValidPathWhite[9][jj][0] && ValidPathBlack[7][0][1]==ValidPathWhite[9][jj][1] )
										{

                                                for(kkk=1;kkk<9;kkk++)
												{
												    SH=0;

                                                            for(AS=0;AS<16;AS++)
                                                            {
                                                                for(AD=1;AD<9;AD++)
                                                                {
                                                                    for(AE=0;AE<16;AE+=2)
                                                                    {
                                                                        if(ValidPathBlack[7][kkk][0]!=ValidPathWhite[AS][AD][AE] || ValidPathBlack[7][kkk][1]!=ValidPathWhite[AS][AD][AE+1])
                                                                            SH++;
                                                                    }
                                                                }

                                                            }
                                                            if(SH==1024)
                                                            ScoreI[7][kkk][0]=100;
												}



                                            }
										}
									}


                                            	if(White.dstx==ValidPathWhite[10][0][0] && White.dsty==ValidPathWhite[10][0][1])
							{
								for(jj=1;jj<3;jj++)
								{


										if(ValidPathBlack[7][0][0]==ValidPathWhite[10][jj][0] && ValidPathBlack[7][0][1]==ValidPathWhite[10][jj][1] )
										{

                                                for(kkk=1;kkk<9;kkk++)
												{
												    SH=0;

                                                            for(AS=0;AS<16;AS++)
                                                            {
                                                                for(AD=1;AD<9;AD++)
                                                                {
                                                                    for(AE=0;AE<16;AE+=2)
                                                                    {
                                                                        if(ValidPathBlack[7][kkk][0]!=ValidPathWhite[AS][AD][AE] || ValidPathBlack[7][kkk][1]!=ValidPathWhite[AS][AD][AE+1])
                                                                            SH++;
                                                                    }
                                                                }

                                                            }
                                                            if(SH==1024)
                                                            ScoreI[7][kkk][0]=100;
												}



                                            }
										}
									}


									if(White.dstx==ValidPathWhite[11][0][0] && White.dsty==ValidPathWhite[11][0][1])
							{
								for(jj=1;jj<3;jj++)
								{


										if(ValidPathBlack[7][0][0]==ValidPathWhite[11][jj][0] && ValidPathBlack[7][0][1]==ValidPathWhite[11][jj][1] )
										{

                                                for(kkk=1;kkk<9;kkk++)
												{
												    SH=0;

                                                            for(AS=0;AS<16;AS++)
                                                            {
                                                                for(AD=1;AD<9;AD++)
                                                                {
                                                                    for(AE=0;AE<16;AE+=2)
                                                                    {
                                                                        if(ValidPathBlack[7][kkk][0]!=ValidPathWhite[AS][AD][AE] || ValidPathBlack[7][kkk][1]!=ValidPathWhite[AS][AD][AE+1])
                                                                            SH++;
                                                                    }
                                                                }

                                                            }
                                                            if(SH==1024)
                                                            ScoreI[7][kkk][0]=100;
												}



                                            }
										}
									}


                                    	if(White.dstx==ValidPathWhite[12][0][0] && White.dsty==ValidPathWhite[12][0][1])
							{
								for(jj=1;jj<3;jj++)
								{


										if(ValidPathBlack[7][0][0]==ValidPathWhite[12][jj][0] && ValidPathBlack[7][0][1]==ValidPathWhite[12][jj][1] )
										{

                                                for(kkk=1;kkk<9;kkk++)
												{
												    SH=0;

                                                            for(AS=0;AS<16;AS++)
                                                            {
                                                                for(AD=1;AD<9;AD++)
                                                                {
                                                                    for(AE=0;AE<16;AE+=2)
                                                                    {
                                                                        if(ValidPathBlack[7][kkk][0]!=ValidPathWhite[AS][AD][AE] || ValidPathBlack[7][kkk][1]!=ValidPathWhite[AS][AD][AE+1])
                                                                            SH++;
                                                                    }
                                                                }

                                                            }
                                                            if(SH==1024)
                                                            ScoreI[7][kkk][0]=100;
												}



                                            }
										}
									}


                        	if(White.dstx==ValidPathWhite[13][0][0] && White.dsty==ValidPathWhite[13][0][1])
							{
								for(jj=1;jj<3;jj++)
								{


										if(ValidPathBlack[7][0][0]==ValidPathWhite[13][jj][0] && ValidPathBlack[7][0][1]==ValidPathWhite[13][jj][1] )
										{

                                                for(kkk=1;kkk<9;kkk++)
												{
												    SH=0;

                                                            for(AS=0;AS<16;AS++)
                                                            {
                                                                for(AD=1;AD<9;AD++)
                                                                {
                                                                    for(AE=0;AE<16;AE+=2)
                                                                    {
                                                                        if(ValidPathBlack[7][kkk][0]!=ValidPathWhite[AS][AD][AE] || ValidPathBlack[7][kkk][1]!=ValidPathWhite[AS][AD][AE+1])
                                                                            SH++;
                                                                    }
                                                                }

                                                            }
                                                            if(SH==1024)
                                                            ScoreI[7][kkk][0]=100;
												}



                                            }
										}
									}



                                        	if(White.dstx==ValidPathWhite[14][0][0] && White.dsty==ValidPathWhite[14][0][1])
							{
								for(jj=1;jj<3;jj++)
								{


										if(ValidPathBlack[7][0][0]==ValidPathWhite[14][jj][0] && ValidPathBlack[7][0][1]==ValidPathWhite[14][jj][1] )
										{

                                                for(kkk=1;kkk<9;kkk++)
												{
												    SH=0;

                                                            for(AS=0;AS<16;AS++)
                                                            {
                                                                for(AD=1;AD<9;AD++)
                                                                {
                                                                    for(AE=0;AE<16;AE+=2)
                                                                    {
                                                                        if(ValidPathBlack[7][kkk][0]!=ValidPathWhite[AS][AD][AE] || ValidPathBlack[7][kkk][1]!=ValidPathWhite[AS][AD][AE+1])
                                                                            SH++;
                                                                    }
                                                                }

                                                            }
                                                            if(SH==1024)
                                                            ScoreI[7][kkk][0]=100;
												}



                                            }
										}
									}

									if(White.dstx==ValidPathWhite[15][0][0] && White.dsty==ValidPathWhite[15][0][1])
							{
								for(jj=1;jj<3;jj++)
								{


										if(ValidPathBlack[7][0][0]==ValidPathWhite[15][jj][0] && ValidPathBlack[7][0][1]==ValidPathWhite[15][jj][1] )
										{

                                                for(kkk=1;kkk<9;kkk++)
												{
												    SH=0;

                                                            for(AS=0;AS<16;AS++)
                                                            {
                                                                for(AD=1;AD<9;AD++)
                                                                {
                                                                    for(AE=0;AE<16;AE+=2)
                                                                    {
                                                                        if(ValidPathBlack[7][kkk][0]!=ValidPathWhite[AS][AD][AE] || ValidPathBlack[7][kkk][1]!=ValidPathWhite[AS][AD][AE+1])
                                                                            SH++;
                                                                    }
                                                                }

                                                            }
                                                            if(SH==1024)
                                                            ScoreI[7][kkk][0]=100;
												}



                                            }
										}
									}







				}
				}
	}
	break;

		case 1:

			SCORE();
			MaxScore();
            if(Elephant==0)
                {
			Avaz(1,ValidPathBlack[Maximum[0]][Maximum[1]][Maximum[2]],ValidPathBlack[Maximum[0]][Maximum[1]][Maximum[2]+1],ValidPathBlack[Maximum[0]][0][0],ValidPathBlack[Maximum[0]][0][1]);
    			update();
                }






	}
	end:
            if(Elephant==1)
                Tah=1;
}
}
                    initwindow(500,300,"Checkmate",300,200);
                    setfillstyle(1,0);
                    bar(0,0,500,500);
                    setcolor(4);
                    settextstyle(4,3,5);
                    outtextxy(230,100,":)");
                    settextstyle(1,0,3);
                    outtextxy(360,150,"Game Over!!!");

}

//BAZI DONAFARE
else  if(Decide==2)
    {
            setfillstyle(1,14);
            fillellipse(570,110,10,10);
            Set();
            SetGraphic();
            update();

		//graphic
        setcolor(14);
        settextstyle(9,0,1);
        outtextxy(630,290,"Turn");

	while (1)
{

    //checkmate
    start:



	for(o=0;o<2;o++)
	{


	     if(IsCheckBlack()==1)
            {

         if(IsCheckMateWhite() == 1 )
         {
             colour=1;
             goto End;
         }
            }
            if(IsCheckWhite()==1)
            {

         if(IsCheckMateBlack() == 1 )
         {
             colour=4;
              goto End;

         }
            }
 		//TURN
	    if(o==0)
        {
            setfillstyle(1,1);
            fillellipse(700,300,10,10);
        }
        else  if(o==1)
        {
            setfillstyle(1,4);
            fillellipse(700,300,10,10);
        }


	    int X,Y,cntx,cnty,dstx,dsty;
	 //is mouseclick
        again:
        getch();
		if(ismouseclick(WM_LBUTTONDOWN) )
        {
       	 	X=mousex();
        	Y=mousey();
        	 if( X >750 && X<790 && Y > 570 && Y <590 )
                    goto exit;
        	if( X>=500 || X<100 || Y>=500 || Y<100)//birone safe click kone
                goto again;


        clearmouseclick(WM_LBUTTONDOWN);
        }

        if(counter!=0)
        {
            dstx=X;
            dsty=Y;
            dstx=(dstx-100)/50;
        	dsty=(dsty-100)/50;

        }
        if(counter==0)
        {
            cntx=X;
            cnty=Y;
            cntx=(cntx-100)/50;
        	cnty=(cnty-100)/50;
        	counter++;

        	goto again;
        }

        counter=0;


        if(Board[dsty][dstx]==14 || Board[dsty][dstx]==4)
            goto again;

	typedef struct Turns{

	int cntx;
	int cnty;
	int dstx;
	int dsty;
	char piece;
	char iscatch;
	}Turn;
	Turn White;
	Turn Black;

	if(o==0)
        {
	if(Board[cnty][cntx]==0){
							White.piece='R';
							TYPE1=0;
							}
	if(Board[cnty][cntx]==1)
							{
							White.piece='N';
							TYPE1=1;
							}
	if(Board[cnty][cntx]==2)
							{
							White.piece='B';
							TYPE1=2;
							}
	if(Board[cnty][cntx]==3)
							{
							White.piece='Q';
							TYPE1=3;
							}
	if(Board[cnty][cntx]==4)
							{
							White.piece='K';
							TYPE1=4;
							}
	if(Board[cnty][cntx]==5)
							{
							White.piece='S';
							TYPE1=5;
							}
	White.cntx=cntx;

	White.cnty=cnty;

	White.dstx=dstx;

	White.dsty=dsty;

	if(Board[dsty][dstx]>=10)//hamle
	White.iscatch='x';
	else if (Board[dsty][dstx]==-1)//harekate khali
	White.iscatch='-';


	if(Board[White.cnty][White.cntx]>=10 )
		{
                    o++;
					goto End;
		}


	switch (White.piece)
	{
		case 'R':

			if(ValidP(White.cntx,White.cnty,0,White.dstx,White.dsty)==0  ||  (White.iscatch=='-' && Board[White.dsty][White.dstx]!=-1) || (White.iscatch=='x' && Board[White.dsty][White.dstx]<10))
			{
			o++;
			goto End;
			}
			else
			{
					Avaz(o,White.dstx,White.dsty,White.cntx,White.cnty);
					update();
				 if(IsCheckWhite()==1)
                {

                    Reverse_Avaz(o,White.cntx,White.cnty,White.dstx,White.dsty);
                    o++;
                    goto End;

                }

			}
			break;

		case 'N':
			if(ValidP(White.cntx,White.cnty,1,White.dstx,White.dsty)==0 ||  (White.iscatch=='-' && Board[White.dsty][White.dstx]!=-1) || (White.iscatch=='x' && Board[White.dsty][White.dstx]<10) )
				{
						o++;
					goto End;
				}
			else
			{
				Avaz(o,White.dstx,White.dsty,White.cntx,White.cnty);
				update();
				 if(IsCheckWhite()==1)
                {

                    Reverse_Avaz(o,White.cntx,White.cnty,White.dstx,White.dsty);
                    o++;
                    goto End;

                }

			}

			break;
		case 'B':
			if(ValidP(White.cntx,White.cnty,2,White.dstx,White.dsty)==0 ||  (White.iscatch=='-' && Board[White.dsty][White.dstx]!=-1) || (White.iscatch=='x' && Board[White.dsty][White.dstx]<10))
			{

				o++;
			goto End;
			}

			else
			{
				Avaz(o,White.dstx,White.dsty,White.cntx,White.cnty);

				update();
				 if(IsCheckWhite()==1)
                {

                    Reverse_Avaz(o,White.cntx,White.cnty,White.dstx,White.dsty);
                    o++;
                    goto End;

                }
			}
			break;

		case 'Q':
				if(ValidP(White.cntx,White.cnty,3,White.dstx,White.dsty)==0 ||  (White.iscatch=='-' && Board[White.dsty][White.dstx]!=-1) || (White.iscatch=='x' && Board[White.dsty][White.dstx]<10))
				{
						o++;
					goto End;
				}
			else
			{
				Avaz(o,White.dstx,White.dsty,White.cntx,White.cnty);

				update();
				 if(IsCheckWhite()==1)
                {

                    Reverse_Avaz(o,White.cntx,White.cnty,White.dstx,White.dsty);
                    o++;
                    goto End;

                }
			}
			break;

		case 'K':
			if(ValidP(White.cntx,White.cnty,4,White.dstx,White.dsty)==0 ||  (White.iscatch=='-' && Board[White.dsty][White.dstx]!=-1) || (White.iscatch=='x' && Board[White.dsty][White.dstx]<10))
			{
						o++;
					goto End;
			}
			Avaz(o,White.dstx,White.dsty,White.cntx,White.cnty);
				update();
				 if(IsCheckWhite()==1)
                {

                    Reverse_Avaz(o,White.cntx,White.cnty,White.dstx,White.dsty);
                    o++;
                    goto End;

                }
			break;

		case 'S':
			if(ValidP(White.cntx,White.cnty,5,White.dstx,White.dsty)==0 || (White.iscatch=='x' && Board[White.dsty][White.dstx]<10) || (White.iscatch=='-' && Board[White.dsty][White.dstx]!=-1) )
			{

						o++;
					goto End;
				}
			else
			{

				Avaz(o,White.dstx,White.dsty,White.cntx,White.cnty);

				update();
                if(IsCheckWhite()==1)
                {



                    Reverse_Avaz(o,White.cntx,White.cnty,White.dstx,White.dsty);
                    o++;
                    goto End;
                }


           }
           break;
	}

        }


        else if(o==1)
        {

            if(Board[cnty][cntx]==10)
								{
                      			Black.piece='R';

								}
	if(Board[cnty][cntx]==11)
								{
								Black.piece='N';

								}
	if(Board[cnty][cntx]==12)
								{
								Black.piece='B';

								}
	if(Board[cnty][cntx]==13)
								{
								Black.piece='Q';

								}
	if(Board[cnty][cntx]==14)
								{
								Black.piece='K';

								}
	if(Board[cnty][cntx]==15)
								{
								Black.piece='S';

								}
	Black.cntx=cntx;
    Black.cnty=cnty;
	Black.dstx=dstx;
	Black.dsty=dsty;

	if(Board[dsty][dstx]<10 && Board[dsty][dstx]!=-1)//hamle
	Black.iscatch='x';
	else if (Board[dsty][dstx]==-1)//harekate khali
	Black.iscatch='-';


	 if(Board[Black.cnty][Black.cntx]<10 )
		{

					goto again;
		}


	switch (Black.piece)
	{
		case 'R':

			if(ValidP(Black.cntx,Black.cnty,10,Black.dstx,Black.dsty)==0 ||  (Black.iscatch=='-' && Board[Black.dsty][Black.dstx]!=-1) || (Black.iscatch=='x' && ( Board[Black.dsty][Black.dstx]==-1 || Board[Black.dsty][Black.dstx]>=10 )) )
			{
			goto again;
			}
			else
			{
					Avaz(o,Black.dstx,Black.dsty,Black.cntx,Black.cnty);
					update();
				 if(IsCheckBlack()==1)
                {
                    Reverse_Avaz(o,Black.cntx,Black.cnty,Black.dstx,Black.dsty);
                    goto again;

                }

			}
			break;

		case 'N':
			if(ValidP(Black.cntx,Black.cnty,11,Black.dstx,Black.dsty)==0 ||  (Black.iscatch=='-' && Board[Black.dsty][Black.dstx]!=-1) || (Black.iscatch=='x' && ( Board[Black.dsty][Black.dstx]==-1 || Board[Black.dsty][Black.dstx]>=10 )) )
			{
			goto again;
			}
			else
			{
					Avaz(o,Black.dstx,Black.dsty,Black.cntx,Black.cnty);
					update();
				 if(IsCheckBlack()==1)
                {
                    Reverse_Avaz(o,Black.cntx,Black.cnty,Black.dstx,Black.dsty);
                    goto again;

                }

			}
			break;
		case 'B':
			if(ValidP(Black.cntx,Black.cnty,12,Black.dstx,Black.dsty)==0 ||  (Black.iscatch=='-' && Board[Black.dsty][Black.dstx]!=-1) || (Black.iscatch=='x' && ( Board[Black.dsty][Black.dstx]==-1 || Board[Black.dsty][Black.dstx]>=10 )) )
			{
			goto again;
			}
			else
			{
					Avaz(o,Black.dstx,Black.dsty,Black.cntx,Black.cnty);
					update();
				 if(IsCheckBlack()==1)
                {
                   Reverse_Avaz(o,Black.cntx,Black.cnty,Black.dstx,Black.dsty);
                    goto again;

                }

			}
			break;
		case 'Q':
				if(ValidP(Black.cntx,Black.cnty,13,Black.dstx,Black.dsty)==0 ||  (Black.iscatch=='-' && Board[Black.dsty][Black.dstx]!=-1) || (Black.iscatch=='x' && ( Board[Black.dsty][Black.dstx]==-1 || Board[Black.dsty][Black.dstx]>=10 )) )
			{
			goto again;
			}
			else
			{
					Avaz(o,Black.dstx,Black.dsty,Black.cntx,Black.cnty);
					update();
				 if(IsCheckBlack()==1)
                {
                    Reverse_Avaz(o,Black.cntx,Black.cnty,Black.dstx,Black.dsty);
                    goto again;

                }

			}
			break;
		case 'K':
			if(ValidP(Black.cntx,Black.cnty,14,Black.dstx,Black.dsty)==0 ||  (Black.iscatch=='-' && Board[Black.dsty][Black.dstx]!=-1) || (Black.iscatch=='x' && ( Board[Black.dsty][Black.dstx]==-1 || Board[Black.dsty][Black.dstx]>=10 )) )
			{
			goto again;
			}
			else
			{
					Avaz(o,Black.dstx,Black.dsty,Black.cntx,Black.cnty);
					update();
				 if(IsCheckBlack()==1)
                {
                    Reverse_Avaz(o,Black.cntx,Black.cnty,Black.dstx,Black.dsty);
                    goto again;

                }

			}
			break;

		case 'S':
			if(ValidP(Black.cntx,Black.cnty,15,Black.dstx,Black.dsty)==0 )
			{

			goto again;
			}
			else
			{
					Avaz(o,Black.dstx,Black.dsty,Black.cntx,Black.cnty);
					update();
				 if(IsCheckBlack()==1)
                {
                    Reverse_Avaz(o,Black.cntx,Black.cnty,Black.dstx,Black.dsty);
                    goto again;

                }

			}
			break;
	  }

        }
 	End:
	if(Elephant==1)
	{
    goto Final;
	}
    }

    }
                    Final :
                    initwindow(500,300,"Checkmate",300,200);
                    setfillstyle(1,0);
                    bar(0,0,500,500);
                    printf("%d",colour);
                    setcolor(colour);
                    settextstyle(4,3,5);
                    outtextxy(230,100,":)");
                    settextstyle(1,0,3);
                    outtextxy(360,150,"Game Over!!!");

}
    exit:
   getch();
	return 0;
}
