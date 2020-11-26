/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "cmp.y"

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
    NO_TYPEPP, NO_DFUNC, NO_ARGNT, NO_FLOAT};

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

#line 112 "cmp.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_CMP_TAB_H_INCLUDED
# define YY_YY_CMP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    IDENT = 259,
    TINT = 260,
    TFLOAT = 261,
    RETURN = 262,
    STRUCT = 263,
    PRINT = 264,
    IF = 265,
    GEQUAL = 266,
    LEQUAL = 267,
    WHILE = 268,
    EQUAL = 269,
    DIFF = 270,
    AND = 271,
    OR = 272,
    T_INT = 273,
    T_FLOAT = 274,
    T_STRING = 275,
    T_CHAR = 276,
    ASPAS = 277,
    ELSE = 278,
    FLOAT = 279
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 46 "cmp.y"

    char *nome;
    int valor;
    struct syntaticno *no;

#line 195 "cmp.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CMP_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   203

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

#define YYUNDEFTOK  2
#define YYMAXUTOK   279


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    31,     2,     2,     2,     2,
      27,    28,    38,    36,    35,    37,    33,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    26,
      32,    25,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    30,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    76,    81,    84,    93,    99,   107,   113,
     119,   124,   127,   136,   142,   148,   157,   163,   170,   177,
     183,   190,   195,   198,   205,   206,   207,   208,   211,   212,
     215,   220,   223,   228,   233,   237,   243,   244,   247,   253,
     256,   262,   266,   273,   279,   282,   289,   296,   303,   309,
     312,   318,   323,   324,   327,   332,   337,   340,   345,   350,
     353,   358,   363,   368
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENT", "TINT", "TFLOAT",
  "RETURN", "STRUCT", "PRINT", "IF", "GEQUAL", "LEQUAL", "WHILE", "EQUAL",
  "DIFF", "AND", "OR", "T_INT", "T_FLOAT", "T_STRING", "T_CHAR", "ASPAS",
  "ELSE", "FLOAT", "'='", "';'", "'('", "')'", "'{'", "'}'", "'#'", "'<'",
  "'.'", "'>'", "','", "'+'", "'-'", "'*'", "'/'", "$accept", "prog",
  "stmtsF", "stmtF", "stmts", "stmt", "fields", "field", "typeP", "type",
  "args", "arg", "logic", "exprOR", "exprAND", "exprl", "terml", "factorl",
  "arit", "expr", "term", "factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    61,    59,    40,    41,   123,
     125,    35,    60,    46,    62,    44,    43,    45,    42,    47
};
# endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-53)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,   -75,   -75,   -17,    10,    22,     5,   -75,    29,    44,
      15,   -75,   -75,    -1,    26,    44,    41,    58,    13,   -75,
     146,    65,   -75,    57,    61,   -75,   -75,   -75,    13,    64,
      27,    39,   -75,    76,    88,   118,   -75,    71,   -75,    96,
      -7,   -75,   -75,    13,    13,    13,    13,   -75,    81,    90,
     -75,   -75,   132,   -75,    39,    39,   -75,   -75,   -75,   168,
     -75,   107,    13,   141,   142,   149,   150,    75,   -75,   166,
      13,   154,   160,    48,    48,   168,   -75,   -75,    83,   157,
     -75,   136,    48,   156,     6,   169,   111,   133,   -75,   -75,
     158,    97,    62,   -75,   -75,   -75,   -75,   -75,   -75,   165,
       4,    59,   159,   -75,    48,    48,    48,    48,    48,    48,
      48,    48,   161,   -75,   162,   167,   163,   -75,   168,   169,
     111,   133,   133,   -75,   -75,   -75,   -75,   168,   146,   -75,
     188,   108,   130,   143,   171,   -75,   -75,   170,   174,   -75,
     -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    28,    29,     0,     0,     0,     2,     4,     0,     0,
       0,     1,     3,     0,     0,    22,     0,     0,     0,     6,
       0,     0,    21,     0,     0,    61,    63,    62,     0,     0,
       0,    56,    59,    34,     0,     0,    31,     0,    23,     0,
       0,     5,    53,     0,     0,     0,     0,    35,    32,     0,
      30,     9,     0,    60,    54,    55,    57,    58,    33,     0,
       8,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,     0,     0,     0,     7,    10,     0,     0,
      16,     0,     0,     0,     0,    39,    41,    44,    49,    51,
       0,     0,     0,    13,    14,    25,    24,    26,    27,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    63,     0,     0,    50,     0,    38,
      40,    42,    43,    47,    48,    46,    45,     0,     0,    12,
       0,     0,     0,     0,     0,    18,    20,     0,     0,    15,
      17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   189,   -70,   -64,   179,   -75,   -75,     0,
      69,   -34,   127,   -75,    99,   -74,    23,    53,   -16,   -24,
      98,   113
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    67,    68,    14,    15,    99,    69,
      35,    36,    83,    84,    85,    86,    87,    88,    89,    30,
      31,    32
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       8,    50,    29,    77,    40,    91,     8,   103,   100,    16,
       1,     2,     9,     3,    10,    16,    25,    26,   106,   107,
      34,    53,    11,   104,    18,    19,    20,    77,    42,    43,
      44,   120,   117,    13,   -36,    34,     4,    27,   -52,   -52,
      28,   -52,   -52,   -52,   -52,    23,    71,    17,   131,     1,
       2,    25,    26,   -52,    79,   -52,    21,   132,   101,   -52,
      42,   -52,    24,    43,    44,    25,   114,    77,    77,    37,
     -52,   -52,    27,   -52,   -52,    82,   115,    45,    46,    61,
       1,     2,    62,    38,    63,    64,    27,    53,    65,    28,
      41,   -52,    48,   -52,    39,    43,    44,    51,    66,    50,
      52,    61,     1,     2,    62,    76,    63,    64,    92,    93,
      65,    47,    61,     1,     2,    62,    58,    63,    64,    59,
      66,    65,    33,     1,     2,   106,   107,   113,    34,   121,
     122,    66,    70,    34,    61,     1,     2,    62,   135,    63,
      64,    54,    55,    65,   108,   109,    49,    33,     1,     2,
      33,     1,     2,    66,    95,    96,    97,    98,    56,    57,
     136,   123,   124,   125,   126,   110,    60,   111,    72,    73,
      78,   137,    61,     1,     2,    62,    74,    63,    64,    75,
      80,    65,    81,    94,   102,   105,   112,   116,   118,   128,
     127,    66,   134,   129,    22,    12,   139,   133,   130,   138,
     140,    90,     0,   119
};

static const yytype_int16 yycheck[] =
{
       0,    35,    18,    67,    28,    75,     6,     1,    82,     9,
       5,     6,    29,     8,     4,    15,     3,     4,    14,    15,
      20,    28,     0,    17,    25,    26,    27,    91,     1,    36,
      37,   105,    28,     4,    28,    35,    31,    24,    11,    12,
      27,    14,    15,    16,    17,     4,    62,    32,   118,     5,
       6,     3,     4,    26,    70,    28,    30,   127,    82,    32,
       1,    34,     4,    36,    37,     3,     4,   131,   132,     4,
      11,    12,    24,    14,    15,    27,    92,    38,    39,     4,
       5,     6,     7,    26,     9,    10,    24,    28,    13,    27,
      26,    32,     4,    34,    33,    36,    37,    26,    23,   133,
       4,     4,     5,     6,     7,    30,     9,    10,    25,    26,
      13,    35,     4,     5,     6,     7,    35,     9,    10,    29,
      23,    13,     4,     5,     6,    14,    15,    30,   128,   106,
     107,    23,    25,   133,     4,     5,     6,     7,    30,     9,
      10,    43,    44,    13,    11,    12,    28,     4,     5,     6,
       4,     5,     6,    23,    18,    19,    20,    21,    45,    46,
      30,   108,   109,   110,   111,    32,    34,    34,    27,    27,
       4,    28,     4,     5,     6,     7,    27,     9,    10,    29,
      26,    13,    22,    26,    28,    16,    28,    22,    29,    27,
      29,    23,     4,    26,    15,     6,    26,   128,    35,    28,
      26,    74,    -1,   104
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     8,    31,    41,    42,    43,    49,    29,
       4,     0,    43,     4,    46,    47,    49,    32,    25,    26,
      27,    30,    46,     4,     4,     3,     4,    24,    27,    58,
      59,    60,    61,     4,    49,    50,    51,     4,    26,    33,
      59,    26,     1,    36,    37,    38,    39,    35,     4,    28,
      51,    26,     4,    28,    60,    60,    61,    61,    35,    29,
      34,     4,     7,     9,    10,    13,    23,    44,    45,    49,
      25,    58,    27,    27,    27,    29,    30,    45,     4,    58,
      26,    22,    27,    52,    53,    54,    55,    56,    57,    58,
      52,    44,    25,    26,    26,    18,    19,    20,    21,    48,
      55,    59,    28,     1,    17,    16,    14,    15,    11,    12,
      32,    34,    28,    30,     4,    58,    22,    28,    29,    54,
      55,    56,    56,    57,    57,    57,    57,    29,    27,    26,
      35,    44,    44,    50,     4,    30,    30,    28,    28,    26,
      26
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
      44,    44,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    46,    46,    47,    48,    48,    48,    48,    49,    49,
      50,    50,    51,    51,    51,    51,    52,    52,    53,    53,
      54,    54,    55,    55,    55,    56,    56,    56,    56,    56,
      57,    57,    58,    58,    59,    59,    59,    60,    60,    60,
      61,    61,    61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     5,     3,     8,     7,     6,
       2,     1,     5,     3,     4,     8,     3,     9,     7,     4,
       7,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     3,     1,     2,     1,     2,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     1,     1,     2,     3,     3,     1,     3,     3,     1,
       3,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 65 "cmp.y"
                      { if (errorc > 0) 
                        printf("%d erro(s) encontrado(s)", errorc);
                    else {
                        printf("programa reconhecido\n");
                        syntaticno *root = novo_syntaticno(NO_INVALIDO, "prog", 1);
                        root->filhos[0] = (yyvsp[0].no);
                        debug(root);
                    }
                }
#line 1480 "cmp.tab.c"
    break;

  case 3:
#line 76 "cmp.y"
                      {
        (yyval.no) = novo_syntaticno(NO_STMTF, "stmtsF", 2);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1490 "cmp.tab.c"
    break;

  case 4:
#line 81 "cmp.y"
            { (yyval.no) = (yyvsp[0].no); }
#line 1496 "cmp.tab.c"
    break;

  case 5:
#line 84 "cmp.y"
                                {
        char aux[20];
        sprintf(aux, "%s", (yyvsp[-3].nome));
        (yyval.no) = novo_syntaticno(NO_VAR, strdup(aux), 2);
        (yyval.no)->filhos[0] = (yyvsp[-4].no);
        (yyval.no)->filhos[1] = (yyvsp[-1].no);
    }
#line 1508 "cmp.tab.c"
    break;

  case 6:
#line 93 "cmp.y"
                         {
        (yyval.no) = novo_syntaticno(NO_IDENT, (yyvsp[-1].nome), 1);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
    }
#line 1517 "cmp.tab.c"
    break;

  case 7:
#line 99 "cmp.y"
                                            {
        (yyval.no) = novo_syntaticno(NO_FUNCAO, (yyvsp[-6].nome), 3);
        (yyval.no)->filhos[0] = (yyvsp[-7].no);
        (yyval.no)->filhos[1] = (yyvsp[-4].no);
        (yyval.no)->filhos[2] = (yyvsp[-1].no);
    }
#line 1528 "cmp.tab.c"
    break;

  case 8:
#line 107 "cmp.y"
                                        {
        (yyval.no) = novo_syntaticno(NO_INCLUDE,"include", 1);
        (yyval.no)->filhos[0] = novo_syntaticno(NO_IDENT, (yyvsp[-3].nome), 0);
    }
#line 1537 "cmp.tab.c"
    break;

  case 9:
#line 113 "cmp.y"
                                      {
        (yyval.no) = novo_syntaticno(NO_STRUCT, "struct", 2);
        (yyval.no)->filhos[0] = novo_syntaticno(NO_IDENT, (yyvsp[-1].nome), 0);
        (yyval.no)->filhos[1] = (yyvsp[-3].no);
    }
#line 1547 "cmp.tab.c"
    break;

  case 10:
#line 119 "cmp.y"
                   {
        (yyval.no) = novo_syntaticno(NO_STMT, "stmts", 2);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1557 "cmp.tab.c"
    break;

  case 11:
#line 124 "cmp.y"
           { (yyval.no) = (yyvsp[0].no); }
#line 1563 "cmp.tab.c"
    break;

  case 12:
#line 127 "cmp.y"
                                {
        char aux[20];
        sprintf(aux, "%s", (yyvsp[-3].nome));
        (yyval.no) = novo_syntaticno(NO_VAR, strdup(aux), 2);
        (yyval.no)->filhos[0] = (yyvsp[-4].no);
        (yyval.no)->filhos[1] = (yyvsp[-1].no);
    }
#line 1575 "cmp.tab.c"
    break;

  case 13:
#line 136 "cmp.y"
                     {
        (yyval.no) = novo_syntaticno(NO_IDENT, (yyvsp[-1].nome), 1);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
    }
#line 1584 "cmp.tab.c"
    break;

  case 14:
#line 142 "cmp.y"
                        {
        (yyval.no) = novo_syntaticno(NO_RECEBE, (yyvsp[-3].nome), 1);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
    }
#line 1593 "cmp.tab.c"
    break;

  case 15:
#line 148 "cmp.y"
                                            {
        (yyval.no) = novo_syntaticno(NO_DFUNC, "funcDecl", 4);
        (yyval.no)->filhos[0] = (yyvsp[-7].no);
        (yyval.no)->filhos[1] = novo_syntaticno(NO_PPRINT, (yyvsp[-6].nome), 0);
        (yyval.no)->filhos[2] = novo_syntaticno(NO_PPRINT, (yyvsp[-4].nome), 0);
        (yyval.no)->filhos[3] = (yyvsp[-2].no);
    }
#line 1605 "cmp.tab.c"
    break;

  case 16:
#line 157 "cmp.y"
                      {
        (yyval.no) = novo_syntaticno(NO_RETURN, "return", 1);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
    }
#line 1614 "cmp.tab.c"
    break;

  case 17:
#line 163 "cmp.y"
                                                    {
        (yyval.no) = novo_syntaticno(NO_PRINT, "print", 2);
        (yyval.no)->filhos[0] = (yyvsp[-5].no);
        (yyval.no)->filhos[1] = novo_syntaticno(NO_PPRINT, (yyvsp[-2].nome), 0);
    }
#line 1624 "cmp.tab.c"
    break;

  case 18:
#line 170 "cmp.y"
                                    {
        (yyval.no) = novo_syntaticno(NO_IF, "if", 2);
        (yyval.no)->filhos[0] = (yyvsp[-4].no);
        (yyval.no)->filhos[1] = (yyvsp[-1].no);
    }
#line 1634 "cmp.tab.c"
    break;

  case 19:
#line 177 "cmp.y"
                         {
        (yyval.no) = novo_syntaticno(NO_ELSE, "else", 1);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
    }
#line 1643 "cmp.tab.c"
    break;

  case 20:
#line 183 "cmp.y"
                                        {
        (yyval.no) = novo_syntaticno(NO_WHILE, "while", 2);
        (yyval.no)->filhos[0] = (yyvsp[-4].no);
        (yyval.no)->filhos[1] = (yyvsp[-1].no);
    }
#line 1653 "cmp.tab.c"
    break;

  case 21:
#line 190 "cmp.y"
                      {
        (yyval.no) = novo_syntaticno(NO_FIELDS, "fields", 2);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1663 "cmp.tab.c"
    break;

  case 22:
#line 195 "cmp.y"
            { (yyval.no) = (yyvsp[0].no); }
#line 1669 "cmp.tab.c"
    break;

  case 23:
#line 198 "cmp.y"
                       {
        (yyval.no) = novo_syntaticno(NO_FIELD,"field", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = novo_syntaticno(NO_ARGT, (yyvsp[-1].nome), 0);
    }
#line 1679 "cmp.tab.c"
    break;

  case 24:
#line 205 "cmp.y"
                    { (yyval.no) = novo_syntaticno(NO_TYPEP, "%f", 0); }
#line 1685 "cmp.tab.c"
    break;

  case 25:
#line 206 "cmp.y"
                    { (yyval.no) = novo_syntaticno(NO_TYPEP, "%d", 0); }
#line 1691 "cmp.tab.c"
    break;

  case 26:
#line 207 "cmp.y"
                    { (yyval.no) = novo_syntaticno(NO_TYPEP, "%s", 0); }
#line 1697 "cmp.tab.c"
    break;

  case 27:
#line 208 "cmp.y"
                    { (yyval.no) = novo_syntaticno(NO_TYPEP, "%c", 0); }
#line 1703 "cmp.tab.c"
    break;

  case 28:
#line 211 "cmp.y"
                    { (yyval.no) = novo_syntaticno(NO_TYPE, "int", 0); }
#line 1709 "cmp.tab.c"
    break;

  case 29:
#line 212 "cmp.y"
                    { (yyval.no) = novo_syntaticno(NO_TYPE, "float", 0); }
#line 1715 "cmp.tab.c"
    break;

  case 30:
#line 215 "cmp.y"
                {
        (yyval.no) = novo_syntaticno(NO_ARGS, "args", 2);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1725 "cmp.tab.c"
    break;

  case 31:
#line 220 "cmp.y"
          { (yyval.no) = (yyvsp[0].no); }
#line 1731 "cmp.tab.c"
    break;

  case 32:
#line 223 "cmp.y"
                 {
        (yyval.no) = novo_syntaticno(NO_ARG, "arg", 2);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
        (yyval.no)->filhos[1] = novo_syntaticno(NO_ARGT, (yyvsp[0].nome), 0);
    }
#line 1741 "cmp.tab.c"
    break;

  case 33:
#line 228 "cmp.y"
                     {
        (yyval.no) = novo_syntaticno(NO_ARG, "arg", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = novo_syntaticno(NO_ARGT, (yyvsp[-1].nome), 0);
    }
#line 1751 "cmp.tab.c"
    break;

  case 34:
#line 233 "cmp.y"
            {
        (yyval.no) = novo_syntaticno(NO_ARGNT, "arg", 1);
        (yyval.no)->filhos[0] = novo_syntaticno(NO_PPRINT, (yyvsp[0].nome), 0);
    }
#line 1760 "cmp.tab.c"
    break;

  case 35:
#line 237 "cmp.y"
                {
        (yyval.no) = novo_syntaticno(NO_ARGNT, "arg", 1);
        (yyval.no)->filhos[0] = novo_syntaticno(NO_PPRINT, (yyvsp[-1].nome), 0);
    }
#line 1769 "cmp.tab.c"
    break;

  case 38:
#line 247 "cmp.y"
                           {
        (yyval.no) = novo_syntaticno(NO_OPERL,"||", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1779 "cmp.tab.c"
    break;

  case 39:
#line 253 "cmp.y"
               { (yyval.no) = (yyvsp[0].no); }
#line 1785 "cmp.tab.c"
    break;

  case 40:
#line 256 "cmp.y"
                            {
        (yyval.no) = novo_syntaticno(NO_OPERL,"&&", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1795 "cmp.tab.c"
    break;

  case 41:
#line 262 "cmp.y"
             { (yyval.no) = (yyvsp[0].no); }
#line 1801 "cmp.tab.c"
    break;

  case 42:
#line 266 "cmp.y"
                          {
        (yyval.no) = novo_syntaticno(NO_OPERL,"==", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1811 "cmp.tab.c"
    break;

  case 43:
#line 273 "cmp.y"
                       {
        (yyval.no) = novo_syntaticno(NO_OPERL,"!=", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1821 "cmp.tab.c"
    break;

  case 44:
#line 279 "cmp.y"
                { (yyval.no) = (yyvsp[0].no); }
#line 1827 "cmp.tab.c"
    break;

  case 45:
#line 282 "cmp.y"
                          {
        (yyval.no) = novo_syntaticno(NO_OPERL,">", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1837 "cmp.tab.c"
    break;

  case 46:
#line 289 "cmp.y"
                        {
        (yyval.no) = novo_syntaticno(NO_OPERL,"<", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1847 "cmp.tab.c"
    break;

  case 47:
#line 296 "cmp.y"
                           {
        (yyval.no) = novo_syntaticno(NO_OPERL,">=", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1857 "cmp.tab.c"
    break;

  case 48:
#line 303 "cmp.y"
                           {
        (yyval.no) = novo_syntaticno(NO_OPERL,"<=", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1867 "cmp.tab.c"
    break;

  case 49:
#line 309 "cmp.y"
                { (yyval.no) = (yyvsp[0].no); }
#line 1873 "cmp.tab.c"
    break;

  case 50:
#line 312 "cmp.y"
                        {
			(yyval.no) = novo_syntaticno(NO_PAREM, "()", 1);
			(yyval.no)->filhos[0] = (yyvsp[-1].no);
			// $$ = $2;
		 }
#line 1883 "cmp.tab.c"
    break;

  case 51:
#line 318 "cmp.y"
                       { (yyval.no) = (yyvsp[0].no); }
#line 1889 "cmp.tab.c"
    break;

  case 52:
#line 323 "cmp.y"
            { (yyval.no) = (yyvsp[0].no); }
#line 1895 "cmp.tab.c"
    break;

  case 54:
#line 327 "cmp.y"
                     {
        (yyval.no) = novo_syntaticno(NO_OPER, "+", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1905 "cmp.tab.c"
    break;

  case 55:
#line 332 "cmp.y"
                    {
        (yyval.no) = novo_syntaticno(NO_OPER, "-", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1915 "cmp.tab.c"
    break;

  case 56:
#line 337 "cmp.y"
           { (yyval.no) = (yyvsp[0].no); }
#line 1921 "cmp.tab.c"
    break;

  case 57:
#line 340 "cmp.y"
                       {
        (yyval.no) = novo_syntaticno(NO_OPER, "*", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
}
#line 1931 "cmp.tab.c"
    break;

  case 58:
#line 345 "cmp.y"
                      {
        (yyval.no) = novo_syntaticno(NO_OPER, "/", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1941 "cmp.tab.c"
    break;

  case 59:
#line 350 "cmp.y"
                    { (yyval.no) = (yyvsp[0].no); }
#line 1947 "cmp.tab.c"
    break;

  case 60:
#line 353 "cmp.y"
                      {
        (yyval.no) = novo_syntaticno(NO_PAREM, "()", 1);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
        // $$ = $2;
    }
#line 1957 "cmp.tab.c"
    break;

  case 61:
#line 358 "cmp.y"
             {
        (yyval.no) = novo_syntaticno(NO_CONST, "const", 0);
        (yyval.no)->constvalue = (yyvsp[0].valor);
    }
#line 1966 "cmp.tab.c"
    break;

  case 62:
#line 363 "cmp.y"
            {
        (yyval.no) = novo_syntaticno(NO_FLOAT, "const", 0);
        (yyval.no)->floatvalue = (yyvsp[0].valor);
    }
#line 1975 "cmp.tab.c"
    break;

  case 63:
#line 368 "cmp.y"
            {
        simbolo *s = simbolo_existe((yyvsp[0].nome));
        if (!s)
            s = simbolo_novo((yyvsp[0].nome), IDENT);
        (yyval.no)  = novo_syntaticno(NO_IDENT, "IDENT", 0);
        (yyval.no)->sim = s;
    }
#line 1987 "cmp.tab.c"
    break;


#line 1991 "cmp.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 377 "cmp.y"


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

void translate(syntaticno *n) {    

    switch (n->type)
    {

    case NO_PAREM:
        printf("(");
        translate(n->filhos[0]);
        printf(")");
        break;

    case NO_VAR:
        for (int i = 0; i < level; i++)
            printf("\t");
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
    
    case NO_RECEBE:
        for (int i = 0; i < level; i++)
            printf("\t");
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
        for (int i = 0; i < level; i++)
            printf("\t");
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
        for (int i = 0; i < level; i++)
            printf("\t");
        translate(n->filhos[1]);
        translate(n->filhos[0]);
        printf(",\n");
        break;

    case NO_RETURN:
        for (int i = 0; i < level; i++)
            printf("\t");
        printf("%s ", n->label);
        translate(n->filhos[0]);
        break;

    case NO_IF:
        for (int i = 0; i < level; i++)
            printf("\t");
        printf("%s ", n->label);
        translate(n->filhos[0]);
        printf("{\n");
        level++;
        translate(n->filhos[1]);
        level--;
        printf("\n}\n");
        break;
    
    case NO_ELSE:
        for (int i = 0; i < level; i++)
            printf("\t");
        printf("%s {\n", n->label);
        level++;
        translate(n->filhos[0]);
        printf("\n}\n");
        level--;
        break;

    case NO_WHILE:
        for (int i = 0; i < level; i++)
            printf("\t");
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
        for (int i = 0; i < level; i++)
            printf("\t");
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
