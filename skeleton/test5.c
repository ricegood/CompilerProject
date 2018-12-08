/* func struct return , parameter test */
struct _str1{
	int x;
	int y;
	struct _st2{
		int z;
		int w[5];
	} strstr;
} sample_str;

struct _str1 test(int a, int b, int c, int d){
	struct _str1 s;

	s.x = a;
	s.y = b;
	s.strstr.z = c;
	s.strstr.w[3] = d;

	return s;
}

int main(){
	int i;
	int j;
	int k;
	int l;

	struct _str1 a;

	write_int(a.x); /* 0 */
	write_string("\n");
	write_int(a.y); /* 0 */
	write_string("\n");
	write_int(a.strstr.z); /* 0 */
	write_string("\n");
	write_int(a.strstr.w[1]); /* 0 */
	write_string("\n");
	write_int(a.strstr.w[3]); /* 0 */
	write_string("\n========================\n");

	i = 5;
	j = 2;
	k = 3;

	a = test(i, j, k, 13);

	write_int(test(i, j, k, 13).x); /* 5 */
	write_string("\n");
	write_int(test(i, j, k, 13).y); /* 2 */
	write_string("\n");
	write_int(test(i, j, k, 13).strstr.z); /* 3 */
	write_string("\n");
	write_int(test(i, j, k, 13).strstr.w[1]); /* 0 */
	write_string("\n");
	write_int(test(i, j, k, 13).strstr.w[3]); /* 13 */
	write_string("\n========================\n");

	write_int(a.x); /* 5 */
	write_string("\n");
	write_int(a.y); /* 2 */
	write_string("\n");
	write_int(a.strstr.z); /* 3 */
	write_string("\n");
	write_int(a.strstr.w[1]); /* 0 */
	write_string("\n");
	write_int(a.strstr.w[3]); /* 13 */
	write_string("\n");
}
