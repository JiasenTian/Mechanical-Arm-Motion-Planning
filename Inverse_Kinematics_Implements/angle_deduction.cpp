#include <stdio.h>
#include <math.h>
#include <string.h>
#include "angle_deduction.h"

void initialAngleArray(){
	int i;
	for(i = 0; i < 6; i++){
		angle_array[i].angle_num = i + 1;
		angle_array[i].angle_degree[0] = 90.0;
		angle_array[i].angle_degree[1] = 90.0;
		angle_array[i].angle_option[0] = false;
		angle_array[i].angle_option[1] = false;
		angle_array[i].count = 0;
		angle_array[i].option = -1;
	}
}

double roundTo4DecimalPlaces(double x){
	double temp = (int)(10000.0 * x + 0.5) / 10000.0;
	return temp;
}

double angleToRadian(double angle){
	double radian = angle * PI/180.0;
	return radian;
}

double radianToAngle(double radian){
	double angle = radian * (180.0/PI);
	return angle;
}

double Sin(double x){
	double temp_radian = angleToRadian(x);
	return sin(temp_radian);
}

double Cos(double x){
	double temp_radian = angleToRadian(x);
	return cos(temp_radian);
}

double Tan(double x){
	double temp_radian = angleToRadian(x);
	return tan(temp_radian);
}

double ATan2(double y, double x){
	return atan2(y, x);
}

double angle_1_calculation(double y, double x){
    at1 = ATan2(y, x);
	return radianToAngle(at1);
}

void angle_2_calculation(double x, double y, double z){
	angle_2_beta = radianToAngle(ATan2(z, (sqrt(pow(x, 2) + pow(y, 2)) - a_1)));
	
	double cos_theta = (pow((sqrt(pow(x, 2) + pow(y, 2)) - a_1), 2) + pow(z, 2) + pow(l1, 2) - pow(l2, 2))/ (2 * l1 * sqrt(pow(z, 2) + pow((sqrt(pow(x, 2) + pow(y, 2))- a_1),2)));
	angle_2_theta = radianToAngle(acos(cos_theta));
	
}

double angle_3_calculation(double x, double y, double z){
	double c3 = (pow((sqrt(pow(x, 2) + pow(y, 2)) - a_1),2) + pow(z, 2) - pow(l1, 2) - pow(l2, 2)) / (2 * l1 *l2);
	if((c3 > 0) && (c3 - 1.00) > 0){
		c3 = 1.0000;
	}
	else if((c3 < 0) && (c3 + 1.00) < 0){
		c3 = -1.0000;
	}
	cot3 = acos(c3);   //余弦值。x (c3) 的取值必须位于区间[-1, 1]中，如果 x 的值超出此区间，将会产生域错误（domain error）。
	return radianToAngle(cot3);//cot3;
}

void angle_4_calculation(void){
	s1 = Sin(angle_array[0].angle_degree[0]);
	c1 = Cos(angle_array[0].angle_degree[0]); 
	s2_1 = Sin(angle_array[1].angle_degree[0]);
    c2_1 = Cos(angle_array[1].angle_degree[0]);
	s3_1 = Sin(angle_array[2].angle_degree[0]);
	c3_1 = Cos(angle_array[2].angle_degree[0]);
	s23_1 = Sin(angle_array[1].angle_degree[0] + angle_array[2].angle_degree[0]);
	c23_1 = Cos(angle_array[1].angle_degree[0] + angle_array[2].angle_degree[0]);
	if(angle_array[1].count == 1 && angle_array[1].option == 0){
		s2_2 = -1.1;
		c2_2 = -1.1;
		s3_2 = -1.1;
		c3_2 = -1.1;
		s23_2 = -1.1;
		c23_2 = -1.1;
	}
	else if(angle_array[1].count == 2){
        s2_2 = Sin(angle_array[1].angle_degree[1]);
		c2_2 = Cos(angle_array[1].angle_degree[1]);
		s3_2 = Sin(angle_array[2].angle_degree[1]);
		c3_2 = Cos(angle_array[2].angle_degree[1]);
		s23_2 = Sin(angle_array[1].angle_degree[1] + angle_array[2].angle_degree[1]);
		c23_2 = Cos(angle_array[1].angle_degree[1] + angle_array[2].angle_degree[1]);
		/*printf("s2_2 = %f    c2_2 = %f\n", s2_2, c2_2);
		printf("s3_2 = %f    c3_2 = %f\n", s3_2, c3_2);
		printf("s23_2 = %f    c23_2= %f\n", s23_2, c23_2);*/
	}
}

void angle_5_calculation(void){
	s4_1 = Sin(angle_array[3].angle_degree[0]);
	c4_1 = Cos(angle_array[3].angle_degree[0]);
	if(angle_array[3].count == 1){
		s4_2 = -1.1;
		c4_2 = -1.1;
	}
	else if(angle_array[3].count == 2){
		s4_2 = Sin(angle_array[3].angle_degree[1]);
     	c4_2 = Cos(angle_array[3].angle_degree[1]);
	}
}

void angle_6_calculation(void){
    s5_1 = Sin(angle_array[4].angle_degree[0]);
	c5_1 = Cos(angle_array[4].angle_degree[0]);
	if(angle_array[4].count == 1){
		s5_2 = -1.1;
		c5_2 = -1.1;
	}
	else if(angle_array[4].count == 2){
		s5_2 = Sin(angle_array[4].angle_degree[1]);
	    c5_2 = Cos(angle_array[4].angle_degree[1]);
	}
}

void angle_1_possible_solution(double angle_result){
	angle_array[0].angle_num = 1;
	angle_array[0].angle_degree[0] = roundTo4DecimalPlaces(angle_result);
	angle_array[0].angle_option[0] = true;
	angle_array[0].count = 1;
	angle_array[0].option = 0;
}

void angle_2_possible_solution(double w_x, double w_y, double w_z){
	angle_2_calculation(w_x, w_y, w_z);
	angle_array[1].angle_num = 2;
	angle_array[1].angle_degree[0] = roundTo4DecimalPlaces(angle_2_beta + angle_2_theta );
	angle_array[1].angle_degree[1] = roundTo4DecimalPlaces(angle_2_beta - angle_2_theta );
	if(angle_2_theta == 0.0){
		angle_array[1].count = 1;
		angle_array[1].angle_option[0] = true;
	    angle_array[1].angle_option[1] = false;
	}
	else{
		angle_array[1].count = 2;
		angle_array[1].angle_option[0] = true;
	    angle_array[1].angle_option[1] = true;
	}

	if(angle_array[2].angle_degree[angle_array[2].option] <= 0){
		angle_array[1].option = 0;
	}
	else{
		angle_array[1].option = 1;
	}
}

void angle_3_possible_solution(double angle_result){
	angle_array[2].angle_num = 3;
	if(angle_result != 0.0){
	    angle_array[2].angle_degree[0] = roundTo4DecimalPlaces(90 - angle_result);//2019/7/3 少尤其以
	    angle_array[2].angle_degree[1] = roundTo4DecimalPlaces(90 + angle_result);
		angle_array[2].angle_option[0] = true;
		angle_array[2].angle_option[1] = true;
		angle_array[2].count = 2;
		angle_array[2].option = 0;
	}
	else{
		angle_array[2].angle_degree[0] = roundTo4DecimalPlaces(90 - angle_result);
		angle_array[2].angle_option[0] = true;
		angle_array[2].count = 1;
		angle_array[2].option = 0;
	}
}

void angle_4_possible_solution(double p_x, double p_y, double p_z){
	angle_array[3].angle_num = 4;
	angle_4_calculation();
	at4_1 = ATan2((s1 * p_x - c1 * p_y), (c1 * c23_1 * p_x + s1 * c23_1 * p_y + s23_1 * p_z - a_2 * s2_1 * s23_1 - c23_1 * (c2_1 * a_2 + a_1)));
	at4_2 = ATan2((s1 * p_x - c1 * p_y), (c1 * c23_2 * p_x + s1 * c23_2 * p_y + s23_2 * p_z - a_2 * s2_2 * s23_2 - c23_2 * (c2_2 * a_2 + a_1)));
	if(angle_array[2].count == 1){
		angle_array[3].angle_degree[0] = roundTo4DecimalPlaces(radianToAngle(at4_1));
		angle_array[3].angle_option[0] = true;
		angle_array[3].count = 1;
		angle_array[3].option = 0;
	}
	else if(angle_array[2].count == 2){
		angle_array[3].angle_degree[0] = roundTo4DecimalPlaces(radianToAngle(at4_1));
		angle_array[3].angle_option[0] = true;
		angle_array[3].angle_degree[1] = roundTo4DecimalPlaces(radianToAngle(at4_2));
		angle_array[3].angle_option[1] = true;
		angle_array[3].count = 2;
		angle_array[3].option = 0;
	}

}

void angle_5_possible_solution(double p_x, double p_y, double p_z){
	angle_array[4].angle_num = 5;
	angle_5_calculation();
	double alfa1 = (s1 * s4_1 * p_x) + (c1 * c23_1 * c4_1 * p_x) - (c1 * s4_1 * p_y) + (s1 * c23_1 * c4_1 * p_y) + (s23_1 * c4_1 * p_z) - (c2_1 * c23_1 *  c4_1 * a_2) - (a_1 * c23_1 * c4_1) - (a_2 * s2_1 * s23_1 * c4_1);
	double beta1 = -((c1 * s23_1 * p_x) + (s1 * s23_1 * p_y) - (c23_1 * p_z) - d_4 - (c2_1 * s23_1 * a_2) - (a_1 * s23_1) + (s2_1 * c23_1 * a_2));
	at5_1 = ATan2(alfa1, beta1);
	if(angle_array[3].count == 1){
		angle_array[4].angle_degree[0] = roundTo4DecimalPlaces(radianToAngle(at5_1));
		angle_array[4].angle_option[0] = true;
		angle_array[4].count = 1;
		angle_array[4].option = 0;
	}
	else if(angle_array[3].count == 2){
		angle_array[4].angle_degree[0] = roundTo4DecimalPlaces(radianToAngle(at5_1));
		angle_array[4].angle_option[0] = true;
		
		double alfa2 = (s1 * s4_2 * p_x) + (c1 * c23_2 * c4_2 * p_x) - (c1 * s4_2 * p_y) + (s1 * c23_2 * c4_2 * p_y) + (s23_2 * c4_2 * p_z) - (c2_2 * c23_2 *  c4_2 * a_2) - (a_1 * c23_2 * c4_2) - (a_2 * s2_2 * s23_2 * c4_2);
        double beta2 = -((c1 * s23_2 * p_x) + (s1 * s23_2 * p_y) - (c23_2 * p_z) - d_4 - (c2_2 * s23_2 * a_2) - (a_1 * s23_2) + (s2_2 * c23_2 * a_2));
		at5_2 = ATan2(alfa2, beta2);

		angle_array[4].angle_degree[1] = roundTo4DecimalPlaces(radianToAngle(at5_2));
		angle_array[4].angle_option[1] = true;
		angle_array[4].count = 2;
		angle_array[4].option = 0;
	}
}

void angle_6_possible_solution(double p_x, double p_y, double p_z){
	angle_array[5].angle_num = 6;
	angle_6_calculation();
	double alfa1 = ((-s1 * c4_1 + c1 * c23_1 * s4_1) * n_x + (c1 * c4_1 + s1 * c23_1 * s4_1) * n_y + s23_1 * s4_1 * n_z);
	double beta1 = ((c1 * s23_1 * s5_1 + c1 * c23_1 * c4_1 * c5_1 + s1 * s4_1 * c5_1) * n_x + (s1 * s23_1 * s5_1 + s1 * c23_1 * c4_1 * c5_1 - c1 * s4_1 * c5_1) * n_y + (-c23_1 * s5_1 + s23_1 * c4_1 * c5_1) * n_z); 
	at6_1 = ATan2(alfa1, beta1);
	if(angle_array[4].count == 1){
		angle_array[5].angle_degree[0] = roundTo4DecimalPlaces(radianToAngle(at6_1));
		angle_array[5].angle_option[0] = true;
		angle_array[5].count = 1;
		angle_array[5].option = 0;
	}
	else if(angle_array[4].count == 2){
        angle_array[5].angle_degree[0] = roundTo4DecimalPlaces(radianToAngle(at6_1));
		angle_array[5].angle_option[0] = true;

		double alfa2 = ((-s1 * c4_2 + c1 * c23_2 * s4_2) * n_x + (c1 * c4_2 + s1 * c23_2 * s4_2) * n_y + s23_2 * s4_2 * n_z);
	    double beta2 = ((c1 * s23_2 * s5_2 + c1 * c23_2 * c4_2 * c5_2 + s1 * s4_2 * c5_2) * n_x + (s1 * s23_2 * s5_2 + s1 * c23_2 * c4_2 * c5_2 - c1 * s4_2 * c5_2) * n_y + (-c23_2 * s5_2 + s23_2 * c4_2 * c5_2) * n_z); 
	    at6_2 = ATan2(alfa2, beta2);
		angle_array[5].angle_degree[1] = roundTo4DecimalPlaces(radianToAngle(at6_2));
		angle_array[5].angle_option[1] = true;

		angle_array[5].count = 2;
		angle_array[5].option = 0;
	}
}

void angleIntegration(double w_x, double w_y, double w_z, double p_x, double p_y, double p_z){
	angle_1_possible_solution(angle_1_calculation(w_y, w_x));
	angle_3_possible_solution(angle_3_calculation(w_x, w_y, w_z));
	angle_2_possible_solution(w_x, w_y, w_z);
	angle_4_possible_solution(p_x, p_y, p_z);
	angle_5_possible_solution(p_x, p_y, p_z);
	angle_6_possible_solution(p_x, p_y, p_z);
}

void angle_deduction(double (*matrix)[4]){
	initialAngleArray();

	n_x = matrix[0][0];
	n_y = matrix[1][0];
	n_z = matrix[2][0];

	o_x = matrix[0][1];
	o_y = matrix[1][1];
	o_z = matrix[2][1];

	a_x = matrix[0][2];
	a_y = matrix[1][2];
	a_z = matrix[2][2];

	P_x = matrix[0][3];
	P_y = matrix[1][3];
	P_z = matrix[2][3];

	W_x = P_x - a_x * l3;
	W_y = P_y - a_y * l3;
	W_z = P_z - a_z * l3;

	/*printf("The position matrix is : \n");
	printf("%f , %f , %f , %f\n", n_x, o_x, a_x, P_x);
	printf("%f , %f , %f , %f\n", n_y, o_y, a_y, P_y);
	printf("%f , %f , %f , %f\n", n_z, o_z, a_z, P_z);
	printf("%f , %f , %f , %f\n", matrix[3][0], matrix[3][1], matrix[3][2], matrix[3][3]);

	printf("W_x = %f,  W_y = %f, W_z = %f\n", W_x, W_y, W_z);*/
	angleIntegration(W_x, W_y, W_z, P_x, P_y, P_z);

}

int main(){
	initialAngleArray();
	double matrix[4][4] = {
		{-1.0,  0  , 0, 1.25},
		{0  , -1.0, 0, 0},
		{0  ,  0  , 1, 33.5},
		{0  ,  0  , 0, 1}   
	};
	double matrix_1[4][4] = {
		{0  ,  0  , 1 , 24.25},
		{0  , -1  , 0 , 0},
		{1  ,  0  , 0 , 10.5},
		{0  ,  0  , 0 , 1}   
	};
	double matrix_2[4][4] = {
		{-0.2500 , -0.4571 , 0.8536 , 23.8618},
		{0.9571  , -0.2500 , 0.1464 , 16.7907},
		{0.1464  , 0.8536  , 0.5000 , 12.4246},
		{0       , 0       , 0      ,  1     }
	};
	/*result1 = angle_1_calculation(1.25, 0.0);
	printf("角度1为%f\n", result1);
	result3 = angle_3_calculation(0.0, 1.25, 23.5);
	printf("角度3为%f\n", result3);*/
    //angleIntegration(11.75, 0, 13, 0, 0, 0);
	angle_deduction(matrix_2);
	int i;
	for(i = 0; i < 6; i++){
		printf("Angle %d :\n", angle_array[i].angle_num);
		printf("Degree 1 is %f\n", angle_array[i].angle_degree[0]);
		printf("Degree 2 is %f\n", angle_array[i].angle_degree[1]);
		printf("Degree 1 is %d\n", angle_array[i].angle_option[0]);
		printf("Degree 2 is %d\n", angle_array[i].angle_option[1]);
		printf("Count is %d\n", angle_array[i].count);
		printf("Option is %d\n", angle_array[i].option);
	}
	//printf("The result is %f\n", roundTo4DecimalPlaces(0.12345));
	return 0;
}