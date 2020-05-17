# Dalio, Brian A.
# dalioba
# 2020-04-09
#---------#---------#---------#---------#---------#--------#
# A simple calculator with variables.

import math
import random
import sys

from Roman import Roman

#---------#---------#---------#---------#---------#--------#
# Lexical analysis section.

# TODO: Add the additional token categories here.
tokens = (
  'INTEGER', 'REAL', 'ID', 'STRING',

  'LPAREN', 'RPAREN',

  'ASSIGN', 'DIVIDE', 'EXPONENTIATION', 'MINUS', 'MODULUS',
  'MULTIPLY', 'PLUS', 'RANDOM', 'XOR', 'AND', 'OR',

  'FACTORIAL', 'NOT', 'SQRT',

  )

# TODO: Add specifications for the new token categories here.
# Tokens
t_ASSIGN         = r'='
t_DIVIDE         = r'/'
t_EXPONENTIATION = r'\^'
t_MINUS          = r'-'
t_MODULUS        = r'%'
t_MULTIPLY       = r'\*'
t_PLUS           = r'\+'
t_AND			 = r'\&'
t_FACTORIAL      = r'\!'
t_NOT			 = r'\~'
t_OR			 = r'\|'
t_RANDOM		 = r'\?'
t_SQRT			 = r'\$'
t_XOR			 = r'\#'

t_LPAREN  = r'\('
t_RPAREN  = r'\)'

def t_ID( t ) :
  r'[_a-zA-Z][_a-zA-Z0-9]*'
  num = Roman.fromRoman( t.value )

  if num is None :
    t.type = 'ID'

  else :
    t.type = 'INTEGER'
    t.value = num

  return t

def t_REAL( t ) :
  r'(\d+[eE][-+]?\d+)|((\d*((\.\d)|(\d\.))\d*)([eE][-+]?\d+)?)'
  t.value = float(t.value)
  return t

# TODO: Extend this definition for t_INTEGER so that it
#       handles binary, octal, decimal, and hex int literals.
def t_INTEGER( t ) :
  r'0x[a-fA-F0-9]+|0b[01]+|0o[0-9]+|\d+'
  
  if (t.value.startswith('0b')):
    t.value = int(t.value, 2)

  elif (t.value.startswith('0o')):
    t.value = int(t.value, 8)

  elif (t.value.startswith('0x')):
    t.value = int(t.value, 16)

  else:
    t.value = int(t.value)

  return t

# TODO: Put your definition for t_STRING here.
def t_STRING( t ):
	r'"[^"/n]*"'
	t.value = str(t.value)
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

# Catchall for any unrecognized characters
def t_error( t ) :
  print( f'{t.lexer.lineno}: Illegal character {t.value[0]!r}.' )
  t.lexer.skip(1)

#-------------------------------------------------
# Build the lexer
import ply.lex as lex
lex.lex()

#---------#---------#---------#---------#---------#--------#
# Syntactic section.

# TODO: Add precedence and associativity rules for the
#       new operators here.
# Precedence rules for the arithmetic operators
precedence = (
  ( 'left', 'AND', 'OR'),
  ( 'left', 'XOR'),
  ( 'left', 'RANDOM'),
  ( 'left',  'PLUS', 'MINUS' ),
  ( 'left',  'MULTIPLY', 'DIVIDE', 'MODULUS' ),
  ( 'left', 'FACTORIAL'),
  ( 'right', 'SQRT'),
  ( 'right', 'UMINUS', 'UPLUS', 'NOT' ),
  ( 'left', 'EXPONENTIATION'),
  )

# Dictionary of names (for storing variables) and constants, which
# cannot be changed (duh).
names = {
  'printBase'  : 10,
  'printRoman' : 0
}

constants = {
  'pi'  : math.pi,
  'e'   : math.e,
  'inf' : math.inf,
  'nan' : math.nan
}

def p_statement_assign( p ) :
  'statement : ID ASSIGN expression'
  if p[1] in constants :
    print( f'Cannot assign to constant {p[1]!r}.' )

  else :
    names[ p[1] ] = p[3]
    print( f'{p[1]} = {p[3]}' )
    if p[1] == 'seed' :
      random.seed( p[3] )

def p_statement_expr( p ) :
  'statement : expression'
  baseInfo = { 2 : '0b{0:b}', 8 : '0o{0:o}', 16 : '0x{0:x}' }
  try :
    iNum = int( p[1] )

    if p[1] == iNum :
      if names.get( 'printRoman', 0 ) :
        print( Roman.toRoman( iNum ), f'({iNum})' )

      else :
        fmt = baseInfo.get( names.get( 'printBase', 10 ), '{0}' )
        print( fmt.format( iNum ) )

    else :
      print( p[1] )

  except :
    print( p[1] )

# TODO: Write p_statement_string(). The production rule is
#       simply 'statement : STRING'.  The processing is just
#       to print the value of the STRING token.

def p_statement_string( p ):
	'statement : STRING'
	print('\'%s\'' % p[1])

# TODO: Update the production rule and processing to deal with
#       all of the new binary operators.
def p_expression_binop( p ) :
  '''expression : expression DIVIDE expression
                | expression EXPONENTIATION expression
                | expression MINUS expression
                | expression MODULUS expression
                | expression MULTIPLY expression
                | expression PLUS expression
				| expression AND expression
				| expression OR expression
				| expression XOR expression
				| expression RANDOM expression'''
  
  if   p[2] == '&' :
      if(p[1] != 0 and p[3] != 0):
          p[0] = 1
      else:
          p[0] = 0

  elif p[2] == '|' :
      if(p[1] == 0 or p[3] == 0):
          p[0] = 0
      else:
          p[0] = 1
  
  elif p[2] == '#' :
      if(not(isinstance(p[1], int)) or not(isinstance(p[3], int))):
          print('XOR requires (int, int) not (%s, %s)' % (type(p[1]), type(p[3])))
      else:
          p[0] = p[1] ^ p[3]

  elif p[2] == '?' : 
      if((isinstance(p[1], float)) or (isinstance(p[3], float))):
          if(p[1] > p[3]):
	          p[0] = random.uniform(p[3],p[1])
          else:
              p[0] = random.uniform(p[1],p[3])
      else:
          if(p[1] > p[3]):
	          p[0] = random.randint(p[3],p[1])
          else:
              p[0] = random.randint(p[1],p[3])

  elif p[2] == '+' : p[0] = p[1] + p[3]
  elif p[2] == '-' : p[0] = p[1] - p[3]
  elif p[2] == '*' : p[0] = p[1] * p[3]
  elif p[2] == '/' : p[0] = p[1] / p[3]
  elif p[2] == '%' : p[0] = p[1] % p[3]
  elif p[2] == '^' : p[0] = p[1] ** p[3]
  else : print("YA DUN GOOFED")

# TODO: Update the production rule and processing to deal with
#       the new prefix binary operators.
def p_expression_unop_prefix( p ) :
  '''expression : MINUS expression %prec UMINUS
                | PLUS expression %prec UPLUS
				| NOT expression'''
  if   p[1] == '-' : p[0] = -p[2]
  elif p[1] == '+' : p[0] = +p[2]
  elif p[1] == '~' : p[0] = not(p[2])

# TODO: Write a p_expression_unop_suffix() routine here to deal
#       with the new suffix unary operators.
def p_expression_unop_suffix( p ) :
	'''expression : expression FACTORIAL
	   expression : expression SQRT'''
	if p[2] == '!' : p[0] = math.gamma(p[1] + 1)
	elif p[2] == '$' : p[0] = math.sqrt(p[1])


def p_expression_group( p ) :
  'expression : LPAREN expression RPAREN'
  p[0] = p[2]

def p_expression_number( p ) :
  '''expression : INTEGER
                | REAL'''
  p[0] = p[1]

def p_expression_name( p ) :
  'expression : ID'

  if p[1] in names :
    p[0] = names[p[1]]

  elif p[1] in constants :
    p[0] = constants[p[1]]

  else :
    print( f'Undefined name {p[1]!r}' )
    p[0] = 0

def p_error( p ) :
  print( "Syntax error at '%s'" % p.value )

#-------------------------------------------------
# Build the parser
import ply.yacc as yacc
yacc.yacc()

#-----------------------------------------------------------
def main() :
  fName = sys.argv[ 1 ]
  print( 'processing expressions from ' + fName + ' ...' )

  with open( fName, 'r' ) as fp :
    lines = fp.read().replace( '\r', '' ).split( '\n' )

  for line in lines :
    if line != '' :
      print( f'{line} ==> ', end='' )
      yacc.parse( line )

if __name__ == '__main__' :
  main()

#---------#---------#---------#---------#---------#--------#
