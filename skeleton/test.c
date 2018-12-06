struct temp {
	/* size = 4 */
	int x;
	char y[2];
	int z;
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
	j.z = 2;
	/* j.y[1] = 'c'; */
	k = 3;

	l = test(i, j, k);
}