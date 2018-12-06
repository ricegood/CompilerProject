struct temp {
	/* size = 4 */
	int x;
	char y[3];
};

int test(int a, struct temp b, int c) {
	/* Q. num of args = 3, but size of args = 6 */
	return a;
}

int main(){
	int i;
	struct temp j;
	int k;
	int l;

	i = 1;
	j.x = 2;
	k = 3;

	l = test(i, j, k);
}