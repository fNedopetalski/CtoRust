%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int yyerror(const char *s);
int yylex(void);
int errorc = 0;
int level = 0;

typedef struct {
    char *nome;
    int token;
} simbolo;

enum TIPONO {NO_INVALIDO, NO_VAR, NO_INCLUDE, NO_FUNCAO, NO_RETURN,
    NO_STRUCT, NO_RECEBE, NO_IF, NO_WHILE, NO_CONST, NO_OPER, NO_OPERL,
    NO_ARG, NO_ARGS, NO_TYPE, NO_FIELD, NO_FIELDS, NO_IDENT, NO_STMT,
    NO_ARGT, NO_STMTF, NO_PAREM, NO_PRINT, NO_TYPEP, NO_PPRINT, NO_ELSE,
    NO_TYPEPP, NO_DFUNC, NO_ARGNT, NO_FLOAT, NO_COMMENT};

struct syntaticno {
    int id;
    enum TIPONO type;
    char *label;
    simbolo *sim;
    int constvalue;
    float floatvalue;
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
%token EQUAL DIFF AND OR T_INT T_FLOAT T_STRING T_CHAR ASPAS ELSE FLOAT COMMENT

%type <nome> IDENT COMMENT
%type <valor> NUMBER FLOAT
%type <no> prog arit expr term factor stmts stmt type typeP args arg fields 
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
    
    // comentario
    | COMMENT {
        $$ = novo_syntaticno(NO_COMMENT, $1, 0);
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

    // int d = exemplo(a,b);
    | type IDENT '=' IDENT '(' args ')' ';' {
        $$ = novo_syntaticno(NO_DFUNC, "funcDecl", 4);
        $$->filhos[0] = $1;
        $$->filhos[1] = novo_syntaticno(NO_PPRINT, $2, 0);
        $$->filhos[2] = novo_syntaticno(NO_PPRINT, $4, 0);
        $$->filhos[3] = $6;
    }

    // return 1;
    | RETURN arit ';' {
        $$ = novo_syntaticno(NO_RETURN, "return", 1);
        $$->filhos[0] = $2;
    }

    // printf()
    | PRINT '(' ASPAS typeP ASPAS ',' IDENT ')' ';' {
        $$ = novo_syntaticno(NO_PRINT, "print", 2);
        $$->filhos[0] = $4;
        $$->filhos[1] = novo_syntaticno(NO_PPRINT, $7, 0);
    }

    // comentario
    | COMMENT {
        $$ = novo_syntaticno(NO_COMMENT, $1, 0);
    }

    // if( arit ) { stmts }
    | IF '(' logic ')' '{' stmts '}'{
        $$ = novo_syntaticno(NO_IF, "if", 2);
        $$->filhos[0] = $3;
        $$->filhos[1] = $6;
    }

    // else { stmts }
    | ELSE '{' stmts '}' {
        $$ = novo_syntaticno(NO_ELSE, "else", 1);
        $$->filhos[0] = $3;
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

typeP: T_FLOAT      { $$ = novo_syntaticno(NO_TYPEP, "%f", 0); }
    | T_INT         { $$ = novo_syntaticno(NO_TYPEP, "%d", 0); }         
    | T_STRING      { $$ = novo_syntaticno(NO_TYPEP, "%s", 0); }         
    | T_CHAR        { $$ = novo_syntaticno(NO_TYPEP, "%c", 0); } 
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
    | IDENT {
        $$ = novo_syntaticno(NO_ARGNT, "arg", 1);
        $$->filhos[0] = novo_syntaticno(NO_PPRINT, $1, 0);
    }
    | IDENT ',' {
        $$ = novo_syntaticno(NO_ARGNT, "arg", 1);
        $$->filhos[0] = novo_syntaticno(NO_PPRINT, $1, 0);
    }
    ;

logic : exprOR;
    |   exprOR error;
    ;

exprOR : exprOR OR exprAND {
        $$ = novo_syntaticno(NO_OPERL,"||", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
    }

    | exprAND  { $$ = $1; }
    ;

exprAND : exprAND AND exprl {
        $$ = novo_syntaticno(NO_OPERL,"&&", 2);
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
			$$ = novo_syntaticno(NO_PAREM, "()", 1);
			$$->filhos[0] = $2;
			// $$ = $2;
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
        $$ = novo_syntaticno(NO_PAREM, "()", 1);
        $$->filhos[0] = $2;
        // $$ = $2;
    }
    | NUMBER {
        $$ = novo_syntaticno(NO_CONST, "const", 0);
        $$->constvalue = $1;
    }

    | FLOAT {
        $$ = novo_syntaticno(NO_FLOAT, "const", 0);
        $$->floatvalue = $1;
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
    printf("%c%s {", toupper(n->label[0]), n->label+1);
}

void tab(int level){
    for (int i = 0; i < level; i++)
        printf("\t");
}

void translate(syntaticno *n) {    

    switch (n->type)
    {

    case NO_PAREM:
        printf("(");
        translate(n->filhos[0]);
        printf(")");
        break;
    
    case NO_VAR:
        tab(level);
        if(level >= 1)
            printf("let mut %s: ", n->label);
        else {
            printf("static ");
            for (int i = 0; i < strlen(n->label); i++)
                printf("%c",toupper(n->label[i]));
            printf(": ");
        }
        translate(n->filhos[0]);
        printf(" = ");
        translate(n->filhos[1]);
        printf(";\n");
        break;

    case NO_COMMENT:
        tab(level);
        printf("%s",n->label);
        printf("\n");
        break;
    
    case NO_RECEBE:
        tab(level);
        printf("%s = ", n->label);
        translate(n->filhos[0]);
        printf(";\n\n");
        break;
    
    case NO_TYPE:
        if (n->label == "int")
            printf("u32 ");
        else if (n->label == "float")
            printf("f32 ");
        break;
    
    case NO_CONST:
        printf("%d", n->constvalue);
        break;

    case NO_FLOAT:
        printf("%f", n->floatvalue);
        break;

    case NO_INCLUDE:
        printf("use ");
        translate_include(n->filhos[0]);
        printf("\n");
        break;
    
    case NO_FUNCAO:
        if (strcmp(n->label, "main") == 0) {
            printf("fn main() {\n"); 
            level++;
            translate(n->filhos[2]);
            printf("\n}\n\n");
            level--;
        }
        else {
            printf("fn %s(",n->label);
            translate(n->filhos[1]);
            printf(") -> ");
            translate(n->filhos[0]);
            printf("{\n");
            level++;
            translate(n->filhos[2]);
            printf("\n}\n");
            level--;
        }
        break;

    case NO_DFUNC:
        tab(level);
        printf("let ");
        translate(n->filhos[1]);
        printf(": ");
        translate(n->filhos[0]);
        printf("= ");
        translate(n->filhos[2]);
        printf("(");
        translate(n->filhos[3]);
        printf(");\n");
        break;
    
    case NO_ARGS:
        translate(n->filhos[0]);
        printf(",");
        translate(n->filhos[1]);
        break;
    
    case NO_ARG:
        translate(n->filhos[1]);
        translate(n->filhos[0]);
        break;

    case NO_ARGNT:
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
        printf("\n");
        translate(n->filhos[1]);
        printf("}\n");
        break;

    case NO_FIELDS:
        translate(n->filhos[0]);
        translate(n->filhos[1]);
        break;
    
    case NO_FIELD:
        tab(level);
        translate(n->filhos[1]);
        translate(n->filhos[0]);
        printf(",\n");
        break;

    case NO_RETURN:
        tab(level);
        printf("%s ", n->label);
        translate(n->filhos[0]);
        break;

    case NO_IF:
        tab(level);
        printf("%s ", n->label);
        translate(n->filhos[0]);
        printf("{\n");
        level++;
        translate(n->filhos[1]);
        level--;
        printf("\n}\n");
        break;
    
    case NO_ELSE:
        tab(level);
        printf("%s {\n", n->label);
        level++;
        translate(n->filhos[0]);
        printf("\n}\n");
        level--;
        break;

    case NO_WHILE:
        tab(level);
        printf("%s ", n->label);
        translate(n->filhos[0]);
        printf("{\n");
        level++;
        translate(n->filhos[1]);
        printf("}\n");
        level--;
        break;

    case NO_TYPEP:
        if (n->label == "%d" || n->label == "%f")
            printf("{} ");
        break;
    
    case NO_PPRINT:
        printf("%s",n->label);
        break;

    case NO_PRINT:
        tab(level);
        printf("println!(\"");
        translate(n->filhos[0]);
        printf("\", ");
        translate(n->filhos[1]);
        printf(");\n");
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