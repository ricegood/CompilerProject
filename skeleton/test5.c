int main(){
	int *a;
	int b; 
	char *c;
	char d;
	struct a{int x;} e;
	struct a *f;

	/* not comparable */
	a == b; 
	a == c;
	a == d;
	b >= d;
	d <= *a;
	a == f;

	
	/* not int or char or pointer type */
	a == e;
	e == *f;
	e == f;


	/* not int or char type */
	a >= b;
	a >= c;
	a >= d;
	a >= e;
	a >= f;
	e < *f;
	f > &e;

	/* RHS LHS error */
	f = e;
	f = c;
	f = &d;

	/* not a pointer */
	e->x = b;
	b = e->x;

	/* variable is not a struct */
	a->x = b;

	/* OK */
	b == *a;
	d >= *c;
	f == &e;

	f = &e;
	e = *f;

	e.x = b;
	b = e.x;
	a = &(e.x);
	e.x = *a;

	return a;
}