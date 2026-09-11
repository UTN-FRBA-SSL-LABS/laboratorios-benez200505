%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int  yylex(void);
void yyerror(const char *msg) { fprintf(stderr, "Error: %s\n", msg); }
%}

%token NUM
%token POW
%token UMINUS   /* token ficticio para el menos unario — ya declarado, no hay que tocarlo */

/*
 * Sin declaraciones de precedencia, esta gramática tiene múltiples
 * conflictos shift/reduce: Bison no sabe si "2 + 3 * 4" es
 * "(2+3)*4" o "2+(3*4)".
 *
 * Las declaraciones %left / %right resuelven esos conflictos:
 *   - Las que aparecen MÁS ABAJO tienen MAYOR precedencia.
 *   - %left  → asociatividad izquierda: a - b - c  se lee  (a-b)-c
 *   - %right → asociatividad derecha:  a ** b ** c se lee  a**(b**c)
 *   - UMINUS es un token ficticio para darle precedencia al menos unario.
 *     Se asigna a una regla con:  | '-' exp %prec UMINUS  { ... }
 */ /* <-- ACÁ FALTABA CERRAR EL COMENTARIO */

%left '+' '-'      /* Menor precedencia: suma y resta (asociatividad izquierda) */
%left '*' '/'      /* Mayor precedencia que suma/resta: mult y div */
%right POW         /* Mayor precedencia que mult/div: potencia (asociatividad derecha) */
%right UMINUS      /* Mayor precedencia de todas: menos unario (token ficticio) */

%%

input:
    /* vacío */
  | input linea
  ;

linea:
    exp '\n'   { printf("= %d\n", $1); }
  ;

exp:
    NUM                   { $$ = $1; }
  | exp '+' exp           { $$ = $1 + $3; }
  | exp '-' exp           { $$ = $1 - $3; }
  | exp '*' exp           { $$ = $1 * $3; }
  | exp '/' exp           { $$ = $1 / $3; }
  | exp POW exp           { $$ = pow($1, $3); }
  | '(' exp ')'           { $$ = $2; }
  | '-' exp %prec UMINUS  { $$ = -$2; }
;

%%

int main(void) {
    return yyparse();
}