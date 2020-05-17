# Dalio, Brian A.
# dalioba
# 2020-05-03
#-----------------------------------------------------------
import sys

from Exceptions       import *
#-----------------------------------------------------------
INDENT_STR = '  '

def dumpLine( indent, contents, fp = sys.stdout ) :
  print( f'{INDENT_STR*indent}{contents}', file = fp )

#-----------------------------------------------------------
class Dump() :
  @staticmethod
  def dumpProgram( ast, **kwargs ) :
    fp = kwargs.get( 'fp', sys.stdout )
    indent = kwargs.get( 'indent', 0 )

    if ast is None :
      dumpLine( '[[[ None ]]]', fp = fp )

    elif ast[0] == 'ASSIGN' :
      dumpLine( indent, f'ASSIGN {ast[1]!r}', fp = fp )
      Dump.dumpProgram( ast[2], indent = indent+1, fp = fp )

    elif ast[0] == 'BLOCK' :
      dumpLine( indent, f'BLOCK ({len(ast[1])})', fp = fp )
      for item in ast[1] :
        Dump.dumpProgram( item, indent = indent+1, fp = fp )

    elif ast[0] == 'BREAK' :
      dumpLine( indent, 'BREAK', fp = fp )

    elif ast[0] == 'CONTINUE' :
      dumpLine( indent, 'CONITNUE', fp = fp )

    elif ast[0] == 'DECLARATION' :
      dumpLine( indent, f'DECLARATION {ast[1]!r}, {ast[2]!r}', fp = fp )
      Dump.dumpProgram( ast[3], indent = indent+1, fp = fp )

    elif ast[0] == 'EXIT' :
      dumpLine( indent, 'EXIT', fp = fp )
      Dump.dumpProgram( ast[1], indent = indent+1, fp = fp )

    elif ast[0] == 'IF' :
      dumpLine( indent, 'IF', fp = fp )
      Dump.dumpProgram( ast[1], indent = indent+1, fp = fp )
      Dump.dumpProgram( ast[2], indent = indent+1, fp = fp )
      Dump.dumpProgram( ast[3], indent = indent+1, fp = fp )

    elif ast[0] == 'IF-NO-ELSE' :
      dumpLine( indent, 'IF-NO-ELSE', fp = fp )
      Dump.dumpProgram( ast[1], indent = indent+1, fp = fp )
      Dump.dumpProgram( ast[2], indent = indent+1, fp = fp )

    elif ast[0] == 'NOOP' :
      dumpLine( indent, 'NOOP', fp = fp )

    elif ast[0] == 'READ' :
      dumpLine( indent, f'READ ({len(ast[1])})', fp = fp )
      for item in ast[1] :
        dumpLine( indent+1, f'{item!r}', fp = fp )

    elif ast[0] == 'WHILE' :
      dumpLine( indent, 'WHILE', fp = fp )
      Dump.dumpProgram( ast[1], indent = indent+1, fp = fp )
      Dump.dumpProgram( ast[2], indent = indent+1, fp = fp )

    elif ast[0] == 'WRITE' :
      dumpLine( indent, f'WRITE ({len(ast[1])})', fp = fp )
      for item in ast[1] :
        Dump.dumpProgram( item, indent = indent+1, fp = fp )

    elif ast[0] == 'BINOP' :
      dumpLine( indent, f'BINOP {ast[1]!r}', fp = fp )
      Dump.dumpProgram( ast[2], indent = indent+1, fp = fp )
      Dump.dumpProgram( ast[3], indent = indent+1, fp = fp )

    elif ast[0] == 'UNOP' :
      dumpLine( indent, f'UNOP {ast[1]!r}', fp = fp )
      Dump.dumpProgram( ast[2], indent = indent+1, fp = fp )

    elif ast[0] == 'LITERAL' :
      dumpLine( indent, f'LITERAL {ast[1]!r}, {ast[2]!r}', fp = fp )

    elif ast[0] == 'ID' :
      dumpLine( indent, f'ID {ast[1]!r}', fp = fp )

    else :
      raise InternalError( f'Unknown AST node type {ast[0]!r}.' )

#---------#---------#---------#---------#---------#--------#
