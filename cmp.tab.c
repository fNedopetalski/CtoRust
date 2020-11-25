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

#line 110 "cmp.tab.c"

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
    OR = 272
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "cmp.y"

    char *nome;
    int valor;
    struct syntaticno *no;

#line 186 "cmp.tab.c"

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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

#define YYUNDEFTOK  2
#define YYMAXUTOK   272


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
       2,     2,     2,     2,     2,    24,     2,     2,     2,     2,
      20,    21,    31,    29,    28,    30,    26,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    19,
      25,    18,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    22,     2,    23,     2,     2,     2,     2,
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
      15,    16,    17
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    74,    79,    82,    91,    97,   105,   111,
     118,   123,   126,   135,   141,   147,   158,   165,   172,   177,
     180,   187,   188,   191,   196,   199,   204,   211,   212,   215,
     221,   224,   230,   234,   241,   247,   250,   257,   264,   271,
     277,   280,   286,   291,   292,   295,   300,   305,   308,   313,
     318,   321,   326,   330
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENT", "TINT", "TFLOAT",
  "RETURN", "STRUCT", "PRINT", "IF", "GEQUAL", "LEQUAL", "WHILE", "EQUAL",
  "DIFF", "AND", "OR", "'='", "';'", "'('", "')'", "'{'", "'}'", "'#'",
  "'<'", "'.'", "'>'", "','", "'+'", "'-'", "'*'", "'/'", "$accept",
  "prog", "stmtsF", "stmtF", "stmts", "stmt", "fields", "field", "type",
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
     265,   266,   267,   268,   269,   270,   271,   272,    61,    59,
      40,    41,   123,   125,    35,    60,    46,    62,    44,    43,
      45,    42,    47
};
# endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-44)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      34,   -67,   -67,   -15,     0,    15,    34,   -67,     6,    75,
       8,   -67,   -67,   108,    21,    75,    44,    46,    25,   -67,
      75,    51,   -67,    19,    33,   -67,   -67,    25,    45,     5,
     101,   -67,    58,   100,   -67,    47,   -67,    64,   -16,   -67,
     -67,    25,    25,    25,    25,    50,    48,   -67,   -67,    56,
     -67,   101,   101,   -67,   -67,   -67,   112,   -67,    73,    25,
      74,    82,    69,   -67,   116,    25,   110,    57,    57,   -67,
     -67,    70,   115,   -67,    57,   118,    10,   124,    97,    88,
     -67,   -67,   122,    25,   -67,   -67,   109,    42,   123,   -67,
      57,    57,    57,    57,    57,    57,    57,    57,   125,   127,
     -67,   112,   124,    97,    88,    88,   -67,   -67,   -67,   -67,
     112,   -67,    80,    91,   -67,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    21,    22,     0,     0,     0,     2,     4,     0,     0,
       0,     1,     3,     0,     0,    19,     0,     0,     0,     6,
       0,     0,    18,     0,     0,    52,    53,     0,     0,     0,
      47,    50,     0,     0,    24,     0,    20,     0,     0,     5,
      44,     0,     0,     0,     0,    25,     0,    23,     9,     0,
      51,    45,    46,    48,    49,    26,     0,     8,     0,     0,
       0,     0,     0,    11,     0,     0,     0,     0,     0,     7,
      10,     0,     0,    15,     0,     0,     0,    30,    32,    35,
      40,    42,     0,     0,    13,    14,     0,     0,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,    29,    31,    33,    34,    38,    39,    37,    36,
       0,    12,     0,     0,    16,    17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   138,   -64,   -61,   133,   -67,     3,   -67,
     117,    63,   -67,    59,   -66,    43,    13,   -18,   -25,    96,
      98
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    62,    63,    14,    15,    64,    33,
      34,    75,    76,    77,    78,    79,    80,    81,    29,    30,
      31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      28,    70,    38,     8,    10,    50,    40,     9,    86,     8,
      13,    89,    16,    41,    42,    11,   -43,   -43,    16,   -43,
     -43,   -43,   -43,    32,   -43,   103,   -43,    90,    25,    26,
     -43,   -27,   -43,    17,    41,    42,    32,   112,    36,     1,
       2,    66,     3,    40,    21,    27,   113,    72,    23,    87,
      24,    70,    70,   -43,   -43,    35,   -43,   -43,     4,    37,
      25,    26,    45,    50,    39,    99,    48,   -43,    49,   -43,
      56,    41,    42,    58,     1,     2,    59,    74,    55,    60,
       1,     2,    61,    57,    58,     1,     2,    59,    83,    84,
      60,    65,    69,    61,    67,    58,     1,     2,    59,    94,
      95,    60,    68,   114,    61,     1,     2,   106,   107,   108,
     109,    92,    93,    96,   115,    97,    58,     1,     2,    59,
      71,    46,    60,    92,    93,    61,    18,    19,    20,    73,
     100,    82,    43,    44,    85,   104,   105,    51,    52,    88,
      91,    53,    54,    98,    12,   101,   111,   110,    22,   102,
      47
};

static const yytype_int8 yycheck[] =
{
      18,    62,    27,     0,     4,    21,     1,    22,    74,     6,
       4,     1,     9,    29,    30,     0,    11,    12,    15,    14,
      15,    16,    17,    20,    19,    91,    21,    17,     3,     4,
      25,    21,    27,    25,    29,    30,    33,   101,    19,     5,
       6,    59,     8,     1,    23,    20,   110,    65,     4,    74,
       4,   112,   113,    11,    12,     4,    14,    15,    24,    26,
       3,     4,     4,    21,    19,    83,    19,    25,     4,    27,
      22,    29,    30,     4,     5,     6,     7,    20,    28,    10,
       5,     6,    13,    27,     4,     5,     6,     7,    18,    19,
      10,    18,    23,    13,    20,     4,     5,     6,     7,    11,
      12,    10,    20,    23,    13,     5,     6,    94,    95,    96,
      97,    14,    15,    25,    23,    27,     4,     5,     6,     7,
       4,    21,    10,    14,    15,    13,    18,    19,    20,    19,
      21,    68,    31,    32,    19,    92,    93,    41,    42,    21,
      16,    43,    44,    21,     6,    22,    19,    22,    15,    90,
      33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     8,    24,    34,    35,    36,    41,    22,
       4,     0,    36,     4,    39,    40,    41,    25,    18,    19,
      20,    23,    39,     4,     4,     3,     4,    20,    50,    51,
      52,    53,    41,    42,    43,     4,    19,    26,    51,    19,
       1,    29,    30,    31,    32,     4,    21,    43,    19,     4,
      21,    52,    52,    53,    53,    28,    22,    27,     4,     7,
      10,    13,    37,    38,    41,    18,    50,    20,    20,    23,
      38,     4,    50,    19,    20,    44,    45,    46,    47,    48,
      49,    50,    44,    18,    19,    19,    47,    51,    21,     1,
      17,    16,    14,    15,    11,    12,    25,    27,    21,    50,
      21,    22,    46,    47,    48,    48,    49,    49,    49,    49,
      22,    19,    37,    37,    23,    23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    36,    36,    36,
      37,    37,    38,    38,    38,    38,    38,    38,    39,    39,
      40,    41,    41,    42,    42,    43,    43,    44,    44,    45,
      45,    46,    46,    47,    47,    47,    48,    48,    48,    48,
      48,    49,    49,    50,    50,    51,    51,    51,    52,    52,
      52,    53,    53,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     5,     3,     8,     7,     6,
       2,     1,     5,     3,     4,     3,     7,     7,     2,     1,
       3,     1,     1,     2,     1,     2,     3,     1,     2,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     1,     1,     2,     3,     3,     1,     3,     3,
       1,     3,     1,     1
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
#line 63 "cmp.y"
                      { if (errorc > 0) 
                        printf("%d erro(s) encontrado(s)", errorc);
                    else {
                        printf("programa reconhecido\n");
                        syntaticno *root = novo_syntaticno(NO_INVALIDO, "prog", 1);
                        root->filhos[0] = (yyvsp[0].no);
                        debug(root);
                    }
                }
#line 1448 "cmp.tab.c"
    break;

  case 3:
#line 74 "cmp.y"
                      {
        (yyval.no) = novo_syntaticno(NO_STMTF, "stmtsF", 2);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1458 "cmp.tab.c"
    break;

  case 4:
#line 79 "cmp.y"
            { (yyval.no) = (yyvsp[0].no); }
#line 1464 "cmp.tab.c"
    break;

  case 5:
#line 82 "cmp.y"
                                {
        char aux[20];
        sprintf(aux, "%s", (yyvsp[-3].nome));
        (yyval.no) = novo_syntaticno(NO_VAR, strdup(aux), 2);
        (yyval.no)->filhos[0] = (yyvsp[-4].no);
        (yyval.no)->filhos[1] = (yyvsp[-1].no);
    }
#line 1476 "cmp.tab.c"
    break;

  case 6:
#line 91 "cmp.y"
                         {
        (yyval.no) = novo_syntaticno(NO_IDENT, (yyvsp[-1].nome), 1);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
    }
#line 1485 "cmp.tab.c"
    break;

  case 7:
#line 97 "cmp.y"
                                            {
        (yyval.no) = novo_syntaticno(NO_FUNCAO, (yyvsp[-6].nome), 3);
        (yyval.no)->filhos[0] = (yyvsp[-7].no);
        (yyval.no)->filhos[1] = (yyvsp[-4].no);
        (yyval.no)->filhos[2] = (yyvsp[-1].no);
    }
#line 1496 "cmp.tab.c"
    break;

  case 8:
#line 105 "cmp.y"
                                        {
        (yyval.no) = novo_syntaticno(NO_INCLUDE,"include", 1);
        (yyval.no)->filhos[0] = novo_syntaticno(NO_IDENT, (yyvsp[-3].nome), 0);
    }
#line 1505 "cmp.tab.c"
    break;

  case 9:
#line 111 "cmp.y"
                                      {
        (yyval.no) = novo_syntaticno(NO_STRUCT, "struct", 2);
        (yyval.no)->filhos[0] = novo_syntaticno(NO_IDENT, (yyvsp[-1].nome), 0);
        (yyval.no)->filhos[1] = (yyvsp[-3].no);
    }
#line 1515 "cmp.tab.c"
    break;

  case 10:
#line 118 "cmp.y"
                   {
        (yyval.no) = novo_syntaticno(NO_STMT, "stmts", 2);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1525 "cmp.tab.c"
    break;

  case 11:
#line 123 "cmp.y"
           { (yyval.no) = (yyvsp[0].no); }
#line 1531 "cmp.tab.c"
    break;

  case 12:
#line 126 "cmp.y"
                                {
        char aux[20];
        sprintf(aux, "%s", (yyvsp[-3].nome));
        (yyval.no) = novo_syntaticno(NO_VAR, strdup(aux), 2);
        (yyval.no)->filhos[0] = (yyvsp[-4].no);
        (yyval.no)->filhos[1] = (yyvsp[-1].no);
    }
#line 1543 "cmp.tab.c"
    break;

  case 13:
#line 135 "cmp.y"
                     {
        (yyval.no) = novo_syntaticno(NO_IDENT, (yyvsp[-1].nome), 1);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
    }
#line 1552 "cmp.tab.c"
    break;

  case 14:
#line 141 "cmp.y"
                        {
        (yyval.no) = novo_syntaticno(NO_RECEBE, (yyvsp[-3].nome), 1);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
    }
#line 1561 "cmp.tab.c"
    break;

  case 15:
#line 147 "cmp.y"
                      {
        (yyval.no) = novo_syntaticno(NO_RETURN, "return", 1);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
    }
#line 1570 "cmp.tab.c"
    break;

  case 16:
#line 158 "cmp.y"
                                    {
        (yyval.no) = novo_syntaticno(NO_IF, "if", 2);
        (yyval.no)->filhos[0] = (yyvsp[-4].no);
        (yyval.no)->filhos[1] = (yyvsp[-1].no);
    }
#line 1580 "cmp.tab.c"
    break;

  case 17:
#line 165 "cmp.y"
                                        {
        (yyval.no) = novo_syntaticno(NO_WHILE, "while", 2);
        (yyval.no)->filhos[0] = (yyvsp[-4].no);
        (yyval.no)->filhos[1] = (yyvsp[-1].no);
    }
#line 1590 "cmp.tab.c"
    break;

  case 18:
#line 172 "cmp.y"
                      {
        (yyval.no) = novo_syntaticno(NO_FIELDS, "fields", 2);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1600 "cmp.tab.c"
    break;

  case 19:
#line 177 "cmp.y"
            { (yyval.no) = (yyvsp[0].no); }
#line 1606 "cmp.tab.c"
    break;

  case 20:
#line 180 "cmp.y"
                       {
        (yyval.no) = novo_syntaticno(NO_FIELD,"field", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = novo_syntaticno(NO_ARGT, (yyvsp[-1].nome), 0);
    }
#line 1616 "cmp.tab.c"
    break;

  case 21:
#line 187 "cmp.y"
                    { (yyval.no) = novo_syntaticno(NO_TYPE, "int", 0); }
#line 1622 "cmp.tab.c"
    break;

  case 22:
#line 188 "cmp.y"
                    { (yyval.no) = novo_syntaticno(NO_TYPE, "float", 0); }
#line 1628 "cmp.tab.c"
    break;

  case 23:
#line 191 "cmp.y"
                {
        (yyval.no) = novo_syntaticno(NO_ARGS, "args", 2);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1638 "cmp.tab.c"
    break;

  case 24:
#line 196 "cmp.y"
          { (yyval.no) = (yyvsp[0].no); }
#line 1644 "cmp.tab.c"
    break;

  case 25:
#line 199 "cmp.y"
                 {
        (yyval.no) = novo_syntaticno(NO_ARG, "arg", 2);
        (yyval.no)->filhos[0] = (yyvsp[-1].no);
        (yyval.no)->filhos[1] = novo_syntaticno(NO_ARGT, (yyvsp[0].nome), 0);
    }
#line 1654 "cmp.tab.c"
    break;

  case 26:
#line 204 "cmp.y"
                     {
        (yyval.no) = novo_syntaticno(NO_ARG, "arg", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = novo_syntaticno(NO_ARGT, (yyvsp[-1].nome), 0);
    }
#line 1664 "cmp.tab.c"
    break;

  case 29:
#line 215 "cmp.y"
                           {
        (yyval.no) = novo_syntaticno(NO_OPERL,"or", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1674 "cmp.tab.c"
    break;

  case 30:
#line 221 "cmp.y"
               { (yyval.no) = (yyvsp[0].no); }
#line 1680 "cmp.tab.c"
    break;

  case 31:
#line 224 "cmp.y"
                            {
        (yyval.no) = novo_syntaticno(NO_OPERL,"and", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1690 "cmp.tab.c"
    break;

  case 32:
#line 230 "cmp.y"
             { (yyval.no) = (yyvsp[0].no); }
#line 1696 "cmp.tab.c"
    break;

  case 33:
#line 234 "cmp.y"
                          {
        (yyval.no) = novo_syntaticno(NO_OPERL,"==", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1706 "cmp.tab.c"
    break;

  case 34:
#line 241 "cmp.y"
                       {
        (yyval.no) = novo_syntaticno(NO_OPERL,"!=", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1716 "cmp.tab.c"
    break;

  case 35:
#line 247 "cmp.y"
                { (yyval.no) = (yyvsp[0].no); }
#line 1722 "cmp.tab.c"
    break;

  case 36:
#line 250 "cmp.y"
                          {
        (yyval.no) = novo_syntaticno(NO_OPERL,">", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1732 "cmp.tab.c"
    break;

  case 37:
#line 257 "cmp.y"
                        {
        (yyval.no) = novo_syntaticno(NO_OPERL,"<", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1742 "cmp.tab.c"
    break;

  case 38:
#line 264 "cmp.y"
                           {
        (yyval.no) = novo_syntaticno(NO_OPERL,">=", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1752 "cmp.tab.c"
    break;

  case 39:
#line 271 "cmp.y"
                           {
        (yyval.no) = novo_syntaticno(NO_OPERL,"<=", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1762 "cmp.tab.c"
    break;

  case 40:
#line 277 "cmp.y"
                { (yyval.no) = (yyvsp[0].no); }
#line 1768 "cmp.tab.c"
    break;

  case 41:
#line 280 "cmp.y"
                        {
			// $$ = novo_syntaticno("()", 1);
			// $$->filhos[0] = $2;
			(yyval.no) = (yyvsp[-1].no);
		 }
#line 1778 "cmp.tab.c"
    break;

  case 42:
#line 286 "cmp.y"
                       { (yyval.no) = (yyvsp[0].no); }
#line 1784 "cmp.tab.c"
    break;

  case 43:
#line 291 "cmp.y"
            { (yyval.no) = (yyvsp[0].no); }
#line 1790 "cmp.tab.c"
    break;

  case 45:
#line 295 "cmp.y"
                     {
        (yyval.no) = novo_syntaticno(NO_OPER, "+", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1800 "cmp.tab.c"
    break;

  case 46:
#line 300 "cmp.y"
                    {
        (yyval.no) = novo_syntaticno(NO_OPER, "-", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1810 "cmp.tab.c"
    break;

  case 47:
#line 305 "cmp.y"
           { (yyval.no) = (yyvsp[0].no); }
#line 1816 "cmp.tab.c"
    break;

  case 48:
#line 308 "cmp.y"
                       {
        (yyval.no) = novo_syntaticno(NO_OPER, "*", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
}
#line 1826 "cmp.tab.c"
    break;

  case 49:
#line 313 "cmp.y"
                      {
        (yyval.no) = novo_syntaticno(NO_OPER, "/", 2);
        (yyval.no)->filhos[0] = (yyvsp[-2].no);
        (yyval.no)->filhos[1] = (yyvsp[0].no);
    }
#line 1836 "cmp.tab.c"
    break;

  case 50:
#line 318 "cmp.y"
                    { (yyval.no) = (yyvsp[0].no); }
#line 1842 "cmp.tab.c"
    break;

  case 51:
#line 321 "cmp.y"
                      {
        // $$ = novo_syntaticno(/no"()", 1);
        // $$->filhos[0] = $2;
        (yyval.no) = (yyvsp[-1].no);
}
#line 1852 "cmp.tab.c"
    break;

  case 52:
#line 326 "cmp.y"
             {
        (yyval.no) = novo_syntaticno(NO_CONST, "const", 0);
        (yyval.no)->constvalue = (yyvsp[0].valor);
    }
#line 1861 "cmp.tab.c"
    break;

  case 53:
#line 330 "cmp.y"
            {
        simbolo *s = simbolo_existe((yyvsp[0].nome));
        if (!s)
            s = simbolo_novo((yyvsp[0].nome), IDENT);
        (yyval.no)  = novo_syntaticno(NO_IDENT, "IDENT", 0);
        (yyval.no)->sim = s;
    }
#line 1873 "cmp.tab.c"
    break;


#line 1877 "cmp.tab.c"

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
#line 339 "cmp.y"


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
