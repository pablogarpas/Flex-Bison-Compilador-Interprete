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
int ejecutar(ARBOL *var,int parar);
NODO procesarexp(ARBOL *aux);
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
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

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
      59,    61,    52,    49,    60,    50,     2,    53,     2,     2,
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
       0,   101,   101,   116,   117,   121,   122,   127,   133,   142,
     154,   163,   175,   186,   196,   208,   220,   231,   242,   257,
     262,   266,   271,   280,   286,   292,   307,   325,   330,   337,
     350,   354,   361,   380,   387,   394,   401,   414,   432,   452,
     475,   489,   495,   499,   504,   511,   519,   527,   538,   550,
     554,   562,   568,   579,   591,   639,   651,   660,   671,   684,
     692,   720,   734,   747,   754,   765,   772,   779,   785,   791,
     802,   842,   845,   848,   855,   910,   917,   925,   936,   943,
     948,   955,   963,   976,   988,   999,  1010,  1021,  1037,  1051,
    1069,  1080,  1091,  1103,  1114,  1125,  1140,  1153,  1166,  1179,
    1187,  1195,  1203,  1219,  1227,  1234
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
  "TK_FIN", "TK_MOD", "TK_HACER", "TK_INC", "TK_DEC", "TK_FUNCION",
  "TK_CONT", "TK_DEFAULT", "TK_HASTA", "TK_ELSE", "TK_PARA", "TK_CASO",
  "TK_COM", "TK_CADENA", "TK_NBOOL", "TK_NUM", "TK_ENT", "TK_VARIABLE",
  "'='", "TK_MEI", "TK_MAI", "TK_DIS", "'<'", "'>'", "TK_ASIG", "'+'",
  "'-'", "TK_OR", "'*'", "'/'", "TK_AND", "TK_NOT", "MENOSUNARIO",
  "TK_POW", "'\\n'", "'('", "','", "')'", "$accept", "programa",
  "salto_lin", "salto_lin_dec", "cabecera", "librerias", "dec_constantes",
  "constante", "tipo", "dec_vbles", "variable", "puntero", "cuerpo",
  "funciones", "funcion", "dec_arg_fun", "argumento", "lista_sentencias",
  "sentencia", "decre", "llamar", "else", "control3", "control2",
  "control4", "control5", "control", "case", "cases", "default", "break",
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
     295,   296,    61,   297,   298,   299,    60,    62,   300,    43,
      45,   301,    42,    47,   302,   303,   304,   305,    10,    40,
      44,    41
};
# endif

#define YYPACT_NINF -109

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-109)))

#define YYTABLE_NINF -74

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -31,    21,  -109,   -17,  -109,    41,   -17,  -109,  -109,
     -17,    49,  -109,    27,   -17,    66,   -12,  -109,    31,   -17,
      46,   -17,   -17,   -17,   -17,    25,  -109,   228,    36,    46,
    -109,    27,    27,    27,    27,  -109,  -109,  -109,  -109,    62,
     159,   159,  -109,  -109,    20,    59,    43,    44,   159,   159,
      63,  -109,    81,   -17,  -109,    80,    80,    80,   -30,    85,
    -109,    71,  -109,  -109,   100,  -109,  -109,  -109,  -109,  -109,
    -109,   -17,   159,   159,  -109,  -109,  -109,  -109,  -109,   159,
     159,   159,   138,   138,   118,  -109,    73,    83,   138,   138,
      77,  -109,   201,  -109,   228,   228,   228,  -109,   159,   -30,
    -109,   228,  -109,  -109,    78,   -17,    49,    31,   138,   138,
      19,    19,     6,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,  -109,    60,    67,
     138,    74,    68,    92,  -109,   104,  -109,  -109,    95,  -109,
    -109,   -13,   102,   136,  -109,  -109,   138,   138,   138,   138,
     138,   138,   138,    17,    17,    17,    19,    19,    19,    19,
    -109,   159,  -109,   159,   122,  -109,   228,  -109,  -109,   159,
      25,  -109,    25,    99,   -43,   138,   121,  -109,  -109,   138,
      62,   -17,  -109,   159,  -109,  -109,   -17,   228,   138,   102,
      85,  -109,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     8,     4,     1,    10,     5,     7,     3,
       4,    24,     6,     0,     4,     0,     0,     9,     0,     4,
      33,     4,     4,     4,     4,     0,    23,    73,     0,     2,
      30,    14,    13,    11,    12,    19,    20,    22,    21,    28,
       0,     0,    72,    71,     0,     0,     0,     0,     0,     0,
       0,    44,     0,     4,    46,    68,    68,    68,     0,     0,
      40,     0,    42,    43,    35,    31,    18,    17,    15,    16,
      27,     4,     0,     0,   103,   101,    99,   100,   102,     0,
       0,     0,    52,    53,    80,    55,     0,     0,    47,    48,
       0,    29,    38,    67,    73,    73,    73,    65,     0,    63,
      60,    73,    69,    41,     0,     4,    24,    25,   105,   104,
      86,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    78,     0,
      74,     0,     0,     0,    39,    56,    58,    59,    73,    64,
      66,    73,     0,     0,    26,    89,    95,    88,    93,    92,
      94,    90,    91,    82,    83,    97,    84,    85,    96,    87,
      75,     0,    81,     0,     0,    51,    73,    66,    62,     0,
       0,    34,     0,    79,     0,    49,     0,    57,    61,    70,
      28,     4,    76,     0,    45,    54,     4,    73,    50,    36,
       0,    37,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,   -10,   155,  -109,  -109,  -109,    65,  -108,    58,
      79,   -15,  -109,  -109,   137,  -109,   -22,   -72,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,    70,  -109,
       5,   -19,   -20,  -109,    37,    32,  -109,  -109,  -109,   -33
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,     3,     6,    11,    17,    39,    15,
      26,    71,    20,    29,    30,   106,   171,    52,    53,    54,
     174,   166,    55,    56,    57,    58,    59,    99,   100,   101,
     168,    94,   103,    60,    61,   128,    62,   129,    63,   130
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    97,    42,    43,    18,    98,     1,    82,    83,    27,
       4,    31,    32,    33,    34,    88,    89,   183,   184,   113,
     134,     5,   135,   136,   137,    21,    22,    23,    24,   140,
     113,   114,   113,    35,    36,    37,    38,    95,    96,   108,
     109,     7,   114,    92,   114,    10,   110,   111,   112,   115,
     116,   117,   118,   119,    14,   120,   121,   122,   123,   124,
     125,   107,   180,   126,   181,   138,   167,   145,    16,   123,
     124,   125,    25,    19,   126,    28,   126,    64,    70,    84,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   177,   142,    66,    67,    68,    69,
      85,    40,    86,    87,    90,    91,    93,    41,   113,   102,
      42,    43,   104,    44,   131,   190,    45,    46,    47,   105,
     114,   160,    48,    49,   132,   133,   141,   161,   163,    50,
     175,    51,   164,    72,    73,   162,   179,   165,   115,   116,
     117,   118,   119,   170,   120,   121,   122,   123,   124,   125,
     188,   113,   126,   172,   176,    74,    75,    76,    77,    78,
     182,   185,    12,   114,   143,   186,    65,   191,    79,   139,
     192,   187,   178,    80,    72,    73,   189,    81,   169,   127,
       0,   115,   116,   117,   118,   119,   144,   120,   121,   122,
     123,   124,   125,   173,     0,   126,    74,    75,    76,    77,
      78,     0,     0,     0,     0,     0,     0,    40,     0,    79,
       0,     0,     0,    41,    80,     0,    42,    43,    81,    44,
       0,     0,    45,    46,    47,     0,     0,     0,    48,    49,
       0,     0,     0,     0,    40,    50,     0,    51,     0,     0,
      41,     0,   -73,    42,    43,     0,    44,     0,     0,    45,
      46,    47,     0,     0,     0,    48,    49,     0,     0,     0,
       0,     0,    50,     0,    51
};

static const yytype_int16 yycheck[] =
{
      10,    31,    15,    16,    14,    35,     3,    40,    41,    19,
      41,    21,    22,    23,    24,    48,    49,    60,    61,    13,
      92,     0,    94,    95,    96,    37,    38,    39,    40,   101,
      13,    25,    13,     8,     9,    10,    11,    56,    57,    72,
      73,    58,    25,    53,    25,     4,    79,    80,    81,    43,
      44,    45,    46,    47,     5,    49,    50,    51,    52,    53,
      54,    71,   170,    57,   172,    98,   138,    61,    41,    52,
      53,    54,    41,     7,    57,    29,    57,    41,    16,    59,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   166,   105,    31,    32,    33,    34,
      41,     6,    59,    59,    41,    24,    26,    12,    13,    24,
      15,    16,    41,    18,    41,   187,    21,    22,    23,    19,
      25,    61,    27,    28,    41,    48,    48,    60,    60,    34,
     163,    36,    40,    15,    16,    61,   169,    33,    43,    44,
      45,    46,    47,    41,    49,    50,    51,    52,    53,    54,
     183,    13,    57,    17,    32,    37,    38,    39,    40,    41,
      61,    40,     7,    25,   106,   180,    29,   189,    50,    99,
     190,   181,   167,    55,    15,    16,   186,    59,   141,    61,
      -1,    43,    44,    45,    46,    47,   107,    49,    50,    51,
      52,    53,    54,   161,    -1,    57,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    50,
      -1,    -1,    -1,    12,    55,    -1,    15,    16,    59,    18,
      -1,    -1,    21,    22,    23,    -1,    -1,    -1,    27,    28,
      -1,    -1,    -1,    -1,     6,    34,    -1,    36,    -1,    -1,
      12,    -1,    41,    15,    16,    -1,    18,    -1,    -1,    21,
      22,    23,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    63,    66,    41,     0,    67,    58,    64,    65,
       4,    68,    65,    64,     5,    71,    41,    69,    64,     7,
      74,    37,    38,    39,    40,    41,    72,    64,    29,    75,
      76,    64,    64,    64,    64,     8,     9,    10,    11,    70,
       6,    12,    15,    16,    18,    21,    22,    23,    27,    28,
      34,    36,    79,    80,    81,    84,    85,    86,    87,    88,
      95,    96,    98,   100,    41,    76,    69,    69,    69,    69,
      16,    73,    15,    16,    37,    38,    39,    40,    41,    50,
      55,    59,   101,   101,    59,    41,    59,    59,   101,   101,
      41,    24,    64,    26,    93,    93,    93,    31,    35,    89,
      90,    91,    24,    94,    41,    19,    77,    64,   101,   101,
     101,   101,   101,    13,    25,    43,    44,    45,    46,    47,
      49,    50,    51,    52,    53,    54,    57,    61,    97,    99,
     101,    41,    41,    48,    79,    79,    79,    79,   101,    90,
      79,    48,    64,    71,    72,    61,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
      61,    60,    61,    60,    40,    33,    83,    79,    92,    96,
      41,    78,    17,    97,    82,   101,    32,    79,    92,   101,
      70,    70,    61,    60,    61,    40,    73,    64,   101,    64,
      79,    78,    94
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    66,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      75,    75,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    80,    80,    80,    80,    80,    81,    81,    82,
      82,    83,    84,    85,    86,    87,    88,    88,    88,    88,
      88,    89,    89,    90,    90,    91,    92,    93,    93,    94,
      95,    96,    96,    96,    97,    98,    98,    98,    99,    99,
      99,   100,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     0,     1,     2,     3,     0,     3,
       0,     3,     3,     3,     3,     4,     4,     4,     4,     1,
       1,     1,     1,     3,     0,     4,     5,     1,     0,     4,
       1,     2,     9,     0,     3,     0,     4,     5,     2,     3,
       1,     2,     1,     1,     1,     6,     1,     2,     2,     1,
       3,     1,     2,     2,     6,     2,     3,     5,     3,     3,
       2,     4,     3,     1,     2,     1,     0,     1,     0,     1,
       5,     1,     1,     0,     1,     4,     6,     3,     1,     3,
       0,     4,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     1,
       1,     1,     1,     1,     2,     2
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
		
	}
#line 1460 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 116 "trans.y" /* yacc.c:1646  */
    {}
#line 1466 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 117 "trans.y" /* yacc.c:1646  */
    {}
#line 1472 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 121 "trans.y" /* yacc.c:1646  */
    {}
#line 1478 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 122 "trans.y" /* yacc.c:1646  */
    {}
#line 1484 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 128 "trans.y" /* yacc.c:1646  */
    {
		(yyvsp[-1].indice)->tipo=0;  	
	}
#line 1492 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 133 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"#include <stdio.h>\n#include <math.h>\n#include <stdlib.h>\n#include <string.h>");
	}
#line 1500 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 143 "trans.y" /* yacc.c:1646  */
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
#line 1516 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 154 "trans.y" /* yacc.c:1646  */
    {		
	strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1524 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 164 "trans.y" /* yacc.c:1646  */
    { //Un número
		strcpy((yyval.ELEMENTO).trad,intr_const_num((yyvsp[-1].ELEMENTO).valnum,(yyvsp[-2].indice)->nombre)); //La traducción
		(yyval.ELEMENTO).valnum=(yyvsp[-2].indice)->valnum=(yyvsp[-1].ELEMENTO).valnum;
		(yyval.ELEMENTO).tipo=(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		(yyval.ELEMENTO).escons=1;	
		(yyvsp[-2].indice)->escons=1;
		(yyvsp[-2].indice)->aux=3;//Cualquier número
	}
#line 1537 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 176 "trans.y" /* yacc.c:1646  */
    { //Un número
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-1].ELEMENTO).valint,(yyvsp[-2].indice)->nombre)); //La traducción
		(yyval.ELEMENTO).valint=(yyvsp[-2].indice)->valint=(yyvsp[-1].ELEMENTO).valint;
		(yyval.ELEMENTO).tipo=(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		(yyval.ELEMENTO).escons=1;	
		(yyvsp[-2].indice)->escons=1;
		(yyvsp[-2].indice)->aux=3;//Cualquier número
	}
#line 1550 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 187 "trans.y" /* yacc.c:1646  */
    { //Un número
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-1].ELEMENTO).valbool,(yyvsp[-2].indice)->nombre)); //La traducción
		(yyval.ELEMENTO).valbool=(yyvsp[-2].indice)->valbool=(yyvsp[-1].ELEMENTO).valbool;
		(yyval.ELEMENTO).tipo=(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		(yyval.ELEMENTO).escons=1;	
		(yyvsp[-2].indice)->escons=1;
		(yyvsp[-2].indice)->aux=3;//Cualquier número
	}
#line 1563 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 197 "trans.y" /* yacc.c:1646  */
    {//Constante cadena
		strcpy((yyval.ELEMENTO).trad,intr_const_cad((yyvsp[-1].ELEMENTO).cad,(yyvsp[-2].indice)->nombre)); //Traducción
		strcpy((yyval.ELEMENTO).cad,strcpy((yyvsp[-2].indice)->cad,(yyvsp[-1].ELEMENTO).cad));    
		(yyval.ELEMENTO).tipo=(yyvsp[-2].indice)->tipo=(yyvsp[-1].ELEMENTO).tipo;
		(yyval.ELEMENTO).escons=1;
		(yyvsp[-2].indice)->escons=1;
		(yyvsp[-2].indice)->aux=3;//Cualquier número
	}
#line 1576 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 209 "trans.y" /* yacc.c:1646  */
    { 
		strcpy((yyval.ELEMENTO).trad,intr_const_num((yyvsp[-2].ELEMENTO).valnum,(yyvsp[-3].indice)->nombre)); //Traducción
		(yyval.ELEMENTO).valnum=(yyvsp[-3].indice)->valnum=(yyvsp[-2].ELEMENTO).valnum;
		(yyval.ELEMENTO).tipo=(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		(yyval.ELEMENTO).escons=1;
		(yyvsp[-3].indice)->escons=1;
		(yyvsp[-3].indice)->aux=3;//Cualquier número
	}
#line 1589 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 221 "trans.y" /* yacc.c:1646  */
    { //Un número
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-2].ELEMENTO).valint,(yyvsp[-3].indice)->nombre)); //La traducción
		(yyval.ELEMENTO).valint=(yyvsp[-3].indice)->valint=(yyvsp[-2].ELEMENTO).valint;
		(yyval.ELEMENTO).tipo=(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		(yyval.ELEMENTO).escons=1;	
		(yyvsp[-3].indice)->escons=1;
		(yyvsp[-3].indice)->aux=3;//Cualquier número
	}
#line 1602 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 232 "trans.y" /* yacc.c:1646  */
    { //Un número
		strcpy((yyval.ELEMENTO).trad,intr_const_int((yyvsp[-2].ELEMENTO).valbool,(yyvsp[-3].indice)->nombre)); //La traducción
		(yyval.ELEMENTO).valbool=(yyvsp[-3].indice)->valbool=(yyvsp[-2].ELEMENTO).valbool;
		(yyval.ELEMENTO).tipo=(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		(yyval.ELEMENTO).escons=1;	
		(yyvsp[-3].indice)->escons=1;
		(yyvsp[-3].indice)->aux=3;//Cualquier número
	}
#line 1615 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 243 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,intr_const_cad((yyvsp[-2].ELEMENTO).cad,(yyvsp[-3].indice)->nombre));  //Traducción
		strcpy((yyval.ELEMENTO).cad,strcpy((yyvsp[-3].indice)->cad,(yyvsp[-2].ELEMENTO).cad));
		(yyval.ELEMENTO).escons=1;
		(yyval.ELEMENTO).tipo=(yyvsp[-3].indice)->tipo=(yyvsp[-2].ELEMENTO).tipo;
		(yyvsp[-3].indice)->escons=1;
		(yyvsp[-3].indice)->aux=3;//Cualquier número
	}
#line 1628 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 258 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=6; 
	}
#line 1636 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 263 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=1;}
#line 1643 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 267 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=2;
	}
#line 1651 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 272 "trans.y" /* yacc.c:1646  */
    {
	(yyval.ELEMENTO).tipo=3;
	}
#line 1659 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 281 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		(yyval.ELEMENTO).tipo=(yyvsp[0].ELEMENTO).tipo;
	}
#line 1669 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 286 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1677 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 293 "trans.y" /* yacc.c:1646  */
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
#line 1694 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 308 "trans.y" /* yacc.c:1646  */
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
#line 1713 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 326 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).espun=1;
	}
#line 1721 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 330 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).espun=0;
	}
#line 1729 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 338 "trans.y" /* yacc.c:1646  */
    {
		//printf($3.res);
	
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"}\n");
		
		//printf("\n%s\n",$$.trad);
	}
#line 1742 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 351 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1750 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 355 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 1759 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 362 "trans.y" /* yacc.c:1646  */
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
#line 1781 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 380 "trans.y" /* yacc.c:1646  */
    {//Puede no haber funciones
		strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1789 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 388 "trans.y" /* yacc.c:1646  */
    {	
		strcpy((yyval.ELEMENTO).trad,"(");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,")");
	}
#line 1799 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 394 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"(");
		strcat((yyval.ELEMENTO).trad,")");
	}
#line 1808 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 402 "trans.y" /* yacc.c:1646  */
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
#line 1824 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 415 "trans.y" /* yacc.c:1646  */
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
#line 1842 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 433 "trans.y" /* yacc.c:1646  */
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
#line 1863 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 453 "trans.y" /* yacc.c:1646  */
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
#line 1885 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 476 "trans.y" /* yacc.c:1646  */
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
#line 1901 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 490 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1910 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 495 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1918 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 499 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1926 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 505 "trans.y" /* yacc.c:1646  */
    {
		//printf("%s",$1.cad);
		strcpy((yyval.ELEMENTO).trad,"");
	}
#line 1935 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 512 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-3].indice)->nombre);
		strcat((yyval.ELEMENTO).trad,"(");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
	}
#line 1946 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 520 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1954 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 528 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).nombre);
		strcat((yyval.ELEMENTO).trad,"++;\n");
			
		strcpy(auxnodo1.nombre,(yyvsp[0].ELEMENTO).nombre);
	
		insertar(auxnodo1,auxnodo2,OP_INC,auxvar);
	}
#line 1967 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 539 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).nombre);
		strcat((yyval.ELEMENTO).trad,"--;\n");
	
		strcpy(auxnodo1.nombre,(yyvsp[0].ELEMENTO).nombre);
	
		insertar(auxnodo1,auxnodo2,OP_DEC,auxvar);
	}
#line 1980 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 551 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1988 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 555 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad,", ");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 1997 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 563 "trans.y" /* yacc.c:1646  */
    {
		insertar(auxnodo1,auxnodo2,OP_ELSE,auxvar);
	}
#line 2005 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 569 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
			
		copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	
		insertar(auxnodo1,auxnodo2,OP_SI,auxvar);
	}
#line 2017 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 580 "trans.y" /* yacc.c:1646  */
    {
	
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	
		insertar(auxnodo1,auxnodo2,OP_WHILE,auxvar);
	}
#line 2030 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 592 "trans.y" /* yacc.c:1646  */
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
#line 2079 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 639 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).nombre,(yyvsp[0].indice)->nombre);
		(yyval.ELEMENTO).tipo=(yyvsp[0].indice)->tipo;
		
		copiardatos(&auxnodo1,(yyvsp[0].indice)->tipo,(yyvsp[0].indice)->escons,(yyvsp[0].indice)->espun,(yyvsp[0].indice)->valstr,(yyvsp[0].indice)->valbool,(yyvsp[0].indice)->valnum,(yyvsp[0].indice)->valint,(yyvsp[0].indice)->nombre);
		
		insertar(auxnodo1,auxnodo2,OP_SWITCH,auxvar);
	}
#line 2092 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 652 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"if (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,")\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 2103 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 661 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"if (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-4].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,")\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,"} else {\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2116 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 672 "trans.y" /* yacc.c:1646  */
    {
	
		strcpy((yyval.ELEMENTO).trad,"while (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,") {\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		//while($2.valbool)
			//strcpy($$.res,$4.res);
	}
#line 2131 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 685 "trans.y" /* yacc.c:1646  */
    {		
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2141 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 693 "trans.y" /* yacc.c:1646  */
    {				
		int aux=(yyvsp[0].ELEMENTO).tipo;
		int compro;
		
		while(aux>0) {
			compro= aux%10;
			if((yyvsp[-1].ELEMENTO).tipo==compro) {//no se hace nada, tipos compatibles
			}else if (compro==9) {//no se hace nada, default
			}else if ( ((yyvsp[-1].ELEMENTO).tipo==1 && compro== 6) || ((yyvsp[-1].ELEMENTO).tipo==6 && compro== 1) ) {
			//Se puede comparar float con entero sin error
			}
		 	else {
			yyerror("Error: al menos uno de los casos del switch no concuerda en tipo con la variable");
			}
			aux=aux/10;
		}
		
		//Si todo está bien se traduce y saca por pantalla
		
		strcpy((yyval.ELEMENTO).trad,"switch (");
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).nombre);
		strcat((yyval.ELEMENTO).trad,"){\n");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2170 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 721 "trans.y" /* yacc.c:1646  */
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
#line 2188 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 735 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);		
		(yyval.ELEMENTO).tipo=9;
		
		insertar(auxnodo1,auxnodo2,OP_DEFAULT,auxvar);
	}
#line 2201 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 748 "trans.y" /* yacc.c:1646  */
    {
		auxtip*=10;	//Se va aumentando esta variable para guardar los tipos en el mismo número
		//De esta manera tenemos un número cuyas unidades, decenas ... representan un tipo
		
		
	}
#line 2212 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 755 "trans.y" /* yacc.c:1646  */
    {
	
		(yyval.ELEMENTO).tipo+=(yyvsp[0].ELEMENTO).tipo*auxtip;
	
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 2224 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 766 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"default:\n");
	}
#line 2232 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 772 "trans.y" /* yacc.c:1646  */
    {
		//fprintf(salida,"break;\n");
		strcpy((yyval.ELEMENTO).trad,"break;\n");
	}
#line 2241 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 780 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"{\n");
	}
#line 2249 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 785 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"{\n");
	}
#line 2257 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 792 "trans.y" /* yacc.c:1646  */
    {
		//fprintf(salida,"}\n");
		strcpy((yyval.ELEMENTO).trad,"}\n");
		
		insertar(auxnodo1,auxnodo2,OP_FIN,auxvar);
	}
#line 2268 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 803 "trans.y" /* yacc.c:1646  */
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
#line 2309 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 842 "trans.y" /* yacc.c:1646  */
    { 
		(yyval.ELEMENTO).vis=2;//*
	}
#line 2317 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 845 "trans.y" /* yacc.c:1646  */
    { 
		(yyval.ELEMENTO).vis=3;//&
	}
#line 2325 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 848 "trans.y" /* yacc.c:1646  */
    {
	}
#line 2332 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 856 "trans.y" /* yacc.c:1646  */
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
		auxnodo1.valbool=(yyvsp[0].ELEMENTO).valbool;
		strcpy(auxnodo1.valstr,(yyvsp[0].ELEMENTO).trad);
		strcpy((yyval.ELEMENTO).trad,"printf(\" %%d \\n\",");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
		break;
	case 4: 
		strcpy((yyval.ELEMENTO).trad,"printf(\"");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).cad);
		strcat((yyval.ELEMENTO).trad,"\\n\");\n");
		strcpy(auxnodo1.valstr,(yyvsp[0].ELEMENTO).valstr);
		strcpy(auxnodo1.cad,(yyvsp[0].ELEMENTO).trad);
		break;
	case 6: 
		strcpy((yyval.ELEMENTO).trad,"printf(\" %%d \\n\",");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		strcat((yyval.ELEMENTO).trad,");\n");
		auxnodo1.valint=(yyvsp[0].ELEMENTO).valint;
		strcpy(auxnodo1.cad,(yyvsp[0].ELEMENTO).trad);
		break;
	default: 
		yyerror("Error:Imposible visualizar la variable o expresion\n");
		break;
	}//switch
	

	copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	
	insertar(auxnodo1,auxnodo2,OP_ESCRIBIR,auxvar);
}
#line 2387 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 911 "trans.y" /* yacc.c:1646  */
    {
	
	strcpy((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 2396 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 918 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad,(yyvsp[-3].ELEMENTO).trad);
	strcat((yyval.ELEMENTO).trad,(yyvsp[-1].ELEMENTO).trad);
	}
#line 2405 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 926 "trans.y" /* yacc.c:1646  */
    {
	//strcpy($$.res,"\n");
	
	strcpy((yyval.ELEMENTO).trad,"printf(\"\\n\");");
	strcat((yyval.ELEMENTO).trad,"\n");
	}
#line 2416 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 937 "trans.y" /* yacc.c:1646  */
    {	
	strcpy((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2424 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 944 "trans.y" /* yacc.c:1646  */
    {	
	strcpy((yyval.ELEMENTO).trad,(yyvsp[-2].ELEMENTO).trad);
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2433 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 948 "trans.y" /* yacc.c:1646  */
    {}
#line 2439 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 956 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,vis_entrada((yyvsp[-1].indice)->tipo,(yyvsp[-1].indice)->nombre,(yyvsp[-1].indice)->espun));//Traducción
	}
#line 2447 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 965 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," + ");//Traducción
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	
	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_SUMA);
	}
#line 2460 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 977 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," - ");//introducimos la cadena creada para la traduccion
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
		insertarexp(auxnodo1,auxnodo2,OP_RESTA);
		
	}
#line 2474 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 989 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," * ");//Traducción
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		
	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_MULT);
	}
#line 2487 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1000 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," / ");//Traducción
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_DIV);
	}
#line 2500 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1011 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad," -");//introducimos la cadena creada para la traduccion
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_CAM);
	}
#line 2512 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1022 "trans.y" /* yacc.c:1646  */
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
#line 2530 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1038 "trans.y" /* yacc.c:1646  */
    {
		strcat(auxt,(yyvsp[-2].ELEMENTO).trad);
		strcat(auxt,"%");
		strcat(auxt,(yyvsp[0].ELEMENTO).trad);
		strcpy((yyval.ELEMENTO).trad,auxt);


		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
		insertarexp(auxnodo1,auxnodo2,OP_MOD);
	}
#line 2546 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1052 "trans.y" /* yacc.c:1646  */
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
#line 2565 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1070 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," < ");//Traducción
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_MENOR);
	}
#line 2578 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1081 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," > ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_MAYOR);
	}
#line 2591 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1092 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," >= ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	
	insertarexp(auxnodo1,auxnodo2,OP_MAI);
	}
#line 2605 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1104 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," <= ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_MEI);                                
}
#line 2618 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1115 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," != ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	
	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_DESIGUALDAD);                                 
	}
#line 2631 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1126 "trans.y" /* yacc.c:1646  */
    {
		strcat((yyval.ELEMENTO).trad," == ");//introducimos la cadena creada para la traduccion
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
		(yyval.ELEMENTO).tipo=3;
		

		copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
		copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
		insertarexp(auxnodo1,auxnodo2,OP_IGUALDAD);
	}
#line 2646 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1143 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," && ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	
	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_AND);
	}
#line 2659 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1155 "trans.y" /* yacc.c:1646  */
    {
	strcat((yyval.ELEMENTO).trad," || ");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	
	copiardatos(&auxnodo1,(yyvsp[-2].ELEMENTO).tipo,(yyvsp[-2].ELEMENTO).escons,(yyvsp[-2].ELEMENTO).espun,(yyvsp[-2].ELEMENTO).valstr,(yyvsp[-2].ELEMENTO).valbool,(yyvsp[-2].ELEMENTO).valnum,(yyvsp[-2].ELEMENTO).valint,(yyvsp[-2].ELEMENTO).nombre);
	copiardatos(&auxnodo2,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_OR);
	
	}
#line 2673 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1169 "trans.y" /* yacc.c:1646  */
    {
	strcpy((yyval.ELEMENTO).trad," !");//introducimos la cadena creada para la traduccion
	strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);

	
	copiardatos(&auxnodo1,(yyvsp[0].ELEMENTO).tipo,(yyvsp[0].ELEMENTO).escons,(yyvsp[0].ELEMENTO).espun,(yyvsp[0].ELEMENTO).valstr,(yyvsp[0].ELEMENTO).valbool,(yyvsp[0].ELEMENTO).valnum,(yyvsp[0].ELEMENTO).valint,(yyvsp[0].ELEMENTO).nombre);
	insertarexp(auxnodo1,auxnodo2,OP_NOT);	
	}
#line 2686 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1180 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=1;
		(yyval.ELEMENTO).escons=1;
		(yyval.ELEMENTO).valnum =(yyvsp[0].ELEMENTO).valnum;	  
	}
#line 2696 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1188 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=6;
		(yyval.ELEMENTO).escons=1;
		(yyval.ELEMENTO).valint =(yyvsp[0].ELEMENTO).valint;	
	}
#line 2706 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1196 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=3;
		(yyval.ELEMENTO).escons=1;
		(yyval.ELEMENTO).valbool= (yyvsp[0].ELEMENTO).valbool;
	}
#line 2716 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1204 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,(yyvsp[0].indice)->nombre);//copio el nombre de la variable para la traduccion
		strcpy((yyval.ELEMENTO).nombre,(yyvsp[0].indice)->nombre);//copio el nombre de la variable para la traduccion
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
#line 2734 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1220 "trans.y" /* yacc.c:1646  */
    {
		(yyval.ELEMENTO).tipo=(yyvsp[0].ELEMENTO).tipo;
		strcpy((yyval.ELEMENTO).valstr,(yyvsp[0].ELEMENTO).cad);
		(yyval.ELEMENTO).escons=(yyvsp[0].ELEMENTO).escons;
	}
#line 2744 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1228 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"*");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2753 "trans.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1235 "trans.y" /* yacc.c:1646  */
    {
		strcpy((yyval.ELEMENTO).trad,"&");
		strcat((yyval.ELEMENTO).trad,(yyvsp[0].ELEMENTO).trad);
	}
#line 2762 "trans.tab.c" /* yacc.c:1646  */
    break;


#line 2766 "trans.tab.c" /* yacc.c:1646  */
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
#line 1240 "trans.y" /* yacc.c:1906  */

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
		ejecutar(INICIO,0);
		
}

int ejecutar(ARBOL *var,int parar) {
	ARBOL *aux;
	extern com;
	extern fin;
	NODO *variable;
	int defecto;
	aux=var;
	
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
						variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
						printf("%f\n",variable->valnum);
					}
					break;
				case 2:	
					if(aux->exp1.escons) {
						printf("%s\n",aux->exp1.valstr);
					}
					else {
						variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
						printf("%s\n",variable->valstr);
					}
					break;
				case 3:
					if(aux->exp1.escons) {
						printf("%d\n",aux->exp1.valbool);
					}
					else {
						variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
						printf("%d\n",variable->valbool);
					}
					break;
				case 4:	
					if(aux->exp1.escons) {
						printf("%s\n",aux->exp1.valstr);
					}
					else {
						variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
						printf("%s\n",variable->valstr);
					}
					break;
				case 6: 
					if(aux->exp1.escons) {
						printf("%d\n",aux->exp1.valint);
					}
					else {
						variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
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
			else yyerror("Error en la asignación, no concuerdan los tipos o la variable es constante\n");	
			break;
		case OP_INC:
			if(aux->var->tipo==6) {			
				variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
				variable->valint=variable->valint+1;				
			}else if(aux->var->tipo==1) {
				variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
				variable->valnum=variable->valnum+1;
			}
			else
			yyerror("Error en el incremento: No se puede incrementar una variable no númerica");
			break;
		case OP_DEC:
			if(aux->var->tipo==6) {			
				variable=buscar(aux->exp1.nombre,&com,&fin);
				variable->valint=variable->valint-1;				
			}else if(aux->var->tipo==1) {
				variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
				variable->valnum=variable->valnum-1;
			}
			else
			yyerror("Error en el decremento: No se puede incrementar una variable no númerica");
			break;
		case OP_SI:		
			if(aux->izq!=NULL) 
				aux->exp1=procesarexp(aux->izq);	
			
			if(aux->exp1.valbool==0) {
				while(aux->op!=OP_ELSE) {
					aux=aux->der;
				}
			}
			break;
		case OP_ELSE:
			while(aux->der->op!=OP_FIN) {
					aux=aux->der;
				}
			break;
		case OP_WHILE:		
			if(aux->izq!=NULL) 
				aux->exp1=procesarexp(aux->izq);
			
			while(aux->exp1.valbool) {
				ejecutar(aux->der,1);
				aux->exp1=procesarexp(aux->izq);
				}
			break;
		case OP_PARA:
			
			variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
		
			variable->valint=aux->exp1.valint;
		
			while(variable->valint!= aux->exp2.valint) {
				ejecutar(aux->der,1);
				
				if(aux->exp1.valint < aux->exp2.valint)
					variable->valint++;
				if(aux->exp1.valint > aux->exp2.valint)
					variable->valint--;
			}
			break;
		case OP_SWITCH:
		
			variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
		
			while(aux->der->op!=OP_FIN) {
				if(aux->der->op==OP_DEFAULT) {
					if(defecto==0)
						ejecutar(aux,1);	
				}
			
				if(aux->der->op==OP_CASE && aux->der->exp1.valint==variable->valint) {
					ejecutar(aux,1);
					defecto=1;
				}
					
				aux=aux->der;
			}
			defecto=0;
			break;
		case OP_FIN:
			if(parar)
				return 1;
			break;
		case OP_CASE:
			if(parar)
				return 1;
			break;
		case OP_DEFAULT:
			if(parar)
				return 1;
			break;
		}//switch
		aux=aux->der;
	}while(aux!=NULL);
}//función

NODO procesarexp(ARBOL *aux){
	NODO retorno;
	NODO *variable;
	extern com;
	extern fin;
	int i,k;
	char *a,*b;
	float real1,real2;
	int bool1,bool2;
	
	a= malloc(sizeof(NODO));
	b= malloc(sizeof(NODO));
	
	switch(aux->op){
		case OP_IGUALDAD:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}
			
			retorno.tipo=3;//asigno tipo bool
			
			if ((aux->exp1.tipo)==(aux->exp2.tipo))
			{ 	
				if (aux->exp1.tipo==1)//si es numero
				{
					if (real1!=real2) retorno.valbool =0 ;
					else retorno.valbool=1;
				} 
				else if(aux->exp1.tipo==2)//si es string
				{
					if (strcmp(a,b)!=0) retorno.valbool =0; 
					else retorno.valbool=1;
				}
				if (aux->exp1.tipo==3)//si es numero
				{
					if (bool1!=bool2) retorno.valbool =0 ;
					else retorno.valbool=1;
				}  	
				else if(aux->exp1.tipo==4)//si es cte cadena
				{
					if (strcmp(aux->exp1.cad,aux->exp2.cad)!=0) retorno.valbool =0; 
					else retorno.valbool=1;
				}
				if (aux->exp1.tipo==6)//si es numero
				{
					if (i!=k) retorno.valbool =0 ;
					else retorno.valbool=1;
				} 
			}	

			else if ((aux->exp1.tipo==2)&&(aux->exp2.tipo==4))//cadena y constante
			{
			if (strcmp(a,aux->exp2.cad)!=0) retorno.valbool =0; 
			else retorno.valbool=1;
			}
			else if ((aux->exp1.tipo==4)&&(aux->exp2.tipo==2))//constante y cadena
			{
			if (strcmp(aux->exp1.cad,b)!=0) retorno.valbool =0; 
			else retorno.valbool=1;
			}
			else if ((aux->exp1.tipo==6)&&(aux->exp2.tipo==1))//constante y cadena
			{
				if (i!=real2) retorno.valbool =0; 
				else retorno.valbool=1;
			}
			else if ((aux->exp1.tipo==1)&&(aux->exp2.tipo==6))//constante y cadena
			{
				if (real1!=k) retorno.valbool =0; 
				else retorno.valbool=1;
			}
			else yyerror("Error en la desigualdad: Operaciones sobre tipos diferentes \n");                                                            
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_NOT:
			if (aux->exp1.tipo==3) 
			{
				retorno.tipo=3;
				if(aux->exp1.escons)
					retorno.valbool = !aux->exp1.valbool;
				else {
					variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
					retorno.valbool=!(variable->valbool);
				}
			}
			else yyerror("Error en la negación: Operaciones sobre tipos incorrectos\n");
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_OR:
			if ((aux->exp2.tipo==3) && (aux->exp2.tipo==3)) {
				retorno.tipo=3;
				if(!aux->exp1.escons) {
					variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
					i=variable->valbool;
				} else
					i=aux->exp1.valbool;
					
				if(!aux->exp2.escons) {
					variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
					k=variable->valbool;
				} else
					k=aux->exp2.valbool;
				
				retorno.valbool = (k || i);
			}
			else yyerror("Error en el OR: Operación sobre tipos diferentes\n");
			
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_AND:
			if ((aux->exp2.tipo==3) && (aux->exp2.tipo==3)) {
				retorno.tipo=3;
				if(!aux->exp1.escons) {
					variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
					i=variable->valbool;
				} else
					i=aux->exp1.valbool;
					
				if(!aux->exp2.escons) {
					variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
					k=variable->valbool;
				} else
					k=aux->exp2.valbool;
				
				retorno.valbool = (k && i);
			}
			else yyerror("Error en el AND: Operación sobre tipos diferentes\n");
			
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_DESIGUALDAD:		
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}
			
			retorno.tipo=3;//asigno tipo bool
			
			if ((aux->exp1.tipo)==(aux->exp2.tipo))
			{ 	
				if (aux->exp1.tipo==1)//si es numero
				{
					if (real1!=real2) retorno.valbool =0 ;
					else retorno.valbool=1;
				} 
				else if(aux->exp1.tipo==2)//si es string
				{
					if (strcmp(a,b)!=0) retorno.valbool =0; 
					else retorno.valbool=1;
				}
				if (aux->exp1.tipo==3)//si es numero
				{
					if (bool1!=bool2) retorno.valbool =0 ;
					else retorno.valbool=1;
				}  	
				else if(aux->exp1.tipo==4)//si es cte cadena
				{
					if (strcmp(aux->exp1.cad,aux->exp2.cad)!=0) retorno.valbool =0; 
					else retorno.valbool=1;
				}
				if (aux->exp1.tipo==6)//si es numero
				{
					if (i!=k) retorno.valbool =0 ;
					else retorno.valbool=1;
				} 
			}	

			else if ((aux->exp1.tipo==2)&&(aux->exp2.tipo==4))//cadena y constante
			{
			if (strcmp(a,aux->exp2.cad)!=0) retorno.valbool =0; 
			else retorno.valbool=1;
			}
			else if ((aux->exp1.tipo==4)&&(aux->exp2.tipo==2))//constante y cadena
			{
			if (strcmp(aux->exp1.cad,b)!=0) retorno.valbool =0; 
			else retorno.valbool=1;
			}
			else if ((aux->exp1.tipo==6)&&(aux->exp2.tipo==1))//constante y cadena
			{
				if (i!=real2) retorno.valbool =0; 
				else retorno.valbool=1;
			}
			else if ((aux->exp1.tipo==1)&&(aux->exp2.tipo==6))//constante y cadena
			{
				if (real1!=k) retorno.valbool =0; 
				else retorno.valbool=1;
			}
			else yyerror("Error en la desigualdad: Operaciones sobre tipos diferentes \n");                                                            
			retorno.valbool=!retorno.valbool;
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
			
		case OP_MENOR:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
			
				if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}
			
			//printf("%d\t%d\n",i,k);

			retorno.tipo=3;//Se asigna el tipo bool
			if ((aux->exp1.tipo)==(aux->exp2.tipo))
			{ 	
				if (aux->exp1.tipo==1)//si es real
				{
					if (real1<real2) retorno.valbool=1 ;
					else retorno.valbool=0;
				} 
				else if(aux->exp1.tipo==2)//si es string
				{
					if (strcmp(a,b)<0) retorno.valbool =1; 
					else retorno.valbool=0;
				} 	
				else if(aux->exp1.tipo==4)//si es cte cadena
				{
					if (strcmp(aux->exp1.cad,aux->exp2.cad)<0) retorno.valbool =1; 
					else retorno.valbool=0;
				}
				else if(aux->exp1.tipo==6)//si es entero
				{
					if (i<k) retorno.valbool=1 ;
					else retorno.valbool=0;
				}
			}	

			else if ((aux->exp1.tipo==2)&&(aux->exp2.tipo==4))//cadena y constante
			{
				if (strcmp(a,aux->exp2.cad)<0) retorno.valbool =1; 
				else retorno.valbool=0;
			}
			else if ((aux->exp1.tipo==4)&&(aux->exp2.tipo==2))//constante y cadena
			{
				if (strcmp(aux->exp1.cad,b)<0) retorno.valbool =1; 
				else retorno.valbool=0;
			}
			else if ((aux->exp1.tipo==6)&&(aux->exp2.tipo==1))//constante y cadena
			{
				if (i<real2) retorno.valbool =1; 
				else retorno.valbool=0;
			}
			else if ((aux->exp1.tipo==1)&&(aux->exp2.tipo==6))//constante y cadena
			{
				if (real1<k) retorno.valbool =1; 
				else retorno.valbool=0;
			}
			else yyerror("Error en el menor: Operaciones sobre tipos diferentes\n");
			retorno.tipo=3;
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_MAYOR:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}	
			
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}

			retorno.tipo=3;//asigno tipo bool
			if ((aux->exp1.tipo)==(aux->exp2.tipo))
			{ 	
				if (aux->exp1.tipo==1)//si es numero
				{
				if (real1>real2) retorno.valbool =1 ;
				else retorno.valbool=0;
				} 
				else if(aux->exp1.tipo==2)//si es string
				{
				if (strcmp(a,b)>0) retorno.valbool =1; 
				else retorno.valbool=0;
				} 	
				else if(aux->exp1.tipo==4)//si es cte cadena
				{
					if (strcmp(aux->exp1.cad,aux->exp2.cad)>0) retorno.valbool =1; 
					else retorno.valbool=0;
				}
				else if(aux->exp1.tipo==6)//si es cte cadena
				{
					if (i>k) retorno.valbool =1 ;
					else retorno.valbool=0;
				} 	 	
			}	

			else if ((aux->exp1.tipo==2)&&(aux->exp2.tipo==4))//cadena y constante
			{
			if (strcmp(a,aux->exp2.cad)>0) retorno.valbool =1; 
			else retorno.valbool=0;
			}
			else if ((aux->exp1.tipo==4)&&(aux->exp2.tipo==2))//constante y cadena
			{
				if (strcmp(aux->exp1.cad,b)>0) retorno.valbool =1; 
				else retorno.valbool=0;
			}
			else if ((aux->exp1.tipo==6)&&(aux->exp2.tipo==1))//constante y cadena
			{
				if (i>real2) retorno.valbool =1; 
				else retorno.valbool=0;
			}
				else if ((aux->exp1.tipo==1)&&(aux->exp2.tipo==6))//constante y cadena
			{
				if (real1>k) retorno.valbool =1; 
				else retorno.valbool=0;
			}

			else yyerror("Error en el mayor: Operaciones sobre tipos diferentes\n"); 
			retorno.tipo=3;
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_MAI:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}	
		
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}

		retorno.tipo=3;//asigno tipo bool
		if ((aux->exp1.tipo)==(aux->exp2.tipo))
		{ 	
			if (aux->exp1.tipo==1)//si es numero
			{
				if (real1>=real2) retorno.valbool =1 ;
				else retorno.valbool=0;
			} 
			else if(aux->exp1.tipo==2)//si es string
			{
				if (strcmp(a,b)>=0) retorno.valbool =1; 
				else retorno.valbool=0;
			} 	
			else if(aux->exp1.tipo==4)//si es cte cadena
			{
				if (strcmp(aux->exp1.cad,aux->exp2.cad)>=0) retorno.valbool =1; 
				else retorno.valbool=0;
			} 	
			else if (aux->exp1.tipo==6)//si es numero
			{
				if (i>=k) retorno.valbool =1 ;
				else retorno.valbool=0;
			} 
		}	

		else if ((aux->exp1.tipo==2)&&(aux->exp2.tipo==4))//cadena y constante
		{
			if (strcmp(a,aux->exp2.cad)>=0) retorno.valbool =1; 
			else retorno.valbool=0;
		}
		else if ((aux->exp1.tipo==4)&&(aux->exp2.tipo==2))//constante y cadena
		{
			if (strcmp(aux->exp1.cad,b)>=0) retorno.valbool =1; 
			else retorno.valbool=0;
		}
			else if ((aux->exp1.tipo==6)&&(aux->exp2.tipo==1))//constante y cadena
		{
			if (i>=real2) retorno.valbool =1; 
			else retorno.valbool=0;
		}
			else if ((aux->exp1.tipo==1)&&(aux->exp2.tipo==6))//constante y cadena
		{
			if (real1>=k) retorno.valbool =1; 
			else retorno.valbool=0;
		}

		else yyerror("Error en el mayor o igual: Operaciones sobre tipos diferentes\n"); 
			retorno.tipo=3;
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_MEI:
		if(aux->exp1.escons) {
			i=aux->exp1.valint;
			real1=aux->exp1.valnum;
			bool1=aux->exp1.valbool;
			strcpy(a,aux->exp1.valstr);
		} else {
			variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
			i=variable->valint;
			real1=variable->valnum;
			bool1=variable->valbool;
			strcpy(a,variable->valstr);
		}
			
		if(aux->exp2.escons) {
			k=aux->exp2.valint;
			real2=aux->exp2.valnum;
			bool2=aux->exp2.valbool;
			strcpy(b,aux->exp2.valstr);
		} else {
			variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
			k=variable->valint;
			real2=variable->valnum;
			bool2=variable->valbool;
			strcpy(b,variable->valstr);
		}

		retorno.tipo=3;//asigno tipo bool
		if ((aux->exp1.tipo)==(aux->exp2.tipo))
		{ 	
			if (aux->exp1.tipo==1)//si es numero
			{
			if (real1<=real2) retorno.valbool =1 ;
				else retorno.valbool=0;
			} 
			else if(aux->exp1.tipo==2)//si es string
			{
				if (strcmp(a,b)<=0) retorno.valbool =1; 
				else retorno.valbool=0;
			} 	
			else if(aux->exp1.tipo==4)//si es cte cadena
			{
				if (strcmp(aux->exp1.cad,aux->exp2.cad)<=0) retorno.valbool =1; 
				else retorno.valbool=0;
			} 	
			if (aux->exp1.tipo==6)//si es numero
			{
				if (i<=k) retorno.valbool =1 ;
				else retorno.valbool=0;
			} 
		}	

		else if ((aux->exp1.tipo==2)&&(aux->exp2.tipo==4))//cadena y constante
		{
			if (strcmp(a,aux->exp2.cad)<=0) retorno.valbool =1; 
			else retorno.valbool=0;
		}
		else if ((aux->exp1.tipo==4)&&(aux->exp2.tipo==2))//constante y cadena
		{
			if (strcmp(aux->exp1.cad,b)<=0) retorno.valbool =1; 
			else retorno.valbool=0;
		}
		else if ((aux->exp1.tipo==6)&&(aux->exp2.tipo==1))//constante y cadena
		{
			if (i>=real2) retorno.valbool =1; 
			else retorno.valbool=0;
		}
			else if ((aux->exp1.tipo==1)&&(aux->exp2.tipo==6))//constante y cadena
		{
			if (real1>=k) retorno.valbool =1; 
			else retorno.valbool=0;
		}

		else yyerror("Error en el menor o igual: Operaciones sobre tipos diferentes\n");
			retorno.tipo=3;
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_SUMA:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}

			if ((aux->exp1.tipo==1) && (aux->exp2.tipo==1)){
				retorno.tipo=1;
				retorno.valnum = real1 + real2;
			}
			else if((aux->exp1.tipo==2) && (aux->exp2.tipo==2)){
				retorno.tipo=2;
				strcpy(retorno.valstr,strcat(a,b));
			}
			else if((aux->exp1.tipo==2) && (aux->exp2.tipo==4)){
				retorno.tipo=2;
				strcpy(retorno.valstr,strcat(a,aux->exp2.cad));
			}
			else if((aux->exp1.tipo==4) && (aux->exp2.tipo==2)){
				retorno.tipo=2;
				strcpy(retorno.valstr,strcat(aux->exp1.cad,b));
			}
			else if((aux->exp1.tipo==4) && (aux->exp2.tipo==4)){
				retorno.tipo=4;
				strcpy(retorno.cad,strcat(aux->exp1.cad,aux->exp2.cad));
			}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==6)){
				retorno.tipo=6;
				retorno.valint = i + k;
			}
			else if((aux->exp1.tipo==1) && (aux->exp2.tipo==6)){
				retorno.tipo=1;
				retorno.valnum = real1 + k;
			}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==1)){
				retorno.tipo=1;
				retorno.valnum = i + real2;
			}
			else{
			yyerror("Error en la suma: Operaciones sobre tipos diferentes\n");
			}
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_RESTA:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}
			
			if ((aux->exp1.tipo==1) && (aux->exp2.tipo==1)) {
				retorno.tipo=1;
				retorno.valnum = real1 - real2;
				}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==6)){
				retorno.tipo=6;
				retorno.valint = i - k;
			}
			else if((aux->exp1.tipo==1) && (aux->exp2.tipo==6)){
				retorno.tipo=1;
				retorno.valnum = real1 - k;
			}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==1)){
				retorno.tipo=1;
				retorno.valnum = i - real2;
			}
			else {                   
			yyerror("Error en la resta: Operaciones sobre tipos diferentes\n");
			}
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_MULT:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}
			
				if ((aux->exp1.tipo==1) && (aux->exp2.tipo==1))	{
					retorno.tipo=1;
					retorno.valnum = real1 * real2;
				}
				else if((aux->exp1.tipo==6) && (aux->exp2.tipo==6)){
					retorno.tipo=6;
					retorno.valint = i * k;
				}
				else if((aux->exp1.tipo==1) && (aux->exp2.tipo==6)){
					retorno.tipo=1;
					retorno.valnum = real1 * k;
				}
				else if((aux->exp1.tipo==6) && (aux->exp2.tipo==1)){
					retorno.tipo=1;
					retorno.valnum = i * real2;
				}		
				else {		                   
				yyerror("Error en la multiplicación: Operaciones sobre tipos diferentes\n");
				}
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_DIV:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}

			if ((aux->exp1.tipo==1) && (aux->exp2.tipo==1))		{
				if (real2 == 0)
					yyerror("Error en la división: División por cero.\n");
				retorno.tipo=1;
				retorno.valnum = real1 / real2;
			}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==6)){
				if (k == 0)
					yyerror("Error en la división: División por cero.\n");			
				retorno.tipo=6;
				retorno.valint = i / k;
			}
			else if((aux->exp1.tipo==1) && (aux->exp2.tipo==6)){
				if (real2 == 0)
					yyerror("Error en la división: División por cero.\n");			
				retorno.tipo=1;
				retorno.valnum = real1 / k;
			}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==1)){
				if (k == 0)
					yyerror("Error en la división: División por cero.\n");
				retorno.tipo=1;
				retorno.valnum = i / real2;
			}
			else	{		                  
				yyerror("Error en la division: Operaciones sobre tipos diferentes\n");
			}
			
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_MOD:	
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}

			if ((aux->exp1.tipo==6)&& (aux->exp2.tipo==6)) {
				retorno.tipo=6;
				retorno.valint = i%k;
			}
			else {
				yyerror("Error: Operaciones sobre tipos diferentes\n");
			}
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_CAM:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}

			if (aux->exp1.tipo==1)	{
				retorno.tipo=1;
				retorno.valnum = -real1;
			}
			else if (aux->exp1.tipo==6) {
				retorno.tipo=6;
				retorno.valint = -i;
			}
			else	{                               
			yyerror("Error en el cambio de signo: Operaciones sobre tipos diferentes\n");
			}
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_POW:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}

			if ((aux->exp1.tipo==1)&& (aux->exp2.tipo==1))
			{
			retorno.tipo=1;
			retorno.valnum = pow(real1,real2);
			}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==6)){
				retorno.tipo=6;
				retorno.valint = pow(i,k);
			}
			else if((aux->exp1.tipo==1) && (aux->exp2.tipo==6)){
				retorno.tipo=1;
				retorno.valnum = pow(real1,k);
			}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==1)){
				retorno.tipo=1;
				retorno.valnum = pow(i,real2);
			}
			else {
				yyerror("Error en el exponencial: Operaciones sobre tipos diferentes\n");
			}
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
	}//switch
}//función
