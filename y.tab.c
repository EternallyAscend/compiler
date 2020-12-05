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
#line 1 "c.y"

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


#line 110 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 43 "c.y"

    char* str;

#line 256 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  134
/* YYNRULES -- Number of rules.  */
#define YYNRULES  184
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  270

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
       0,   108,   108,   112,   114,   112,   117,   121,   121,   125,
     127,   125,   130,   134,   134,   138,   140,   138,   143,   147,
     147,   151,   153,   151,   156,   160,   160,   164,   164,   169,
     169,   174,   178,   178,   182,   182,   187,   187,   192,   192,
     197,   197,   202,   206,   206,   210,   212,   210,   215,   217,
     215,   220,   224,   224,   228,   230,   228,   233,   235,   233,
     238,   240,   238,   243,   247,   247,   251,   253,   251,   256,
     260,   262,   260,   268,   268,   271,   275,   275,   280,   280,
     286,   292,   292,   297,   301,   304,   307,   307,   316,   321,
     324,   326,   316,   332,   335,   337,   332,   373,   374,   375,
     379,   380,   384,   385,   389,   393,   396,   399,   402,   389,
     412,   412,   420,   421,   425,   425,   428,   432,   435,   439,
     441,   439,   449,   450,   451,   452,   453,   454,   455,   455,
     456,   456,   459,   459,   462,   462,   467,   468,   470,   472,
     468,   476,   478,   476,   486,   487,   493,   493,   501,   502,
     506,   508,   506,   515,   520,   520,   528,   530,   528,   537,
     537,   542,   546,   550,   551,   555,   555,   564,   564,   569,
     573,   573,   581,   581,   590,   591,   595,   596,   600,   602,
     604,   600,   611,   611,   614
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
  "comma_expression", "$@1", "$@2", "single_expression", "$@3",
  "assign_expression", "$@4", "$@5", "orh_expression", "$@6",
  "or_expression", "$@7", "$@8", "andh_expression", "$@9",
  "and_expression", "$@10", "$@11", "eneh_expression", "$@12",
  "ene_expression", "$@13", "$@14", "lgh_expression", "$@15",
  "lg_expression", "$@16", "$@17", "$@18", "$@19", "pmh_expression",
  "$@20", "pm_expression", "$@21", "$@22", "$@23", "$@24",
  "mtdh_expression", "$@25", "mtd_expression", "$@26", "$@27", "$@28",
  "$@29", "$@30", "$@31", "powh_expression", "$@32", "pow_expression",
  "$@33", "$@34", "noth_expression", "$@35", "$@36", "not_expression",
  "$@37", "pid_expression", "$@38", "$@39", "pointer_expression", "$@40",
  "type_defination", "$@41", "do_expression", "$@42", "$@43", "$@44",
  "$@45", "while_expression", "$@46", "$@47", "$@48",
  "for_init_expression", "for_condition_expression",
  "for_action_expression", "for_expression", "$@49", "$@50", "$@51",
  "$@52", "$@53", "array_decorator", "$@54", "high_ay_decorator",
  "high_nter_decorator", "$@55", "address_decorator",
  "decorated_identifier", "$@56", "$@57", "statement", "$@58", "$@59",
  "$@60", "$@61", "$@62", "$@63", "$@64", "$@65", "$@66", "print_content",
  "statement_block", "$@67", "statement_body", "declaration", "$@68",
  "$@69", "declaration_body", "$@70", "function_declaration", "$@71",
  "$@72", "function_defination", "$@73", "argument_declaration_list",
  "argument_declaration_list_tail", "argument_declaration_unit", "$@74",
  "argument_declaration_init", "$@75", "init_identifier", "$@76",
  "function_argument", "$@77", "function_argument_list",
  "function_argument_tail", "condition_expression", "$@78", "$@79", "$@80",
  "condition_tail", "$@81", YY_NULLPTR
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

#define YYPACT_NINF (-214)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-176)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      51,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,   -20,   -13,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,    16,  -214,  -214,  -214,     6,    28,    43,    26,   -24,
    -214,    56,    59,    66,    77,    28,    80,    63,    82,  -214,
    -214,  -214,  -214,    70,    85,    89,    -4,     5,    50,    35,
     102,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,    83,  -214,  -214,  -214,
      87,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,    16,    19,    64,   113,   105,
     120,   116,   111,  -214,  -214,  -214,   -19,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,   114,
    -214,  -214,   121,  -214,  -214,  -214,    96,   123,  -214,  -214,
     124,  -214,  -214,   105,   125,   126,   130,  -214,    97,  -214,
     -13,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,   127,  -214,  -214,   105,
    -214,   115,   105,  -214,  -214,   118,  -214,   117,   144,  -214,
    -214,  -214,  -214,  -214,    70,    85,    89,    50,    50,    35,
      35,    35,   102,   146,  -214,   145,  -214,   147,  -214,  -214,
    -214,   149,  -214,  -214,   128,  -214,  -214,   104,    28,  -214,
     129,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,   147,  -214,   122,   -24,   151,  -214,  -214,
     147,   131,  -214,   152,  -214,   132,   127,  -214,  -214,   149,
    -214,   105,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
     154,  -214,   118,   134,   104,   135,   153,  -214,  -214,  -214,
    -214,    28,  -214,  -214,  -214,   157,  -214,  -214,    28,  -214
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      70,   137,   141,   136,   178,    93,    88,   104,   132,   130,
     134,     0,     6,     7,    13,    19,    25,    32,    43,    52,
      64,    75,   124,   125,   123,    70,     0,     0,     0,     0,
     126,     0,     0,     0,     0,     0,     0,     0,     0,    70,
     122,     3,     2,    12,    18,    24,    31,    42,    51,    63,
      69,    73,    71,   148,   146,   129,     1,   127,    84,    85,
      86,   151,   138,   119,   179,    94,     0,   105,   133,   131,
       0,    70,     9,     8,    15,    14,    21,    20,    27,    29,
      26,    34,    38,    36,    40,    33,    45,    48,    44,    57,
      60,    54,    53,    66,    65,    75,     0,    70,     0,   116,
      70,     0,   118,    70,    70,    89,    70,   135,     4,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    74,    80,    78,    76,    72,     0,
      87,   114,     0,   152,   153,   154,   164,   165,   145,   144,
       0,   142,   117,   116,     0,     0,     0,    98,     0,    97,
       6,    10,    16,    22,    28,    30,    35,    39,    37,    41,
      46,    49,    58,    61,    55,    67,    83,    70,   147,   116,
     170,     0,   116,   162,   156,   169,   139,     0,     0,   180,
      95,    90,   106,     5,    12,    18,    24,    51,    51,    63,
      63,    63,    69,     0,    79,     0,   115,   113,   155,   163,
     165,   172,   167,   166,     0,   143,   120,    70,     0,    70,
      70,    11,    17,    23,    47,    50,    59,    62,    56,    68,
      81,    77,   110,   113,   171,   177,     0,     0,    70,   140,
     113,   184,    96,     0,   100,     0,    83,    70,   112,   172,
     174,   116,   157,   168,   121,   182,   181,    91,   107,    82,
       0,   176,   169,   159,    70,     0,    70,   111,   173,   161,
     158,     0,   183,    92,   102,     0,   160,   108,     0,   109
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,   -38,    24,  -214,  -214,   -69,  -214,   -29,  -214,  -214,
      67,  -214,   -10,  -214,  -214,    68,  -214,    -9,  -214,  -214,
      69,  -214,  -214,  -214,  -214,   -31,  -214,  -214,  -214,  -214,
    -214,  -214,   -80,  -214,   -76,  -214,  -214,  -214,  -214,    -5,
    -214,  -131,  -214,  -214,  -214,  -214,  -214,  -214,   -42,  -214,
     -11,  -214,  -214,    60,  -214,  -214,    84,  -214,  -214,  -214,
    -214,   -54,  -214,   -41,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -213,  -136,  -214,  -214,  -214,
    -214,  -214,  -202,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,   -35,  -214,   -22,    78,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,    14,  -214,  -214,  -214,
     -65,  -214,  -168,  -214,  -214,  -214,   -51,  -214,  -214,  -214,
    -214,  -214,  -214,  -214
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    42,    71,   150,    12,    43,    73,   109,   184,
      13,    44,    75,   110,   185,    14,    45,    77,   111,   186,
      15,    46,    80,   112,   113,    16,    47,    85,   114,   116,
     115,   117,    17,    48,    88,   118,   187,   119,   188,    18,
      49,    92,   122,   191,   120,   189,   121,   190,    19,    50,
      94,   123,   192,    20,    21,    96,    52,    95,   128,   167,
     166,   194,   236,    61,    98,    22,    35,   146,   209,   255,
      23,    34,   104,   208,   148,   235,   265,    24,    36,   106,
     210,   256,   268,   223,   237,   224,   132,   169,   143,   101,
     102,   230,    25,    26,    38,    37,    39,    31,   100,   204,
      32,   177,   140,    55,    97,    27,    28,    29,    99,   133,
     171,   134,   201,   253,   260,   261,   135,   173,   136,   175,
     203,   228,   137,   197,   225,   226,   227,   240,    30,    33,
     103,   207,   246,   254
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    70,   108,    53,   200,   231,  -149,   178,    58,    59,
     238,     1,     2,  -150,  -150,    40,   -99,   244,  -128,  -149,
      60,    41,   125,    78,    79,  -150,   126,   127,    81,    82,
      83,    84,    51,   196,   156,   157,   158,   159,  -150,  -150,
      54,     3,     4,    56,     5,     6,     7,     8,     9,    10,
    -150,  -149,   262,    89,    90,    91,     1,     2,   216,   217,
     218,    57,   139,  -128,    62,   144,   145,    63,   147,     1,
       2,    86,    87,   252,    64,   129,  -128,  -149,   162,   163,
     164,   154,   155,  -150,  -150,    65,     3,     4,    67,     5,
       6,     7,     8,     9,    10,  -150,  -150,  -150,    68,     3,
       4,    72,     5,     6,     7,     8,     9,    10,  -150,     1,
       2,   214,   215,   160,   161,    74,  -128,    69,    76,    93,
     130,   105,   107,   131,   138,   141,   142,   168,   170,   195,
     172,   174,   182,   176,   179,   180,  -150,  -150,   181,     3,
       4,   193,     5,     6,     7,     8,     9,    10,  -150,   202,
     198,   206,   205,   220,   221,   211,   239,   222,  -175,   243,
     242,   247,  -103,   229,  -101,   257,   267,   248,   245,   259,
     263,   233,   234,   232,   183,   212,   151,   213,   152,   124,
     153,   219,   249,   165,   149,   241,   199,   258,   251,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
       0,     0,     0,     0,     0,     0,   266,     0,     0,     0,
       0,     0,     0,   269
};

static const yytype_int16 yycheck[] =
{
      35,    39,    71,    25,   172,   207,     0,   143,    32,    33,
     223,     5,     6,    32,    33,    35,    35,   230,    12,    13,
      44,    34,     3,    27,    28,    44,     7,     8,    23,    24,
      25,    26,    16,   169,   114,   115,   116,   117,    32,    33,
      12,    35,    36,     0,    38,    39,    40,    41,    42,    43,
      44,     0,   254,    18,    19,    20,     5,     6,   189,   190,
     191,    35,   100,    12,     8,   103,   104,     8,   106,     5,
       6,    21,    22,   241,     8,    97,    12,    13,   120,   121,
     122,   112,   113,    32,    33,     8,    35,    36,     8,    38,
      39,    40,    41,    42,    43,    44,    32,    33,    35,    35,
      36,    31,    38,    39,    40,    41,    42,    43,    44,     5,
       6,   187,   188,   118,   119,    30,    12,    35,    29,    17,
       7,    38,    35,    18,     4,     9,    15,    13,     7,   167,
      34,     8,    35,     9,     9,     9,    32,    33,     8,    35,
      36,    14,    38,    39,    40,    41,    42,    43,    44,    31,
      35,     7,    35,     7,     9,   184,    34,    10,     9,   228,
       9,     9,     9,    35,    35,    11,     9,    35,    37,    35,
      35,   209,   210,   208,   150,   185,   109,   186,   110,    95,
     111,   192,   236,   123,   106,   226,   172,   252,   239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,    -1,    -1,   268
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    35,    36,    38,    39,    40,    41,    42,
      43,    47,    51,    56,    61,    66,    71,    78,    85,    94,
      99,   100,   111,   116,   123,   138,   139,   151,   152,   153,
     174,   143,   146,   175,   117,   112,   124,   141,   140,   142,
      35,    34,    48,    52,    57,    62,    67,    72,    79,    86,
      95,    16,   102,   151,    12,   149,     0,    35,    32,    33,
      44,   109,     8,     8,     8,     8,   149,     8,    35,    35,
      47,    49,    31,    53,    30,    58,    29,    63,    27,    28,
      68,    23,    24,    25,    26,    73,    21,    22,    80,    18,
      19,    20,    87,    17,    96,   103,   101,   150,   110,   154,
     144,   135,   136,   176,   118,    38,   125,    35,    51,    54,
      59,    64,    69,    70,    74,    76,    75,    77,    81,    83,
      90,    92,    88,    97,   102,     3,     7,     8,   104,   151,
       7,    18,   132,   155,   157,   162,   164,   168,     4,    47,
     148,     9,    15,   134,    47,    47,   113,    47,   120,   152,
      50,    56,    61,    66,    71,    71,    78,    78,    78,    78,
      85,    85,    94,    94,    94,    99,   106,   105,    13,   133,
       7,   156,    34,   163,     8,   165,     9,   147,   132,     9,
       9,     8,    35,    48,    55,    60,    65,    82,    84,    91,
      93,    89,    98,    14,   107,    47,   132,   169,    35,   162,
     168,   158,    31,   166,   145,    35,     7,   177,   119,   114,
     126,    53,    58,    63,    80,    80,    87,    87,    87,    96,
       7,     9,    10,   129,   131,   170,   171,   172,   167,    35,
     137,   138,   149,    47,    47,   121,   108,   130,   131,    34,
     173,   109,     9,    51,   131,    37,   178,     9,    35,   107,
      47,   172,   168,   159,   179,   115,   127,    11,   166,    35,
     160,   161,   138,    35,    47,   122,   149,     9,   128,   149
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    49,    50,    48,    48,    52,    51,    54,
      55,    53,    53,    57,    56,    59,    60,    58,    58,    62,
      61,    64,    65,    63,    63,    67,    66,    69,    68,    70,
      68,    68,    72,    71,    74,    73,    75,    73,    76,    73,
      77,    73,    73,    79,    78,    81,    82,    80,    83,    84,
      80,    80,    86,    85,    88,    89,    87,    90,    91,    87,
      92,    93,    87,    87,    95,    94,    97,    98,    96,    96,
     100,   101,    99,   103,   102,   102,   105,   104,   106,   104,
     104,   108,   107,   107,   109,   109,   110,   109,   112,   113,
     114,   115,   111,   117,   118,   119,   116,   120,   120,   120,
     121,   121,   122,   122,   124,   125,   126,   127,   128,   123,
     130,   129,   131,   131,   133,   132,   132,   134,   134,   136,
     137,   135,   138,   138,   138,   138,   138,   138,   139,   138,
     140,   138,   141,   138,   142,   138,   138,   143,   144,   145,
     138,   146,   147,   138,   148,   148,   150,   149,   151,   151,
     153,   154,   152,   155,   156,   155,   158,   159,   157,   161,
     160,   160,   162,   163,   163,   165,   164,   167,   166,   166,
     169,   168,   171,   170,   172,   172,   173,   173,   175,   176,
     177,   174,   179,   178,   178
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     0,     5,     0,     0,     3,     0,
       0,     5,     0,     0,     3,     0,     0,     5,     0,     0,
       3,     0,     0,     5,     0,     0,     3,     0,     3,     0,
       3,     0,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     0,     3,     0,     0,     5,     0,     0,
       5,     0,     0,     3,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     0,     0,     3,     0,     0,     5,     0,
       0,     0,     4,     0,     3,     0,     0,     4,     0,     3,
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
#line 112 "c.y"
            {
        extendOptTree(",");
    }
#line 1664 "y.tab.c"
    break;

  case 4:
#line 114 "c.y"
                        {
        backToParent();
    }
#line 1672 "y.tab.c"
    break;

  case 7:
#line 121 "c.y"
                     {printf("single\n");}
#line 1678 "y.tab.c"
    break;

  case 9:
#line 125 "c.y"
             { 
        extendOptTree("=");
    }
#line 1686 "y.tab.c"
    break;

  case 10:
#line 127 "c.y"
                     { 
        backToParent();
    }
#line 1694 "y.tab.c"
    break;

  case 13:
#line 134 "c.y"
                      {printf("orh\n");}
#line 1700 "y.tab.c"
    break;

  case 15:
#line 138 "c.y"
         { 
        extendOptTree("||");
    }
#line 1708 "y.tab.c"
    break;

  case 16:
#line 140 "c.y"
                      {
        backToParent();
    }
#line 1716 "y.tab.c"
    break;

  case 19:
#line 147 "c.y"
                      {printf("andh\n");}
#line 1722 "y.tab.c"
    break;

  case 21:
#line 151 "c.y"
          {  
        extendOptTree("&&");
    }
#line 1730 "y.tab.c"
    break;

  case 22:
#line 153 "c.y"
                      {
        backToParent();
    }
#line 1738 "y.tab.c"
    break;

  case 25:
#line 160 "c.y"
                     {printf("eneh\n");}
#line 1744 "y.tab.c"
    break;

  case 27:
#line 164 "c.y"
         {  
        extendOptTree("==");
    }
#line 1752 "y.tab.c"
    break;

  case 28:
#line 166 "c.y"
                     {
        backToParent();
    }
#line 1760 "y.tab.c"
    break;

  case 29:
#line 169 "c.y"
         {  
        extendOptTree("!=");
    }
#line 1768 "y.tab.c"
    break;

  case 30:
#line 171 "c.y"
                     {
        backToParent();
    }
#line 1776 "y.tab.c"
    break;

  case 32:
#line 178 "c.y"
                     {printf("lgh\n");}
#line 1782 "y.tab.c"
    break;

  case 34:
#line 182 "c.y"
         {  
        extendOptTree(">");
    }
#line 1790 "y.tab.c"
    break;

  case 35:
#line 184 "c.y"
                     {
        backToParent();
    }
#line 1798 "y.tab.c"
    break;

  case 36:
#line 187 "c.y"
         {  
        extendOptTree(">=");
    }
#line 1806 "y.tab.c"
    break;

  case 37:
#line 189 "c.y"
                     {
        backToParent();
    }
#line 1814 "y.tab.c"
    break;

  case 38:
#line 192 "c.y"
         {  
        extendOptTree("<");
    }
#line 1822 "y.tab.c"
    break;

  case 39:
#line 194 "c.y"
                     {
        backToParent();
    }
#line 1830 "y.tab.c"
    break;

  case 40:
#line 197 "c.y"
         {  
        extendOptTree("<=");
    }
#line 1838 "y.tab.c"
    break;

  case 41:
#line 199 "c.y"
                     {
        backToParent();
    }
#line 1846 "y.tab.c"
    break;

  case 43:
#line 206 "c.y"
                      {printf("pmh\n");}
#line 1852 "y.tab.c"
    break;

  case 45:
#line 210 "c.y"
           { 
        extendOptTree("+");
    }
#line 1860 "y.tab.c"
    break;

  case 46:
#line 212 "c.y"
                      {
        backToParent();
    }
#line 1868 "y.tab.c"
    break;

  case 48:
#line 215 "c.y"
            { 
        extendOptTree("-");
    }
#line 1876 "y.tab.c"
    break;

  case 49:
#line 217 "c.y"
                      {
        backToParent();
    }
#line 1884 "y.tab.c"
    break;

  case 52:
#line 224 "c.y"
                      {printf("mtdh\n");}
#line 1890 "y.tab.c"
    break;

  case 54:
#line 228 "c.y"
          { 
        extendOptTree("%");
    }
#line 1898 "y.tab.c"
    break;

  case 55:
#line 230 "c.y"
                      {
        backToParent();
    }
#line 1906 "y.tab.c"
    break;

  case 57:
#line 233 "c.y"
            { 
        extendOptTree("*");
    }
#line 1914 "y.tab.c"
    break;

  case 58:
#line 235 "c.y"
                      {
        backToParent();
    }
#line 1922 "y.tab.c"
    break;

  case 60:
#line 238 "c.y"
             { 
        extendOptTree("/");
    }
#line 1930 "y.tab.c"
    break;

  case 61:
#line 240 "c.y"
                      {
        backToParent();
    }
#line 1938 "y.tab.c"
    break;

  case 64:
#line 247 "c.y"
                      {printf("powh\n");}
#line 1944 "y.tab.c"
    break;

  case 66:
#line 251 "c.y"
          { 
        extendOptTree("^");
    }
#line 1952 "y.tab.c"
    break;

  case 67:
#line 253 "c.y"
                      {
        backToParent();
    }
#line 1960 "y.tab.c"
    break;

  case 70:
#line 260 "c.y"
      {
        saveNode();
    }
#line 1968 "y.tab.c"
    break;

  case 71:
#line 262 "c.y"
                     {printf("noth\n");}
#line 1974 "y.tab.c"
    break;

  case 72:
#line 262 "c.y"
                                                        {
        loadNode();
    }
#line 1982 "y.tab.c"
    break;

  case 73:
#line 268 "c.y"
          { 
        extendTree(NON_TERMINAL, "!", "expression");
    }
#line 1990 "y.tab.c"
    break;

  case 76:
#line 275 "c.y"
         { 
        extendTree(NON_TERMINAL, "()", "expression");
    }
#line 1998 "y.tab.c"
    break;

  case 77:
#line 277 "c.y"
                    { 
        backToParent();
    }
#line 2006 "y.tab.c"
    break;

  case 78:
#line 280 "c.y"
                 {
        //saveNode();
        extendTree(TERMINAL, (yyvsp[0].str), "identifier");
    }
#line 2015 "y.tab.c"
    break;

  case 79:
#line 283 "c.y"
                         {
        //loadNode();
    }
#line 2023 "y.tab.c"
    break;

  case 80:
#line 286 "c.y"
               { 
        extendTree(TERMINAL, (yyvsp[0].str), "const");
    }
#line 2031 "y.tab.c"
    break;

  case 81:
#line 292 "c.y"
                         {
        extendOptTree("->");
        extendTerminal("IDENTIFIER", (yyvsp[0].str));
        backToParent();
    }
#line 2041 "y.tab.c"
    break;

  case 84:
#line 301 "c.y"
          { 
        extendTerminal("int", "type");
    }
#line 2049 "y.tab.c"
    break;

  case 85:
#line 304 "c.y"
           { 
        extendTerminal("void", "type");
    }
#line 2057 "y.tab.c"
    break;

  case 86:
#line 307 "c.y"
             {
        extendTree(NON_TERMINAL, "struct", "type");
    }
#line 2065 "y.tab.c"
    break;

  case 87:
#line 309 "c.y"
                 {  
        extendTerminal((yyvsp[0].str), "identifier");
        backToParent();
    }
#line 2074 "y.tab.c"
    break;

  case 88:
#line 316 "c.y"
         { 
        /*establish local scope*/ ;
        saveNode();
        extendTree(NON_TERMINAL, "", "do while loop");
        extendTree(NON_TERMINAL, "do", "loop body");
    }
#line 2085 "y.tab.c"
    break;

  case 89:
#line 321 "c.y"
                            {
        backToParent();
        extendTree(NON_TERMINAL, "while", "loop condition");
    }
#line 2094 "y.tab.c"
    break;

  case 90:
#line 324 "c.y"
         {  
        extendTree(NON_TERMINAL, "()", "expression");
    }
#line 2102 "y.tab.c"
    break;

  case 91:
#line 326 "c.y"
                    { 
        loadNode();
    }
#line 2110 "y.tab.c"
    break;

  case 93:
#line 332 "c.y"
            {  
        saveNode();
        extendTree(NON_TERMINAL, "while", "while loop");
    }
#line 2119 "y.tab.c"
    break;

  case 94:
#line 335 "c.y"
         { 
        extendTree(NON_TERMINAL, "()", "expression"); 
    }
#line 2127 "y.tab.c"
    break;

  case 95:
#line 337 "c.y"
                    { 
        backToParent(); 
        /*establish local scope*/ ;
        extendTree(NON_TERMINAL, "", "loop body");
    }
#line 2137 "y.tab.c"
    break;

  case 96:
#line 341 "c.y"
                      {
        loadNode();
    }
#line 2145 "y.tab.c"
    break;

  case 104:
#line 389 "c.y"
          { 
        /*establish local scope*/ ;
        saveNode();
        extendTree(NON_TERMINAL, "for", "for loop");
    }
#line 2155 "y.tab.c"
    break;

  case 105:
#line 393 "c.y"
         {  
        extendTree(NON_TERMINAL, "()", "for expression");
        extendTree(NON_TERMINAL, "", "for init expression");
    }
#line 2164 "y.tab.c"
    break;

  case 106:
#line 396 "c.y"
                                    {
        backToParent();
        extendTree(NON_TERMINAL, "", "for condition");
    }
#line 2173 "y.tab.c"
    break;

  case 107:
#line 399 "c.y"
                                         {
        backToParent();
        extendTree(NON_TERMINAL, "", "for action");
    }
#line 2182 "y.tab.c"
    break;

  case 108:
#line 402 "c.y"
                               {  
        backToParent();
        backToParent();
        extendTree(NON_TERMINAL, "", "loop body");
    }
#line 2192 "y.tab.c"
    break;

  case 109:
#line 406 "c.y"
                      {
        loadNode();
    }
#line 2200 "y.tab.c"
    break;

  case 110:
#line 412 "c.y"
          { 
        extendOptTree("[]"); 
    }
#line 2208 "y.tab.c"
    break;

  case 111:
#line 414 "c.y"
                     {
        backToParent();
    }
#line 2216 "y.tab.c"
    break;

  case 114:
#line 425 "c.y"
            {
        extendTree(NON_TERMINAL, "*", "pointer");
    }
#line 2224 "y.tab.c"
    break;

  case 117:
#line 432 "c.y"
              {
        extendTree(NON_TERMINAL, "&", "address");
    }
#line 2232 "y.tab.c"
    break;

  case 119:
#line 439 "c.y"
      {
        saveNode();
    }
#line 2240 "y.tab.c"
    break;

  case 120:
#line 441 "c.y"
                                                       {
        extendTerminal((yyvsp[0].str), "identifier");
    }
#line 2248 "y.tab.c"
    break;

  case 121:
#line 443 "c.y"
                        {
        loadNode();
    }
#line 2256 "y.tab.c"
    break;

  case 128:
#line 455 "c.y"
      { /*establish local scope*/ ; }
#line 2262 "y.tab.c"
    break;

  case 130:
#line 456 "c.y"
            {
        extendTerminal("break", "break");
    }
#line 2270 "y.tab.c"
    break;

  case 132:
#line 459 "c.y"
               {
        extendTerminal("continue", "continue");
    }
#line 2278 "y.tab.c"
    break;

  case 134:
#line 462 "c.y"
             {
        extendTree(NON_TERMINAL, "return", "return");
    }
#line 2286 "y.tab.c"
    break;

  case 135:
#line 464 "c.y"
                           {
        backToParent();
    }
#line 2294 "y.tab.c"
    break;

  case 137:
#line 468 "c.y"
            {
        extendTree(NON_TERMINAL, "print", "print");
    }
#line 2302 "y.tab.c"
    break;

  case 138:
#line 470 "c.y"
         {
        extendTree(NON_TERMINAL, "", "print_content");
    }
#line 2310 "y.tab.c"
    break;

  case 139:
#line 472 "c.y"
                       {
        backToParent();
        backToParent();
    }
#line 2319 "y.tab.c"
    break;

  case 141:
#line 476 "c.y"
            {
        extendTree(NON_TERMINAL, "input", "input");
    }
#line 2327 "y.tab.c"
    break;

  case 142:
#line 478 "c.y"
                                 {
        backToParent();
    }
#line 2335 "y.tab.c"
    break;

  case 145:
#line 487 "c.y"
               {
        extendTerminal((yyvsp[0].str), "string");
    }
#line 2343 "y.tab.c"
    break;

  case 146:
#line 493 "c.y"
          {
        extendTree(NON_TERMINAL, "{}", "statement body");
    }
#line 2351 "y.tab.c"
    break;

  case 147:
#line 495 "c.y"
                         {
        backToParent();
    }
#line 2359 "y.tab.c"
    break;

  case 149:
#line 502 "c.y"
      { printf("statement body over!\n"); YYACCEPT; }
#line 2365 "y.tab.c"
    break;

  case 150:
#line 506 "c.y"
      {
        extendTree(NON_TERMINAL, "", "declaration");
    }
#line 2373 "y.tab.c"
    break;

  case 151:
#line 508 "c.y"
                      {
        extendTree(NON_TERMINAL, "", "declaration body");
        saveNode();
    }
#line 2382 "y.tab.c"
    break;

  case 153:
#line 515 "c.y"
                           {
        extendTree(NON_TERMINAL, "", "function declaration");
        broToParent(-1);
        connectParentChild();
    }
#line 2392 "y.tab.c"
    break;

  case 154:
#line 520 "c.y"
                                {
        extendTree(NON_TERMINAL, "", "argument declaration list");
        broToParent(-1);
        connectParentChild();
    }
#line 2402 "y.tab.c"
    break;

  case 156:
#line 528 "c.y"
                         {
        extendTree(NON_TERMINAL, "()", "function argument list");
    }
#line 2410 "y.tab.c"
    break;

  case 157:
#line 530 "c.y"
                                {
        backToParent();
        // establish local scope
    }
#line 2419 "y.tab.c"
    break;

  case 159:
#line 537 "c.y"
      {
        extendTree(NON_TERMINAL, "", "function defination");
    }
#line 2427 "y.tab.c"
    break;

  case 160:
#line 539 "c.y"
                      {
        backToParent();
    }
#line 2435 "y.tab.c"
    break;

  case 165:
#line 555 "c.y"
                      {
        extendTree(NON_TERMINAL, "", "argument declaration unit");
        broToParent(1);
    }
#line 2444 "y.tab.c"
    break;

  case 166:
#line 558 "c.y"
                                {
        backToParent();
    }
#line 2452 "y.tab.c"
    break;

  case 167:
#line 564 "c.y"
             {
        extendOptTree("=");
    }
#line 2460 "y.tab.c"
    break;

  case 168:
#line 566 "c.y"
                        {
        backToParent();
    }
#line 2468 "y.tab.c"
    break;

  case 170:
#line 573 "c.y"
                                     {
        extendTerminal((yyvsp[0].str), "identifier");
    }
#line 2476 "y.tab.c"
    break;

  case 171:
#line 575 "c.y"
                        {
        loadNode();
    }
#line 2484 "y.tab.c"
    break;

  case 172:
#line 581 "c.y"
      {
        extendTree(NON_TERMINAL, "", "function argument unit");
        saveNode();
    }
#line 2493 "y.tab.c"
    break;

  case 173:
#line 584 "c.y"
                                                                {
        backToParent();
    }
#line 2501 "y.tab.c"
    break;

  case 178:
#line 600 "c.y"
         { 
        extendTree(NON_TERMINAL, "if", "if expression");
    }
#line 2509 "y.tab.c"
    break;

  case 179:
#line 602 "c.y"
         {
        extendTree(NON_TERMINAL, "()", "if condition");
    }
#line 2517 "y.tab.c"
    break;

  case 180:
#line 604 "c.y"
                    {
        backToParent();
        extendTree(NON_TERMINAL, "", "if statement");
    }
#line 2526 "y.tab.c"
    break;

  case 182:
#line 611 "c.y"
           {
        extendTree(NON_TERMINAL, "else", "else statement");
    }
#line 2534 "y.tab.c"
    break;

  case 184:
#line 614 "c.y"
      {}
#line 2540 "y.tab.c"
    break;


#line 2544 "y.tab.c"

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
#line 617 "c.y"



   
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
    int err = yyparse();
    closeLEX();
    generateYACC();
    printGrammerTree(root);
    closeYACC();
    stopTable();
    freeGrammerTree(root);
    fclose(yyin);
    printf("%d\n", err);
    return 0; 
}   

void yyerror(const char* charactor) {
    
}
