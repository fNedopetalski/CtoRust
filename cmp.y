%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int yyerror(const char *s);
int yylex(void);
int errorc = 0;
int level;

typedef struct {
    char *nome;
    int token;
} simbolo;

enum TIPONO {NO_INVALIDO, NO_VAR, NO_INCLUDE, NO_FUNCAO, NO_RETURN,
    NO_STRUCT, NO_RECEBE, NO_IF, NO_WHILE, NO_CONST, NO_OPER, NO_OPERL,
    NO_ARG, NO_ARGS, NO_TYPE, NO_FIELD, NO_FIELDS, NO_IDENT, NO_STMT,
    NO_ARGT, NO_STMTF};

struct syntaticno {
    int id;
    enum TIPONO type;
    char *label;
    simbolo *sim;
    int constvalue;
    int qtdfilhos;
    struct syntaticno *filhos[1]; //ultimo campo
};
typedef struct syntaticno syntaticno;

int simbolo_qtd = 0;
simbolo tsimbolos[100];
simbolo *simbolo_novo(char *nome, int token);
simbolo *simbolo_existe(char *nome);
syntaticno *novo_syntaticno(enum TIPONO type, char *label, int filhos);
void debug(syntaticno *root);
%}

%define parse.error verbose

/* atributos dos tokens */
%union {
    char *nome;
    int valor;
    struct syntaticno *no;
}

%token NUMBER IDENT TINT TFLOAT RETURN STRUCT PRINT IF GEQUAL LEQUAL WHILE
%token EQUAL DIFF AND OR

%type <nome> IDENT
%type <valor> NUMBER
%type <no> prog arit expr term factor stmts stmt type args arg fields 
%type <no> field exprOR exprAND exprl terml factorl logic stmtsF stmtF


%start prog

%%

prog : stmtsF         { if (errorc > 0) 
                        printf("%d erro(s) encontrado(s)", errorc);
                    else {
                        printf("programa reconhecido\n");
                        syntaticno *root = novo_syntaticno(NO_INVALIDO, "prog", 1);
                        root->filhos[0] = $1;
                        debug(root);
                    }
                }
    ;

stmtsF : stmtsF stmtF {
        $$ = novo_syntaticno(NO_STMTF, "stmtsF", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $2;
    }
    | stmtF { $$ = $1; }
    ;

stmtF : type IDENT '=' arit ';' {
        char aux[20];
        sprintf(aux, "%s", $2);
        $$ = novo_syntaticno(NO_VAR, strdup(aux), 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $4;
    }

        // variável sozinha
        | type IDENT ';' {
        $$ = novo_syntaticno(NO_IDENT, $2, 1);
        $$->filhos[0] = $1;
    }
    
    // int funcao (var) { stmts }
    | type IDENT '(' args ')' '{' stmts '}' {
        $$ = novo_syntaticno(NO_FUNCAO, $2, 3);
        $$->filhos[0] = $1;
        $$->filhos[1] = $4;
        $$->filhos[2] = $7;
    }

    // #include <stdio.h>
    | '#' IDENT '<' IDENT '.' IDENT '>' {
        $$ = novo_syntaticno(NO_INCLUDE,"include", 1);
        $$->filhos[0] = novo_syntaticno(NO_IDENT, $4, 0);
    }

    // struct { fields }
    | STRUCT '{' fields '}' IDENT ';' {
        $$ = novo_syntaticno(NO_STRUCT, "struct", 2);
        $$->filhos[0] = novo_syntaticno(NO_IDENT, $5, 0);
        $$->filhos[1] = $3;
    }
    ;

stmts : stmts stmt {
        $$ = novo_syntaticno(NO_STMT, "stmts", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $2;
    }
    | stmt { $$ = $1; }
    ;

stmt :  type IDENT '=' arit ';' {
        char aux[20];
        sprintf(aux, "%s", $2);
        $$ = novo_syntaticno(NO_VAR, strdup(aux), 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $4;
    }

    // variável sozinha
    | type IDENT ';' {
        $$ = novo_syntaticno(NO_IDENT, $2, 1);
        $$->filhos[0] = $1;
    }

        // c = a * b / d;
    |IDENT '=' arit ';' {
        $$ = novo_syntaticno(NO_RECEBE, $1, 1);
        $$->filhos[0] = $3;
    }

    // return 1;
    | RETURN arit ';' {
        $$ = novo_syntaticno(NO_RETURN, "return", 1);
        $$->filhos[0] = $2;
    }

    // printf()
    // | PRINT '(' '"' TYPE_IDENT '"' ',' IDENT ')' ';' {
    //     $$ = novo_syntaticno("print", 0);
    // }

    // if( arit ) { stmts }
    | IF '(' logic ')' '{' stmts '}'{
        $$ = novo_syntaticno(NO_IF, "if", 2);
        $$->filhos[0] = $3;
        $$->filhos[1] = $6;
    }

    // while ( cond ) { stmts }
    | WHILE '(' logic ')' '{' stmts '}' {
        $$ = novo_syntaticno(NO_WHILE, "while", 2);
        $$->filhos[0] = $3;
        $$->filhos[1] = $6;
    }
    ;

fields : field fields {
        $$ = novo_syntaticno(NO_FIELDS, "fields", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $2;
    }
    | field { $$ = $1; }
    ;

field : type IDENT ';' {
        $$ = novo_syntaticno(NO_FIELD,"field", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = novo_syntaticno(NO_ARGT, $2, 0);
    }
    ;

type : TINT         { $$ = novo_syntaticno(NO_TYPE, "int", 0); }
    | TFLOAT        { $$ = novo_syntaticno(NO_TYPE, "float", 0); }
    ;

args : args arg {
        $$ = novo_syntaticno(NO_ARGS, "args", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $2;
    }
    | arg { $$ = $1; }
    ;

arg : type IDENT {
        $$ = novo_syntaticno(NO_ARG, "arg", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = novo_syntaticno(NO_ARGT, $2, 0);
    }
    | type IDENT ',' {
        $$ = novo_syntaticno(NO_ARG, "arg", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = novo_syntaticno(NO_ARGT, $2, 0);
    }
    ;

logic : exprOR;
    |   exprOR error;
    ;

exprOR : exprOR OR exprAND {
        $$ = novo_syntaticno(NO_OPERL,"or", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
    }

    | exprAND  { $$ = $1; }
    ;

exprAND : exprAND AND exprl {
        $$ = novo_syntaticno(NO_OPERL,"and", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
    }

    | exprl  { $$ = $1; }
    ;

        // a == 30*21
exprl : exprl EQUAL terml {
        $$ = novo_syntaticno(NO_OPERL,"==", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
    }

    // a != 30*21
    | exprl DIFF terml {
        $$ = novo_syntaticno(NO_OPERL,"!=", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
    }
    
    | terml     { $$ = $1; }
    ;

terml : terml '>' factorl {
        $$ = novo_syntaticno(NO_OPERL,">", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
    }

    // a < 30*21
    | terml '<' factorl {
        $$ = novo_syntaticno(NO_OPERL,"<", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
    }

    // a >= 30*21
    | terml GEQUAL factorl {
        $$ = novo_syntaticno(NO_OPERL,">=", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
    }

    // a <= 30*21
    | terml LEQUAL factorl {
        $$ = novo_syntaticno(NO_OPERL,"<=", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
    }

    | factorl	{ $$ = $1; }
    ;

factorl : '(' exprl ')' {
			// $$ = novo_syntaticno("()", 1);
			// $$->filhos[0] = $2;
			$$ = $2;
		 }

		| arit { $$ = $1; }
		;



arit : expr { $$ = $1; }
    | expr error
    ;

expr : expr '+' term {
        $$ = novo_syntaticno(NO_OPER, "+", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
    }
    | expr '-' term {
        $$ = novo_syntaticno(NO_OPER, "-", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
    }
    | term { $$ = $1; }
    ;

term : term '*' factor {
        $$ = novo_syntaticno(NO_OPER, "*", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
}
    | term '/' factor {
        $$ = novo_syntaticno(NO_OPER, "/", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
    }
    | factor        { $$ = $1; }
    ;

factor : '(' expr ')' {
        // $$ = novo_syntaticno(/no"()", 1);
        // $$->filhos[0] = $2;
        $$ = $2;
}
    | NUMBER {
        $$ = novo_syntaticno(NO_CONST, "const", 0);
        $$->constvalue = $1;
    }
    | IDENT {
        simbolo *s = simbolo_existe($1);
        if (!s)
            s = simbolo_novo($1, IDENT);
        $$  = novo_syntaticno(NO_IDENT, "IDENT", 0);
        $$->sim = s;
    }
    ;

%%

int yywrap() {
    return 1;
}

int yyerror(const char *s) {
    errorc++;
    printf("erro %d: %s\n", errorc, s);
    return 1;
}

simbolo *simbolo_novo(char*nome, int token) {
    tsimbolos[simbolo_qtd].nome = nome;
    tsimbolos[simbolo_qtd].token = token;
    simbolo *result = &tsimbolos[simbolo_qtd];
    simbolo_qtd++;
    return result;
}

simbolo *simbolo_existe(char *nome) {
    // busca linear, nao eficiente
    for(int i = 0; i <simbolo_qtd; i++) {
        if (strcmp(tsimbolos[i].nome, nome) == 0)
            return &tsimbolos[i];
    }
    return NULL;
}

syntaticno *novo_syntaticno(enum TIPONO type, char *label, int filhos) {
    static int nid = 0;
    int s = sizeof(syntaticno);
    if (filhos > 1)
        s += sizeof(syntaticno*) * (filhos-1);
    syntaticno *n = (syntaticno*)calloc(1,s);
    n->id = nid++;
    n->type = type;
    n->label = label;
    n->qtdfilhos = filhos;
    return n;
}


void translate_include(syntaticno *n) {
    if (strcmp(n->label, "stdio") == 0)
        printf("std::io;\n");
    else
        printf("%s",n->label);
}


void translate_struct_name(syntaticno *n) {
    printf("%c%s {\n", toupper(n->label[0]), n->label+1);
}

void translate(syntaticno *n) {    

    switch (n->type)
    {
    case NO_VAR:
        printf("let mut %s: ", n->label);
        translate(n->filhos[0]);
        printf(" = ");
        translate(n->filhos[1]);
        printf(";\n");
        break;
    
    case NO_RECEBE:
         printf("%s = ", n->label);
        translate(n->filhos[0]);
        printf(";\n\n");
    
    case NO_TYPE:
        if (n->label == "int")
            printf("u32 ");
        else if (n->label == "float")
            printf("f32 ");
        break;
    
    case NO_CONST:
        printf("%d", n->constvalue);
        break;

    case NO_INCLUDE:
        printf("use ");
        translate_include(n->filhos[0]);
        printf("\n");
        break;
    
    case NO_FUNCAO:
        if (strcmp(n->label, "main") == 0) {
            printf("fn main() {\n\t");  
            translate(n->filhos[2]);
            printf("\n}\n\n");
        }
        else {
            printf("fn %s(",n->label);
            translate(n->filhos[1]);
            printf(") -> ");
            translate(n->filhos[0]);
            printf("{\n");
            translate(n->filhos[2]);
            printf("\n}\n");
        }
        break;
    
    case NO_ARGS:
        translate(n->filhos[0]);
        printf(", ");
        translate(n->filhos[1]);
        break;
    
    case NO_ARG:
        translate(n->filhos[1]);
        translate(n->filhos[0]);
        break;
    
    case NO_ARGT:
        printf("%s: ",n->label);
        break;

    case NO_OPER:
        translate(n->filhos[0]);
        printf("%s",n->label);
        translate(n->filhos[1]);
        break;
    
    case NO_OPERL:
        translate(n->filhos[0]);
        printf(" %s ", n->label);
        translate(n->filhos[1]);
        break;

    case NO_IDENT:
        printf("%s",n->sim->nome);
        break;

    case NO_STRUCT:
        printf("%s ",n->label);
        translate_struct_name(n->filhos[0]);
        translate(n->filhos[1]);
        printf("\n}\n");
        break;

    case NO_FIELDS:
        translate(n->filhos[0]);
        translate(n->filhos[1]);
        break;
    
    case NO_FIELD:
        translate(n->filhos[1]);
        translate(n->filhos[0]);
        printf(",\n");
        break;

    case NO_RETURN:
        printf("%s ", n->label);
        translate(n->filhos[0]);
        break;

    case NO_IF:
        printf("%s ", n->label);
        translate(n->filhos[0]);
        printf("{\n\t");
        translate(n->filhos[1]);
        printf("\n}\n");
        break;

    case NO_WHILE:
        printf("%s ", n->label);
        translate(n->filhos[0]);
        printf("{\n\t");
        translate(n->filhos[1]);
        printf("}\n");
        break;
    
    
    default:
        for(int i = 0; i < n->qtdfilhos; i++)
            translate(n->filhos[i]);
        break;
    }
}


void print_tree(syntaticno *n){

    if (n->sim)
        printf("\tn%d [label = \"%s\"];\n", n->id, n->sim->nome);
    else if(strcmp(n->label, "const") == 0)
        printf("\tn%d [label = \"%d\"];\n", n->id, n->constvalue);
    else
        printf("\tn%d [label = \"%s\"];\n", n->id, n->label);
        

    for(int i = 0; i < n->qtdfilhos; i++)
        print_tree(n->filhos[i]);
    for(int i = 0; i < n->qtdfilhos; i++)
        printf("\tn%d -- n%d\n", n->id, n->filhos[i]->id);
}

void debug(syntaticno *no) {
    printf("Simbolos: \n");
    for(int i = 0; i <simbolo_qtd; i++) {
        printf("\t%s\n", tsimbolos[i].nome);
    }
    /* graph prog { ... }*/
    printf("AST: \n");
    printf("graph prog {\n");
    print_tree(no);
    printf("}\n");

    translate(no);
}

int main() {
    yyparse();
}