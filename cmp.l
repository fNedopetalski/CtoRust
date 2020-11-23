
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
">="                { return GEQUAL; }
"<="                { return LEQUAL; }
"int"               { return TINT; }
"float"             { return TFLOAT; }
"return"            { return RETURN; }
"struct"            { return STRUCT; }
"printf"            { return PRINT; }
"if"                { return IF; }
"while"             { return WHILE; }


[0-9]+ { 
    yylval.valor = atoi(yytext);
    return NUMBER; 
}

[a-zA-Z_][a-zA-Z0-9_]*  {
    yylval.nome = strdup(yytext);
    return IDENT; 
}

.                   { return yytext[0]; }

%%

