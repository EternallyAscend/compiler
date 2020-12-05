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
#line 1 "c.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "table.h"
#include "grammerTree.h"
#include "y.tab.h"

#ifdef __cplusplus
extern "C" 

{
#endif
    extern FILE* yyin;
    void yyerror(const char *s);
    extern int yylex(void);
    extern char* yytext;

#ifdef __cplusplus
};
#endif

grammerTree* root;
grammerTree* curNode;
grammerTree* tempPointer;
grammerTree* stack[128];
int stackContentSize = 0;

void extendTree(int isTerminal, const char* word, const char* grammer);
void backToParent();
void extendOptTree(const char* opt);
void extendTerminal(const char* word, const char* grammer);
void broToParent(int num);
void connectParentChild();

void saveNode();
void loadNode();


#line 106 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    CONSTANT = 258,
    STRING_C = 259,
    PRINT = 260,
    INPUT = 261,
    IDENTIFIER = 262,
    LP = 263,
    RP = 264,
    LSB = 265,
    RSB = 266,
    LBP = 267,
    RBP = 268,
    POINTER = 269,
    ADDRESS = 270,
    NOT = 271,
    POW = 272,
    TIMES = 273,
    DIVIDE = 274,
    MOD = 275,
    PLUS = 276,
    MINUS = 277,
    GT = 278,
    LT = 279,
    GE = 280,
    LE = 281,
    EQ = 282,
    NE = 283,
    AND = 284,
    OR = 285,
    ASSIGN = 286,
    INT = 287,
    VOID = 288,
    COMMA = 289,
    SEMICOLON = 290,
    IF = 291,
    ELSE = 292,
    WHILE = 293,
    DO = 294,
    FOR = 295,
    CONTINUE = 296,
    BREAK = 297,
    RETURN = 298,
    STRUCT = 299,
    NONE_ELSE = 300
  };
#endif
/* Tokens.  */
#define CONSTANT 258
#define STRING_C 259
#define PRINT 260
#define INPUT 261
#define IDENTIFIER 262
#define LP 263
#define RP 264
#define LSB 265
#define RSB 266
#define LBP 267
#define RBP 268
#define POINTER 269
#define ADDRESS 270
#define NOT 271
#define POW 272
#define TIMES 273
#define DIVIDE 274
#define MOD 275
#define PLUS 276
#define MINUS 277
#define GT 278
#define LT 279
#define GE 280
#define LE 281
#define EQ 282
#define NE 283
#define AND 284
#define OR 285
#define ASSIGN 286
#define INT 287
#define VOID 288
#define COMMA 289
#define SEMICOLON 290
#define IF 291
#define ELSE 292
#define WHILE 293
#define DO 294
#define FOR 295
#define CONTINUE 296
#define BREAK 297
#define RETURN 298
#define STRUCT 299
#define NONE_ELSE 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 43 "c.y" /* yacc.c:355  */

    char* str;

#line 240 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   224

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  125
/* YYNRULES -- Number of rules.  */
#define YYNRULES  174
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  261

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   108,   108,   112,   114,   112,   117,   121,   125,   127,
     125,   130,   134,   138,   140,   138,   143,   147,   151,   153,
     151,   156,   160,   164,   164,   169,   169,   177,   181,   181,
     186,   186,   191,   191,   196,   196,   201,   205,   209,   211,
     209,   214,   216,   214,   219,   223,   227,   229,   227,   232,
     234,   232,   237,   239,   237,   242,   246,   250,   252,   250,
     255,   259,   259,   267,   267,   270,   274,   274,   279,   279,
     285,   291,   291,   296,   300,   303,   306,   306,   315,   320,
     323,   325,   315,   331,   334,   336,   331,   372,   373,   374,
     378,   379,   383,   384,   388,   392,   395,   398,   401,   388,
     411,   411,   419,   420,   424,   424,   427,   431,   434,   438,
     440,   438,   448,   449,   450,   451,   452,   453,   454,   454,
     455,   455,   458,   458,   461,   461,   466,   467,   469,   471,
     467,   475,   477,   475,   485,   486,   492,   492,   500,   501,
     505,   507,   505,   514,   519,   519,   527,   529,   527,   536,
     536,   541,   545,   549,   550,   554,   554,   563,   563,   568,
     572,   572,   580,   580,   589,   590,   594,   595,   599,   601,
     603,   599,   610,   610,   613
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONSTANT", "STRING_C", "PRINT", "INPUT",
  "IDENTIFIER", "LP", "RP", "LSB", "RSB", "LBP", "RBP", "POINTER",
  "ADDRESS", "NOT", "POW", "TIMES", "DIVIDE", "MOD", "PLUS", "MINUS", "GT",
  "LT", "GE", "LE", "EQ", "NE", "AND", "OR", "ASSIGN", "INT", "VOID",
  "COMMA", "SEMICOLON", "IF", "ELSE", "WHILE", "DO", "FOR", "CONTINUE",
  "BREAK", "RETURN", "STRUCT", "NONE_ELSE", "$accept", "expression",
  "comma_expression", "$@1", "$@2", "single_expression",
  "assign_expression", "$@3", "$@4", "orh_expression", "or_expression",
  "$@5", "$@6", "andh_expression", "and_expression", "$@7", "$@8",
  "eneh_expression", "ene_expression", "$@9", "$@10", "lgh_expression",
  "lg_expression", "$@11", "$@12", "$@13", "$@14", "pmh_expression",
  "pm_expression", "$@15", "$@16", "$@17", "$@18", "mtdh_expression",
  "mtd_expression", "$@19", "$@20", "$@21", "$@22", "$@23", "$@24",
  "powh_expression", "pow_expression", "$@25", "$@26", "noth_expression",
  "$@27", "not_expression", "$@28", "pid_expression", "$@29", "$@30",
  "pointer_expression", "$@31", "type_defination", "$@32", "do_expression",
  "$@33", "$@34", "$@35", "$@36", "while_expression", "$@37", "$@38",
  "$@39", "for_init_expression", "for_condition_expression",
  "for_action_expression", "for_expression", "$@40", "$@41", "$@42",
  "$@43", "$@44", "array_decorator", "$@45", "high_ay_decorator",
  "high_nter_decorator", "$@46", "address_decorator",
  "decorated_identifier", "$@47", "$@48", "statement", "$@49", "$@50",
  "$@51", "$@52", "$@53", "$@54", "$@55", "$@56", "$@57", "print_content",
  "statement_block", "$@58", "statement_body", "declaration", "$@59",
  "$@60", "declaration_body", "$@61", "function_declaration", "$@62",
  "$@63", "function_defination", "$@64", "argument_declaration_list",
  "argument_declaration_list_tail", "argument_declaration_unit", "$@65",
  "argument_declaration_init", "$@66", "init_identifier", "$@67",
  "function_argument", "$@68", "function_argument_list",
  "function_argument_tail", "condition_expression", "$@69", "$@70", "$@71",
  "condition_tail", "$@72", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -204

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-204)))

#define YYTABLE_NINF -166

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      51,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,   -19,   -15,    -8,    -5,    10,    40,     6,    48,    34,
      33,    39,  -204,  -204,  -204,     5,    49,    71,    42,   -24,
    -204,    74,    80,    91,    94,    49,    97,    44,    84,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,    19,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,    83,  -204,  -204,  -204,    87,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,    39,  -204,  -204,  -204,  -204,    68,   116,   106,
     121,   117,   112,  -204,  -204,  -204,   -20,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,   114,  -204,   118,  -204,  -204,
     122,  -204,  -204,  -204,    96,   124,  -204,  -204,   125,  -204,
    -204,   106,   126,   128,   130,  -204,    98,  -204,   -15,    -8,
      -5,    10,    48,    48,    34,    34,    34,    33,   132,  -204,
     133,  -204,   106,  -204,   110,   106,  -204,  -204,   123,  -204,
     120,   146,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,   147,
    -204,  -204,  -204,   149,  -204,  -204,   127,  -204,  -204,   108,
      49,  -204,   129,   114,  -204,   147,  -204,   131,   -24,   150,
    -204,  -204,   147,   119,  -204,   151,  -204,   134,  -204,  -204,
    -204,   149,  -204,   106,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,   152,  -204,   123,   135,   108,   136,   157,  -204,  -204,
    -204,  -204,    49,  -204,  -204,  -204,   158,  -204,  -204,    49,
    -204
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      61,   127,   131,   126,   168,    83,    78,    94,   122,   120,
     124,     0,     6,    11,    16,    21,     0,    36,    44,    55,
      60,    65,   114,   115,   113,    61,     0,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,    61,
     112,     3,     2,     8,     7,    13,    12,    18,    17,    23,
      25,    22,    28,    32,    30,    34,    27,    38,    41,    37,
      49,    52,    46,    45,    57,    56,    63,     0,   138,   136,
     119,     1,   117,    74,    75,    76,   141,   128,   109,   169,
      84,     0,    95,   123,   121,     0,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    65,    70,    68,    66,    62,    61,     0,   106,
      61,     0,   108,    61,    61,    79,    61,   125,     4,     9,
      14,    19,    24,    26,    29,    33,    31,    35,    39,    42,
      50,    53,    47,    58,    64,    73,    61,     0,    77,   104,
       0,   142,   143,   144,   154,   155,   135,   134,     0,   132,
     107,   106,     0,     0,     0,    88,     0,    87,     6,    11,
      16,    21,    44,    44,    55,    55,    55,    60,     0,    69,
       0,   137,   106,   160,     0,   106,   152,   146,   159,   129,
       0,     0,   170,    85,    80,    96,     5,    10,    15,    20,
      40,    43,    51,    54,    48,    59,    71,    67,   105,   103,
     145,   153,   155,   162,   157,   156,     0,   133,   110,    61,
       0,    61,    61,    73,   100,   103,   161,   167,     0,     0,
      61,   130,   103,   174,    86,     0,    90,     0,    72,    61,
     102,   162,   164,   106,   147,   158,   111,   172,   171,    81,
      97,     0,   166,   159,   149,    61,     0,    61,   101,   163,
     151,   148,     0,   173,    82,    92,     0,   150,    98,     0,
      99
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -204,   -38,     3,  -204,  -204,   -84,     9,  -204,  -204,    85,
      16,  -204,  -204,    89,    17,  -204,  -204,    90,  -204,  -204,
    -204,    25,  -204,  -204,  -204,  -204,  -204,   -59,   -66,  -204,
    -204,  -204,  -204,    21,  -106,  -204,  -204,  -204,  -204,  -204,
    -204,   -34,    13,  -204,  -204,    81,  -204,    79,  -204,  -204,
    -204,  -204,   -30,  -204,   -33,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -201,  -144,  -204,  -204,
    -204,  -204,  -204,  -203,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,   -35,  -204,   -22,    70,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,    12,  -204,  -204,
    -204,   -55,  -204,  -171,  -204,  -204,  -204,   -47,  -204,  -204,
    -204,  -204,  -204,  -204,  -204
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    42,    86,   158,    12,    44,    87,   159,    13,
      46,    88,   160,    14,    48,    89,   161,    15,    51,    90,
      91,    16,    56,    92,    94,    93,    95,    17,    59,    96,
     162,    97,   163,    18,    63,   100,   166,    98,   164,    99,
     165,    19,    65,   101,   167,    20,    21,    67,   102,   106,
     136,   135,   169,   213,    76,   108,    22,    35,   154,   211,
     246,    23,    34,   114,   210,   156,   227,   256,    24,    36,
     116,   212,   247,   259,   215,   229,   216,   140,   172,   151,
     111,   112,   222,    25,    26,    38,    37,    39,    31,   110,
     206,    32,   180,   148,    70,   107,    27,    28,    29,   109,
     141,   174,   142,   203,   244,   251,   252,   143,   176,   144,
     178,   205,   220,   145,   199,   217,   218,   219,   232,    30,
      33,   113,   209,   238,   245
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    85,   118,    68,   202,  -139,   223,   181,    73,    74,
       1,     2,  -140,  -140,   230,   -89,    40,  -118,  -139,    41,
      75,   236,   103,    43,  -140,    45,   104,   105,   198,    52,
      53,    54,    55,   124,   125,   126,   127,  -140,  -140,    47,
       3,     4,   253,     5,     6,     7,     8,     9,    10,  -140,
      64,  -139,    60,    61,    62,    66,     1,     2,   192,   193,
     194,    69,   243,  -118,   130,   131,   132,    49,    50,    57,
      58,    71,   147,     1,     2,   152,   153,    72,   155,    83,
    -118,  -139,    77,  -140,  -140,   137,     3,     4,    78,     5,
       6,     7,     8,     9,    10,  -140,   190,   191,   170,    79,
    -140,  -140,    80,     3,     4,    82,     5,     6,     7,     8,
       9,    10,  -140,     1,     2,   122,   123,   128,   129,    84,
    -118,   115,   117,   138,   139,   146,   149,   150,   168,   173,
     175,   171,   177,   185,   179,   182,   235,   183,   184,   196,
    -140,  -140,   197,     3,     4,   200,     5,     6,     7,     8,
       9,    10,  -140,   208,   204,   207,   237,   214,  -165,   234,
     239,   186,   221,   248,   -91,   231,   -93,   258,   187,   240,
     250,   254,   119,   225,   226,   224,   188,   120,   189,   121,
     195,   134,   133,   228,   242,   233,   157,   201,   249,     0,
       0,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
       0,     0,     0,     0,     0,     0,     0,   257,     0,     0,
       0,     0,     0,     0,   260
};

static const yytype_int16 yycheck[] =
{
      35,    39,    86,    25,   175,     0,   209,   151,    32,    33,
       5,     6,    32,    33,   215,    35,    35,    12,    13,    34,
      44,   222,     3,    31,    44,    30,     7,     8,   172,    23,
      24,    25,    26,    92,    93,    94,    95,    32,    33,    29,
      35,    36,   245,    38,    39,    40,    41,    42,    43,    44,
      17,     0,    18,    19,    20,    16,     5,     6,   164,   165,
     166,    12,   233,    12,    98,    99,   100,    27,    28,    21,
      22,     0,   110,     5,     6,   113,   114,    35,   116,    35,
      12,    13,     8,    32,    33,   107,    35,    36,     8,    38,
      39,    40,    41,    42,    43,    44,   162,   163,   136,     8,
      32,    33,     8,    35,    36,     8,    38,    39,    40,    41,
      42,    43,    44,     5,     6,    90,    91,    96,    97,    35,
      12,    38,    35,     7,    18,     4,     9,    15,    14,     7,
      34,    13,     8,    35,     9,     9,   220,     9,     8,     7,
      32,    33,     9,    35,    36,    35,    38,    39,    40,    41,
      42,    43,    44,     7,    31,    35,    37,    10,     9,     9,
       9,   158,    35,    11,    35,    34,     9,     9,   159,    35,
      35,    35,    87,   211,   212,   210,   160,    88,   161,    89,
     167,   102,   101,   213,   231,   218,   116,   175,   243,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,   259
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    35,    36,    38,    39,    40,    41,    42,
      43,    47,    51,    55,    59,    63,    67,    73,    79,    87,
      91,    92,   102,   107,   114,   129,   130,   142,   143,   144,
     165,   134,   137,   166,   108,   103,   115,   132,   131,   133,
      35,    34,    48,    31,    52,    30,    56,    29,    60,    27,
      28,    64,    23,    24,    25,    26,    68,    21,    22,    74,
      18,    19,    20,    80,    17,    88,    16,    93,   142,    12,
     140,     0,    35,    32,    33,    44,   100,     8,     8,     8,
       8,   140,     8,    35,    35,    47,    49,    53,    57,    61,
      65,    66,    69,    71,    70,    72,    75,    77,    83,    85,
      81,    89,    94,     3,     7,     8,    95,   141,   101,   145,
     135,   126,   127,   167,   109,    38,   116,    35,    51,    55,
      59,    63,    67,    67,    73,    73,    73,    73,    79,    79,
      87,    87,    87,    91,    93,    97,    96,   142,     7,    18,
     123,   146,   148,   153,   155,   159,     4,    47,   139,     9,
      15,   125,    47,    47,   104,    47,   111,   143,    50,    54,
      58,    62,    76,    78,    84,    86,    82,    90,    14,    98,
      47,    13,   124,     7,   147,    34,   154,     8,   156,     9,
     138,   123,     9,     9,     8,    35,    48,    52,    56,    60,
      74,    74,    80,    80,    80,    88,     7,     9,   123,   160,
      35,   153,   159,   149,    31,   157,   136,    35,     7,   168,
     110,   105,   117,    99,    10,   120,   122,   161,   162,   163,
     158,    35,   128,   129,   140,    47,    47,   112,    98,   121,
     122,    34,   164,   100,     9,    51,   122,    37,   169,     9,
      35,    47,   163,   159,   150,   170,   106,   118,    11,   157,
      35,   151,   152,   129,    35,    47,   113,   140,     9,   119,
     140
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    49,    50,    48,    48,    51,    53,    54,
      52,    52,    55,    57,    58,    56,    56,    59,    61,    62,
      60,    60,    63,    65,    64,    66,    64,    67,    69,    68,
      70,    68,    71,    68,    72,    68,    68,    73,    75,    76,
      74,    77,    78,    74,    74,    79,    81,    82,    80,    83,
      84,    80,    85,    86,    80,    80,    87,    89,    90,    88,
      88,    92,    91,    94,    93,    93,    96,    95,    97,    95,
      95,    99,    98,    98,   100,   100,   101,   100,   103,   104,
     105,   106,   102,   108,   109,   110,   107,   111,   111,   111,
     112,   112,   113,   113,   115,   116,   117,   118,   119,   114,
     121,   120,   122,   122,   124,   123,   123,   125,   125,   127,
     128,   126,   129,   129,   129,   129,   129,   129,   130,   129,
     131,   129,   132,   129,   133,   129,   129,   134,   135,   136,
     129,   137,   138,   129,   139,   139,   141,   140,   142,   142,
     144,   145,   143,   146,   147,   146,   149,   150,   148,   152,
     151,   151,   153,   154,   154,   156,   155,   158,   157,   157,
     160,   159,   162,   161,   163,   163,   164,   164,   166,   167,
     168,   165,   170,   169,   169
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     0,     5,     0,     2,     0,     0,
       5,     0,     2,     0,     0,     5,     0,     2,     0,     0,
       5,     0,     2,     0,     3,     0,     3,     2,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     2,     0,     0,
       5,     0,     0,     5,     0,     2,     0,     0,     5,     0,
       0,     5,     0,     0,     5,     0,     2,     0,     0,     5,
       0,     0,     3,     0,     3,     0,     0,     4,     0,     3,
       1,     0,     4,     0,     1,     1,     0,     3,     0,     0,
       0,     0,    11,     0,     0,     0,     8,     1,     1,     0,
       1,     0,     1,     0,     0,     0,     0,     0,     0,    14,
       0,     4,     2,     0,     0,     3,     0,     1,     0,     0,
       0,     6,     2,     1,     1,     1,     1,     2,     0,     2,
       0,     3,     0,     3,     0,     4,     1,     0,     0,     0,
       8,     0,     0,     7,     1,     1,     0,     4,     2,     0,
       0,     0,     4,     1,     0,     3,     0,     0,     7,     0,
       2,     1,     2,     2,     0,     0,     3,     0,     3,     0,
       0,     4,     0,     4,     2,     0,     2,     0,     0,     0,
       0,     9,     0,     3,     0
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
        case 3:
#line 112 "c.y" /* yacc.c:1646  */
    {
        extendOptTree(",");
    }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 114 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 117 "c.y" /* yacc.c:1646  */
    {}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 125 "c.y" /* yacc.c:1646  */
    { 
        extendOptTree("=");
    }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 127 "c.y" /* yacc.c:1646  */
    { 
        backToParent();
    }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 138 "c.y" /* yacc.c:1646  */
    { 
        extendOptTree("||");
    }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 140 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 151 "c.y" /* yacc.c:1646  */
    {  
        extendOptTree("&&");
    }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 153 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 164 "c.y" /* yacc.c:1646  */
    {  
        extendOptTree("==");
    }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 166 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 169 "c.y" /* yacc.c:1646  */
    {  
        extendOptTree("!=");
    }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 171 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 181 "c.y" /* yacc.c:1646  */
    {  
        extendOptTree(">");
    }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 183 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 186 "c.y" /* yacc.c:1646  */
    {  
        extendOptTree(">=");
    }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 188 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 191 "c.y" /* yacc.c:1646  */
    {  
        extendOptTree("<");
    }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 193 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 196 "c.y" /* yacc.c:1646  */
    {  
        extendOptTree("<=");
    }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 198 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 209 "c.y" /* yacc.c:1646  */
    { 
        extendOptTree("+");
    }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 211 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 214 "c.y" /* yacc.c:1646  */
    { 
        extendOptTree("-");
    }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 216 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 227 "c.y" /* yacc.c:1646  */
    { 
        extendOptTree("%");
    }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 229 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 232 "c.y" /* yacc.c:1646  */
    { 
        extendOptTree("*");
    }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 234 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 237 "c.y" /* yacc.c:1646  */
    { 
        extendOptTree("/");
    }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 239 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 250 "c.y" /* yacc.c:1646  */
    { 
        extendOptTree("^");
    }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 252 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 259 "c.y" /* yacc.c:1646  */
    {
        saveNode();
    }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 261 "c.y" /* yacc.c:1646  */
    {
        loadNode();
    }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 267 "c.y" /* yacc.c:1646  */
    { 
        extendTree(NON_TERMINAL, "!", "expression");
    }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 274 "c.y" /* yacc.c:1646  */
    { 
        extendTree(NON_TERMINAL, "()", "expression");
    }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 276 "c.y" /* yacc.c:1646  */
    { 
        backToParent();
    }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 279 "c.y" /* yacc.c:1646  */
    {
        //saveNode();
        extendTree(TERMINAL, (yyvsp[0].str), "identifier");
    }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 282 "c.y" /* yacc.c:1646  */
    {
        //loadNode();
    }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 285 "c.y" /* yacc.c:1646  */
    { 
        extendTree(TERMINAL, (yyvsp[0].str), "identifier");
    }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 291 "c.y" /* yacc.c:1646  */
    {
        extendOptTree("->");
        extendTerminal("IDENTIFIER", (yyvsp[0].str));
        backToParent();
    }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 300 "c.y" /* yacc.c:1646  */
    { 
        extendTerminal("int", "type");
    }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 303 "c.y" /* yacc.c:1646  */
    { 
        extendTerminal("void", "type");
    }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 306 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "struct", "type");
    }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 308 "c.y" /* yacc.c:1646  */
    {  
        extendTerminal((yyvsp[0].str), "identifier");
        backToParent();
    }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 315 "c.y" /* yacc.c:1646  */
    { 
        /*establish local scope*/ ;
        saveNode();
        extendTree(NON_TERMINAL, "", "do while loop");
        extendTree(NON_TERMINAL, "do", "loop body");
    }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 320 "c.y" /* yacc.c:1646  */
    {
        backToParent();
        extendTree(NON_TERMINAL, "while", "loop condition");
    }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 323 "c.y" /* yacc.c:1646  */
    {  
        extendTree(NON_TERMINAL, "()", "expression");
    }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 325 "c.y" /* yacc.c:1646  */
    { 
        loadNode();
    }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 331 "c.y" /* yacc.c:1646  */
    {  
        saveNode();
        extendTree(NON_TERMINAL, "while", "while loop");
    }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 334 "c.y" /* yacc.c:1646  */
    { 
        extendTree(NON_TERMINAL, "()", "expression"); 
    }
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 336 "c.y" /* yacc.c:1646  */
    { 
        backToParent(); 
        /*establish local scope*/ ;
        extendTree(NON_TERMINAL, "", "loop body");
    }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 340 "c.y" /* yacc.c:1646  */
    {
        loadNode();
    }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 388 "c.y" /* yacc.c:1646  */
    { 
        /*establish local scope*/ ;
        saveNode();
        extendTree(NON_TERMINAL, "for", "for loop");
    }
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 392 "c.y" /* yacc.c:1646  */
    {  
        extendTree(NON_TERMINAL, "()", "for expression");
        extendTree(NON_TERMINAL, "", "for init expression");
    }
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 395 "c.y" /* yacc.c:1646  */
    {
        backToParent();
        extendTree(NON_TERMINAL, "", "for condition");
    }
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 398 "c.y" /* yacc.c:1646  */
    {
        backToParent();
        extendTree(NON_TERMINAL, "", "for action");
    }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 401 "c.y" /* yacc.c:1646  */
    {  
        backToParent();
        backToParent();
        extendTree(NON_TERMINAL, "", "loop body");
    }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 405 "c.y" /* yacc.c:1646  */
    {
        loadNode();
    }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 411 "c.y" /* yacc.c:1646  */
    { 
        extendOptTree("[]"); 
    }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 413 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 424 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "*", "pointer");
    }
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 431 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "&", "address");
    }
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 438 "c.y" /* yacc.c:1646  */
    {
        saveNode();
    }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 440 "c.y" /* yacc.c:1646  */
    {
        extendTerminal((yyvsp[0].str), "identifier");
    }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 442 "c.y" /* yacc.c:1646  */
    {
        loadNode();
    }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 454 "c.y" /* yacc.c:1646  */
    { /*establish local scope*/ ; }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 455 "c.y" /* yacc.c:1646  */
    {
        extendTerminal("break", "break");
    }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 458 "c.y" /* yacc.c:1646  */
    {
        extendTerminal("continue", "continue");
    }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 461 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "return", "return");
    }
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 463 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 467 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "print", "print");
    }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 469 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "", "print_content");
    }
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 471 "c.y" /* yacc.c:1646  */
    {
        backToParent();
        backToParent();
    }
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 475 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "input", "input");
    }
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 477 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 486 "c.y" /* yacc.c:1646  */
    {
        extendTerminal((yyvsp[0].str), "string");
    }
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 492 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "{}", "statement body");
    }
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 494 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 505 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "", "declaration");
    }
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 507 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "", "declaration body");
        saveNode();
    }
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 514 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "", "function declaration");
        broToParent(-1);
        connectParentChild();
    }
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 519 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "", "argument declaration list");
        broToParent(-1);
        connectParentChild();
    }
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 527 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "()", "function argument list");
    }
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 529 "c.y" /* yacc.c:1646  */
    {
        backToParent();
        // establish local scope
    }
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 536 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "", "function defination");
    }
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 538 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 554 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "", "argument declaration unit");
        broToParent(1);
    }
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 557 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 563 "c.y" /* yacc.c:1646  */
    {
        extendOptTree("=");
    }
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 565 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 572 "c.y" /* yacc.c:1646  */
    {
        extendTerminal((yyvsp[0].str), "identifier");
    }
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 574 "c.y" /* yacc.c:1646  */
    {
        loadNode();
    }
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 580 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "", "function argument unit");
        saveNode();
    }
#line 2334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 583 "c.y" /* yacc.c:1646  */
    {
        backToParent();
    }
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 599 "c.y" /* yacc.c:1646  */
    { 
        extendTree(NON_TERMINAL, "if", "if expression");
    }
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 601 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "()", "if condition");
    }
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 603 "c.y" /* yacc.c:1646  */
    {
        backToParent();
        extendTree(NON_TERMINAL, "", "if statement");
    }
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 610 "c.y" /* yacc.c:1646  */
    {
        extendTree(NON_TERMINAL, "else", "else statement");
    }
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 613 "c.y" /* yacc.c:1646  */
    {}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2385 "y.tab.c" /* yacc.c:1646  */
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
#line 616 "c.y" /* yacc.c:1906  */



   
void extendTree(int isTerminal, const char* word, const char* grammer) {
    tempPointer = createGrammerNode(isTerminal, word, grammer); 
    push_child(curNode, tempPointer); 
    if (isTerminal == NON_TERMINAL) curNode = tempPointer;
}

void backToParent() {
    if (curNode->parent == NULL) return;
    curNode = curNode->parent;
}

void saveNode() {
    stack[stackContentSize++] = curNode;
}

void loadNode() {
    if (stackContentSize <= 0) return;
    curNode = stack[--stackContentSize];
}

void extendOptTree(const char* opt) {
    extendTree(NON_TERMINAL, opt, "expression");
    adjustOptNode(curNode);
}

void extendTerminal(const char* word, const char* grammer) {
    extendTree(TERMINAL, word, grammer);
}

void broToParent(int num) {
    grammerTree* parent = curNode->parent;
    int selfPos;
    int i;
    selfPos = findSelfPos(curNode);
    if (num == -1) i = 0;
    else i =  selfPos - num;
    for (int n = i; n < selfPos; n++) {
        push_child(curNode, parent->child[n]);
    }
    parent->child[i++] = curNode;
    parent->size = i;
}

void connectParentChild() {
    grammerTree* parent = curNode->parent;
    grammerTree** child = curNode->child;
    for (int i = 0; i < curNode->size; i++) {
        push_child(parent, child[i]);
    }
    freeGrammerNode(curNode);
    curNode = parent;
}

int main(int arg, char* argv[]) {
    if (2 > arg) {
        exit(-1);
    }
    yyin = fopen(argv[1], "r");
    root = createGrammerNode(NON_TERMINAL, "", "start");
    curNode = root;
    tempPointer = NULL;
    generateLEX();
    appendLEX("Type           Name           Attribute \n");
    launchTable();
    yyparse();
    closeLEX();
    generateYACC();
    printGrammerTree(root);
    closeYACC();
    stopTable();
    freeGrammerTree(root);
    fclose(yyin);
    return 0; 
}   

void yyerror(const char* charactor) {
    
}
