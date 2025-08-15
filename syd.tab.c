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
#line 1 "syd.y"


#include "defs.h" 


void yyerror(char *s);
int yyparse();
int yylex();

#define DEBUG 1
static symbol *new_num_symbol(int value);



#line 86 "syd.tab.c"

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
  YYSYMBOL_19_ = 19,                       /* '('  */
  YYSYMBOL_20_ = 20,                       /* ')'  */
  YYSYMBOL_21_ = 21,                       /* ','  */
  YYSYMBOL_22_ = 22,                       /* '{'  */
  YYSYMBOL_23_ = 23,                       /* '}'  */
  YYSYMBOL_24_ = 24,                       /* ';'  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   100

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

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
      19,    20,    28,    26,    21,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
       2,    25,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    22,     2,    23,     2,     2,     2,     2,
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
       0,    37,    37,    46,    53,    61,    71,    60,    91,   103,
     109,   121,   127,   133,   140,   149,   155,   163,   169,   179,
     190,   200,   212,   218,   230,   236,   247,   259,   267,   266,
     281,   292,   299,   306,   313,   320,   328,   340,   347,   354,
     361,   368,   375,   382,   389,   396,   403,   410,   417,   424,
     435,   442,   449,   456,   463,   470,   478,   486,   494,   515,
     524,   530,   538
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "RETURN", "BREAK",
  "ELSE", "IF", "INT", "WHILE", "TRUE", "FALSE", "GT", "LT", "GE", "LE",
  "EQ", "NE", "ID", "NUM", "'('", "')'", "','", "'{'", "'}'", "';'", "'='",
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

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-61)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -3,   -61,     6,   -61,    -3,     3,   -61,   -61,   -61,    -5,
      19,     8,    -3,   -61,    14,    12,    20,    40,   -61,   -61,
     -61,    -3,    -1,    32,    54,    57,    26,    44,    52,   -61,
     -61,   -61,   -61,   -61,   -61,    38,    53,    47,   -61,   -61,
      61,   -61,    57,   -61,    62,    60,    43,   -17,   -61,   -61,
      57,    57,    21,   -61,    57,    65,    57,    63,    66,    68,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,    57,
      57,   -61,   -61,    57,    69,    70,   -61,   -61,    58,    64,
     -61,   -61,    71,    57,    13,   -17,   -61,    29,   -61,    57,
     -61,    72,   -61,    73,    87,    29,    64,   -61,   -61,    29,
     -61,   -61,   -61
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    12,     0,     2,     4,     0,     1,     3,     5,     0,
       9,     0,     0,     6,     0,     0,     8,    15,     7,    10,
      24,     0,     0,     0,    14,     0,     0,     0,     0,    35,
      24,    13,    32,    23,    31,     0,     0,    22,    56,    57,
      35,    55,     0,    54,     0,     0,    38,    46,    50,    30,
       0,     0,     0,    25,     0,     0,     0,     0,     0,    62,
      26,    41,    40,    42,    39,    43,    44,    47,    48,     0,
       0,    51,    52,     0,     0,     0,    33,    34,    22,    22,
      18,    53,     0,     0,    37,    45,    49,     0,    28,     0,
      20,     0,    58,    59,     0,     0,    22,    19,    61,     0,
      29,    21,    27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   -61,    89,   -61,   -61,   -61,   -61,   -61,    -4,   -61,
     -61,   -61,   -61,   -60,    67,   -35,   -61,   -61,   -61,   -22,
     -61,   -41,   -61,    30,   -61,    25,   -61,    27,   -61,   -61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,     9,    15,    11,    12,     5,    18,
      20,    21,    24,    57,    22,    33,    95,    34,    35,    43,
      44,    45,    69,    46,    70,    47,    73,    48,    82,    83
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    58,    25,    26,     1,    27,     6,    28,    14,    74,
      75,    71,    72,    77,    10,    79,    29,    23,    90,    91,
       8,    30,    31,    32,    25,    26,   -11,    27,    13,    28,
      36,    16,    25,    26,    17,    27,   101,    28,    29,    67,
      68,    19,    93,    30,    76,    32,    29,   -17,    96,    37,
      49,    30,    94,    32,    61,    62,    63,    64,    65,    66,
     100,   -16,    53,    50,   102,    36,    38,    39,    55,    67,
      68,    51,    56,    36,    40,    41,    42,    36,    54,    55,
     -36,    59,    78,    89,    60,    55,    81,    80,   -60,    87,
      88,    92,    99,     7,    98,    85,    97,    52,     0,    84,
      86
};

static const yytype_int8 yycheck[] =
{
      22,    42,     3,     4,     7,     6,     0,     8,    12,    50,
      51,    28,    29,    54,    19,    56,    17,    21,    78,    79,
      17,    22,    23,    24,     3,     4,     7,     6,    20,     8,
      52,    17,     3,     4,    22,     6,    96,     8,    17,    26,
      27,    21,    83,    22,    23,    24,    17,     7,    89,    17,
      24,    22,    87,    24,    11,    12,    13,    14,    15,    16,
      95,     7,    24,    19,    99,    87,     9,    10,    21,    26,
      27,    19,    25,    95,    17,    18,    19,    99,    25,    21,
      19,    19,    17,    25,    24,    21,    20,    24,    20,    20,
      20,    20,     5,     4,    21,    70,    24,    30,    -1,    69,
      73
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    31,    32,    33,    38,     0,    32,    17,    34,
      19,    36,    37,    20,    38,    35,    17,    22,    39,    21,
      40,    41,    44,    38,    42,     3,     4,     6,     8,    17,
      22,    23,    24,    45,    47,    48,    49,    17,     9,    10,
      17,    18,    19,    49,    50,    51,    53,    55,    57,    24,
      19,    19,    44,    24,    25,    21,    25,    43,    51,    19,
      24,    11,    12,    13,    14,    15,    16,    26,    27,    52,
      54,    28,    29,    56,    51,    51,    23,    51,    17,    51,
      24,    20,    58,    59,    53,    55,    57,    20,    20,    25,
      43,    43,    20,    51,    45,    46,    51,    24,    21,     5,
      45,    43,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    34,    35,    33,    36,    36,
      37,    37,    38,    39,    40,    40,    41,    41,    42,    42,
      43,    43,    43,    44,    44,    45,    45,    45,    46,    45,
      45,    45,    45,    47,    48,    49,    50,    51,    51,    52,
      52,    52,    52,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    57,    57,    57,    57,    58,
      58,    59,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     0,     8,     3,     0,
       4,     0,     1,     4,     2,     0,     2,     0,     4,     6,
       3,     5,     0,     2,     0,     2,     3,     7,     0,     6,
       2,     1,     1,     3,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     4,     2,
       0,     3,     0
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
#line 38 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #1\n");
#endif 
			TreeRoot=MkNode(astProgram,NULL,(yyvsp[0].stnode),NULL,NULL,NULL);
			(yyval.stnode)=TreeRoot;
                     }
#line 1204 "syd.tab.c"
    break;

  case 3: /* METH_LIST: METH METH_LIST  */
#line 47 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #3\n");
#endif 
			(yyval.stnode)=MkNode(astMethList,NULL,(yyvsp[-1].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1215 "syd.tab.c"
    break;

  case 4: /* METH_LIST: METH  */
#line 54 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #4\n");
#endif
			(yyval.stnode)=MkNode(astMethList,NULL,(yyvsp[0].stnode),NULL,NULL,NULL);
                     }
#line 1226 "syd.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 61 "syd.y"
{
#if DEBUG
                        printf("Rule #5\n");
#endif
			addmethod((yyvsp[0].ystr));
			currentscope((yyvsp[0].ystr));
			cur_param_count=0;
			mt[currentmethod].has_return=0;
}
#line 1240 "syd.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 71 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #5\n");
#endif
			mt[currentmethod].param_count=cur_param_count;
 		}
#line 1251 "syd.tab.c"
    break;

  case 7: /* METH: TYPE ID $@1 '(' PARAMS ')' $@2 BODY  */
#line 78 "syd.y"
                {
#if DEBUG
                        printf("Rule #5\n");
#endif
			if(!mt[currentmethod].has_return){
				printf("method %s doesn't have 								return",mt[currentmethod].name);
				exit(1);
			}
			symbol *temps=new_symbol((yyvsp[-6].ystr));
			(yyval.stnode)=MkNode(astMethod,temps,(yyvsp[0].stnode),NULL,NULL,NULL);
			leavescope();
			}
#line 1268 "syd.tab.c"
    break;

  case 8: /* PARAMS: FORMALS TYPE ID  */
#line 92 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #6\n");
#endif
			addvariable((yyvsp[0].ystr),TRUE_VAL);
			cur_param_count++;
			symbol *temps=new_symbol((yyvsp[0].ystr));
			AstNode *parameter=MkNode(astParam,temps,NULL,NULL,NULL,NULL);
			(yyval.stnode)=MkNode(astParam,NULL,(yyvsp[-2].stnode),parameter,NULL,NULL);
                     }
#line 1283 "syd.tab.c"
    break;

  case 9: /* PARAMS: %empty  */
#line 103 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #7\n");
#endif
			(yyval.stnode)=MkNode(astParams,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1294 "syd.tab.c"
    break;

  case 10: /* FORMALS: FORMALS TYPE ID ','  */
#line 110 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #8\n");
#endif
			addvariable((yyvsp[-1].ystr),TRUE_VAL);
			cur_param_count++;
			symbol *temps=new_symbol((yyvsp[-1].ystr));
			AstNode *parameter=MkNode(astParam,temps,NULL,NULL,NULL,NULL);
			(yyval.stnode)=MkNode(astParam,NULL,(yyvsp[-3].stnode),parameter,NULL,NULL);
                     }
#line 1309 "syd.tab.c"
    break;

  case 11: /* FORMALS: %empty  */
#line 121 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #9\n");
#endif
			(yyval.stnode)=NULL;
                     }
#line 1320 "syd.tab.c"
    break;

  case 12: /* TYPE: INT  */
#line 128 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #10\n");
#endif
                     }
#line 1330 "syd.tab.c"
    break;

  case 13: /* BODY: '{' DECLS STMTS '}'  */
#line 134 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #11\n");
#endif
			(yyval.stnode)=MkNode(astBody,NULL,(yyvsp[-2].stnode),(yyvsp[-1].stnode),NULL,NULL);
                     }
#line 1341 "syd.tab.c"
    break;

  case 14: /* DECLS: DECL_LIST DECL  */
#line 141 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #12\n");
#endif
			(yyval.stnode)=MkNode(astBody,NULL,(yyvsp[-1].stnode),(yyvsp[0].stnode),NULL,NULL);

                     }
#line 1353 "syd.tab.c"
    break;

  case 15: /* DECLS: %empty  */
#line 149 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #13\n");
#endif
			(yyval.stnode)=MkNode(astBody,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1364 "syd.tab.c"
    break;

  case 16: /* DECL_LIST: DECL_LIST DECL  */
#line 156 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #14\n");
#endif
			(yyval.stnode)=MkNode(astDecls,NULL,(yyvsp[-1].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1375 "syd.tab.c"
    break;

  case 17: /* DECL_LIST: %empty  */
#line 163 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #15\n");
#endif
			(yyval.stnode)=NULL;
                     }
#line 1386 "syd.tab.c"
    break;

  case 18: /* DECL: TYPE ID VARS ';'  */
#line 170 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #16\n");
#endif
			addvariable((yyvsp[-2].ystr),FALSE_VAL);
			symbol *temps=new_symbol((yyvsp[-2].ystr));
			AstNode *var=MkNode(astVarList,temps,NULL,NULL,NULL,NULL);
			(yyval.stnode)=MkNode(astDecls,NULL,var,(yyvsp[-1].stnode),NULL,NULL);
                     }
#line 1400 "syd.tab.c"
    break;

  case 19: /* DECL: TYPE ID '=' EXPR VARS ';'  */
#line 180 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #17\n");
#endif
			addvariable((yyvsp[-4].ystr),FALSE_VAL);
			symbol *temps=new_symbol((yyvsp[-4].ystr));
			AstNode *init=MkNode(astAssign,NULL,MkNode(astId, findsymbolinmethod((yyvsp[-4].ystr)), NULL, 					NULL,NULL,NULL),(yyvsp[-2].stnode),NULL,NULL);
			AstNode *var=MkNode(astVarList,temps,init,NULL,NULL,NULL);
			(yyval.stnode)=MkNode(astDecls,NULL,var,(yyvsp[-1].stnode),NULL,NULL);
                     }
#line 1415 "syd.tab.c"
    break;

  case 20: /* VARS: ',' ID VARS  */
#line 191 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #18\n");
#endif
			addvariable((yyvsp[-1].ystr),FALSE_VAL);
			symbol *temps=new_symbol((yyvsp[-1].ystr));
			AstNode *var=MkNode(astVarList,temps,NULL,NULL,NULL,NULL);
			(yyval.stnode)=MkNode(astDecls,NULL,var,(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1429 "syd.tab.c"
    break;

  case 21: /* VARS: ',' ID '=' EXPR VARS  */
#line 201 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #19\n");
#endif
			addvariable((yyvsp[-3].ystr),FALSE_VAL);
			symbol *temps=new_symbol((yyvsp[-3].ystr));
			AstNode *init=MkNode(astAssign,NULL,MkNode(astId, findsymbolinmethod((yyvsp[-3].ystr)), NULL, 					NULL,NULL,NULL),(yyvsp[-1].stnode),NULL,NULL);
			AstNode *var=MkNode(astVarList,temps,init,NULL,NULL,NULL);
			(yyval.stnode)=MkNode(astDecls,NULL,var,(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1444 "syd.tab.c"
    break;

  case 22: /* VARS: %empty  */
#line 212 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #20\n");
#endif
			(yyval.stnode)=NULL;
                     }
#line 1455 "syd.tab.c"
    break;

  case 23: /* STMTS: STMTS STMT  */
#line 219 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #21\n");
#endif
			/* if(ast_returns($1)){
				printf("cannot reach code after return in method %					s",mt[currentmethod].name);
				exit(1);
			} */
			(yyval.stnode)=MkNode(astStmtSeq,NULL,(yyvsp[-1].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1470 "syd.tab.c"
    break;

  case 24: /* STMTS: %empty  */
#line 230 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #22\n");
#endif
			(yyval.stnode)=MkNode(astStmtSeq,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1481 "syd.tab.c"
    break;

  case 25: /* STMT: ASSIGN ';'  */
#line 237 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #23\n");
#endif
			if(!is_location((yyvsp[-1].stnode)->pAstNode[0])){
				printf("assignment target is not a variable\n");
				exit(1);
			}
			(yyval.stnode)=MkNode(astExprStmt,NULL,(yyvsp[-1].stnode),NULL,NULL,NULL);
                     }
#line 1496 "syd.tab.c"
    break;

  case 26: /* STMT: RETURN EXPR ';'  */
#line 248 "syd.y"
                { 
#if DEBUG
                        printf("Rule #24\n");
#endif
			if(currentmethod==-1){
				printf("return outside of method\n");
				exit(1);
			}
			mt[currentmethod].has_return=1;
			(yyval.stnode)=MkNode(astReturnStmt,NULL,(yyvsp[-1].stnode),NULL,NULL,NULL);
                     }
#line 1512 "syd.tab.c"
    break;

  case 27: /* STMT: IF '(' EXPR ')' STMT ELSE STMT  */
#line 260 "syd.y"
                { 
#if DEBUG
                        printf("Rule #25\n");
#endif
			(yyval.stnode)=MkNode(astIfElseStmt,NULL,(yyvsp[-4].stnode),(yyvsp[-2].stnode),(yyvsp[0].stnode),NULL);
                     }
#line 1523 "syd.tab.c"
    break;

  case 28: /* $@3: %empty  */
#line 267 "syd.y"
                { 
#if DEBUG
                        printf("Rule #26\n");
#endif
			loopdepth++;
		}
#line 1534 "syd.tab.c"
    break;

  case 29: /* STMT: WHILE '(' EXPR ')' $@3 STMT  */
#line 274 "syd.y"
                {
#if DEBUG
                        printf("Rule #26\n");
#endif
			loopdepth--;
			(yyval.stnode)=MkNode(astWhileStmt,NULL,(yyvsp[-3].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1546 "syd.tab.c"
    break;

  case 30: /* STMT: BREAK ';'  */
#line 282 "syd.y"
                { 
#if DEBUG
                        printf("Rule #27\n");
#endif
			if(loopdepth==0){
				printf("break outside of a loop\n");
				exit(1);
			}
			(yyval.stnode)=MkNode(astBreakStmt,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1561 "syd.tab.c"
    break;

  case 31: /* STMT: BLOCK  */
#line 293 "syd.y"
                { 
#if DEBUG
                        printf("Rule #28\n");
#endif
			(yyval.stnode)=(yyvsp[0].stnode);
                     }
#line 1572 "syd.tab.c"
    break;

  case 32: /* STMT: ';'  */
#line 300 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #29\n");
#endif
			(yyval.stnode)=MkNode(astNullStmt,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1583 "syd.tab.c"
    break;

  case 33: /* BLOCK: '{' STMTS '}'  */
#line 307 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #30\n");
#endif
			(yyval.stnode)=MkNode(astBlock,NULL,(yyvsp[-1].stnode),NULL,NULL,NULL);
                     }
#line 1594 "syd.tab.c"
    break;

  case 34: /* ASSIGN: LOCATION '=' EXPR  */
#line 314 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #31\n");
#endif
			(yyval.stnode)=MkNode(astAssign,NULL,(yyvsp[-2].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1605 "syd.tab.c"
    break;

  case 35: /* LOCATION: ID  */
#line 321 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #32\n");
#endif
			symbol *temps=findsymbolinmethod((yyvsp[0].ystr));
			(yyval.stnode)=MkNode(astId,temps,NULL,NULL,NULL,NULL);
                     }
#line 1617 "syd.tab.c"
    break;

  case 36: /* METHOD: ID  */
#line 329 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #33\n");
#endif
			if(methodidx((yyvsp[0].ystr))==-1){
				printf("method %s isn't declared\n",(yyvsp[0].ystr));
				exit(1);
			}
			symbol *temps=new_symbol((yyvsp[0].ystr));
			(yyval.stnode)=MkNode(astId,temps,NULL,NULL,NULL,NULL);
                     }
#line 1633 "syd.tab.c"
    break;

  case 37: /* EXPR: ADD_EXPR RELOP ADD_EXPR  */
#line 341 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #34\n");
#endif
			(yyval.stnode)=MkNode((yyvsp[-1].stnode)->NodeType,NULL,(yyvsp[-2].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1644 "syd.tab.c"
    break;

  case 38: /* EXPR: ADD_EXPR  */
#line 348 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #35\n");
#endif
			(yyval.stnode)=(yyvsp[0].stnode);
                     }
#line 1655 "syd.tab.c"
    break;

  case 39: /* RELOP: LE  */
#line 355 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #36\n");
#endif
			(yyval.stnode)=MkNode(astLeEq,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1666 "syd.tab.c"
    break;

  case 40: /* RELOP: LT  */
#line 362 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #37\n");
#endif
			(yyval.stnode)=MkNode(astLess,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1677 "syd.tab.c"
    break;

  case 41: /* RELOP: GT  */
#line 369 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #38\n");
#endif
			(yyval.stnode)=MkNode(astGreater,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1688 "syd.tab.c"
    break;

  case 42: /* RELOP: GE  */
#line 376 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #39\n");
#endif
			(yyval.stnode)=MkNode(astGrEq,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1699 "syd.tab.c"
    break;

  case 43: /* RELOP: EQ  */
#line 383 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #40\n");
#endif
			(yyval.stnode)=MkNode(astEq,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1710 "syd.tab.c"
    break;

  case 44: /* RELOP: NE  */
#line 390 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #41\n");
#endif
			(yyval.stnode)=MkNode(astNotEq,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1721 "syd.tab.c"
    break;

  case 45: /* ADD_EXPR: ADD_EXPR ADDOP TERM  */
#line 397 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #42\n");
#endif
			(yyval.stnode)=MkNode((yyvsp[-1].stnode)->NodeType,NULL,(yyvsp[-2].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1732 "syd.tab.c"
    break;

  case 46: /* ADD_EXPR: TERM  */
#line 404 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #43\n");
#endif
			(yyval.stnode)=(yyvsp[0].stnode);
                     }
#line 1743 "syd.tab.c"
    break;

  case 47: /* ADDOP: '+'  */
#line 411 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #44\n");
#endif
			(yyval.stnode)=MkNode(astAdd,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1754 "syd.tab.c"
    break;

  case 48: /* ADDOP: '-'  */
#line 418 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #45\n");
#endif
			(yyval.stnode)=MkNode(astSub,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1765 "syd.tab.c"
    break;

  case 49: /* TERM: TERM MULOP FACTOR  */
#line 425 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #46\n");
#endif
			if((yyvsp[-1].stnode)->NodeType==astDiv && is_zero((yyvsp[0].stnode))){
				printf("division by zero\n");
				exit(1);
			}
			(yyval.stnode)=MkNode((yyvsp[-1].stnode)->NodeType,NULL,(yyvsp[-2].stnode),(yyvsp[0].stnode),NULL,NULL);
                     }
#line 1780 "syd.tab.c"
    break;

  case 50: /* TERM: FACTOR  */
#line 436 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #47\n");
#endif
			(yyval.stnode)=(yyvsp[0].stnode);
                     }
#line 1791 "syd.tab.c"
    break;

  case 51: /* MULOP: '*'  */
#line 443 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #48\n");
#endif
			(yyval.stnode)=MkNode(astMult,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1802 "syd.tab.c"
    break;

  case 52: /* MULOP: '/'  */
#line 450 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #49\n");
#endif
			(yyval.stnode)=MkNode(astDiv,NULL,NULL,NULL,NULL,NULL);
                     }
#line 1813 "syd.tab.c"
    break;

  case 53: /* FACTOR: '(' EXPR ')'  */
#line 457 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #50\n");
#endif
			(yyval.stnode)=(yyvsp[-1].stnode);
                     }
#line 1824 "syd.tab.c"
    break;

  case 54: /* FACTOR: LOCATION  */
#line 464 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #51\n");
#endif
			(yyval.stnode)=(yyvsp[0].stnode);
                     }
#line 1835 "syd.tab.c"
    break;

  case 55: /* FACTOR: NUM  */
#line 471 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #52\n");
#endif
			symbol *temps=new_num_symbol((yyvsp[0].yint));
			(yyval.stnode)=MkNode(astDecimConst,temps,NULL,NULL,NULL,NULL);
                     }
#line 1847 "syd.tab.c"
    break;

  case 56: /* FACTOR: TRUE  */
#line 479 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #53\n");
#endif
			symbol *temps=new_num_symbol(1);
			(yyval.stnode)=MkNode(astDecimConst,temps,NULL,NULL,NULL,NULL);
                     }
#line 1859 "syd.tab.c"
    break;

  case 57: /* FACTOR: FALSE  */
#line 487 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #54\n");
#endif
			symbol *temps=new_num_symbol(0);
			(yyval.stnode)=MkNode(astDecimConst,temps,NULL,NULL,NULL,NULL);
                     }
#line 1871 "syd.tab.c"
    break;

  case 58: /* FACTOR: METHOD '(' ACTUALS ')'  */
#line 495 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #55\n");
#endif
			if(!(yyvsp[-3].stnode) || !(yyvsp[-3].stnode)->SymbolNode){
				printf("internal: method symbol missing in call\n");
                           	exit(1);
			}
			int mi=methodidx((char*)(yyvsp[-3].stnode)->SymbolNode->name);
			if(mi==-1){
				printf("method %s not declared\n",(char*)(yyvsp[-3].stnode)->SymbolNode->name);
                           	exit(1);
			}
			int ca=count_args((yyvsp[-1].stnode));
			if(ca != mt[mi].param_count){
				printf("method %s needs %d arguments but got %d\n",mt[mi].name,mt[mi].param_count,ca);
                           	exit(1);
			}
			(yyval.stnode)=MkNode(astCall,NULL,(yyvsp[-3].stnode),(yyvsp[-1].stnode),NULL,NULL);
                     }
#line 1896 "syd.tab.c"
    break;

  case 59: /* ACTUALS: ARGS EXPR  */
#line 516 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #56\n");
#endif
			AstNode *last=MkNode(astArgs,NULL,(yyvsp[0].stnode),NULL,NULL,NULL);
			(yyval.stnode)=MkNode(astArgs,NULL,(yyvsp[0].stnode),NULL,NULL,NULL);
                     }
#line 1908 "syd.tab.c"
    break;

  case 60: /* ACTUALS: %empty  */
#line 524 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #57\n");
#endif
			(yyval.stnode)=NULL;
                     }
#line 1919 "syd.tab.c"
    break;

  case 61: /* ARGS: ARGS EXPR ','  */
#line 531 "syd.y"
                     { 
#if DEBUG
                        printf("Rule #58\n");
#endif
			(yyval.stnode)=MkNode(astArgs,NULL,(yyvsp[-2].stnode),MkNode(astArgs,NULL,(yyvsp[-1].stnode),NULL,NULL,NULL),NULL,NULL);
                     }
#line 1930 "syd.tab.c"
    break;

  case 62: /* ARGS: %empty  */
#line 538 "syd.y"
                        { 
#if DEBUG
                        printf("Rule #59\n");
#endif
			(yyval.stnode)=NULL;
                     }
#line 1941 "syd.tab.c"
    break;


#line 1945 "syd.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 544 "syd.y"


/* creates symbols with int instead of char* */
static symbol *new_num_symbol(int value) {
    char buf[32];
    snprintf(buf, sizeof(buf), "%d", value);
    symbol *s = new_symbol(buf);  
    s->timi = value;
    return s;
}

void yyerror(char *s)
{
   fputs(s,stderr); putc('\n',stderr);
}

int main(void)
{
   fprintf(stderr, "Starting parse...\n");
   yyparse();
   fprintf(stderr, "yyparse() returned %d\n", yyparse());

   if(yyparse()==0){
	int mi=methodidx("main");
	if(mi==-1){
		printf("need to have a main method\n");
		exit(1);
	}
	if(mt[mi].param_count != 0){
		printf("main cannot have parameters\n");
		exit(1);
	}
	fflush(stdout);
	printAST(TreeRoot, -3);
   }
}
