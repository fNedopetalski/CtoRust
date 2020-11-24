%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int yyerror(const char *s);
int yylex(void);
int errorc = 0;

typedef struct {
    char *nome;
    int token;
} simbolo;

typedef enum TIPONO {NO_INVALIDO, NO_VAR, NO_INCLUDE, NO_FUNCAO, NO_RETURN,
    NO_STRUCT, NO_RECEBE, NO_IF, NO_WHILE}tipo;

struct syntaticno {
    int id;
    tipo type;
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
syntaticno *novo_syntaticno(char *label, int filhos);
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
%token EQUAL DIFF

%type <nome> IDENT
%type <valor> NUMBER
%type <no> prog arit expr term factor stmts stmt type args arg fields 
%type <no> field cond


%start prog

%%

prog : stmts         { if (errorc > 0) 
                        printf("%d erro(s) encontrado(s)", errorc);
                    else {
                        printf("programa reconhecido\n");
                        syntaticno *root = novo_syntaticno("prog", 1);
                        root->filhos[0] = $1;
                        debug(root);
                    }
                }
    ;

stmts : stmts stmt {
        $$ = novo_syntaticno("stmts", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $2;
    }
    | stmt { $$ = $1; }
    ;

stmt : type IDENT '=' arit ';' {
        char aux[20];
        sprintf(aux, "%s", $2);
        $$ = novo_syntaticno(strdup(aux), 2);
        $$->type = NO_VAR;
        $$->filhos[0] = $1;
        $$->filhos[1] = $4;
    }

    // c = a * b / d;
    | IDENT '=' arit ';' {
        $$ = novo_syntaticno($1, 1);
        $$->type = NO_RECEBE;
        $$->filhos[0] = $3;
    }
    
    // variável sozinha
    | type IDENT ';' {
        $$ = novo_syntaticno($2, 1);
        $$->filhos[0] = $1;
    }
    
    // int funcao (var) { stmts }
    | type IDENT '(' args ')' '{' stmts '}' {
        $$ = novo_syntaticno($2, 3);
        $$->filhos[0] = $1;
        $$->filhos[1] = $4;
        $$->filhos[2] = $7;
        $$->type = NO_FUNCAO;
    }

    // #include <stdio.h>
    | '#' IDENT '<' IDENT '.' IDENT '>' {
        $$ = novo_syntaticno("include", 1);
        $$->filhos[0] = novo_syntaticno($4, 0);
        $$->type = NO_INCLUDE;
    }

    // return 1;
    | RETURN arit ';' {
        $$ = novo_syntaticno("return", 1);
        $$->type = NO_RETURN;
        $$->filhos[0] = $2;
    }

    // struct { fields }
    | STRUCT '{' fields '}' IDENT ';' {
        $$ = novo_syntaticno("struct", 2);
        $$->filhos[0] = novo_syntaticno($5, 0);
        $$->filhos[1] = $3;
        $$->type = NO_STRUCT;
    }

    // printf()
    // | PRINT '(' '"' TYPE_IDENT '"' ',' IDENT ')' ';' {
    //     $$ = novo_syntaticno("print", 0);
    // }

    // if( arit ) { stmts }
    | IF '(' cond ')' '{' stmts '}'{
        $$ = novo_syntaticno("if", 2);
        $$->filhos[0] = $3;
        $$->filhos[1] = $6;
        $$->type = NO_IF;
    }

    // while ( cond ) { stmts }
    | WHILE '(' cond ')' '{' stmts '}' {
        $$ = novo_syntaticno("while", 2);
        $$->filhos[0] = $3;
        $$->filhos[1] = $6;
        $$->type = NO_WHILE;
    }
    ;

fields : field fields {
        $$ = novo_syntaticno("fields", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $2;
    }
    | field { $$ = $1; }
    ;

field : type IDENT ';' {
        $$ = novo_syntaticno("field", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = novo_syntaticno($2, 0);
    }
    ;

type : TINT         { $$ = novo_syntaticno("int", 0); }
    | TFLOAT        { $$ = novo_syntaticno("float", 0); }
    ;

args : args arg {
        $$ = novo_syntaticno("args", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $2;
    }
    | arg { $$ = $1; }
    ;

arg : type IDENT {
        $$ = novo_syntaticno("arg", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = novo_syntaticno($2, 0);
    }
    | type IDENT ',' {
        $$ = novo_syntaticno("arg", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = novo_syntaticno($2, 0);
    }
    ;


cond : IDENT '>' arit {
        $$ = novo_syntaticno(">", 2);
        $$->filhos[0] = novo_syntaticno($1, 0);
        $$->filhos[1] = $3;
    }

    // a < 30*21
    | IDENT '<' arit {
        $$ = novo_syntaticno("<", 2);
        $$->filhos[0] = novo_syntaticno($1, 0);
        $$->filhos[1] = $3;
    }

    // a >= 30*21
    | IDENT GEQUAL arit {
        $$ = novo_syntaticno(">=", 2);
        $$->filhos[0] = novo_syntaticno($1, 0);
        $$->filhos[1] = $3;
    }

    // a <= 30*21
    | IDENT LEQUAL arit {
        $$ = novo_syntaticno("<=", 2);
        $$->filhos[0] = novo_syntaticno($1, 0);
        $$->filhos[1] = $3;
    }

    // a == 30*21
    | IDENT EQUAL arit {
        $$ = novo_syntaticno("==", 2);
        $$->filhos[0] = novo_syntaticno($1, 0);
        $$->filhos[1] = $3;
    }

    // a != 30*21
    | IDENT DIFF arit {
        $$ = novo_syntaticno("!=", 2);
        $$->filhos[0] = novo_syntaticno($1, 0);
        $$->filhos[1] = $3;
    }
    ;

arit : expr { 
    $$ = $1; 
    $$->type = NO_RECEBE;
    }
    | expr error
    ;

expr : expr '+' term {
        $$ = novo_syntaticno("+", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
    }
    | expr '-' term {
        $$ = novo_syntaticno("-", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
    }
    | term { $$ = $1; }
    ;

term : term '*' factor {
        $$ = novo_syntaticno("*", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
}
    | term '/' factor {
        $$ = novo_syntaticno("/", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $3;
    }
    | factor        { $$ = $1; }
    ;

factor : '(' expr ')' {
        /*$$ = novo_syntaticno("()", 1);
        $$->filhos[0] = $2;*/
        $$ = $2;
}
    | NUMBER {
        $$ = novo_syntaticno("const", 0);
        $$->constvalue = $1;
    }
    | IDENT {
        simbolo *s = simbolo_existe($1);
        if (!s)
            s = simbolo_novo($1, IDENT);
        $$  = novo_syntaticno("IDENT", 0);
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

syntaticno *novo_syntaticno(char *label, int filhos) {
    static int nid = 0;
    int s = sizeof(syntaticno);
    if (filhos > 1)
        s += sizeof(syntaticno*) * (filhos-1);
    syntaticno *n = (syntaticno*)calloc(1,s);
    n->id = nid++;
    n->label = label;
    n->qtdfilhos = filhos;
    return n;
}


void translate_type (syntaticno *n){
    if (n->label == "int")
        printf("u32 ");
    else if (n->label == "float")
        printf("f32 ");
}

void translate_args(syntaticno *n){
    if(strcmp(n->label, "args") == 0){
        translate_args(n->filhos[0]);
        translate_args(n->filhos[1]);
    }
    else if(strcmp(n->label, "arg") == 0) {
        translate_args(n->filhos[1]);
        translate_type(n->filhos[0]);
    }
    else {
        printf("%s: ", n->label);
    }
}

void translate_include(syntaticno *n) {
    if (strcmp(n->label, "stdio") == 0)
        printf("std::io;\n");
}

void translate_arit(syntaticno *n) {
    if (n->label == "+" || n->label == "-" || n->label == "/" || n->label == "*") {
        translate_arit(n->filhos[0]);
        printf(" %s ",n->label);
        translate_arit(n->filhos[1]);
    }
    else if(n->constvalue)
        printf(" %d;\n", n->constvalue);
    else if(n->sim->nome)
        printf("%s", n->sim->nome);
    else if(n->label)
        printf("%s", n->label);
}

void translate_const(syntaticno *n) {
    if(n->constvalue)
        printf(" %d;\n", n->constvalue);
    else
        translate_arit(n);
}

void translate_func(syntaticno *n) {
    if (n->type == NO_RETURN) {
        printf("\treturn ");
        translate_arit(n->filhos[0]);
    }
    else {
        printf("%s" ,n->label);
    }
}

void translate_cond (syntaticno *n) {
    if(n->label == ">" || n->label == "<" || n->label == ">=" || n->label == "<=" || n->label == "==" || n->label == "!="){
        translate_cond(n->filhos[0]);
        printf(" %s ",n->label);
        translate_cond(n->filhos[1]);
    }
    else if(n->constvalue)
        printf("%d ", n->constvalue);
    else 
        printf("%s", n->label);
}

// void translate_while2(syntaticno *n){
//     if (n->label == "+" || n->label == "-" || n->label == "/" || n->label == "*") {
//         translate_while2(n->filhos[0]);
//         printf(" %s ",n->label);
//         translate_while2(n->filhos[1]);
//     }
//     else if(n->constvalue)
//         printf(" %d;\n", n->constvalue);
//     else 
//         printf("%s", n->label);
// }

// void translate_while(syntaticno *n) {
//     printf("%s = ", n->label);
//     translate_while2(n->filhos[0]);
//     printf("\n");
// }

void translate_struct_name(syntaticno *n) {
    printf("%c%s {\n", toupper(n->label[0]), n->label+1);
}

void translate_struct(syntaticno *n) {
    if(strcmp(n->label, "fields") == 0){
        translate_struct(n->filhos[0]);
        translate_struct(n->filhos[1]);
    }
    else if(strcmp(n->label, "field") == 0) {
        translate_struct(n->filhos[1]);
        translate_type(n->filhos[0]);
        printf(",\n");
    }
    else {
        printf("\t%s: ", n->label);
    }
}

void translate(syntaticno *n) {
    
    if (n->type == NO_VAR){
        printf("let %s: ", n->label);
        translate_type(n->filhos[0]);
        printf(" = ");
        translate_const(n->filhos[1]);
        printf("\n");
    }
    else if(n->type == NO_RECEBE) {
        printf("%s = ", n->label);
        translate_arit(n->filhos[0]);
        printf(";\n\n");
    }
    else if (n->type == NO_INCLUDE) {
        printf("use ");
        translate_include(n->filhos[0]);
        printf("\n");
    } 
    else if (n->type == NO_FUNCAO) {
        if (strcmp(n->label, "main") == 0) {
            printf("fn main() {\n");  
            translate(n->filhos[2]);
            printf("\n}\n\n");
        }
        else {
            printf("fn %s (", n->label);
            translate_args(n->filhos[1]);
            printf(") -> ");
            translate_type(n->filhos[0]);
            printf("{\n");
            
            translate_func(n->filhos[2]);
            printf("\n}\n\n");
        }
    }
    else if(n->type == NO_STRUCT) {
        printf("%s ",n->label);
        translate_struct_name(n->filhos[0]);
        translate_struct(n->filhos[1]);
        printf("}\n\n");
    }
    else if(n->type == NO_IF){
        printf("%s ", n->label);
        translate_cond(n->filhos[0]);
        printf("{\n");
        translate(n->filhos[1]);
        printf("\n}");
    }
    else if(n->type == NO_WHILE) {
        printf("%s ", n->label);
        translate_cond(n->filhos[0]);
        printf("{\n");
        translate(n->filhos[1]);
        printf("}\n");

    }
    else{
        for(int i = 0; i < n->qtdfilhos; i++)
            translate(n->filhos[i]);
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