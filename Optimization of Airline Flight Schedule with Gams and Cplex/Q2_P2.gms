sets

*Newspaper Interval Index
  i Interval_News /1*3/
*TV Interval Index
  j Interval_TV /1*5/
*Binary Variable Index
  k BinaryVariable /1*5/

variables
 u OptAnswer
integer variables

*Number of News Ad in ith interval
X(i)

*Number of TV Ad in jth interval
Y(j)

binary variables
Z(k)
;

Equation
Goal

*Budget Constraint
Budget

*Constraint Subject to TV Intervals
Interval_TV_1
Interval_TV_2
Interval_TV_3
Interval_TV_4
Interval_TV_5
Interval_TV_6

*Constraint Subject to TV Intervals Part 2
Interval_TV_11
Interval_TV_22
Interval_TV_33

Interval_TV_111
Interval_TV_222
Interval_TV_333
Interval_TV_444
Interval_TV_555

*Constraint Subject to News Intervals
Interval_News(i)
Interval_News_1
Interval_News_2
Interval_News_3
Interval_News_4
Interval_News_5
Interval_News_6

*Constraint Subject to Number Of Ad
News_Ad_Num
TV_Ad_Num


*Sign Constraint
Sign_X(i)
Sign_Y(j)

*Part Two Constraints

*Total Ad Number
Total_Ad_Num

*Relation between TV Ads
TV_Ads
;

*Maximizing Customer

Goal.. u =E= 900*X('1')+ 600*X('2')+300*X('3')+10000*Y('1')+5000*Y('2')+2000*Y('3');




*Budget Constraint
Budget.. 1000*(X('1')+X('2')+X('3'))+10000*Y('4')+8000*Y('5') =l= 150000 ;


*Constraint Subject to TV Intervals
Interval_News(i)..  X(i)   =l= 10         ;
Interval_News_1..   X('1') =l=10          ;
Interval_News_2..   X('1') =g=10*Z('1')   ;
Interval_News_3..   X('2') =l=10*Z('1')   ;
Interval_News_4..   X('2') =g=10*Z('2')   ;
Interval_News_5..   X('3') =l=10*Z('2')   ;
Interval_News_6..   X('3') =g=0           ;

Interval_TV_1.. Y('1') =l=5            ;
Interval_TV_2.. Y('1') =g=5*Z('3')     ;
Interval_TV_3.. Y('2') =l=5*Z('3')     ;
Interval_TV_4.. Y('2') =g=5*Z('4')     ;
Interval_TV_5.. Y('3') =l=5*Z('4')     ;
Interval_TV_6.. Y('3') =g=0            ;


*Constraint Subject to TV Intervals Part 2
Interval_TV_11.. Y('4') =l=12            ;
Interval_TV_22.. Y('4') =g=12*Z('5')     ;
Interval_TV_33.. Y('5') =l=3*Z('5')     ;

Interval_TV_111.. Y('1') =l= 5;
Interval_TV_222.. Y('2') =l= 5;
Interval_TV_333.. Y('3') =l= 5;
Interval_TV_444.. Y('4') =l= 12;
Interval_TV_555.. Y('5') =l= 3;


*Constraint Subject to Number Of Ad
TV_Ad_Num.. Y('1')+Y('2')+Y('3') =l= 15 ;
News_Ad_Num..   X('1')+X('2')+X('3') =l= 30 ;


*Total Ad Number
Total_Ad_Num.. X('1')+ X('2')+ X('3')+ Y('1')+ Y('2')+ Y('3') =l= 30;


*Relation between TV Ads
TV_Ads.. Y('1')+Y('2')+Y('3') =e= Y('4')+Y('5');

*Sign Constraint
Sign_X(i).. X(i) =g=0 ;
Sign_Y(j).. Y(j) =g=0
;

Model Question2_Part2 inja modele /all/;
Solve Question2_Part2 using MIP maximization u;


