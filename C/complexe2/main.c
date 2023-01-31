#include <stdio.h>
#include "complexe.h"

void check_complexe(struct complexe result, struct complexe exp_result);

void check_complexe_add(struct complexe n1, struct complexe n2, struct complexe exp_result);

int main(void)
{

////////////////////////////////////////////////////////
//                    ADDITION			      //
////////////////////////////////////////////////////////

	struct complexe n1;

	n1.re = 1;
	n1.im = 2;

	struct complexe n2;

	n2.re = 4;
	n2.im = 3;

	struct complexe exp_result;

	exp_result.re = 5;
	exp_result.im = 5;

	struct complexe n3;
	
	n3.re = 7;
	n3.im = -9;

	struct complexe n4;

	n4.re = -5;
	n4.im = 3;

	struct complexe exp_result2;

	exp_result2.re = 2;
	exp_result2.im = -6;

	struct complexe exp_resultmul1;

	exp_resultmul1.re = -8;
	exp_resultmul1.im = 66;

	struct complexe exp_resultsub1;

	exp_resultsub1.re = 12;
	exp_resultsub1.im = -12;

////////////////////////////////////////////////////////

	check_complexe_add(n1, n2, exp_result);  

	check_complexe_add(n3, n4, exp_result2);  

	check_complexe(complexe_mul(n3, n4), exp_resultmul1);

	check_complexe(complexe_sub(n3, n4), exp_resultsub1);
	
	return 0;
}

void check_complexe(struct complexe result, struct complexe exp_result)
{
	if (result.re == exp_result.re && result.im == exp_result.im)
		printf("OK. expected (%d + %di), got (%d + %di)\n", exp_result.re, exp_result.im, 
				result.re, result.im);
	else 
		printf("KO. expected (%d + %di), got (%d + %di)\n", exp_result.re, exp_result.im,
					result.re, result.im);
}

void check_complexe_add(struct complexe n1, struct complexe n2, struct complexe exp_result)
{
	struct complexe result = complexe_add(n1, n2);

	check_complexe(result, exp_result);

	//if (result.re == exp_result.re && result.im == exp_result.im)
	//	printf("OK. expected (%d + %di), got (%d + %di)\n", exp_result.re, exp_result.im, 
	//			result.re, result.im);
	//else 
	//	printf("KO. expected (%d + %di), got (%d + %di)\n", exp_result.re, exp_result.im,
	//				result.re, result.im);
}
