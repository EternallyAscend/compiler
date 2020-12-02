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
#include "childNode.h"
#include "y.tab.c"

extern "C" 

{
    void yyerror(const char *s);
    extern int yylex(void);
}




#line 87 "y.tab.c"

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
#line 20 "combine.y"

    char* symbolName;
    child child_label;

#line 231 "y.tab.c"

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
#define YYFINAL  83
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  137
/* YYNRULES -- Number of rules.  */
#define YYNRULES  187
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  279

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
       0,    86,    86,    86,    95,    98,    95,   104,   108,   108,
     112,   112,   113,   117,   121,   121,   122,   126,   130,   130,
     131,   131,   132,   136,   140,   140,   141,   141,   142,   142,
     143,   143,   144,   148,   152,   152,   153,   153,   154,   158,
     162,   162,   163,   163,   164,   164,   165,   169,   173,   173,
     174,   178,   182,   182,   183,   187,   187,   187,   188,   188,
     189,   189,   193,   193,   194,   198,   198,   199,   199,   200,
     200,   200,   204,   204,   204,   204,   204,   204,   204,   208,
     208,   208,   208,   208,   212,   213,   214,   218,   219,   223,
     223,   224,   228,   229,   233,   233,   234,   238,   238,   238,
     238,   238,   238,   238,   242,   242,   242,   246,   247,   251,
     251,   252,   256,   256,   257,   261,   261,   265,   265,   267,
     268,   269,   270,   271,   271,   272,   272,   273,   273,   273,
     274,   274,   274,   275,   275,   275,   276,   276,   277,   277,
     277,   277,   277,   278,   278,   278,   278,   278,   284,   285,
     285,   289,   289,   289,   293,   294,   298,   298,   298,   298,
     302,   302,   306,   310,   311,   315,   323,   327,   327,   328,
     332,   336,   336,   337,   341,   345,   346,   350,   350,   351,
     355,   355,   355,   355,   355,   359,   359,   360
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
  "BREAK", "RETURN", "STRUCT", "NONE_ELSE", "$accept", "expression", "@1",
  "assign_expression", "@2", "@3", "orh_expression", "@4", "or_expression",
  "$@5", "andh_expression", "and_expression", "$@6", "eneh_expression",
  "ene_expression", "$@7", "$@8", "lgh_expression", "lg_expression", "$@9",
  "$@10", "$@11", "$@12", "pmh_expression", "pm_expression", "$@13",
  "$@14", "mtdh_expression", "mtd_expression", "$@15", "$@16", "$@17",
  "powh_expression", "pow_expression", "$@18", "noth_expression",
  "not_expression", "$@19", "pid_expression", "$@20", "$@21", "$@22",
  "$@23", "pointer_expression", "$@24", "type_defination", "$@25", "$@26",
  "$@27", "$@28", "do_expression", "$@29", "$@30", "$@31", "$@32", "$@33",
  "$@34", "while_expression", "$@35", "$@36", "$@37", "$@38",
  "for_init_expression", "for_condition_expression",
  "for_more_condition_expression", "$@39", "for_action_expression",
  "for_more_action_expression", "$@40", "for_expression", "$@41", "$@42",
  "$@43", "$@44", "$@45", "$@46", "array_decorator", "$@47", "$@48",
  "high_ay_decorator", "high_nter_decorator", "$@49", "address_decorator",
  "$@50", "decorated_identifier", "$@51", "statement", "$@52", "$@53",
  "$@54", "$@55", "$@56", "$@57", "$@58", "$@59", "$@60", "$@61", "$@62",
  "$@63", "$@64", "$@65", "$@66", "$@67", "$@68", "$@69", "print_content",
  "$@70", "statement_block", "$@71", "$@72", "statement_body",
  "function_declaration", "$@73", "$@74", "$@75", "argument_declaration",
  "$@76", "declaration", "declaration_content", "declaration_name",
  "declaration_list", "declaration_list_tail", "$@77", "declaration_unit",
  "declaration_init", "$@78", "function_argument",
  "function_argument_list", "function_argument_tail", "$@79",
  "condition_expression", "$@80", "$@81", "$@82", "$@83", "condition_tail",
  "$@84", YY_NULLPTR
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

#define YYPACT_NINF (-224)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-156)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,   -32,  -224,  -224,
     -22,    47,    13,    71,    84,    -8,    -4,     5,  -224,  -224,
    -224,    21,    11,    31,    -1,    17,  -224,  -224,    34,    37,
      41,    14,  -224,  -224,  -224,    50,    59,  -224,  -224,    42,
      52,    14,    90,  -224,    88,    97,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,   126,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,   118,  -224,  -224,  -224,
     111,   127,  -224,  -224,   145,  -224,   151,  -224,  -224,    11,
     154,  -224,  -224,   128,  -224,  -224,  -224,  -224,  -224,  -224,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,  -224,  -224,   157,    73,  -224,   -14,
    -224,  -224,  -224,  -224,  -224,    65,     5,  -224,  -224,    14,
      14,   129,  -224,  -224,  -224,  -224,  -224,    14,    14,   -22,
      47,    47,    13,    13,    13,    13,    71,    71,    84,    84,
      84,    -8,    -4,   126,  -224,   152,   118,   132,   159,    14,
    -224,     5,  -224,  -224,   160,   161,    41,  -224,   162,   163,
    -224,    63,  -224,  -224,    97,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
     164,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,   165,   141,   142,  -224,    88,  -224,
    -224,   164,  -224,  -224,   -14,  -224,   143,   146,   115,  -224,
    -224,  -224,  -224,  -224,  -224,    14,  -224,  -224,    11,  -224,
    -224,   139,    11,    14,    14,    14,   169,  -224,  -224,  -224,
    -224,  -224,  -224,   173,   141,   141,   148,  -224,   115,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,   149,    14,  -224,   153,
     176,  -224,  -224,  -224,  -224,    14,    11,  -224,  -224
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     125,    60,   138,   143,    58,    55,    65,    67,   136,   180,
      79,    72,    97,   130,   127,   133,    69,     0,     2,     8,
      16,    22,    32,    38,    46,    50,    54,   114,   120,   121,
     119,   155,     0,     0,     0,   114,   122,    61,     0,     0,
      64,     0,    66,    68,   137,     0,     0,    73,    98,     0,
       0,     0,     0,   117,     7,    12,    14,    13,    18,    20,
      17,    24,    28,    26,    30,    23,    34,    36,    33,    42,
      44,    40,    39,    48,    47,    52,    51,   112,   111,   165,
     154,   151,   126,     1,   123,   156,   173,   163,   164,   162,
       0,   169,   139,   144,     0,    59,     0,   181,    80,     0,
       0,   131,   128,     0,    70,   118,     4,     3,    10,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,   109,     0,   125,   124,   176,
     171,   170,   160,   167,   166,     0,   114,    62,    56,     0,
       0,     0,    99,   132,   129,   134,    71,     0,     0,    16,
      22,    22,    32,    32,    32,    32,    38,    38,    46,    46,
      46,    50,    54,   111,   115,     0,   173,   179,     0,     0,
     161,   114,   149,   148,     0,     0,    64,    57,     0,     0,
      74,    86,   135,     5,    12,    15,    19,    21,    25,    29,
      27,    31,    35,    37,    43,    45,    41,    49,    53,   110,
     108,   152,   174,   177,   175,   157,   172,   168,   150,   140,
     145,    63,   182,    81,     0,    91,     0,    84,     7,    11,
     104,   108,   116,   153,   176,   158,     0,     0,   125,    82,
      75,    89,    85,   100,     6,     0,   107,   178,     0,   141,
     146,   187,     0,     0,     0,    88,     0,   159,   142,   147,
     185,   183,    83,     0,    91,    91,     0,   105,   125,   184,
      76,    90,    87,   101,   106,   186,     0,    93,    77,    96,
       0,    78,    94,    92,   102,     0,     0,    95,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -224,   -41,  -224,   -30,  -224,  -224,    39,  -224,     6,  -224,
      43,    40,  -224,    82,   -18,  -224,  -224,    23,   -70,  -224,
    -224,  -224,  -224,   -25,   -20,  -224,  -224,    25,   -34,  -224,
    -224,  -224,    10,    32,  -224,    74,    33,  -224,    75,  -224,
    -224,  -224,  -224,    24,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -116,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,   -24,
      36,  -224,  -224,  -224,   -26,  -224,  -223,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,   -97,  -224,  -224,
     -27,  -224,  -224,  -224,  -224,  -224,  -224,    20,  -224,  -123,
      35,  -224,  -224,  -224,    44,  -224,  -224,   -19,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    54,   107,   147,   218,    18,    55,   109,   148,
      19,    57,   110,    20,    60,   111,   112,    21,    65,   113,
     115,   114,   116,    22,    68,   117,   118,    23,    72,   121,
     119,   120,    24,    74,   122,    25,    76,   123,    26,    41,
     177,    40,    37,    95,   176,    27,    42,    43,    52,   146,
      28,    47,    99,   214,   243,   266,   271,    29,    46,   140,
     229,   242,   216,   256,   232,   244,   270,   273,   275,    30,
      48,   100,   181,   245,   267,   276,   221,   235,   264,   222,
     126,   163,    78,   124,    86,   200,    31,   105,   128,    32,
      50,   144,    49,   143,    51,   182,    44,    38,   135,   226,
     248,    39,   136,   227,   249,   174,   208,    82,   127,   223,
      33,    87,   129,   225,   238,    88,   170,    34,    89,    35,
      90,   134,   171,    91,   131,   169,   167,   168,   204,   224,
      36,    45,   139,   228,   259,   251,   258
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      96,    79,   141,    53,    80,   241,   166,    56,  -155,    73,
     103,     1,    75,     2,     3,     4,     5,     1,     6,     7,
      77,     4,     5,    81,     1,    85,     2,     3,     4,     5,
      16,    83,    77,  -125,    84,   265,    61,    62,    63,    64,
       6,     7,    92,     8,     9,    93,    10,    11,    12,    13,
      14,    15,    16,     6,     7,    94,     8,     9,    97,    10,
      11,    12,    13,    14,    15,    16,     1,    98,     1,   172,
       4,     5,     4,     5,    58,    59,     1,   101,     2,     3,
       4,     5,   188,   189,   190,   191,  -155,   102,   152,   153,
     154,   155,    66,    67,   173,     6,     7,   104,   178,   179,
     165,   166,    69,    70,    71,     6,     7,    16,     8,     9,
     175,    10,    11,    12,    13,    14,    15,    16,     1,   106,
       2,     3,     4,     5,   194,   195,   196,   108,   206,   158,
     159,   160,   186,   187,   150,   151,   192,   193,   261,   262,
     215,   247,   156,   157,   125,   252,   132,     6,     7,   130,
       8,     9,   137,    10,    11,    12,    13,    14,    15,    16,
     138,   133,   142,   145,   164,   201,   203,   180,   205,   209,
     210,   212,   213,   230,   220,   231,   250,   233,   239,   278,
     257,   240,   260,   263,   268,   274,   183,   272,   234,   185,
     219,   184,   149,   197,   246,   198,   161,   236,   162,   199,
     211,   217,   253,   254,   255,   237,   207,     0,     0,     0,
     202,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   269,     0,     0,     0,
       0,     0,     0,     0,   277
};

static const yytype_int16 yycheck[] =
{
      41,    27,    99,    35,    31,   228,   129,    29,     0,    17,
      51,     3,    16,     5,     6,     7,     8,     3,    32,    33,
      15,     7,     8,    12,     3,     8,     5,     6,     7,     8,
      44,     0,    15,    12,    35,   258,    23,    24,    25,    26,
      32,    33,     8,    35,    36,     8,    38,    39,    40,    41,
      42,    43,    44,    32,    33,    14,    35,    36,     8,    38,
      39,    40,    41,    42,    43,    44,     3,     8,     3,     4,
       7,     8,     7,     8,    27,    28,     3,    35,     5,     6,
       7,     8,   152,   153,   154,   155,    13,    35,   113,   114,
     115,   116,    21,    22,   135,    32,    33,     7,   139,   140,
     127,   224,    18,    19,    20,    32,    33,    44,    35,    36,
     136,    38,    39,    40,    41,    42,    43,    44,     3,    31,
       5,     6,     7,     8,   158,   159,   160,    30,   169,   119,
     120,   121,   150,   151,   111,   112,   156,   157,   254,   255,
     181,   238,   117,   118,    18,   242,    35,    32,    33,    31,
      35,    36,     7,    38,    39,    40,    41,    42,    43,    44,
       9,    34,     8,    35,     7,    13,    34,    38,     9,     9,
       9,     9,     9,     8,    10,    34,    37,    35,    35,   276,
      11,    35,     9,    35,    35,     9,   147,    34,   218,   149,
     184,   148,   110,   161,   235,   162,   122,   221,   123,   163,
     176,   181,   243,   244,   245,   224,   171,    -1,    -1,    -1,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   267,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,    32,    33,    35,    36,
      38,    39,    40,    41,    42,    43,    44,    47,    52,    56,
      59,    63,    69,    73,    78,    81,    84,    91,    96,   103,
     115,   132,   135,   156,   163,   165,   176,    88,   143,   147,
      87,    85,    92,    93,   142,   177,   104,    97,   116,   138,
     136,   140,    94,    35,    48,    53,    29,    57,    27,    28,
      60,    23,    24,    25,    26,    64,    21,    22,    70,    18,
      19,    20,    74,    17,    79,    16,    82,    15,   128,   130,
     156,    12,   153,     0,    35,     8,   130,   157,   161,   164,
     166,   169,     8,     8,    14,    89,    47,     8,     8,    98,
     117,    35,    35,    47,     7,   133,    31,    49,    30,    54,
      58,    61,    62,    65,    67,    66,    68,    71,    72,    76,
      77,    75,    80,    83,   129,    18,   126,   154,   134,   158,
      31,   170,    35,    34,   167,   144,   148,     7,     9,   178,
     105,   153,     8,   139,   137,    35,    95,    50,    55,    59,
      63,    63,    69,    69,    69,    69,    73,    73,    78,    78,
      78,    81,    84,   127,     7,   156,   165,   172,   173,   171,
     162,   168,     4,    47,   151,   130,    90,    86,    47,    47,
      38,   118,   141,    52,    56,    57,    60,    60,    64,    64,
      64,    64,    70,    70,    74,    74,    74,    79,    82,   126,
     131,    13,   170,    34,   174,     9,    47,   166,   152,     9,
       9,    89,     9,     9,    99,    47,   108,   163,    51,    54,
      10,   122,   125,   155,   175,   159,   145,   149,   179,   106,
       8,    34,   110,    35,    49,   123,   125,   173,   160,    35,
      35,   132,   107,   100,   111,   119,    47,   153,   146,   150,
      37,   181,   153,    47,    47,    47,   109,    11,   182,   180,
       9,   110,   110,    35,   124,   132,   101,   120,    35,    47,
     112,   102,    34,   113,     9,   114,   121,    47,   153
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    48,    47,    50,    51,    49,    49,    53,    52,
      55,    54,    54,    56,    58,    57,    57,    59,    61,    60,
      62,    60,    60,    63,    65,    64,    66,    64,    67,    64,
      68,    64,    64,    69,    71,    70,    72,    70,    70,    73,
      75,    74,    76,    74,    77,    74,    74,    78,    80,    79,
      79,    81,    83,    82,    82,    85,    86,    84,    87,    84,
      88,    84,    90,    89,    89,    92,    91,    93,    91,    94,
      95,    91,    97,    98,    99,   100,   101,   102,    96,   104,
     105,   106,   107,   103,   108,   108,   108,   109,   109,   111,
     110,   110,   112,   112,   114,   113,   113,   116,   117,   118,
     119,   120,   121,   115,   123,   124,   122,   125,   125,   127,
     126,   126,   129,   128,   128,   131,   130,   133,   132,   132,
     132,   132,   132,   134,   132,   135,   132,   136,   137,   132,
     138,   139,   132,   140,   141,   132,   142,   132,   143,   144,
     145,   146,   132,   147,   148,   149,   150,   132,   151,   152,
     151,   154,   155,   153,   156,   156,   158,   159,   160,   157,
     162,   161,   163,   164,   164,   165,   166,   168,   167,   167,
     169,   171,   170,   170,   172,   173,   173,   175,   174,   174,
     177,   178,   179,   180,   176,   182,   181,   181
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     0,     5,     0,     0,     3,
       0,     4,     0,     2,     0,     4,     0,     2,     0,     4,
       0,     4,     0,     2,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     2,     0,     4,     0,     4,     0,     2,
       0,     4,     0,     4,     0,     4,     0,     2,     0,     4,
       0,     2,     0,     4,     0,     0,     0,     5,     0,     3,
       0,     2,     0,     4,     0,     0,     2,     0,     2,     0,
       0,     4,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     9,     1,     2,     0,     2,     0,     0,
       4,     0,     2,     0,     0,     3,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,     5,     2,     0,     0,
       3,     0,     0,     2,     0,     0,     5,     0,     3,     1,
       1,     1,     1,     0,     3,     0,     2,     0,     0,     4,
       0,     0,     4,     0,     0,     5,     0,     2,     0,     0,
       0,     0,     9,     0,     0,     0,     0,     9,     1,     0,
       2,     0,     0,     5,     2,     0,     0,     0,     0,     7,
       0,     3,     2,     1,     1,     2,     2,     0,     3,     0,
       2,     0,     3,     0,     2,     2,     0,     0,     3,     0,
       0,     0,     0,     0,    10,     0,     3,     0
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
#line 86 "combine.y"
                     { 
        push_child(word_pos - 1, &((yyval.child_label))); 
      }
#line 1641 "y.tab.c"
    break;

  case 3:
#line 88 "combine.y"
                          { 
        push_child(word_pos - 1, &((yyval.child_label).child_label)); 
        print_non_terminal_symbol(word_pos++, "expression"); 
      }
#line 1650 "y.tab.c"
    break;

  case 4:
#line 95 "combine.y"
             { 
        print_terminal_symbol(word_pos++, );
        push_child(word_pos - 1, &((yyval.child_label)));
      }
#line 1659 "y.tab.c"
    break;

  case 5:
#line 98 "combine.y"
                       { 
        push_child(word_pos - 1, &((yyval.child_label))); 
      }
#line 1667 "y.tab.c"
    break;

  case 6:
#line 100 "combine.y"
                          { 
        push_child(word_pos - 1, &((yyval.child_label))); 
        print_non_terminal_symbol(word_pos++, "assign_expression", &((yyval.child_label))); 
      }
#line 1676 "y.tab.c"
    break;

  case 8:
#line 108 "combine.y"
                      { push_child(word_pos - 1, &((yyval.child_label))); }
#line 1682 "y.tab.c"
    break;

  case 9:
#line 108 "combine.y"
                                                                                      { push_child(word_pos - 1, &((yyval.child_label))); print_non_terminal_symbol(word_pos++, "orh_expression"); }
#line 1688 "y.tab.c"
    break;

  case 10:
#line 112 "combine.y"
         { print_terminal_symbol(word_pos++, ); }
#line 1694 "y.tab.c"
    break;

  case 11:
#line 112 "combine.y"
                                                                                { push_child(word_pos - 1, &((yyval.child_label))); print_non_terminal_symbol(word_pos++, "or_expression"); }
#line 1700 "y.tab.c"
    break;

  case 13:
#line 117 "combine.y"
                                     { print_non_terminal_symbol(word_pos++, "andh_expression"); }
#line 1706 "y.tab.c"
    break;

  case 14:
#line 121 "combine.y"
          { print_terminal_symbol(word_pos++, ); }
#line 1712 "y.tab.c"
    break;

  case 15:
#line 121 "combine.y"
                                                                                  { print_non_terminal_symbol(word_pos++, "and_expression"); }
#line 1718 "y.tab.c"
    break;

  case 17:
#line 126 "combine.y"
                                    { print_non_terminal_symbol(word_pos++, "eneh_expression"); }
#line 1724 "y.tab.c"
    break;

  case 18:
#line 130 "combine.y"
         { print_terminal_symbol(word_pos++, ); }
#line 1730 "y.tab.c"
    break;

  case 19:
#line 130 "combine.y"
                                                                                { print_non_terminal_symbol(word_pos++, "ene_expression"); }
#line 1736 "y.tab.c"
    break;

  case 20:
#line 131 "combine.y"
         { print_terminal_symbol(word_pos++, ); }
#line 1742 "y.tab.c"
    break;

  case 21:
#line 131 "combine.y"
                                                                                { print_non_terminal_symbol(word_pos++, "ene_expression"); }
#line 1748 "y.tab.c"
    break;

  case 23:
#line 136 "combine.y"
                                   { print_non_terminal_symbol(word_pos++, "lgh_expression"); }
#line 1754 "y.tab.c"
    break;

  case 24:
#line 140 "combine.y"
         { print_terminal_symbol(word_pos++, ); }
#line 1760 "y.tab.c"
    break;

  case 25:
#line 140 "combine.y"
                                                                               { print_non_terminal_symbol(word_pos++, "lg_expression"); }
#line 1766 "y.tab.c"
    break;

  case 26:
#line 141 "combine.y"
         { print_terminal_symbol(word_pos++, ); }
#line 1772 "y.tab.c"
    break;

  case 27:
#line 141 "combine.y"
                                                                               { print_non_terminal_symbol(word_pos++, "lg_expression"); }
#line 1778 "y.tab.c"
    break;

  case 28:
#line 142 "combine.y"
         { print_terminal_symbol(word_pos++, ); }
#line 1784 "y.tab.c"
    break;

  case 29:
#line 142 "combine.y"
                                                                               { print_non_terminal_symbol(word_pos++, "lg_expression"); }
#line 1790 "y.tab.c"
    break;

  case 30:
#line 143 "combine.y"
         { print_terminal_symbol(word_pos++, ); }
#line 1796 "y.tab.c"
    break;

  case 31:
#line 143 "combine.y"
                                                                               { print_non_terminal_symbol(word_pos++, "lg_expression"); }
#line 1802 "y.tab.c"
    break;

  case 33:
#line 148 "combine.y"
                                    { print_non_terminal_symbol(word_pos++, "pmh_expression"); }
#line 1808 "y.tab.c"
    break;

  case 34:
#line 152 "combine.y"
           { print_terminal_symbol(word_pos++, ); }
#line 1814 "y.tab.c"
    break;

  case 35:
#line 152 "combine.y"
                                                                                  { print_non_terminal_symbol(word_pos++, "pm_expression"); }
#line 1820 "y.tab.c"
    break;

  case 36:
#line 153 "combine.y"
            { print_terminal_symbol(word_pos++, ); }
#line 1826 "y.tab.c"
    break;

  case 37:
#line 153 "combine.y"
                                                                                   { print_non_terminal_symbol(word_pos++, "pm_expression"); }
#line 1832 "y.tab.c"
    break;

  case 39:
#line 158 "combine.y"
                                     { print_non_terminal_symbol(word_pos++, "mtdh_expression"); }
#line 1838 "y.tab.c"
    break;

  case 40:
#line 162 "combine.y"
          { print_terminal_symbol(word_pos++, ); }
#line 1844 "y.tab.c"
    break;

  case 41:
#line 162 "combine.y"
                                                                                  { print_non_terminal_symbol(word_pos++, "mtd_expression"); }
#line 1850 "y.tab.c"
    break;

  case 42:
#line 163 "combine.y"
            { print_terminal_symbol(word_pos++, ); }
#line 1856 "y.tab.c"
    break;

  case 43:
#line 163 "combine.y"
                                                                                    { print_non_terminal_symbol(word_pos++, "mtd_expression"); }
#line 1862 "y.tab.c"
    break;

  case 44:
#line 164 "combine.y"
             { print_terminal_symbol(word_pos++, ); }
#line 1868 "y.tab.c"
    break;

  case 45:
#line 164 "combine.y"
                                                                                     { print_non_terminal_symbol(word_pos++, "mtd_expression"); }
#line 1874 "y.tab.c"
    break;

  case 47:
#line 169 "combine.y"
                                     { print_non_terminal_symbol(word_pos++, "powh_expression"); }
#line 1880 "y.tab.c"
    break;

  case 48:
#line 173 "combine.y"
          { print_terminal_symbol(word_pos++, ); }
#line 1886 "y.tab.c"
    break;

  case 49:
#line 173 "combine.y"
                                                                                  { print_non_terminal_symbol(word_pos++, "pow_expression"); }
#line 1892 "y.tab.c"
    break;

  case 51:
#line 178 "combine.y"
                                    { print_non_terminal_symbol(word_pos++, "noth_expression"); }
#line 1898 "y.tab.c"
    break;

  case 52:
#line 182 "combine.y"
          { print_terminal_symbol(word_pos++, ); }
#line 1904 "y.tab.c"
    break;

  case 53:
#line 182 "combine.y"
                                                                                 { print_non_terminal_symbol(word_pos++, "noth_expression"); }
#line 1910 "y.tab.c"
    break;

  case 55:
#line 187 "combine.y"
         { print_terminal_symbol(word_pos++, ); }
#line 1916 "y.tab.c"
    break;

  case 56:
#line 187 "combine.y"
                                                                { print_terminal_symbol(word_pos++, ); }
#line 1922 "y.tab.c"
    break;

  case 57:
#line 187 "combine.y"
                                                                                                         { print_non_terminal_symbol(word_pos++, "pid_expression"); }
#line 1928 "y.tab.c"
    break;

  case 58:
#line 188 "combine.y"
                 { print_terminal_symbol(word_pos++, ); }
#line 1934 "y.tab.c"
    break;

  case 59:
#line 188 "combine.y"
                                                                             { print_non_terminal_symbol(word_pos++, "pid_expression"); }
#line 1940 "y.tab.c"
    break;

  case 60:
#line 189 "combine.y"
               { print_terminal_symbol(word_pos++, ); }
#line 1946 "y.tab.c"
    break;

  case 61:
#line 189 "combine.y"
                                                        { print_non_terminal_symbol(word_pos++, "pid_expression"); }
#line 1952 "y.tab.c"
    break;

  case 62:
#line 193 "combine.y"
                         { print_terminal_symbol(word_pos++, ); }
#line 1958 "y.tab.c"
    break;

  case 63:
#line 193 "combine.y"
                                                                                     { print_non_terminal_symbol(word_pos++, "pointer_expression"); }
#line 1964 "y.tab.c"
    break;

  case 65:
#line 198 "combine.y"
          { print_terminal_symbol(word_pos++, ); }
#line 1970 "y.tab.c"
    break;

  case 66:
#line 198 "combine.y"
                                                   { print_non_terminal_symbol(word_pos++, "pointer_expression"); }
#line 1976 "y.tab.c"
    break;

  case 67:
#line 199 "combine.y"
           { print_terminal_symbol(word_pos++, ); }
#line 1982 "y.tab.c"
    break;

  case 68:
#line 199 "combine.y"
                                                    { print_non_terminal_symbol(word_pos++, "pointer_expression"); }
#line 1988 "y.tab.c"
    break;

  case 69:
#line 200 "combine.y"
             { print_terminal_symbol(word_pos++, ); }
#line 1994 "y.tab.c"
    break;

  case 70:
#line 200 "combine.y"
                                                                 { print_terminal_symbol(word_pos++, ); }
#line 2000 "y.tab.c"
    break;

  case 71:
#line 200 "combine.y"
                                                                                                          { print_non_terminal_symbol(word_pos++, "pointer_expression"); }
#line 2006 "y.tab.c"
    break;

  case 72:
#line 204 "combine.y"
         { print_terminal_symbol(word_pos++, ); }
#line 2012 "y.tab.c"
    break;

  case 73:
#line 204 "combine.y"
                                                  { /*establish local scope*/ ;}
#line 2018 "y.tab.c"
    break;

  case 74:
#line 204 "combine.y"
                                                                                                       { print_terminal_symbol(word_pos++, ); }
#line 2024 "y.tab.c"
    break;

  case 75:
#line 204 "combine.y"
                                                                                                                                                   { print_terminal_symbol(word_pos++, ); }
#line 2030 "y.tab.c"
    break;

  case 76:
#line 204 "combine.y"
                                                                                                                                                                                                          { print_terminal_symbol(word_pos++, ); }
#line 2036 "y.tab.c"
    break;

  case 77:
#line 204 "combine.y"
                                                                                                                                                                                                                                                             { print_terminal_symbol(word_pos++, ); }
#line 2042 "y.tab.c"
    break;

  case 78:
#line 204 "combine.y"
                                                                                                                                                                                                                                                                                                      { print_non_terminal_symbol(word_pos++, "do_expression"); }
#line 2048 "y.tab.c"
    break;

  case 79:
#line 208 "combine.y"
            { print_terminal_symbol(word_pos++, ); }
#line 2054 "y.tab.c"
    break;

  case 80:
#line 208 "combine.y"
                                                        { print_terminal_symbol(word_pos++, ); }
#line 2060 "y.tab.c"
    break;

  case 81:
#line 208 "combine.y"
                                                                                                               { print_terminal_symbol(word_pos++, ); }
#line 2066 "y.tab.c"
    break;

  case 82:
#line 208 "combine.y"
                                                                                                                                                        { /*establish local scope*/ ;}
#line 2072 "y.tab.c"
    break;

  case 83:
#line 208 "combine.y"
                                                                                                                                                                                                       { print_non_terminal_symbol(word_pos++, "while_expression"); }
#line 2078 "y.tab.c"
    break;

  case 84:
#line 212 "combine.y"
                  { print_non_terminal_symbol(word_pos++, "for_init_expression"); }
#line 2084 "y.tab.c"
    break;

  case 85:
#line 213 "combine.y"
                                               { print_non_terminal_symbol(word_pos++, "for_init_expression"); }
#line 2090 "y.tab.c"
    break;

  case 87:
#line 218 "combine.y"
                                               { print_non_terminal_symbol(word_pos++, "for_condition_expression"); }
#line 2096 "y.tab.c"
    break;

  case 89:
#line 223 "combine.y"
            { print_terminal_symbol(word_pos++, ); }
#line 2102 "y.tab.c"
    break;

  case 90:
#line 223 "combine.y"
                                                                                              { print_non_terminal_symbol(word_pos++, "for_condition_expression"); }
#line 2108 "y.tab.c"
    break;

  case 92:
#line 228 "combine.y"
                                            { print_non_terminal_symbol(word_pos++, "for_action_expression"); }
#line 2114 "y.tab.c"
    break;

  case 94:
#line 233 "combine.y"
            { print_terminal_symbol(word_pos++, ); }
#line 2120 "y.tab.c"
    break;

  case 95:
#line 233 "combine.y"
                                                                { print_non_terminal_symbol(word_pos++, "for_action_expression"); }
#line 2126 "y.tab.c"
    break;

  case 97:
#line 238 "combine.y"
          { print_terminal_symbol(word_pos++, ); }
#line 2132 "y.tab.c"
    break;

  case 98:
#line 238 "combine.y"
                                                   { /*establish local scope*/ ;}
#line 2138 "y.tab.c"
    break;

  case 99:
#line 238 "combine.y"
                                                                                     { print_terminal_symbol(word_pos++, ); }
#line 2144 "y.tab.c"
    break;

  case 100:
#line 238 "combine.y"
                                                                                                                                                            { print_terminal_symbol(word_pos++, ); }
#line 2150 "y.tab.c"
    break;

  case 101:
#line 238 "combine.y"
                                                                                                                                                                                                                                        { print_terminal_symbol(word_pos++, ); }
#line 2156 "y.tab.c"
    break;

  case 102:
#line 238 "combine.y"
                                                                                                                                                                                                                                                                                                          { print_terminal_symbol(word_pos++, ); }
#line 2162 "y.tab.c"
    break;

  case 103:
#line 238 "combine.y"
                                                                                                                                                                                                                                                                                                                                                                   { print_non_terminal_symbol(word_pos++, "for_expression"); }
#line 2168 "y.tab.c"
    break;

  case 104:
#line 242 "combine.y"
          { print_terminal_symbol(word_pos++, ); }
#line 2174 "y.tab.c"
    break;

  case 105:
#line 242 "combine.y"
                                                                  { print_terminal_symbol(word_pos++, ); }
#line 2180 "y.tab.c"
    break;

  case 106:
#line 242 "combine.y"
                                                                                                           { print_non_terminal_symbol(word_pos++, "array_decorator"); }
#line 2186 "y.tab.c"
    break;

  case 107:
#line 246 "combine.y"
                                        { print_non_terminal_symbol(word_pos++, "high_ay_decorator"); }
#line 2192 "y.tab.c"
    break;

  case 109:
#line 251 "combine.y"
            { print_terminal_symbol(word_pos++, ); }
#line 2198 "y.tab.c"
    break;

  case 110:
#line 251 "combine.y"
                                                                         { print_non_terminal_symbol(word_pos++, "high_nter_decorator"); }
#line 2204 "y.tab.c"
    break;

  case 112:
#line 256 "combine.y"
              { print_terminal_symbol(word_pos++, ); }
#line 2210 "y.tab.c"
    break;

  case 113:
#line 256 "combine.y"
                                                       { print_non_terminal_symbol(word_pos++, "address_decorator"); }
#line 2216 "y.tab.c"
    break;

  case 115:
#line 261 "combine.y"
                                                       { print_terminal_symbol(word_pos++, ); }
#line 2222 "y.tab.c"
    break;

  case 116:
#line 261 "combine.y"
                                                                                                                  { print_non_terminal_symbol(word_pos++, "decorated_identifier"); }
#line 2228 "y.tab.c"
    break;

  case 117:
#line 265 "combine.y"
                           { print_terminal_symbol(word_pos++, ); }
#line 2234 "y.tab.c"
    break;

  case 118:
#line 265 "combine.y"
                                                                    { print_non_terminal_symbol(word_pos++, "statement"); }
#line 2240 "y.tab.c"
    break;

  case 119:
#line 267 "combine.y"
                     { print_non_terminal_symbol(word_pos++, "statement"); }
#line 2246 "y.tab.c"
    break;

  case 120:
#line 268 "combine.y"
                    { print_non_terminal_symbol(word_pos++, "statement"); }
#line 2252 "y.tab.c"
    break;

  case 121:
#line 269 "combine.y"
                       { print_non_terminal_symbol(word_pos++, "statement"); }
#line 2258 "y.tab.c"
    break;

  case 122:
#line 270 "combine.y"
                           { print_non_terminal_symbol(word_pos++, "statement"); }
#line 2264 "y.tab.c"
    break;

  case 123:
#line 271 "combine.y"
                            { print_terminal_symbol(word_pos++, ); }
#line 2270 "y.tab.c"
    break;

  case 124:
#line 271 "combine.y"
                                                                     { print_non_terminal_symbol(word_pos++, "statement"); }
#line 2276 "y.tab.c"
    break;

  case 125:
#line 272 "combine.y"
      { /*establish local scope*/ ; }
#line 2282 "y.tab.c"
    break;

  case 126:
#line 272 "combine.y"
                                                     { print_non_terminal_symbol(word_pos++, "statement"); }
#line 2288 "y.tab.c"
    break;

  case 127:
#line 273 "combine.y"
            { print_terminal_symbol(word_pos++, ); }
#line 2294 "y.tab.c"
    break;

  case 128:
#line 273 "combine.y"
                                                               { print_terminal_symbol(word_pos++, ); }
#line 2300 "y.tab.c"
    break;

  case 129:
#line 273 "combine.y"
                                                                                                        { print_non_terminal_symbol(word_pos++, "statement"); }
#line 2306 "y.tab.c"
    break;

  case 130:
#line 274 "combine.y"
               { print_terminal_symbol(word_pos++, ); }
#line 2312 "y.tab.c"
    break;

  case 131:
#line 274 "combine.y"
                                                                  { print_terminal_symbol(word_pos++, ); }
#line 2318 "y.tab.c"
    break;

  case 132:
#line 274 "combine.y"
                                                                                                           { print_non_terminal_symbol(word_pos++, "statement"); }
#line 2324 "y.tab.c"
    break;

  case 133:
#line 275 "combine.y"
             { print_terminal_symbol(word_pos++, ); }
#line 2330 "y.tab.c"
    break;

  case 134:
#line 275 "combine.y"
                                                                           { print_terminal_symbol(word_pos++, ); }
#line 2336 "y.tab.c"
    break;

  case 135:
#line 275 "combine.y"
                                                                                                                    { print_non_terminal_symbol(word_pos++, "statement"); }
#line 2342 "y.tab.c"
    break;

  case 136:
#line 276 "combine.y"
                { print_terminal_symbol(word_pos++, ); }
#line 2348 "y.tab.c"
    break;

  case 137:
#line 276 "combine.y"
                                                         { print_non_terminal_symbol(word_pos++, ""); }
#line 2354 "y.tab.c"
    break;

  case 138:
#line 277 "combine.y"
            { print_terminal_symbol(word_pos++, ); }
#line 2360 "y.tab.c"
    break;

  case 139:
#line 277 "combine.y"
                                                        { print_terminal_symbol(word_pos++, ); }
#line 2366 "y.tab.c"
    break;

  case 140:
#line 277 "combine.y"
                                                                                                                  { print_terminal_symbol(word_pos++, ); }
#line 2372 "y.tab.c"
    break;

  case 141:
#line 277 "combine.y"
                                                                                                                                                                     { print_terminal_symbol(word_pos++, ); }
#line 2378 "y.tab.c"
    break;

  case 142:
#line 277 "combine.y"
                                                                                                                                                                                                              { print_non_terminal_symbol(word_pos++, "statement"); }
#line 2384 "y.tab.c"
    break;

  case 143:
#line 278 "combine.y"
            { print_terminal_symbol(word_pos++, ); }
#line 2390 "y.tab.c"
    break;

  case 144:
#line 278 "combine.y"
                                                        { print_terminal_symbol(word_pos++, ); }
#line 2396 "y.tab.c"
    break;

  case 145:
#line 278 "combine.y"
                                                                                                                         { print_terminal_symbol(word_pos++, ); }
#line 2402 "y.tab.c"
    break;

  case 146:
#line 278 "combine.y"
                                                                                                                                                                            { print_terminal_symbol(word_pos++, ); }
#line 2408 "y.tab.c"
    break;

  case 147:
#line 278 "combine.y"
                                                                                                                                                                                                                     { print_non_terminal_symbol(word_pos++, "statement"); }
#line 2414 "y.tab.c"
    break;

  case 148:
#line 284 "combine.y"
                 { print_non_terminal_symbol(word_pos++, "print_content"); }
#line 2420 "y.tab.c"
    break;

  case 149:
#line 285 "combine.y"
               { print_terminal_symbol(word_pos++, ); }
#line 2426 "y.tab.c"
    break;

  case 150:
#line 285 "combine.y"
                                                        { print_non_terminal_symbol(word_pos++, "print_content"); }
#line 2432 "y.tab.c"
    break;

  case 151:
#line 289 "combine.y"
          { print_terminal_symbol(word_pos++, ); }
#line 2438 "y.tab.c"
    break;

  case 152:
#line 289 "combine.y"
                                                                      { print_terminal_symbol(word_pos++, ); }
#line 2444 "y.tab.c"
    break;

  case 153:
#line 289 "combine.y"
                                                                                                               { print_non_terminal_symbol(word_pos++, "statement_block"); }
#line 2450 "y.tab.c"
    break;

  case 154:
#line 293 "combine.y"
                               { print_non_terminal_symbol(word_pos++, "statement_body"); }
#line 2456 "y.tab.c"
    break;

  case 156:
#line 298 "combine.y"
         { print_terminal_symbol(word_pos++, ); }
#line 2462 "y.tab.c"
    break;

  case 157:
#line 298 "combine.y"
                                                                            { print_terminal_symbol(word_pos++, ); }
#line 2468 "y.tab.c"
    break;

  case 158:
#line 298 "combine.y"
                                                                                                                     { /*establish local scope*/ ;}
#line 2474 "y.tab.c"
    break;

  case 159:
#line 298 "combine.y"
                                                                                                                                                                    { print_non_terminal_symbol(word_pos++, "function_declaration"); }
#line 2480 "y.tab.c"
    break;

  case 160:
#line 302 "combine.y"
                                 { print_terminal_symbol(word_pos++, ); }
#line 2486 "y.tab.c"
    break;

  case 161:
#line 302 "combine.y"
                                                                          { print_non_terminal_symbol(word_pos++, "argument_declaration"); }
#line 2492 "y.tab.c"
    break;

  case 162:
#line 306 "combine.y"
                                           { print_non_terminal_symbol(word_pos++, "declaration"); }
#line 2498 "y.tab.c"
    break;

  case 163:
#line 310 "combine.y"
                           { print_non_terminal_symbol(word_pos++, "declaration_content"); }
#line 2504 "y.tab.c"
    break;

  case 164:
#line 311 "combine.y"
                           { print_non_terminal_symbol(word_pos++, "declaration_content"); }
#line 2510 "y.tab.c"
    break;

  case 165:
#line 315 "combine.y"
                                           { print_non_terminal_symbol(word_pos++, "declaration_name"); }
#line 2516 "y.tab.c"
    break;

  case 166:
#line 323 "combine.y"
                                             { print_non_terminal_symbol(word_pos++, "declaration_list"); }
#line 2522 "y.tab.c"
    break;

  case 167:
#line 327 "combine.y"
            { print_terminal_symbol(word_pos++, ); }
#line 2528 "y.tab.c"
    break;

  case 170:
#line 332 "combine.y"
                                            { print_non_terminal_symbol(word_pos++, "declaration_unit"); }
#line 2534 "y.tab.c"
    break;

  case 171:
#line 336 "combine.y"
             { print_terminal_symbol(word_pos++, ); }
#line 2540 "y.tab.c"
    break;

  case 172:
#line 336 "combine.y"
                                                                 { print_non_terminal_symbol(word_pos++, "declaration_init"); }
#line 2546 "y.tab.c"
    break;

  case 174:
#line 341 "combine.y"
                                       { print_non_terminal_symbol(word_pos++, "function_argument"); }
#line 2552 "y.tab.c"
    break;

  case 175:
#line 345 "combine.y"
                                               { print_non_terminal_symbol(word_pos++, "function_argument_list"); }
#line 2558 "y.tab.c"
    break;

  case 177:
#line 350 "combine.y"
            { print_terminal_symbol(word_pos++, ); }
#line 2564 "y.tab.c"
    break;

  case 180:
#line 355 "combine.y"
         { print_terminal_symbol(word_pos++, ); }
#line 2570 "y.tab.c"
    break;

  case 181:
#line 355 "combine.y"
                                                     { print_terminal_symbol(word_pos++, ); }
#line 2576 "y.tab.c"
    break;

  case 182:
#line 355 "combine.y"
                                                                                                            { print_terminal_symbol(word_pos++, ); }
#line 2582 "y.tab.c"
    break;

  case 183:
#line 355 "combine.y"
                                                                                                                                                                              { print_non_terminal_symbol(word_pos++, "condition_tail"); }
#line 2588 "y.tab.c"
    break;

  case 184:
#line 355 "combine.y"
                                                                                                                                                                                                                                           { print_non_terminal_symbol(word_pos++, "condition_expression"); }
#line 2594 "y.tab.c"
    break;

  case 185:
#line 359 "combine.y"
           { print_terminal_symbol(word_pos++, ); }
#line 2600 "y.tab.c"
    break;

  case 187:
#line 360 "combine.y"
      {}
#line 2606 "y.tab.c"
    break;


#line 2610 "y.tab.c"

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
#line 363 "combine.y"


%{
    void print_non_terminal_symbol(int word_pos, const char* sentence, child* childSymbol){
        printf(sentence);
        printf(":%d", word_pos);
        printf("/t/tchild:");
        for (int i = 0; i < childSymbol)
    }

    void print_terminal_symbol(){

    }

    int main(void)  { 
        int word_pos = 0;
        yyparse(); 
        return 0; 
        // grammerItem grammerHead
        // grammerItem* grammerStackTail;
        // int size = 0;
    }   
%}
