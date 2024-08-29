#include "ws1.h"

int main() {
	
	/*TESTS DATA*/
	/*variables for PowerOfTen tests*/
	/*positive n:*/
	int pos_n_val = 2;
	double pos_n_val_res = 100.0;
	
	/*n is zero:*/
	int zero_n_val = 0;
	double zero_n_val_res = 1.0;
	
	/*negative n:*/
	int neg_n_val = -2;
	double neg_n_val_res = 0.01;
	
	
	/*variables for FlipIntOrder tests*/
	/*leading zero positive n:*/
	int pos_lead_zero_num = 156480, pos_lead_zero_num_exp_res = 84651;
	
	/*leading zero negative n:*/
	int neg_lead_zero_num = -156480, neg_lead_zero_num_exp_res = -84651;
	
	/*non leading zero postive n:*/
	int pos_non_lead_zero_num = 56248, pos_non_lead_zero_num_exp_res = 84265;
	
	/*non leading zero negative n:*/
	int neg_non_lead_zero_num = -56248, neg_non_lead_zero_num_exp_res = -84265;
	
	
	/*varibles for swap values test:*/
	int a = 7, b = 3;

	
	
	
	/*TESTS*/
	/*test print "Hello World" from hex:*/
	PrintHello();
	
	
	
	/*test calculation of ten in the power of n:*/
	/*test positive n:*/
	assert (PowerOfTen(pos_n_val) == pos_n_val_res);

	/*test zero n:*/
	assert (PowerOfTen(zero_n_val) == zero_n_val_res);
	
	/*test negative n:*/
	assert (PowerOfTen(neg_n_val) == neg_n_val_res);
	
	
	
	/*test number in reversed order*/
	/*test leading zero positive n:*/
	assert (FlipIntOrder(pos_lead_zero_num) == pos_lead_zero_num_exp_res);
	
	/*test leading zero negative n:*/
	
	assert (FlipIntOrder(neg_lead_zero_num) == neg_lead_zero_num_exp_res);
	
	/*test non leading zero postive n:*/
	assert (FlipIntOrder(pos_non_lead_zero_num) == pos_non_lead_zero_num_exp_res);
	
	/*test non leading zero negative n:*/
	
	assert (FlipIntOrder(neg_non_lead_zero_num) == neg_non_lead_zero_num_exp_res);
	

	
	/*test swap values:*/
	Swap(&a, &b);
	assert (a == 3);
	assert (b == 7);

	
	return 0;
}

