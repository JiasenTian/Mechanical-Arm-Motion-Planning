#ifndef _ANGLE_DEDUCTION_H_
#define _ANGLE_DEDUCTION_H_

#include<stdio.h>

/*********************** Common Parameters *********************************/
#define PI                        3.1415926

/*********************** arm matrices parameter ****************************/
#define a_0                       0
#define a_1                       1.25
#define a_2                       10.5
#define a_3                       0
#define a_4                       0
#define a_5                       0
#define alfa_0                    0
#define alfa_1                    PI/2
#define alfa_2                    0
#define alfa_3                    PI/2
#define alfa_4                    PI/2
#define alfa_5                    PI/2
#define d_1                       0
#define d_2                       0
#define d_3                       0
#define d_4                       13
#define d_5                       0
#define d_6                       10

/*********************** arm information parameter ****************************/
#define l1                       10.5
#define pow_l1 
#define l2                       13
#define l3                       10
/***************************************************/


struct angle{
	int angle_num;
	double angle_degree[2];
	bool angle_option[2];
	int count;
	int option;
};

/***************************************************/
struct angle angle_array[6];
float angle_1_F, angle_2_F, angle_3_F, angle_4_F, angle_5_F, angle_6_F; 
double angle_1, angle_2, angle_3, angle_4, angle_5, angle_6;
double angle_2_beta, angle_2_theta;
double s1, s2_1, s2_2, s3_1, s3_2, s4_1, s4_2, s5_1, s5_2, s6;
double c1, c2_1, c2_2, c3_1, c3_2, c4_1, c4_2, c5_1, c5_2, c6;
double c23_1, c23_2, s23_1, s23_2;
double cot1, cot2, cot3, cot4, cot5, cot6;
double at1, at2, at3, at4_1, at4_2, at5_1, at5_2, at6_1, at6_2;
double t1, t2, t3, t4, t5, t6;

/********************** attitude matrix *****************************/
/*×ËÌ¬¾ØÕó*/
double n_x, o_x, a_x;
double n_y, o_y, a_y;
double n_z, o_z, a_z;

/********************** terminal position *****************************/

double P_x, P_y, P_z;
double W_x, W_y, W_z;

/************************ commom function ***************************/

double roundTo4DecimalPlaces(double x);
double angleToRadian(double angle);
double radianToAngle(double radian);
double Sin(double x);
double Cos(double x);
double Tan(double x);
double ATan2(double y, double x);

/************************** deduction function ******************************/

void initialAngleArray(void);
double angle_1_calculation(double y, double x);
void angle_2_calculation(double x, double y, double z);
double angle_3_calculation(double x, double y, double z);
void angle_4_calculation(void);
void angle_5_calculation(void);
void angle_6_calculation(void);
void angle_1_possible_solution(double angle_result);
void angle_2_possible_solution(double w_x, double w_y, double w_z);
void angle_3_possible_solution(double angle_result);
void angle_4_possible_solution(double p_x, double p_y, double p_z);
void angle_5_possible_solution(double p_x, double p_y, double p_z);
void angle_6_possible_solution(double p_x, double p_y, double p_z);
void angleIntegration(double w_x, double w_y, double w_z, double p_x, double p_y, double p_z);
void angle_deduction(double (*matrix)[4]);
#endif /* _ANGLE_DEDUCTION_H_ */
