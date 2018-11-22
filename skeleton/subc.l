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
"int"			{ yylval.declptr = inttype;
						return TYPE; }
"char"		{ yylval.declptr = chartype;
						return TYPE; }
"void"		{ yylval.declptr = voidtype;
						return VOID; }
"NULL"		{ yylval.declptr = nulltype;
						return NULL_TOKEN; }
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


{integer-const}	{
								//printf("INT\t%s\n",yytext);
								yylval.intVal = atoi(yytext);
								return INTEGER_CONST;
							}
{operator}		{
								/* [TODO] remove here ??.... If remove, must add '.' , ';' operator. */
								//printf("OP\t%s\n",yytext);
								return yytext[0];
							}
{id}					{
								/* Determine the token type, and get the data */
								id* data = enter(UNDEFINED, yytext, strlen(yytext));

								/* Print the result */
								if (data->lexType == KEYWORD) {
									printf("KEY\t%s\t%d\n",data->name,data->count);
								}
								else if(data->lexType == ID_) {
									printf("ID\t%s\t%d\n",data->name,data->count);
									yylval.idptr = data;
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

int main(int argc, char** argv)
{
	/* initialize type decl */
	init_type();

	/*
	// [TODO] modify this??
	static char* keyWord[]={
		"auto","break","case","char","continue","default","do","else","extern","for","goto","if","int","register","return","sizeof","static","struct","switch","while", NULL
	};

	static int tokentype[] = { TYPE, 0 }; // [TODO] oh this field is for keyword token type!!!!!!
	int i;

	// Initilize Hash Tabel with Keywords
	for (i = 0; keyWord[i] != NULL; i++) {
		// [TODO] change 'KEYWORD' to 'tokentype[i]'.
		enter(KEYWORD, keyWord[i], strlen(keyWord[i]));
	}
	*/

	if(argc >= 2) yyin = fopen(argv[1], "r");
	else yyin = stdin;
	if(!yyin) {
		printf("Can't open input stream!\n");
		exit(1);
	}

	filename = argv[1];

	yyparse();
	fclose(yyin);
	return 0;
}
