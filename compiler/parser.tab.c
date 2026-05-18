/* A Bison parser, made by GNU Bison 3.7.4.  */

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
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

/* ============================================================
   parser.y  —  Bison Parser for Mini C Compiler
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "ast.h"
#include "semantic.h"
#include "tac.h"
#include "error.h"

extern int  yylineno;
extern int  token_count;
extern int  get_token_count(void);
int yylex(void);
void yyerror(const char *msg);

ASTNode *parse_tree_root = NULL;
static int param_count = 0;

/* forward declare the helper so mid-rule actions can call it */
static void begin_function(const char *name, const char *type_str);

#line 98 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_INT = 3,                     /* KW_INT  */
  YYSYMBOL_KW_FLOAT = 4,                   /* KW_FLOAT  */
  YYSYMBOL_KW_CHAR = 5,                    /* KW_CHAR  */
  YYSYMBOL_KW_VOID = 6,                    /* KW_VOID  */
  YYSYMBOL_KW_RETURN = 7,                  /* KW_RETURN  */
  YYSYMBOL_KW_IF = 8,                      /* KW_IF  */
  YYSYMBOL_KW_ELSE = 9,                    /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 10,                  /* KW_WHILE  */
  YYSYMBOL_KW_FOR = 11,                    /* KW_FOR  */
  YYSYMBOL_KW_DO = 12,                     /* KW_DO  */
  YYSYMBOL_KW_BREAK = 13,                  /* KW_BREAK  */
  YYSYMBOL_KW_CONT = 14,                   /* KW_CONT  */
  YYSYMBOL_IDENTIFIER = 15,                /* IDENTIFIER  */
  YYSYMBOL_INT_LITERAL = 16,               /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 17,             /* FLOAT_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 18,              /* CHAR_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 19,            /* STRING_LITERAL  */
  YYSYMBOL_OP_PLUS = 20,                   /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 21,                  /* OP_MINUS  */
  YYSYMBOL_OP_MUL = 22,                    /* OP_MUL  */
  YYSYMBOL_OP_DIV = 23,                    /* OP_DIV  */
  YYSYMBOL_OP_MOD = 24,                    /* OP_MOD  */
  YYSYMBOL_OP_EQ = 25,                     /* OP_EQ  */
  YYSYMBOL_OP_NEQ = 26,                    /* OP_NEQ  */
  YYSYMBOL_OP_LT = 27,                     /* OP_LT  */
  YYSYMBOL_OP_GT = 28,                     /* OP_GT  */
  YYSYMBOL_OP_LTE = 29,                    /* OP_LTE  */
  YYSYMBOL_OP_GTE = 30,                    /* OP_GTE  */
  YYSYMBOL_OP_AND = 31,                    /* OP_AND  */
  YYSYMBOL_OP_OR = 32,                     /* OP_OR  */
  YYSYMBOL_OP_NOT = 33,                    /* OP_NOT  */
  YYSYMBOL_OP_ASSIGN = 34,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_PLUSEQ = 35,                 /* OP_PLUSEQ  */
  YYSYMBOL_OP_MINEQ = 36,                  /* OP_MINEQ  */
  YYSYMBOL_OP_MULEQ = 37,                  /* OP_MULEQ  */
  YYSYMBOL_OP_DIVEQ = 38,                  /* OP_DIVEQ  */
  YYSYMBOL_OP_INC = 39,                    /* OP_INC  */
  YYSYMBOL_OP_DEC = 40,                    /* OP_DEC  */
  YYSYMBOL_LPAREN = 41,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 42,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 43,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 44,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 45,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 46,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 47,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 48,                     /* COMMA  */
  YYSYMBOL_UMINUS = 49,                    /* UMINUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 50,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_function_list = 53,             /* function_list  */
  YYSYMBOL_func_header_with_params = 54,   /* func_header_with_params  */
  YYSYMBOL_func_header_no_params = 55,     /* func_header_no_params  */
  YYSYMBOL_function_def = 56,              /* function_def  */
  YYSYMBOL_type_spec = 57,                 /* type_spec  */
  YYSYMBOL_param_list = 58,                /* param_list  */
  YYSYMBOL_param = 59,                     /* param  */
  YYSYMBOL_compound_stmt = 60,             /* compound_stmt  */
  YYSYMBOL_stmt_list = 61,                 /* stmt_list  */
  YYSYMBOL_statement = 62,                 /* statement  */
  YYSYMBOL_declaration = 63,               /* declaration  */
  YYSYMBOL_expr_stmt = 64,                 /* expr_stmt  */
  YYSYMBOL_return_stmt = 65,               /* return_stmt  */
  YYSYMBOL_if_stmt = 66,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 67,                /* while_stmt  */
  YYSYMBOL_for_stmt = 68,                  /* for_stmt  */
  YYSYMBOL_expression = 69,                /* expression  */
  YYSYMBOL_assignment_expr = 70,           /* assignment_expr  */
  YYSYMBOL_logical_or_expr = 71,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 72,          /* logical_and_expr  */
  YYSYMBOL_equality_expr = 73,             /* equality_expr  */
  YYSYMBOL_relational_expr = 74,           /* relational_expr  */
  YYSYMBOL_additive_expr = 75,             /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 76,       /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 77,                /* unary_expr  */
  YYSYMBOL_postfix_expr = 78,              /* postfix_expr  */
  YYSYMBOL_arg_list = 79,                  /* arg_list  */
  YYSYMBOL_primary_expr = 80               /* primary_expr  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   254

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,    90,    94,   113,   128,   147,   162,   183,
     184,   185,   186,   194,   200,   208,   226,   232,   239,   245,
     258,   259,   260,   261,   262,   263,   264,   265,   270,   284,
     299,   328,   335,   346,   354,   367,   378,   396,   413,   436,
     440,   441,   456,   468,   483,   484,   496,   497,   509,   510,
     519,   531,   532,   540,   548,   556,   567,   568,   577,   589,
     590,   599,   608,   620,   621,   629,   637,   648,   662,   663,
     674,   685,   698,   711,   719,   729,   737,   744,   751,   759
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
  "\"end of file\"", "error", "\"invalid token\"", "KW_INT", "KW_FLOAT",
  "KW_CHAR", "KW_VOID", "KW_RETURN", "KW_IF", "KW_ELSE", "KW_WHILE",
  "KW_FOR", "KW_DO", "KW_BREAK", "KW_CONT", "IDENTIFIER", "INT_LITERAL",
  "FLOAT_LITERAL", "CHAR_LITERAL", "STRING_LITERAL", "OP_PLUS", "OP_MINUS",
  "OP_MUL", "OP_DIV", "OP_MOD", "OP_EQ", "OP_NEQ", "OP_LT", "OP_GT",
  "OP_LTE", "OP_GTE", "OP_AND", "OP_OR", "OP_NOT", "OP_ASSIGN",
  "OP_PLUSEQ", "OP_MINEQ", "OP_MULEQ", "OP_DIVEQ", "OP_INC", "OP_DEC",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET",
  "SEMICOLON", "COMMA", "UMINUS", "LOWER_THAN_ELSE", "$accept", "program",
  "function_list", "func_header_with_params", "func_header_no_params",
  "function_def", "type_spec", "param_list", "param", "compound_stmt",
  "stmt_list", "statement", "declaration", "expr_stmt", "return_stmt",
  "if_stmt", "while_stmt", "for_stmt", "expression", "assignment_expr",
  "logical_or_expr", "logical_and_expr", "equality_expr",
  "relational_expr", "additive_expr", "multiplicative_expr", "unary_expr",
  "postfix_expr", "arg_list", "primary_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     105,   -34,   -34,   -34,   -34,     2,   105,   -29,   -29,   -34,
       1,   -34,   -34,    17,   -34,   -34,   -22,    55,   -12,    10,
      18,    -6,    22,    45,   -34,   -34,   -34,    82,    82,    50,
      59,   213,   -34,   -34,    60,   -34,   122,   -34,   -34,   -34,
     -34,   -34,   -34,   -34,    30,   -34,    46,    51,    11,   117,
      19,   130,   -34,   -34,   -34,     4,   -34,    40,   213,   213,
     176,   -34,   -34,   213,   213,   213,   -34,   -34,   203,   118,
     -34,   -34,   -34,   -34,    47,   -21,   -34,   -34,   -34,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,   -34,    75,   -31,   -34,   -34,    63,    64,   213,
     -34,   -34,   -34,   -34,   -34,   -30,   -34,   213,   -34,    51,
      11,   117,   117,    19,    19,    19,    19,   130,   130,   -34,
     -34,   -34,   -34,   -34,   105,   167,   167,    54,   -34,   213,
      67,   -34,   103,   -34,   213,   -34,   -34,   167,    74,   -34,
     167,   -34
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,    11,    12,     0,     2,     0,     0,     3,
       0,     1,     4,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,    78,    75,    76,    77,     0,     0,     0,
       0,     0,    17,    32,     0,    26,     0,    18,    20,    21,
      22,    23,    24,    25,     0,    39,    40,    44,    46,    48,
      51,    56,    59,    63,    68,     0,    34,     0,     0,     0,
       0,    27,    28,     0,     0,     0,    69,    70,     0,    78,
      64,    65,    66,    67,     0,     0,    16,    19,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     0,     0,    13,    33,     0,     0,     0,
      41,    42,    43,    72,    73,     0,    79,     0,    29,    45,
      47,    49,    50,    52,    53,    54,    55,    57,    58,    60,
      61,    62,    15,     5,     0,     0,     0,     0,    71,     0,
       0,    14,    35,    37,     0,    74,    30,     0,     0,    36,
       0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,   -34,   -34,   -34,   111,     0,   -34,    -5,    37,
     -34,   -33,   -34,    71,   -34,   -34,   -34,   -34,   -16,   -34,
     -34,    41,    61,   -28,    65,   -25,   -23,   -34,   -34,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    34,    94,    95,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,   105,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      10,    57,    11,    77,    70,    71,    10,     1,     2,     3,
       4,   123,   128,   107,    13,    74,    16,   124,   129,    55,
       1,     2,     3,     4,    17,    18,   108,    19,    20,    58,
      21,    22,    23,    24,    25,    26,    81,    82,    27,    87,
      88,    61,    97,    98,    14,    15,    92,   100,   101,   102,
      28,    59,   104,   111,   112,    93,    29,    30,    31,    60,
      13,    32,   117,   118,    33,    72,   119,   120,   121,    62,
      23,    24,    25,    26,    73,    75,    27,    78,    79,    63,
      64,    65,    80,   127,    66,    67,    68,    96,    28,   106,
     122,   130,   132,   133,    29,    30,    31,    69,    24,    25,
      26,   134,    56,    27,   139,   125,   126,   141,     1,     2,
       3,     4,   137,   135,   136,    28,   140,    12,   138,   131,
     109,    29,    30,    31,    93,     1,     2,     3,     4,    17,
      18,    99,    19,    20,     0,    21,    22,    23,    24,    25,
      26,   110,     0,    27,    83,    84,    85,    86,   113,   114,
     115,   116,    89,    90,    91,    28,     0,    66,    67,    68,
       0,    29,    30,    31,     0,    13,    76,     0,     0,    33,
       1,     2,     3,     4,    17,    18,     0,    19,    20,     0,
      21,    22,    23,    24,    25,    26,     0,     0,    27,     0,
       0,    23,    24,    25,    26,     0,     0,    27,     0,     0,
      28,     0,     0,     0,     0,     0,    29,    30,    31,    28,
      13,     0,     0,     0,    33,    29,    30,    31,    23,    24,
      25,    26,     0,    33,    27,     0,     0,     0,    23,    24,
      25,    26,     0,     0,    27,     0,    28,     0,     0,     0,
       0,     0,    29,    30,    31,   103,    28,     0,     0,     0,
       0,     0,    29,    30,    31
};

static const yytype_int16 yycheck[] =
{
       0,    17,     0,    36,    27,    28,     6,     3,     4,     5,
       6,    42,    42,    34,    43,    31,    15,    48,    48,    41,
       3,     4,     5,     6,     7,     8,    47,    10,    11,    41,
      13,    14,    15,    16,    17,    18,    25,    26,    21,    20,
      21,    47,    58,    59,     7,     8,    42,    63,    64,    65,
      33,    41,    68,    81,    82,    55,    39,    40,    41,    41,
      43,    44,    87,    88,    47,    15,    89,    90,    91,    47,
      15,    16,    17,    18,    15,    15,    21,    47,    32,    34,
      35,    36,    31,    99,    39,    40,    41,    47,    33,    42,
      15,   107,   125,   126,    39,    40,    41,    15,    16,    17,
      18,    47,    47,    21,   137,    42,    42,   140,     3,     4,
       5,     6,     9,   129,    47,    33,    42,     6,   134,   124,
      79,    39,    40,    41,   124,     3,     4,     5,     6,     7,
       8,    60,    10,    11,    -1,    13,    14,    15,    16,    17,
      18,    80,    -1,    21,    27,    28,    29,    30,    83,    84,
      85,    86,    22,    23,    24,    33,    -1,    39,    40,    41,
      -1,    39,    40,    41,    -1,    43,    44,    -1,    -1,    47,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    -1,    -1,    21,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    33,
      43,    -1,    -1,    -1,    47,    39,    40,    41,    15,    16,
      17,    18,    -1,    47,    21,    -1,    -1,    -1,    15,    16,
      17,    18,    -1,    -1,    21,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    33,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    52,    53,    54,    55,    56,
      57,     0,    56,    43,    60,    60,    15,     7,     8,    10,
      11,    13,    14,    15,    16,    17,    18,    21,    33,    39,
      40,    41,    44,    47,    57,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    80,    41,    47,    69,    41,    41,
      41,    47,    47,    34,    35,    36,    39,    40,    41,    15,
      77,    77,    15,    15,    69,    15,    44,    62,    47,    32,
      31,    25,    26,    27,    28,    29,    30,    20,    21,    22,
      23,    24,    42,    57,    58,    59,    47,    69,    69,    64,
      69,    69,    69,    42,    69,    79,    42,    34,    47,    72,
      73,    74,    74,    75,    75,    75,    75,    76,    76,    77,
      77,    77,    15,    42,    48,    42,    42,    69,    42,    48,
      69,    59,    62,    62,    47,    69,    47,     9,    69,    62,
      42,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    55,    56,    56,    57,
      57,    57,    57,    58,    58,    59,    60,    60,    61,    61,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    68,    69,
      70,    70,    70,    70,    71,    71,    72,    72,    73,    73,
      73,    74,    74,    74,    74,    74,    75,    75,    75,    76,
      76,    76,    76,    77,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    79,    79,    80,    80,    80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     5,     4,     2,     2,     1,
       1,     1,     1,     1,     3,     2,     3,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       5,     2,     1,     3,     2,     5,     7,     5,     8,     1,
       1,     3,     3,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     2,     2,     1,     2,
       2,     4,     3,     1,     3,     1,     1,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  case 3: /* function_list: function_def  */
#line 91 "parser.y"
        {
            parse_tree_root = (yyvsp[0].expr).node;
        }
#line 1289 "parser.tab.c"
    break;

  case 4: /* function_list: function_list function_def  */
#line 95 "parser.y"
        {
            ASTNode *prog = ast_new_node("Program", yylineno);
            ast_add_child(prog, parse_tree_root);
            ast_add_child(prog, (yyvsp[0].expr).node);
            parse_tree_root = prog;
        }
#line 1300 "parser.tab.c"
    break;

  case 5: /* func_header_with_params: type_spec IDENTIFIER LPAREN param_list RPAREN  */
#line 114 "parser.y"
        {
            /* Inherited attribute: type flows down into function body */
            begin_function((yyvsp[-3].str), (yyvsp[-4].str));
            ASTNode *hdr = ast_new_node("FuncHeader", yylineno);
            ast_add_child(hdr, ast_new_node((yyvsp[-4].str), yylineno));
            ast_add_child(hdr, ast_new_node((yyvsp[-3].str), yylineno));
            if ((yyvsp[-1].expr).node) ast_add_child(hdr, (yyvsp[-1].expr).node);
            (yyval.expr).node = hdr;
            strncpy((yyval.expr).temp, (yyvsp[-3].str), 63);
            free((yyvsp[-4].str)); free((yyvsp[-3].str));
        }
#line 1316 "parser.tab.c"
    break;

  case 6: /* func_header_no_params: type_spec IDENTIFIER LPAREN RPAREN  */
#line 129 "parser.y"
        {
            /* Inherited attribute: type flows down into function body */
            begin_function((yyvsp[-2].str), (yyvsp[-3].str));
            ASTNode *hdr = ast_new_node("FuncHeader", yylineno);
            ast_add_child(hdr, ast_new_node((yyvsp[-3].str), yylineno));
            ast_add_child(hdr, ast_new_node((yyvsp[-2].str), yylineno));
            ast_add_child(hdr, ast_new_node("(no params)", yylineno));
            (yyval.expr).node = hdr;
            strncpy((yyval.expr).temp, (yyvsp[-2].str), 63);
            free((yyvsp[-3].str)); free((yyvsp[-2].str));
        }
#line 1332 "parser.tab.c"
    break;

  case 7: /* function_def: func_header_with_params compound_stmt  */
#line 148 "parser.y"
        {
            ASTNode *fn = ast_new_node("FunctionDef", yylineno);
            /* pull children from header node */
            ASTNode *hdr = (yyvsp[-1].expr).node;
            for (int i = 0; i < hdr->child_count; i++)
                ast_add_child(fn, hdr->children[i]);
            if ((yyvsp[0].expr).node) ast_add_child(fn, (yyvsp[0].expr).node);

            tac_emit(TAC_FUNC_BEGIN, "", (yyvsp[-1].expr).temp, "");
            tac_emit(TAC_FUNC_END,   "", (yyvsp[-1].expr).temp, "");

            (yyval.expr).node = fn;
            sem_exit_scope();
        }
#line 1351 "parser.tab.c"
    break;

  case 8: /* function_def: func_header_no_params compound_stmt  */
#line 163 "parser.y"
        {
            ASTNode *fn = ast_new_node("FunctionDef", yylineno);
            ASTNode *hdr = (yyvsp[-1].expr).node;
            for (int i = 0; i < hdr->child_count; i++)
                ast_add_child(fn, hdr->children[i]);
            if ((yyvsp[0].expr).node) ast_add_child(fn, (yyvsp[0].expr).node);

            tac_emit(TAC_FUNC_BEGIN, "", (yyvsp[-1].expr).temp, "");
            tac_emit(TAC_FUNC_END,   "", (yyvsp[-1].expr).temp, "");

            (yyval.expr).node = fn;
            sem_exit_scope();
        }
#line 1369 "parser.tab.c"
    break;

  case 9: /* type_spec: KW_INT  */
#line 183 "parser.y"
               { (yyval.str) = strdup("int");   }
#line 1375 "parser.tab.c"
    break;

  case 10: /* type_spec: KW_FLOAT  */
#line 184 "parser.y"
               { (yyval.str) = strdup("float"); }
#line 1381 "parser.tab.c"
    break;

  case 11: /* type_spec: KW_CHAR  */
#line 185 "parser.y"
               { (yyval.str) = strdup("char");  }
#line 1387 "parser.tab.c"
    break;

  case 12: /* type_spec: KW_VOID  */
#line 186 "parser.y"
               { (yyval.str) = strdup("void");  }
#line 1393 "parser.tab.c"
    break;

  case 13: /* param_list: param  */
#line 195 "parser.y"
        {
            ASTNode *pl = ast_new_node("ParamList", yylineno);
            ast_add_child(pl, (yyvsp[0].expr).node);
            (yyval.expr).node = pl;
        }
#line 1403 "parser.tab.c"
    break;

  case 14: /* param_list: param_list COMMA param  */
#line 201 "parser.y"
        {
            ast_add_child((yyvsp[-2].expr).node, (yyvsp[0].expr).node);
            (yyval.expr).node = (yyvsp[-2].expr).node;
        }
#line 1412 "parser.tab.c"
    break;

  case 15: /* param: type_spec IDENTIFIER  */
#line 209 "parser.y"
        {
            SymType t = str_to_type((yyvsp[-1].str));
            sem_declare_param((yyvsp[0].str), t, yylineno);
            ASTNode *p = ast_new_node("Param", yylineno);
            ast_add_child(p, ast_new_node((yyvsp[-1].str), yylineno));
            ast_add_child(p, ast_new_node((yyvsp[0].str), yylineno));
            (yyval.expr).node = p;
            free((yyvsp[-1].str)); free((yyvsp[0].str));
        }
#line 1426 "parser.tab.c"
    break;

  case 16: /* compound_stmt: LBRACE stmt_list RBRACE  */
#line 227 "parser.y"
        {
            ASTNode *blk = ast_new_node("Block", yylineno);
            if ((yyvsp[-1].expr).node) ast_add_child(blk, (yyvsp[-1].expr).node);
            (yyval.expr).node = blk;
        }
#line 1436 "parser.tab.c"
    break;

  case 17: /* compound_stmt: LBRACE RBRACE  */
#line 233 "parser.y"
        {
            (yyval.expr).node = ast_new_node("Block(empty)", yylineno);
        }
#line 1444 "parser.tab.c"
    break;

  case 18: /* stmt_list: statement  */
#line 240 "parser.y"
        {
            ASTNode *sl = ast_new_node("StmtList", yylineno);
            if ((yyvsp[0].expr).node) ast_add_child(sl, (yyvsp[0].expr).node);
            (yyval.expr).node = sl;
        }
#line 1454 "parser.tab.c"
    break;

  case 19: /* stmt_list: stmt_list statement  */
#line 246 "parser.y"
        {
            if ((yyvsp[0].expr).node)
                ast_add_child((yyvsp[-1].expr).node, (yyvsp[0].expr).node);
            (yyval.expr).node = (yyvsp[-1].expr).node;
        }
#line 1464 "parser.tab.c"
    break;

  case 20: /* statement: declaration  */
#line 258 "parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 1470 "parser.tab.c"
    break;

  case 21: /* statement: expr_stmt  */
#line 259 "parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 1476 "parser.tab.c"
    break;

  case 22: /* statement: return_stmt  */
#line 260 "parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 1482 "parser.tab.c"
    break;

  case 23: /* statement: if_stmt  */
#line 261 "parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 1488 "parser.tab.c"
    break;

  case 24: /* statement: while_stmt  */
#line 262 "parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 1494 "parser.tab.c"
    break;

  case 25: /* statement: for_stmt  */
#line 263 "parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 1500 "parser.tab.c"
    break;

  case 26: /* statement: compound_stmt  */
#line 264 "parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 1506 "parser.tab.c"
    break;

  case 27: /* statement: KW_BREAK SEMICOLON  */
#line 266 "parser.y"
        {
            (yyval.expr).node = ast_new_node("break", yylineno);
            tac_emit(TAC_GOTO, "BREAK_TARGET", "", "");
        }
#line 1515 "parser.tab.c"
    break;

  case 28: /* statement: KW_CONT SEMICOLON  */
#line 271 "parser.y"
        {
            (yyval.expr).node = ast_new_node("continue", yylineno);
            tac_emit(TAC_GOTO, "CONT_TARGET", "", "");
        }
#line 1524 "parser.tab.c"
    break;

  case 29: /* declaration: type_spec IDENTIFIER SEMICOLON  */
#line 285 "parser.y"
        {
            SymType t = str_to_type((yyvsp[-2].str));
            sem_declare_var((yyvsp[-1].str), t, yylineno);

            ASTNode *decl  = ast_new_node("CodeStatement", yylineno);
            ASTNode *data  = ast_new_node("Data",          yylineno);
            ASTNode *ident = ast_new_node("Identifier",    yylineno);
            ast_add_child(data,  ast_new_node((yyvsp[-2].str), yylineno));
            ast_add_child(ident, ast_new_node((yyvsp[-1].str), yylineno));
            ast_add_child(decl, data);
            ast_add_child(decl, ident);
            (yyval.expr).node = decl;
            free((yyvsp[-2].str)); free((yyvsp[-1].str));
        }
#line 1543 "parser.tab.c"
    break;

  case 30: /* declaration: type_spec IDENTIFIER OP_ASSIGN expression SEMICOLON  */
#line 300 "parser.y"
        {
            SymType t = str_to_type((yyvsp[-4].str));
            sem_declare_var((yyvsp[-3].str), t, yylineno);
            sem_check_assign(t, (SymType)(yyvsp[-1].expr).type, (yyvsp[-3].str), yylineno);
            tac_emit(TAC_ASSIGN, (yyvsp[-3].str), (yyvsp[-1].expr).temp, "");

            ASTNode *decl  = ast_new_node("CodeStatement", yylineno);
            ASTNode *data  = ast_new_node("Data",          yylineno);
            ASTNode *ident = ast_new_node("Identifier",    yylineno);
            ASTNode *eq    = ast_new_node("(=)",           yylineno);
            ASTNode *expr_n= ast_new_node("(Expression)",  yylineno);
            ast_add_child(data,   ast_new_node((yyvsp[-4].str), yylineno));
            ast_add_child(ident,  ast_new_node((yyvsp[-3].str), yylineno));
            ast_add_child(expr_n, (yyvsp[-1].expr).node);
            ast_add_child(eq,     expr_n);
            ast_add_child(decl, data);
            ast_add_child(decl, ident);
            ast_add_child(decl, eq);
            (yyval.expr).node = decl;
            free((yyvsp[-4].str)); free((yyvsp[-3].str));
        }
#line 1569 "parser.tab.c"
    break;

  case 31: /* expr_stmt: expression SEMICOLON  */
#line 329 "parser.y"
        {
            ASTNode *es = ast_new_node("ExprStmt", yylineno);
            ast_add_child(es, (yyvsp[-1].expr).node);
            (yyval.expr).node = es;
            (yyval.expr).type = (yyvsp[-1].expr).type;
        }
#line 1580 "parser.tab.c"
    break;

  case 32: /* expr_stmt: SEMICOLON  */
#line 336 "parser.y"
        {
            (yyval.expr).node = ast_new_node("EmptyStmt", yylineno);
        }
#line 1588 "parser.tab.c"
    break;

  case 33: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 347 "parser.y"
        {
            sem_check_return((SymType)(yyvsp[-1].expr).type, yylineno);
            tac_emit(TAC_RETURN, "", (yyvsp[-1].expr).temp, "");
            ASTNode *ret = ast_new_node("ReturnStmt", yylineno);
            ast_add_child(ret, (yyvsp[-1].expr).node);
            (yyval.expr).node = ret;
        }
#line 1600 "parser.tab.c"
    break;

  case 34: /* return_stmt: KW_RETURN SEMICOLON  */
#line 355 "parser.y"
        {
            sem_check_return(SYM_VOID, yylineno);
            tac_emit(TAC_RETURN, "", "", "");
            (yyval.expr).node = ast_new_node("ReturnStmt(void)", yylineno);
        }
#line 1610 "parser.tab.c"
    break;

  case 35: /* if_stmt: KW_IF LPAREN expression RPAREN statement  */
#line 368 "parser.y"
        {
            sem_check_cond((SymType)(yyvsp[-2].expr).type, yylineno);
            char *lend = tac_new_label();
            tac_emit(TAC_IF_FALSE, lend, (yyvsp[-2].expr).temp, "");
            tac_emit(TAC_LABEL,    lend, "",       "");
            ASTNode *ifs = ast_new_node("IfStmt", yylineno);
            ast_add_child(ifs, (yyvsp[-2].expr).node);
            if ((yyvsp[0].expr).node) ast_add_child(ifs, (yyvsp[0].expr).node);
            (yyval.expr).node = ifs;
        }
#line 1625 "parser.tab.c"
    break;

  case 36: /* if_stmt: KW_IF LPAREN expression RPAREN statement KW_ELSE statement  */
#line 379 "parser.y"
        {
            sem_check_cond((SymType)(yyvsp[-4].expr).type, yylineno);
            char *lfalse = tac_new_label();
            char *lend   = tac_new_label();
            tac_emit(TAC_IF_FALSE, lfalse, (yyvsp[-4].expr).temp, "");
            tac_emit(TAC_GOTO,     lend,   "",       "");
            tac_emit(TAC_LABEL,    lfalse, "",       "");
            tac_emit(TAC_LABEL,    lend,   "",       "");
            ASTNode *ifs = ast_new_node("IfElseStmt", yylineno);
            ast_add_child(ifs, (yyvsp[-4].expr).node);
            if ((yyvsp[-2].expr).node) ast_add_child(ifs, (yyvsp[-2].expr).node);
            if ((yyvsp[0].expr).node) ast_add_child(ifs, (yyvsp[0].expr).node);
            (yyval.expr).node = ifs;
        }
#line 1644 "parser.tab.c"
    break;

  case 37: /* while_stmt: KW_WHILE LPAREN expression RPAREN statement  */
#line 397 "parser.y"
        {
            sem_check_cond((SymType)(yyvsp[-2].expr).type, yylineno);
            char *lstart = tac_new_label();
            char *lend   = tac_new_label();
            tac_emit(TAC_LABEL,    lstart, "",        "");
            tac_emit(TAC_IF_FALSE, lend,   (yyvsp[-2].expr).temp,   "");
            tac_emit(TAC_GOTO,     lstart, "",        "");
            tac_emit(TAC_LABEL,    lend,   "",        "");
            ASTNode *ws = ast_new_node("WhileStmt", yylineno);
            ast_add_child(ws, (yyvsp[-2].expr).node);
            if ((yyvsp[0].expr).node) ast_add_child(ws, (yyvsp[0].expr).node);
            (yyval.expr).node = ws;
        }
#line 1662 "parser.tab.c"
    break;

  case 38: /* for_stmt: KW_FOR LPAREN expr_stmt expression SEMICOLON expression RPAREN statement  */
#line 414 "parser.y"
        {
            sem_check_cond((SymType)(yyvsp[-4].expr).type, yylineno);
            char *lstart = tac_new_label();
            char *lend   = tac_new_label();
            tac_emit(TAC_LABEL,    lstart, "",       "");
            tac_emit(TAC_IF_FALSE, lend,   (yyvsp[-4].expr).temp,  "");
            tac_emit(TAC_GOTO,     lstart, "",       "");
            tac_emit(TAC_LABEL,    lend,   "",       "");
            ASTNode *fs = ast_new_node("ForStmt", yylineno);
            if ((yyvsp[-5].expr).node) ast_add_child(fs, (yyvsp[-5].expr).node);
            ast_add_child(fs, (yyvsp[-4].expr).node);
            ast_add_child(fs, (yyvsp[-2].expr).node);
            if ((yyvsp[0].expr).node) ast_add_child(fs, (yyvsp[0].expr).node);
            (yyval.expr).node = fs;
        }
#line 1682 "parser.tab.c"
    break;

  case 39: /* expression: assignment_expr  */
#line 436 "parser.y"
                      { (yyval.expr) = (yyvsp[0].expr); }
#line 1688 "parser.tab.c"
    break;

  case 40: /* assignment_expr: logical_or_expr  */
#line 440 "parser.y"
                      { (yyval.expr) = (yyvsp[0].expr); }
#line 1694 "parser.tab.c"
    break;

  case 41: /* assignment_expr: IDENTIFIER OP_ASSIGN expression  */
#line 442 "parser.y"
        {
            SymType lhs = sem_check_var((yyvsp[-2].str), yylineno);
            sem_check_assign(lhs, (SymType)(yyvsp[0].expr).type, (yyvsp[-2].str), yylineno);
            tac_emit(TAC_ASSIGN, (yyvsp[-2].str), (yyvsp[0].expr).temp, "");
            ASTNode *as = ast_new_node("Assignment", yylineno);
            ASTNode *eq = ast_new_node("(=)", yylineno);
            ast_add_child(eq, (yyvsp[0].expr).node);
            ast_add_child(as, ast_new_node((yyvsp[-2].str), yylineno));
            ast_add_child(as, eq);
            (yyval.expr).node = as;
            strncpy((yyval.expr).temp, (yyvsp[-2].str), 63);
            (yyval.expr).type = lhs;
            free((yyvsp[-2].str));
        }
#line 1713 "parser.tab.c"
    break;

  case 42: /* assignment_expr: IDENTIFIER OP_PLUSEQ expression  */
#line 457 "parser.y"
        {
            SymType lhs = sem_check_var((yyvsp[-2].str), yylineno);
            char *t = tac_new_temp();
            tac_emit(TAC_ADD,    t,  (yyvsp[-2].str), (yyvsp[0].expr).temp);
            tac_emit(TAC_ASSIGN, (yyvsp[-2].str), t,  "");
            ASTNode *as = ast_new_node("CompoundAssign(+=)", yylineno);
            ast_add_child(as, ast_new_node((yyvsp[-2].str), yylineno));
            ast_add_child(as, (yyvsp[0].expr).node);
            (yyval.expr).node = as; strncpy((yyval.expr).temp, (yyvsp[-2].str), 63); (yyval.expr).type = lhs;
            free((yyvsp[-2].str));
        }
#line 1729 "parser.tab.c"
    break;

  case 43: /* assignment_expr: IDENTIFIER OP_MINEQ expression  */
#line 469 "parser.y"
        {
            SymType lhs = sem_check_var((yyvsp[-2].str), yylineno);
            char *t = tac_new_temp();
            tac_emit(TAC_SUB,    t,  (yyvsp[-2].str), (yyvsp[0].expr).temp);
            tac_emit(TAC_ASSIGN, (yyvsp[-2].str), t,  "");
            ASTNode *as = ast_new_node("CompoundAssign(-=)", yylineno);
            ast_add_child(as, ast_new_node((yyvsp[-2].str), yylineno));
            ast_add_child(as, (yyvsp[0].expr).node);
            (yyval.expr).node = as; strncpy((yyval.expr).temp, (yyvsp[-2].str), 63); (yyval.expr).type = lhs;
            free((yyvsp[-2].str));
        }
#line 1745 "parser.tab.c"
    break;

  case 44: /* logical_or_expr: logical_and_expr  */
#line 483 "parser.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 1751 "parser.tab.c"
    break;

  case 45: /* logical_or_expr: logical_or_expr OP_OR logical_and_expr  */
#line 485 "parser.y"
        {
            SymType t = sem_check_binop((SymType)(yyvsp[-2].expr).type,(SymType)(yyvsp[0].expr).type,"||",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_OR, tmp, (yyvsp[-2].expr).temp, (yyvsp[0].expr).temp);
            ASTNode *n = ast_new_node("(||)", yylineno);
            ast_add_child(n,(yyvsp[-2].expr).node); ast_add_child(n,(yyvsp[0].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=t;
        }
#line 1764 "parser.tab.c"
    break;

  case 46: /* logical_and_expr: equality_expr  */
#line 496 "parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 1770 "parser.tab.c"
    break;

  case 47: /* logical_and_expr: logical_and_expr OP_AND equality_expr  */
#line 498 "parser.y"
        {
            SymType t = sem_check_binop((SymType)(yyvsp[-2].expr).type,(SymType)(yyvsp[0].expr).type,"&&",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_AND, tmp, (yyvsp[-2].expr).temp, (yyvsp[0].expr).temp);
            ASTNode *n = ast_new_node("(&&)", yylineno);
            ast_add_child(n,(yyvsp[-2].expr).node); ast_add_child(n,(yyvsp[0].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=t;
        }
#line 1783 "parser.tab.c"
    break;

  case 48: /* equality_expr: relational_expr  */
#line 509 "parser.y"
                      { (yyval.expr) = (yyvsp[0].expr); }
#line 1789 "parser.tab.c"
    break;

  case 49: /* equality_expr: equality_expr OP_EQ relational_expr  */
#line 511 "parser.y"
        {
            SymType t = sem_check_binop((SymType)(yyvsp[-2].expr).type,(SymType)(yyvsp[0].expr).type,"==",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_EQ, tmp, (yyvsp[-2].expr).temp, (yyvsp[0].expr).temp);
            ASTNode *n = ast_new_node("(==)", yylineno);
            ast_add_child(n,(yyvsp[-2].expr).node); ast_add_child(n,(yyvsp[0].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=t;
        }
#line 1802 "parser.tab.c"
    break;

  case 50: /* equality_expr: equality_expr OP_NEQ relational_expr  */
#line 520 "parser.y"
        {
            SymType t = sem_check_binop((SymType)(yyvsp[-2].expr).type,(SymType)(yyvsp[0].expr).type,"!=",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_NEQ, tmp, (yyvsp[-2].expr).temp, (yyvsp[0].expr).temp);
            ASTNode *n = ast_new_node("(!=)", yylineno);
            ast_add_child(n,(yyvsp[-2].expr).node); ast_add_child(n,(yyvsp[0].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=t;
        }
#line 1815 "parser.tab.c"
    break;

  case 51: /* relational_expr: additive_expr  */
#line 531 "parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 1821 "parser.tab.c"
    break;

  case 52: /* relational_expr: relational_expr OP_LT additive_expr  */
#line 533 "parser.y"
        {
            char *tmp = tac_new_temp();
            tac_emit(TAC_LT, tmp, (yyvsp[-2].expr).temp, (yyvsp[0].expr).temp);
            ASTNode *n = ast_new_node("(<)", yylineno);
            ast_add_child(n,(yyvsp[-2].expr).node); ast_add_child(n,(yyvsp[0].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=SYM_INT;
        }
#line 1833 "parser.tab.c"
    break;

  case 53: /* relational_expr: relational_expr OP_GT additive_expr  */
#line 541 "parser.y"
        {
            char *tmp = tac_new_temp();
            tac_emit(TAC_GT, tmp, (yyvsp[-2].expr).temp, (yyvsp[0].expr).temp);
            ASTNode *n = ast_new_node("(>)", yylineno);
            ast_add_child(n,(yyvsp[-2].expr).node); ast_add_child(n,(yyvsp[0].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=SYM_INT;
        }
#line 1845 "parser.tab.c"
    break;

  case 54: /* relational_expr: relational_expr OP_LTE additive_expr  */
#line 549 "parser.y"
        {
            char *tmp = tac_new_temp();
            tac_emit(TAC_LTE, tmp, (yyvsp[-2].expr).temp, (yyvsp[0].expr).temp);
            ASTNode *n = ast_new_node("(<=)", yylineno);
            ast_add_child(n,(yyvsp[-2].expr).node); ast_add_child(n,(yyvsp[0].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=SYM_INT;
        }
#line 1857 "parser.tab.c"
    break;

  case 55: /* relational_expr: relational_expr OP_GTE additive_expr  */
#line 557 "parser.y"
        {
            char *tmp = tac_new_temp();
            tac_emit(TAC_GTE, tmp, (yyvsp[-2].expr).temp, (yyvsp[0].expr).temp);
            ASTNode *n = ast_new_node("(>=)", yylineno);
            ast_add_child(n,(yyvsp[-2].expr).node); ast_add_child(n,(yyvsp[0].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=SYM_INT;
        }
#line 1869 "parser.tab.c"
    break;

  case 56: /* additive_expr: multiplicative_expr  */
#line 567 "parser.y"
                          { (yyval.expr) = (yyvsp[0].expr); }
#line 1875 "parser.tab.c"
    break;

  case 57: /* additive_expr: additive_expr OP_PLUS multiplicative_expr  */
#line 569 "parser.y"
        {
            SymType t = sem_check_binop((SymType)(yyvsp[-2].expr).type,(SymType)(yyvsp[0].expr).type,"+",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_ADD, tmp, (yyvsp[-2].expr).temp, (yyvsp[0].expr).temp);
            ASTNode *n = ast_new_node("(+)", yylineno);
            ast_add_child(n,(yyvsp[-2].expr).node); ast_add_child(n,(yyvsp[0].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=t;
        }
#line 1888 "parser.tab.c"
    break;

  case 58: /* additive_expr: additive_expr OP_MINUS multiplicative_expr  */
#line 578 "parser.y"
        {
            SymType t = sem_check_binop((SymType)(yyvsp[-2].expr).type,(SymType)(yyvsp[0].expr).type,"-",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_SUB, tmp, (yyvsp[-2].expr).temp, (yyvsp[0].expr).temp);
            ASTNode *n = ast_new_node("(-)", yylineno);
            ast_add_child(n,(yyvsp[-2].expr).node); ast_add_child(n,(yyvsp[0].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=t;
        }
#line 1901 "parser.tab.c"
    break;

  case 59: /* multiplicative_expr: unary_expr  */
#line 589 "parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 1907 "parser.tab.c"
    break;

  case 60: /* multiplicative_expr: multiplicative_expr OP_MUL unary_expr  */
#line 591 "parser.y"
        {
            SymType t = sem_check_binop((SymType)(yyvsp[-2].expr).type,(SymType)(yyvsp[0].expr).type,"*",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_MUL, tmp, (yyvsp[-2].expr).temp, (yyvsp[0].expr).temp);
            ASTNode *n = ast_new_node("(*)", yylineno);
            ast_add_child(n,(yyvsp[-2].expr).node); ast_add_child(n,(yyvsp[0].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=t;
        }
#line 1920 "parser.tab.c"
    break;

  case 61: /* multiplicative_expr: multiplicative_expr OP_DIV unary_expr  */
#line 600 "parser.y"
        {
            SymType t = sem_check_binop((SymType)(yyvsp[-2].expr).type,(SymType)(yyvsp[0].expr).type,"/",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_DIV, tmp, (yyvsp[-2].expr).temp, (yyvsp[0].expr).temp);
            ASTNode *n = ast_new_node("(/)", yylineno);
            ast_add_child(n,(yyvsp[-2].expr).node); ast_add_child(n,(yyvsp[0].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=t;
        }
#line 1933 "parser.tab.c"
    break;

  case 62: /* multiplicative_expr: multiplicative_expr OP_MOD unary_expr  */
#line 609 "parser.y"
        {
            SymType t = sem_check_binop((SymType)(yyvsp[-2].expr).type,(SymType)(yyvsp[0].expr).type,"%",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_MOD, tmp, (yyvsp[-2].expr).temp, (yyvsp[0].expr).temp);
            ASTNode *n = ast_new_node("(%)", yylineno);
            ast_add_child(n,(yyvsp[-2].expr).node); ast_add_child(n,(yyvsp[0].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=t;
        }
#line 1946 "parser.tab.c"
    break;

  case 63: /* unary_expr: postfix_expr  */
#line 620 "parser.y"
                   { (yyval.expr) = (yyvsp[0].expr); }
#line 1952 "parser.tab.c"
    break;

  case 64: /* unary_expr: OP_MINUS unary_expr  */
#line 622 "parser.y"
        {
            char *tmp = tac_new_temp();
            tac_emit(TAC_UMINUS, tmp, (yyvsp[0].expr).temp, "");
            ASTNode *n = ast_new_node("(unary-)", yylineno);
            ast_add_child(n,(yyvsp[0].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=(yyvsp[0].expr).type;
        }
#line 1964 "parser.tab.c"
    break;

  case 65: /* unary_expr: OP_NOT unary_expr  */
#line 630 "parser.y"
        {
            char *tmp = tac_new_temp();
            tac_emit(TAC_NOT, tmp, (yyvsp[0].expr).temp, "");
            ASTNode *n = ast_new_node("(!)", yylineno);
            ast_add_child(n,(yyvsp[0].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=(yyvsp[0].expr).type;
        }
#line 1976 "parser.tab.c"
    break;

  case 66: /* unary_expr: OP_INC IDENTIFIER  */
#line 638 "parser.y"
        {
            SymType t = sem_check_var((yyvsp[0].str), yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_ADD,    tmp, (yyvsp[0].str), "1");
            tac_emit(TAC_ASSIGN, (yyvsp[0].str),  tmp, "");
            ASTNode *n = ast_new_node("(++pre)", yylineno);
            ast_add_child(n, ast_new_node((yyvsp[0].str), yylineno));
            (yyval.expr).node=n; strncpy((yyval.expr).temp,(yyvsp[0].str),63); (yyval.expr).type=t;
            free((yyvsp[0].str));
        }
#line 1991 "parser.tab.c"
    break;

  case 67: /* unary_expr: OP_DEC IDENTIFIER  */
#line 649 "parser.y"
        {
            SymType t = sem_check_var((yyvsp[0].str), yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_SUB,    tmp, (yyvsp[0].str), "1");
            tac_emit(TAC_ASSIGN, (yyvsp[0].str),  tmp, "");
            ASTNode *n = ast_new_node("(--pre)", yylineno);
            ast_add_child(n, ast_new_node((yyvsp[0].str), yylineno));
            (yyval.expr).node=n; strncpy((yyval.expr).temp,(yyvsp[0].str),63); (yyval.expr).type=t;
            free((yyvsp[0].str));
        }
#line 2006 "parser.tab.c"
    break;

  case 68: /* postfix_expr: primary_expr  */
#line 662 "parser.y"
                   { (yyval.expr) = (yyvsp[0].expr); }
#line 2012 "parser.tab.c"
    break;

  case 69: /* postfix_expr: IDENTIFIER OP_INC  */
#line 664 "parser.y"
        {
            SymType t = sem_check_var((yyvsp[-1].str), yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_ASSIGN, tmp, (yyvsp[-1].str), "");
            tac_emit(TAC_ADD,    (yyvsp[-1].str),  (yyvsp[-1].str), "1");
            ASTNode *n = ast_new_node("(post++)", yylineno);
            ast_add_child(n, ast_new_node((yyvsp[-1].str), yylineno));
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=t;
            free((yyvsp[-1].str));
        }
#line 2027 "parser.tab.c"
    break;

  case 70: /* postfix_expr: IDENTIFIER OP_DEC  */
#line 675 "parser.y"
        {
            SymType t = sem_check_var((yyvsp[-1].str), yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_ASSIGN, tmp, (yyvsp[-1].str), "");
            tac_emit(TAC_SUB,    (yyvsp[-1].str),  (yyvsp[-1].str), "1");
            ASTNode *n = ast_new_node("(post--)", yylineno);
            ast_add_child(n, ast_new_node((yyvsp[-1].str), yylineno));
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=t;
            free((yyvsp[-1].str));
        }
#line 2042 "parser.tab.c"
    break;

  case 71: /* postfix_expr: IDENTIFIER LPAREN arg_list RPAREN  */
#line 686 "parser.y"
        {
            SymType t = sem_check_call((yyvsp[-3].str), param_count, yylineno);
            char *tmp = tac_new_temp();
            char cnt[8]; snprintf(cnt,sizeof(cnt),"%d",param_count);
            tac_emit(TAC_CALL, tmp, (yyvsp[-3].str), cnt);
            param_count = 0;
            ASTNode *n = ast_new_node("FunctionCall", yylineno);
            ast_add_child(n, ast_new_node((yyvsp[-3].str), yylineno));
            if ((yyvsp[-1].expr).node) ast_add_child(n, (yyvsp[-1].expr).node);
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=t;
            free((yyvsp[-3].str));
        }
#line 2059 "parser.tab.c"
    break;

  case 72: /* postfix_expr: IDENTIFIER LPAREN RPAREN  */
#line 699 "parser.y"
        {
            SymType t = sem_check_call((yyvsp[-2].str), 0, yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_CALL, tmp, (yyvsp[-2].str), "0");
            ASTNode *n = ast_new_node("FunctionCall", yylineno);
            ast_add_child(n, ast_new_node((yyvsp[-2].str), yylineno));
            (yyval.expr).node=n; strncpy((yyval.expr).temp,tmp,63); (yyval.expr).type=t;
            free((yyvsp[-2].str));
        }
#line 2073 "parser.tab.c"
    break;

  case 73: /* arg_list: expression  */
#line 712 "parser.y"
        {
            tac_emit(TAC_PARAM, "", (yyvsp[0].expr).temp, "");
            param_count = 1;
            ASTNode *al = ast_new_node("ArgList", yylineno);
            ast_add_child(al, (yyvsp[0].expr).node);
            (yyval.expr).node = al;
        }
#line 2085 "parser.tab.c"
    break;

  case 74: /* arg_list: arg_list COMMA expression  */
#line 720 "parser.y"
        {
            tac_emit(TAC_PARAM, "", (yyvsp[0].expr).temp, "");
            param_count++;
            ast_add_child((yyvsp[-2].expr).node, (yyvsp[0].expr).node);
            (yyval.expr).node = (yyvsp[-2].expr).node;
        }
#line 2096 "parser.tab.c"
    break;

  case 75: /* primary_expr: INT_LITERAL  */
#line 730 "parser.y"
        {
            char buf[32];
            snprintf(buf, sizeof(buf), "%d", (yyvsp[0].ival));
            ASTNode *lit = ast_new_node("(Literal)", yylineno);
            ast_add_child(lit, ast_new_node(buf, yylineno));
            (yyval.expr).node=lit; strncpy((yyval.expr).temp,buf,63); (yyval.expr).type=SYM_INT;
        }
#line 2108 "parser.tab.c"
    break;

  case 76: /* primary_expr: FLOAT_LITERAL  */
#line 738 "parser.y"
        {
            ASTNode *lit = ast_new_node("(Literal)", yylineno);
            ast_add_child(lit, ast_new_node((yyvsp[0].str), yylineno));
            (yyval.expr).node=lit; strncpy((yyval.expr).temp,(yyvsp[0].str),63); (yyval.expr).type=SYM_FLOAT;
            free((yyvsp[0].str));
        }
#line 2119 "parser.tab.c"
    break;

  case 77: /* primary_expr: CHAR_LITERAL  */
#line 745 "parser.y"
        {
            ASTNode *lit = ast_new_node("(Literal)", yylineno);
            ast_add_child(lit, ast_new_node((yyvsp[0].str), yylineno));
            (yyval.expr).node=lit; strncpy((yyval.expr).temp,(yyvsp[0].str),63); (yyval.expr).type=SYM_CHAR;
            free((yyvsp[0].str));
        }
#line 2130 "parser.tab.c"
    break;

  case 78: /* primary_expr: IDENTIFIER  */
#line 752 "parser.y"
        {
            SymType t = sem_check_var((yyvsp[0].str), yylineno);
            ASTNode *id = ast_new_node("Identifier", yylineno);
            ast_add_child(id, ast_new_node((yyvsp[0].str), yylineno));
            (yyval.expr).node=id; strncpy((yyval.expr).temp,(yyvsp[0].str),63); (yyval.expr).type=t;
            free((yyvsp[0].str));
        }
#line 2142 "parser.tab.c"
    break;

  case 79: /* primary_expr: LPAREN expression RPAREN  */
#line 760 "parser.y"
        {
            ASTNode *grp = ast_new_node("(grouped)", yylineno);
            ast_add_child(grp, (yyvsp[-1].expr).node);
            (yyval.expr).node=grp; strncpy((yyval.expr).temp,(yyvsp[-1].expr).temp,63); (yyval.expr).type=(yyvsp[-1].expr).type;
        }
#line 2152 "parser.tab.c"
    break;


#line 2156 "parser.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 767 "parser.y"


/* ── Helper: declare function + enter scope ── */
static void begin_function(const char *name, const char *type_str) {
    SymType rt = str_to_type(type_str);
    sem_declare_func(name, rt, yylineno);
    sem_enter_scope();
}

/* ── Syntax error ── */
void yyerror(const char *msg) {
    SYN_ERR(yylineno, "%s", msg);
}
