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

letter			[A-Za-z_]
alnum			[A-Za-z0-9_]
digit			[0-9]
white-space		[ \t\n]
integer-constant(([1-9]+{digit}*)|0)
float-constant	{digit}+("."){digit}*([eE][+-]?{digit}+)?
operator		("("|")"|"["|"]"|"{"|"}"|"->"|"."|","|".."|"!"|"~"|"++"|"--"|"*"|"/"|"%"|"+"|"-"|"<<"|">>"|"<"|"<="|">"|">="|"=="|"!="|"&"|"^"|"|"|"&&"|"||"|"?"|":"|";"|"="|"+="|"-="|"*="|"/="|"%="|"&="|"^="|"|="|"<<="|">>=")
open-comment 	("/*")
close-comment 	("*/")
special-char	\\[nt]

%x COMMENT

%%
"int"|"char"|"float"|"double"|"short"|"long" { return TYPE; }
"struct" 	{ return STRUCT; }
"if"		{ return IF; }
"else"		{ return ELSE; }
"break"		{ return BREAK; }
"continue"	{ return CONTINUE; }
"=="		{ return EQUOP; }
"for"		{ return FOR; }
"&&"		{ return LOGICAL_AND; }
"||"		{ return LOGICAL_OR; }
"--"		{ return MINUS_MINUS; }
"++"		{ return PLUS_PLUS; }
"<"|"<="|">"|">="|"!=" { return RELOP; }
"return"	{ return RETURN; }
"while"		{ return WHILE; }

{integer-constant}			{
								  //printf("INT\t%s\n",yytext);
								  yylval.intVal = atoi(yytext);
								  return INTEGER_CONST;
								}
{integer-constant}/("..")	{
								  //printf("INT\t%s\n",yytext);
								  yylval.intVal = atoi(yytext);
								  return INTEGER_CONST;
								}
{float-constant}			{
								  //printf("F\t%s\n",yytext);
								}
{operator}					{
								  //printf("OP\t%s\n",yytext);
								  return yytext[0];
								}
{letter}+{alnum}*			{
								  /* Determine the token type, and get the data */
								  id* data = enter(UNDEFINED, yytext, strlen(yytext));

								  /* Print the result */
								  if (data->tokenType == KEYWORD) {
								  	// printf("KEY\t%s\t%d\n",data->name,data->count);
								  }
								  else if(data->tokenType == ID_) {
								  	// printf("ID\t%s\t%d\n",data->name,data->count);
								    yylval.stringVal = data->name;
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

<*>\n		   ++lineno;
<INITIAL,COMMENT>"/*"	{
		   ++comment_depth;
		   BEGIN (COMMENT);
		}
<COMMENT>"*/"	   if(--comment_depth == 0) BEGIN (INITIAL);
<COMMENT>.		 {}

{white-space}					{ ; }
. 								{ ; }

%%

int read_line()
{
   return lineno;
}

int main(int argc, char** argv)
{
   static char* keyWord[]={
		"auto","break","case","char","continue","default","do","double","else","extern","float","for","goto","if","int","long","register","return","short","sizeof","static","struct","switch","typedef","union","unsigned","void","while", "\0"
	};
   static int tokentype[] = { TYPE, 0 };
   int i;
   /* Initilize Hash Tabel with Keywords */
   for (i = 0; strcmp(keyWord[i], "\0") !=0; i++) {
      enter(KEYWORD, keyWord[i],strlen(keyWord[i]));
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
