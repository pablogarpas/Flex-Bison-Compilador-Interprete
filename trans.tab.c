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
#include "trad.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Prototipos
int ejecutar();
NODO procesarexp(ARBOL *aux);
//Variables globales
int eje[10]={1,0,0,0,0,0,0,0,0,0};//variable para ver que añadir al AST
int poscontrol;//variable guardando posición
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

#line 92 "trans.tab.c" /* yacc.c:339  */

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
    TK_STRING = 266,
    TK_MIENTRAS = 267,
    TK_IGU = 268,
    TK_HAZ = 269,
    TK_DIR = 270,
    TK_VAL = 271,
    TK_RETORNO = 272,
    TK_ESCRIBIR = 273,
    TK_ARG = 274,
    TK_LIB = 275,
    TK_SWITCH = 276,
    TK_LEER = 277,
    TK_LLAMAR = 278,
    TK_FIN = 279,
    TK_HACER = 280,
    TK_INC = 281,
    TK_DEC = 282,
    TK_FUNCION = 283,
    TK_CONT = 284,
    TK_DEFAULT = 285,
    TK_HASTA = 286,
    TK_ELSE = 287,
    TK_PARA = 288,
    TK_CASO = 289,
    TK_COM = 290,
    TK_CADENA = 291,
    TK_NBOOL = 292,
    TK_NUM = 293,
    TK_ENT = 294,
    TK_VARIABLE = 295,
    TK_MEI = 296,
    TK_MAI = 297,
    TK_DIS = 298,
    TK_ASIG = 299,
    TK_OR = 300,
    TK_AND = 301,
    TK_NOT = 302,
    MENOSUNARIO = 303,
    TK_POW = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "trans.y" /* yacc.c:355  */

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

#line 200 "trans.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TRANS_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 217 "trans.tab.c" /* yacc.c:358  */

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
#define YYLAST   361

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

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
      58,    60,    51,    48,    59,    49,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,    41,    46,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    42,    43,    44,    47,
      50,    53,    54,    55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   117,   118,   122,   123,   128,   134,   143,
     155,   164,   176,   187,   197,   209,   221,   232,   243,   258,
     263,   267,   272,   281,   287,   293,   308,   326,   331,   338,
     351,   355,   362,   381,   388,   395,   402,   415,   433,   453,
     476,   490,   496,   500,   505,   512,   522,   526,   534,   545,
     554,   564,   575,   584,   637,   665,   675,   686,   691,   702,
     709,   716,   722,   728,   739,   779,   782,   785,   792,   851,
     858,   866,   877,   884,   889,   896,   904,   947,   973,  1000,
    1029,  1049,  1082,  1099,  1153,  1208,  1263,  1318,  1373,  1388,
    1404,  1419,  1435,  1442,  1450,  1457,  1472,  1481,  1493,  1505,
    1517,  1528,  1533
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PROGRAM", "TK_CONST", "TK_VAR",
  "TK_SI", "TK_INICIO", "TK_ENTERO", "TK_REAL", "TK_BOOL", "TK_STRING",
  "TK_MIENTRAS", "TK_IGU", "TK_HAZ", "TK_DIR", "TK_VAL", "TK_RETORNO",
  "TK_ESCRIBIR", "TK_ARG", "TK_LIB", "TK_SWITCH", "TK_LEER", "TK_LLAMAR",
  "TK_FIN", "TK_HACER", "TK_INC", "TK_DEC", "TK_FUNCION", "TK_CONT",
  "TK_DEFAULT", "TK_HASTA", "TK_ELSE", "TK_PARA", "TK_CASO", "TK_COM",
  "TK_CADENA", "TK_NBOOL", "TK_NUM", "TK_ENT", "TK_VARIABLE", "'='",
  "TK_MEI", "TK_MAI", "TK_DIS", "'<'", "'>'", "TK_ASIG", "'+'", "'-'",
  "TK_OR", "'*'", "'/'", "TK_AND", "TK_NOT", "MENOSUNARIO", "TK_POW",
  "'\\n'", "'('", "','", "')'", "$accept", "programa", "salto_lin",
  "salto_lin_dec", "cabecera", "librerias", "dec_constantes", "constante",
  "tipo", "dec_vbles", "variable", "puntero", "cuerpo", "funciones",
  "funcion", "dec_arg_fun", "argumento", "lista_sentencias", "sentencia",
  "llamar", "control2", "control", "case", "cases", "default", "break",
  "cont", "final", "asignacion", "punteros_asignar", "elemento_mostrar",
  "visual", "visual2", "lectura", "exp", YY_NULLPTR
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
     295,    61,   296,   297,   298,    60,    62,   299,    43,    45,
     300,    42,    47,   301,   302,   303,   304,    10,    40,    44,
      41
};
# endif

#define YYPACT_NINF -149

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-149)))

#define YYTABLE_NINF -68

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -22,    36,  -149,   -35,  -149,    23,   -35,  -149,  -149,
     -35,    40,  -149,    12,   -35,    55,   -13,  -149,    24,   -35,
      35,   -35,   -35,   -35,   -35,    22,  -149,   326,    26,    35,
    -149,    12,    12,    12,    12,  -149,  -149,  -149,  -149,    49,
     267,   267,   326,  -149,  -149,     9,    41,    29,    30,    44,
    -149,    66,   -35,    67,    69,  -149,    51,  -149,  -149,    75,
    -149,  -149,  -149,  -149,  -149,  -149,   -35,   267,   267,    24,
      24,  -149,  -149,  -149,  -149,    22,   267,   267,   267,     8,
     187,   187,    85,   168,   -14,    58,    59,    53,  -149,   296,
    -149,   326,  -149,  -149,    54,   -35,    40,    24,   228,   228,
    -149,  -149,    -5,    -5,   129,  -149,  -149,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     326,   326,   267,  -149,    42,    45,   228,  -149,   267,   -14,
    -149,   326,    43,    46,   267,  -149,  -149,    25,    68,    89,
    -149,  -149,   228,   228,   228,   228,   228,   228,    -3,    -3,
      -3,    -5,    -5,    -5,    -5,    77,  -149,   228,  -149,   267,
     108,  -149,  -149,  -149,   267,   203,   267,    22,  -149,    22,
     326,    47,  -149,  -149,   -16,   228,   267,   228,    49,   -35,
    -149,  -149,  -149,   267,  -149,   187,   -35,   326,   228,   326,
      68,    69,  -149,  -149,  -149
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     8,     4,     1,    10,     5,     7,     3,
       4,    24,     6,     0,     4,     0,     0,     9,     0,     4,
      33,     4,     4,     4,     4,     0,    23,    67,     0,     2,
      30,    14,    13,    11,    12,    19,    20,    22,    21,    28,
       0,     0,    67,    66,    65,     0,     0,     0,     0,     0,
      44,     0,     4,    62,     0,    40,     0,    42,    43,    35,
      31,    18,    17,    15,    16,    27,     4,     0,     0,     0,
       0,    96,    94,    92,    93,    95,     0,     0,     0,     0,
      48,    62,     0,    74,     0,     0,     0,     0,    29,    38,
      61,    67,    63,    41,     0,     4,    24,    25,   102,   101,
      97,    99,    80,    91,     0,    98,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,    67,     0,    71,    72,     0,    68,    59,     0,    57,
      54,    67,     0,     0,     0,    39,    49,    67,     0,     0,
      26,    82,    88,    86,    85,    87,    83,    84,    76,    77,
      90,    78,    79,    89,    81,     0,    51,    52,    69,     0,
      67,    58,    60,    75,     0,     0,     0,     0,    34,     0,
      67,    73,    60,    56,     0,    46,     0,    64,    28,     4,
      50,    70,    55,     0,    45,    62,     4,    67,    47,    67,
      36,     0,    53,    37,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,   -10,   104,  -149,  -149,  -149,    27,  -148,    16,
     -15,   -62,  -149,  -149,    88,  -149,   -72,   -74,    86,  -149,
    -149,  -149,  -149,     3,  -149,   -53,   -75,   -58,  -149,    -2,
     -25,  -149,  -149,  -149,   -39
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,     3,     6,    11,    17,    39,    15,
      79,    66,    20,    29,    30,    96,   168,    51,    52,   174,
      53,    54,   129,   130,   131,   173,    91,    93,    55,    56,
     124,    57,   125,    58,   126
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    80,    81,    26,    18,   120,   121,     1,   107,    27,
     107,    31,    32,    33,    34,   135,   127,   136,     4,   178,
     128,   179,     7,    21,    22,    23,    24,    10,    98,    99,
      35,    36,    37,    38,   105,   106,     5,   102,   103,   104,
      43,    44,    89,   183,   184,    14,   155,   156,   116,   117,
     118,   119,    16,   119,   100,   101,    97,   162,    61,    62,
      63,    64,    19,    28,    25,    65,    59,    83,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    84,   140,   157,    87,   138,   172,    85,    86,   160,
      88,    94,    90,    92,    95,   165,   180,   122,   132,   133,
     134,   137,   158,   163,   159,   164,   169,   181,   167,   170,
     189,    12,   139,   191,    40,   192,   186,    60,   193,   182,
      41,   107,    42,    43,    44,   175,    45,   177,    82,    46,
      47,    48,   161,   194,   171,   166,     0,   185,     0,     0,
       0,    49,   107,    50,   188,     0,     0,     0,     0,     0,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,   118,     0,     0,   119,     0,     0,     0,     0,   187,
       0,   108,   109,   110,   111,   112,   190,   113,   114,   115,
     116,   117,   118,    67,    68,   119,     0,     0,     0,   141,
       0,     0,     0,     0,    69,    70,     0,     0,     0,     0,
     107,     0,     0,     0,    71,    72,    73,    74,    75,     0,
       0,     0,    90,     0,     0,     0,   107,    76,     0,     0,
       0,     0,    77,     0,     0,     0,    78,     0,   123,   108,
     109,   110,   111,   112,   176,   113,   114,   115,   116,   117,
     118,   107,     0,   119,     0,   108,   109,   110,   111,   112,
       0,   113,   114,   115,   116,   117,   118,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,   118,    67,    68,   119,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,     0,     0,     0,     0,     0,
       0,     0,    40,    71,    72,    73,    74,    75,    41,     0,
      42,    43,    44,     0,    45,     0,    76,    46,    47,    48,
       0,    77,     0,     0,     0,    78,     0,     0,     0,    49,
       0,    50,    40,     0,     0,     0,   -67,     0,    41,     0,
      42,    43,    44,     0,    45,     0,     0,    46,    47,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,    50
};

static const yytype_int16 yycheck[] =
{
      10,    40,    41,    18,    14,    80,    81,     3,    13,    19,
      13,    21,    22,    23,    24,    89,    30,    91,    40,   167,
      34,   169,    57,    36,    37,    38,    39,     4,    67,    68,
       8,     9,    10,    11,    26,    27,     0,    76,    77,    78,
      15,    16,    52,    59,    60,     5,   120,   121,    51,    52,
      53,    56,    40,    56,    69,    70,    66,   131,    31,    32,
      33,    34,     7,    28,    40,    16,    40,    58,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    40,    97,   122,    40,    95,   160,    58,    58,   128,
      24,    40,    25,    24,    19,   134,   170,    12,    40,    40,
      47,    47,    60,    60,    59,    59,    17,    60,    40,    32,
     185,     7,    96,   187,     6,   189,   178,    29,   190,   172,
      12,    13,    14,    15,    16,   164,    18,   166,    42,    21,
      22,    23,   129,   191,   159,   137,    -1,   176,    -1,    -1,
      -1,    33,    13,    35,   183,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,   179,
      -1,    42,    43,    44,    45,    46,   186,    48,    49,    50,
      51,    52,    53,    15,    16,    56,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    13,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    58,    -1,    60,    42,
      43,    44,    45,    46,    31,    48,    49,    50,    51,    52,
      53,    13,    -1,    56,    -1,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    15,    16,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    36,    37,    38,    39,    40,    12,    -1,
      14,    15,    16,    -1,    18,    -1,    49,    21,    22,    23,
      -1,    54,    -1,    -1,    -1,    58,    -1,    -1,    -1,    33,
      -1,    35,     6,    -1,    -1,    -1,    40,    -1,    12,    -1,
      14,    15,    16,    -1,    18,    -1,    -1,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    62,    65,    40,     0,    66,    57,    63,    64,
       4,    67,    64,    63,     5,    70,    40,    68,    63,     7,
      73,    36,    37,    38,    39,    40,    71,    63,    28,    74,
      75,    63,    63,    63,    63,     8,     9,    10,    11,    69,
       6,    12,    14,    15,    16,    18,    21,    22,    23,    33,
      35,    78,    79,    81,    82,    89,    90,    92,    94,    40,
      75,    68,    68,    68,    68,    16,    72,    15,    16,    26,
      27,    36,    37,    38,    39,    40,    49,    54,    58,    71,
      95,    95,    79,    58,    40,    58,    58,    40,    24,    63,
      25,    87,    24,    88,    40,    19,    76,    63,    95,    95,
      71,    71,    95,    95,    95,    26,    27,    13,    42,    43,
      44,    45,    46,    48,    49,    50,    51,    52,    53,    56,
      87,    87,    12,    60,    91,    93,    95,    30,    34,    83,
      84,    85,    40,    40,    47,    78,    78,    47,    63,    70,
      71,    60,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    78,    78,    95,    60,    59,
      95,    84,    78,    60,    59,    95,    90,    40,    77,    17,
      32,    91,    78,    86,    80,    95,    31,    95,    69,    69,
      78,    60,    86,    59,    60,    95,    72,    63,    95,    87,
      63,    78,    78,    77,    88
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    64,    65,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      79,    79,    79,    79,    79,    79,    80,    80,    81,    82,
      82,    82,    82,    82,    82,    83,    83,    84,    84,    85,
      86,    87,    87,    88,    89,    90,    90,    90,    91,    92,
      92,    92,    93,    93,    93,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     0,     1,     2,     3,     0,     3,
       0,     3,     3,     3,     3,     4,     4,     4,     4,     1,
       1,     1,     1,     3,     0,     4,     5,     1,     0,     4,
       1,     2,     9,     0,     3,     0,     4,     5,     2,     3,
       1,     2,     1,     1,     1,     6,     1,     3,     2,     3,
       6,     4,     4,     8,     3,     4,     3,     1,     2,     1,
       0,     1,     0,     1,     5,     1,     1,     0,     1,     4,
       6,     3,     1,     3,     0,     4,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2
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
#line 103 "trans.y" /* yacc.c:1646  */
    {
		fprintf(salida,(yyvsp[-4].ELEMENTO).trad);
		fprintf(salida,(yyvsp[-3].ELEMENTO).trad);
		fprintf(salida,(yyvsp[0].ELEMENTO).trad);
		fprintf(salida,intr_cabecera());//Introducir el main después de las constantes
		fprintf(salida,(yyvsp[-2].ELEMENTO).trad);
		fprintf(salida,(yyvsp[-1].ELEMENTO).trad);
		
	}
#line 1480 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 117 "trans.y" /* yacc.c:1646  */
    {}
#line 1486 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 118 "trans.y" /* yacc.c:1646  */
    {}
#line 1492 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 122 "trans.y" /* yacc.c:1646  */
    {}
#line 1498 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 123 "trans.y" /* yacc.c:1646  */
    {}
#line 1504 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 129 "trans.y" /* yacc.c:1646  */
    {
		(yyvsp[-1].indice)->tipo=0;  	
	}
#line 1512 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 134 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"#include <stdio.h>\n#include <math.h>\n");
	}
#line 1520 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 144 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		(yyval.ELEMENTO).tipo=(yyvsp[0].ELEMENTO).tipo;
		switch ((yyvsp[0].ELEMENTO).tipo){
			case 1:(yyval.ELEMENTO).valnum=(yyvsp[0].ELEMENTO).valnum;break;
			case 2:strcpy((yyval.ELEMENTO).cad,(yyvsp[0].ELEMENTO).cad);break;
			case 3:(yyval.ELEMENTO).valbool=(yyvsp[0].ELEMENTO).valbool;break;
			case 6:(yyval.ELEMENTO).valint=(yyvsp[0].ELEMENTO).valint;break;
		}		
	}
#line 1536 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 155 "trans.y" /* yacc.c:1646  */
    {		
	strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1544 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 165 "trans.y" /* yacc.c:1646  */
    { //Un número
		strcpy((yyval.ELEMENTO).trad,intr_const_num((yyvsp[-1].ELEMENTO).valnum,(yyvsp[-2].indice)->nombre)); //La traducción
		(yyval.ELEMENTO).valnum=(yyvsp[-2].indice)->valnum=(yyvsp[-1].ELEMENTO).valnum;
		(yyval.ELEMENTO).tipo=(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		(yyval.ELEMENTO).escons=1;	
		(yyvsp[-2].indice)->escons=1;
		(yyvsp[-2].indice)->aux=3;//Cualquier número
	}
#line 1557 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 177 "trans.y" /* yacc.c:1646  */
    { //Un número
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-1].ELEMENTO).valint,(yyvsp[-2].indice)->nombre)); //La traducción
		(yyval.ELEMENTO).valint=(yyvsp[-2].indice)->valint=(yyvsp[-1].ELEMENTO).valint;
		(yyval.ELEMENTO).tipo=(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		(yyval.ELEMENTO).escons=1;	
		(yyvsp[-2].indice)->escons=1;
		(yyvsp[-2].indice)->aux=3;//Cualquier número
	}
#line 1570 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 188 "trans.y" /* yacc.c:1646  */
    { //Un número
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-1].ELEMENTO).valbool,(yyvsp[-2].indice)->nombre)); //La traducción
		(yyval.ELEMENTO).valbool=(yyvsp[-2].indice)->valbool=(yyvsp[-1].ELEMENTO).valbool;
		(yyval.ELEMENTO).tipo=(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		(yyval.ELEMENTO).escons=1;	
		(yyvsp[-2].indice)->escons=1;
		(yyvsp[-2].indice)->aux=3;//Cualquier número
	}
#line 1583 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 198 "trans.y" /* yacc.c:1646  */
    {//Constante cadena
		strcpy((yyval.ELEMENTO).trad,intr_const_cad((yyvsp[-1].ELEMENTO).cad,(yyvsp[-2].indice)->nombre)); //Traducción
		strcpy((yyval.ELEMENTO).cad,strcpy((yyvsp[-2].indice)->cad,(yyvsp[-1].ELEMENTO).cad));    
		(yyval.ELEMENTO).tipo=(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		(yyval.ELEMENTO).escons=1;
		(yyvsp[-2].indice)->escons=1;
		(yyvsp[-2].indice)->aux=3;//Cualquier número
	}
#line 1596 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 210 "trans.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.ELEMENTO).trad,intr_const_num((yyvsp[-2].ELEMENTO).valnum,(yyvsp[-3].indice)->nombre)); //Traducción
		(yyval.ELEMENTO).valnum=(yyvsp[-3].indice)->valnum=(yyvsp[-2].ELEMENTO).valnum;
		(yyval.ELEMENTO).tipo=(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		(yyval.ELEMENTO).escons=1;
		(yyvsp[-3].indice)->escons=1;
		(yyvsp[-3].indice)->aux=3;//Cualquier número
	}
#line 1609 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 222 "trans.y" /* yacc.c:1646  */
    { //Un número
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre)); //La traducción
		(yyval.ELEMENTO).valint=(yyvsp[-3].indice)->valint=(yyvsp[-2].ELEMENTO).valint;
		(yyval.ELEMENTO).tipo=(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		(yyval.ELEMENTO).escons=1;	
		(yyvsp[-3].indice)->escons=1;
		(yyvsp[-3].indice)->aux=3;//Cualquier número
	}
#line 1622 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 233 "trans.y" /* yacc.c:1646  */
    { //Un número
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-2].ELEMENTO).valbool,(yyvsp[-3].indice)->nombre)); //La traducción
		(yyval.ELEMENTO).valbool=(yyvsp[-3].indice)->valbool=(yyvsp[-2].ELEMENTO).valbool;
		(yyval.ELEMENTO).tipo=(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		(yyval.ELEMENTO).escons=1;	
		(yyvsp[-3].indice)->escons=1;
		(yyvsp[-3].indice)->aux=3;//Cualquier número
	}
#line 1635 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 244 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,intr_const_cad((yyvsp[-2].ELEMENTO).cad,(yyvsp[-3].indice)->nombre));  //Traducción
		strcpy((yyval.ELEMENTO).cad,strcpy((yyvsp[-3].indice)->cad,(yyvsp[-2].ELEMENTO).cad));
		(yyval.ELEMENTO).escons=1;
		(yyval.ELEMENTO).tipo=(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		(yyvsp[-3].indice)->escons=1;
		(yyvsp[-3].indice)->aux=3;//Cualquier número
	}
#line 1648 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 259 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=6; 
	}
#line 1656 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 264 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=1;}
#line 1663 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 268 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=2;
	}
#line 1671 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 273 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=3;
	}
#line 1679 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 282 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		(yyval.ELEMENTO).tipo=(yyvsp[0].ELEMENTO).tipo;
	}
#line 1689 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 287 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1697 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 294 "trans.y" /* yacc.c:1646  */
    {
	
		strcpy((yyval.ELEMENTO).trad,intr_variable((yyvsp[-2].ELEMENTO).tipo, (yyvsp[-3].indice)->nombre,(yyvsp[-1].ELEMENTO).espun)); //Traducción
	
	if ((yyvsp[-3].indice)->escons==0) {
		(yyval.ELEMENTO).tipo=(yyvsp[-2].ELEMENTO).tipo;
		(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).nombre,(yyvsp[-3].indice)->nombre);
		(yyvsp[-3].indice)->espun=(yyvsp[-1].ELEMENTO).espun;
		}
	else yyerror("Error: %s ---Variable ya declarada como constante\n",(yyvsp[-3].indice)->nombre);
	}
#line 1714 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 309 "trans.y" /* yacc.c:1646  */
    {
	
		strcpy((yyval.ELEMENTO).trad,intr_variable((yyvsp[-3].ELEMENTO).tipo, (yyvsp[-4].indice)->nombre,(yyvsp[-2].ELEMENTO).espun)); //Traducción
			
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
			
		if ((yyvsp[-4].indice)->escons==0)	{
			(yyval.ELEMENTO).tipo=(yyvsp[-3].ELEMENTO).tipo;
			(yyvsp[-4].indice)->tipo=(yyvsp[-3].ELEMENTO).tipo;
			strcpy((yyval.ELEMENTO).nombre,(yyvsp[-4].indice)->nombre);
			(yyvsp[-4].indice)->espun=(yyvsp[-2].ELEMENTO).espun;
			}
		else yyerror("Error: %s ---Variable ya declarada como constante\n",(yyvsp[-4].indice)->nombre);             
	}
#line 1733 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 327 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).espun=1;
	}
#line 1741 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 331 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).espun=0;
	}
#line 1749 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 339 "trans.y" /* yacc.c:1646  */
    {
		//printf($3.res);
	
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"}\n");
		
		//printf("\n%s\n",$$.trad);
	}
#line 1762 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 352 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1770 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 356 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 1779 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 363 "trans.y" /* yacc.c:1646  */
    {
		//printf("%s \n",$6.nombre);
		if((yyvsp[-3].ELEMENTO).tipo==1)
			strcpy((yyval.ELEMENTO).trad,"float ");
		if((yyvsp[-3].ELEMENTO).tipo==6||(yyvsp[-3].ELEMENTO).tipo==3)
			strcpy((yyval.ELEMENTO).trad,"int ");
		if((yyvsp[-3].ELEMENTO).tipo==2)
			strcpy((yyval.ELEMENTO).trad,"char *");
			
		strcat((yyval.ELEMENTO).trad,(yyvsp[-7].indice)->nombre);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-6].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"{\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		//printf("\n%s\n",$$.trad);
	}
#line 1801 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 381 "trans.y" /* yacc.c:1646  */
    {//Puede no haber funciones
		strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1809 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 389 "trans.y" /* yacc.c:1646  */
    {	
		strcpy((yyval.ELEMENTO).trad,"(");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,")");
	}
#line 1819 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 395 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"(");
		strcat((yyval.ELEMENTO).trad,")");
	}
#line 1828 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 403 "trans.y" /* yacc.c:1646  */
    {

		strcpy((yyval.ELEMENTO).trad,intr_argumento((yyvsp[-2].ELEMENTO).tipo, (yyvsp[-3].indice)->nombre,(yyvsp[-1].ELEMENTO).espun)); //Traducción
	if ((yyvsp[-3].indice)->escons==0) {
		(yyval.ELEMENTO).tipo=(yyvsp[-2].ELEMENTO).tipo;
		(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).nombre,(yyvsp[-3].indice)->nombre);
		(yyvsp[-3].indice)->espun=(yyvsp[-1].ELEMENTO).espun;
		}
	else yyerror("Error: %s ---Variable ya declarada como constante\n",(yyvsp[-3].indice)->nombre);
	}
#line 1844 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 416 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,intr_argumento((yyvsp[-3].ELEMENTO).tipo, (yyvsp[-4].indice)->nombre,(yyvsp[-2].ELEMENTO).espun)); //Traducción
		strcat((yyval.ELEMENTO).trad,", ");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
			
		if ((yyvsp[-4].indice)->escons==0)	{
			(yyval.ELEMENTO).tipo=(yyvsp[-3].ELEMENTO).tipo;
			(yyvsp[-4].indice)->tipo=(yyvsp[-3].ELEMENTO).tipo;
			strcpy((yyval.ELEMENTO).nombre,(yyvsp[-4].indice)->nombre);
			(yyvsp[-4].indice)->espun=(yyvsp[-2].ELEMENTO).espun;
			}
		else yyerror("Error: %s ---Variable ya declarada como constante\n",(yyvsp[-4].indice)->nombre);
	}
#line 1862 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 434 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=(yyvsp[-1].ELEMENTO).tipo;
		switch ((yyvsp[-1].ELEMENTO).tipo){
		case 1: (yyval.ELEMENTO).valnum = (yyvsp[-1].ELEMENTO).valnum;break;
		case 2:	strcpy((yyval.ELEMENTO).valstr,(yyvsp[-1].ELEMENTO).valstr);break;
		case 3: (yyval.ELEMENTO).valbool = (yyvsp[-1].ELEMENTO).valbool;break;
		case 4: strcat((yyval.ELEMENTO).valstr,(yyvsp[-1].ELEMENTO).cad);
			//fprintf(salida,"%s",$1.trad);
			break;
		case 6: (yyval.ELEMENTO).valint = (yyvsp[-1].ELEMENTO).valint;break;
		}
		
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);	
		
		strcpy((yyval.ELEMENTO).res,(yyvsp[-1].ELEMENTO).res);	
	}
#line 1883 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 454 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=(yyvsp[-2].ELEMENTO).tipo;
		
		switch ((yyvsp[-2].ELEMENTO).tipo){
			case 1: (yyval.ELEMENTO).valnum = (yyvsp[-2].ELEMENTO).valnum;break;
			case 2:	strcpy((yyval.ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valstr);break;
			case 3: (yyval.ELEMENTO).valbool = (yyvsp[-2].ELEMENTO).valbool;break;
			case 4: strcat((yyval.ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).cad);
				//fprintf(salida,"%s",$1.trad);
				break;
			case 6: (yyval.ELEMENTO).valint = (yyvsp[-2].ELEMENTO).valint;break;
		}	
				
		 strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		 
		 strcat((yyval.ELEMENTO).res,(yyvsp[0].ELEMENTO).res);
	}
#line 1905 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 477 "trans.y" /* yacc.c:1646  */
    {		
		(yyval.ELEMENTO).tipo=(yyvsp[0].ELEMENTO).tipo;
		switch ((yyvsp[0].ELEMENTO).tipo){
			case 1: (yyval.ELEMENTO).valnum = (yyvsp[0].ELEMENTO).valnum;break;
			case 2:	strcpy((yyval.ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valstr);break;
			case 3: (yyval.ELEMENTO).valbool = (yyvsp[0].ELEMENTO).valbool;break;
			case 4: strcpy((yyval.ELEMENTO).valstr,(yyvsp[0].ELEMENTO).cad);break; 
			case 6: (yyval.ELEMENTO).valint = (yyvsp[0].ELEMENTO).valint;break;
		}
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);//Se limpia .trad
	}
#line 1921 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 491 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1930 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 496 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1938 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 500 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1946 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 506 "trans.y" /* yacc.c:1646  */
    {
		//printf("%s",$1.cad);
		strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1955 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 513 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-3].indice)->nombre);
		strcat((yyval.ELEMENTO).trad,"(");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
	}
#line 1966 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 523 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1974 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 527 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad,", ");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1983 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 535 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
			
		copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint);
	
		insertar(auxnodo1,auxnodo2,OP_SI,auxvar);
	}
#line 1995 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 546 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"if (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,")\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 2006 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 555 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"if (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-4].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,")\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"} else {\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2019 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 565 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"while (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,") {\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		//while($2.valbool)
			//strcpy($$.res,$4.res);
	}
#line 2033 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 576 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"do {\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"} while(");		
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");		
	}
#line 2045 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 585 "trans.y" /* yacc.c:1646  */
    {
		//printf("%s",intr_para($2->nombre,$4.trad,$6.trad));
		
		char signo[3]=">";
		char op[3];
		int ini;
		int obj;
		int i;
		
		//Se comprueba si el valor objetivo es mayor o menor que el inicial para 
		//Hacer el for bien
		if(atoi((yyvsp[-4].ELEMENTO).trad)>atoi((yyvsp[-2].ELEMENTO).trad)) {
			strcpy(signo,">");
			strcpy(op,"--");
			}
		else if(atoi((yyvsp[-4].ELEMENTO).trad)<atoi( (yyvsp[-2].ELEMENTO).trad)) {
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
		strcat((yyval.ELEMENTO).trad,(yyvsp[-6].indice)->nombre);
		strcat((yyval.ELEMENTO).trad,"=");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-4].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,";");		
		strcat((yyval.ELEMENTO).trad,(yyvsp[-6].indice)->nombre);
		strcat((yyval.ELEMENTO).trad,signo);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,";");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-6].indice)->nombre);
		strcat((yyval.ELEMENTO).trad,op);
		strcat((yyval.ELEMENTO).trad,")");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		ini=atoi((yyvsp[-4].ELEMENTO).trad);
		obj=atoi((yyvsp[-2].ELEMENTO).trad);
		
		for(i=ini;i<obj;i++)
			printf("%s",(yyvsp[0].ELEMENTO).res);
	}
#line 2101 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 638 "trans.y" /* yacc.c:1646  */
    {				
		int aux=(yyvsp[0].ELEMENTO).tipo;
		int compro;
		
		while(aux>0) {
			compro= aux%10;
			if((yyvsp[-1].indice)->tipo==compro) {//no se hace nada, tipos compatibles
			}else if (compro==9) {//no se hace nada, default
			}else if ( ((yyvsp[-1].indice)->tipo==1 && compro== 6) || ((yyvsp[-1].indice)->tipo==6 && compro== 1) ) {
			//Se puede comparar float con entero sin error
			}
		 	else {
			yyerror("Error: al menos uno de los casos del switch no concuerda en tipo con la variable");
			}
			aux=aux/10;
		}
		
		//Si todo está bien se traduce y saca por pantalla
		
		strcpy((yyval.ELEMENTO).trad,"switch (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].indice)->nombre);
		strcat((yyval.ELEMENTO).trad,"){\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2130 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 666 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=(yyvsp[-2].ELEMENTO).tipo;
		
		strcpy((yyval.ELEMENTO).trad,"case ");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,":\n");		
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);		
	}
#line 2144 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 676 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);		
		(yyval.ELEMENTO).tipo=9;
	}
#line 2155 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 687 "trans.y" /* yacc.c:1646  */
    {
		auxtip*=10;	//Se va aumentando esta variable para guardar los tipos en el mismo número
		//De esta manera tenemos un número cuyas unidades, decenas ... representan un tipo
	}
#line 2164 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 692 "trans.y" /* yacc.c:1646  */
    {
	
		(yyval.ELEMENTO).tipo+=(yyvsp[0].ELEMENTO).tipo*auxtip;
	
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 2176 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 703 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"default:\n");
	}
#line 2184 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 709 "trans.y" /* yacc.c:1646  */
    {
		//fprintf(salida,"break;\n");
		strcpy((yyval.ELEMENTO).trad,"break;\n");
	}
#line 2193 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 717 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"{\n");
	}
#line 2201 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 722 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"{\n");
	}
#line 2209 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 729 "trans.y" /* yacc.c:1646  */
    {
		//fprintf(salida,"}\n");
		strcpy((yyval.ELEMENTO).trad,"}\n");
		
		insertar(auxnodo1,auxnodo2,OP_FIN,auxvar);
	}
#line 2220 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 740 "trans.y" /* yacc.c:1646  */
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
	
	copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint);
	
	insertar(auxnodo1,auxnodo2,OP_ASIGNAR,auxvar);
	}
#line 2261 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 779 "trans.y" /* yacc.c:1646  */
    { 
		(yyval.ELEMENTO).vis=2;//*
	}
#line 2269 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 782 "trans.y" /* yacc.c:1646  */
    { 
		(yyval.ELEMENTO).vis=3;//&
	}
#line 2277 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 785 "trans.y" /* yacc.c:1646  */
    {
	}
#line 2284 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 793 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).vis=(yyvsp[0].ELEMENTO).vis;	
	(yyval.ELEMENTO).tipo=(yyvsp[0].ELEMENTO).tipo;
	
	switch ((yyvsp[0].ELEMENTO).tipo){
	case 1: 
		strcpy((yyval.ELEMENTO).trad,"printf(\" %%f \\n\",");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
		auxnodo1.valnum=(yyvsp[0].ELEMENTO).valnum;
		strcpy(auxnodo1.cad,(yyvsp[0].ELEMENTO).trad);
		break;
	case 2:					
		strcpy((yyval.ELEMENTO).trad,"printf(\" %%s \\n\",");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
		strcpy(auxnodo1.valstr,(yyvsp[0].ELEMENTO).valstr);
		strcpy(auxnodo1.cad,(yyvsp[0].ELEMENTO).trad);
		break;
	case 3: 
		auxnodo1.valint=(yyvsp[0].ELEMENTO).valint;
		strcpy(auxnodo1.cad,(yyvsp[0].ELEMENTO).trad);
		if((yyvsp[0].ELEMENTO).valbool==1) {
		 	strcpy((yyval.ELEMENTO).trad,"printf(\" TRUE \\n\");\n");
			break;
		 }
		else if((yyvsp[0].ELEMENTO).valbool==0) {
			strcpy((yyval.ELEMENTO).trad,"printf(\" TRUE \\n\");\n");
			break;
			}
	case 4: 
		strcpy((yyval.ELEMENTO).trad,"printf(\"");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).cad);
		strcat((yyval.ELEMENTO).trad,"\\n\");\n");
		strcpy(auxnodo1.valstr,(yyvsp[0].ELEMENTO).valstr);
		strcpy(auxnodo1.cad,(yyvsp[0].ELEMENTO).trad);
		break;
	case 6: 
		strcpy((yyval.ELEMENTO).trad,"printf(\" %%s \\n\",");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
		auxnodo1.valint=(yyvsp[0].ELEMENTO).valint;
		strcpy(auxnodo1.cad,(yyvsp[0].ELEMENTO).trad);
		break;
	default: 
		yyerror("Error:Imposible visualizar la variable o expresion\n");
		break;
	}//switch
	

	copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint);
	
	insertar(auxnodo1,auxnodo2,OP_ESCRIBIR,auxvar);
}
#line 2343 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 852 "trans.y" /* yacc.c:1646  */
    {
	
	strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 2352 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 859 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad,(yyvsp[-3].ELEMENTO).trad);
	strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 2361 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 867 "trans.y" /* yacc.c:1646  */
    {
	//strcpy($$.res,"\n");
	
	strcpy((yyval.ELEMENTO).trad,"printf(\"\\n\");");
	strcat((yyval.ELEMENTO).trad,"\n");
	}
#line 2372 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 878 "trans.y" /* yacc.c:1646  */
    {	
	strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2380 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 885 "trans.y" /* yacc.c:1646  */
    {	
	strcpy((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2389 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 889 "trans.y" /* yacc.c:1646  */
    {}
#line 2395 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 897 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,vis_entrada((yyvsp[-1].indice)->tipo,(yyvsp[-1].indice)->nombre,(yyvsp[-1].indice)->espun));//Traducción
	}
#line 2403 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 906 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," + ");//Traducción
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	if (((yyvsp[-2].ELEMENTO).tipo==1) && ((yyvsp[0].ELEMENTO).tipo==1)){
		(yyval.ELEMENTO).tipo=1;
		(yyval.ELEMENTO).valnum = (yyvsp[-2].ELEMENTO).valnum + (yyvsp[0].ELEMENTO).valnum;
	}
	else if(((yyvsp[-2].ELEMENTO).tipo==2) && ((yyvsp[0].ELEMENTO).tipo==2)){
		(yyval.ELEMENTO).tipo=2;
		strcpy((yyval.ELEMENTO).valstr,strcat((yyvsp[-2].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valstr));
	}
	else if(((yyvsp[-2].ELEMENTO).tipo==2) && ((yyvsp[0].ELEMENTO).tipo==4)){
		(yyval.ELEMENTO).tipo=2;
		strcpy((yyval.ELEMENTO).valstr,strcat((yyvsp[-2].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).cad));
	}
	else if(((yyvsp[-2].ELEMENTO).tipo==4) && ((yyvsp[0].ELEMENTO).tipo==2)){
		(yyval.ELEMENTO).tipo=2;
		strcpy((yyval.ELEMENTO).valstr,strcat((yyvsp[-2].ELEMENTO).cad,(yyvsp[0].ELEMENTO).valstr));
	}
	else if(((yyvsp[-2].ELEMENTO).tipo==4) && ((yyvsp[0].ELEMENTO).tipo==4)){
		(yyval.ELEMENTO).tipo=4;
		strcpy((yyval.ELEMENTO).cad,strcat((yyvsp[-2].ELEMENTO).cad,(yyvsp[0].ELEMENTO).cad));
	}
	else if(((yyvsp[-2].ELEMENTO).tipo==6) && ((yyvsp[0].ELEMENTO).tipo==6)){
		(yyval.ELEMENTO).tipo=6;
		(yyval.ELEMENTO).valint = (yyvsp[-2].ELEMENTO).valint + (yyvsp[0].ELEMENTO).valint;
	}
	else if(((yyvsp[-2].ELEMENTO).tipo==1) && ((yyvsp[0].ELEMENTO).tipo==6)){
		(yyval.ELEMENTO).tipo=1;
		(yyval.ELEMENTO).valnum = (yyvsp[-2].ELEMENTO).valnum + (yyvsp[0].ELEMENTO).valint;
	}
	else if(((yyvsp[-2].ELEMENTO).tipo==6) && ((yyvsp[0].ELEMENTO).tipo==1)){
		(yyval.ELEMENTO).tipo=1;
		(yyval.ELEMENTO).valnum = (yyvsp[-2].ELEMENTO).valint + (yyvsp[0].ELEMENTO).valnum;
	}
	else
	yyerror("Error: Operaciones sobre tipos diferentes\n");
	}
#line 2446 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 948 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," - ");//introducimos la cadena creada para la traduccion
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		if (((yyvsp[-2].ELEMENTO).tipo==1) && ((yyvsp[0].ELEMENTO).tipo==1)) {
			(yyval.ELEMENTO).tipo=1;
			(yyval.ELEMENTO).valnum = (yyvsp[-2].ELEMENTO).valnum - (yyvsp[0].ELEMENTO).valnum;
			}
		else if(((yyvsp[-2].ELEMENTO).tipo==6) && ((yyvsp[0].ELEMENTO).tipo==6)){
			(yyval.ELEMENTO).tipo=6;
			(yyval.ELEMENTO).valint = (yyvsp[-2].ELEMENTO).valint - (yyvsp[0].ELEMENTO).valint;
		}
		else if(((yyvsp[-2].ELEMENTO).tipo==1) && ((yyvsp[0].ELEMENTO).tipo==6)){
			(yyval.ELEMENTO).tipo=1;
			(yyval.ELEMENTO).valnum = (yyvsp[-2].ELEMENTO).valnum - (yyvsp[0].ELEMENTO).valint;
		}
		else if(((yyvsp[-2].ELEMENTO).tipo==6) && ((yyvsp[0].ELEMENTO).tipo==1)){
			(yyval.ELEMENTO).tipo=1;
			(yyval.ELEMENTO).valnum = (yyvsp[-2].ELEMENTO).valint - (yyvsp[0].ELEMENTO).valnum;
		}
		else {                   
		yyerror("Error: Operaciones sobre tipos diferentes\n");
		}
	}
#line 2474 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 974 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," * ");//Traducción
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		if (((yyvsp[-2].ELEMENTO).tipo==1) && ((yyvsp[0].ELEMENTO).tipo==1))	{
			(yyval.ELEMENTO).tipo=1;
			(yyval.ELEMENTO).valnum = (yyvsp[-2].ELEMENTO).valnum * (yyvsp[0].ELEMENTO).valnum;
		}
		else if(((yyvsp[-2].ELEMENTO).tipo==6) && ((yyvsp[0].ELEMENTO).tipo==6)){
			(yyval.ELEMENTO).tipo=6;
			(yyval.ELEMENTO).valint = (yyvsp[-2].ELEMENTO).valint * (yyvsp[0].ELEMENTO).valint;
		}
		else if(((yyvsp[-2].ELEMENTO).tipo==1) && ((yyvsp[0].ELEMENTO).tipo==6)){
			(yyval.ELEMENTO).tipo=1;
			(yyval.ELEMENTO).valnum = (yyvsp[-2].ELEMENTO).valnum * (yyvsp[0].ELEMENTO).valint;
		}
		else if(((yyvsp[-2].ELEMENTO).tipo==6) && ((yyvsp[0].ELEMENTO).tipo==1)){
			(yyval.ELEMENTO).tipo=1;
			(yyval.ELEMENTO).valnum = (yyvsp[-2].ELEMENTO).valint * (yyvsp[0].ELEMENTO).valnum;
		}		
		else {		                   
		yyerror("Error: Operaciones sobre tipos diferentes\n");
		}
	}
#line 2503 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1001 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," / ");//Traducción
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

		if ((yyvsp[0].ELEMENTO).valnum == 0)
			yyerror("División por cero.\n");
		else if (((yyvsp[-2].ELEMENTO).tipo==1) && ((yyvsp[0].ELEMENTO).tipo==1))		{
			(yyval.ELEMENTO).tipo=1;
			(yyval.ELEMENTO).valnum = (yyvsp[-2].ELEMENTO).valnum / (yyvsp[0].ELEMENTO).valnum;
		}
		else if(((yyvsp[-2].ELEMENTO).tipo==6) && ((yyvsp[0].ELEMENTO).tipo==6)){
			(yyval.ELEMENTO).tipo=6;
			(yyval.ELEMENTO).valint = (yyvsp[-2].ELEMENTO).valint / (yyvsp[0].ELEMENTO).valint;
		}
		else if(((yyvsp[-2].ELEMENTO).tipo==1) && ((yyvsp[0].ELEMENTO).tipo==6)){
			(yyval.ELEMENTO).tipo=1;
			(yyval.ELEMENTO).valnum = (yyvsp[-2].ELEMENTO).valnum / (yyvsp[0].ELEMENTO).valint;
		}
		else if(((yyvsp[-2].ELEMENTO).tipo==6) && ((yyvsp[0].ELEMENTO).tipo==1)){
			(yyval.ELEMENTO).tipo=1;
			(yyval.ELEMENTO).valnum = (yyvsp[-2].ELEMENTO).valint / (yyvsp[0].ELEMENTO).valnum;
		}
		else	{		                  
			yyerror("Error: Operaciones sobre tipos diferentes\n");
		}
	}
#line 2534 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1030 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad," -");//introducimos la cadena creada para la traduccion
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

		if ((yyvsp[0].ELEMENTO).tipo==1)	{
			(yyval.ELEMENTO).tipo=1;
			(yyval.ELEMENTO).valnum = -(yyvsp[0].ELEMENTO).valnum;
		}
		else if ((yyvsp[0].ELEMENTO).tipo==6) {
			(yyval.ELEMENTO).tipo=6;
			(yyval.ELEMENTO).valint = -(yyvsp[0].ELEMENTO).valint;
		}
		else	{                               
		yyerror("Error: Operaciones sobre tipos diferentes\n");
		}
	}
#line 2555 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1050 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad," TK_POW");//Traducción
		strcpy(auxt,"(");
		strcat(auxt,(yyvsp[-2].ELEMENTO).trad);
		strcat(auxt,",");
		strcat(auxt,(yyvsp[0].ELEMENTO).trad);
		strcat(auxt,")");
		strcat((yyval.ELEMENTO).trad,auxt);

		if (((yyvsp[-2].ELEMENTO).tipo==1)&& ((yyvsp[0].ELEMENTO).tipo==1))
		{
		(yyval.ELEMENTO).tipo=1;
		(yyval.ELEMENTO).valnum = pow((yyvsp[-2].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valnum);
		}
		else if(((yyvsp[-2].ELEMENTO).tipo==6) && ((yyvsp[0].ELEMENTO).tipo==6)){
			(yyval.ELEMENTO).tipo=6;
			(yyval.ELEMENTO).valint = pow((yyvsp[-2].ELEMENTO).valint,(yyvsp[0].ELEMENTO).valint);
		}
		else if(((yyvsp[-2].ELEMENTO).tipo==1) && ((yyvsp[0].ELEMENTO).tipo==6)){
			(yyval.ELEMENTO).tipo=1;
			(yyval.ELEMENTO).valnum = pow((yyvsp[-2].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint);
		}
		else if(((yyvsp[-2].ELEMENTO).tipo==6) && ((yyvsp[0].ELEMENTO).tipo==1)){
			(yyval.ELEMENTO).tipo=1;
			(yyval.ELEMENTO).valnum = pow((yyvsp[-2].ELEMENTO).valint,(yyvsp[0].ELEMENTO).valnum);
		}
		else {
			yyerror("Error: Operaciones sobre tipos diferentes\n");
		}
	}
#line 2590 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1083 "trans.y" /* yacc.c:1646  */
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
	}
#line 2608 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1100 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," < ");//Traducción
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	(yyval.ELEMENTO).tipo=3;//Se asigna el tipo bool
	if (((yyvsp[-2].ELEMENTO).tipo)==((yyvsp[0].ELEMENTO).tipo))
	{ 	
		if ((yyvsp[-2].ELEMENTO).tipo==1)//si es real
		{
			if ((yyvsp[-2].ELEMENTO).valnum<(yyvsp[0].ELEMENTO).valnum) (yyval.ELEMENTO).valbool=1 ;
			else (yyval.ELEMENTO).valbool=0;
		} 
		else if((yyvsp[-2].ELEMENTO).tipo==2)//si es string
		{
			if (strcmp((yyvsp[-2].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valstr)<0) (yyval.ELEMENTO).valbool =1; 
			else (yyval.ELEMENTO).valbool=0;
		} 	
		else if((yyvsp[-2].ELEMENTO).tipo==4)//si es cte cadena
		{
			if (strcmp((yyvsp[-2].ELEMENTO).cad,(yyvsp[0].ELEMENTO).cad)<0) (yyval.ELEMENTO).valbool =1; 
			else (yyval.ELEMENTO).valbool=0;
		}
		else if((yyvsp[-2].ELEMENTO).tipo==6)//si es entero
		{
			if ((yyvsp[-2].ELEMENTO).valint<(yyvsp[0].ELEMENTO).valint) (yyval.ELEMENTO).valbool=1 ;
			else (yyval.ELEMENTO).valbool=0;
		}
	}	

	else if (((yyvsp[-2].ELEMENTO).tipo==2)&&((yyvsp[0].ELEMENTO).tipo==4))//cadena y constante
	{
		if (strcmp((yyvsp[-2].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).cad)<0) (yyval.ELEMENTO).valbool =1; 
		else (yyval.ELEMENTO).valbool=0;
	}
	else if (((yyvsp[-2].ELEMENTO).tipo==4)&&((yyvsp[0].ELEMENTO).tipo==2))//constante y cadena
	{
		if (strcmp((yyvsp[-2].ELEMENTO).cad,(yyvsp[0].ELEMENTO).valstr)<0) (yyval.ELEMENTO).valbool =1; 
		else (yyval.ELEMENTO).valbool=0;
	}
	else if (((yyvsp[-2].ELEMENTO).tipo==6)&&((yyvsp[0].ELEMENTO).tipo==1))//constante y cadena
	{
		if ((yyvsp[-2].ELEMENTO).valint<(yyvsp[0].ELEMENTO).valnum) (yyval.ELEMENTO).valbool =1; 
		else (yyval.ELEMENTO).valbool=0;
	}
	else if (((yyvsp[-2].ELEMENTO).tipo==1)&&((yyvsp[0].ELEMENTO).tipo==6))//constante y cadena
	{
		if ((yyvsp[-2].ELEMENTO).valnum<(yyvsp[0].ELEMENTO).valint) (yyval.ELEMENTO).valbool =1; 
		else (yyval.ELEMENTO).valbool=0;
	}
	else yyerror("Error: Operaciones sobre tipos diferentes\n"); 
	}
#line 2664 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1154 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," > ");//introducimos la cadena creada para la traduccion
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

		(yyval.ELEMENTO).tipo=3;//asigno tipo bool
		if (((yyvsp[-2].ELEMENTO).tipo)==((yyvsp[0].ELEMENTO).tipo))
		{ 	
			if ((yyvsp[-2].ELEMENTO).tipo==1)//si es numero
			{
			if ((yyvsp[-2].ELEMENTO).valnum>(yyvsp[0].ELEMENTO).valnum) (yyval.ELEMENTO).valbool =1 ;
			else (yyval.ELEMENTO).valbool=0;
			} 
			else if((yyvsp[-2].ELEMENTO).tipo==2)//si es string
			{
			if (strcmp((yyvsp[-2].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valstr)>0) (yyval.ELEMENTO).valbool =1; 
			else (yyval.ELEMENTO).valbool=0;
			} 	
			else if((yyvsp[-2].ELEMENTO).tipo==4)//si es cte cadena
			{
				if (strcmp((yyvsp[-2].ELEMENTO).cad,(yyvsp[0].ELEMENTO).cad)>0) (yyval.ELEMENTO).valbool =1; 
				else (yyval.ELEMENTO).valbool=0;
			}
			else if((yyvsp[-2].ELEMENTO).tipo==6)//si es cte cadena
			{
				if ((yyvsp[-2].ELEMENTO).valint>(yyvsp[0].ELEMENTO).valint) (yyval.ELEMENTO).valbool =1 ;
				else (yyval.ELEMENTO).valbool=0;
			} 	 	
		}	

		else if (((yyvsp[-2].ELEMENTO).tipo==2)&&((yyvsp[0].ELEMENTO).tipo==4))//cadena y constante
		{
		if (strcmp((yyvsp[-2].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).cad)>0) (yyval.ELEMENTO).valbool =1; 
		else (yyval.ELEMENTO).valbool=0;
		}
		else if (((yyvsp[-2].ELEMENTO).tipo==4)&&((yyvsp[0].ELEMENTO).tipo==2))//constante y cadena
		{
			if (strcmp((yyvsp[-2].ELEMENTO).cad,(yyvsp[0].ELEMENTO).valstr)>0) (yyval.ELEMENTO).valbool =1; 
			else (yyval.ELEMENTO).valbool=0;
		}
		else if (((yyvsp[-2].ELEMENTO).tipo==6)&&((yyvsp[0].ELEMENTO).tipo==1))//constante y cadena
		{
			if ((yyvsp[-2].ELEMENTO).valint>(yyvsp[0].ELEMENTO).valnum) (yyval.ELEMENTO).valbool =1; 
			else (yyval.ELEMENTO).valbool=0;
		}
			else if (((yyvsp[-2].ELEMENTO).tipo==1)&&((yyvsp[0].ELEMENTO).tipo==6))//constante y cadena
		{
			if ((yyvsp[-2].ELEMENTO).valnum>(yyvsp[0].ELEMENTO).valint) (yyval.ELEMENTO).valbool =1; 
			else (yyval.ELEMENTO).valbool=0;
		}

		else yyerror("Error: Operaciones sobre tipos diferentes\n"); 
	}
#line 2721 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1209 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," >= ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	(yyval.ELEMENTO).tipo=3;//asigno tipo bool
	if (((yyvsp[-2].ELEMENTO).tipo)==((yyvsp[0].ELEMENTO).tipo))
	{ 	
		if ((yyvsp[-2].ELEMENTO).tipo==1)//si es numero
		{
			if ((yyvsp[-2].ELEMENTO).valnum>=(yyvsp[0].ELEMENTO).valnum) (yyval.ELEMENTO).valbool =1 ;
			else (yyval.ELEMENTO).valbool=0;
		} 
		else if((yyvsp[-2].ELEMENTO).tipo==2)//si es string
		{
			if (strcmp((yyvsp[-2].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valstr)>=0) (yyval.ELEMENTO).valbool =1; 
			else (yyval.ELEMENTO).valbool=0;
		} 	
		else if((yyvsp[-2].ELEMENTO).tipo==4)//si es cte cadena
		{
			if (strcmp((yyvsp[-2].ELEMENTO).cad,(yyvsp[0].ELEMENTO).cad)>=0) (yyval.ELEMENTO).valbool =1; 
			else (yyval.ELEMENTO).valbool=0;
		} 	
		else if ((yyvsp[-2].ELEMENTO).tipo==6)//si es numero
		{
			if ((yyvsp[-2].ELEMENTO).valint>=(yyvsp[0].ELEMENTO).valint) (yyval.ELEMENTO).valbool =1 ;
			else (yyval.ELEMENTO).valbool=0;
		} 
	}	

	else if (((yyvsp[-2].ELEMENTO).tipo==2)&&((yyvsp[0].ELEMENTO).tipo==4))//cadena y constante
	{
		if (strcmp((yyvsp[-2].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).cad)>=0) (yyval.ELEMENTO).valbool =1; 
		else (yyval.ELEMENTO).valbool=0;
	}
	else if (((yyvsp[-2].ELEMENTO).tipo==4)&&((yyvsp[0].ELEMENTO).tipo==2))//constante y cadena
	{
		if (strcmp((yyvsp[-2].ELEMENTO).cad,(yyvsp[0].ELEMENTO).valstr)>=0) (yyval.ELEMENTO).valbool =1; 
		else (yyval.ELEMENTO).valbool=0;
	}
		else if (((yyvsp[-2].ELEMENTO).tipo==6)&&((yyvsp[0].ELEMENTO).tipo==1))//constante y cadena
	{
		if ((yyvsp[-2].ELEMENTO).valint>=(yyvsp[0].ELEMENTO).valnum) (yyval.ELEMENTO).valbool =1; 
		else (yyval.ELEMENTO).valbool=0;
	}
		else if (((yyvsp[-2].ELEMENTO).tipo==1)&&((yyvsp[0].ELEMENTO).tipo==6))//constante y cadena
	{
		if ((yyvsp[-2].ELEMENTO).valnum>=(yyvsp[0].ELEMENTO).valint) (yyval.ELEMENTO).valbool =1; 
		else (yyval.ELEMENTO).valbool=0;
	}

	else yyerror("Error: Operaciones sobre tipos diferentes\n"); 
	}
#line 2778 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1264 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," <= ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	(yyval.ELEMENTO).tipo=3;//asigno tipo bool
	if (((yyvsp[-2].ELEMENTO).tipo)==((yyvsp[0].ELEMENTO).tipo))
	{ 	
		if ((yyvsp[-2].ELEMENTO).tipo==1)//si es numero
		{
		if ((yyvsp[-2].ELEMENTO).valnum<=(yyvsp[0].ELEMENTO).valnum) (yyval.ELEMENTO).valbool =1 ;
			else (yyval.ELEMENTO).valbool=0;
		} 
		else if((yyvsp[-2].ELEMENTO).tipo==2)//si es string
		{
			if (strcmp((yyvsp[-2].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valstr)<=0) (yyval.ELEMENTO).valbool =1; 
			else (yyval.ELEMENTO).valbool=0;
		} 	
		else if((yyvsp[-2].ELEMENTO).tipo==4)//si es cte cadena
		{
			if (strcmp((yyvsp[-2].ELEMENTO).cad,(yyvsp[0].ELEMENTO).cad)<=0) (yyval.ELEMENTO).valbool =1; 
			else (yyval.ELEMENTO).valbool=0;
		} 	
		if ((yyvsp[-2].ELEMENTO).tipo==6)//si es numero
		{
			if ((yyvsp[-2].ELEMENTO).valint<=(yyvsp[0].ELEMENTO).valint) (yyval.ELEMENTO).valbool =1 ;
			else (yyval.ELEMENTO).valbool=0;
		} 
	}	

	else if (((yyvsp[-2].ELEMENTO).tipo==2)&&((yyvsp[0].ELEMENTO).tipo==4))//cadena y constante
	{
		if (strcmp((yyvsp[-2].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).cad)<=0) (yyval.ELEMENTO).valbool =1; 
		else (yyval.ELEMENTO).valbool=0;
	}
	else if (((yyvsp[-2].ELEMENTO).tipo==4)&&((yyvsp[0].ELEMENTO).tipo==2))//constante y cadena
	{
		if (strcmp((yyvsp[-2].ELEMENTO).cad,(yyvsp[0].ELEMENTO).valstr)<=0) (yyval.ELEMENTO).valbool =1; 
		else (yyval.ELEMENTO).valbool=0;
	}
	else if (((yyvsp[-2].ELEMENTO).tipo==6)&&((yyvsp[0].ELEMENTO).tipo==1))//constante y cadena
	{
		if ((yyvsp[-2].ELEMENTO).valint>=(yyvsp[0].ELEMENTO).valnum) (yyval.ELEMENTO).valbool =1; 
		else (yyval.ELEMENTO).valbool=0;
	}
		else if (((yyvsp[-2].ELEMENTO).tipo==1)&&((yyvsp[0].ELEMENTO).tipo==6))//constante y cadena
	{
		if ((yyvsp[-2].ELEMENTO).valnum>=(yyvsp[0].ELEMENTO).valint) (yyval.ELEMENTO).valbool =1; 
		else (yyval.ELEMENTO).valbool=0;
	}

	else yyerror("Error: Operaciones sobre tipos diferentes\n");                                  
}
#line 2835 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1319 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," != ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	(yyval.ELEMENTO).tipo=3;//asigno tipo bool
	if (((yyvsp[-2].ELEMENTO).tipo)==((yyvsp[0].ELEMENTO).tipo))
	{ 	
		if ((yyvsp[-2].ELEMENTO).tipo==1)//si es numero
		{
			if ((yyvsp[-2].ELEMENTO).valnum!=(yyvsp[0].ELEMENTO).valnum) (yyval.ELEMENTO).valbool =1 ;
			else (yyval.ELEMENTO).valbool=0;
		} 
		else if((yyvsp[-2].ELEMENTO).tipo==2)//si es string
		{
			if (strcmp((yyvsp[-2].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valstr)!=0) (yyval.ELEMENTO).valbool =1; 
			else (yyval.ELEMENTO).valbool=0;
		} 	
		else if((yyvsp[-2].ELEMENTO).tipo==4)//si es cte cadena
		{
			if (strcmp((yyvsp[-2].ELEMENTO).cad,(yyvsp[0].ELEMENTO).cad)!=0) (yyval.ELEMENTO).valbool =1; 
			else (yyval.ELEMENTO).valbool=0;
		}
		if ((yyvsp[-2].ELEMENTO).tipo==6)//si es numero
		{
			if ((yyvsp[-2].ELEMENTO).valint!=(yyvsp[0].ELEMENTO).valint) (yyval.ELEMENTO).valbool =1 ;
			else (yyval.ELEMENTO).valbool=0;
		} 
	}	

	else if (((yyvsp[-2].ELEMENTO).tipo==2)&&((yyvsp[0].ELEMENTO).tipo==4))//cadena y constante
	{
	if (strcmp((yyvsp[-2].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).cad)!=0) (yyval.ELEMENTO).valbool =1; 
	else (yyval.ELEMENTO).valbool=0;
	}
	else if (((yyvsp[-2].ELEMENTO).tipo==4)&&((yyvsp[0].ELEMENTO).tipo==2))//constante y cadena
	{
	if (strcmp((yyvsp[-2].ELEMENTO).cad,(yyvsp[0].ELEMENTO).valstr)!=0) (yyval.ELEMENTO).valbool =1; 
	else (yyval.ELEMENTO).valbool=0;
	}
	else if (((yyvsp[-2].ELEMENTO).tipo==6)&&((yyvsp[0].ELEMENTO).tipo==1))//constante y cadena
	{
		if ((yyvsp[-2].ELEMENTO).valint!=(yyvsp[0].ELEMENTO).valnum) (yyval.ELEMENTO).valbool =1; 
		else (yyval.ELEMENTO).valbool=0;
	}
	else if (((yyvsp[-2].ELEMENTO).tipo==1)&&((yyvsp[0].ELEMENTO).tipo==6))//constante y cadena
	{
		if ((yyvsp[-2].ELEMENTO).valnum!=(yyvsp[0].ELEMENTO).valint) (yyval.ELEMENTO).valbool =1; 
		else (yyval.ELEMENTO).valbool=0;
	}

	else yyerror("Error: Operaciones sobre tipos diferentes\n");                                  
	}
#line 2892 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1374 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," == ");//introducimos la cadena creada para la traduccion
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		(yyval.ELEMENTO).tipo=3;
		

		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint);
		insertarexp(auxnodo1,auxnodo2,OP_IGUALDAD);
	}
#line 2907 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1391 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," && ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	if (((yyvsp[-2].ELEMENTO).tipo==3) && ((yyvsp[0].ELEMENTO).tipo==3))
	{
	(yyval.ELEMENTO).tipo=3;
	(yyval.ELEMENTO).valbool = (yyvsp[-2].ELEMENTO).valbool && (yyvsp[0].ELEMENTO).valbool;
	}
	else yyerror("Error: Operaciones sobre tipos diferentes\n");
	}
#line 2923 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1406 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," || ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	if (((yyvsp[-2].ELEMENTO).tipo==3) && ((yyvsp[0].ELEMENTO).tipo==3))
	{
		(yyval.ELEMENTO).tipo=3;
		(yyval.ELEMENTO).valbool = (yyvsp[-2].ELEMENTO).valbool || (yyvsp[0].ELEMENTO).valbool;
	}
	else yyerror("Error: Operaciones sobre tipos diferentes\n");
	}
#line 2939 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1422 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad," !");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	if ((yyvsp[0].ELEMENTO).tipo==3) 
	{
		(yyval.ELEMENTO).tipo=3;
		(yyval.ELEMENTO).valbool = !(yyvsp[0].ELEMENTO).valbool;
	}
	else yyerror("Error: Operaciones sobre tipos diferentes\n");	
	}
#line 2955 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1436 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=1;
		(yyval.ELEMENTO).valnum =(yyvsp[0].ELEMENTO).valnum;	  
	}
#line 2964 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1443 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=6;
		
		(yyval.ELEMENTO).valint =(yyvsp[0].ELEMENTO).valint;	
	}
#line 2974 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1451 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=3;
		(yyval.ELEMENTO).valbool= (yyvsp[0].ELEMENTO).valbool;
	}
#line 2983 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1458 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].indice)->nombre);//copio el nombre de la variable para la traduccion
		strcpy((yyval.ELEMENTO).valstr,(yyvsp[0].indice)->valstr);//strign
		strcpy((yyval.ELEMENTO).cad,(yyvsp[0].indice)->cad);//cadena, esto es por los identificadores de las constantes
		(yyval.ELEMENTO).valnum=(yyvsp[0].indice)->valnum;	//variable numerica
		(yyval.ELEMENTO).valbool=(yyvsp[0].indice)->valbool;//variable de tipo booleano
		(yyval.ELEMENTO).valint=(yyvsp[0].indice)->valint;//variable de tipo entero
		(yyval.ELEMENTO).tipo=(yyvsp[0].indice)->tipo;//tipo de la variable
		(yyval.ELEMENTO).escons=(yyvsp[0].indice)->escons; //Nos dice si es una cosntante o no                    
		(yyval.ELEMENTO).vis=(yyvsp[0].indice)->aux;//para traducir la visualizacion
		(yyval.ELEMENTO).espun= (yyvsp[0].indice)->espun;
	}
#line 3000 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1473 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=(yyvsp[0].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).valstr,(yyvsp[0].ELEMENTO).cad);
		(yyval.ELEMENTO).escons=(yyvsp[0].ELEMENTO).escons;
	}
#line 3010 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1482 "trans.y" /* yacc.c:1646  */
    {
		if((yyvsp[0].ELEMENTO).tipo==6) {
			intr_inc((yyvsp[0].ELEMENTO).nombre,0);
			(yyval.ELEMENTO).valint=(yyvsp[0].ELEMENTO).valint;		
			(yyval.ELEMENTO).tipo=(yyvsp[0].ELEMENTO).tipo;
			}
		else
			yyerror("Error: No se puede incrementar una variable no númerica");
	}
#line 3024 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1494 "trans.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].ELEMENTO).tipo==6) {
			intr_inc((yyvsp[-1].ELEMENTO).nombre,1);
			(yyval.ELEMENTO).valint=(yyvsp[-1].ELEMENTO).valint;
			(yyval.ELEMENTO).tipo=(yyvsp[-1].ELEMENTO).tipo;
			}
		else
			yyerror("Error: No se puede incrementar una variable no númerica");
	}
#line 3038 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1506 "trans.y" /* yacc.c:1646  */
    {
		if((yyvsp[0].ELEMENTO).tipo==6) {
			intr_dec((yyvsp[0].ELEMENTO).nombre,0);
			(yyval.ELEMENTO).valint=(yyvsp[0].ELEMENTO).valint;		
			(yyval.ELEMENTO).tipo=(yyvsp[0].ELEMENTO).tipo;
			}
		else
			yyerror("Error: No se puede decrementar una variable no númerica");
	}
#line 3052 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1518 "trans.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].ELEMENTO).tipo==6) {
			intr_dec((yyvsp[-1].ELEMENTO).nombre,1);
			(yyval.ELEMENTO).valint=(yyvsp[-1].ELEMENTO).valint;
			(yyval.ELEMENTO).tipo=(yyvsp[-1].ELEMENTO).tipo;
			}
		else
			yyerror("Error: No se puede decrementar una variable no númerica");
	}
#line 3066 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1529 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"*");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 3075 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1534 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"&");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 3084 "trans.tab.c" /* yacc.c:1646  */
    break;


#line 3088 "trans.tab.c" /* yacc.c:1646  */
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
#line 1539 "trans.y" /* yacc.c:1906  */

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
	
	if(INICIO==NULL)
		printf("\nError, programa vacio.\n");
	else
		ejecutar();
}

int ejecutar() {
	ARBOL *aux;
	extern com;
	extern fin;
	NODO *variable;
	aux=INICIO;
	
	do {
		switch(aux->op){
		case OP_ESCRIBIR:
			if(aux->izq!=NULL) 
				aux->exp1=procesarexp(aux->izq);

			switch (aux->exp1.tipo){
				case 1:
					if(aux->exp1.escons) {
						printf("%f\n",aux->exp1.valnum);
					}
					else {
						variable=buscar_simbolo(aux->exp1.cad,&com,&fin);
						printf("%f\n",variable->valnum);
					}
					break;
				case 2:	
					if(aux->exp1.escons) {
						printf("%s\n",aux->exp1.valstr);
					}
					else {
						variable=buscar_simbolo(aux->exp1.cad,&com,&fin);
						printf("%s\n",variable->valstr);
					}
					break;
				case 3:
					if(aux->exp1.escons) {
						printf("%d\n",aux->exp1.valbool);
					}
					else {
						variable=buscar_simbolo(aux->exp1.cad,&com,&fin);
						printf("%d\n",variable->valbool);
					}
					break;
				case 4:	
					if(aux->exp1.escons) {
						printf("%s\n",aux->exp1.valstr);
					}
					else {
						variable=buscar_simbolo(aux->exp1.cad,&com,&fin);
						printf("%s\n",variable->valstr);
					}
					break;
				case 6: 
					if(aux->exp1.escons) {
						printf("%d\n",aux->exp1.valint);
					}
					else {
						variable=buscar_simbolo(aux->exp1.cad,&com,&fin);
						printf("%d\n",variable->valint);
					}
					break;
			}//switch
			break;
		case OP_ASIGNAR:		
			if ((aux->var->tipo==aux->exp1.tipo)&&(aux->var->escons==0)&&(aux->var->espun==0)) {
				aux->var->tipo=aux->exp1.tipo;
				strcpy(aux->var->valstr,aux->exp1.valstr);
				aux->var->valbool= aux->exp1.valbool;
				aux->var->valnum = aux->exp1.valnum;
				aux->var->valint = aux->exp1.valint;
			}
			else if((aux->var->tipo=2)&&(aux->exp1.tipo==4)&&(aux->var->escons==0)&&(aux->var->espun==0)) {	
				strcpy(aux->var->valstr,aux->exp1.valstr);
			}
			else yyerror("Error en la asignación, no concuerdan los tipos o %s es constante\n",aux->exp1.nombre);	
			break;
		case OP_SI:		
			if (aux->exp1.tipo != 3){
				yyerror("Error en el si\n");
				break;
				}
				
			if(aux->izq!=NULL) 
				aux->exp1=procesarexp(aux->izq);	
			
			if(aux->exp1.valbool==0) {
				while(aux->der->op!=OP_FIN) {
					aux=aux->der;
				}
			}
				
			break;
		}//switch
		aux=aux->der;
	}while(aux!=NULL);
}//función

NODO procesarexp(ARBOL *aux){
	NODO retorno;
	do {
		switch(aux->op){
			case OP_IGUALDAD:
				retorno.tipo=3;//asigno tipo bool
				if ((aux->exp1.tipo)==(aux->exp2.tipo))
				{ 	
					if (aux->exp1.tipo==1)//si es numero
					{
						if (aux->exp1.valnum!=aux->exp2.valnum) retorno.valbool =0 ;
						else retorno.valbool=1;
					} 
					else if(aux->exp1.tipo==2)//si es string
					{
						if (strcmp(aux->exp1.valstr,aux->exp2.valstr)!=0) retorno.valbool =0; 
						else retorno.valbool=1;
					} 	
					else if(aux->exp1.tipo==4)//si es cte cadena
					{
						if (strcmp(aux->exp1.cad,aux->exp2.cad)!=0) retorno.valbool =0; 
						else retorno.valbool=1;
					}
					if (aux->exp1.tipo==6)//si es numero
					{
						if (aux->exp1.valint!=aux->exp2.valint) retorno.valbool =0 ;
						else retorno.valbool=1;
					} 
				}	

				else if ((aux->exp1.tipo==2)&&(aux->exp2.tipo==4))//cadena y constante
				{
				if (strcmp(aux->exp1.valstr,aux->exp2.cad)!=0) retorno.valbool =0; 
				else retorno.valbool=1;
				}
				else if ((aux->exp1.tipo==4)&&(aux->exp2.tipo==2))//constante y cadena
				{
				if (strcmp(aux->exp1.cad,aux->exp2.valstr)!=0) retorno.valbool =0; 
				else retorno.valbool=1;
				}
				else if ((aux->exp1.tipo==6)&&(aux->exp2.tipo==1))//constante y cadena
				{
					if (aux->exp1.valint!=aux->exp2.valnum) retorno.valbool =0; 
					else retorno.valbool=1;
				}
				else if ((aux->exp1.tipo==1)&&(aux->exp2.tipo==6))//constante y cadena
				{
					if (aux->exp1.valnum!=aux->exp2.valint) retorno.valbool =0; 
					else retorno.valbool=1;
				}
				else yyerror("Error: Operaciones sobre tipos diferentes\n");                                                            
				
				retorno.escons=1;
				retorno.espun=0;
				return retorno;
		}//switch
		aux=aux->izq;
	}while(aux!=NULL);
}//función
