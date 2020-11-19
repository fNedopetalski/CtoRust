
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
"int"               { return TINT; }
"float"             { return TFLOAT; }
"return"            { return RETURN; }

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

