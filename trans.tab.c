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
NODO *com;//Principio de la lista de śimbolos para la traducción
NODO *fin;//Final de la lista de śimbolos para la traducción
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

#line 90 "trans.tab.c" /* yacc.c:339  */

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
    TK_VAR = 260,
    TK_SI = 261,
    TK_INICIO = 262,
    TK_ENTERO = 263,
    TK_REAL = 264,
    TK_BOOL = 265,
    TK_MIENTRAS = 266,
    TK_IGU = 267,
    TK_HAZ = 268,
    TK_DIR = 269,
    TK_VAL = 270,
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
    TK_DEFAULT = 286,
    TK_HASTA = 287,
    TK_ELSE = 288,
    TK_PARA = 289,
    TK_CASO = 290,
    TK_COM = 291,
    TK_CADENA = 292,
    TK_NBOOL = 293,
    TK_NUM = 294,
    TK_ENT = 295,
    TK_VARIABLE = 296,
    TK_MEI = 297,
    TK_MAI = 298,
    TK_DIS = 299,
    TK_ASIG = 300,
    TK_OR = 301,
    TK_AND = 302,
    TK_NOT = 303,
    MENOSUNARIO = 304,
    TK_POW = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "trans.y" /* yacc.c:355  */

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
#define YYLAST   270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      58,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      61,    59,    52,    49,    60,    50,     2,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,    42,    47,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    43,    44,    45,
      48,    51,    54,    55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   118,   119,   123,   124,   129,   136,   145,
     149,   155,   166,   176,   186,   197,   208,   218,   228,   242,
     247,   251,   255,   259,   267,   271,   277,   287,   300,   305,
     312,   321,   325,   333,   346,   363,   370,   377,   384,   393,
     407,   414,   423,   429,   435,   439,   444,   450,   458,   466,
     473,   483,   494,   506,   510,   518,   524,   535,   547,   595,
     607,   617,   628,   637,   645,   658,   672,   683,   686,   694,
     701,   708,   714,   720,   731,   770,   773,   776,   783,   825,
     831,   839,   848,   855,   860,   869,   881,   895,   907,   918,
     929,   940,   956,   970,   988,  1000,  1011,  1024,  1035,  1047,
    1058,  1071,  1085,  1099,  1107,  1115,  1123,  1131,  1140,  1147
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PROGRAM", "TK_CONST", "TK_VAR",
  "TK_SI", "TK_INICIO", "TK_ENTERO", "TK_REAL", "TK_BOOL", "TK_MIENTRAS",
  "TK_IGU", "TK_HAZ", "TK_DIR", "TK_VAL", "TK_RETORNO", "TK_ESCRIBIR",
  "TK_STRING", "TK_ARG", "TK_LIB", "TK_SWITCH", "TK_LEER", "TK_LLAMAR",
  "TK_FIN", "TK_MOD", "TK_HACER", "TK_INC", "TK_DEC", "TK_FUNCION",
  "TK_CONT", "TK_DEFAULT", "TK_HASTA", "TK_ELSE", "TK_PARA", "TK_CASO",
  "TK_COM", "TK_CADENA", "TK_NBOOL", "TK_NUM", "TK_ENT", "TK_VARIABLE",
  "'='", "TK_MEI", "TK_MAI", "TK_DIS", "'<'", "'>'", "TK_ASIG", "'+'",
  "'-'", "TK_OR", "'*'", "'/'", "TK_AND", "TK_NOT", "MENOSUNARIO",
  "TK_POW", "'\\n'", "')'", "','", "'('", "$accept", "programa",
  "salto_lin", "salto_lin_dec", "cabecera", "librerias", "dec_constantes",
  "constante", "tipo", "dec_vbles", "variable", "puntero", "cuerpo",
  "funciones", "fun_dec", "funcion", "dec_arg_fun", "argumento",
  "lista_sentencias", "sentencia", "llamar_fun", "decre", "llamar_arg",
  "else", "control3", "control2", "control4", "control5", "control",
  "case", "cases", "default", "break", "cont", "final", "asignacion",
  "punteros_asignar", "elemento_mostrar", "visual", "visual2", "lectura",
  "exp", YY_NULLPTR
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
     295,   296,    61,   297,   298,   299,    60,    62,   300,    43,
      45,   301,    42,    47,   302,   303,   304,   305,    10,    41,
      44,    40
};
# endif

#define YYPACT_NINF -125

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-125)))

#define YYTABLE_NINF -78

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -31,    28,  -125,   -18,  -125,    37,   -18,  -125,  -125,
     -18,    41,  -125,     6,   -18,    45,    95,  -125,    12,   -18,
      19,   -18,   -18,   -18,   -18,    26,  -125,   234,    27,    19,
      54,  -125,     6,     6,     6,     6,  -125,  -125,  -125,  -125,
    -125,    59,    66,    66,  -125,  -125,    16,    34,    18,    21,
      66,    66,    42,  -125,    60,   -18,   -57,  -125,    74,    74,
      74,   -30,    77,  -125,    61,  -125,  -125,  -125,  -125,   -18,
      41,  -125,  -125,  -125,  -125,  -125,   -18,    66,    66,  -125,
    -125,  -125,  -125,  -125,    66,    66,    66,   156,   156,    17,
    -125,    67,    69,   156,   156,    63,  -125,   205,  -125,    66,
    -125,   234,   234,   234,  -125,    66,   -30,  -125,   234,  -125,
    -125,    65,    78,   106,    12,   156,   156,    14,    14,   139,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,  -125,    64,    76,   156,    70,  -125,
      98,  -125,   -42,   156,   125,  -125,  -125,   103,  -125,  -125,
       7,    26,  -125,    26,  -125,  -125,   156,   156,   156,   156,
     156,   156,   156,     8,     8,     8,    14,    14,    14,    14,
    -125,    66,  -125,   127,  -125,    66,  -125,   234,  -125,  -125,
      66,    59,   -18,   102,   122,   156,  -125,  -125,   156,   -18,
     234,  -125,  -125,    78,    77,  -125,  -125
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     8,     4,     1,    10,     5,     7,     3,
       4,    25,     6,     0,     4,     0,     0,     9,     0,     4,
      35,     4,     4,     4,     4,     0,    24,    77,     0,     2,
      37,    31,    14,    13,    11,    12,    19,    20,    23,    21,
      22,    29,     0,     0,    76,    75,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     4,     0,    49,    72,    72,
      72,     0,     0,    42,     0,    44,    45,    33,    32,     4,
      25,    18,    17,    15,    16,    28,     4,     0,     0,   107,
     105,   103,   104,   106,     0,     0,     0,    56,    57,    84,
      59,     0,     0,    51,    52,     0,    30,    40,    47,     0,
      71,    77,    77,    77,    69,     0,    67,    64,    77,    73,
      43,     0,     0,     0,    26,   109,   108,    90,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,    82,     0,    78,     0,    50,
       0,    41,     0,    53,    60,    62,    63,    77,    68,    70,
      77,     0,    36,     0,    27,    93,    99,    92,    97,    96,
      98,    94,    95,    86,    87,   101,    88,    89,   100,    91,
      79,     0,    85,     0,    48,     0,    55,    77,    70,    66,
       0,    29,     4,    83,     0,    54,    61,    65,    74,     4,
      77,    80,    58,    38,     0,    39,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,   -10,   158,  -125,  -125,  -125,   109,  -124,    93,
      52,   -14,  -125,  -125,  -125,   140,  -125,   -23,   -78,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
      68,  -125,    -7,   -22,   -21,  -125,    25,     5,  -125,  -125,
    -125,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,     3,     6,    11,    17,    41,    15,
      26,    76,    20,    29,    30,    31,    70,   152,    54,    55,
      56,    57,   142,   177,    58,    59,    60,    61,    62,   106,
     107,   108,   179,   101,   110,    63,    64,   135,    65,   136,
      66,   137
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,   104,    98,    99,    18,   105,     1,    87,    88,    27,
       4,    32,    33,    34,    35,    93,    94,   174,   175,   141,
     120,    44,    45,   144,   145,   146,   120,   181,     5,   182,
     149,    77,    78,   121,    36,    37,    38,   102,   103,   121,
       7,    10,   115,   116,    39,    97,    14,    16,    28,   117,
     118,   119,    19,    25,    79,    80,    81,    82,    83,   112,
     130,   131,   132,    40,   143,   133,   114,    84,    67,   178,
     147,   133,    85,    69,    75,    90,   134,    89,    86,    91,
      77,    78,    92,    95,    96,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   186,
     100,   109,   111,    79,    80,    81,    82,    83,   138,    42,
     139,   140,   194,   150,    43,   120,    84,    44,    45,   151,
      46,    85,   153,   170,    47,    48,    49,    86,   121,   172,
      50,    51,    21,    22,    23,    24,   171,    52,   173,    53,
     185,    71,    72,    73,    74,   188,   122,   123,   124,   125,
     126,   120,   127,   128,   129,   130,   131,   132,   176,   184,
     133,   191,   192,   113,   121,    12,   154,   189,   120,    68,
     195,   187,   190,   196,   148,   180,   183,     0,     0,   193,
       0,   121,   122,   123,   124,   125,   126,     0,   127,   128,
     129,   130,   131,   132,     0,     0,   133,     0,   155,   122,
     123,   124,   125,   126,     0,   127,   128,   129,   130,   131,
     132,    42,     0,   133,     0,     0,    43,     0,     0,    44,
      45,     0,    46,     0,     0,     0,    47,    48,    49,     0,
       0,     0,    50,    51,     0,     0,     0,     0,     0,    52,
      42,    53,     0,     0,     0,    43,   -77,     0,    44,    45,
       0,    46,     0,     0,     0,    47,    48,    49,     0,     0,
       0,    50,    51,     0,     0,     0,     0,     0,    52,     0,
      53
};

static const yytype_int16 yycheck[] =
{
      10,    31,    59,    60,    14,    35,     3,    42,    43,    19,
      41,    21,    22,    23,    24,    50,    51,    59,    60,    97,
      12,    14,    15,   101,   102,   103,    12,   151,     0,   153,
     108,    14,    15,    25,     8,     9,    10,    59,    60,    25,
      58,     4,    77,    78,    18,    55,     5,    41,    29,    84,
      85,    86,     7,    41,    37,    38,    39,    40,    41,    69,
      52,    53,    54,    37,    99,    57,    76,    50,    41,   147,
     105,    57,    55,    19,    15,    41,    59,    61,    61,    61,
      14,    15,    61,    41,    24,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   177,
      26,    24,    41,    37,    38,    39,    40,    41,    41,     6,
      41,    48,   190,    48,    11,    12,    50,    14,    15,    41,
      17,    55,    16,    59,    21,    22,    23,    61,    25,    59,
      27,    28,    37,    38,    39,    40,    60,    34,    40,    36,
     175,    32,    33,    34,    35,   180,    43,    44,    45,    46,
      47,    12,    49,    50,    51,    52,    53,    54,    33,    32,
      57,    59,    40,    70,    25,     7,   114,   181,    12,    29,
     193,   178,   182,   194,   106,   150,   171,    -1,    -1,   189,
      -1,    25,    43,    44,    45,    46,    47,    -1,    49,    50,
      51,    52,    53,    54,    -1,    -1,    57,    -1,    59,    43,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      54,     6,    -1,    57,    -1,    -1,    11,    -1,    -1,    14,
      15,    -1,    17,    -1,    -1,    -1,    21,    22,    23,    -1,
      -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    34,
       6,    36,    -1,    -1,    -1,    11,    41,    -1,    14,    15,
      -1,    17,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    63,    66,    41,     0,    67,    58,    64,    65,
       4,    68,    65,    64,     5,    71,    41,    69,    64,     7,
      74,    37,    38,    39,    40,    41,    72,    64,    29,    75,
      76,    77,    64,    64,    64,    64,     8,     9,    10,    18,
      37,    70,     6,    11,    14,    15,    17,    21,    22,    23,
      27,    28,    34,    36,    80,    81,    82,    83,    86,    87,
      88,    89,    90,    97,    98,   100,   102,    41,    77,    19,
      78,    69,    69,    69,    69,    15,    73,    14,    15,    37,
      38,    39,    40,    41,    50,    55,    61,   103,   103,    61,
      41,    61,    61,   103,   103,    41,    24,    64,    59,    60,
      26,    95,    95,    95,    31,    35,    91,    92,    93,    24,
      96,    41,    64,    71,    64,   103,   103,   103,   103,   103,
      12,    25,    43,    44,    45,    46,    47,    49,    50,    51,
      52,    53,    54,    57,    59,    99,   101,   103,    41,    41,
      48,    80,    84,   103,    80,    80,    80,   103,    92,    80,
      48,    41,    79,    16,    72,    59,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
      59,    60,    59,    40,    59,    60,    33,    85,    80,    94,
      98,    70,    70,    99,    32,   103,    80,    94,   103,    73,
      64,    59,    40,    64,    80,    79,    96
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    66,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    70,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    75,    75,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    83,    83,    84,    84,    85,    86,    87,    88,    89,
      90,    90,    90,    90,    90,    91,    91,    92,    92,    93,
      94,    95,    95,    96,    97,    98,    98,    98,    99,   100,
     100,   100,   101,   101,   101,   102,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     0,     1,     2,     3,     0,     3,
       0,     3,     3,     3,     3,     4,     4,     4,     4,     1,
       1,     1,     1,     1,     3,     0,     4,     5,     1,     0,
       4,     1,     2,     2,     8,     0,     3,     0,     4,     5,
       2,     3,     1,     2,     1,     1,     1,     2,     4,     1,
       3,     2,     2,     1,     3,     1,     2,     2,     6,     2,
       3,     5,     3,     3,     2,     4,     3,     1,     2,     1,
       0,     1,     0,     1,     5,     1,     1,     0,     1,     4,
       6,     3,     1,     3,     0,     4,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     1,     1,     2,     2
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
		
		copiardatos(&auxnodo1,5,0,0,"",0,0,0,"final");
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1467 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 118 "trans.y" /* yacc.c:1646  */
    {}
#line 1473 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 119 "trans.y" /* yacc.c:1646  */
    {}
#line 1479 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 123 "trans.y" /* yacc.c:1646  */
    {}
#line 1485 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 124 "trans.y" /* yacc.c:1646  */
    {}
#line 1491 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 130 "trans.y" /* yacc.c:1646  */
    {
		copiardatos(&auxnodo1,5,0,0,"",0,0,0,"main");
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1500 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 136 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"#include <stdio.h>\n#include <math.h>\n#include <stdlib.h>\n#include <string.h>\n");
	}
#line 1508 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 146 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1516 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 149 "trans.y" /* yacc.c:1646  */
    {		
	strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1524 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 156 "trans.y" /* yacc.c:1646  */
    { //Un número
		(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_num((yyvsp[-1].ELEMENTO).valnum,(yyvsp[-2].indice)->nombre)); //La traducción
		
		copiardatos(&auxnodo1,(yyvsp[-1].ELEMENTO).tipo,1,0,(yyvsp[-1].ELEMENTO).valstr,(yyvsp[-1].ELEMENTO).valbool,(yyvsp[-1].ELEMENTO).valnum,(yyvsp[-1].ELEMENTO).valint,(yyvsp[-2].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1536 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 167 "trans.y" /* yacc.c:1646  */
    { //Un número
		(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-1].ELEMENTO).valint,(yyvsp[-2].indice)->nombre)); //La traducción
		
		copiardatos(&auxnodo1,(yyvsp[-1].ELEMENTO).tipo,1,0,(yyvsp[-1].ELEMENTO).valstr,(yyvsp[-1].ELEMENTO).valbool,(yyvsp[-1].ELEMENTO).valnum,(yyvsp[-1].ELEMENTO).valint,(yyvsp[-2].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1548 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 177 "trans.y" /* yacc.c:1646  */
    { //Un número
		(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-1].ELEMENTO).valbool,(yyvsp[-2].indice)->nombre)); //La traducción
		
		
		copiardatos(&auxnodo1,(yyvsp[-1].ELEMENTO).tipo,1,0,(yyvsp[-1].ELEMENTO).valstr,(yyvsp[-1].ELEMENTO).valbool,(yyvsp[-1].ELEMENTO).valnum,(yyvsp[-1].ELEMENTO).valint,(yyvsp[-2].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1561 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 187 "trans.y" /* yacc.c:1646  */
    {//Constante cadena
		(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_cad((yyvsp[-1].ELEMENTO).cad,(yyvsp[-2].indice)->nombre)); //Traducción

		copiardatos(&auxnodo1,(yyvsp[-1].ELEMENTO).tipo,1,0,(yyvsp[-1].ELEMENTO).valstr,(yyvsp[-1].ELEMENTO).valbool,(yyvsp[-1].ELEMENTO).valnum,(yyvsp[-1].ELEMENTO).valint,(yyvsp[-2].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1573 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 198 "trans.y" /* yacc.c:1646  */
    { 
		(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_num((yyvsp[-2].ELEMENTO).valnum,(yyvsp[-3].indice)->nombre)); //Traducción
		
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,1,0,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1585 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 209 "trans.y" /* yacc.c:1646  */
    { //Un número
		(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre)); //La traducción
		
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,1,0,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1597 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 219 "trans.y" /* yacc.c:1646  */
    { //Un número
		(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-2].ELEMENTO).valbool,(yyvsp[-3].indice)->nombre)); //La traducción
		
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,1,0,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1609 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 229 "trans.y" /* yacc.c:1646  */
    {
		(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_const_cad((yyvsp[-2].ELEMENTO).cad,(yyvsp[-3].indice)->nombre));  //Traducción

		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,1,0,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1621 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 243 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=6; 
	}
#line 1629 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 248 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=1;}
#line 1636 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 252 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=4;
	}
#line 1644 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 256 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=4;
	}
#line 1652 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 260 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=3;
	}
#line 1660 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 268 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1668 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 271 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1676 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 278 "trans.y" /* yacc.c:1646  */
    {
		(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_variable((yyvsp[-2].ELEMENTO).tipo, (yyvsp[-3].indice)->nombre,(yyvsp[-1].ELEMENTO).espun)); //Traducción
	
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,0,(yyvsp[-1].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1688 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 288 "trans.y" /* yacc.c:1646  */
    {
		(yyvsp[-4].indice)->tipo=(yyvsp[-3].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_variable((yyvsp[-3].ELEMENTO).tipo, (yyvsp[-4].indice)->nombre,(yyvsp[-2].ELEMENTO).espun)); //Traducción
			
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
			
		copiardatos(&auxnodo1,(yyvsp[-3].ELEMENTO).tipo,0,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-3].ELEMENTO).valstr,(yyvsp[-3].ELEMENTO).valbool,(yyvsp[-3].ELEMENTO).valnum,(yyvsp[-3].ELEMENTO).valint,(yyvsp[-4].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1702 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 301 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).espun=1;
	}
#line 1710 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 305 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).espun=0;
	}
#line 1718 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 313 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"}\n");
	}
#line 1727 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 322 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1735 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 326 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 1744 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 334 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].indice)->nombre);
		
		auxvar=(yyvsp[0].indice);
		insertar_fun(auxvar,OP_FUN);
		
		copiardatos(&auxnodo1,5,0,0,"",0,0,0,(yyvsp[0].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1758 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 347 "trans.y" /* yacc.c:1646  */
    {
		//printf("%s \n",$6.nombre);
		if((yyvsp[-3].ELEMENTO).tipo==1)
			strcpy((yyval.ELEMENTO).trad,"float ");
		if((yyvsp[-3].ELEMENTO).tipo==6||(yyvsp[-3].ELEMENTO).tipo==3)
			strcpy((yyval.ELEMENTO).trad,"int ");
		if((yyvsp[-3].ELEMENTO).tipo==2)
			strcpy((yyval.ELEMENTO).trad,"char *");
			
		strcat((yyval.ELEMENTO).trad,(yyvsp[-7].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-6].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"{\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1778 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 363 "trans.y" /* yacc.c:1646  */
    {//Puede no haber funciones
		strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1786 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 371 "trans.y" /* yacc.c:1646  */
    {	
		strcpy((yyval.ELEMENTO).trad,"(");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,")");
	}
#line 1796 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 377 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"(");
		strcat((yyval.ELEMENTO).trad,")");
	}
#line 1805 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 385 "trans.y" /* yacc.c:1646  */
    {
		(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_argumento((yyvsp[-2].ELEMENTO).tipo, (yyvsp[-3].indice)->nombre,(yyvsp[-1].ELEMENTO).espun)); //Traducción

		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,0,(yyvsp[-1].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1817 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 394 "trans.y" /* yacc.c:1646  */
    {
		(yyvsp[-4].indice)->tipo=(yyvsp[-3].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).trad,intr_argumento((yyvsp[-3].ELEMENTO).tipo, (yyvsp[-4].indice)->nombre,(yyvsp[-2].ELEMENTO).espun)); //Traducción
		strcat((yyval.ELEMENTO).trad,", ");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
			
		copiardatos(&auxnodo1,(yyvsp[-3].ELEMENTO).tipo,0,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-3].ELEMENTO).valstr,(yyvsp[-3].ELEMENTO).valbool,(yyvsp[-3].ELEMENTO).valnum,(yyvsp[-3].ELEMENTO).valint,(yyvsp[-4].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
#line 1831 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 408 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);	
	}
#line 1839 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 415 "trans.y" /* yacc.c:1646  */
    {		
		 strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad); 
	}
#line 1847 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 424 "trans.y" /* yacc.c:1646  */
    {		
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);//Se limpia .trad
	}
#line 1855 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 430 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1864 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 435 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1872 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 439 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1880 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 445 "trans.y" /* yacc.c:1646  */
    {
		//printf("%s",$1.cad);
		strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1889 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 451 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"(");;
		strcat((yyval.ELEMENTO).trad,");\n");
	}
#line 1899 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 459 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-3].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"(");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
	}
#line 1910 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 467 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1918 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 474 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].indice)->nombre);
		strcpy(auxnodo1.nombre,(yyvsp[0].indice)->nombre);
		insertar(auxnodo1,auxnodo2,OP_LLAMAR,auxvar);
	}
#line 1928 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 484 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).nombre);
		strcat((yyval.ELEMENTO).trad,"++;\n");
			
		strcpy(auxnodo1.nombre,(yyvsp[0].ELEMENTO).nombre);
	
		insertar(auxnodo1,auxnodo2,OP_INC,auxvar);
	}
#line 1941 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 495 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).nombre);
		strcat((yyval.ELEMENTO).trad,"--;\n");
	
		strcpy(auxnodo1.nombre,(yyvsp[0].ELEMENTO).nombre);
	
		insertar(auxnodo1,auxnodo2,OP_DEC,auxvar);
	}
#line 1954 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 507 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1962 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 511 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad,", ");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1971 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 519 "trans.y" /* yacc.c:1646  */
    {
		insertar(auxnodo1,auxnodo2,OP_ELSE,auxvar);
	}
#line 1979 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 525 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
			
		copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	
		insertar(auxnodo1,auxnodo2,OP_SI,auxvar);
	}
#line 1991 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 536 "trans.y" /* yacc.c:1646  */
    {
	
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	
		insertar(auxnodo1,auxnodo2,OP_WHILE,auxvar);
	}
#line 2004 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 548 "trans.y" /* yacc.c:1646  */
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
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	
		insertar_para(auxnodo1,auxnodo2,OP_PARA,auxvar);
	}
#line 2053 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 595 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).nombre,(yyvsp[0].indice)->nombre);
		(yyval.ELEMENTO).tipo=(yyvsp[0].indice)->tipo;
		
		copiardatos(&auxnodo1,(yyvsp[0].indice)->tipo,(yyvsp[0].indice)->escons,(yyvsp[0].indice)->espun,(yyvsp[0].indice)->valstr,(yyvsp[0].indice)->valbool,(yyvsp[0].indice)->valnum,(yyvsp[0].indice)->valint,(yyvsp[0].indice)->nombre);
		
		insertar(auxnodo1,auxnodo2,OP_SWITCH,auxvar);
	}
#line 2066 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 608 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"if (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,")\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2078 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 618 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"if (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-4].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,") {\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"} else {\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2091 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 629 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"while (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,") {\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2102 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 638 "trans.y" /* yacc.c:1646  */
    {		
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2112 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 646 "trans.y" /* yacc.c:1646  */
    {	
		
		//Si todo está bien se traduce y saca por pantalla
		
		strcpy((yyval.ELEMENTO).trad,"switch (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).nombre);
		strcat((yyval.ELEMENTO).trad,"){\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2126 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 659 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=(yyvsp[-2].ELEMENTO).tipo;
		
		strcpy((yyval.ELEMENTO).trad,"case ");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,":\n");		
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);		
		
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	
		insertar(auxnodo1,auxnodo2,OP_CASE,auxvar);
	}
#line 2144 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 673 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);		
		
		insertar(auxnodo1,auxnodo2,OP_DEFAULT,auxvar);
	}
#line 2156 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 684 "trans.y" /* yacc.c:1646  */
    {
	}
#line 2163 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 687 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 2172 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 695 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"default:\n");
	}
#line 2180 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 701 "trans.y" /* yacc.c:1646  */
    {
		//fprintf(salida,"break;\n");
		strcpy((yyval.ELEMENTO).trad,"break;\n");
	}
#line 2189 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 709 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"{\n");
	}
#line 2197 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 714 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"{\n");
	}
#line 2205 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 721 "trans.y" /* yacc.c:1646  */
    {
		//fprintf(salida,"}\n");
		strcpy((yyval.ELEMENTO).trad,"}\n");
		
		insertar(auxnodo1,auxnodo2,OP_FIN,auxvar);
	}
#line 2216 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 732 "trans.y" /* yacc.c:1646  */
    {
	char signo1[3],signo2[3];
	char retorno[255];
	
	if ((yyvsp[-4].ELEMENTO).vis==0)
		strcpy(signo1,"");
	if ((yyvsp[-4].ELEMENTO).vis==2)
		strcpy(signo1,"*");
	if ((yyvsp[-4].ELEMENTO).vis==3)
		strcpy(signo1,"&");
	
	if ((yyvsp[-1].ELEMENTO).vis==0)
		strcpy(signo2,"");
	if ((yyvsp[-1].ELEMENTO).vis==2)
		strcpy(signo2,"*");
	if ((yyvsp[-1].ELEMENTO).vis==3)
		strcpy(signo2,"&");
		
	strcpy(retorno,signo1);
	strcat(retorno,(yyvsp[-3].indice)->nombre);
	strcat(retorno,"=");
	strcat(retorno,signo2);
	strcat(retorno,(yyvsp[0].ELEMENTO).trad);
	strcat(retorno,";");
	strcat(retorno,"\n");
	
	//printf("%s\n",retorno);
	strcpy((yyval.ELEMENTO).trad,retorno);	
	
	auxvar=(yyvsp[-3].indice);
	
	copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	
	insertar(auxnodo1,auxnodo2,OP_ASIGNAR,auxvar);
	}
#line 2256 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 770 "trans.y" /* yacc.c:1646  */
    { 
		(yyval.ELEMENTO).vis=2;//*
	}
#line 2264 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 773 "trans.y" /* yacc.c:1646  */
    { 
		(yyval.ELEMENTO).vis=3;//&
	}
#line 2272 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 776 "trans.y" /* yacc.c:1646  */
    {
	}
#line 2279 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 784 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).vis=(yyvsp[0].ELEMENTO).vis;	
	(yyval.ELEMENTO).tipo=(yyvsp[0].ELEMENTO).tipo;
	
	switch ((yyvsp[0].ELEMENTO).tipo){
	case 1: 
		strcpy((yyval.ELEMENTO).trad,"printf(\" %%f \\n\",");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
		break;
	case 2:					
		strcpy((yyval.ELEMENTO).trad,"printf(\" %%s \\n\",");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
		break;
	case 3: 
		strcpy((yyval.ELEMENTO).trad,"printf(\" %%d \\n\",");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
		break;
	case 4: 
		strcpy((yyval.ELEMENTO).trad,"printf(\"");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).cad);
		strcat((yyval.ELEMENTO).trad,"\\n\");\n");
		break;
	case 6: 
		strcpy((yyval.ELEMENTO).trad,"printf(\" %%d \\n\",");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
		break;
	}//switch
	

	copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).cad,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	
	insertar(auxnodo1,auxnodo2,OP_ESCRIBIR,auxvar);
}
#line 2321 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 826 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 2329 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 832 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-3].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 2338 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 840 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"printf(\"\\n\");");
		strcat((yyval.ELEMENTO).trad,"\n");
	}
#line 2347 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 849 "trans.y" /* yacc.c:1646  */
    {	
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2355 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 856 "trans.y" /* yacc.c:1646  */
    {	
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2364 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 860 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"");
	}
#line 2372 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 870 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,vis_entrada((yyvsp[-1].indice)->tipo,(yyvsp[-1].indice)->nombre,(yyvsp[-1].indice)->espun));//Traducción
		
		auxvar=(yyvsp[-1].indice);
	
		insertar(auxnodo1,auxnodo2,OP_LEER,auxvar);
	}
#line 2384 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 883 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," + ");//Traducción
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	
	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);

	insertarexp(auxnodo1,auxnodo2,OP_SUMA);
	}
#line 2398 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 896 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," - ");//introducimos la cadena creada para la traduccion
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
		insertarexp(auxnodo1,auxnodo2,OP_RESTA);
		
	}
#line 2412 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 908 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," * ");//Traducción
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
		insertarexp(auxnodo1,auxnodo2,OP_MULT);
	}
#line 2425 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 919 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," / ");//Traducción
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
		insertarexp(auxnodo1,auxnodo2,OP_DIV);
	}
#line 2438 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 930 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad," -");//introducimos la cadena creada para la traduccion
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

		copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
		insertarexp(auxnodo1,auxnodo2,OP_CAM);
	}
#line 2450 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 941 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad," pow");//Traducción
		strcpy(auxt,"(");
		strcat(auxt,(yyvsp[-2].ELEMENTO).trad);
		strcat(auxt,",");
		strcat(auxt,(yyvsp[0].ELEMENTO).trad);
		strcat(auxt,")");
		strcat((yyval.ELEMENTO).trad,auxt);

	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_POW);
	}
#line 2468 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 957 "trans.y" /* yacc.c:1646  */
    {
		strcat(auxt,(yyvsp[-2].ELEMENTO).trad);
		strcat(auxt,"%");
		strcat(auxt,(yyvsp[0].ELEMENTO).trad);
		strcpy((yyval.ELEMENTO).trad,auxt);


		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
		insertarexp(auxnodo1,auxnodo2,OP_MOD);
	}
#line 2484 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 971 "trans.y" /* yacc.c:1646  */
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
	}
#line 2503 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 989 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," < ");//Traducción
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	(yyval.ELEMENTO).tipo=3;

	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_MENOR);
	}
#line 2517 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1001 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," > ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_MAYOR);
	}
#line 2530 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1012 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," >= ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	(yyval.ELEMENTO).tipo=3;

	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	
	insertarexp(auxnodo1,auxnodo2,OP_MAI);
	}
#line 2545 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1025 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," <= ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_MEI);                                
}
#line 2558 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1036 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," != ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	(yyval.ELEMENTO).tipo=3;
	
	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_DESIGUALDAD);                                 
	}
#line 2572 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1048 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," == ");//introducimos la cadena creada para la traduccion
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		(yyval.ELEMENTO).tipo=3;
		
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
		insertarexp(auxnodo1,auxnodo2,OP_IGUALDAD);
	}
#line 2586 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1060 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," && ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	(yyval.ELEMENTO).tipo=3;
	
	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_AND);
	}
#line 2600 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1073 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," || ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	(yyval.ELEMENTO).tipo=3;
	
	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_OR);
	
	}
#line 2615 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1088 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad," !");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	(yyval.ELEMENTO).tipo=3;

	
	copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_NOT);	
	}
#line 2629 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1100 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=1;
		(yyval.ELEMENTO).escons=1;
		(yyval.ELEMENTO).valnum =(yyvsp[0].ELEMENTO).valnum;	  
	}
#line 2639 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1108 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=6;
		(yyval.ELEMENTO).escons=1;
		(yyval.ELEMENTO).valint =(yyvsp[0].ELEMENTO).valint;	
	}
#line 2649 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1116 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=3;
		(yyval.ELEMENTO).escons=1;
		(yyval.ELEMENTO).valbool= (yyvsp[0].ELEMENTO).valbool;
	}
#line 2659 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1124 "trans.y" /* yacc.c:1646  */
    {	
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].indice)->nombre);//copio el nombre de la variable para la traduccion
		strcpy((yyval.ELEMENTO).nombre,(yyvsp[0].indice)->nombre);//copio el nombre de la variable para la traduccion
		(yyval.ELEMENTO).tipo=(yyvsp[0].indice)->tipo;
	}
#line 2669 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1132 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=(yyvsp[0].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).valstr,(yyvsp[0].ELEMENTO).cad);
		strcpy((yyval.ELEMENTO).cad,(yyvsp[0].ELEMENTO).cad);
		(yyval.ELEMENTO).escons=(yyvsp[0].ELEMENTO).escons;
	}
#line 2680 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1141 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"*");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2689 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1148 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"&");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2698 "trans.tab.c" /* yacc.c:1646  */
    break;


#line 2702 "trans.tab.c" /* yacc.c:1646  */
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
#line 1153 "trans.y" /* yacc.c:1906  */

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
}

