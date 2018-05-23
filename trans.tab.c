/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "trans.y" /* yacc.c:339  */

/****************************************************************************
****************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "trad.h"
#include "comp.c"

//Variables globales
int   auxb;  //variable auxiliar para la lectura de booleanos 
int   auxint;  //variable auxiliar para la lectura de enteros
float auxn;  //variable auxiliar para la lectura de numeros
char  auxc[255];//variable auxiliar para la lectura de strings
char  auxt[255];//variable auxiliar para las traducciones
int auxtip=1;//variable auxiliar para los tipos de varias sentencias
NODO auxnodo1;//Variables para trabajar con la lista
NODO auxnodo2;
NODO *auxvar;
NODO *auxvar2;

#line 88 "trans.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "trans.tab.h".  */
#ifndef YY_YY_TRANS_TAB_H_INCLUDED
# define YY_YY_TRANS_TAB_H_INCLUDED
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
    TK_PROGRAM = 258,
    TK_CONST = 259,
    TK_MUL = 260,
    TK_DIV = 261,
    TK_VAR = 262,
    TK_SI = 263,
    TK_INICIO = 264,
    TK_ENTERO = 265,
    TK_REAL = 266,
    TK_BOOL = 267,
    TK_MIENTRAS = 268,
    TK_IGU = 269,
    TK_HAZ = 270,
    TK_RETORNO = 271,
    TK_ESCRIBIR = 272,
    TK_STRING = 273,
    TK_ARG = 274,
    TK_LIB = 275,
    TK_SWITCH = 276,
    TK_LEER = 277,
    TK_LLAMAR = 278,
    TK_FIN = 279,
    TK_MOD = 280,
    TK_HACER = 281,
    TK_INC = 282,
    TK_DEC = 283,
    TK_FUNCION = 284,
    TK_CONT = 285,
    TK_ARRAY = 286,
    TK_DEFAULT = 287,
    TK_HASTA = 288,
    TK_ELSE = 289,
    TK_PARA = 290,
    TK_CASO = 291,
    TK_COM = 292,
    TK_CADENA = 293,
    TK_NBOOL = 294,
    TK_NUM = 295,
    TK_ENT = 296,
    TK_VARIABLE = 297,
    TK_MEI = 298,
    TK_MAI = 299,
    TK_DIS = 300,
    TK_ASIG = 301,
    TK_OR = 302,
    TK_AND = 303,
    TK_NOT = 304,
    MENOSUNARIO = 305,
    TK_POW = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "trans.y" /* yacc.c:355  */

	struct NODO *indice; //puntero a la tabla de simbolos 
	struct elemento {
		char nombre[255]; //amacenar el nombre
		int escons; //nos dice si es o no constante 1->si 0->no 
		int espun; //nos dice si es o no puntero 1->si 0->no 
		int tipo; //tipo de variable
		int valbool; //tipo booleano
		double valnum;	//valor numerico	     
		int valint; //valor entero  
		char valstr[255]; //valor de tipo string
		char cad[255];//valor para las cadenas
		char trad[555];//almaceno la cadena de composicion de exp
		int vis; //variable para visualizar las constantes cadena correctamente	
		char res[255];//cadena para mostrar por pantalla
		int aux;//Variable para el índice del array
		} ELEMENTO;

#line 199 "trans.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TRANS_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 216 "trans.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   289

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      57,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      59,    58,     2,    50,    60,    51,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      47,    43,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    44,    45,
      46,    49,    52,    53,    54,    55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   120,   121,   125,   126,   131,   139,   148,
     152,   158,   169,   179,   189,   200,   211,   221,   231,   242,
     247,   251,   255,   259,   267,   271,   277,   287,   301,   310,
     316,   323,   332,   336,   344,   358,   376,   382,   393,   400,
     407,   417,   432,   439,   448,   454,   460,   464,   469,   475,
     483,   498,   513,   524,   534,   539,   558,   562,   573,   583,
     595,   608,   618,   632,   638,   649,   661,   709,   721,   731,
     742,   751,   759,   772,   786,   797,   801,   809,   816,   823,
     829,   835,   846,   865,   904,   910,   918,   927,   932,   937,
     944,   957,   966,   974,   987,   999,  1010,  1021,  1032,  1048,
    1062,  1081,  1093,  1104,  1117,  1128,  1140,  1151,  1164,  1178,
    1192,  1200,  1208,  1216,  1225,  1234
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PROGRAM", "TK_CONST", "TK_MUL",
  "TK_DIV", "TK_VAR", "TK_SI", "TK_INICIO", "TK_ENTERO", "TK_REAL",
  "TK_BOOL", "TK_MIENTRAS", "TK_IGU", "TK_HAZ", "TK_RETORNO",
  "TK_ESCRIBIR", "TK_STRING", "TK_ARG", "TK_LIB", "TK_SWITCH", "TK_LEER",
  "TK_LLAMAR", "TK_FIN", "TK_MOD", "TK_HACER", "TK_INC", "TK_DEC",
  "TK_FUNCION", "TK_CONT", "TK_ARRAY", "TK_DEFAULT", "TK_HASTA", "TK_ELSE",
  "TK_PARA", "TK_CASO", "TK_COM", "TK_CADENA", "TK_NBOOL", "TK_NUM",
  "TK_ENT", "TK_VARIABLE", "'='", "TK_MEI", "TK_MAI", "TK_DIS", "'<'",
  "'>'", "TK_ASIG", "'+'", "'-'", "TK_OR", "TK_AND", "TK_NOT",
  "MENOSUNARIO", "TK_POW", "'\\n'", "')'", "'('", "','", "'['", "']'",
  "$accept", "programa", "salto_lin", "salto_lin_dec", "cabecera",
  "librerias", "dec_constantes", "constante", "tipo", "dec_vbles",
  "variable", "array", "cuerpo", "funciones", "fun_dec", "funcion",
  "devolver", "dec_arg_fun", "argumento", "lista_sentencias", "sentencia",
  "asig_fun", "llamar_fun", "decre", "llamar_arg", "else", "control3",
  "control2", "control4", "control5", "control", "case", "cases",
  "default", "break", "cont", "final", "asignacion", "elemento_mostrar",
  "visual", "visual2", "lectura", "indice", "exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    61,   298,   299,   300,    60,    62,   301,
      43,    45,   302,   303,   304,   305,   306,    10,    41,    40,
      44,    91,    93
};
# endif

#define YYPACT_NINF -147

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-147)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,   -26,    30,  -147,    -3,  -147,    52,    -3,  -147,  -147,
      -3,    51,  -147,    22,    -3,    56,    11,  -147,    28,    -3,
      53,    -3,    -3,    -3,    -3,     8,  -147,   238,    31,    53,
      51,  -147,    22,    22,    22,    22,  -147,  -147,  -147,  -147,
    -147,   -16,   230,   230,   230,    24,    39,    25,    27,   230,
     230,    45,  -147,    29,    64,    -3,    33,    35,  -147,    63,
      63,    63,   -29,    70,  -147,  -147,  -147,  -147,  -147,    76,
    -147,  -147,  -147,  -147,  -147,  -147,    -3,  -147,  -147,  -147,
    -147,    29,   230,   230,   230,   197,   197,   197,    92,  -147,
      54,    55,   197,   197,    49,    58,    69,  -147,   238,    59,
    -147,  -147,   238,   238,   238,  -147,   230,   -29,  -147,   238,
    -147,  -147,    -3,    84,    28,  -147,    -8,    -8,   115,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,  -147,    65,    43,   197,    29,   -50,    81,
      62,    21,  -147,   -27,    93,  -147,  -147,   173,  -147,  -147,
      86,     8,    -3,  -147,  -147,    -8,    -8,   197,   197,   197,
     197,   197,   197,   197,    18,    18,    18,    -8,    -8,  -147,
     230,    77,  -147,   230,   103,  -147,  -147,   197,  -147,   230,
    -147,   238,  -147,  -147,     8,  -147,  -147,   238,    79,  -147,
     -21,   197,    97,    -5,  -147,  -147,   -16,    70,  -147,  -147,
     230,  -147,  -147,    -3,  -147,   197,    86,  -147
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     8,     4,     1,    10,     5,     7,     3,
       4,    25,     6,     0,     4,     0,     0,     9,     0,     4,
      36,     4,     4,     4,     4,     0,    24,     0,     0,     2,
      25,    32,    14,    13,    11,    12,    19,    20,    23,    21,
      22,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    92,     0,     4,     0,     0,    54,    80,
      80,    80,     0,     0,    44,    46,    47,    34,    33,    39,
      18,    17,    15,    16,    29,    28,     4,   114,   112,   110,
     111,    92,     0,     0,     0,    64,    65,    55,    89,    67,
       0,     0,    59,    60,     0,     0,     0,    31,    42,     0,
      49,    79,     0,     0,     0,    77,     0,    75,    72,     0,
      81,    45,     4,     0,    26,   115,    97,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,     0,    83,    92,     0,     0,
       0,     0,    43,     0,    68,    70,    71,     0,    76,    78,
       0,     0,     4,    27,   100,    95,    96,   106,    99,   104,
     103,   105,   101,   102,    93,    94,   108,   107,    98,    84,
       0,     0,    53,     0,     0,    91,    57,    82,    50,     0,
      63,     0,    78,    74,     0,    38,    37,     0,    88,    90,
       0,    61,     0,     0,    69,    73,    30,     0,    85,    52,
       0,    66,    51,     4,    35,    62,    40,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,   -10,   132,  -147,  -147,  -147,    44,  -146,   111,
      34,   -52,  -147,  -147,  -147,   116,  -147,  -147,   -59,   -62,
    -147,  -147,  -147,  -147,   -30,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,    46,  -147,   -28,   -39,   -45,  -147,   -14,  -147,
    -147,  -147,   -80,   -15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,     3,     6,    11,    17,    41,    15,
      26,    76,    20,    29,    30,    31,   152,   113,   185,    54,
      55,    56,    57,    58,   190,   181,    59,    60,    61,    62,
      63,   107,   108,   109,   183,   102,   111,    64,   134,    65,
     135,    66,    96,   136
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,   115,     1,   105,    18,   186,   121,   106,   172,    27,
     173,    32,    33,    34,    35,    74,     4,   122,    36,    37,
      38,   103,   104,   119,   120,    75,    39,    85,    86,    87,
       5,   178,   121,   179,    92,    93,   142,   199,   196,   200,
     144,   145,   146,   122,   176,    98,    40,   149,   132,    21,
      22,    23,    24,   202,     7,   200,    10,   171,    14,    77,
      78,    79,    80,    81,    16,    19,   114,   116,   117,   118,
      25,   131,    82,    67,   132,    83,    70,    71,    72,    73,
      84,    89,    28,    88,    90,   182,    91,    94,    97,   101,
      95,   147,    99,   100,   110,   112,   137,   138,   139,   140,
     151,   143,   150,   170,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   141,   194,
     119,   120,   174,   169,   175,   197,   177,   180,   184,   121,
      77,    78,    79,    80,    81,   189,   192,   198,   201,    12,
     122,    69,   187,    82,   203,    68,    83,   207,   153,   193,
     133,    84,   204,   148,   195,     0,   188,     0,   191,   123,
     124,   125,   126,   127,   191,   128,   129,   130,   131,     0,
       0,   132,     0,   154,     0,     0,     0,     0,   119,   120,
       0,    42,     0,     0,     0,   205,    43,   121,     0,    44,
      45,     0,     0,   206,    46,    47,    48,     0,   122,     0,
      49,    50,   119,   120,     0,     0,     0,     0,    51,     0,
      52,   121,     0,     0,     0,    53,     0,   123,   124,   125,
     126,   127,   122,   128,   129,   130,   131,     0,     0,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,   124,   125,   126,   127,    42,   128,   129,   130,
     131,    43,     0,   132,    44,    45,     0,     0,     0,    46,
      47,    48,     0,     0,     0,    49,    50,     0,    77,    78,
      79,    80,    81,    51,     0,    52,     0,     0,     0,     0,
      53,    82,     0,     0,    83,     0,     0,     0,     0,    84
};

static const yytype_int16 yycheck[] =
{
      10,    81,     3,    32,    14,   151,    14,    36,    58,    19,
      60,    21,    22,    23,    24,    31,    42,    25,    10,    11,
      12,    60,    61,     5,     6,    41,    18,    42,    43,    44,
       0,    58,    14,    60,    49,    50,    98,    58,   184,    60,
     102,   103,   104,    25,    23,    55,    38,   109,    56,    38,
      39,    40,    41,    58,    57,    60,     4,   137,     7,    38,
      39,    40,    41,    42,    42,     9,    76,    82,    83,    84,
      42,    53,    51,    42,    56,    54,    32,    33,    34,    35,
      59,    42,    29,    59,    59,   147,    59,    42,    24,    26,
      61,   106,    59,    58,    24,    19,    42,    42,    49,    41,
      16,    42,   112,    60,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    49,   181,
       5,     6,    41,    58,    62,   187,   141,    34,    42,    14,
      38,    39,    40,    41,    42,    58,    33,    58,    41,     7,
      25,    30,   152,    51,   196,    29,    54,   206,   114,   179,
      58,    59,   197,   107,   182,    -1,   170,    -1,   173,    44,
      45,    46,    47,    48,   179,    50,    51,    52,    53,    -1,
      -1,    56,    -1,    58,    -1,    -1,    -1,    -1,     5,     6,
      -1,     8,    -1,    -1,    -1,   200,    13,    14,    -1,    16,
      17,    -1,    -1,   203,    21,    22,    23,    -1,    25,    -1,
      27,    28,     5,     6,    -1,    -1,    -1,    -1,    35,    -1,
      37,    14,    -1,    -1,    -1,    42,    -1,    44,    45,    46,
      47,    48,    25,    50,    51,    52,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,     8,    50,    51,    52,
      53,    13,    -1,    56,    16,    17,    -1,    -1,    -1,    21,
      22,    23,    -1,    -1,    -1,    27,    28,    -1,    38,    39,
      40,    41,    42,    35,    -1,    37,    -1,    -1,    -1,    -1,
      42,    51,    -1,    -1,    54,    -1,    -1,    -1,    -1,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    64,    67,    42,     0,    68,    57,    65,    66,
       4,    69,    66,    65,     7,    72,    42,    70,    65,     9,
      75,    38,    39,    40,    41,    42,    73,    65,    29,    76,
      77,    78,    65,    65,    65,    65,    10,    11,    12,    18,
      38,    71,     8,    13,    16,    17,    21,    22,    23,    27,
      28,    35,    37,    42,    82,    83,    84,    85,    86,    89,
      90,    91,    92,    93,   100,   102,   104,    42,    78,    72,
      70,    70,    70,    70,    31,    41,    74,    38,    39,    40,
      41,    42,    51,    54,    59,   106,   106,   106,    59,    42,
      59,    59,   106,   106,    42,    61,   105,    24,    65,    59,
      58,    26,    98,    98,    98,    32,    36,    94,    95,    96,
      24,    99,    19,    80,    65,   105,   106,   106,   106,     5,
       6,    14,    25,    44,    45,    46,    47,    48,    50,    51,
      52,    53,    56,    58,   101,   103,   106,    42,    42,    49,
      41,    49,    82,    42,    82,    82,    82,   106,    95,    82,
      65,    16,    79,    73,    58,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,    58,
      60,   105,    58,    60,    41,    62,    23,   106,    58,    60,
      34,    88,    82,    97,    42,    81,    71,    65,   101,    58,
      87,   106,    33,    87,    82,    97,    71,    82,    58,    58,
      60,    41,    58,    74,    99,   106,    65,    81
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    67,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    72,    72,    73,    73,    74,    74,
      74,    75,    76,    76,    77,    78,    78,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    84,    85,    86,
      86,    87,    87,    88,    89,    90,    91,    92,    93,    93,
      93,    93,    93,    94,    94,    95,    95,    96,    97,    98,
      98,    99,   100,   101,   102,   102,   102,   103,   103,   103,
     104,   105,   105,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     0,     1,     2,     3,     0,     3,
       0,     3,     3,     3,     3,     4,     4,     4,     4,     1,
       1,     1,     1,     1,     3,     0,     4,     5,     1,     1,
       0,     4,     1,     2,     2,     7,     0,     2,     3,     0,
       4,     5,     2,     3,     1,     2,     1,     1,     1,     2,
       4,     6,     6,     4,     1,     2,     1,     4,     3,     2,
       2,     1,     3,     1,     2,     2,     6,     2,     3,     5,
       3,     3,     2,     4,     3,     1,     2,     1,     0,     1,
       0,     1,     4,     1,     4,     6,     3,     1,     3,     0,
       5,     3,     0,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     1,     1,     1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 102 "trans.y" /* yacc.c:1646  */
    {
		fprintf(salida,(yyvsp[-4].ELEMENTO).trad);
		fprintf(salida,(yyvsp[-3].ELEMENTO).trad);
		fprintf(salida,(yyvsp[0].ELEMENTO).trad);
		fprintf(salida,intr_cabecera());//Introducir el main después de las constantes
		fprintf(salida,(yyvsp[-2].ELEMENTO).trad);
		fprintf(salida,(yyvsp[-1].ELEMENTO).trad);
		
		/*		
		copiardatos(&auxnodo1,5,0,0,"",0,0,0,"final",0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
		*/
	}
#line 1477 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 120 "trans.y" /* yacc.c:1646  */
    {}
#line 1483 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 121 "trans.y" /* yacc.c:1646  */
    {}
#line 1489 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 125 "trans.y" /* yacc.c:1646  */
    {}
#line 1495 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 126 "trans.y" /* yacc.c:1646  */
    {}
#line 1501 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 132 "trans.y" /* yacc.c:1646  */
    {
		copiardatos(&auxnodo1,5,0,0,"",0,0,0,"main",0,0);
		copiardatos(&auxnodo2,5,0,0,"",0,0,0,"main",0,0);
		insertar(auxnodo1,auxnodo2,OP_DECL_FUN,auxvar);
	}
#line 1511 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 139 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"#include <stdio.h>\n#include <math.h>\n#include <stdlib.h>\n#include <string.h>\n");
	}
#line 1519 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 149 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1527 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 152 "trans.y" /* yacc.c:1646  */
    {		
	strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1535 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 159 "trans.y" /* yacc.c:1646  */
    { //Un número
		(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_num((yyvsp[-1].ELEMENTO).valnum,(yyvsp[-2].indice)->nombre)); //La traducción
		
		copiardatos(&auxnodo1,(yyvsp[-1].ELEMENTO).tipo,1,0,(yyvsp[-1].ELEMENTO).valstr,(yyvsp[-1].ELEMENTO).valbool,(yyvsp[-1].ELEMENTO).valnum,(yyvsp[-1].ELEMENTO).valint,(yyvsp[-2].indice)->nombre,0,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1547 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 170 "trans.y" /* yacc.c:1646  */
    { //Un número
		(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-1].ELEMENTO).valint,(yyvsp[-2].indice)->nombre)); //La traducción
		
		copiardatos(&auxnodo1,(yyvsp[-1].ELEMENTO).tipo,1,0,(yyvsp[-1].ELEMENTO).valstr,(yyvsp[-1].ELEMENTO).valbool,(yyvsp[-1].ELEMENTO).valnum,(yyvsp[-1].ELEMENTO).valint,(yyvsp[-2].indice)->nombre,0,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1559 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 180 "trans.y" /* yacc.c:1646  */
    { //Un número
		(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-1].ELEMENTO).valbool,(yyvsp[-2].indice)->nombre)); //La traducción
		
		
		copiardatos(&auxnodo1,(yyvsp[-1].ELEMENTO).tipo,1,0,(yyvsp[-1].ELEMENTO).valstr,(yyvsp[-1].ELEMENTO).valbool,(yyvsp[-1].ELEMENTO).valnum,(yyvsp[-1].ELEMENTO).valint,(yyvsp[-2].indice)->nombre,0,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1572 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 190 "trans.y" /* yacc.c:1646  */
    {//Constante cadena
		(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_cad((yyvsp[-1].ELEMENTO).cad,(yyvsp[-2].indice)->nombre)); //Traducción

		copiardatos(&auxnodo1,(yyvsp[-1].ELEMENTO).tipo,1,0,(yyvsp[-1].ELEMENTO).valstr,(yyvsp[-1].ELEMENTO).valbool,(yyvsp[-1].ELEMENTO).valnum,(yyvsp[-1].ELEMENTO).valint,(yyvsp[-2].indice)->nombre,0,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1584 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 201 "trans.y" /* yacc.c:1646  */
    { 
		(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_num((yyvsp[-2].ELEMENTO).valnum,(yyvsp[-3].indice)->nombre)); //Traducción
		
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,1,0,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre,0,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1596 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 212 "trans.y" /* yacc.c:1646  */
    { //Un número
		(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre)); //La traducción
		
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,1,0,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre,0,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1608 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 222 "trans.y" /* yacc.c:1646  */
    { //Un número
		(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-2].ELEMENTO).valbool,(yyvsp[-3].indice)->nombre)); //La traducción
		
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,1,0,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre,0,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1620 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 232 "trans.y" /* yacc.c:1646  */
    {
		(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_cad((yyvsp[-2].ELEMENTO).cad,(yyvsp[-3].indice)->nombre));  //Traducción

		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,1,0,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre,0,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1632 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 243 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=6; 
	}
#line 1640 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 248 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=1;}
#line 1647 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 252 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=4;
	}
#line 1655 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 256 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=4;
	}
#line 1663 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 260 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=3;
	}
#line 1671 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 268 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1679 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 271 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1687 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 278 "trans.y" /* yacc.c:1646  */
    {
		(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_variable((yyvsp[-2].ELEMENTO).tipo, (yyvsp[-3].indice)->nombre,(yyvsp[-1].ELEMENTO).espun,(yyvsp[-1].ELEMENTO).cad)); //Traducción
	
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,0,(yyvsp[-1].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre,0,(yyvsp[-1].ELEMENTO).aux);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1699 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 288 "trans.y" /* yacc.c:1646  */
    {
		(yyvsp[-4].indice)->tipo=(yyvsp[-3].ELEMENTO).tipo;

		strcpy((yyval.ELEMENTO).trad,intr_variable((yyvsp[-3].ELEMENTO).tipo, (yyvsp[-4].indice)->nombre,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).cad)); //Traducción
			
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
			
		copiardatos(&auxnodo1,(yyvsp[-3].ELEMENTO).tipo,0,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-3].ELEMENTO).valstr,(yyvsp[-3].ELEMENTO).valbool,(yyvsp[-3].ELEMENTO).valnum,(yyvsp[-3].ELEMENTO).valint,(yyvsp[-4].indice)->nombre,0,(yyvsp[-2].ELEMENTO).aux);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1714 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 302 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).espun=1;
		strcpy((yyval.ELEMENTO).cad,(yyvsp[0].ELEMENTO).trad);
		strcpy((yyval.ELEMENTO).trad,"[");
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcpy((yyval.ELEMENTO).trad,"]");
		(yyval.ELEMENTO).aux=(yyvsp[0].ELEMENTO).valint;
	}
#line 1727 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 311 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).espun=1;
		strcpy((yyval.ELEMENTO).trad,"*");
	}
#line 1736 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 316 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).espun=0;
	}
#line 1744 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 324 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"}\n");
	}
#line 1753 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 333 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1761 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 337 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 1770 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 345 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].indice)->nombre);
		
		auxvar=(yyvsp[0].indice);
		insertar_fun(auxvar,OP_FUN);
		
		copiardatos(&auxnodo1,5,0,0,"",0,0,0,(yyvsp[0].indice)->nombre,0,0);
		copiardatos(&auxnodo2,5,0,0,"",0,0,0,(yyvsp[0].indice)->nombre,0,0);
		insertar(auxnodo1,auxnodo2,OP_DECL_FUN,auxvar);
	}
#line 1785 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 359 "trans.y" /* yacc.c:1646  */
    {
		//printf("%s \n",$6.nombre);
		
		if((yyvsp[-3].ELEMENTO).tipo==1)
			strcpy((yyval.ELEMENTO).trad,"float ");
		if((yyvsp[-3].ELEMENTO).tipo==6||(yyvsp[-3].ELEMENTO).tipo==3)
			strcpy((yyval.ELEMENTO).trad,"int ");
		if((yyvsp[-3].ELEMENTO).tipo==2)
			strcpy((yyval.ELEMENTO).trad,"char *");
			
		strcat((yyval.ELEMENTO).trad,(yyvsp[-6].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-4].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"{\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1806 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 376 "trans.y" /* yacc.c:1646  */
    {//Puede no haber funciones
		strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1814 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 383 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=(yyvsp[0].ELEMENTO).tipo;
		
		copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,0,0,"",0,0,0,"devolver",0,0);
		insertar(auxnodo1,auxnodo2,OP_RETURN,auxvar);
	}
#line 1825 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 394 "trans.y" /* yacc.c:1646  */
    {	
		strcpy((yyval.ELEMENTO).trad,"(");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,")");
	}
#line 1835 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 400 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"(");
		strcat((yyval.ELEMENTO).trad,")");
	}
#line 1844 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 408 "trans.y" /* yacc.c:1646  */
    {
		(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		
		strcpy((yyval.ELEMENTO).trad,intr_argumento((yyvsp[-2].ELEMENTO).tipo, (yyvsp[-3].indice)->nombre,(yyvsp[-1].ELEMENTO).espun)); //Traducción

		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,0,(yyvsp[-1].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre,1,(yyvsp[-1].ELEMENTO).aux);
		insertar(auxnodo1,auxnodo2,OP_ARG,auxvar);
	}
#line 1857 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 418 "trans.y" /* yacc.c:1646  */
    {
		(yyvsp[-4].indice)->tipo=(yyvsp[-3].ELEMENTO).tipo;
		
		strcpy((yyval.ELEMENTO).trad,intr_argumento((yyvsp[-3].ELEMENTO).tipo, (yyvsp[-4].indice)->nombre,(yyvsp[-2].ELEMENTO).espun)); //Traducción
		strcat((yyval.ELEMENTO).trad,", ");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
				
		copiardatos(&auxnodo1,(yyvsp[-3].ELEMENTO).tipo,0,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-4].indice)->valstr,(yyvsp[-4].indice)->valbool,(yyvsp[-4].indice)->valnum,(yyvsp[-4].indice)->valint,(yyvsp[-4].indice)->nombre,1,(yyvsp[-2].ELEMENTO).aux);
		insertar(auxnodo1,auxnodo2,OP_ARG,auxvar);
	}
#line 1872 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 433 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);	
	}
#line 1880 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 440 "trans.y" /* yacc.c:1646  */
    {		
		 strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad); 
	}
#line 1888 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 449 "trans.y" /* yacc.c:1646  */
    {		
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);//Se limpia .trad
	}
#line 1896 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 455 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1905 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 460 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1913 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 464 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1921 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 470 "trans.y" /* yacc.c:1646  */
    {
		//printf("%s",$1.cad);
		strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1930 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 476 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"(");;
		strcat((yyval.ELEMENTO).trad,");\n");
	}
#line 1940 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 484 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-3].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].indice)->nombre);
		strcat((yyval.ELEMENTO).trad,"(");
		strcat((yyval.ELEMENTO).trad,");\n");
	
		strcpy(auxnodo1.nombre,(yyvsp[-1].indice)->nombre);
		strcpy(auxnodo2.nombre,(yyvsp[-3].ELEMENTO).nombre);
		auxnodo1.aux=(yyvsp[-3].ELEMENTO).aux;

		insertar(auxnodo1,auxnodo2,OP_ASIG_LLAMAR,auxvar);
	}
#line 1957 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 499 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-5].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-3].indice)->nombre);
		strcat((yyval.ELEMENTO).trad,"(");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
	
		strcpy(auxnodo1.nombre,(yyvsp[-3].indice)->nombre);
		strcpy(auxnodo2.nombre,(yyvsp[-5].ELEMENTO).nombre);
		auxnodo1.aux=(yyvsp[-5].ELEMENTO).aux;

		insertar(auxnodo1,auxnodo2,OP_ASIG_LLAMAR,auxvar);
	}
#line 1975 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 514 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-3].indice)->nombre);
		strcat((yyval.ELEMENTO).trad,"(");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
	
		strcpy(auxnodo1.nombre,(yyvsp[-3].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_LLAMAR,auxvar);
	}
#line 1989 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 525 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].indice)->nombre);
		strcat((yyval.ELEMENTO).trad,"(");
		strcat((yyval.ELEMENTO).trad,");\n");
	
		strcpy(auxnodo1.nombre,(yyvsp[-1].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_LLAMAR,auxvar);
	}
#line 2002 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 535 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2010 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 540 "trans.y" /* yacc.c:1646  */
    {	
		if((yyvsp[0].ELEMENTO).escons)	{
			strcpy((yyval.ELEMENTO).trad,"return ");
			strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
			strcat((yyval.ELEMENTO).trad,";\n");
		}else{
			strcpy((yyval.ELEMENTO).trad,"return ");
			strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).nombre);
			strcat((yyval.ELEMENTO).trad,";\n");		
		}
		copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
	
		insertar(auxnodo1,auxnodo2,OP_DEVOLVER,auxvar);
	}
#line 2029 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 559 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad,"");
	}
#line 2037 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 563 "trans.y" /* yacc.c:1646  */
    {	
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-3].indice)->nombre);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"=");
		(yyval.ELEMENTO).aux=(yyvsp[-2].ELEMENTO).aux;
		strcpy((yyval.ELEMENTO).nombre,(yyvsp[-3].indice)->nombre);
	}
#line 2049 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 574 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].indice)->nombre);
		strcpy(auxnodo1.nombre,(yyvsp[0].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_LLAMAR,auxvar);
	}
#line 2059 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 584 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).nombre);
		strcat((yyval.ELEMENTO).trad,"++;\n");
			
		strcpy(auxnodo1.nombre,(yyvsp[0].ELEMENTO).nombre);
		auxnodo1.tipo=(yyvsp[0].ELEMENTO).tipo;
	
		insertar(auxnodo1,auxnodo2,OP_INC,auxvar);
	}
#line 2073 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 596 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).nombre);
		strcat((yyval.ELEMENTO).trad,"--;\n");
	
		strcpy(auxnodo1.nombre,(yyvsp[0].ELEMENTO).nombre);
		auxnodo1.tipo=(yyvsp[0].ELEMENTO).tipo;
	
		insertar(auxnodo1,auxnodo2,OP_DEC,auxvar);
	}
#line 2087 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 609 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		if((yyvsp[0].ELEMENTO).espun)
			(yyvsp[0].ELEMENTO).tipo=2;
		
		copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,0,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
		insertar(auxnodo1,auxnodo2,OP_DECL_ARG,auxvar);
	}
#line 2101 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 619 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad,", ");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		if((yyvsp[0].ELEMENTO).espun)
			(yyvsp[0].ELEMENTO).tipo=2;
		
		copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,0,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
		insertar(auxnodo1,auxnodo2,OP_DECL_ARG,auxvar);
	}
#line 2116 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 633 "trans.y" /* yacc.c:1646  */
    {
		insertar(auxnodo1,auxnodo2,OP_ELSE,auxvar);
	}
#line 2124 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 639 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
			
		copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
	
		insertar(auxnodo1,auxnodo2,OP_SI,auxvar);
	}
#line 2136 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 650 "trans.y" /* yacc.c:1646  */
    {
	
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
	
		insertar(auxnodo1,auxnodo2,OP_WHILE,auxvar);
	}
#line 2149 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 662 "trans.y" /* yacc.c:1646  */
    {
		char signo[3]=">";
		char op[3];
		
		//Se comprueba si el valor objetivo es mayor o menor que el inicial para 
		//Hacer el for bien
		if(atoi((yyvsp[-2].ELEMENTO).trad)>atoi((yyvsp[0].ELEMENTO).trad)) {
			strcpy(signo,">");
			strcpy(op,"--");
			}
		else if(atoi((yyvsp[-2].ELEMENTO).trad)<atoi( (yyvsp[0].ELEMENTO).trad)) {
			strcpy(signo,"<");
			strcpy(op,"++");
			}
		else{
			strcpy(signo,"!=");
			strcpy(op," ");//Por poner algo
			}
		
		
		//No funciona esta forma así que se hace de la formas más larga.
		//snprintf($$.trad,"for (",$2->nombre,"=",$4.trad,";",$2->nombre,signo,$6.trad,";",$2->nombre,op,")");
		

		//Se escribe el for y se devuelve
		strcpy((yyval.ELEMENTO).trad,"for (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-4].indice)->nombre);
		strcat((yyval.ELEMENTO).trad,"=");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,";");		
		strcat((yyval.ELEMENTO).trad,(yyvsp[-4].indice)->nombre);
		strcat((yyval.ELEMENTO).trad,signo);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,";");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-4].indice)->nombre);
		strcat((yyval.ELEMENTO).trad,op);
		strcat((yyval.ELEMENTO).trad,")");
		
		auxvar=(yyvsp[-4].indice);
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,0);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,0);
	
		insertar_para(auxnodo1,auxnodo2,OP_PARA,auxvar);
	}
#line 2198 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 709 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).nombre,(yyvsp[0].indice)->nombre);
		(yyval.ELEMENTO).tipo=(yyvsp[0].indice)->tipo;
		
		copiardatos(&auxnodo1,(yyvsp[0].indice)->tipo,(yyvsp[0].indice)->escons,(yyvsp[0].indice)->espun,(yyvsp[0].indice)->valstr,(yyvsp[0].indice)->valbool,(yyvsp[0].indice)->valnum,(yyvsp[0].indice)->valint,(yyvsp[0].indice)->nombre,0,0);
		
		insertar(auxnodo1,auxnodo2,OP_SWITCH,auxvar);
	}
#line 2211 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 722 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"if (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,")\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2223 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 732 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"if (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-4].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,") {\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"} else {\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2236 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 743 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"while (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,") {\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2247 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 752 "trans.y" /* yacc.c:1646  */
    {		
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2257 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 760 "trans.y" /* yacc.c:1646  */
    {	
		
		//Si todo está bien se traduce y saca por pantalla
		
		strcpy((yyval.ELEMENTO).trad,"switch (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).nombre);
		strcat((yyval.ELEMENTO).trad,"){\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2271 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 773 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=(yyvsp[-2].ELEMENTO).tipo;
		
		strcpy((yyval.ELEMENTO).trad,"case ");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,":\n");		
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);		
		
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,0);
	
		insertar(auxnodo1,auxnodo2,OP_CASE,auxvar);
	}
#line 2289 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 787 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);		
		
		insertar(auxnodo1,auxnodo2,OP_DEFAULT,auxvar);
	}
#line 2301 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 798 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"");
	}
#line 2309 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 802 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 2318 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 810 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"default:\n");
	}
#line 2326 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 816 "trans.y" /* yacc.c:1646  */
    {
		//fprintf(salida,"break;\n");
		strcpy((yyval.ELEMENTO).trad,"break;\n");
	}
#line 2335 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 824 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"{\n");
	}
#line 2343 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 829 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"{\n");
	}
#line 2351 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 836 "trans.y" /* yacc.c:1646  */
    {
		//fprintf(salida,"}\n");
		strcpy((yyval.ELEMENTO).trad,"}\n");
		
		insertar(auxnodo1,auxnodo2,OP_FIN,auxvar);
	}
#line 2362 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 847 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad,(yyvsp[-3].indice)->nombre);
	strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
	strcat((yyval.ELEMENTO).trad,"=");
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	strcat((yyval.ELEMENTO).trad,";");
	strcat((yyval.ELEMENTO).trad,"\n");
	
	auxvar=(yyvsp[-3].indice);
	
	copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[-2].ELEMENTO).aux);
	
	insertar(auxnodo1,auxnodo2,OP_ASIGNAR,auxvar);
	}
#line 2381 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 866 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).vis=(yyvsp[0].ELEMENTO).vis;	
	(yyval.ELEMENTO).tipo=(yyvsp[0].ELEMENTO).tipo;
	
	if((yyvsp[0].ELEMENTO).tipo==2)
		printf("nombre:%s\n",(yyvsp[0].ELEMENTO).nombre);
	
	switch ((yyvsp[0].ELEMENTO).tipo){
	case 1: 
		strcpy((yyval.ELEMENTO).trad,"printf(\" %%f \\n\",");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
		break;
	case 3: 
		strcpy((yyval.ELEMENTO).trad,"printf(\" %%d \\n\",");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
		break;
	case 4: 
		strcpy((yyval.ELEMENTO).trad,"printf(\" %%s \\n\",");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
		break;
	case 6: 
		strcpy((yyval.ELEMENTO).trad,"printf(\" %%d \\n\",");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
		break;
	}//switch

	copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).cad,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
	
	insertar(auxnodo1,auxnodo2,OP_ESCRIBIR,auxvar);
}
#line 2420 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 905 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 2428 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 911 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-3].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 2437 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 919 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"printf(\"\\n\");");
		strcat((yyval.ELEMENTO).trad,"\n");
	}
#line 2446 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 928 "trans.y" /* yacc.c:1646  */
    {	
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2454 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 933 "trans.y" /* yacc.c:1646  */
    {	
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2463 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 937 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"");
	}
#line 2471 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 945 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,vis_entrada((yyvsp[-2].indice)->tipo,(yyvsp[-2].indice)->nombre,(yyvsp[-1].ELEMENTO).espun,(yyvsp[-1].ELEMENTO).cad));//Traducción
		
		auxvar=(yyvsp[-2].indice);
	
		copiardatos(&auxnodo1,(yyvsp[-2].indice)->tipo,(yyvsp[-2].indice)->escons,(yyvsp[-1].ELEMENTO).espun,(yyvsp[-2].indice)->cad,(yyvsp[-2].indice)->valbool,(yyvsp[-2].indice)->valnum,(yyvsp[-2].indice)->valint,(yyvsp[-2].indice)->nombre,0,(yyvsp[-1].ELEMENTO).aux);
	
		insertar(auxnodo1,auxnodo2,OP_LEER,auxvar);
	}
#line 2485 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 958 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"[");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"]");
		(yyval.ELEMENTO).aux=(yyvsp[-1].ELEMENTO).valint;
		(yyval.ELEMENTO).espun=1;
		strcpy((yyval.ELEMENTO).cad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 2498 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 966 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"");
		(yyval.ELEMENTO).espun=0;
	}
#line 2507 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 976 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," + ");//Traducción
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	
	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,(yyvsp[-2].ELEMENTO).aux);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);

	insertarexp(auxnodo1,auxnodo2,OP_SUMA);
	}
#line 2521 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 988 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," - ");//introducimos la cadena creada para la traduccion
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,(yyvsp[-2].ELEMENTO).aux);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
		insertarexp(auxnodo1,auxnodo2,OP_RESTA);
		
	}
#line 2535 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1000 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," * ");//Traducción
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,(yyvsp[-2].ELEMENTO).aux);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
		insertarexp(auxnodo1,auxnodo2,OP_MULT);
	}
#line 2548 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1011 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," / ");//Traducción
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,(yyvsp[-2].ELEMENTO).aux);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
		insertarexp(auxnodo1,auxnodo2,OP_DIV);
	}
#line 2561 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1022 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad," -");//introducimos la cadena creada para la traduccion
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

		copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
		insertarexp(auxnodo1,auxnodo2,OP_CAM);
	}
#line 2573 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1033 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad," pow");//Traducción
		strcpy(auxt,"(");
		strcat(auxt,(yyvsp[-2].ELEMENTO).trad);
		strcat(auxt,",");
		strcat(auxt,(yyvsp[0].ELEMENTO).trad);
		strcat(auxt,")");
		strcat((yyval.ELEMENTO).trad,auxt);

	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,(yyvsp[-2].ELEMENTO).aux);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
	insertarexp(auxnodo1,auxnodo2,OP_POW);
	}
#line 2591 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1049 "trans.y" /* yacc.c:1646  */
    {
		strcat(auxt,(yyvsp[-2].ELEMENTO).trad);
		strcat(auxt,"%");
		strcat(auxt,(yyvsp[0].ELEMENTO).trad);
		strcpy((yyval.ELEMENTO).trad,auxt);


		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,(yyvsp[-2].ELEMENTO).aux);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
		insertarexp(auxnodo1,auxnodo2,OP_MOD);
	}
#line 2607 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1063 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad,"(");//Traducción
	strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	strcat((yyval.ELEMENTO).trad,")");

	(yyval.ELEMENTO).tipo=(yyvsp[-1].ELEMENTO).tipo;
	(yyval.ELEMENTO).valnum = (yyvsp[-1].ELEMENTO).valnum;
	strcpy((yyval.ELEMENTO).valstr,(yyvsp[-1].ELEMENTO).valstr);
	strcpy((yyval.ELEMENTO).cad,(yyvsp[-1].ELEMENTO).cad);
	(yyval.ELEMENTO).valbool = (yyvsp[-1].ELEMENTO).valbool;
	(yyval.ELEMENTO).valint= (yyvsp[-1].ELEMENTO).valint;
	(yyval.ELEMENTO).espun= (yyvsp[-1].ELEMENTO).espun;
	(yyval.ELEMENTO).escons= (yyvsp[-1].ELEMENTO).escons;
	(yyval.ELEMENTO).aux= (yyvsp[-1].ELEMENTO).aux;
	}
#line 2627 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1082 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," < ");//Traducción
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	(yyval.ELEMENTO).tipo=3;

	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,(yyvsp[-2].ELEMENTO).aux);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
	insertarexp(auxnodo1,auxnodo2,OP_MENOR);
	}
#line 2641 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1094 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," > ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,(yyvsp[-2].ELEMENTO).aux);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
	insertarexp(auxnodo1,auxnodo2,OP_MAYOR);
	}
#line 2654 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1105 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," >= ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	(yyval.ELEMENTO).tipo=3;

	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,(yyvsp[-2].ELEMENTO).aux);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
	
	insertarexp(auxnodo1,auxnodo2,OP_MAI);
	}
#line 2669 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1118 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," <= ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,(yyvsp[-2].ELEMENTO).aux);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
	insertarexp(auxnodo1,auxnodo2,OP_MEI);                                
}
#line 2682 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1129 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," != ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	(yyval.ELEMENTO).tipo=3;
	
	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,(yyvsp[-2].ELEMENTO).aux);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
	insertarexp(auxnodo1,auxnodo2,OP_DESIGUALDAD);                                 
	}
#line 2696 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1141 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," == ");//introducimos la cadena creada para la traduccion
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		(yyval.ELEMENTO).tipo=3;
		
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,(yyvsp[-2].ELEMENTO).aux);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
		insertarexp(auxnodo1,auxnodo2,OP_IGUALDAD);
	}
#line 2710 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1153 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," && ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	(yyval.ELEMENTO).tipo=3;
	
	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,(yyvsp[-2].ELEMENTO).aux);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
	insertarexp(auxnodo1,auxnodo2,OP_AND);
	}
#line 2724 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1166 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," || ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	(yyval.ELEMENTO).tipo=3;
	
	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre,0,(yyvsp[-2].ELEMENTO).aux);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
	insertarexp(auxnodo1,auxnodo2,OP_OR);
	
	}
#line 2739 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1181 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad," !");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	(yyval.ELEMENTO).tipo=3;

	
	copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre,0,(yyvsp[0].ELEMENTO).aux);
	insertarexp(auxnodo1,auxnodo2,OP_NOT);	
	}
#line 2753 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1193 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=1;
		(yyval.ELEMENTO).escons=1;
		(yyval.ELEMENTO).valnum =(yyvsp[0].ELEMENTO).valnum;	  
	}
#line 2763 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1201 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=6;
		(yyval.ELEMENTO).escons=1;
		(yyval.ELEMENTO).valint =(yyvsp[0].ELEMENTO).valint;	
	}
#line 2773 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1209 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=3;
		(yyval.ELEMENTO).escons=1;
		(yyval.ELEMENTO).valbool= (yyvsp[0].ELEMENTO).valbool;
	}
#line 2783 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1217 "trans.y" /* yacc.c:1646  */
    {	
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].indice)->nombre);//copio el nombre de la variable para la traduccion
		strcpy((yyval.ELEMENTO).nombre,(yyvsp[0].indice)->nombre);//copio el nombre de la variable para la traduccion
		(yyval.ELEMENTO).tipo=(yyvsp[0].indice)->tipo;
		(yyval.ELEMENTO).escons=0;
	}
#line 2794 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1226 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=(yyvsp[0].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).valstr,(yyvsp[0].ELEMENTO).cad);
		strcpy((yyval.ELEMENTO).cad,(yyvsp[0].ELEMENTO).cad);
		(yyval.ELEMENTO).escons=(yyvsp[0].ELEMENTO).escons;
	}
#line 2805 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1235 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].indice)->nombre);//copio el nombre de la variable para la traduccion
		strcpy((yyval.ELEMENTO).nombre,(yyvsp[-1].indice)->nombre);//copio el nombre de la variable para la traduccion
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		(yyval.ELEMENTO).tipo=(yyvsp[-1].indice)->tipo;
		(yyval.ELEMENTO).escons=0;
		(yyval.ELEMENTO).espun=1;
		(yyval.ELEMENTO).aux=(yyvsp[0].ELEMENTO).aux;
	}
#line 2819 "trans.tab.c" /* yacc.c:1646  */
    break;


#line 2823 "trans.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 1245 "trans.y" /* yacc.c:1906  */

//////////////////////////////////////////////////////////////////////////////////////////////////
//Main, dónde se genera el fichero
int main(int argc, char **argv)
{     	
	if(argc==1) {
		printf("Se debe introducir: el fichero a analizar\n\n");
		exit(0);
	}//no se han introducido los parametros correctos	
	extern yyin;//se importa la variable yyin de lex        
	yyin = fopen (argv[1],"r");
	
	salida=fopen("salida.c","w");//creamos el fichero de salida de la traduccion
	salida=fopen("salida.c","a+"); //abrimos en modo para añadir
	yyparse();

	fclose(salida);//se cierra el fichero de salida
	
	com=NULL;
	fin=NULL;
	
	if(INICIO==NULL)
		printf("\nError, programa vacio.\n");
	else
		ejecutar(INICIO,0,"main");
		
	
	//listar(&com);
	//listar(&argini);
}

