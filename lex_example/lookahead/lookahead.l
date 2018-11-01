letter	[A-Za-z*/]
ws	[ \t\n]
operator ["/"|"*"]
%%
{ws} { ; }
{operator} {printf("operator\n");}
"/*"[^*]*(\*)+([^*/][^*]*\*+)*"/" {printf("comment\n");}
. { printf("%s\n", yytext); }

%%

#include <stdio.h>
main(int argc, char ** argv)
{
	if (argc > 1) {
		FILE * file;
		file = fopen(argv[1], "r");
		if (!file) {
			fprintf(stderr, "could not open %s\n", argv[1]);
			exit(1);	
		} 
		yyin = file;
	}
	yylex();
	return 0;
}

