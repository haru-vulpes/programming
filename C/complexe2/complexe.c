#include "complexe.h"

struct complexe complexe_add(struct complexe n1, struct complexe n2)
{
	int resadd_re = n1.re + n2.re;
	int resadd_im = n1.im + n2.im;

	//struct complexe r;
	//r.re = resadd_re;
	//r.im = resadd_im;
	//return r;

	struct complexe r = { resadd_re, resadd_im };
	return r;
}

struct complexe complexe_mul(struct complexe n1, struct complexe n2)
{
	int resadd_re = n1.re * n2.re - n1.im * n2.im;
	int resadd_im = n1.re * n2.im + n1.im * n2.re;

	//struct complexe r;
	//r.re = resadd_re;
	//r.im = resadd_im;
	//return r;

	struct complexe r = { resadd_re, resadd_im };
	return r;
}

struct complexe complexe_sub(struct complexe n1, struct complexe n2)
{
	int resadd_re = n1.re - n2.re;
	int resadd_im = n1.im - n2.im;

	//struct complexe r;
	//r.re = resadd_re;
	//r.im = resadd_im;
	//return r;

	struct complexe r = { resadd_re, resadd_im };
	return r;
}


