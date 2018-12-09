/* func struct return , parameter test */
struct _str1{
	int x;
	struct _st2{
		int z;
		int w[5];
	} strstr;
	int y;
} sample_str;

int call_by_value(int a, struct _str1 b) {

	write_int(b.x); /* 777 */
	write_string("\n");
	write_int(b.y); /* 356 */
	write_string("\n");
	write_int(b.strstr.z); /* 123 */
	write_string("\n");
	write_int(b.strstr.w[1]); /* ? */
	write_string("\n");
	write_int(b.strstr.w[3]); /* 987 */
	write_string("\n========================\n");

	b.strstr.w[1] = 256;

	return b.strstr.w[1];
}

int call_by_ref(int a, struct _str1 *b) {
	
	write_int(b->x); /* 777 */
	write_string("\n");
	write_int(b->y); /* 356 */
	write_string("\n");
	write_int(b->strstr.z); /* 123 */
	write_string("\n");
	write_int(b->strstr.w[1]); /* ? */
	write_string("\n");
	write_int(b->strstr.w[3]); /* 987 */
	write_string("\n========================\n");

	b->strstr.w[1] = 256;

	return b->strstr.w[1];
}

void main(){
	
	struct _str1 a;
	int b;

	a.x = 777;
	a.y = 356;
	a.strstr.z = 123;
	a.strstr.w[3] = 987;

	b = call_by_value(5, a); /* print call_by_value */
	write_int(b); /* 256 */
	write_string("\n");
	write_int(a.strstr.w[1]); /* ? */
	write_string("\n========================\n");

	b = call_by_ref(5, &a); /* print call_by_ref */
	write_int(b); /* 256 */
	write_string("\n");
	write_int(a.strstr.w[1]); /* 256 */
	write_string("\n");
}
