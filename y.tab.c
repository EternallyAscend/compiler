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

#line 253 "y.tab.c"

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
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   228

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  131
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  268

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
       0,   108,   108,   112,   114,   112,   117,   121,   125,   127,
     125,   130,   134,   138,   140,   138,   143,   147,   151,   153,
     151,   156,   160,   164,   164,   169,   169,   174,   178,   182,
     182,   187,   187,   192,   192,   197,   197,   202,   206,   206,
     210,   212,   210,   215,   217,   215,   220,   224,   224,   228,
     230,   228,   233,   235,   233,   238,   240,   238,   243,   247,
     247,   251,   253,   251,   256,   260,   262,   260,   268,   268,
     271,   275,   275,   280,   281,   287,   287,   292,   296,   299,
     302,   302,   311,   317,   321,   323,   311,   329,   332,   334,
     329,   372,   373,   374,   378,   379,   383,   384,   388,   393,
     396,   399,   402,   388,   413,   414,   418,   418,   426,   427,
     431,   431,   434,   438,   441,   445,   447,   445,   455,   456,
     456,   463,   464,   465,   466,   467,   468,   469,   469,   472,
     472,   475,   475,   480,   481,   483,   485,   481,   489,   491,
     489,   497,   498,   504,   504,   512,   513,   517,   519,   517,
     526,   531,   531,   539,   542,   539,   551,   551,   556,   560,
     564,   565,   569,   569,   578,   578,   583,   587,   587,   595,
     595,   604,   605,   609,   610,   614,   616,   618,   622,   614,
     628,   628,   633
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
  "$@15", "pm_expression", "$@16", "$@17", "$@18", "$@19",
  "mtdh_expression", "$@20", "mtd_expression", "$@21", "$@22", "$@23",
  "$@24", "$@25", "$@26", "powh_expression", "$@27", "pow_expression",
  "$@28", "$@29", "noth_expression", "$@30", "$@31", "not_expression",
  "$@32", "pid_expression", "$@33", "pointer_expression", "$@34",
  "type_defination", "$@35", "do_expression", "$@36", "$@37", "$@38",
  "$@39", "while_expression", "$@40", "$@41", "$@42",
  "for_init_expression", "for_condition_expression",
  "for_action_expression", "for_expression", "$@43", "$@44", "$@45",
  "$@46", "$@47", "for_child_statement", "array_decorator", "$@48",
  "high_ay_decorator", "high_nter_decorator", "$@49", "address_decorator",
  "decorated_identifier", "$@50", "$@51", "statement", "$@52",
  "dependent_statement", "$@53", "$@54", "$@55", "$@56", "$@57", "$@58",
  "$@59", "$@60", "print_content", "statement_block", "$@61",
  "statement_body", "declaration", "$@62", "$@63", "declaration_body",
  "$@64", "function_declaration", "$@65", "$@66", "function_defination",
  "$@67", "argument_declaration_list", "argument_declaration_list_tail",
  "argument_declaration_unit", "$@68", "argument_declaration_init", "$@69",
  "init_identifier", "$@70", "function_argument", "$@71",
  "function_argument_list", "function_argument_tail",
  "condition_expression", "$@72", "$@73", "$@74", "$@75", "condition_tail",
  "$@76", YY_NULLPTR
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

#define YYPACT_NINF (-202)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-173)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      52,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,   -18,   -26,     0,    13,    11,    39,    10,  -202,  -202,
    -202,    35,  -202,  -202,  -202,     6,    51,  -202,    72,  -202,
     -12,  -202,    78,    81,    91,    94,    51,    97,    80,    82,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,    54,     4,
      99,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,    83,  -202,  -202,  -202,    84,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,    35,
       7,    68,   111,   104,   119,   115,   113,  -202,  -202,  -202,
     -19,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,   116,   118,  -202,  -202,   122,  -202,  -202,  -202,
      98,   126,  -202,  -202,   127,  -202,  -202,   104,   128,   129,
     131,  -202,   100,  -202,   -26,     0,    13,    11,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,   135,  -202,  -202,   104,  -202,
     120,   104,  -202,  -202,   136,  -202,   123,   159,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,    54,    54,     4,     4,
       4,    99,   162,   163,  -202,   163,  -202,  -202,  -202,   165,
    -202,  -202,   137,  -202,  -202,   108,    51,  -202,   140,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,   163,  -202,  -202,
     142,   -12,   168,  -202,  -202,   163,  -202,  -202,   169,  -202,
     144,  -202,  -202,   116,   165,  -202,   104,  -202,  -202,  -202,
     143,  -202,  -202,   170,  -202,  -202,   136,   147,  -202,  -202,
     148,   175,  -202,  -202,  -202,  -202,    51,   108,  -202,  -202,
     176,  -202,  -202,  -202,   121,  -202,  -202,  -202
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      65,   134,   138,   133,   175,    87,    82,    98,   129,   127,
     131,     0,     6,    11,    16,    21,    27,    37,    38,    47,
      59,    70,   123,   124,   122,    65,     0,   118,     0,   126,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
      65,   121,     3,     2,     8,     7,    13,    12,    18,    17,
      23,    25,    22,    29,    33,    31,    35,    28,    46,    58,
      64,    68,    66,   145,   143,   120,     1,    78,    79,    80,
     148,   135,   115,   176,    88,     0,    99,   130,   128,     0,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      40,    43,    39,    52,    55,    49,    48,    61,    60,    70,
     115,    65,     0,   112,    65,     0,   114,    65,    65,    83,
      65,   132,     4,     9,    14,    19,    24,    26,    30,    34,
      32,    36,    65,    65,    65,    65,    65,    65,    69,    74,
      71,    67,    77,     0,    81,   110,     0,   149,   150,   151,
     161,   162,   142,   141,     0,   139,   113,   112,     0,     0,
       0,    92,     0,    91,     6,    11,    16,    21,    41,    44,
      53,    56,    50,    62,    65,     0,    73,   144,   112,   167,
       0,   112,   159,   153,   166,   136,     0,     0,   177,    89,
      84,   100,     5,    10,    15,    20,    46,    46,    58,    58,
      58,    64,     0,   109,   111,   109,   152,   160,   162,   169,
     164,   163,     0,   140,   116,    65,     0,    65,    65,    42,
      45,    54,    57,    51,    63,    72,   106,   109,    75,   168,
     174,     0,     0,    65,   137,   109,   178,    90,     0,    94,
       0,    65,   108,    77,   169,   171,   112,   154,   165,   117,
     182,    85,   101,     0,    76,   173,   166,   156,   180,   179,
       0,    65,   107,   170,   158,   155,     0,    65,    86,    96,
       0,   157,   181,   102,    65,   103,   105,   104
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -202,   -39,    32,  -202,  -202,   -78,    33,  -202,  -202,   106,
      34,  -202,  -202,   107,    36,  -202,  -202,   112,  -202,  -202,
    -202,    -7,  -202,  -202,  -202,  -202,  -202,   -27,  -202,  -104,
    -202,  -202,  -202,  -202,   -25,  -202,  -162,  -202,  -202,  -202,
    -202,  -202,  -202,   -71,  -202,     3,  -202,  -202,    64,  -202,
    -202,   101,  -202,  -202,  -202,   -37,  -202,   -24,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -188,  -138,  -202,  -202,   102,  -202,  -202,  -201,  -202,   -66,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,   -36,
    -202,   -22,    89,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,    30,  -202,  -202,  -202,   -43,  -202,  -166,  -202,
    -202,  -202,   -30,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    43,    80,   154,    12,    45,    81,   155,    13,
      47,    82,   156,    14,    49,    83,   157,    15,    52,    84,
      85,    16,    57,    86,    88,    87,    89,    17,    58,    92,
     122,   186,   123,   187,    18,    59,    96,   126,   190,   124,
     188,   125,   189,    19,    60,    98,   127,   191,    20,    21,
     100,    62,    99,   131,   164,   166,   233,    70,   102,    22,
      36,   150,   207,   250,    23,    35,   108,   206,   152,   230,
     260,    24,    37,   110,   208,   251,   264,   265,   217,   231,
     218,   136,   168,   147,   105,   106,   225,    25,    26,    27,
      39,    38,    40,    32,   104,   202,    33,   176,   144,    65,
     101,    28,    29,    30,   103,   137,   170,   138,   199,   247,
     255,   256,   139,   172,   140,   174,   201,   223,   141,   195,
     220,   221,   222,   235,    31,    34,   107,   205,   240,   249,
     257
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    79,   112,    63,   226,   198,  -146,   219,    42,   177,
     129,     1,     2,  -147,  -147,   130,   -93,    41,  -119,  -146,
      67,    68,    93,    94,    95,  -147,   211,   212,   213,   232,
     194,    44,    69,    53,    54,    55,    56,   239,  -147,  -147,
      48,     3,     4,    46,     5,     6,     7,     8,     9,    10,
    -147,    61,  -146,   160,   161,   162,   262,     1,     2,   118,
     119,   120,   121,    64,  -119,   143,    50,    51,   148,   149,
     246,   151,    66,     1,     2,    90,    91,   116,   117,   133,
    -119,  -146,   209,   210,  -147,  -147,    71,     3,     4,    72,
       5,     6,     7,     8,     9,    10,  -147,   158,   159,    73,
    -147,  -147,    74,     3,     4,    76,     5,     6,     7,     8,
       9,    10,  -147,     1,     2,    77,    97,    78,   134,   111,
    -119,   109,   135,   142,   145,   192,     1,     2,   146,   169,
     165,   167,   171,    64,   173,   181,   175,   178,   179,   180,
    -147,  -147,   193,     3,     4,   238,     5,     6,     7,     8,
       9,    10,  -147,  -147,  -147,   196,     3,     4,   203,     5,
       6,     7,     8,     9,    10,  -147,   204,   200,   228,   229,
     227,   215,   224,   216,  -172,   -95,   234,   237,   241,   242,
     248,   252,   254,   258,   -97,   263,   182,   113,   183,   114,
     184,   163,   243,   185,   214,   115,   244,   236,   266,   153,
     128,   197,   132,   253,   245,     0,     0,     0,     0,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,     0,     0,     0,   267
};

static const yytype_int16 yycheck[] =
{
      36,    40,    80,    25,   205,   171,     0,   195,    34,   147,
       3,     5,     6,    32,    33,     8,    35,    35,    12,    13,
      32,    33,    18,    19,    20,    44,   188,   189,   190,   217,
     168,    31,    44,    23,    24,    25,    26,   225,    32,    33,
      29,    35,    36,    30,    38,    39,    40,    41,    42,    43,
      44,    16,     0,   124,   125,   126,   257,     5,     6,    86,
      87,    88,    89,    12,    12,   104,    27,    28,   107,   108,
     236,   110,     0,     5,     6,    21,    22,    84,    85,   101,
      12,    13,   186,   187,    32,    33,     8,    35,    36,     8,
      38,    39,    40,    41,    42,    43,    44,   122,   123,     8,
      32,    33,     8,    35,    36,     8,    38,    39,    40,    41,
      42,    43,    44,     5,     6,    35,    17,    35,     7,    35,
      12,    38,    18,     4,     9,   164,     5,     6,    15,     7,
      14,    13,    34,    12,     8,    35,     9,     9,     9,     8,
      32,    33,     7,    35,    36,   223,    38,    39,    40,    41,
      42,    43,    44,    32,    33,    35,    35,    36,    35,    38,
      39,    40,    41,    42,    43,    44,     7,    31,   207,   208,
     206,     9,    35,    10,     9,    35,    34,     9,     9,    35,
      37,    11,    35,    35,     9,     9,   154,    81,   155,    82,
     156,   127,   231,   157,   191,    83,   233,   221,   264,   110,
      99,   171,   100,   246,   234,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    35,    36,    38,    39,    40,    41,    42,
      43,    47,    51,    55,    59,    63,    67,    73,    80,    89,
      94,    95,   105,   110,   117,   133,   134,   135,   147,   148,
     149,   170,   139,   142,   171,   111,   106,   118,   137,   136,
     138,    35,    34,    48,    31,    52,    30,    56,    29,    60,
      27,    28,    64,    23,    24,    25,    26,    68,    74,    81,
      90,    16,    97,   147,    12,   145,     0,    32,    33,    44,
     103,     8,     8,     8,     8,   145,     8,    35,    35,    47,
      49,    53,    57,    61,    65,    66,    69,    71,    70,    72,
      21,    22,    75,    18,    19,    20,    82,    17,    91,    98,
      96,   146,   104,   150,   140,   130,   131,   172,   112,    38,
     119,    35,    51,    55,    59,    63,    67,    67,    73,    73,
      73,    73,    76,    78,    85,    87,    83,    92,    97,     3,
       8,    99,   130,   147,     7,    18,   127,   151,   153,   158,
     160,   164,     4,    47,   144,     9,    15,   129,    47,    47,
     107,    47,   114,   148,    50,    54,    58,    62,    80,    80,
      89,    89,    89,    94,   100,    14,   101,    13,   128,     7,
     152,    34,   159,     8,   161,     9,   143,   127,     9,     9,
       8,    35,    48,    52,    56,    60,    77,    79,    86,    88,
      84,    93,    47,     7,   127,   165,    35,   158,   164,   154,
      31,   162,   141,    35,     7,   173,   113,   108,   120,    75,
      75,    82,    82,    82,    91,     9,    10,   124,   126,   126,
     166,   167,   168,   163,    35,   132,   133,   145,    47,    47,
     115,   125,   126,   102,    34,   169,   103,     9,    51,   126,
     174,     9,    35,    47,   101,   168,   164,   155,    37,   175,
     109,   121,    11,   162,    35,   156,   157,   176,    35,    47,
     116,   145,   133,     9,   122,   123,   135,   145
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    49,    50,    48,    48,    51,    53,    54,
      52,    52,    55,    57,    58,    56,    56,    59,    61,    62,
      60,    60,    63,    65,    64,    66,    64,    64,    67,    69,
      68,    70,    68,    71,    68,    72,    68,    68,    74,    73,
      76,    77,    75,    78,    79,    75,    75,    81,    80,    83,
      84,    82,    85,    86,    82,    87,    88,    82,    82,    90,
      89,    92,    93,    91,    91,    95,    96,    94,    98,    97,
      97,   100,    99,    99,    99,   102,   101,   101,   103,   103,
     104,   103,   106,   107,   108,   109,   105,   111,   112,   113,
     110,   114,   114,   114,   115,   115,   116,   116,   118,   119,
     120,   121,   122,   117,   123,   123,   125,   124,   126,   126,
     128,   127,   127,   129,   129,   131,   132,   130,   133,   134,
     133,   135,   135,   135,   135,   135,   135,   136,   135,   137,
     135,   138,   135,   135,   139,   140,   141,   135,   142,   143,
     135,   144,   144,   146,   145,   147,   147,   149,   150,   148,
     151,   152,   151,   154,   155,   153,   157,   156,   156,   158,
     159,   159,   161,   160,   163,   162,   162,   165,   164,   167,
     166,   168,   168,   169,   169,   171,   172,   173,   174,   170,
     176,   175,   175
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     0,     5,     0,     2,     0,     0,
       5,     0,     2,     0,     0,     5,     0,     2,     0,     0,
       5,     0,     2,     0,     3,     0,     3,     0,     2,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     0,     3,
       0,     0,     5,     0,     0,     5,     0,     0,     3,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       3,     0,     0,     5,     0,     0,     0,     4,     0,     3,
       0,     0,     4,     2,     1,     0,     5,     0,     1,     1,
       0,     3,     0,     0,     0,     0,    11,     0,     0,     0,
       8,     1,     1,     0,     1,     0,     1,     0,     0,     0,
       0,     0,     0,    14,     1,     1,     0,     4,     2,     0,
       0,     3,     0,     1,     0,     0,     0,     6,     1,     0,
       2,     2,     1,     1,     1,     1,     1,     0,     3,     0,
       3,     0,     4,     1,     0,     0,     0,     8,     0,     0,
       7,     1,     1,     0,     4,     2,     0,     0,     0,     4,
       1,     0,     3,     0,     0,     7,     0,     2,     1,     2,
       2,     0,     0,     3,     0,     3,     0,     0,     4,     0,
       4,     2,     0,     2,     0,     0,     0,     0,     0,    10,
       0,     3,     0
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
#line 1659 "y.tab.c"
    break;

  case 4:
#line 114 "c.y"
                        {
        backToParent();
    }
#line 1667 "y.tab.c"
    break;

  case 8:
#line 125 "c.y"
             { 
        extendOptTree("=");
    }
#line 1675 "y.tab.c"
    break;

  case 9:
#line 127 "c.y"
                     { 
        backToParent();
    }
#line 1683 "y.tab.c"
    break;

  case 13:
#line 138 "c.y"
         { 
        extendOptTree("||");
    }
#line 1691 "y.tab.c"
    break;

  case 14:
#line 140 "c.y"
                      {
        backToParent();
    }
#line 1699 "y.tab.c"
    break;

  case 18:
#line 151 "c.y"
          {  
        extendOptTree("&&");
    }
#line 1707 "y.tab.c"
    break;

  case 19:
#line 153 "c.y"
                      {
        backToParent();
    }
#line 1715 "y.tab.c"
    break;

  case 23:
#line 164 "c.y"
         {  
        extendOptTree("==");
    }
#line 1723 "y.tab.c"
    break;

  case 24:
#line 166 "c.y"
                     {
        backToParent();
    }
#line 1731 "y.tab.c"
    break;

  case 25:
#line 169 "c.y"
         {  
        extendOptTree("!=");
    }
#line 1739 "y.tab.c"
    break;

  case 26:
#line 171 "c.y"
                     {
        backToParent();
    }
#line 1747 "y.tab.c"
    break;

  case 29:
#line 182 "c.y"
         {  
        extendOptTree(">");
    }
#line 1755 "y.tab.c"
    break;

  case 30:
#line 184 "c.y"
                     {
        backToParent();
    }
#line 1763 "y.tab.c"
    break;

  case 31:
#line 187 "c.y"
         {  
        extendOptTree(">=");
    }
#line 1771 "y.tab.c"
    break;

  case 32:
#line 189 "c.y"
                     {
        backToParent();
    }
#line 1779 "y.tab.c"
    break;

  case 33:
#line 192 "c.y"
         {  
        extendOptTree("<");
    }
#line 1787 "y.tab.c"
    break;

  case 34:
#line 194 "c.y"
                     {
        backToParent();
    }
#line 1795 "y.tab.c"
    break;

  case 35:
#line 197 "c.y"
         {  
        extendOptTree("<=");
    }
#line 1803 "y.tab.c"
    break;

  case 36:
#line 199 "c.y"
                     {
        backToParent();
    }
#line 1811 "y.tab.c"
    break;

  case 38:
#line 206 "c.y"
                      {printf("pmh\n");}
#line 1817 "y.tab.c"
    break;

  case 40:
#line 210 "c.y"
           { 
        extendOptTree("+");
    }
#line 1825 "y.tab.c"
    break;

  case 41:
#line 212 "c.y"
                      {
        backToParent();
    }
#line 1833 "y.tab.c"
    break;

  case 43:
#line 215 "c.y"
            { 
        extendOptTree("-");
    }
#line 1841 "y.tab.c"
    break;

  case 44:
#line 217 "c.y"
                      {
        backToParent();
    }
#line 1849 "y.tab.c"
    break;

  case 47:
#line 224 "c.y"
                      {printf("mtdh\n");}
#line 1855 "y.tab.c"
    break;

  case 49:
#line 228 "c.y"
          { 
        extendOptTree("%");
    }
#line 1863 "y.tab.c"
    break;

  case 50:
#line 230 "c.y"
                      {
        backToParent();
    }
#line 1871 "y.tab.c"
    break;

  case 52:
#line 233 "c.y"
            { 
        extendOptTree("*");
    }
#line 1879 "y.tab.c"
    break;

  case 53:
#line 235 "c.y"
                      {
        backToParent();
    }
#line 1887 "y.tab.c"
    break;

  case 55:
#line 238 "c.y"
             { 
        extendOptTree("/");
    }
#line 1895 "y.tab.c"
    break;

  case 56:
#line 240 "c.y"
                      {
        backToParent();
    }
#line 1903 "y.tab.c"
    break;

  case 59:
#line 247 "c.y"
                      {printf("powh\n");}
#line 1909 "y.tab.c"
    break;

  case 61:
#line 251 "c.y"
          { 
        extendOptTree("^");
    }
#line 1917 "y.tab.c"
    break;

  case 62:
#line 253 "c.y"
                      {
        backToParent();
    }
#line 1925 "y.tab.c"
    break;

  case 65:
#line 260 "c.y"
      {
        saveNode();
    }
#line 1933 "y.tab.c"
    break;

  case 66:
#line 262 "c.y"
                     {printf("noth\n");}
#line 1939 "y.tab.c"
    break;

  case 67:
#line 262 "c.y"
                                                        {
        loadNode();
    }
#line 1947 "y.tab.c"
    break;

  case 68:
#line 268 "c.y"
          { 
        extendTree(NON_TERMINAL, "!", "expression");
    }
#line 1955 "y.tab.c"
    break;

  case 71:
#line 275 "c.y"
         { 
        extendTree(NON_TERMINAL, "()", "expression");
    }
#line 1963 "y.tab.c"
    break;

  case 72:
#line 277 "c.y"
                    { 
        backToParent();
    }
#line 1971 "y.tab.c"
    break;

  case 74:
#line 281 "c.y"
               { 
        extendTree(TERMINAL, (yyvsp[0].str), "const");
    }
#line 1979 "y.tab.c"
    break;

  case 75:
#line 287 "c.y"
                                           {
        extendOptTree("->");
        extendTerminal("IDENTIFIER", (yyvsp[-1].str));
        backToParent();
    }
#line 1989 "y.tab.c"
    break;

  case 78:
#line 296 "c.y"
          { 
        extendTerminal("int", "type");
    }
#line 1997 "y.tab.c"
    break;

  case 79:
#line 299 "c.y"
           { 
        extendTerminal("void", "type");
    }
#line 2005 "y.tab.c"
    break;

  case 80:
#line 302 "c.y"
             {
        extendTree(NON_TERMINAL, "struct", "type");
    }
#line 2013 "y.tab.c"
    break;

  case 81:
#line 304 "c.y"
                 {  
        extendTerminal((yyvsp[0].str), "identifier");
        backToParent();
    }
#line 2022 "y.tab.c"
    break;

  case 82:
#line 311 "c.y"
         { 
        /*establish local scope*/ ;
        saveNode();
        extendTree(NON_TERMINAL, "", "do while loop");
        extendTree(NON_TERMINAL, "do", "loop body");
        pushScope(1);
    }
#line 2034 "y.tab.c"
    break;

  case 83:
#line 317 "c.y"
                            {
        popScope();
        backToParent();
        extendTree(NON_TERMINAL, "while", "loop condition");
    }
#line 2044 "y.tab.c"
    break;

  case 84:
#line 321 "c.y"
         {  
        extendTree(NON_TERMINAL, "()", "expression");
    }
#line 2052 "y.tab.c"
    break;

  case 85:
#line 323 "c.y"
                    { 
        loadNode();
    }
#line 2060 "y.tab.c"
    break;

  case 87:
#line 329 "c.y"
            {  
        saveNode();
        extendTree(NON_TERMINAL, "while", "while loop");
    }
#line 2069 "y.tab.c"
    break;

  case 88:
#line 332 "c.y"
         { 
        extendTree(NON_TERMINAL, "()", "expression"); 
    }
#line 2077 "y.tab.c"
    break;

  case 89:
#line 334 "c.y"
                    { 
        backToParent(); 
        /*establish local scope*/ ;
        extendTree(NON_TERMINAL, "", "loop body");
        pushScope(1);
    }
#line 2088 "y.tab.c"
    break;

  case 90:
#line 339 "c.y"
                      {
        loadNode();
        popScope();
    }
#line 2097 "y.tab.c"
    break;

  case 98:
#line 388 "c.y"
          { 
        /*establish local scope*/ ;
        saveNode();
        extendTree(NON_TERMINAL, "for", "for loop");
        pushScope(1);
    }
#line 2108 "y.tab.c"
    break;

  case 99:
#line 393 "c.y"
         {  
        extendTree(NON_TERMINAL, "()", "for expression");
        extendTree(NON_TERMINAL, "", "for init expression");
    }
#line 2117 "y.tab.c"
    break;

  case 100:
#line 396 "c.y"
                                    {
        backToParent();
        extendTree(NON_TERMINAL, "", "for condition");
    }
#line 2126 "y.tab.c"
    break;

  case 101:
#line 399 "c.y"
                                         {
        backToParent();
        extendTree(NON_TERMINAL, "", "for action");
    }
#line 2135 "y.tab.c"
    break;

  case 102:
#line 402 "c.y"
                               {  
        backToParent();
        backToParent();
        extendTree(NON_TERMINAL, "", "loop body");
    }
#line 2145 "y.tab.c"
    break;

  case 103:
#line 406 "c.y"
                          {
        loadNode();
        popScope();
    }
#line 2154 "y.tab.c"
    break;

  case 106:
#line 418 "c.y"
          { 
        extendOptTree("[]"); 
    }
#line 2162 "y.tab.c"
    break;

  case 107:
#line 420 "c.y"
                     {
        backToParent();
    }
#line 2170 "y.tab.c"
    break;

  case 110:
#line 431 "c.y"
            {
        extendTree(NON_TERMINAL, "*", "pointer");
    }
#line 2178 "y.tab.c"
    break;

  case 113:
#line 438 "c.y"
              {
        extendTree(NON_TERMINAL, "&", "address");
    }
#line 2186 "y.tab.c"
    break;

  case 115:
#line 445 "c.y"
      {
        saveNode();
    }
#line 2194 "y.tab.c"
    break;

  case 116:
#line 447 "c.y"
                                                       {
        extendTerminal((yyvsp[0].str), "identifier");
    }
#line 2202 "y.tab.c"
    break;

  case 117:
#line 449 "c.y"
                        {
        loadNode();
    }
#line 2210 "y.tab.c"
    break;

  case 119:
#line 456 "c.y"
      { 
        pushScope(1); 
    }
#line 2218 "y.tab.c"
    break;

  case 120:
#line 458 "c.y"
                      {
        popScope();
    }
#line 2226 "y.tab.c"
    break;

  case 127:
#line 469 "c.y"
            {
        extendTerminal("break", "break");
    }
#line 2234 "y.tab.c"
    break;

  case 129:
#line 472 "c.y"
               {
        extendTerminal("continue", "continue");
    }
#line 2242 "y.tab.c"
    break;

  case 131:
#line 475 "c.y"
             {
        extendTree(NON_TERMINAL, "return", "return");
    }
#line 2250 "y.tab.c"
    break;

  case 132:
#line 477 "c.y"
                           {
        backToParent();
    }
#line 2258 "y.tab.c"
    break;

  case 134:
#line 481 "c.y"
            {
        extendTree(NON_TERMINAL, "print", "print");
    }
#line 2266 "y.tab.c"
    break;

  case 135:
#line 483 "c.y"
         {
        extendTree(NON_TERMINAL, "", "print_content");
    }
#line 2274 "y.tab.c"
    break;

  case 136:
#line 485 "c.y"
                       {
        backToParent();
        backToParent();
    }
#line 2283 "y.tab.c"
    break;

  case 138:
#line 489 "c.y"
            {
        extendTree(NON_TERMINAL, "input", "input");
    }
#line 2291 "y.tab.c"
    break;

  case 139:
#line 491 "c.y"
                                 {
        backToParent();
    }
#line 2299 "y.tab.c"
    break;

  case 142:
#line 498 "c.y"
               {
        extendTerminal((yyvsp[0].str), "string");
    }
#line 2307 "y.tab.c"
    break;

  case 143:
#line 504 "c.y"
          {
        extendTree(NON_TERMINAL, "{}", "statement body");
    }
#line 2315 "y.tab.c"
    break;

  case 144:
#line 506 "c.y"
                         {
        backToParent();
    }
#line 2323 "y.tab.c"
    break;

  case 146:
#line 513 "c.y"
      { printf("statement body over!\n"); }
#line 2329 "y.tab.c"
    break;

  case 147:
#line 517 "c.y"
      {
        extendTree(NON_TERMINAL, "", "declaration");
    }
#line 2337 "y.tab.c"
    break;

  case 148:
#line 519 "c.y"
                      {
        extendTree(NON_TERMINAL, "", "declaration body");
        saveNode();
    }
#line 2346 "y.tab.c"
    break;

  case 150:
#line 526 "c.y"
                           {
        extendTree(NON_TERMINAL, "", "function declaration");
        broToParent(-1);
        //connectParentChild();
    }
#line 2356 "y.tab.c"
    break;

  case 151:
#line 531 "c.y"
                                {
        extendTree(NON_TERMINAL, "", "argument declaration list");
        broToParent(-1);
        //connectParentChild();
    }
#line 2366 "y.tab.c"
    break;

  case 153:
#line 539 "c.y"
                         {
        extendTree(NON_TERMINAL, "()", "function argument list");
        pushScope(1);
    }
#line 2375 "y.tab.c"
    break;

  case 154:
#line 542 "c.y"
                                {
        backToParent();
        // establish local scope
    }
#line 2384 "y.tab.c"
    break;

  case 155:
#line 545 "c.y"
                          {
        popScope();
    }
#line 2392 "y.tab.c"
    break;

  case 156:
#line 551 "c.y"
      {
        extendTree(NON_TERMINAL, "", "function defination");
    }
#line 2400 "y.tab.c"
    break;

  case 157:
#line 553 "c.y"
                      {
        backToParent();
    }
#line 2408 "y.tab.c"
    break;

  case 162:
#line 569 "c.y"
                      {
        extendTree(NON_TERMINAL, "", "argument declaration unit");
        broToParent(1);
    }
#line 2417 "y.tab.c"
    break;

  case 163:
#line 572 "c.y"
                                {
        backToParent();
    }
#line 2425 "y.tab.c"
    break;

  case 164:
#line 578 "c.y"
             {
        extendOptTree("=");
    }
#line 2433 "y.tab.c"
    break;

  case 165:
#line 580 "c.y"
                        {
        backToParent();
    }
#line 2441 "y.tab.c"
    break;

  case 167:
#line 587 "c.y"
                                     {
        extendTerminal((yyvsp[0].str), "identifier");
    }
#line 2449 "y.tab.c"
    break;

  case 168:
#line 589 "c.y"
                        {
        loadNode();
    }
#line 2457 "y.tab.c"
    break;

  case 169:
#line 595 "c.y"
      {
        extendTree(NON_TERMINAL, "", "function argument unit");
        saveNode();
    }
#line 2466 "y.tab.c"
    break;

  case 170:
#line 598 "c.y"
                                                                {
        backToParent();
    }
#line 2474 "y.tab.c"
    break;

  case 175:
#line 614 "c.y"
         { 
        extendTree(NON_TERMINAL, "if", "if expression");
    }
#line 2482 "y.tab.c"
    break;

  case 176:
#line 616 "c.y"
         {
        extendTree(NON_TERMINAL, "()", "if condition");
    }
#line 2490 "y.tab.c"
    break;

  case 177:
#line 618 "c.y"
                    {
        backToParent();
        extendTree(NON_TERMINAL, "", "if statement");
        pushScope(1);
    }
#line 2500 "y.tab.c"
    break;

  case 178:
#line 622 "c.y"
                {
        popScope();
    }
#line 2508 "y.tab.c"
    break;

  case 180:
#line 628 "c.y"
           {
        extendTree(NON_TERMINAL, "else", "else statement");
        pushScope(1);
        popScope();
    }
#line 2518 "y.tab.c"
    break;

  case 182:
#line 633 "c.y"
      {}
#line 2524 "y.tab.c"
    break;


#line 2528 "y.tab.c"

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
#line 636 "c.y"



   
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
    /* printGrammerNode(parent);
    printGrammerNode(curNode); */
    for (int n = i; n < selfPos; n++) {
        /* printGrammerNode(parent->child[n]); */
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
