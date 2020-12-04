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
#line 1 "combine.y"

#include <stdio.h>
#include <stdlib.h>
#include "grammerTree.h"
#include "y.tab.h"

#ifndef __cplusplus
extern "C" 

{
#endif

    void yyerror(const char *s);
    extern int yylex(void);
    extern char* yytext;

#ifndef __cplusplus
};
#endif

int word_pos = 0;
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


#line 109 "y.tab.c"

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
# define YYERROR_VERBOSE 0
#endif


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
#line 42 "combine.y"

    char* str;

#line 252 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  124
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  259

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


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
static const yytype_int16 yyrline[] =
{
       0,   107,   107,   111,   113,   111,   116,   120,   124,   126,
     124,   129,   133,   137,   139,   137,   142,   146,   150,   152,
     150,   155,   159,   163,   163,   168,   168,   176,   180,   180,
     185,   185,   190,   190,   195,   195,   200,   204,   208,   210,
     208,   213,   215,   213,   218,   222,   226,   228,   226,   231,
     233,   231,   236,   238,   236,   241,   245,   249,   251,   249,
     254,   258,   258,   266,   266,   269,   273,   273,   278,   278,
     284,   290,   290,   295,   299,   302,   305,   305,   314,   319,
     322,   324,   314,   330,   333,   335,   330,   371,   372,   373,
     377,   378,   382,   383,   387,   391,   394,   397,   400,   387,
     410,   410,   418,   419,   423,   423,   426,   430,   433,   437,
     439,   437,   447,   449,   450,   451,   452,   453,   454,   454,
     455,   455,   458,   458,   461,   461,   466,   467,   469,   471,
     467,   475,   477,   475,   485,   486,   492,   492,   500,   501,
     505,   507,   505,   514,   519,   519,   527,   529,   527,   536,
     536,   541,   545,   549,   550,   554,   562,   562,   567,   571,
     571,   579,   579,   588,   589,   593,   594,   598,   600,   602,
     598,   609,   609,   612
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
  "argument_declaration_list_tail", "argument_declaration_unit",
  "argument_declaration_init", "$@65", "init_identifier", "$@66",
  "function_argument", "$@67", "function_argument_list",
  "function_argument_tail", "condition_expression", "$@68", "$@69", "$@70",
  "condition_tail", "$@71", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF (-199)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-165)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,   -29,   -25,   -17,    -7,     3,    64,    45,    98,    16,
      38,    23,  -199,  -199,  -199,     5,    65,    87,    60,   -13,
    -199,   100,   103,   119,   120,    65,   121,    95,    96,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,    22,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,    94,  -199,  -199,  -199,    99,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,    23,  -199,  -199,  -199,  -199,    61,   126,   117,
     132,   128,   123,  -199,  -199,  -199,   -20,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,   125,  -199,   127,  -199,  -199,
     134,  -199,  -199,  -199,   108,   135,  -199,  -199,   136,  -199,
    -199,   117,   137,   138,   140,  -199,   109,  -199,   -25,   -17,
      -7,     3,    98,    98,    16,    16,    16,    38,   142,  -199,
     141,  -199,   117,  -199,   116,   117,  -199,  -199,  -199,   118,
     145,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,   144,  -199,
    -199,  -199,   146,   122,  -199,  -199,    74,    65,  -199,   124,
     125,  -199,   144,  -199,   129,   -13,   147,  -199,   144,   130,
    -199,   149,  -199,   131,  -199,  -199,  -199,   146,  -199,   117,
    -199,  -199,  -199,  -199,  -199,  -199,   150,  -199,   133,   139,
      74,   143,   151,  -199,  -199,  -199,  -199,  -199,    65,  -199,
    -199,  -199,   153,  -199,  -199,  -199,  -199,    65,  -199
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      61,   127,   131,   126,   167,    83,    78,    94,   122,   120,
     124,     0,     6,    11,    16,    21,     0,    36,    44,    55,
      60,    65,   114,   115,   113,    61,     0,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,    61,
     112,     3,     2,     8,     7,    13,    12,    18,    17,    23,
      25,    22,    28,    32,    30,    34,    27,    38,    41,    37,
      49,    52,    46,    45,    57,    56,    63,     0,   138,   136,
     119,     1,   117,    74,    75,    76,   141,   128,   109,   168,
      84,     0,    95,   123,   121,     0,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    65,    70,    68,    66,    62,    61,     0,   106,
      61,     0,   108,    61,    61,    79,    61,   125,     4,     9,
      14,    19,    24,    26,    29,    33,    31,    35,    39,    42,
      50,    53,    47,    58,    64,    73,    61,     0,    77,   104,
       0,   142,   143,   144,   154,   155,   135,   134,     0,   132,
     107,   106,     0,     0,     0,    88,     0,    87,     6,    11,
      16,    21,    44,    44,    55,    55,    55,    60,     0,    69,
       0,   137,   106,   159,     0,   106,   152,   146,   129,     0,
       0,   169,    85,    80,    96,     5,    10,    15,    20,    40,
      43,    51,    54,    48,    59,    71,    67,   105,   103,   145,
     153,   155,   161,     0,   133,   110,    61,     0,    61,    61,
      73,   100,   103,   160,   166,     0,     0,   130,   103,   173,
      86,     0,    90,     0,    72,    61,   102,   161,   163,   106,
     147,   111,   171,   170,    81,    97,     0,   165,   158,   149,
      61,     0,    61,   101,   156,   162,   151,   148,     0,   172,
      82,    92,     0,    61,   150,    98,   157,     0,    99
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -199,   -38,     7,  -199,  -199,   -84,     9,  -199,  -199,    86,
      15,  -199,  -199,    88,    18,  -199,  -199,    91,  -199,  -199,
    -199,    31,  -199,  -199,  -199,  -199,  -199,   -11,   -39,  -199,
    -199,  -199,  -199,    29,  -114,  -199,  -199,  -199,  -199,  -199,
    -199,   -10,    10,  -199,  -199,    80,  -199,    81,  -199,  -199,
    -199,  -199,   -28,  -199,   -31,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -196,  -144,  -199,  -199,
    -199,  -199,  -199,  -198,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,   -35,  -199,   -22,    69,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,    11,  -199,  -199,
    -199,  -199,  -171,  -199,  -199,  -199,   -37,  -199,  -199,  -199,
    -199,  -199,  -199,  -199
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    42,    86,   158,    12,    44,    87,   159,    13,
      46,    88,   160,    14,    48,    89,   161,    15,    51,    90,
      91,    16,    56,    92,    94,    93,    95,    17,    59,    96,
     162,    97,   163,    18,    63,   100,   166,    98,   164,    99,
     165,    19,    65,   101,   167,    20,    21,    67,   102,   106,
     136,   135,   169,   210,    76,   108,    22,    35,   154,   208,
     241,    23,    34,   114,   207,   156,   223,   252,    24,    36,
     116,   209,   242,   257,   212,   225,   213,   140,   172,   151,
     111,   112,   218,    25,    26,    38,    37,    39,    31,   110,
     203,    32,   179,   148,    70,   107,    27,    28,    29,   109,
     141,   174,   142,   202,   239,   247,   248,   143,   176,   144,
     245,   253,   145,   198,   214,   215,   216,   228,    30,    33,
     113,   206,   233,   240
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    85,   118,    68,   201,  -139,    40,   180,   219,    41,
       1,     2,  -140,  -140,    43,   -89,   226,  -118,  -139,    73,
      74,  -139,   231,    45,  -140,   103,     1,     2,   197,   104,
     105,    75,    47,  -118,    60,    61,    62,  -140,  -140,    66,
       3,     4,   249,     5,     6,     7,     8,     9,    10,  -140,
     191,   192,   193,  -140,  -140,    64,     3,     4,   238,     5,
       6,     7,     8,     9,    10,  -140,     1,     2,    52,    53,
      54,    55,   147,  -118,  -139,   152,   153,    69,   155,     1,
       2,   124,   125,   126,   127,   137,  -118,    71,   130,   131,
     132,    49,    50,  -140,  -140,    72,     3,     4,   170,     5,
       6,     7,     8,     9,    10,  -140,  -140,  -140,    77,     3,
       4,    78,     5,     6,     7,     8,     9,    10,  -140,    57,
      58,   122,   123,   189,   190,   128,   129,    79,    80,    82,
      83,    84,   115,   138,   117,   139,   146,   149,   150,   168,
     171,   173,   175,   177,   184,   178,   181,   182,   183,   195,
     196,   199,   205,   204,   211,  -164,   230,   217,   234,   -91,
     -93,   243,   255,   227,   244,   185,   235,   232,   186,   256,
     221,   222,   220,   119,   246,   187,   120,   194,   250,   188,
     121,   133,   224,   134,   229,   157,   200,   236,     0,     0,
     237,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   251,     0,     0,     0,     0,     0,
       0,     0,     0,   254,     0,     0,     0,     0,     0,     0,
       0,     0,   258
};

static const yytype_int16 yycheck[] =
{
      35,    39,    86,    25,   175,     0,    35,   151,   206,    34,
       5,     6,    32,    33,    31,    35,   212,    12,    13,    32,
      33,     0,   218,    30,    44,     3,     5,     6,   172,     7,
       8,    44,    29,    12,    18,    19,    20,    32,    33,    16,
      35,    36,   240,    38,    39,    40,    41,    42,    43,    44,
     164,   165,   166,    32,    33,    17,    35,    36,   229,    38,
      39,    40,    41,    42,    43,    44,     5,     6,    23,    24,
      25,    26,   110,    12,    13,   113,   114,    12,   116,     5,
       6,    92,    93,    94,    95,   107,    12,     0,    98,    99,
     100,    27,    28,    32,    33,    35,    35,    36,   136,    38,
      39,    40,    41,    42,    43,    44,    32,    33,     8,    35,
      36,     8,    38,    39,    40,    41,    42,    43,    44,    21,
      22,    90,    91,   162,   163,    96,    97,     8,     8,     8,
      35,    35,    38,     7,    35,    18,     4,     9,    15,    14,
      13,     7,    34,     8,    35,     9,     9,     9,     8,     7,
       9,    35,     7,    35,    10,     9,     9,    35,     9,    35,
       9,    11,     9,    34,    31,   158,    35,    37,   159,   253,
     208,   209,   207,    87,    35,   160,    88,   167,    35,   161,
      89,   101,   210,   102,   215,   116,   175,   225,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    35,    36,    38,    39,    40,    41,    42,
      43,    47,    51,    55,    59,    63,    67,    73,    79,    87,
      91,    92,   102,   107,   114,   129,   130,   142,   143,   144,
     164,   134,   137,   165,   108,   103,   115,   132,   131,   133,
      35,    34,    48,    31,    52,    30,    56,    29,    60,    27,
      28,    64,    23,    24,    25,    26,    68,    21,    22,    74,
      18,    19,    20,    80,    17,    88,    16,    93,   142,    12,
     140,     0,    35,    32,    33,    44,   100,     8,     8,     8,
       8,   140,     8,    35,    35,    47,    49,    53,    57,    61,
      65,    66,    69,    71,    70,    72,    75,    77,    83,    85,
      81,    89,    94,     3,     7,     8,    95,   141,   101,   145,
     135,   126,   127,   166,   109,    38,   116,    35,    51,    55,
      59,    63,    67,    67,    73,    73,    73,    73,    79,    79,
      87,    87,    87,    91,    93,    97,    96,   142,     7,    18,
     123,   146,   148,   153,   155,   158,     4,    47,   139,     9,
      15,   125,    47,    47,   104,    47,   111,   143,    50,    54,
      58,    62,    76,    78,    84,    86,    82,    90,    14,    98,
      47,    13,   124,     7,   147,    34,   154,     8,     9,   138,
     123,     9,     9,     8,    35,    48,    52,    56,    60,    74,
      74,    80,    80,    80,    88,     7,     9,   123,   159,    35,
     153,   158,   149,   136,    35,     7,   167,   110,   105,   117,
      99,    10,   120,   122,   160,   161,   162,    35,   128,   129,
     140,    47,    47,   112,    98,   121,   122,    34,   163,   100,
       9,   122,    37,   168,     9,    35,    47,   162,   158,   150,
     169,   106,   118,    11,    31,   156,    35,   151,   152,   129,
      35,    47,   113,   157,   140,     9,    51,   119,   140
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
     151,   151,   153,   154,   154,   155,   157,   156,   156,   159,
     158,   161,   160,   162,   162,   163,   163,   165,   166,   167,
     164,   169,   168,   168
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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
       2,     1,     2,     2,     0,     1,     0,     3,     0,     0,
       4,     0,     4,     2,     0,     2,     0,     0,     0,     0,
       9,     0,     3,     0
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
  case 3:
#line 111 "combine.y"
            {
        extendOptTree(",");
    }
#line 1648 "y.tab.c"
    break;

  case 4:
#line 113 "combine.y"
                        {
        backToParent();
    }
#line 1656 "y.tab.c"
    break;

  case 6:
#line 116 "combine.y"
      {}
#line 1662 "y.tab.c"
    break;

  case 8:
#line 124 "combine.y"
             { 
        extendOptTree("=");
    }
#line 1670 "y.tab.c"
    break;

  case 9:
#line 126 "combine.y"
                     { 
        backToParent();
    }
#line 1678 "y.tab.c"
    break;

  case 13:
#line 137 "combine.y"
         { 
        extendOptTree("||");
    }
#line 1686 "y.tab.c"
    break;

  case 14:
#line 139 "combine.y"
                      {
        backToParent();
    }
#line 1694 "y.tab.c"
    break;

  case 18:
#line 150 "combine.y"
          {  
        extendOptTree("&&");
    }
#line 1702 "y.tab.c"
    break;

  case 19:
#line 152 "combine.y"
                      {
        backToParent();
    }
#line 1710 "y.tab.c"
    break;

  case 23:
#line 163 "combine.y"
         {  
        extendOptTree("==");
    }
#line 1718 "y.tab.c"
    break;

  case 24:
#line 165 "combine.y"
                     {
        backToParent();
    }
#line 1726 "y.tab.c"
    break;

  case 25:
#line 168 "combine.y"
         {  
        extendOptTree("!=");
    }
#line 1734 "y.tab.c"
    break;

  case 26:
#line 170 "combine.y"
                     {
        backToParent();
    }
#line 1742 "y.tab.c"
    break;

  case 28:
#line 180 "combine.y"
         {  
        extendOptTree(">");
    }
#line 1750 "y.tab.c"
    break;

  case 29:
#line 182 "combine.y"
                     {
        backToParent();
    }
#line 1758 "y.tab.c"
    break;

  case 30:
#line 185 "combine.y"
         {  
        extendOptTree(">=");
    }
#line 1766 "y.tab.c"
    break;

  case 31:
#line 187 "combine.y"
                     {
        backToParent();
    }
#line 1774 "y.tab.c"
    break;

  case 32:
#line 190 "combine.y"
         {  
        extendOptTree("<");
    }
#line 1782 "y.tab.c"
    break;

  case 33:
#line 192 "combine.y"
                     {
        backToParent();
    }
#line 1790 "y.tab.c"
    break;

  case 34:
#line 195 "combine.y"
         {  
        extendOptTree("<=");
    }
#line 1798 "y.tab.c"
    break;

  case 35:
#line 197 "combine.y"
                     {
        backToParent();
    }
#line 1806 "y.tab.c"
    break;

  case 38:
#line 208 "combine.y"
           { 
        extendOptTree("+");
    }
#line 1814 "y.tab.c"
    break;

  case 39:
#line 210 "combine.y"
                      {
        backToParent();
    }
#line 1822 "y.tab.c"
    break;

  case 41:
#line 213 "combine.y"
            { 
        extendOptTree("-");
    }
#line 1830 "y.tab.c"
    break;

  case 42:
#line 215 "combine.y"
                      {
        backToParent();
    }
#line 1838 "y.tab.c"
    break;

  case 46:
#line 226 "combine.y"
          { 
        extendOptTree("%");
    }
#line 1846 "y.tab.c"
    break;

  case 47:
#line 228 "combine.y"
                      {
        backToParent();
    }
#line 1854 "y.tab.c"
    break;

  case 49:
#line 231 "combine.y"
            { 
        extendOptTree("*");
    }
#line 1862 "y.tab.c"
    break;

  case 50:
#line 233 "combine.y"
                      {
        backToParent();
    }
#line 1870 "y.tab.c"
    break;

  case 52:
#line 236 "combine.y"
             { 
        extendOptTree("/");
    }
#line 1878 "y.tab.c"
    break;

  case 53:
#line 238 "combine.y"
                      {
        backToParent();
    }
#line 1886 "y.tab.c"
    break;

  case 57:
#line 249 "combine.y"
          { 
        extendOptTree("^");
    }
#line 1894 "y.tab.c"
    break;

  case 58:
#line 251 "combine.y"
                      {
        backToParent();
    }
#line 1902 "y.tab.c"
    break;

  case 61:
#line 258 "combine.y"
      {
        saveNode();
    }
#line 1910 "y.tab.c"
    break;

  case 62:
#line 260 "combine.y"
                                    {
        loadNode();
    }
#line 1918 "y.tab.c"
    break;

  case 63:
#line 266 "combine.y"
          { 
        extendTree(NON_TERMINAL, "!", "expression");
    }
#line 1926 "y.tab.c"
    break;

  case 66:
#line 273 "combine.y"
         { 
        extendTree(NON_TERMINAL, "()", "expression");
    }
#line 1934 "y.tab.c"
    break;

  case 67:
#line 275 "combine.y"
                    { 
        backToParent();
    }
#line 1942 "y.tab.c"
    break;

  case 68:
#line 278 "combine.y"
                 {
        //saveNode();
        extendTree(TERMINAL, (yyvsp[0].str), "identifier");
    }
#line 1951 "y.tab.c"
    break;

  case 69:
#line 281 "combine.y"
                         {
        //loadNode();
    }
#line 1959 "y.tab.c"
    break;

  case 70:
#line 284 "combine.y"
               { 
        extendTree(TERMINAL, (yyvsp[0].str), "identifier");
    }
#line 1967 "y.tab.c"
    break;

  case 71:
#line 290 "combine.y"
                         {
        extendOptTree("->");
        extendTerminal("IDENTIFIER", (yyvsp[0].str));
        backToParent();
    }
#line 1977 "y.tab.c"
    break;

  case 74:
#line 299 "combine.y"
          { 
        extendTerminal("int", "type");
    }
#line 1985 "y.tab.c"
    break;

  case 75:
#line 302 "combine.y"
           { 
        extendTerminal("void", "type");
    }
#line 1993 "y.tab.c"
    break;

  case 76:
#line 305 "combine.y"
             {
        extendTree(NON_TERMINAL, "struct", "type");
    }
#line 2001 "y.tab.c"
    break;

  case 77:
#line 307 "combine.y"
                 {  
        extendTerminal((yyvsp[0].str), "identifier");
        backToParent();
    }
#line 2010 "y.tab.c"
    break;

  case 78:
#line 314 "combine.y"
         { 
        /*establish local scope*/ ;
        saveNode();
        extendTree(NON_TERMINAL, "", "do while loop");
        extendTree(NON_TERMINAL, "do", "loop body");
    }
#line 2021 "y.tab.c"
    break;

  case 79:
#line 319 "combine.y"
                            {
        backToParent();
        extendTree(NON_TERMINAL, "while", "loop condition");
    }
#line 2030 "y.tab.c"
    break;

  case 80:
#line 322 "combine.y"
         {  
        extendTree(NON_TERMINAL, "()", "expression");
    }
#line 2038 "y.tab.c"
    break;

  case 81:
#line 324 "combine.y"
                    { 
        loadNode();
    }
#line 2046 "y.tab.c"
    break;

  case 83:
#line 330 "combine.y"
            {  
        saveNode();
        extendTree(NON_TERMINAL, "while", "while loop");
    }
#line 2055 "y.tab.c"
    break;

  case 84:
#line 333 "combine.y"
         { 
        extendTree(NON_TERMINAL, "()", "expression"); 
    }
#line 2063 "y.tab.c"
    break;

  case 85:
#line 335 "combine.y"
                    { 
        backToParent(); 
        /*establish local scope*/ ;
        extendTree(NON_TERMINAL, "", "loop body");
    }
#line 2073 "y.tab.c"
    break;

  case 86:
#line 339 "combine.y"
                      {
        loadNode();
    }
#line 2081 "y.tab.c"
    break;

  case 94:
#line 387 "combine.y"
          { 
        /*establish local scope*/ ;
        saveNode();
        extendTree(NON_TERMINAL, "for", "for loop");
    }
#line 2091 "y.tab.c"
    break;

  case 95:
#line 391 "combine.y"
         {  
        extendTree(NON_TERMINAL, "()", "for expression");
        extendTree(NON_TERMINAL, "", "for init expression");
    }
#line 2100 "y.tab.c"
    break;

  case 96:
#line 394 "combine.y"
                                    {
        backToParent();
        extendTree(NON_TERMINAL, "", "for condition");
    }
#line 2109 "y.tab.c"
    break;

  case 97:
#line 397 "combine.y"
                                         {
        backToParent();
        extendTree(NON_TERMINAL, "", "for action");
    }
#line 2118 "y.tab.c"
    break;

  case 98:
#line 400 "combine.y"
                               {  
        backToParent();
        backToParent();
        extendTree(NON_TERMINAL, "", "loop body");
    }
#line 2128 "y.tab.c"
    break;

  case 99:
#line 404 "combine.y"
                      {
        loadNode();
    }
#line 2136 "y.tab.c"
    break;

  case 100:
#line 410 "combine.y"
          { 
        extendOptTree("[]"); 
    }
#line 2144 "y.tab.c"
    break;

  case 101:
#line 412 "combine.y"
                     {
        backToParent();
    }
#line 2152 "y.tab.c"
    break;

  case 104:
#line 423 "combine.y"
            {
        extendTree(NON_TERMINAL, "*", "pointer");
    }
#line 2160 "y.tab.c"
    break;

  case 107:
#line 430 "combine.y"
              {
        extendTree(NON_TERMINAL, "&", "address");
    }
#line 2168 "y.tab.c"
    break;

  case 109:
#line 437 "combine.y"
      {
        saveNode();
    }
#line 2176 "y.tab.c"
    break;

  case 110:
#line 439 "combine.y"
                                                       {
        extendTerminal((yyvsp[0].str), "identifier");
    }
#line 2184 "y.tab.c"
    break;

  case 111:
#line 441 "combine.y"
                        {
        loadNode();
    }
#line 2192 "y.tab.c"
    break;

  case 118:
#line 454 "combine.y"
      { /*establish local scope*/ ; }
#line 2198 "y.tab.c"
    break;

  case 120:
#line 455 "combine.y"
            {
        extendTerminal("break", "break");
    }
#line 2206 "y.tab.c"
    break;

  case 122:
#line 458 "combine.y"
               {
        extendTerminal("continue", "continue");
    }
#line 2214 "y.tab.c"
    break;

  case 124:
#line 461 "combine.y"
             {
        extendTree(NON_TERMINAL, "return", "return");
    }
#line 2222 "y.tab.c"
    break;

  case 125:
#line 463 "combine.y"
                           {
        backToParent();
    }
#line 2230 "y.tab.c"
    break;

  case 127:
#line 467 "combine.y"
            {
        extendTree(NON_TERMINAL, "print", "print");
    }
#line 2238 "y.tab.c"
    break;

  case 128:
#line 469 "combine.y"
         {
        extendTree(NON_TERMINAL, "", "print_content");
    }
#line 2246 "y.tab.c"
    break;

  case 129:
#line 471 "combine.y"
                       {
        backToParent();
        backToParent();
    }
#line 2255 "y.tab.c"
    break;

  case 131:
#line 475 "combine.y"
            {
        extendTree(NON_TERMINAL, "input", "input");
    }
#line 2263 "y.tab.c"
    break;

  case 132:
#line 477 "combine.y"
                                 {
        backToParent();
    }
#line 2271 "y.tab.c"
    break;

  case 135:
#line 486 "combine.y"
               {
        extendTerminal((yyvsp[0].str), "string");
    }
#line 2279 "y.tab.c"
    break;

  case 136:
#line 492 "combine.y"
          {
        extendTree(NON_TERMINAL, "{}", "statement body");
    }
#line 2287 "y.tab.c"
    break;

  case 137:
#line 494 "combine.y"
                         {
        backToParent();
    }
#line 2295 "y.tab.c"
    break;

  case 140:
#line 505 "combine.y"
      {
        extendTree(NON_TERMINAL, "", "declaration");
    }
#line 2303 "y.tab.c"
    break;

  case 141:
#line 507 "combine.y"
                      {
        extendTree(NON_TERMINAL, "", "declaration body");
        saveNode();
    }
#line 2312 "y.tab.c"
    break;

  case 143:
#line 514 "combine.y"
                           {
        extendTree(NON_TERMINAL, "", "function declaration");
        broToParent(-1);
        connectParentChild();
    }
#line 2322 "y.tab.c"
    break;

  case 144:
#line 519 "combine.y"
                                {
        extendTree(NON_TERMINAL, "", "argument declaration list");
        broToParent(-1);
        connectParentChild();
    }
#line 2332 "y.tab.c"
    break;

  case 146:
#line 527 "combine.y"
                         {
        extendTree(NON_TERMINAL, "()", "function argument list");
    }
#line 2340 "y.tab.c"
    break;

  case 147:
#line 529 "combine.y"
                                {
        backToParent();
        // establish local scope
    }
#line 2349 "y.tab.c"
    break;

  case 149:
#line 536 "combine.y"
      {
        extendTree(NON_TERMINAL, "", "function defination");
    }
#line 2357 "y.tab.c"
    break;

  case 150:
#line 538 "combine.y"
                      {
        backToParent();
    }
#line 2365 "y.tab.c"
    break;

  case 155:
#line 554 "combine.y"
                      {
        extendTree(NON_TERMINAL, "", "argument declaration unit");
        broToParent(1);
        backToParent();
    }
#line 2375 "y.tab.c"
    break;

  case 156:
#line 562 "combine.y"
             {
        extendOptTree("=");
    }
#line 2383 "y.tab.c"
    break;

  case 157:
#line 564 "combine.y"
                        {
        backToParent();
    }
#line 2391 "y.tab.c"
    break;

  case 159:
#line 571 "combine.y"
                                     {
        extendTerminal((yyvsp[0].str), "identifier");
    }
#line 2399 "y.tab.c"
    break;

  case 160:
#line 573 "combine.y"
                        {
        loadNode();
    }
#line 2407 "y.tab.c"
    break;

  case 161:
#line 579 "combine.y"
      {
        extendTree(NON_TERMINAL, "", "function argument unit");
        saveNode();
    }
#line 2416 "y.tab.c"
    break;

  case 162:
#line 582 "combine.y"
                                                                {
        backToParent();
    }
#line 2424 "y.tab.c"
    break;

  case 167:
#line 598 "combine.y"
         { 
        extendTree(NON_TERMINAL, "if", "if expression");
    }
#line 2432 "y.tab.c"
    break;

  case 168:
#line 600 "combine.y"
         {
        extendTree(NON_TERMINAL, "()", "if condition");
    }
#line 2440 "y.tab.c"
    break;

  case 169:
#line 602 "combine.y"
                    {
        backToParent();
        extendTree(NON_TERMINAL, "", "if statement");
    }
#line 2449 "y.tab.c"
    break;

  case 171:
#line 609 "combine.y"
           {
        extendTree(NON_TERMINAL, "else", "else statement");
    }
#line 2457 "y.tab.c"
    break;

  case 173:
#line 612 "combine.y"
      {}
#line 2463 "y.tab.c"
    break;


#line 2467 "y.tab.c"

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
#line 615 "combine.y"



   
void extendTree(int isTerminal, const char* word, const char* grammer) {
    tempPointer = createGrammerNode(isTerminal, word, grammer, word_pos++); 
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

void broToParent(int num = -1) {
    grammerTree* parent = curNode->parent;
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
    grammerTree* child[] = curNode->child;
    for (int i = 0; i < curNode->size; i++) {
        push_child(parent, child[i]);
    }
    freeGrammerNode(curNode);
    curNode = parent;
}

int main(void) { 
    root = createGrammerNode(NON_TERMINAL, "start", -1, word_pos++);
    curNode = root;
    tempPointer = NULL;
    yyparse();
    generateYACC();
    printGrammerTree(root);
    closeYACC();
    freeGrammerTree(root);
    return 0; 
}   


