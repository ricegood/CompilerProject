%{
/**************************************************************
* File Name   : subc.l
*
* Description
*	This is a skeleton input file to lex.
*
* Which tool to use
*	The GNU lex-clone, flex/flex++ is recommended to use.
*	It supports a C++ mode.
*	For any information about flex, refer to flex.man.
*
*	Good Luck!
*
***************************************************************/

/**************************************************************/
/* This section will appear at the head of lex.yy.c/lex.yy.cc */
/**************************************************************/

#include "subc.h"
#include "subc.tab.h"
static int comment_depth = 0;
static int lineno = 1;

%}

/* regular definitions */
/* [TODO] operator .. remove or not ? */
letter			[A-Za-z_]
digit			[0-9]
id				{letter}({letter}|{digit})*
integer-const	([1-9]{digit}*)|"0"
white-space		[ \t\n]+
special-char	\\[nt]
operator		("("|")"|"["|"]"|"{"|"}"|"->"|"."|","|".."|"!"|"~"|"++"|"--"|"*"|"/"|"%"|"+"|"-"|"<<"|">>"|"<"|"<="|">"|">="|"=="|"!="|"&"|"^"|"|"|"&&"|"||"|"?"|":"|";"|"="|"+="|"-="|"*="|"/="|"%="|"&="|"^="|"|="|"<<="|">>=")

%x COMMENT

%%
"int"|"char" { return TYPE; }
"void"		{ return VOID; }
"struct"	{ return STRUCT; }
"return"	{ return RETURN; }
"if"		{ return IF; }
"else"		{ return ELSE; }
"while"		{ return WHILE; }
"for"		{ return FOR; }
"break"		{ return BREAK; }
"continue"	{ return CONTINUE; }
"||"		{ return LOGICAL_OR; }
"&&"		{ return LOGICAL_AND; }
"<"|"<="|">"|">=" { return RELOP; }
"=="|"!="	{ return EQUOP; }
"++"		{ return INCOP; }
"--"		{ return DECOP; }
"->"		{ return STRUCTOP; }


{integer-const}				{
								//printf("INT\t%s\n",yytext);
								yylval.intVal = atoi(yytext);
								return INTEGER_CONST;
							}
{operator}					{
								/* [TODO] remove here ??.... If remove, must add '.' , ';' operator. */
								//printf("OP\t%s\n",yytext);
								return yytext[0];
							}
{id}						{
								/* Determine the token type, and get the data */
								id* data = enter(UNDEFINED, yytext, strlen(yytext));

								/* Print the result */
								if (data->lexType == KEYWORD) {
									//printf("KEY\t%s\t%d\n",data->name,data->count);
								}
								else if(data->lexType == ID_) {
									//printf("ID\t%s\t%d\n",data->name,data->count);
									yylval.idptr->lexType;
									/* [TODO] why is here [return entered->lextype] in the skeleton? */
									return ID;
								}
							}

\"({special-char}|[^\\\"\n])*\"	{
									/* String Variable */
									yylval.stringVal = yytext;
									return STRING;
								}
'({special-char}|[^\\'\n])'		{
									/* Character Variable */
									yylval.stringVal = yytext;
									return CHAR_CONST;
								}
","								{ return ','; }
";"								{ return yytext[0]; }
{white-space}					{}

<*>\n		   					++lineno;
<INITIAL,COMMENT>"/*"			{
									++comment_depth;
									BEGIN (COMMENT);
								}
<COMMENT>"*/"					if(--comment_depth == 0) BEGIN (INITIAL);
<COMMENT>.						{}

. 								{}

%%

int read_line()
{
   return lineno;
}

struct decl *maketypedecl(int typeclass) {
	printf("maketypedecl()\n");
}

void declare(struct id *id_ptr, struct decl *decl_ptr) {
	printf("declare()\n");
}

void init_type()
{
	printf("==init_type() START==\n");

	struct decl *inttype = maketypedecl(INT_);
	struct decl *chartype = maketypedecl(CHAR_);
	struct decl *voidtype = maketypedecl(VOID_);
	struct decl *structtype = maketypedecl(STRUCT_);
	struct decl *stringtype = maketypedecl(STRING_);
	struct decl *arraytype = maketypedecl(ARRAY_);
	struct decl *pointertype = maketypedecl(POINTER_);

	declare(enter(ID_, "int", 3), inttype);
	declare(enter(ID_, "char", 5), chartype);
	declare(enter(ID_, "void", 5), voidtype);
	declare(enter(ID_, "struct", 5), structtype);
	declare(enter(ID_, "string", 5), stringtype);
	declare(enter(ID_, "array", 5), arraytype);
	declare(enter(ID_, "pointer", 5), pointertype);

	enter(ID_, "*return", 7);

	printf("==init_type() END==\n");
}

int main(int argc, char** argv)
{
	/* initialize type decl */
	init_type();

	/* [TODO] modify this?? */
	static char* keyWord[]={
		"auto","break","case","char","continue","default","do","else","extern","for","goto","if","int","register","return","sizeof","static","struct","switch","while", NULL
	};

	static int tokentype[] = { TYPE, 0 }; // [TODO] oh this field is for keyword token type!!!!!!
	int i;

	/* Initilize Hash Tabel with Keywords */
	for (i = 0; keyWord[i] != NULL; i++) {
		/*[TODO] change 'KEYWORD' to 'tokentype[i]'. */
		enter(KEYWORD, keyWord[i], strlen(keyWord[i]));
	}

	if(argc >= 2) yyin = fopen(argv[1], "r");
	else yyin = stdin;
	if(!yyin) {
		printf("Can't open input stream!\n");
		exit(1);
	}
	
	yyparse();
	fclose(yyin);
	return 0;
}
