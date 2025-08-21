/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "syd.y"


#include "defs.h" 

int error_count=0;

void yyerror(const char *s);
int yyparse();
int yylex();

extern int currLine;
extern int currCol;
extern char *yytext;

#define DEBUG 0

static symbol *new_num_symbol(int value);



#line 92 "syd.tab.c"

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

#include "syd.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_RETURN = 3,                     /* RETURN  */
  YYSYMBOL_BREAK = 4,                      /* BREAK  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_TRUE = 9,                       /* TRUE  */
  YYSYMBOL_FALSE = 10,                     /* FALSE  */
  YYSYMBOL_GT = 11,                        /* GT  */
  YYSYMBOL_LT = 12,                        /* LT  */
  YYSYMBOL_GE = 13,                        /* GE  */
  YYSYMBOL_LE = 14,                        /* LE  */
  YYSYMBOL_EQ = 15,                        /* EQ  */
  YYSYMBOL_NE = 16,                        /* NE  */
  YYSYMBOL_ID = 17,                        /* ID  */
  YYSYMBOL_NUM = 18,                       /* NUM  */
  YYSYMBOL_19_ = 19,                       /* ';'  */
  YYSYMBOL_20_ = 20,                       /* '('  */
  YYSYMBOL_21_ = 21,                       /* ')'  */
  YYSYMBOL_22_ = 22,                       /* ','  */
  YYSYMBOL_23_ = 23,                       /* '{'  */
  YYSYMBOL_24_ = 24,                       /* '}'  */
  YYSYMBOL_25_ = 25,                       /* '='  */
  YYSYMBOL_26_ = 26,                       /* '+'  */
  YYSYMBOL_27_ = 27,                       /* '-'  */
  YYSYMBOL_28_ = 28,                       /* '*'  */
  YYSYMBOL_29_ = 29,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_PROGRAM = 31,                   /* PROGRAM  */
  YYSYMBOL_METH_LIST = 32,                 /* METH_LIST  */
  YYSYMBOL_METH = 33,                      /* METH  */
  YYSYMBOL_34_1 = 34,                      /* $@1  */
  YYSYMBOL_35_2 = 35,                      /* $@2  */
  YYSYMBOL_PARAMS = 36,                    /* PARAMS  */
  YYSYMBOL_FORMALS = 37,                   /* FORMALS  */
  YYSYMBOL_TYPE = 38,                      /* TYPE  */
  YYSYMBOL_BODY = 39,                      /* BODY  */
  YYSYMBOL_DECLS = 40,                     /* DECLS  */
  YYSYMBOL_DECL_LIST = 41,                 /* DECL_LIST  */
  YYSYMBOL_DECL = 42,                      /* DECL  */
  YYSYMBOL_VARS = 43,                      /* VARS  */
  YYSYMBOL_STMTS = 44,                     /* STMTS  */
  YYSYMBOL_STMT = 45,                      /* STMT  */
  YYSYMBOL_46_3 = 46,                      /* $@3  */
  YYSYMBOL_BLOCK = 47,                     /* BLOCK  */
  YYSYMBOL_ASSIGN = 48,                    /* ASSIGN  */
  YYSYMBOL_LOCATION = 49,                  /* LOCATION  */
  YYSYMBOL_METHOD = 50,                    /* METHOD  */
  YYSYMBOL_EXPR = 51,                      /* EXPR  */
  YYSYMBOL_RELOP = 52,                     /* RELOP  */
  YYSYMBOL_ADD_EXPR = 53,                  /* ADD_EXPR  */
  YYSYMBOL_ADDOP = 54,                     /* ADDOP  */
  YYSYMBOL_TERM = 55,                      /* TERM  */
  YYSYMBOL_MULOP = 56,                     /* MULOP  */
  YYSYMBOL_FACTOR = 57,                    /* FACTOR  */
  YYSYMBOL_ACTUALS = 58,                   /* ACTUALS  */
  YYSYMBOL_ARGS = 59                       /* ARGS  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   273


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      20,    21,    28,    26,    22,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    19,
       2,    25,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,    24,     2,     2,     2,     2,
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
      15,    16,    17,    18
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    46,    46,    55,    60,    68,    75,    82,    88,    94,
     101,   111,   100,   130,   145,   151,   159,   171,   177,   183,
     190,   199,   205,   213,   219,   229,   240,   245,   255,   267,
     273,   284,   290,   300,   311,   319,   318,   333,   343,   350,
     357,   366,   373,   380,   388,   399,   406,   413,   420,   427,
     434,   441,   448,   455,   462,   469,   476,   483,   496,   503,
     510,   517,   524,   531,   539,   547,   555,   573,   585,   591,
     599
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "RETURN", "BREAK",
  "ELSE", "IF", "INT", "WHILE", "TRUE", "FALSE", "GT", "LT", "GE", "LE",
  "EQ", "NE", "ID", "NUM", "';'", "'('", "')'", "','", "'{'", "'}'", "'='",
  "'+'", "'-'", "'*'", "'/'", "$accept", "PROGRAM", "METH_LIST", "METH",
  "$@1", "$@2", "PARAMS", "FORMALS", "TYPE", "BODY", "DECLS", "DECL_LIST",
  "DECL", "VARS", "STMTS", "STMT", "$@3", "BLOCK", "ASSIGN", "LOCATION",
  "METHOD", "EXPR", "RELOP", "ADD_EXPR", "ADDOP", "TERM", "MULOP",
  "FACTOR", "ACTUALS", "ARGS", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-69)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,   -14,   114,   -11,    -7,   -80,    -2,   -80,   -80,   -80,
      36,   -80,    52,    25,    21,    27,   -80,    31,    32,    42,
     -80,   -80,    54,   -80,   114,   -80,    59,    53,   103,     9,
     -80,   -80,   114,   114,    24,   -80,   -14,   -80,    63,    51,
     -80,   -80,   -80,   114,    64,    68,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   114,   114,   -80,   -80,   114,
      69,    71,    81,   -80,   -80,   -80,    84,   114,    82,    86,
     -80,   -80,    85,   114,    41,     9,   -80,    90,   -80,   -80,
     -19,    88,     8,   -80,   -80,    98,   107,    90,   114,   -80,
      89,   100,   101,   118,   -80,    90,   -80,    88,   -80,   -80,
     -80,   109,   -80,   -80,   104,   106,   126,   -80,   -80,   -80,
     118,    80,    48,   128,   -80,   -18
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,     0,     0,    18,     0,    43,    39,    31,
       0,     2,     0,     0,     0,     0,    38,     0,     0,     9,
      64,    65,    43,    63,     0,    62,     0,     0,    46,    54,
      58,    37,     0,     0,     0,     1,     0,     5,     0,    10,
       7,     8,    32,     0,     0,    70,    33,    49,    48,    50,
      47,    51,    52,    55,    56,     0,     0,    59,    60,     0,
       0,     0,     0,    41,    30,    26,     0,     0,     0,     0,
      42,    61,     0,     0,    45,    53,    57,     0,    35,    40,
      29,    29,     0,    24,    66,    67,     0,     0,     0,    27,
       0,     0,     0,     0,    69,     0,    36,    29,    25,    15,
      11,     0,    34,    28,     0,    13,    21,    12,    16,    31,
       0,     0,     0,    20,    19,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,   124,   -80,   -80,   -80,   -80,   -80,   -79,   -80,
     -80,   -80,    28,   -17,    30,   -33,   -80,   -80,   -80,     0,
     -80,   -22,   -80,    87,   -80,    91,   -80,    78,   -80,   -80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    10,    11,    12,    68,   104,    92,    93,    13,   107,
     109,   110,    14,    69,    34,    15,    87,    16,    17,    25,
      26,    27,    55,    28,    56,    29,    59,    30,    72,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      18,    64,    44,    66,    66,    19,    88,    67,    31,    91,
      60,    61,    18,    32,   101,   -17,    -3,     1,    33,     2,
       3,    70,     4,     5,     6,    62,    38,     2,     3,   -14,
       4,   112,     6,     7,    18,     8,    35,    57,    58,     9,
      40,     7,    39,     8,    86,    81,    41,     9,    63,    38,
      42,    85,    -6,    36,    96,     2,     3,    43,     4,     5,
       6,   -40,   102,    89,    90,   115,    97,    53,    54,     7,
     -29,     8,    46,    66,   -44,     9,    67,    18,    64,    45,
     103,    62,    65,     2,     3,    71,     4,    18,     6,   -68,
      77,    62,    78,     2,     3,    18,     4,     7,     6,     8,
      79,    80,    82,     9,   114,    83,    84,     7,    98,     8,
      66,    18,    95,     9,    47,    48,    49,    50,    51,    52,
      94,    99,   100,    20,    21,     5,   105,   106,   108,    53,
      54,    22,    23,   -23,    24,   -22,    37,    76,   113,   111,
       0,     0,    74,     0,     0,     0,     0,    75
};

static const yytype_int8 yycheck[] =
{
       0,    34,    24,    22,    22,    19,    25,    25,    19,     1,
      32,    33,    12,    20,    93,     7,     0,     1,    20,     3,
       4,    43,     6,     7,     8,     1,     1,     3,     4,    21,
       6,   110,     8,    17,    34,    19,     0,    28,    29,    23,
      19,    17,    17,    19,    77,    67,    19,    23,    24,     1,
      19,    73,     0,     1,    87,     3,     4,    25,     6,     7,
       8,    19,    95,    80,    81,    17,    88,    26,    27,    17,
      19,    19,    19,    22,    20,    23,    25,    77,   111,    20,
      97,     1,    19,     3,     4,    21,     6,    87,     8,    21,
      21,     1,    21,     3,     4,    95,     6,    17,     8,    19,
      19,    17,    20,    23,    24,    19,    21,    17,    19,    19,
      22,   111,     5,    23,    11,    12,    13,    14,    15,    16,
      22,    21,    21,     9,    10,     7,    17,    23,    22,    26,
      27,    17,    18,     7,    20,     7,    12,    59,   110,   109,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    56
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     6,     7,     8,    17,    19,    23,
      31,    32,    33,    38,    42,    45,    47,    48,    49,    19,
       9,    10,    17,    18,    20,    49,    50,    51,    53,    55,
      57,    19,    20,    20,    44,     0,     1,    32,     1,    17,
      19,    19,    19,    25,    51,    20,    19,    11,    12,    13,
      14,    15,    16,    26,    27,    52,    54,    28,    29,    56,
      51,    51,     1,    24,    45,    19,    22,    25,    34,    43,
      51,    21,    58,    59,    53,    55,    57,    21,    21,    19,
      17,    51,    20,    19,    21,    51,    45,    46,    25,    43,
      43,     1,    36,    37,    22,     5,    45,    51,    19,    21,
      21,    38,    45,    43,    35,    17,    23,    39,    22,    40,
      41,    44,    38,    42,    24,    17
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    31,    31,    32,    32,    32,    32,    32,
      34,    35,    33,    36,    36,    36,    37,    37,    38,    39,
      40,    40,    41,    41,    42,    42,    42,    43,    43,    43,
      44,    44,    45,    45,    45,    46,    45,    45,    45,    45,
      45,    47,    48,    49,    50,    51,    51,    52,    52,    52,
      52,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    57,    57,    57,    57,    58,    58,    59,
      59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     2,     2,     2,
       0,     0,     8,     3,     0,     2,     4,     0,     1,     4,
       2,     0,     2,     0,     4,     6,     3,     3,     5,     0,
       2,     0,     2,     3,     7,     0,     6,     2,     1,     1,
       2,     3,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     4,     2,     0,     3,
       0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* PROGRAM: METH_LIST  */
#line 47 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #1\n");
#endif 
			TreeRoot=MkNode(astProgram,NULL,(yyvsp[0].stnode),NULL,NULL,NULL);
			(yyval.stnode)=TreeRoot;
                     }
#line 1494 "syd.tab.c"
    break;

  case 3: /* PROGRAM: %empty  */
#line 55 "syd.y"
                {
#if DEBUG
                        printf("Rule #2\n");
#endif
		}
#line 1504 "syd.tab.c"
    break;

  case 4: /* PROGRAM: error  */
#line 61 "syd.y"
                {
			error_message("Syntax Error","program must have only methods",NULL);
			yyerrok;
			yyclearin;
			(yyval.stnode)=MkNode(astProgram,NULL,NULL,NULL,NULL,NULL);
		}
#line 1515 "syd.tab.c"
    break;

  case 5: /* METH_LIST: METH METH_LIST  */
#line 69 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #3\n");
#endif 
			(yyval.stnode)=MkNode(astMethList,NULL,(yyvsp[-1].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1526 "syd.tab.c"
    break;

  case 6: /* METH_LIST: METH  */
#line 76 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #4\n");
#endif
			(yyval.stnode)=MkNode(astMethList,NULL,(yyvsp[0].stnode),NULL,NULL,NULL);
                     }
#line 1537 "syd.tab.c"
    break;

  case 7: /* METH_LIST: DECL ';'  */
#line 83 "syd.y"
                {
			error_message("Syntax Error","declaration outside of method",NULL);
			yyerrok;
			yyclearin;
		}
#line 1547 "syd.tab.c"
    break;

  case 8: /* METH_LIST: STMT ';'  */
#line 89 "syd.y"
                {
			error_message("Syntax Error","statement outside of method",NULL);
			yyerrok;
			yyclearin;
		}
#line 1557 "syd.tab.c"
    break;

  case 9: /* METH_LIST: error ';'  */
#line 95 "syd.y"
                {
			error_message("Syntax Error","only methods allowed at the top level",NULL);
			yyerrok;
			yyclearin;
		}
#line 1567 "syd.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 101 "syd.y"
{
#if DEBUG
                        printf("Rule #5 - Part 1\n");
#endif
			addmethod((yyvsp[0].ystr));
			currentscope((yyvsp[0].ystr));
			cur_param_count=0;
			mt[currentmethod].has_return=0;
}
#line 1581 "syd.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 111 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #5 - Part 2\n");
#endif
			mt[currentmethod].param_count=cur_param_count;
 		}
#line 1592 "syd.tab.c"
    break;

  case 12: /* METH: TYPE ID $@1 '(' PARAMS ')' $@2 BODY  */
#line 118 "syd.y"
                {
#if DEBUG
                        printf("Rule #5 - Part 3\n");
#endif
			if(!mt[currentmethod].has_return){
				error_message("Semantic Error","method doesn't have return value",mt[currentmethod].name);
			}
			symbol *temps=new_symbol((yyvsp[-6].ystr));
			(yyval.stnode)=MkNode(astMethod,temps,(yyvsp[0].stnode),NULL,NULL,NULL);
			leavescope();
			}
#line 1608 "syd.tab.c"
    break;

  case 13: /* PARAMS: FORMALS TYPE ID  */
#line 131 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #6\n");
#endif
			if(findsymb(&mt[currentmethod].ht,(yyvsp[0].ystr))){
				error_message("Semantic Error","duplicate parameter in method",(yyvsp[0].ystr));
			}
			addvariable((yyvsp[0].ystr),TRUE_VAL);
			cur_param_count++;
			symbol *temps=new_symbol((yyvsp[0].ystr));
			AstNode *parameter=MkNode(astParam,temps,NULL,NULL,NULL,NULL);
			(yyval.stnode)=MkNode(astParam,NULL,(yyvsp[-2].stnode),parameter,NULL,NULL);
                     }
#line 1626 "syd.tab.c"
    break;

  case 14: /* PARAMS: %empty  */
#line 145 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #7\n");
#endif
			(yyval.stnode)=MkNode(astParams,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1637 "syd.tab.c"
    break;

  case 15: /* PARAMS: error ')'  */
#line 152 "syd.y"
                {
#if DEBUG
                        printf("Rule #8\n");
			fprintf(stderr,"Skipping parameters.\n");
#endif
			yyerrok;
		}
#line 1649 "syd.tab.c"
    break;

  case 16: /* FORMALS: FORMALS TYPE ID ','  */
#line 160 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #9\n");
#endif
			addvariable((yyvsp[-1].ystr),TRUE_VAL);
			cur_param_count++;
			symbol *temps=new_symbol((yyvsp[-1].ystr));
			AstNode *parameter=MkNode(astParam,temps,NULL,NULL,NULL,NULL);
			(yyval.stnode)=MkNode(astParam,NULL,(yyvsp[-3].stnode),parameter,NULL,NULL);
                     }
#line 1664 "syd.tab.c"
    break;

  case 17: /* FORMALS: %empty  */
#line 171 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #10\n");
#endif
			(yyval.stnode)=NULL;
                     }
#line 1675 "syd.tab.c"
    break;

  case 18: /* TYPE: INT  */
#line 178 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #11\n");
#endif
                     }
#line 1685 "syd.tab.c"
    break;

  case 19: /* BODY: '{' DECLS STMTS '}'  */
#line 184 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #12\n");
#endif
			(yyval.stnode)=MkNode(astBody,NULL,(yyvsp[-2].stnode),(yyvsp[-1].stnode),NULL,NULL);
                     }
#line 1696 "syd.tab.c"
    break;

  case 20: /* DECLS: DECL_LIST DECL  */
#line 191 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #13\n");
#endif
			(yyval.stnode)=MkNode(astBody,NULL,(yyvsp[-1].stnode),(yyvsp[0].stnode),NULL,NULL);

                     }
#line 1708 "syd.tab.c"
    break;

  case 21: /* DECLS: %empty  */
#line 199 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #14\n");
#endif
			(yyval.stnode)=MkNode(astBody,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1719 "syd.tab.c"
    break;

  case 22: /* DECL_LIST: DECL_LIST DECL  */
#line 206 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #15\n");
#endif
			(yyval.stnode)=MkNode(astDecls,NULL,(yyvsp[-1].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1730 "syd.tab.c"
    break;

  case 23: /* DECL_LIST: %empty  */
#line 213 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #16\n");
#endif
			(yyval.stnode)=NULL;
                     }
#line 1741 "syd.tab.c"
    break;

  case 24: /* DECL: TYPE ID VARS ';'  */
#line 220 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #17\n");
#endif
			addvariable((yyvsp[-2].ystr),FALSE_VAL);
			symbol *temps=new_symbol((yyvsp[-2].ystr));
			AstNode *var=MkNode(astVarList,temps,NULL,NULL,NULL,NULL);
			(yyval.stnode)=MkNode(astDecls,NULL,var,(yyvsp[-1].stnode),NULL,NULL);
                     }
#line 1755 "syd.tab.c"
    break;

  case 25: /* DECL: TYPE ID '=' EXPR VARS ';'  */
#line 230 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #18\n");
#endif
			addvariable((yyvsp[-4].ystr),FALSE_VAL);
			symbol *temps=new_symbol((yyvsp[-4].ystr));
			AstNode *init=MkNode(astAssign,NULL,MkNode(astId, findsymbolinmethod((yyvsp[-4].ystr)), NULL,NULL,NULL,NULL),(yyvsp[-2].stnode),NULL,NULL);
			AstNode *var=MkNode(astVarList,temps,init,NULL,NULL,NULL);
			(yyval.stnode)=MkNode(astDecls,NULL,var,(yyvsp[-1].stnode),NULL,NULL);
                     }
#line 1770 "syd.tab.c"
    break;

  case 26: /* DECL: TYPE error ';'  */
#line 241 "syd.y"
                {
			yyerrok;
			(yyval.stnode)=MkNode(astDecls,NULL,NULL,NULL,NULL,NULL);
		}
#line 1779 "syd.tab.c"
    break;

  case 27: /* VARS: ',' ID VARS  */
#line 246 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #19\n");
#endif
			addvariable((yyvsp[-1].ystr),FALSE_VAL);
			symbol *temps=new_symbol((yyvsp[-1].ystr));
			AstNode *var=MkNode(astVarList,temps,NULL,NULL,NULL,NULL);
			(yyval.stnode)=MkNode(astDecls,NULL,var,(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1793 "syd.tab.c"
    break;

  case 28: /* VARS: ',' ID '=' EXPR VARS  */
#line 256 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #20\n");
#endif
			addvariable((yyvsp[-3].ystr),FALSE_VAL);
			symbol *temps=new_symbol((yyvsp[-3].ystr));
			AstNode *init=MkNode(astAssign,NULL,MkNode(astId, findsymbolinmethod((yyvsp[-3].ystr)), NULL,NULL,NULL,NULL),(yyvsp[-1].stnode),NULL,NULL);
			AstNode *var=MkNode(astVarList,temps,init,NULL,NULL,NULL);
			(yyval.stnode)=MkNode(astDecls,NULL,var,(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1808 "syd.tab.c"
    break;

  case 29: /* VARS: %empty  */
#line 267 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #21\n");
#endif
			(yyval.stnode)=NULL;
                     }
#line 1819 "syd.tab.c"
    break;

  case 30: /* STMTS: STMTS STMT  */
#line 274 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #22\n");
#endif
			if(ast_returns((yyvsp[-1].stnode))){
				error_message("Semantic Error","cannot reach code after return",mt[currentmethod].name);
			}
			(yyval.stnode)=MkNode(astStmtSeq,NULL,(yyvsp[-1].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1833 "syd.tab.c"
    break;

  case 31: /* STMTS: %empty  */
#line 284 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #23\n");
#endif
			(yyval.stnode)=MkNode(astStmtSeq,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1844 "syd.tab.c"
    break;

  case 32: /* STMT: ASSIGN ';'  */
#line 291 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #24\n");
#endif
			if(!(yyvsp[-1].stnode) || !is_location((yyvsp[-1].stnode)->pAstNode[0])){
				error_message("Semantic Error","assignment target is not a variable",NULL);
			}
			(yyval.stnode)=MkNode(astExprStmt,NULL,(yyvsp[-1].stnode),NULL,NULL,NULL);
                     }
#line 1858 "syd.tab.c"
    break;

  case 33: /* STMT: RETURN EXPR ';'  */
#line 301 "syd.y"
                { 
#if DEBUG
                        printf("Rule #25\n");
#endif
			if(currentmethod==-1){
				error_message("Semantic Error","return outside of a method",NULL);
			}			
			mt[currentmethod].has_return=1;
			(yyval.stnode)=MkNode(astReturnStmt,NULL,(yyvsp[-1].stnode),NULL,NULL,NULL);
                     }
#line 1873 "syd.tab.c"
    break;

  case 34: /* STMT: IF '(' EXPR ')' STMT ELSE STMT  */
#line 312 "syd.y"
                { 
#if DEBUG
                        printf("Rule #26\n");
#endif
			(yyval.stnode)=MkNode(astIfElseStmt,NULL,(yyvsp[-4].stnode),(yyvsp[-2].stnode),(yyvsp[0].stnode),NULL);
                     }
#line 1884 "syd.tab.c"
    break;

  case 35: /* $@3: %empty  */
#line 319 "syd.y"
                { 
#if DEBUG
                        printf("Rule #27 - Part 1\n");
#endif
			loopdepth++;
		}
#line 1895 "syd.tab.c"
    break;

  case 36: /* STMT: WHILE '(' EXPR ')' $@3 STMT  */
#line 326 "syd.y"
                {
#if DEBUG
                        printf("Rule #27 - Part 2\n");
#endif
			loopdepth--;
			(yyval.stnode)=MkNode(astWhileStmt,NULL,(yyvsp[-3].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1907 "syd.tab.c"
    break;

  case 37: /* STMT: BREAK ';'  */
#line 334 "syd.y"
                { 
#if DEBUG
                        printf("Rule #28\n");
#endif
			if(loopdepth==0){
				error_message("Semantic Error","break outside of loop",NULL);
			}
			(yyval.stnode)=MkNode(astBreakStmt,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1921 "syd.tab.c"
    break;

  case 38: /* STMT: BLOCK  */
#line 344 "syd.y"
                { 
#if DEBUG
                        printf("Rule #29\n");
#endif
			(yyval.stnode)=(yyvsp[0].stnode);
                     }
#line 1932 "syd.tab.c"
    break;

  case 39: /* STMT: ';'  */
#line 351 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #30\n");
#endif
			(yyval.stnode)=MkNode(astNullStmt,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1943 "syd.tab.c"
    break;

  case 40: /* STMT: error ';'  */
#line 358 "syd.y"
                {
#if DEBUG
                        printf("Rule #31\n");
			fprintf(stderr,"Skipping statement.\n");
#endif
			yyerrok;
			(yyval.stnode)=MkNode(astNullStmt,NULL,NULL,NULL,NULL,NULL);
		}
#line 1956 "syd.tab.c"
    break;

  case 41: /* BLOCK: '{' STMTS '}'  */
#line 367 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #32\n");
#endif
			(yyval.stnode)=MkNode(astBlock,NULL,(yyvsp[-1].stnode),NULL,NULL,NULL);
                     }
#line 1967 "syd.tab.c"
    break;

  case 42: /* ASSIGN: LOCATION '=' EXPR  */
#line 374 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #33\n");
#endif
			(yyval.stnode)=MkNode(astAssign,NULL,(yyvsp[-2].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1978 "syd.tab.c"
    break;

  case 43: /* LOCATION: ID  */
#line 381 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #34\n");
#endif
			symbol *temps=findsymbolinmethod((yyvsp[0].ystr));
			(yyval.stnode)=MkNode(astId,temps,NULL,NULL,NULL,NULL);
                     }
#line 1990 "syd.tab.c"
    break;

  case 44: /* METHOD: ID  */
#line 389 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #35\n");
#endif
			if(methodidx((yyvsp[0].ystr))==-1){
				error_message("Semantic Error","undeclared method",(yyvsp[0].ystr));
			}
			symbol *temps=new_symbol((yyvsp[0].ystr));
			(yyval.stnode)=MkNode(astId,temps,NULL,NULL,NULL,NULL);
                     }
#line 2005 "syd.tab.c"
    break;

  case 45: /* EXPR: ADD_EXPR RELOP ADD_EXPR  */
#line 400 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #36\n");
#endif
			(yyval.stnode)=MkNode((yyvsp[-1].stnode)->NodeType,NULL,(yyvsp[-2].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 2016 "syd.tab.c"
    break;

  case 46: /* EXPR: ADD_EXPR  */
#line 407 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #37\n");
#endif
			(yyval.stnode)=(yyvsp[0].stnode);
                     }
#line 2027 "syd.tab.c"
    break;

  case 47: /* RELOP: LE  */
#line 414 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #38\n");
#endif
			(yyval.stnode)=MkNode(astLeEq,NULL,NULL,NULL,NULL,NULL);
                     }
#line 2038 "syd.tab.c"
    break;

  case 48: /* RELOP: LT  */
#line 421 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #39\n");
#endif
			(yyval.stnode)=MkNode(astLess,NULL,NULL,NULL,NULL,NULL);
                     }
#line 2049 "syd.tab.c"
    break;

  case 49: /* RELOP: GT  */
#line 428 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #40\n");
#endif
			(yyval.stnode)=MkNode(astGreater,NULL,NULL,NULL,NULL,NULL);
                     }
#line 2060 "syd.tab.c"
    break;

  case 50: /* RELOP: GE  */
#line 435 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #41\n");
#endif
			(yyval.stnode)=MkNode(astGrEq,NULL,NULL,NULL,NULL,NULL);
                     }
#line 2071 "syd.tab.c"
    break;

  case 51: /* RELOP: EQ  */
#line 442 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #42\n");
#endif
			(yyval.stnode)=MkNode(astEq,NULL,NULL,NULL,NULL,NULL);
                     }
#line 2082 "syd.tab.c"
    break;

  case 52: /* RELOP: NE  */
#line 449 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #43\n");
#endif
			(yyval.stnode)=MkNode(astNotEq,NULL,NULL,NULL,NULL,NULL);
                     }
#line 2093 "syd.tab.c"
    break;

  case 53: /* ADD_EXPR: ADD_EXPR ADDOP TERM  */
#line 456 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #44\n");
#endif
			(yyval.stnode)=MkNode((yyvsp[-1].stnode)->NodeType,NULL,(yyvsp[-2].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 2104 "syd.tab.c"
    break;

  case 54: /* ADD_EXPR: TERM  */
#line 463 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #45\n");
#endif
			(yyval.stnode)=(yyvsp[0].stnode);
                     }
#line 2115 "syd.tab.c"
    break;

  case 55: /* ADDOP: '+'  */
#line 470 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #46\n");
#endif
			(yyval.stnode)=MkNode(astAdd,NULL,NULL,NULL,NULL,NULL);
                     }
#line 2126 "syd.tab.c"
    break;

  case 56: /* ADDOP: '-'  */
#line 477 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #47\n");
#endif
			(yyval.stnode)=MkNode(astSub,NULL,NULL,NULL,NULL,NULL);
                     }
#line 2137 "syd.tab.c"
    break;

  case 57: /* TERM: TERM MULOP FACTOR  */
#line 484 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #48\n");
#endif
			if((yyvsp[-1].stnode)->NodeType==astDiv){
			    if(is_zero((yyvsp[0].stnode)))
				error_message("Semantic Error","division by zero",NULL);
			    else if((yyvsp[0].stnode)->NodeType==astId && (yyvsp[0].stnode)->SymbolNode && (yyvsp[0].stnode)->					SymbolNode->timi==0)
				error_message("Semantic Error","division by zero",NULL);
			}
			(yyval.stnode)=MkNode((yyvsp[-1].stnode)->NodeType,NULL,(yyvsp[-2].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 2154 "syd.tab.c"
    break;

  case 58: /* TERM: FACTOR  */
#line 497 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #49\n");
#endif
			(yyval.stnode)=(yyvsp[0].stnode);
                     }
#line 2165 "syd.tab.c"
    break;

  case 59: /* MULOP: '*'  */
#line 504 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #50\n");
#endif
			(yyval.stnode)=MkNode(astMult,NULL,NULL,NULL,NULL,NULL);
                     }
#line 2176 "syd.tab.c"
    break;

  case 60: /* MULOP: '/'  */
#line 511 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #51\n");
#endif
			(yyval.stnode)=MkNode(astDiv,NULL,NULL,NULL,NULL,NULL);
                     }
#line 2187 "syd.tab.c"
    break;

  case 61: /* FACTOR: '(' EXPR ')'  */
#line 518 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #52\n");
#endif
			(yyval.stnode)=(yyvsp[-1].stnode);
                     }
#line 2198 "syd.tab.c"
    break;

  case 62: /* FACTOR: LOCATION  */
#line 525 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #53\n");
#endif
			(yyval.stnode)=(yyvsp[0].stnode);
                     }
#line 2209 "syd.tab.c"
    break;

  case 63: /* FACTOR: NUM  */
#line 532 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #54\n");
#endif
			symbol *temps=new_num_symbol((yyvsp[0].yint));
			(yyval.stnode)=MkNode(astDecimConst,temps,NULL,NULL,NULL,NULL);
                     }
#line 2221 "syd.tab.c"
    break;

  case 64: /* FACTOR: TRUE  */
#line 540 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #55\n");
#endif
			symbol *temps=new_num_symbol(1);
			(yyval.stnode)=MkNode(astDecimConst,temps,NULL,NULL,NULL,NULL);
                     }
#line 2233 "syd.tab.c"
    break;

  case 65: /* FACTOR: FALSE  */
#line 548 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #56\n");
#endif
			symbol *temps=new_num_symbol(0);
			(yyval.stnode)=MkNode(astDecimConst,temps,NULL,NULL,NULL,NULL);
                     }
#line 2245 "syd.tab.c"
    break;

  case 66: /* FACTOR: METHOD '(' ACTUALS ')'  */
#line 556 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #57\n");
#endif
			if(!(yyvsp[-3].stnode) || !(yyvsp[-3].stnode)->SymbolNode){
				error_message("Semantic Error","method symbol missing in call",(char*)(yyvsp[-3].stnode)->SymbolNode->name);
			}
			int mi=methodidx((char*)(yyvsp[-3].stnode)->SymbolNode->name);
			if(mi==-1){
				error_message("Semantic Error","undeclared method",(char*)(yyvsp[-3].stnode)->SymbolNode->name);
			}
			int ca=count_args((yyvsp[-1].stnode));
			if(ca != mt[mi].param_count){
				error_message("Syntax Error","method needs different type of arguments",mt[mi].name);
			}
			(yyval.stnode)=MkNode(astCall,NULL,(yyvsp[-3].stnode),(yyvsp[-1].stnode),NULL,NULL);
                     }
#line 2267 "syd.tab.c"
    break;

  case 67: /* ACTUALS: ARGS EXPR  */
#line 574 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #58\n");
#endif
			if((yyvsp[-1].stnode)==NULL){
				(yyval.stnode)=MkNode(astArgs,NULL,(yyvsp[0].stnode),NULL,NULL,NULL);
			}else{
			        (yyval.stnode) = MkNode(astArgs, NULL, (yyvsp[-1].stnode), MkNode(astArgs, NULL, (yyvsp[0].stnode), 				NULL, NULL, NULL), NULL, NULL);
			}
                     }
#line 2282 "syd.tab.c"
    break;

  case 68: /* ACTUALS: %empty  */
#line 585 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #59\n");
#endif
			(yyval.stnode)=NULL;
                     }
#line 2293 "syd.tab.c"
    break;

  case 69: /* ARGS: ARGS EXPR ','  */
#line 592 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #60\n");
#endif
			(yyval.stnode)=MkNode(astArgs,NULL,(yyvsp[-2].stnode),MkNode(astArgs,NULL,(yyvsp[-1].stnode),NULL,NULL,NULL),NULL,NULL);
                     }
#line 2304 "syd.tab.c"
    break;

  case 70: /* ARGS: %empty  */
#line 599 "syd.y"
                        { 
#if DEBUG
                        printf("Rule #61\n");
#endif
			(yyval.stnode)=NULL;
                     }
#line 2315 "syd.tab.c"
    break;


#line 2319 "syd.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 605 "syd.y"


/* creates symbols with int instead of char* */
static symbol *new_num_symbol(int value) {
    char buf[32];
    snprintf(buf, sizeof(buf), "%d", value);
    symbol *s = new_symbol(buf);  
    s->timi = value;
    return s;
}


void yyerror(const char *s)
{
   error_message("Syntax Error",s,NULL);
}

int main(void)
{
   if(yyparse()==0){
	int mi=methodidx("main");
	if(mi==-1){
		error_message("Syntax Error","need to have main method",NULL);
	}
	if(mt[mi].param_count != 0){
		error_message("Syntax Error","main cannot have parameters",NULL);
	}
	fflush(stdout);
	if(error_count==0){
		printAST(TreeRoot, -3);
	} else {
		fprintf(stderr,"Parsing failed.\n");
	}
   }
}
