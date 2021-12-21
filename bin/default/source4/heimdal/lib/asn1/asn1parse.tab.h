/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_ASN1PARSE_TAB_H_INCLUDED
# define YY_YY_ASN1PARSE_TAB_H_INCLUDED
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
    kw_ABSENT = 258,
    kw_ABSTRACT_SYNTAX = 259,
    kw_ALL = 260,
    kw_APPLICATION = 261,
    kw_AUTOMATIC = 262,
    kw_BEGIN = 263,
    kw_BIT = 264,
    kw_BMPString = 265,
    kw_BOOLEAN = 266,
    kw_BY = 267,
    kw_CHARACTER = 268,
    kw_CHOICE = 269,
    kw_CLASS = 270,
    kw_COMPONENT = 271,
    kw_COMPONENTS = 272,
    kw_CONSTRAINED = 273,
    kw_CONTAINING = 274,
    kw_DEFAULT = 275,
    kw_DEFINITIONS = 276,
    kw_EMBEDDED = 277,
    kw_ENCODED = 278,
    kw_END = 279,
    kw_ENUMERATED = 280,
    kw_EXCEPT = 281,
    kw_EXPLICIT = 282,
    kw_EXPORTS = 283,
    kw_EXTENSIBILITY = 284,
    kw_EXTERNAL = 285,
    kw_FALSE = 286,
    kw_FROM = 287,
    kw_GeneralString = 288,
    kw_GeneralizedTime = 289,
    kw_GraphicString = 290,
    kw_IA5String = 291,
    kw_IDENTIFIER = 292,
    kw_IMPLICIT = 293,
    kw_IMPLIED = 294,
    kw_IMPORTS = 295,
    kw_INCLUDES = 296,
    kw_INSTANCE = 297,
    kw_INTEGER = 298,
    kw_INTERSECTION = 299,
    kw_ISO646String = 300,
    kw_MAX = 301,
    kw_MIN = 302,
    kw_MINUS_INFINITY = 303,
    kw_NULL = 304,
    kw_NumericString = 305,
    kw_OBJECT = 306,
    kw_OCTET = 307,
    kw_OF = 308,
    kw_OPTIONAL = 309,
    kw_ObjectDescriptor = 310,
    kw_PATTERN = 311,
    kw_PDV = 312,
    kw_PLUS_INFINITY = 313,
    kw_PRESENT = 314,
    kw_PRIVATE = 315,
    kw_PrintableString = 316,
    kw_REAL = 317,
    kw_RELATIVE_OID = 318,
    kw_SEQUENCE = 319,
    kw_SET = 320,
    kw_SIZE = 321,
    kw_STRING = 322,
    kw_SYNTAX = 323,
    kw_T61String = 324,
    kw_TAGS = 325,
    kw_TRUE = 326,
    kw_TYPE_IDENTIFIER = 327,
    kw_TeletexString = 328,
    kw_UNION = 329,
    kw_UNIQUE = 330,
    kw_UNIVERSAL = 331,
    kw_UTCTime = 332,
    kw_UTF8String = 333,
    kw_UniversalString = 334,
    kw_VideotexString = 335,
    kw_VisibleString = 336,
    kw_WITH = 337,
    RANGE = 338,
    EEQUAL = 339,
    ELLIPSIS = 340,
    IDENTIFIER = 341,
    referencename = 342,
    STRING = 343,
    NUMBER = 344
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

    int constant;
    struct value *value;
    struct range *range;
    char *name;
    Type *type;
    Member *member;
    struct objid *objid;
    char *defval;
    struct string_list *sl;
    struct tagtype tag;
    struct memhead *members;
    struct constraint_spec *constraint_spec;


};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASN1PARSE_TAB_H_INCLUDED  */
