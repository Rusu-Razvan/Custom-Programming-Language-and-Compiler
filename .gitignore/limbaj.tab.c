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
#line 1 "limbaj.y"

#include <iostream>
#include <vector>
#include <cstring>
#include "SymTable.h"
#include "AST.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class SymTable* current;
class SymTable* classes;
class SymTable* functions;
class SymTable* temp;
std::string current_function;
int errorCount = 0;
std::string current_struct_type;
char error_message[256];

#line 92 "limbaj.tab.c"

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

#include "limbaj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BGIN = 3,                       /* BGIN  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_ASSIGN = 5,                     /* ASSIGN  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_FOR = 8,                        /* FOR  */
  YYSYMBOL_LE = 9,                         /* LE  */
  YYSYMBOL_EQ = 10,                        /* EQ  */
  YYSYMBOL_GE = 11,                        /* GE  */
  YYSYMBOL_AND = 12,                       /* AND  */
  YYSYMBOL_OR = 13,                        /* OR  */
  YYSYMBOL_PRINT = 14,                     /* PRINT  */
  YYSYMBOL_TYPEOF = 15,                    /* TYPEOF  */
  YYSYMBOL_BGINF = 16,                     /* BGINF  */
  YYSYMBOL_BGINC = 17,                     /* BGINC  */
  YYSYMBOL_BGIND = 18,                     /* BGIND  */
  YYSYMBOL_ENDF = 19,                      /* ENDF  */
  YYSYMBOL_ENDC = 20,                      /* ENDC  */
  YYSYMBOL_ENDD = 21,                      /* ENDD  */
  YYSYMBOL_STRUCT = 22,                    /* STRUCT  */
  YYSYMBOL_RETURN = 23,                    /* RETURN  */
  YYSYMBOL_REAL = 24,                      /* REAL  */
  YYSYMBOL_FAKE = 25,                      /* FAKE  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_ID = 27,                        /* ID  */
  YYSYMBOL_TYPE = 28,                      /* TYPE  */
  YYSYMBOL_STRING = 29,                    /* STRING  */
  YYSYMBOL_CHAR = 30,                      /* CHAR  */
  YYSYMBOL_NRFLOAT = 31,                   /* NRFLOAT  */
  YYSYMBOL_NR = 32,                        /* NR  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '*'  */
  YYSYMBOL_36_ = 36,                       /* '/'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* '['  */
  YYSYMBOL_41_ = 41,                       /* ']'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* '@'  */
  YYSYMBOL_46_ = 46,                       /* '<'  */
  YYSYMBOL_47_ = 47,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_progr = 49,                     /* progr  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_sections = 51,                  /* sections  */
  YYSYMBOL_section = 52,                   /* section  */
  YYSYMBOL_globals = 53,                   /* globals  */
  YYSYMBOL_54_2 = 54,                      /* $@2  */
  YYSYMBOL_declarations = 55,              /* declarations  */
  YYSYMBOL_classes = 56,                   /* classes  */
  YYSYMBOL_class_declarations = 57,        /* class_declarations  */
  YYSYMBOL_clas = 58,                      /* clas  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_optional_object_decl = 60,      /* optional_object_decl  */
  YYSYMBOL_class_members = 61,             /* class_members  */
  YYSYMBOL_functions = 62,                 /* functions  */
  YYSYMBOL_function_declarations = 63,     /* function_declarations  */
  YYSYMBOL_decl_class = 64,                /* decl_class  */
  YYSYMBOL_func_class = 65,                /* func_class  */
  YYSYMBOL_66_4 = 66,                      /* $@4  */
  YYSYMBOL_67_5 = 67,                      /* $@5  */
  YYSYMBOL_optional_function_body_class = 68, /* optional_function_body_class  */
  YYSYMBOL_69_6 = 69,                      /* $@6  */
  YYSYMBOL_list_class = 70,                /* list_class  */
  YYSYMBOL_list_param_class = 71,          /* list_param_class  */
  YYSYMBOL_param_class = 72,               /* param_class  */
  YYSYMBOL_func = 73,                      /* func  */
  YYSYMBOL_74_7 = 74,                      /* $@7  */
  YYSYMBOL_75_8 = 75,                      /* $@8  */
  YYSYMBOL_optional_function_body_func = 76, /* optional_function_body_func  */
  YYSYMBOL_77_9 = 77,                      /* $@9  */
  YYSYMBOL_list_func = 78,                 /* list_func  */
  YYSYMBOL_decl = 79,                      /* decl  */
  YYSYMBOL_list_id = 80,                   /* list_id  */
  YYSYMBOL_list_param = 81,                /* list_param  */
  YYSYMBOL_param = 82,                     /* param  */
  YYSYMBOL_main = 83,                      /* main  */
  YYSYMBOL_list = 84,                      /* list  */
  YYSYMBOL_control = 85,                   /* control  */
  YYSYMBOL_86_10 = 86,                     /* $@10  */
  YYSYMBOL_87_11 = 87,                     /* $@11  */
  YYSYMBOL_88_12 = 88,                     /* $@12  */
  YYSYMBOL_89_13 = 89,                     /* $@13  */
  YYSYMBOL_90_14 = 90,                     /* $@14  */
  YYSYMBOL_optional_else = 91,             /* optional_else  */
  YYSYMBOL_92_15 = 92,                     /* $@15  */
  YYSYMBOL_for_init = 93,                  /* for_init  */
  YYSYMBOL_statement = 94,                 /* statement  */
  YYSYMBOL_e = 95,                         /* e  */
  YYSYMBOL_b = 96,                         /* b  */
  YYSYMBOL_reality_check = 97,             /* reality_check  */
  YYSYMBOL_boole = 98,                     /* boole  */
  YYSYMBOL_call_list = 99,                 /* call_list  */
  YYSYMBOL_anye = 100                      /* anye  */
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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   407

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  293

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
      43,    44,    35,    33,    42,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
      46,     2,    47,     2,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    38,    38,    37,    52,    53,    55,    56,    57,    59,
      59,    70,    71,    74,    77,    78,    82,    81,    91,   104,
     111,   112,   113,   114,   116,   119,   120,   123,   131,   146,
     163,   171,   179,   187,   199,   208,   198,   220,   220,   221,
     223,   224,   225,   226,   227,   228,   231,   232,   235,   241,
     253,   240,   264,   264,   265,   267,   268,   269,   270,   271,
     272,   275,   283,   298,   315,   323,   331,   339,   349,   350,
     352,   353,   356,   362,   366,   367,   368,   369,   370,   371,
     375,   380,   374,   386,   389,   385,   395,   394,   403,   403,
     411,   412,   415,   416,   419,   497,   520,   528,   538,   550,
     560,   570,   586,   602,   612,   632,   653,   663,   666,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   745,   758,
     774,   785,   788,   791,   793,   795,   797,   798,   799,   800,
     803,   804,   806,   809,   812,   815,   820,   821,   822,   823,
     825,   833,   847,   848
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
  "\"end of file\"", "error", "\"invalid token\"", "BGIN", "END",
  "ASSIGN", "IF", "WHILE", "FOR", "LE", "EQ", "GE", "AND", "OR", "PRINT",
  "TYPEOF", "BGINF", "BGINC", "BGIND", "ENDF", "ENDC", "ENDD", "STRUCT",
  "RETURN", "REAL", "FAKE", "ELSE", "ID", "TYPE", "STRING", "CHAR",
  "NRFLOAT", "NR", "'+'", "'-'", "'*'", "'/'", "'{'", "'}'", "';'", "'['",
  "']'", "','", "'('", "')'", "'@'", "'<'", "'>'", "$accept", "progr",
  "$@1", "sections", "section", "globals", "$@2", "declarations",
  "classes", "class_declarations", "clas", "$@3", "optional_object_decl",
  "class_members", "functions", "function_declarations", "decl_class",
  "func_class", "$@4", "$@5", "optional_function_body_class", "$@6",
  "list_class", "list_param_class", "param_class", "func", "$@7", "$@8",
  "optional_function_body_func", "$@9", "list_func", "decl", "list_id",
  "list_param", "param", "main", "list", "control", "$@10", "$@11", "$@12",
  "$@13", "$@14", "optional_else", "$@15", "for_init", "statement", "e",
  "b", "reality_check", "boole", "call_list", "anye", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-212)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-132)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     133,    43,    59,  -212,   109,   133,  -212,  -212,  -212,  -212,
      91,    -8,  -212,    97,   144,  -212,     1,  -212,   136,  -212,
     120,  -212,  -212,   134,  -212,  -212,   143,   147,    -3,  -212,
     336,  -212,  -212,  -212,   176,   101,  -212,  -212,   139,   142,
     148,   161,   162,   341,    16,  -212,   326,  -212,   170,   195,
       7,   179,   341,  -212,   197,   217,   341,   341,  -212,   341,
     341,   254,   259,   182,  -212,  -212,  -212,  -212,   341,   266,
    -212,   271,   117,  -212,   341,   260,   341,   277,  -212,  -212,
    -212,   270,  -212,   278,   154,  -212,   290,   292,   255,     7,
       7,   341,    69,     2,   279,   -23,  -212,   266,    63,    70,
     192,   112,    73,   167,    75,   293,   341,   297,   226,   100,
     253,   350,   253,   253,   253,   253,   253,   253,   253,   253,
     341,   341,   266,   117,   285,   266,   117,   168,     8,  -212,
    -212,   195,  -212,   322,    26,   301,  -212,  -212,   -33,  -212,
    -212,    -1,  -212,   217,   300,   302,  -212,   341,   299,  -212,
    -212,  -212,  -212,   288,   188,  -212,  -212,  -212,   253,   213,
    -212,  -212,   213,  -212,   213,   118,   118,  -212,  -212,   213,
     213,   213,  -212,   333,   342,   341,  -212,   341,   341,  -212,
     201,   311,   341,  -212,   320,   217,  -212,   316,  -212,   317,
     321,  -212,  -212,  -212,  -212,    14,  -212,  -212,  -212,    98,
     341,   266,   117,   266,   117,   209,  -212,  -212,  -212,   341,
     232,   113,   319,  -212,   329,  -212,  -212,   341,   336,   336,
     172,   266,   117,  -212,   336,    25,  -212,  -212,     5,   334,
     210,  -212,    32,   336,   336,    17,   318,   280,  -212,  -212,
     328,   330,   339,  -212,  -212,   329,  -212,   344,   340,   347,
     349,  -212,  -212,  -212,   348,  -212,  -212,   341,  -212,   219,
    -212,   362,  -212,   336,  -212,    35,  -212,  -212,  -212,   146,
    -212,   283,   351,   336,  -212,   352,  -212,  -212,   354,   336,
     356,   357,   358,   336,  -212,  -212,   360,   361,   363,   365,
     308,   366,  -212
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     9,     0,     2,     4,     6,     8,     7,
       0,     0,    25,     0,     0,    14,     0,     1,     0,     5,
       0,    24,    26,     0,    13,    15,     0,     0,     0,    11,
       0,     3,    49,    16,     0,     0,    10,    12,     0,     0,
       0,     0,     0,     0,     0,    76,     0,    75,     0,     0,
       0,     0,     0,    61,     0,     0,     0,     0,    86,     0,
       0,   128,   129,   117,   113,   114,   116,   115,     0,   143,
     134,     0,   142,   107,     0,     0,   140,     0,    73,    79,
      78,     0,    74,     0,     0,    70,     0,     0,     0,    20,
      21,   140,     0,     0,     0,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,     0,   136,   137,     0,   103,    77,
      72,     0,    50,     0,     0,    19,    23,    22,     0,    63,
      62,     0,    69,     0,     0,     0,    93,     0,     0,    98,
      97,   100,    99,     0,     0,   119,   112,   135,     0,   124,
     130,   131,   123,   126,   125,   108,   110,   109,   111,   121,
     122,   127,   133,   132,     0,   141,    96,     0,   140,    71,
       0,     0,     0,    27,     0,     0,    34,     0,    17,     0,
       0,    66,    68,    80,    83,     0,    92,   120,   118,     0,
       0,   139,   138,   104,   105,     0,    52,    54,    51,   140,
       0,     0,     0,    31,     0,    18,    67,   140,     0,     0,
       0,   101,   102,   106,     0,     0,    29,    28,     0,     0,
       0,    46,     0,    81,    84,     0,     0,     0,    57,    56,
       0,     0,     0,    32,    48,     0,    35,     0,     0,     0,
       0,    53,    60,    59,     0,    55,    33,   140,    47,     0,
      64,    91,    85,     0,    58,     0,    37,    39,    36,     0,
      82,     0,     0,     0,    88,     0,    87,    30,     0,     0,
      57,    56,     0,     0,    90,    38,    60,    59,     0,    55,
       0,    58,    89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -212,  -212,  -212,  -212,   384,  -212,  -212,  -212,  -212,  -212,
     382,  -212,  -212,    46,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,   155,   390,  -212,  -212,  -212,  -212,
     132,   -16,  -140,  -212,   275,  -212,  -211,   -40,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,   -45,   -20,  -212,   296,
     -10,   -89,  -212
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,    18,     5,     6,     7,    16,    28,     8,    14,
      15,    50,   188,    88,     9,    11,    89,    90,   214,   259,
     268,   273,   278,   230,   231,    12,    49,   180,   208,   224,
     237,    45,    96,    84,    85,    31,    46,    47,   218,   248,
     219,   249,   100,   270,   283,   147,    48,   125,    70,    71,
     126,   127,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    81,   138,   192,   190,   189,    80,   233,   234,   175,
     242,    21,    37,   177,   120,   121,   142,   154,    36,   143,
      10,    74,    74,    69,    26,    27,   120,   121,    26,    27,
      79,   182,    92,    72,    86,    87,    97,    97,   191,   101,
     103,   140,    93,    34,   243,   213,    98,    99,   108,   102,
     104,   178,   271,   220,   122,   148,    75,    75,   109,    76,
      76,    77,    77,   241,   123,   183,   184,   175,   185,   186,
     247,    10,   290,   272,   175,   120,   121,   175,   110,   111,
     112,    13,   120,   121,   146,   120,   121,   120,   121,   205,
     159,   162,   164,   165,   166,   167,   168,   169,   170,   171,
      97,    97,   113,   114,   115,   116,    52,   144,   139,    17,
     172,   173,   120,   121,   145,   117,   118,   150,    20,   152,
     225,   110,   111,   112,    23,   120,   121,    97,   232,   120,
     121,   113,   114,   115,   116,   136,   137,   195,   199,    30,
      53,    54,   156,    55,   157,   113,   114,   115,   116,     1,
       2,     3,   227,   115,   116,   201,   149,   203,   117,   118,
      41,    42,   210,    32,    24,   202,    13,   204,   265,    43,
      34,    33,   211,   235,    35,   236,   110,   111,   112,   240,
     221,    51,    56,   274,   239,    57,    41,    42,    81,    81,
     222,    58,   254,    80,    80,    43,   131,   253,   132,   235,
     113,   114,   115,   116,    59,    60,    41,    42,   238,    82,
     175,   151,   176,   117,   118,    43,    91,    79,    79,    44,
      27,   252,   105,    83,   275,   106,    81,   107,   282,    94,
     175,    80,   198,   281,   288,   110,   111,   112,   206,   287,
     207,   110,   111,   112,    95,    81,   113,   114,   115,   116,
      80,   175,   245,   223,   246,    79,   266,   280,   267,   113,
     114,   115,   116,   286,  -130,   113,   114,   115,   116,  -131,
     156,   226,   117,   118,    79,   110,   111,   112,   117,   118,
      63,   119,    64,    65,    66,    67,    38,    39,    40,    38,
      39,    40,   124,   135,    41,    42,   158,    41,    42,   113,
     114,   115,   116,    43,   128,   130,    43,    44,    27,   129,
      44,    27,   117,   118,    38,    39,    40,   133,   251,   134,
     141,   276,    41,    42,   155,   153,   174,   181,   187,   197,
      78,    43,    38,    39,    40,    44,    27,   193,   196,   194,
      41,    42,    38,    39,    40,   120,   292,   200,   209,    43,
      41,    42,   212,    44,    27,   215,   216,   229,   217,    43,
     228,   244,   250,    44,    27,    61,    62,   255,    63,   256,
      64,    65,    66,    67,   160,   161,   257,    63,   261,    64,
      65,    66,    67,   260,    68,   262,   263,   264,   269,    19,
     277,   284,   285,   158,   -42,   -41,    25,   289,   -45,   -44,
     258,    22,   291,   -40,   -43,   279,   179,   163
};

static const yytype_int16 yycheck[] =
{
      16,    46,    91,   143,     5,    38,    46,   218,   219,    42,
       5,    19,    28,     5,    12,    13,    39,   106,    21,    42,
      28,     5,     5,    43,    27,    28,    12,    13,    27,    28,
      46,     5,    52,    43,    27,    28,    56,    57,    39,    59,
      60,    39,    52,    27,    39,   185,    56,    57,    68,    59,
      60,    43,   263,    39,    74,   100,    40,    40,    68,    43,
      43,    45,    45,    38,    74,    39,    40,    42,    42,    43,
      38,    28,   283,    38,    42,    12,    13,    42,     9,    10,
      11,    22,    12,    13,   100,    12,    13,    12,    13,   178,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    33,    34,    35,    36,     5,    44,    39,     0,
     120,   121,    12,    13,    44,    46,    47,    44,    27,    44,
     209,     9,    10,    11,    27,    12,    13,   147,   217,    12,
      13,    33,    34,    35,    36,    89,    90,   147,   158,     3,
      39,    40,    44,    42,    44,    33,    34,    35,    36,    16,
      17,    18,    39,    35,    36,   175,    44,   177,    46,    47,
      14,    15,   182,    43,    20,   175,    22,   177,   257,    23,
      27,    37,   182,    27,    27,   220,     9,    10,    11,   224,
     200,     5,    43,    37,   224,    43,    14,    15,   233,   234,
     200,    43,   237,   233,   234,    23,    42,   237,    44,    27,
      33,    34,    35,    36,    43,    43,    14,    15,   224,    39,
      42,    44,    44,    46,    47,    23,    37,   233,   234,    27,
      28,   237,    40,    28,   269,    43,   271,    45,   273,    32,
      42,   271,    44,   273,   279,     9,    10,    11,    37,   279,
      39,     9,    10,    11,    27,   290,    33,    34,    35,    36,
     290,    42,    42,    44,    44,   271,    37,   273,    39,    33,
      34,    35,    36,   279,    10,    33,    34,    35,    36,    10,
      44,    39,    46,    47,   290,     9,    10,    11,    46,    47,
      27,    10,    29,    30,    31,    32,     6,     7,     8,     6,
       7,     8,    32,    38,    14,    15,    43,    14,    15,    33,
      34,    35,    36,    23,    27,    27,    23,    27,    28,    39,
      27,    28,    46,    47,     6,     7,     8,    27,    38,    27,
      41,    38,    14,    15,    27,    32,    41,     5,    27,    41,
       4,    23,     6,     7,     8,    27,    28,    37,    39,    37,
      14,    15,     6,     7,     8,    12,    38,     5,    37,    23,
      14,    15,    32,    27,    28,    39,    39,    28,    37,    23,
      41,    27,    44,    27,    28,    24,    25,    39,    27,    39,
      29,    30,    31,    32,    24,    25,    37,    27,    38,    29,
      30,    31,    32,    39,    43,    38,    37,    39,    26,     5,
      39,    39,    38,    43,    38,    38,    14,    39,    38,    38,
     245,    11,    39,    38,    38,   273,   131,   111
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    17,    18,    49,    51,    52,    53,    56,    62,
      28,    63,    73,    22,    57,    58,    54,     0,    50,    52,
      27,    19,    73,    27,    20,    58,    27,    28,    55,    79,
       3,    83,    43,    37,    27,    27,    21,    79,     6,     7,
       8,    14,    15,    23,    27,    79,    84,    85,    94,    74,
      59,     5,     5,    39,    40,    42,    43,    43,    43,    43,
      43,    24,    25,    27,    29,    30,    31,    32,    43,    95,
      96,    97,    98,   100,     5,    40,    43,    45,     4,    79,
      85,    94,    39,    28,    81,    82,    27,    28,    61,    64,
      65,    37,    95,    98,    32,    27,    80,    95,    98,    98,
      90,    95,    98,    95,    98,    40,    43,    45,    95,    98,
       9,    10,    11,    33,    34,    35,    36,    46,    47,    10,
      12,    13,    95,    98,    32,    95,    98,    99,    27,    39,
      27,    42,    44,    27,    27,    38,    61,    61,    99,    39,
      39,    41,    39,    42,    44,    44,    79,    93,    94,    44,
      44,    44,    44,    32,    99,    27,    44,    44,    43,    95,
      24,    25,    95,    97,    95,    95,    95,    95,    95,    95,
      95,    95,    98,    98,    41,    42,    44,     5,    43,    82,
      75,     5,     5,    39,    40,    42,    43,    27,    60,    38,
       5,    39,    80,    37,    37,    98,    39,    41,    44,    95,
       5,    95,    98,    95,    98,    99,    37,    39,    76,    37,
      95,    98,    32,    80,    66,    39,    39,    37,    86,    88,
      39,    95,    98,    44,    77,    99,    39,    39,    41,    28,
      71,    72,    99,    84,    84,    27,    94,    78,    79,    85,
      94,    38,     5,    39,    27,    42,    44,    38,    87,    89,
      44,    38,    79,    85,    94,    39,    39,    37,    72,    67,
      39,    38,    38,    37,    39,    99,    37,    39,    68,    26,
      91,    84,    38,    69,    37,    94,    38,    39,    70,    78,
      79,    85,    94,    92,    39,    38,    79,    85,    94,    39,
      84,    39,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    50,    49,    51,    51,    52,    52,    52,    54,
      53,    55,    55,    56,    57,    57,    59,    58,    60,    60,
      61,    61,    61,    61,    62,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    66,    67,    65,    69,    68,    68,
      70,    70,    70,    70,    70,    70,    71,    71,    72,    74,
      75,    73,    77,    76,    76,    78,    78,    78,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    80,    80,
      81,    81,    82,    83,    84,    84,    84,    84,    84,    84,
      86,    87,    85,    88,    89,    85,    90,    85,    92,    91,
      91,    91,    93,    93,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    98,    98,    98,    98,    99,    99,    99,    99,
      99,    99,   100,   100
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     1,     2,     1,     1,     1,     0,
       4,     1,     2,     3,     1,     2,     0,     7,     2,     0,
       1,     1,     2,     2,     3,     1,     2,     3,     5,     5,
      10,     4,     6,     7,     0,     0,     8,     0,     4,     1,
       2,     1,     1,     3,     2,     2,     1,     3,     2,     0,
       0,     8,     0,     4,     1,     2,     1,     1,     3,     2,
       2,     3,     5,     5,    10,     4,     6,     7,     3,     2,
       1,     3,     2,     3,     2,     1,     1,     3,     2,     2,
       0,     0,    10,     0,     0,     9,     0,    11,     0,     5,
       3,     0,     2,     1,     3,     3,     4,     4,     4,     4,
       4,     6,     6,     3,     5,     5,     6,     2,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     4,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     3,     3,     1,     3,     1,     1,     3,     3,
       0,     2,     1,     1
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
  case 2: /* $@1: %empty  */
#line 38 "limbaj.y"
          {                          
          current = new SymTable("main", current); 
          cout << "Am intrat în scope-ul lui main \n";
          }
#line 1403 "limbaj.tab.c"
    break;

  case 3: /* progr: sections $@1 main  */
#line 42 "limbaj.y"
                {
               //current->printVars();
               cout << "Am iesit din scope-ul main-ului \n";
               current = current->getParent();
               //current->printVars();
               //current = current->getParent();
               cout << "Am iesit din global\n";
               if (errorCount == 0) cout<< "The program is correct!" << endl;}
#line 1416 "limbaj.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 59 "limbaj.y"
                { 
                    //cout << "Am intrat în scope-ul variabilelor globale \n";
                }
#line 1424 "limbaj.tab.c"
    break;

  case 10: /* globals: BGIND $@2 declarations ENDD  */
#line 63 "limbaj.y"
               {
               //current->printVars();             
               //cout << "Am iesit din scope-ul variabilelor global \n";
          }
#line 1433 "limbaj.tab.c"
    break;

  case 16: /* $@3: %empty  */
#line 82 "limbaj.y"
                    {
                         current_struct_type = (yyvsp[-1].string);
                         classes->addClass((yyvsp[-1].string),(yyvsp[-1].string));
                         //classes = new SymTable($2, classes); 
                         cout << "Am intrat în scope-ul clasei \"" << (yyvsp[-1].string) << "\"\n";
                    }
#line 1444 "limbaj.tab.c"
    break;

  case 18: /* optional_object_decl: ID ';'  */
#line 91 "limbaj.y"
                             {   
                                   //current->printVars();
                                   cout << "Am iesit din scope-ul clasei " << current_struct_type << "\n";
                                   //current=current->getParent();
                               if(!current->existsId((yyvsp[-1].string))) {
                                    
                                    current->addClass(current_struct_type.c_str(),(yyvsp[-1].string));
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                              }
#line 1461 "limbaj.tab.c"
    break;

  case 19: /* optional_object_decl: %empty  */
#line 104 "limbaj.y"
                         {  
                                   //current->printVars();
                                   cout << "Am iesit din scope-ul clasei " << current_struct_type << " \n";
                         //current=current->getParent();
                         }
#line 1471 "limbaj.tab.c"
    break;

  case 27: /* decl_class: TYPE ID ';'  */
#line 123 "limbaj.y"
                             { 
                              if(!classes->existsIdRecursive((yyvsp[-1].string))) {
                                    classes->addClassParam((yyvsp[-2].string),(yyvsp[-1].string),current_struct_type);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined\n");
                              }
                          }
#line 1484 "limbaj.tab.c"
    break;

  case 28: /* decl_class: TYPE ID ASSIGN boole ';'  */
#line 131 "limbaj.y"
                                          { 
                              if(!classes->existsIdRecursive((yyvsp[-3].string))) {
                                (yyvsp[-1].node)->evaluate();
                                if(strcmp((yyvsp[-4].string),(yyvsp[-1].node)->type.c_str())==0){
                                    classes->addClassParam((yyvsp[-4].string),(yyvsp[-3].string),current_struct_type,(yyvsp[-1].node)->evaluate());
                                }
                                else{
                                    errorCount++;
                                    yyerror("Can only assign real or fake to bool value");
                                }
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined\n");
                              }
                          }
#line 1504 "limbaj.tab.c"
    break;

  case 29: /* decl_class: TYPE ID ASSIGN e ';'  */
#line 146 "limbaj.y"
                                      { 
                              if(!classes->existsIdRecursive((yyvsp[-3].string))) {
                                    (yyvsp[-1].node)->evaluate();
                                    if(strcmp((yyvsp[-4].string),(yyvsp[-1].node)->type.c_str())==0){
                                    classes->addClassParam((yyvsp[-4].string),(yyvsp[-3].string),current_struct_type,(yyvsp[-1].node)->evaluate());
                                    }
                                    else{
                                        errorCount++;
                                        yyerror("Can't define variable with a different type of value!");
                                    }
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                            delete((yyvsp[-1].node));
                          }
#line 1525 "limbaj.tab.c"
    break;

  case 30: /* decl_class: TYPE ID '[' NR ']' ASSIGN '{' call_list '}' ';'  */
#line 163 "limbaj.y"
                                                               { 
                              if(!classes->existsIdRecursive((yyvsp[-8].string))) {
                                    classes->addClassParam((yyvsp[-9].string),(yyvsp[-8].string),current_struct_type);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
#line 1538 "limbaj.tab.c"
    break;

  case 31: /* decl_class: TYPE ID ',' list_id  */
#line 171 "limbaj.y"
                                     { 
                              if(!classes->existsIdRecursive((yyvsp[-2].string))) {
                                    classes->addClassParam((yyvsp[-3].string),(yyvsp[-2].string),current_struct_type);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
#line 1551 "limbaj.tab.c"
    break;

  case 32: /* decl_class: TYPE ID '[' NR ']' ';'  */
#line 179 "limbaj.y"
                                       { 
                              if(!classes->existsIdRecursive((yyvsp[-4].string))) {
                                    classes->addClassParam((yyvsp[-5].string),(yyvsp[-4].string),current_struct_type);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
#line 1564 "limbaj.tab.c"
    break;

  case 33: /* decl_class: ID ID ASSIGN '{' call_list '}' ';'  */
#line 187 "limbaj.y"
                                                    { 
                              if(!classes->existsIdRecursive((yyvsp[-5].string))) {
                                    classes->addClassParam((yyvsp[-6].string),(yyvsp[-5].string),current_struct_type);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
#line 1577 "limbaj.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 199 "limbaj.y"
                         {        
                            current_function = (yyvsp[-1].string);
                              if(!classes->existsIdRecursive((yyvsp[-1].string))) {
                                   classes->addClassParam((yyvsp[-2].string),(yyvsp[-1].string),current_struct_type);
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
#line 1591 "limbaj.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 208 "limbaj.y"
                                              {
                                   classes = new SymTable((yyvsp[-4].string), classes);
                                    cout << "Am intrat in scope-ul funcției \"" << (yyvsp[-4].string) << "\"\n";
                         }
#line 1600 "limbaj.tab.c"
    break;

  case 36: /* func_class: TYPE ID '(' $@4 list_param_class ')' $@5 optional_function_body_class  */
#line 213 "limbaj.y"
                         {   
                              //classes->printVars();             
                              cout << "Am iesit din scope-ul funcției \"" << (yyvsp[-6].string) << "\"\n";
                              classes = classes->getParent(); 
                              }
#line 1610 "limbaj.tab.c"
    break;

  case 37: /* $@6: %empty  */
#line 220 "limbaj.y"
                                    {temp = current; current = classes; }
#line 1616 "limbaj.tab.c"
    break;

  case 38: /* optional_function_body_class: '{' $@6 list_class '}'  */
#line 220 "limbaj.y"
                                                                                         {current = temp;}
#line 1622 "limbaj.tab.c"
    break;

  case 48: /* param_class: TYPE ID  */
#line 235 "limbaj.y"
                       { 
                    classes->addParamsToClassFunc((yyvsp[-1].string),(yyvsp[0].string),current_struct_type,current_function,"0");
                       
                }
#line 1631 "limbaj.tab.c"
    break;

  case 49: /* $@7: %empty  */
#line 241 "limbaj.y"
                         {        
                            current_function = (yyvsp[-1].string);
                            cout<<current_function;
                              if(!functions->existsIdRecursive((yyvsp[-1].string))) {
                                   functions->addFunc((yyvsp[-2].string),(yyvsp[-1].string));
                                    cout << "Am intrat in scope-ul funcției \"" << (yyvsp[-1].string) << "\"\n";
                                    
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
#line 1648 "limbaj.tab.c"
    break;

  case 50: /* $@8: %empty  */
#line 253 "limbaj.y"
                                        {
                                   functions = new SymTable((yyvsp[-4].string), functions);
                         }
#line 1656 "limbaj.tab.c"
    break;

  case 51: /* func: TYPE ID '(' $@7 list_param ')' $@8 optional_function_body_func  */
#line 257 "limbaj.y"
                         {   
                              functions->printVars();             
                              cout << "Am iesit din scope-ul funcției \"" << (yyvsp[-6].string) << "\"\n";
                              functions = functions->getParent(); 
                              }
#line 1666 "limbaj.tab.c"
    break;

  case 52: /* $@9: %empty  */
#line 264 "limbaj.y"
                                   { temp = current; current = functions;}
#line 1672 "limbaj.tab.c"
    break;

  case 53: /* optional_function_body_func: '{' $@9 list_func '}'  */
#line 264 "limbaj.y"
                                                                                         {current = temp;}
#line 1678 "limbaj.tab.c"
    break;

  case 61: /* decl: TYPE ID ';'  */
#line 275 "limbaj.y"
                             { 
                              if(!current->existsId((yyvsp[-1].string))) {
                                    current->addVar((yyvsp[-2].string),(yyvsp[-1].string));
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined\n");
                              }
                          }
#line 1691 "limbaj.tab.c"
    break;

  case 62: /* decl: TYPE ID ASSIGN boole ';'  */
#line 283 "limbaj.y"
                                          { 
                              if(!current->existsId((yyvsp[-3].string))) {
                                (yyvsp[-1].node)->evaluate();
                                if(strcmp((yyvsp[-4].string),(yyvsp[-1].node)->type.c_str())==0){
                                    current->addVar((yyvsp[-4].string),(yyvsp[-3].string),(yyvsp[-1].node)->evaluate());
                                }
                                else{
                                    errorCount++;
                                    yyerror("Can only assign real or fake to bool value");
                                }
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined\n");
                              }
                          }
#line 1711 "limbaj.tab.c"
    break;

  case 63: /* decl: TYPE ID ASSIGN e ';'  */
#line 298 "limbaj.y"
                                      { 
                              if(!current->existsId((yyvsp[-3].string))) {
                                    (yyvsp[-1].node)->evaluate();
                                    if(strcmp((yyvsp[-4].string),(yyvsp[-1].node)->type.c_str())==0){
                                        current->addVar((yyvsp[-4].string),(yyvsp[-3].string),(yyvsp[-1].node)->evaluate());
                                    }
                                    else{
                                        errorCount++;
                                        yyerror("Can't define variable with a different type of value!");
                                    }
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                            delete((yyvsp[-1].node));
                          }
#line 1732 "limbaj.tab.c"
    break;

  case 64: /* decl: TYPE ID '[' NR ']' ASSIGN '{' call_list '}' ';'  */
#line 315 "limbaj.y"
                                                               { 
                              if(!current->existsId((yyvsp[-8].string))) {
                                    current->addVar((yyvsp[-9].string),(yyvsp[-8].string));
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
#line 1745 "limbaj.tab.c"
    break;

  case 65: /* decl: TYPE ID ',' list_id  */
#line 323 "limbaj.y"
                                     { 
                              if(!current->existsId((yyvsp[-2].string))) {
                                    current->addVar((yyvsp[-3].string),(yyvsp[-2].string));
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
#line 1758 "limbaj.tab.c"
    break;

  case 66: /* decl: TYPE ID '[' NR ']' ';'  */
#line 331 "limbaj.y"
                                       { 
                              if(!current->existsId((yyvsp[-4].string))) {
                                    current->addVar((yyvsp[-5].string),(yyvsp[-4].string));
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
#line 1771 "limbaj.tab.c"
    break;

  case 67: /* decl: ID ID ASSIGN '{' call_list '}' ';'  */
#line 339 "limbaj.y"
                                                    { 
                              if(!current->existsId((yyvsp[-5].string))) {
                                    current->addVar((yyvsp[-6].string),(yyvsp[-5].string));
                              } else {
                                   errorCount++; 
                                   yyerror("Variable already defined");
                              }
                          }
#line 1784 "limbaj.tab.c"
    break;

  case 72: /* param: TYPE ID  */
#line 356 "limbaj.y"
                { 
                    functions->addFuncParam((yyvsp[-1].string),(yyvsp[0].string),current_function);
                }
#line 1792 "limbaj.tab.c"
    break;

  case 80: /* $@10: %empty  */
#line 375 "limbaj.y"
                                   {current = new SymTable("if block", current); 
                                   cout << "Am intrat în scope-ul unui if block \n";}
#line 1799 "limbaj.tab.c"
    break;

  case 81: /* $@11: %empty  */
#line 380 "limbaj.y"
                                   {//current->printVars();             
                                   cout << "Am iesit din scope-ul if block-ului\n";
                                   current = current->getParent();}
#line 1807 "limbaj.tab.c"
    break;

  case 83: /* $@12: %empty  */
#line 386 "limbaj.y"
                                        {current = new SymTable("while block", current); 
                                        cout << "Am intrat în scope-ul unui while block \n";}
#line 1814 "limbaj.tab.c"
    break;

  case 84: /* $@13: %empty  */
#line 389 "limbaj.y"
                                        {//current->printVars();             
                                        cout << "Am iesit din scope-ul while block-ului\n";
                                        current = current->getParent();}
#line 1822 "limbaj.tab.c"
    break;

  case 86: /* $@14: %empty  */
#line 395 "limbaj.y"
                         {current = new SymTable("for block", current); 
                         cout << "Am intrat în scope-ul unui for block \n";}
#line 1829 "limbaj.tab.c"
    break;

  case 87: /* control: FOR '(' $@14 for_init boole ';' statement ')' '{' list '}'  */
#line 398 "limbaj.y"
                          {//current->printVars();   
                         cout << "Am iesit din scope-ul for block-ului\n";
                          current = current->getParent();}
#line 1837 "limbaj.tab.c"
    break;

  case 88: /* $@15: %empty  */
#line 403 "limbaj.y"
                         {
                    current = new SymTable("else block", current); 
                   cout << "Am intrat în scope-ul unui else block \n";
            }
#line 1846 "limbaj.tab.c"
    break;

  case 89: /* optional_else: ELSE '{' $@15 list '}'  */
#line 407 "limbaj.y"
                    {
               cout << "Am iesit din scope-ul else block-ului\n";
                current = current->getParent();
            }
#line 1855 "limbaj.tab.c"
    break;

  case 94: /* statement: ID ASSIGN e  */
#line 419 "limbaj.y"
                        {
        (yyvsp[0].node)->evaluate();
        if(current->getRoot() == "global"){
            if (!current->existsIdRecursive((yyvsp[-2].string))) {
              errorCount++;
              yyerror("Variable used before definition");
            }
          else {
            if((yyvsp[0].node)->evaluate() == "invalid") {
                errorCount++;
                yyerror("Expression is invalid");
            }
            else{
                if(current->getType((yyvsp[-2].string)) == (yyvsp[0].node)->type ){
                    current->changeValue((yyvsp[-2].string), (yyvsp[0].node)->evaluate());
                }
                else{
                    errorCount++;
                    snprintf(error_message,256,"Attempting to assign value of type %s to variable of type %s!",current->getType((yyvsp[-2].string)).c_str(),(yyvsp[0].node)->type.c_str());
                    yyerror(error_message);
                }
            }
          }
        }
        else if(current->getRoot() == "functions"){
            if(temp->existsIdRecursive((yyvsp[-2].string))){
                if(temp->getType((yyvsp[-2].string)) == (yyvsp[0].node)->type){
                    temp->changeValue((yyvsp[-2].string),(yyvsp[0].node)->evaluate());
                }
                else{
                    errorCount++;
                    snprintf(error_message,256,"Attempting to assign value of type %s to variable of type %s!",current->getType((yyvsp[-2].string)).c_str(),(yyvsp[0].node)->type.c_str());
                    yyerror(error_message);
                }            }
            if(!current->existsIdFunction((yyvsp[-2].string),current_function)){
              errorCount++;
              yyerror("Variable used before definition");
            }
            else{
                if(current->getTypeFunction((yyvsp[-2].string),current_function) == (yyvsp[0].node)->type){
                   current->changeValueFunction((yyvsp[-2].string),(yyvsp[0].node)->evaluate(),current_function);
                }
                else{
                    errorCount++;
                    snprintf(error_message,256,"Attempting to assign value of type %s to variable of type %s!", (yyvsp[0].node)->type.c_str(), current->getTypeFunction((yyvsp[-2].string),current_function).c_str());
                    yyerror(error_message);
                }
            }
        }
        else if(current->getRoot() == "classes"){
            if(current->existsIdInClass((yyvsp[-2].string), current_struct_type)){
                if(current->getTypeInClass((yyvsp[-2].string),current_struct_type) == (yyvsp[0].node)->type){
                    current->changeValueInClass((yyvsp[-2].string),(yyvsp[0].node)->evaluate(),current_struct_type);
                }
                else{
                    errorCount++;
                    snprintf(error_message,256,"Attempting to assign value of type %s to variable of type %s!", (yyvsp[0].node)->type.c_str(), current->getTypeInClass((yyvsp[-2].string),current_struct_type).c_str());
                    yyerror(error_message);
                }
            }
            else if(current->existsIdInClassFunc((yyvsp[-2].string), current_struct_type,current_function)){
                if(current->getTypeInClassFunc((yyvsp[-2].string),current_struct_type,current_function) == (yyvsp[0].node)->type){
                    //current->changeValueInClassFunc($1,$3->evaluate(),current_struct_type,current_function);
                }
                else{
                    errorCount++;
                    snprintf(error_message,256,"Attempting to assign value of type %s to variable of type %s!", (yyvsp[0].node)->type.c_str(), current->getTypeInClassFunc((yyvsp[-2].string),current_struct_type,current_function).c_str());
                    yyerror(error_message);
                }
            }
            else{
                errorCount++;
                yyerror("Variable used before definition");
            }
        }
    
            delete((yyvsp[0].node));
}
#line 1938 "limbaj.tab.c"
    break;

  case 95: /* statement: ID ASSIGN boole  */
#line 497 "limbaj.y"
                            {if (!current->existsIdRecursive((yyvsp[-2].string))) {
              errorCount++;
              yyerror("Variable used before definition");
          }
        else {
            if((yyvsp[0].node)->evaluate() == "invalid") {
                errorCount++;
                yyerror("Expression is invalid");
            }
            else{
                if(current->getType((yyvsp[-2].string)) == (yyvsp[0].node)->type ){
                    current->changeValue((yyvsp[-2].string), (yyvsp[0].node)->evaluate());
                }
                else{
                    errorCount++;
                    snprintf(error_message,256,"Attempting to assign value of type %s to variable of type %s!\n",current->getType((yyvsp[-2].string)).c_str(),(yyvsp[0].node)->type.c_str());
                    yyerror(error_message);
                }
            }
            delete((yyvsp[0].node));
          }
      }
#line 1965 "limbaj.tab.c"
    break;

  case 96: /* statement: ID '(' call_list ')'  */
#line 520 "limbaj.y"
                                 {
            if(!classes->existsIdInClass((yyvsp[-3].string),current_struct_type) && !functions->existsIdRecursive((yyvsp[-3].string))){

              errorCount++;
              yyerror("Function used before definition");
            }

      }
#line 1978 "limbaj.tab.c"
    break;

  case 97: /* statement: PRINT '(' boole ')'  */
#line 528 "limbaj.y"
                                {
            if((yyvsp[-1].node)->evaluate() == "invalid") {
                errorCount++;
                yyerror("Expression is invalid.");
            }
            else{
                printf("Value of expression is %s\n", (yyvsp[-1].node)->evaluate().c_str());
                delete((yyvsp[-1].node));
            }
          }
#line 1993 "limbaj.tab.c"
    break;

  case 98: /* statement: PRINT '(' e ')'  */
#line 538 "limbaj.y"
                            {
            if((yyvsp[-1].node)->evaluate() == "invalid") {
                errorCount++;
                yyerror("Expression is invalid.");
            }
            else{
                printf("Value of expression is %s\n", (yyvsp[-1].node)->evaluate().c_str());
                delete((yyvsp[-1].node));
            }
            
            
          }
#line 2010 "limbaj.tab.c"
    break;

  case 99: /* statement: TYPEOF '(' boole ')'  */
#line 550 "limbaj.y"
                                 {
            if((yyvsp[-1].node)->evaluate() == "invalid") {
                errorCount++;
                yyerror("Expression is invalid.");
            }
            else{
                std::cout << "Value of expression is " << (yyvsp[-1].node)->evaluate() << " and type is " << (yyvsp[-1].node)->type << std::endl;
                delete((yyvsp[-1].node));
            }
          }
#line 2025 "limbaj.tab.c"
    break;

  case 100: /* statement: TYPEOF '(' e ')'  */
#line 560 "limbaj.y"
                            {
            if((yyvsp[-1].node)->evaluate() == "invalid") {
                errorCount++;
                yyerror("Expression is invalid.");
            }
            else{
                std::cout << "Value of expression is " << (yyvsp[-1].node)->evaluate() << " and type is " << (yyvsp[-1].node)->type << std::endl;
                delete((yyvsp[-1].node));
            }
          }
#line 2040 "limbaj.tab.c"
    break;

  case 101: /* statement: ID '[' NR ']' ASSIGN e  */
#line 570 "limbaj.y"
                                   {
          if (!current->existsIdRecursive((yyvsp[-5].string))) {
              errorCount++;
              yyerror("Array used before definition");
          }
                  else {
            if((yyvsp[0].node)->evaluate() == "invalid"){
                errorCount++;
                yyerror("Expression is invalid.");
            }
            else{
            current->changeValue((yyvsp[-5].string), (yyvsp[0].node)->evaluate());
            delete((yyvsp[0].node));
            }
          }
      }
#line 2061 "limbaj.tab.c"
    break;

  case 102: /* statement: ID '[' NR ']' ASSIGN boole  */
#line 586 "limbaj.y"
                                        {
          if (!current->existsIdRecursive((yyvsp[-5].string))) {
              errorCount++;
              yyerror("Array used before definition");
          }
                  else {
            if((yyvsp[0].node)->evaluate() == "invalid"){
                errorCount++;
                yyerror("Expression is invalid.");
            }
            else{
            current->changeValue((yyvsp[-5].string), (yyvsp[0].node)->evaluate());
            delete((yyvsp[0].node));
            }
          }
      }
#line 2082 "limbaj.tab.c"
    break;

  case 103: /* statement: ID '@' ID  */
#line 602 "limbaj.y"
                      {
          if (!current->existsIdRecursive((yyvsp[-2].string))) {
              errorCount++;
              yyerror("Object used before definition");
          }
          if (!current->existsIdRecursive((yyvsp[0].string))) {
              errorCount++;
              yyerror("Member used before definition");
          }
      }
#line 2097 "limbaj.tab.c"
    break;

  case 104: /* statement: ID '@' ID ASSIGN e  */
#line 612 "limbaj.y"
                               {
          if (!current->existsIdRecursive((yyvsp[-4].string))) {
              errorCount++;
              yyerror("Object used before definition");
          }
          else if (!current->existsIdRecursive((yyvsp[-2].string))) {
              errorCount++;
              yyerror("Member used before definition");
          }
          else {
                if((yyvsp[0].node)->evaluate() == "invalid"){
                    errorCount++;
                    yyerror("Expression is invalid");
                }
                else{
                    current->changeValue((yyvsp[-4].string), (yyvsp[0].node)->evaluate());
                    delete((yyvsp[0].node));
                }
          }
      }
#line 2122 "limbaj.tab.c"
    break;

  case 105: /* statement: ID '@' ID ASSIGN boole  */
#line 632 "limbaj.y"
                                   {
          if (!current->existsIdRecursive((yyvsp[-4].string))) {
              errorCount++;
              yyerror("Object used before definition");
              current->changeValue((yyvsp[-4].string), (yyvsp[0].node)->evaluate());
          }
          else if (!current->existsIdRecursive((yyvsp[-2].string))) {
              errorCount++;
              yyerror("Member used before definition");
          }
          else {
                if((yyvsp[0].node)->evaluate() == "invalid"){
                    errorCount++;
                    yyerror("Expression is invalid");
                }
                else{
                    current->changeValue((yyvsp[-4].string), (yyvsp[0].node)->evaluate());
                    delete((yyvsp[0].node));
                }
          }
      }
#line 2148 "limbaj.tab.c"
    break;

  case 106: /* statement: ID '@' ID '(' call_list ')'  */
#line 653 "limbaj.y"
                                        {
          if (!current->existsIdRecursive((yyvsp[-5].string))) {
              errorCount++;
              yyerror("Object used before definition");
          }
          if (!current->existsIdRecursive((yyvsp[-3].string))) {
              errorCount++;
              yyerror("Method used before definition");
          }
      }
#line 2163 "limbaj.tab.c"
    break;

  case 108: /* e: e '+' e  */
#line 666 "limbaj.y"
               {/*$$=$1+$3; */(yyval.node) = new ASTNode((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->value = "+"; }
#line 2169 "limbaj.tab.c"
    break;

  case 109: /* e: e '*' e  */
#line 667 "limbaj.y"
               {/*$$=$1*$3;*/(yyval.node) = new ASTNode((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->value = "*"; }
#line 2175 "limbaj.tab.c"
    break;

  case 110: /* e: e '-' e  */
#line 668 "limbaj.y"
               {/*$$ = $1-$3;*/ (yyval.node) = new ASTNode((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) -> value = "-"; }
#line 2181 "limbaj.tab.c"
    break;

  case 111: /* e: e '/' e  */
#line 669 "limbaj.y"
               {/*$$ = $1/$3;*/ (yyval.node) = new ASTNode((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) -> value = '/'; }
#line 2187 "limbaj.tab.c"
    break;

  case 112: /* e: '(' e ')'  */
#line 670 "limbaj.y"
               {/*$$= $2;*/ (yyval.node) = (yyvsp[-1].node);    }
#line 2193 "limbaj.tab.c"
    break;

  case 113: /* e: STRING  */
#line 671 "limbaj.y"
               { (yyval.node) = new ASTNode((yyvsp[0].string), "string");}
#line 2199 "limbaj.tab.c"
    break;

  case 114: /* e: CHAR  */
#line 672 "limbaj.y"
               { (yyval.node) = new ASTNode((yyvsp[0].string), "char");}
#line 2205 "limbaj.tab.c"
    break;

  case 115: /* e: NR  */
#line 673 "limbaj.y"
               {/*$$=$1;*/  (yyval.node) = new ASTNode((yyvsp[0].Int),"int"); }
#line 2211 "limbaj.tab.c"
    break;

  case 116: /* e: NRFLOAT  */
#line 674 "limbaj.y"
               {/*$$=$1;*/  (yyval.node) = new ASTNode((yyvsp[0].string),"float"); }
#line 2217 "limbaj.tab.c"
    break;

  case 117: /* e: ID  */
#line 675 "limbaj.y"
               { 
    if(current->getRoot() == "global"){
        if (!current->existsIdRecursive((yyvsp[0].string))) {
              errorCount++;
              snprintf(error_message,256,"Variable used before definition:%s", (yyvsp[0].string));
              (yyval.node) = new ASTNode("invalid","null");
              yyerror(error_message);
        }
        else if(current->getValueAsString((yyvsp[0].string)) == "invalid"){
            errorCount++;
            snprintf(error_message,256,"Use of variable %s with invalid value!", (yyvsp[0].string));
              (yyval.node) = new ASTNode("invalid","null");
                yyerror(error_message);
        }
        else{
            (yyval.node) = new ASTNode(current->getValueAsString((yyvsp[0].string)), current->getType((yyvsp[0].string)));
        }
    }
    else if(current->getRoot() == "functions"){
        if(temp->existsIdRecursive((yyvsp[0].string))){
            if(temp->getValueAsString((yyvsp[0].string)) == "invalid"){
                errorCount++;
                snprintf(error_message,256,"Use of variable %s with invalid value!", (yyvsp[0].string));
                (yyval.node) = new ASTNode("invalid","null");
                yyerror(error_message);
            }
            else{
                (yyval.node) = new ASTNode(temp->getValueAsString((yyvsp[0].string)), temp->getType((yyvsp[0].string)));
            }
        }
        else if(!current->existsIdFunction((yyvsp[0].string),current_function)){
              errorCount++;
              snprintf(error_message,256,"Variable used before definitions:%s", (yyvsp[0].string));
              (yyval.node) = new ASTNode("invalid","null");
              yyerror(error_message);
        }
        else if(current->getValueFunction((yyvsp[0].string),current_function) == "invalid"){
            errorCount++;
            snprintf(error_message,256,"Use of variable %s with invalid value!", (yyvsp[0].string));
            (yyval.node) = new ASTNode("invalid","null");
            yyerror(error_message);
        }
        else{
            (yyval.node) = new ASTNode(current->getValueFunction((yyvsp[0].string), current_function), current->getTypeFunction((yyvsp[0].string),current_function));
        }
    }
    else if(current->getRoot() == "classes"){
            if(current->getValueInClass((yyvsp[0].string),current_struct_type) == "invalid") {
                errorCount++;
                snprintf(error_message,256,"Use of variable %s with invalid value!", (yyvsp[0].string));
                (yyval.node) = new ASTNode("invalid", "null");
                yyerror(error_message);
            }
            else{
                if(current->existsIdInClass((yyvsp[0].string),current_struct_type)){
                    (yyval.node) = new ASTNode(current->getValueInClass((yyvsp[0].string), current_struct_type), current->getTypeInClass((yyvsp[0].string),current_struct_type));
                }
                else if (current->existsIdInClassFunc((yyvsp[0].string), current_struct_type, current_function)){
                    (yyval.node) = new ASTNode("0", "int");
                }
                else {
                    errorCount++;
                snprintf(error_message,256,"Use of uninitialized variable %s", (yyvsp[0].string));
                (yyval.node) = new ASTNode("invalid","null");
                yyerror(error_message);
                }
            }
    }
}
#line 2291 "limbaj.tab.c"
    break;

  case 118: /* e: ID '(' call_list ')'  */
#line 745 "limbaj.y"
                         {
        if(strcmp((yyvsp[-3].string),current_function.c_str()) == 0){
            (yyval.node) = new ASTNode(1, functions->getType((yyvsp[-3].string)));
        }
        else if (!functions->existsIdRecursive((yyvsp[-3].string)) && !classes->existsIdInClass((yyvsp[-3].string),current_struct_type)) {
              errorCount++;
              yyerror("Variable used before definition");
            (yyval.node) = new ASTNode("invalid","null");
          }
          else {
            (yyval.node) = new ASTNode(1, functions->getType((yyvsp[-3].string)));
            }
  }
#line 2309 "limbaj.tab.c"
    break;

  case 119: /* e: ID '@' ID  */
#line 758 "limbaj.y"
               {
            if (!current->existsIdRecursive((yyvsp[-2].string))) {
              errorCount++;
              yyerror("Variable used before definition");
              (yyval.node) = new ASTNode("invalid","null");            }
            else {
                //cout<<"!!!!!!!!!!!!1"<<$3<< ' '<<current->getType($1)<<endl;
                if(classes->existsIdInClass((yyvsp[0].string),current->getType((yyvsp[-2].string)))){
                    (yyval.node) = new ASTNode(1, classes->getTypeInClass((yyvsp[0].string),current->getType((yyvsp[-2].string))));
                }
                else{
                    errorCount++;
                    yyerror("Variable not in class");
              (yyval.node) = new ASTNode("invalid","null");                }
            }
            }
#line 2330 "limbaj.tab.c"
    break;

  case 120: /* e: ID '[' NR ']'  */
#line 774 "limbaj.y"
                    {
        if (!current->existsIdRecursive((yyvsp[-3].string))) {
              errorCount++;
              yyerror("Variable used before definition");
          }
         (yyval.node) = new ASTNode(1, current->getType((yyvsp[-3].string)));
         }
#line 2342 "limbaj.tab.c"
    break;

  case 121: /* b: e '<' e  */
#line 785 "limbaj.y"
            { 
        (yyval.node) = new ASTNode((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->value = "<"; 
  }
#line 2350 "limbaj.tab.c"
    break;

  case 122: /* b: e '>' e  */
#line 788 "limbaj.y"
            { 
    (yyval.node) = new ASTNode((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->value = ">";   
    }
#line 2358 "limbaj.tab.c"
    break;

  case 123: /* b: e EQ e  */
#line 791 "limbaj.y"
            { 
    (yyval.node) = new ASTNode((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->value = "==";   }
#line 2365 "limbaj.tab.c"
    break;

  case 124: /* b: e LE e  */
#line 793 "limbaj.y"
            { 
    (yyval.node) = new ASTNode((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->value = "<=";   }
#line 2372 "limbaj.tab.c"
    break;

  case 125: /* b: e GE e  */
#line 795 "limbaj.y"
            { 
    (yyval.node) = new ASTNode((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->value = ">=";   }
#line 2379 "limbaj.tab.c"
    break;

  case 126: /* b: e EQ reality_check  */
#line 797 "limbaj.y"
                       { (yyval.node) = new ASTNode((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->value = "==";}
#line 2385 "limbaj.tab.c"
    break;

  case 127: /* b: reality_check EQ e  */
#line 798 "limbaj.y"
                       { (yyval.node) = new ASTNode((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->value = "==";}
#line 2391 "limbaj.tab.c"
    break;

  case 128: /* b: REAL  */
#line 799 "limbaj.y"
            {    (yyval.node) = new ASTNode("real","bool");  }
#line 2397 "limbaj.tab.c"
    break;

  case 129: /* b: FAKE  */
#line 800 "limbaj.y"
            {  (yyval.node) = new ASTNode("fake","bool");   }
#line 2403 "limbaj.tab.c"
    break;

  case 130: /* reality_check: REAL  */
#line 803 "limbaj.y"
                         {    (yyval.node) = new ASTNode("real","bool");  }
#line 2409 "limbaj.tab.c"
    break;

  case 131: /* reality_check: FAKE  */
#line 804 "limbaj.y"
                      {  (yyval.node) = new ASTNode("fake","bool");   }
#line 2415 "limbaj.tab.c"
    break;

  case 132: /* boole: boole OR boole  */
#line 806 "limbaj.y"
                       { 
    (yyval.node) = new ASTNode((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->value = "||";
        }
#line 2423 "limbaj.tab.c"
    break;

  case 133: /* boole: boole AND boole  */
#line 809 "limbaj.y"
                        {
    (yyval.node) = new ASTNode((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)->value = "&&";
        }
#line 2431 "limbaj.tab.c"
    break;

  case 134: /* boole: b  */
#line 812 "limbaj.y"
          {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2439 "limbaj.tab.c"
    break;

  case 135: /* boole: '(' boole ')'  */
#line 815 "limbaj.y"
                      {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 2447 "limbaj.tab.c"
    break;

  case 140: /* call_list: %empty  */
#line 825 "limbaj.y"
          { if(current->getRoot() == "global"){
            cout<<current->ids[current_function].params.parameters.size()<<endl;
            if(current->ids[current_function].params.parameters.size() != 0){
                errorCount++;
                yyerror("Invalid function call");
            }
            }
          }
#line 2460 "limbaj.tab.c"
    break;

  case 141: /* call_list: call_list ','  */
#line 833 "limbaj.y"
                            {
            if(current->getRoot() == "global"){
                if(functions->ids[current_function].params.parameters.size() != 0){
                    errorCount++;
                    yyerror("Invalid function call");
                }   
            }
            else if(current->getRoot() == "functions" || current->getRoot() == "classes"){
                errorCount++;
                yyerror("Cannot declare function without a variable at the end");
            }
            }
#line 2477 "limbaj.tab.c"
    break;


#line 2481 "limbaj.tab.c"

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

#line 850 "limbaj.y"

void yyerror(const char * s){
     cout << "error:" << s << " at line: " << yylineno << endl;
}

int main(int argc, char** argv){
     ofstream fout("SymTables.txt",std::ios::trunc);
     yyin=fopen(argv[1],"r");
     current = new SymTable("global",nullptr);
     classes = new SymTable("classes",nullptr);
     functions = new SymTable("functions", nullptr);
     cout << "Am intrat in scope-ul global\n";
     yyparse();
     current->printVars();
     classes->printVars();
     functions->printVars();
     delete current;
     delete classes;
     delete functions;
}
