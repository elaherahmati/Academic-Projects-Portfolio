sets

*Large Airplanes Index
  i number_typeB /1*10/
*Medium Airplanes Index
  j number_typeM /1*15/
*Small Airplanes Indices
  m number_typeL /1*2/
* 1 = City A  ,  2 = City B  ,  3 = City C , 4 = City D
  k city /1*4/

  Type Type/B777,A330,A320/;


*Inputs

Parameter Cost(k,Type),Flight_Hour(k,Type),Profit(k,Type);
$call GDXXRW  Input.xlsx par=Cost rng=Data!b1:e5 Rdim=1 cdim=1 par=Flight_Hour rng=Data!h1:k5 Rdim=1 cdim=1 par=Profit rng=Data!n1:q5 Rdim=1 cdim=1
$GDXIN Input.gdx
$load Cost,Flight_Hour,Profit
$gdxin
;

* Cost is the Table of Flight Costs given in Prob, First Argument (k) is the city and the Second Argument (Type) is the Airplane type
* Flight_Hour is the Table of Flight Hours given in Prob, First Argument (k) is the city and the Second Argument (Type) is the Airplane type



variables
 z OptAnswer
integer variables
*Number of Daily Flights of ith Large Airplane to City k
 B(i,k)
*Number of Daily Flights of jth Medium Airplane to City k
 W(j,k)
*Number of Daily Flights of mth Small Airplane to City k
 L(m,k)
 ;

Equation
Goal

*Constraints related to the number of flights that each city should have daily.
Fly_Num1
Fly_Num2
Fly_Num3
Fly_Num4

*Constraints related to the Maximum daily flight hour limit of each airplane
Hour_I(i)
Hour_J(j)
Hour_M(m)

* Medium Airplanes cant fly to City D
Impossible_Flight(j)

* Sign Constraint
Sign_B(i,k)
Sign_W(j,k)
Sign_L(m,k)
;
*Maximizing Profit
Goal.. z =E= sum(i,Profit('1','B777')*B(i,'1') + Profit('2','B777')*B(i,'2') +
Profit('3','B777')*B(i,'3') + Profit('4','B777')*B(i,'4')) +
sum(j,Profit('1','A330')*W(j,'1') + Profit('2','A330')*W(j,'2') +
Profit('3','A330')*W(j,'3')) +
sum(m,Profit('1','A320')*L(m,'1') + Profit('2','A320')*L(m,'2') +
Profit('3','A320')*L(m,'3') + Profit('4','A320')*L(m,'4'));


*Constraints related to the number of flights that each city should have daily.
Fly_Num1..sum(i , B(i,'1')) + sum(j,W(j,'1')) + sum(m,L(m,'1')) =E=4;
Fly_Num2..sum(i , B(i,'2')) + sum(j,W(j,'2')) + sum(m,L(m,'2')) =E=4;
Fly_Num3..sum(i , B(i,'3')) + sum(j,W(j,'3')) + sum(m,L(m,'3')) =E=4;
Fly_Num4..sum(i , B(i,'4')) + sum(j,W(j,'4')) + sum(m,L(m,'4')) =E=2;

*Constraints related to the Maximum daily flight hour limit of each airplane
Hour_I(i).. Flight_Hour('1','B777')*B(i,'1') + Flight_Hour('2','B777')*B(i,'2') + Flight_Hour('3','B777')*B(i,'3') + Flight_Hour('4','B777')*B(i,'4') =l= 18;
Hour_J(j).. Flight_Hour('1','A330')*W(j,'1') + Flight_Hour('2','A330')*W(j,'2') + Flight_Hour('3','A330')*W(j,'3')  =l= 18;
Hour_M(m).. Flight_Hour('1','A320')*L(m,'1') + Flight_Hour('2','A320')*L(m,'2') + Flight_Hour('3','A320')*L(m,'3') + Flight_Hour('4','A320')*L(m,'4') =l= 18;

* Medium Airplanes cant fly to City D
Impossible_Flight(j).. W(j,'4') =e= 0 ;

* Sign Constraint
Sign_B(i,k).. B(i,k)=g=0      ;
Sign_W(j,k)..W(j,k) =g=0   ;
Sign_L(m,k)..L(m,k) =g=0
;


Model Question1_Part2 inja modele /all/;
Solve Question1_Part2 using MIP maximization z;

*Output
execute_unload "Output_Part2.gdx"   z , B, W,L ;
execute 'gdxxrw.exe Output_Part2.gdx var=z rng=TargetFunction_MaxProfit!a1'
execute 'gdxxrw.exe Output_Part2.gdx var=B rng=B777Airplane!a1'
execute 'gdxxrw.exe Output_Part2.gdx var=W rng=A330Airplane!a1'
execute 'gdxxrw.exe Output_Part2.gdx var=L rng=A320Airplane!a1'