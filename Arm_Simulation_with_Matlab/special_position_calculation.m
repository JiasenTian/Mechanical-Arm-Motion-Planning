
T01 = [1,0,0,0;
       0,1,0,0;
       0,0,1,0;
       0,0,0,1];
   
T12 = [0,-1,0,1.25;
       0,0,-1,0;
       1,0,0,0;
       0,0,0,1];
   
T23 = [1,0,0,10.5;
       0,1,0,0;
       0,0,1,0;
       0,0,0,1];
   
T34 = [-1,0,0,0;
       0,0,-1,-13;
       0,-1,0,0;
       0,0,0,1];
   
T45 = [-1,0,0,0;
       0,0,-1,0;
       0,-1,0,0;
       0,0,0,1];
   
T56 = [1,0,0,0;
       0,0,-1,-10;
       0,1,0,0;
       0,0,0,1];
   
T01 * T12 * T23 * T34 * T45 * T56
T01 * T12 * T23 * T34
T01 * T12 * T23

theta_1 = 45;
theta_2 = 45;
theta_3 = 45;
theta_4 = 45;
theta_5 = 135;
theta_6 = 45;

T01 = [cosd(theta_1), -sind(theta_1), 0 , 0 ;
       sind(theta_1), cosd(theta_1) , 0 , 0 ;
       0            , 0             , 1 , 0 ;
       0            , 0             , 0 , 1 ];

T12 = [cosd(theta_2), -sind(theta_2), 0 , 1.25;
       0            , 0             ,-1 , 0   ;
       sind(theta_2), cosd(theta_2) , 0 , 0   ;
       0            , 0             , 0 , 1   ];
   
T23 = [cosd(theta_3), -sind(theta_3), 0 , 10.5;
       sind(theta_3), cosd(theta_3) , 0 , 0   ;
       0            , 0             , 1 , 0   ;
       0            , 0             , 0 , 1   ];

T34 = [cosd(theta_4), -sind(theta_4), 0 , 0   ;
       0            , 0             , -1, -13 ;
       sind(theta_4),cosd(theta_4)  , 0 , 0   ;
       0            , 0             , 0 , 1   ];
 
T45 = [cosd(theta_5), -sind(theta_5), 0 , 0   ;
       0            , 0             , -1, 0   ;
       sind(theta_5), cosd(theta_5) , 0 , 0   ;
       0            , 0             , 0 , 1   ];
   
T56 = [cosd(theta_6), -sind(theta_6), 0 , 0   ;
       0            , 0             , -1, -10 ;
       sind(theta_6), cosd(theta_6) , 0 , 0   ;
       0            , 0             , 0 , 1   ];

T01 * T12 * T23 * T34 * T45 * T56