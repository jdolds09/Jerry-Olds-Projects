# Olds, Jerry
# jdo3643
# 2020-05-10
#-----------------------------------------------------------
import logging
import math
import random
import sys

import ply
import ply.yacc
import ply.lex

from pathlib          import Path
from time             import localtime, strftime, time

from Dump             import Dump
from Exceptions       import *
from Roman            import Roman

#-----------------------------------------------------------
# Lexical analysis section.

# Reserved words
reserved = {
  'and' : 'AND_LOGICAL',
  'or'  : 'OR_LOGICAL',
  'not' : 'NOT_LOGICAL',
  }

reserved.update( { rw : rw.upper() for rw in (
  'exit',
  'if', 'then', 'else', 'end',
  'while', 'do',
  'break', 'continue',
  'read', 'write',
  'int', 'real' ) } )

# Token categories
tokens = [
  'INTEGER_LITERAL',
  'REAL_LITERAL',
  'STRING_LITERAL',
  'ID',

  'LPAREN', 'RPAREN',
  'SEMICOLON',
  'COMMA',

  'AND_BITWISE',
  'ASSIGN',
  'DIVIDE',
  'EQUAL',
  'EXPONENTIATION',
  'FACTORIAL',
  'GREATER',
  'GREATER_EQUAL',
  'LESS',
  'LESS_EQUAL',
  'MINUS',
  'MODULUS',
  'MULTIPLY',
  'NOT_BITWISE',
  'NOT_EQUAL',
  'OR_BITWISE',
  'PLUS',
  'RANDOM',
  'SQUARE_ROOT',
  'XOR_BITWISE',
  ] + list( reserved.values() )

# Token definitions
t_EQUAL          = r'=='
t_GREATER_EQUAL  = r'>='
t_LESS_EQUAL     = r'<='
t_NOT_EQUAL      = r'<>'

t_AND_BITWISE    = r'&'
t_ASSIGN         = r'='
t_DIVIDE         = r'/'
t_EXPONENTIATION = r'\^'
t_FACTORIAL      = r'!'
t_GREATER        = r'>'
t_LESS           = r'<'
t_MINUS          = r'-'
t_MODULUS        = r'%'
t_MULTIPLY       = r'\*'
t_NOT_BITWISE    = r'~'
t_OR_BITWISE     = r'\|'
t_PLUS           = r'\+'
t_RANDOM         = r'\?'
t_SQUARE_ROOT    = r'\$'
t_XOR_BITWISE    = r'\#'

t_COMMA          = r','
t_LPAREN         = r'\('
t_RPAREN         = r'\)'
t_SEMICOLON      = r';'

def t_ID( t ) :
  r'[_a-zA-Z][_a-zA-Z0-9]*'
  num = Roman.fromRoman( t.value )

  if t.value in reserved :
    t.type = reserved[ t.value ]

  elif num is None :
    t.type = 'ID'

  else :
    t.type = 'INTEGER_LITERAL'
    t.value = num

  return t

def t_REAL_LITERAL( t ) :
  r'(\d+[eE][-+]?\d+)|((\d*((\.\d)|(\d\.))\d*)([eE][-+]?\d+)?)'
  t.value = float(t.value)
  return t

def t_INTEGER_LITERAL( t ) :
  r'(0b[01]+)|(0o[0-7]+)|(0x[0-9a-fA-F]+)|(\d+)'

  baseInfo = { '0b' : 2, '0o' : 8, '0x' : 16 }
  base = 10

  if len( t.value ) > 2 and t.value[0:2] in baseInfo :
    base = baseInfo[ t.value[0:2] ]
    t.value = t.value[2:]

  t.value = int(t.value, base )

  return t

def t_STRING_LITERAL( t ) :
  '"[^"\n]*"'
  t.value = t.value[1:-1]
  return t

#-------------------------------------------------
# Things that don't return tokens
#-------------------------------------------------

# Ignored characters
t_ignore = ' \t\f\r\v'

# Comment to EOL
def t_comment( _ ) :
  '@[^\n]*'

# New lines have to be counted so error messages are accurate
def t_newline( t ) :
  r'\n+'
  t.lexer.lineno += t.value.count("\n")

#-------------------
def t_error( t ) :
  # Go through elaborate shennanigans to determine the column
  # at which the lexical error occurred.
  lineStart = t.lexer.lexdata.rfind('\n', 0, t.lexer.lexpos) + 1
  column = t.lexer.lexpos - lineStart + 1

  msg = f'Illegal character "{t.value[0]}" at line {t.lexer.lineno}, column {column}.'

  raise LexicalError( msg )

#-----------------------------------------------------------
# Syntactic section.

#-------------------
# The start symbol.
start = 'program'

#-------------------
# Precedence rules for the arithmetic operators
precedence = (
  # TODO: Using the information from the ASL description, replace
  #       the following line with the proper 13 lines ofTODO
  #       precedence / associativity definitions.
  ( 'left', 'OR_LOGICAL'),
  ( 'left', 'AND_LOGICAL'),
  ( 'left', 'OR_BITWISE'),
  ( 'left', 'XOR_BITWISE'),
  ( 'left', 'AND_BITWISE'),
  ( 'left', 'EQUAL', 'NOT_EQUAL'),
  ( 'left', 'LESS', 'LESS_EQUAL', 'GREATER', 'GREATER_EQUAL'),
  ( 'left', 'RANDOM'),
  ( 'left', 'PLUS', 'MINUS'),
  ( 'left', 'MULTIPLY', 'DIVIDE', 'MODULUS'),
  ( 'left', 'EXPONENTIATION'),
  ( 'right', 'UMINUS', 'UPLUS', 'NOT_BITWISE', 'NOT_LOGICAL'),
  ( 'left', 'FACTORIAL', 'SQUARE_ROOT'),
  )

#---------------------------------------
# PROGRAM ...
def p_program( p ) :
  'program : statement_list'
  p[0] = ( 'BLOCK', p[1] )

#---------------------------------------
# STATEMENTS ...

# ASSIGN statement
def p_statement_assign( p ) :
  'statement : ID ASSIGN expression'
  p[0] = ( 'ASSIGN', p[1], p[3] )

# BREAK statement
def p_statement_break( p ) :
  # TODO: Production rule for the BREAK statement.
  'statement : BREAK'
  # TODO: Parse form construction for the BREAK statement.
  p[0] = ( 'BREAK', )

# CONTINUE statement
def p_statement_continue( p ) :
  # TODO: Production rule for the CONTINUE statement.
  'statement : CONTINUE'
  # TODO: Parse form construction for the CONTINUE statement.
  p[0] = ( 'CONTINUE', )

# DECLARATION statement
def p_statement_declaration( p ) :
  # TODO: Production rule for the DECLARATION statement.
  #       Don't forget that the initializer expression is
  #         optional.
  '''statement : INT ID 
               | REAL ID'''
  # TODO: Parse form construction for the DECLARATION statement.
  #       If the initializer was omitted, construct a default one
  #         that takes the type into account.
  if(p[1] == 'int'):
      p[0] = ('DECLARATION', 'INT', p[2], ('LITERAL', 'INT', 0))
  if(p[1] == 'real'):
      p[0] = ('DECLARATION', 'REAL', p[2], ('LITERAL', 'REAL', 0.0))

def p_initializer_opt( p ) :
  # TODO: Production rule for the optional initializer expression.
  # TODO: Parse form construction for the optional initializer
  #         expression.
  '''statement : INT ID ASSIGN expression
               | REAL ID ASSIGN expression'''
  #       The result should be None if the expression is omitted
  #         and the given expression otherwise.
  if(p[1] == 'int'):
      p[0] = ('DECLARATION', 'INT', p[2], p[4])
  if(p[1] == 'real'):
      p[0] = ('DECLARATION', 'REAL', p[2], p[4])
  
# EXIT statement
def p_statement_exit_A( p ) :
  # TODO: Production rule for the EXIT statement WITHOUT an
  #         expression.
  'statement : EXIT'
  # TODO: Parse form construction for the EXIT statement WITHOUT
  #         an expression.  Construct a default expression (the
  #         integer literal zero) instead.
  p[0] = ( 'EXIT', ('LITERAL', 'INT', 0) )

def p_statement_exit_B( p ) :
  # TODO: Production rule for the EXIT statement WITH an
  #         expression.
  'statement : EXIT expression'
  # TODO: Parse form construction for the EXIT statement WITH an
  #         an expression.  Use the given expression for the
  #         EXIT expression.
  p[0] = ( 'EXIT', p[2] )

# IF statement
def p_statement_if( p ) :
  # TODO: Production rule for the IF statement. Don't forget that
  #         the ELSE portion is optional.
  'statement : IF expression THEN statement_list END IF'
  # TODO: Parse form construction for the IF statement.
  #       There are four cases:
  #         (1) If both the THEN part and the ELSE part have
  #             statements, generate an IF parse form with the
  #             test expression and BLOCKs for the THEN and ELSE
  #             parts.
  #         (2) If the THEN part has statements but the ELSE part
  #             doesn't, generate an IF-NO-ELSE parse form with
  #             the test expression and a BLOCK for the THEN part.
  #         (3) If the ELSE part has statements but the THEN part
  #             doesn't, generate an IF-NO-ELSE parse form with
  #             an INVERTED test expression (use the NOT_LOGICAL
  #             unary operator) and a BLOCK for the ELSE part now
  #             being the THEN part.
  #         (4) If neither part has statements, generate a NOOP
  #             parse form and ignore the test expression.
  if(len(p[4]) == 0):
      p[0] = ( 'NOOP', )
  else:
      p[0] = ( 'IF-NO-ELSE', p[2], ('BLOCK', p[4]) )
  

def p_else_opt( p ) :
  # TODO: Production rule for the optional ELSE part.
  'statement : IF expression THEN statement_list ELSE statement_list END IF'
  # TODO: Parse form construction for the optional ELSE part.
  #       The result should be None if the ELSE part is omitted
  #         and the statement list otherwise.

  if(len(p[4]) == 0 and len(p[6]) == 0):
      p[0] = ( 'NOOP',  )

  elif(len(p[4]) == 0):
      p[0] = ( 'IF-NO-ELSE', ('UNOP', 'NOT_LOGICAL', p[2]), ('BLOCK', p[6]) )

  elif(len(p[6]) == 0):
      p[0] = ( 'IF-NO-ELSE', p[2], ('BLOCK', p[4]) )

  else:
      p[0] = ( 'IF', p[2], ('BLOCK', p[4]), ('BLOCK', p[6]) )

# READ statement
def p_statement_read( p ) :
  # TODO: Production rule for the READ statement.  (Use id_list to
  #         get the list of IDs.)
  'statement : READ LPAREN id_list RPAREN'
  # TODO: Parse form construction for the READ statement.
  p[0] = ( 'READ', p[3] )

# WHILE statement
def p_statement_while( p ) :
  # TODO: Production rule for the WHILE statement.
  'statement : WHILE expression DO statement_list END WHILE'
  # TODO: Parse form construction for the WHILE statement.
  if(len(p[4]) == 0):
      p[0] = ( 'NOOP', )
  else:
      p[0] = ( 'WHILE', p[2], ('BLOCK', p[4]))

# WRITE statement
def p_statement_write( p ) :
  # TODO: Production rule for the WRITE statement.  (Use
  #         expression_list to get the list of expressions.)
  'statement : WRITE LPAREN expression_list RPAREN'
  # TODO: Parse form construction for the WRITE statement.
  p[0] = ( 'WRITE', p[3])
#---------------------------------------
# EXPRESSION ...
def p_expression_binop( p ) :
  '''expression : expression AND_BITWISE expression
                | expression AND_LOGICAL expression
                | expression DIVIDE expression
                | expression EQUAL expression
                | expression EXPONENTIATION expression
                | expression GREATER expression
                | expression GREATER_EQUAL expression
                | expression LESS expression
                | expression LESS_EQUAL expression
                | expression MINUS expression
                | expression MODULUS expression
                | expression MULTIPLY expression
                | expression NOT_EQUAL expression
                | expression OR_BITWISE expression
                | expression OR_LOGICAL expression
                | expression PLUS expression
                | expression RANDOM expression
                | expression XOR_BITWISE expression'''
  # TODO: Parse form construction for a BINOP.
  if p[2] == '&' :
      p[0] = ('BINOP', '&', p[1], p[3])
  
  elif p[2] == '|' :
      p[0] = ('BINOP', '|', p[1], p[3])

  elif p[2] == '#' :
      p[0] = ('BINOP', '#', p[1], p[3])

  elif p[2] == '?' :
      if(p[1] > p[3]): 
          p[0] = ('BINOP', '?', p[3], p[1])
      else:
	      p[0] = ('BINOP', '?', p[1], p[3])

  elif p[2] == '>' :
      p[0] = ('BINOP', '>', p[1], p[3])

  elif p[2] == '<' :
      p[0] = ('BINOP', '<', p[1], p[3])

  elif p[2] == '>=' :
      p[0] = ('BINOP', '>=', p[1], p[3])

  elif p[2] == '<=' :
      p[0] = ('BINOP', '<=', p[1], p[3])

  elif p[2] == '==' :
      p[0] = ('BINOP', '==', p[1], p[3])

  elif p[2] == '<>' :
      p[0] = ('BINOP', '<>', p[1], p[3])

  elif p[2] == 'and' :
      p[0] = ('BINOP', 'and', p[1], p[3])

  elif p[2] == 'or' :
      p[0] = ('BINOP', 'or', p[1], p[3])

  elif p[2] == '+' : p[0] = ('BINOP', '+', p[1], p[3])
  elif p[2] == '-' : p[0] = ('BINOP', '-', p[1], p[3])
  elif p[2] == '*' : p[0] = ('BINOP', '*', p[1], p[3])
  elif p[2] == '/' : p[0] = ('BINOP', '/', p[1], p[3])
  elif p[2] == '%' : p[0] = ('BINOP', '%', p[1], p[3])
  elif p[2] == '^' : p[0] = ('BINOP', '^', p[1], p[3])
  else : pass


def p_expression_unop_prefix( p ) :
  '''expression : MINUS expression %prec UMINUS
                | PLUS expression %prec UPLUS
                | NOT_BITWISE expression
                | NOT_LOGICAL expression'''
  # TODO: Parse form construction for a UNOP.
  if   p[1] == '-' : p[0] = ('UNOP', '-', p[2])
  elif p[1] == '+' : p[0] = ('UNOP', '+', p[2])
  elif p[1] == '~' : 
      p[0] = ('UNOP', '~', p[2])

  elif p[1] == 'not' : p[0] = ('UNOP', 'NOT_LOGICAL', p[2])
  else: pass

def p_expression_unop_suffix( p ) :
  '''expression : expression FACTORIAL
                | expression SQUARE_ROOT'''
  # TODO: Parse form construction for a UNOP.
  if p[2] == '!' : p[0] = ('UNOP', '!', p[1])
  elif p[2] == '$' : p[0] = ('UNOP', '$', p[1])
  else: pass

def p_expression_group( p ) :
  'expression : LPAREN expression RPAREN'
  p[0] = p[2]

def p_expression_literal( p ) :
  '''expression : INTEGER_LITERAL
                | REAL_LITERAL
                | STRING_LITERAL'''
  # TODO: Parse form construction for a LITERAL.
  if(isinstance(p[1], int)):
      p[0] = ( 'LITERAL', 'INT', p[1] )
  elif(isinstance(p[1], float)):
      p[0] = ( 'LITERAL', 'REAL', p[1] )
  else:
      p[0] = ( 'LITERAL', 'STRING', p[1] )

def p_expression_name( p ) :
  'expression : ID'
  p[0] = ( 'ID', p[1] )

#---------------------------------------
# LISTS ...

# EXPRESSION list
def p_expression_list_A1( p ) :
  'expression_list : epsilon'
  p[0] = []

def p_expression_list_A2( p ) :
  'expression_list : expression_list_B'
  p[0] = p[1]

def p_expression_list_B1( p ) :
  'expression_list_B : expression'
  p[0] = [ p[1] ]

def p_expression_list_B2( p ) :
  'expression_list_B : expression_list_B COMMA expression'
  p[1].append( p[3] )
  p[0] = p[1]

# ID list
def p_id_list_A( p ) :
  'id_list : ID'
  p[0] = [ p[1] ]

def p_id_list_B( p ) :
  'id_list : id_list COMMA ID'
  p[1].append( p[3] )
  p[0] = p[1]

# STATEMENT list
def p_statement_list_A1( p ) :
  'statement_list : epsilon'
  p[0] = []

def p_statement_list_A2( p ) :
  'statement_list : statement_list_C'
  p[0] = p[1]

def p_statement_list_C1( p ) :
  'statement_list_C : statement'
  p[0] = [ p[1] ]

def p_statement_list_C2( p ) :
  'statement_list_C : statement_list_C SEMICOLON statement'
  p[1].append( p[3] )
  p[0] = p[1]

#-------------------
# The 'empty' value.  It's possible to just have an empty RHS
# in a production, but having the non-terminal 'epsilon' makes
# it much more obvious that the empty string is being parsed.
def p_epsilon( p ) :
  'epsilon :'
  p[0] = None

#-------------------
# Gets called if an unexpected token (or the EOF) is seen during
# a parse.  We throw an exception
def p_error( p ) :
  msg = 'Syntax error at '
  if p is None :
    msg += 'EOF.'

  else :
    # Go through elaborate shennanigans to determine the column
    # at which the parse error occurred.
    lineStart = p.lexer.lexdata.rfind('\n', 0, p.lexpos) + 1
    column = p.lexpos - lineStart + 1

    msg += f'token "{p.value}", line {p.lineno}, column {column}'

  raise SyntacticError( msg )

#-----------------------------------------------------------
def _main( inputFileName ) :
  debug = True
  logging.basicConfig(
    level = logging.DEBUG,
    filename = 'parselog.txt',
    filemode = 'w',
    format = '%(filename)10s:%(lineno)4d:%(message)s'
  )

  log = logging.getLogger()

  begin = time()
  timestamp = strftime( '%Y-%m-%d %H:%M:%S', localtime( begin ) )

  fileName  = str( Path( inputFileName ).name )
  parseFile = str( Path( inputFileName ).with_suffix( '.parse' ) )
  ASTFile   = str( Path( inputFileName ).with_suffix( '.ast' ) )
  ASMFile   = str( Path( inputFileName ).with_suffix( '.s' ) )

  print( f'#----------\n# Begin at {timestamp}' )
  print( f'# Reading source file {inputFileName!r} ...' )

  try :
    strt = time()
    with open( inputFileName, 'r' ) as fp :
      data = fp.read()

    print( f'#    Read succeeded.  ({time()-strt:.3f}s)' )
    print( f'# Beginning parse ...' )

    strt    = time()
    lexer   = ply.lex.lex( debug = debug, debuglog = log )
    parser  = ply.yacc.yacc( debug = debug, debuglog = log )

    program = parser.parse( data, tracking = True, debug = log )

    print( f'#    Parse succeeded.  ({time()-strt:.3f}s)' )
    print( f'# Beginning parse tree dump to {parseFile!r} ...' )

    strt = time()
    with open( parseFile, 'w' ) as fp :
      Dump.dumpProgram( program, indent = 0, fp = fp )

    print( f'#    Parse dumped.  ({time()-strt:.3f}s)' )

    finish = time()
    total = finish - begin
    timestamp = strftime( '%Y-%m-%d %H:%M:%S', localtime( finish ) )
    print( f'# End at {timestamp}' )
    print( f'# Total time {total:.3f}s.\n#----------')

  except FileNotFoundError as e :
    print( f'File {inputFileName!r} not found.' )
    print( f'*** Compilation of {inputFileName!r} failed.' )
    sys.exit( 1 )

  except LexicalError as e :
    print( 'Exception detected during lexical analysis.' )
    print( e )
    #traceback.print_exc()
    print( f'*** Compilation of {inputFileName!r} failed.' )
    sys.exit( 1 )

  except SyntacticError as e :
    print( 'Exception detected during syntactic analysis.' )
    print( e )
    #traceback.print_exc()
    print( f'*** Compilation of {inputFileName!r} failed.' )
    sys.exit( 1 )

if __name__ == '__main__' :
  if len( sys.argv ) > 1 :
    _main( sys.argv[ 1 ] )

  else :
    print( 'Input file name required.' )

#---------#---------#---------#---------#---------#--------#
