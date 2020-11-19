%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
int yyerror(const char *s);
int yylex(void);
int errorc = 0;

typedef struct {
    char *nome;
    int token;
} simbolo;

struct syntaticno {
    int id;
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

%token NUMBER IDENT TINT TFLOAT RETURN

%type <nome> IDENT
%type <valor> NUMBER
%type <no> prog arit expr term factor stmts stmt type args arg


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

stmts : stmt stmts {
        $$ = novo_syntaticno("stmts", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $2;
    }
    | stmt { $$ = $1; }
    ;

stmt : type IDENT '=' arit ';' {
        char aux[20];
        sprintf(aux, "%s=", $2);
        $$ = novo_syntaticno(strdup(aux), 1);
        $$->filhos[0] = $4;
    }
    
    // variável sozinha
    | type IDENT ';' {
        $$ = novo_syntaticno($2, 0);
    }

    | type IDENT '(' args ')' '{' stmts '}' {
        $$ = novo_syntaticno("function", 2);
        $$->filhos[0] = $4;
        $$->filhos[1] = $7;
    }

    // #include <stdio.h>
    | '#' IDENT '<' IDENT '.' IDENT '>' {
        $$ = novo_syntaticno("include", 0);
    }

    | RETURN arit ';' {
        $$ = novo_syntaticno("return", 1);
        $$->filhos[0] = $2;
    }
    ;

type : TINT         { $$ = novo_syntaticno("int", 0); }
    | TFLOAT        { $$ = novo_syntaticno("float", 0); }
    ;

args : arg args {
        $$ = novo_syntaticno("args", 2);
        $$->filhos[0] = $1;
        $$->filhos[1] = $2;
    }

    | arg { $$ = $1; }
    ;

arg : type IDENT
    ;

arit : expr { $$ = $1; }
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
}

int main() {
    yyparse();
}