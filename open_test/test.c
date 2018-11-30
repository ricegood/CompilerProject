/* total error message test */
int global_i;
char global_c;

struct s; /* incomplete type */
struct s a; /* incomplete type */

struct s main(int a) { /* incomplete type */
  int a; /* redeclaration */
  struct s {
    int a;
    char b;
  } y;
}

void main(void v) {
  int x;
  char* c;
  c = "abc";
  x + y; /* not declared */
  if (x == 1) {
    return x; /* return type was not matched */
  }
  else {
    void x;
    return x;
  }
}

int returnIntFunc() {
  return 'c'; /* return type was not matched */
  return 5;
}

struct bar{};
void bar(void);
int bar; /* redeclaration error */
int bar(int i, void a) { /* redeclaration error */
  int bar;
  int a; /* redeclaration error */
  struct bar{}; /* redeclaration error */
  struct bar s;

  struct s s2;
  {
    int a;
    int bar;
    s2.a = a;
  }

  a = bar(); /* not a function */
  s = bar(); /* not a function */
  s2.a = s2.b; /* LHS RHS error */

  i++;
  i--;
  i == s2.b; /* not comparable */
  s2++; /* [CHECK] not int or char type */
  i || s2->a; /* not pointer */
  i = s2.a && i;
  return s2.a;
}

int* foo(int* i, char* c) {
  struct s *ptr_s;
  struct s s;
  int a[10];
  int aa[5];
  char b[5];

  b = "abc"; /* 'LHS is not a variable' */
  i = NULL;
  i == NULL;
  c = NULL;
  c == NULL;
  a = NULL; /* LHS is not variable */
  ptr_s = NULL;
  ptr_s == NULL;
  ptr_s->a == NULL; /* not comparable */
  ptr_s->a = NULL; /* RHS is not const or var */
  a[5] = NULL; /* RHS is not const or var */
  s.d = 5; /* [CHECK] not such field */

  i->a; /* variable is not struct */
  a == aa;
  aa == b; /* not comparable */
  a < aa; /* not int or char type */
  i = &a[5];
  a[5] = *i;
  i++; /* not int or char type */
  (*i)++;
  *i = bar(); /* LHS RHS error */
  i[1]; /* not array type */
  global_i[5]; /* not array type */
  global_c[3]; /* not arrray type */
  ptr_s[5]; /* not array type */
  s[3]; /* not array type */
  a[5];
  a[5+*i];
  a[5+s.a];
  a[5+*c]; /* not int type */
  a[c]; /* not int type */
  a[d]; /* not declared */
  ptr_s.a = *i; /* not struct type */
  ptr_s->a = *i;
  s.a = *i;
  s.a = i; /* LHS RHS error */
  returnIntFunc = s.a[1]; /* not array type */
  returnIntFunc = 1; /* LHS is not a variable */
  returnIntFunc() = 1; /* LHS is not variable */
  if (returnIntFunc() == 1)
    return i; 
  i == c; /* not comparable */
  s == c; /* not int or char type */
  s < s; /* not int or char type */
  *c < s.b;
  ptr_s->a || a[5];

  &a; /* not a variable */

  return; /* return type was not matched */
  return c; /* return type was not matched */
  return &a[3];
}