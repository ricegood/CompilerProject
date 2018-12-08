int global_1;
int global_2;

/* struct, array operation */

struct _str1{
	int x;
	int y;
	struct _st2{
		int z;
		int w[5];
	} strstr;
} sample_str;

int main(){
	int i;
	int j;
	int k;
	int *l;
	struct _str1 *teststr[10];
	struct _str1 test1;
	struct _str1 test2;

	teststr[7] = &test1;
	teststr[2] = &test2;

	i = 7;

	teststr[i]->y = i - 10;
	teststr[i]->x = 2;
	teststr[i]->strstr.z = 5;
	teststr[i]->strstr.w[3] = 7;
	
	j = teststr[i]->y;

	write_int(j); /* -3 */
	write_string("\n");

	write_string("=========================\n");
	write_int(teststr[2]->y); /* 0 */
	write_string("\n");
	write_int(teststr[2]->x); /* 0 */
	write_string("\n");
	write_int(teststr[2]->strstr.z); /* 0 */
	write_string("\n");
	write_int(teststr[2]->strstr.w[0]); /* 0 */
	write_int(teststr[2]->strstr.w[3]); /* 0 */

	teststr[2] = teststr[7]; /* struct assignment */

	write_string("=========================\n");
	write_int(teststr[2]->y); /* -3 */
	write_string("\n");
	write_int(teststr[2]->x); /* 2 */
	write_string("\n");
	write_int(teststr[2]->strstr.z); /* 5 */
	write_string("\n");
	write_int(teststr[2]->strstr.w[0]); /* 0 */
	write_string("\n");
	write_int(teststr[2]->strstr.w[3]); /* 7 */
	write_string("\n");
	
}