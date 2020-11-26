
%{
#include "cmp.tab.h"
%}

%%
[ \t\n\r]           {}
"+"                 { return '+'; }
"-"                 { return '-'; }
"*"                 { return '*'; }
"/"                 { return '/'; }
"("                 { return '('; }
")"                 { return ')'; }
">"                 { return '>'; }
"<"                 { return '<'; }
"="                 { return '='; }
"\""                { return ASPAS; }
">="                { return GEQUAL; }
"<="                { return LEQUAL; }
"=="                { return EQUAL; }
"!="                { return DIFF; }
"&&"                { return AND; }
"||"                { return OR; }
"int"               { return TINT; }
"float"             { return TFLOAT; }
"return"            { return RETURN; }
"struct"            { return STRUCT; }
"printf"            { return PRINT; }
"if"                { return IF; }
"else"              { return ELSE; }
"while"             { return WHILE; }
"%d"                { return T_INT; }
"%f"                { return T_FLOAT; }
"%s"                { return T_STRING; }
"%c"                { return T_CHAR; }


[0-9]+ { 
    yylval.valor = atoi(yytext);
    return NUMBER; 
}
[0-9]+\.[0-9]+ { 
    yylval.valor = atoi(yytext);
    return FLOAT; 
}

[a-zA-Z_][a-zA-Z0-9_]*  {
    yylval.nome = strdup(yytext);
    return IDENT; 
}

.                   { return yytext[0]; }

%%

