/*int a;*/

int main(){
	int a;
	char b;
	int c[20];
	struct temp w; /*error*/
	{
		struct temp {int x; int y[20]; } w;
	}
	{

	}

/* hi my /* name is yj * sdkfjls */ /***/ /*****/ */
	a = 10;
	b = 5;  /*error*/

	if ( a == 10 || b == 'a' )
	{
		return c[1];
	}
	else {
		return c; /*error*/
	}
	
	w = a;
	return w.x; /*error*/
	return b;  /*error*/
}
