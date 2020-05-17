
# parsetab.py
# This file is automatically generated. Do not edit.
# pylint: disable=W,C,R
_tabversion = '3.10'

_lr_method = 'LALR'

_lr_signature = 'leftANDORleftXORleftRANDOMleftPLUSMINUSleftMULTIPLYDIVIDEMODULUSleftFACTORIALrightSQRTrightUMINUSUPLUSNOTleftEXPONENTIATIONAND ASSIGN DIVIDE EXPONENTIATION FACTORIAL ID INTEGER LPAREN MINUS MODULUS MULTIPLY NOT OR PLUS RANDOM REAL RPAREN SQRT STRING XORstatement : ID ASSIGN expressionstatement : expressionstatement : STRINGexpression : expression DIVIDE expression\n                | expression EXPONENTIATION expression\n                | expression MINUS expression\n                | expression MODULUS expression\n                | expression MULTIPLY expression\n                | expression PLUS expression\n\t\t\t\t| expression AND expression\n\t\t\t\t| expression OR expression\n\t\t\t\t| expression XOR expression\n\t\t\t\t| expression RANDOM expressionexpression : MINUS expression %prec UMINUS\n                | PLUS expression %prec UPLUS\n\t\t\t\t| NOT expressionexpression : expression FACTORIAL\n\t   expression : expression SQRTexpression : LPAREN expression RPARENexpression : INTEGER\n                | REALexpression : ID'
    
_lr_action_items = {'ID':([0,5,6,7,8,11,12,13,14,15,16,17,18,19,20,21,],[2,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,]),'STRING':([0,],[4,]),'MINUS':([0,2,3,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,],[5,-22,14,5,5,5,5,-20,-21,5,5,5,5,5,5,5,5,5,5,5,-17,-18,-14,-22,-15,-16,14,14,-4,-5,-6,-7,-8,-9,14,14,14,14,-19,]),'PLUS':([0,2,3,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,],[6,-22,17,6,6,6,6,-20,-21,6,6,6,6,6,6,6,6,6,6,6,-17,-18,-14,-22,-15,-16,17,17,-4,-5,-6,-7,-8,-9,17,17,17,17,-19,]),'NOT':([0,5,6,7,8,11,12,13,14,15,16,17,18,19,20,21,],[7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,]),'LPAREN':([0,5,6,7,8,11,12,13,14,15,16,17,18,19,20,21,],[8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,]),'INTEGER':([0,5,6,7,8,11,12,13,14,15,16,17,18,19,20,21,],[9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,]),'REAL':([0,5,6,7,8,11,12,13,14,15,16,17,18,19,20,21,],[10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,]),'$end':([1,2,3,4,9,10,22,23,24,25,26,27,29,30,31,32,33,34,35,36,37,38,39,40,],[0,-22,-2,-3,-20,-21,-17,-18,-14,-22,-15,-16,-1,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-19,]),'ASSIGN':([2,],[11,]),'DIVIDE':([2,3,9,10,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,],[-22,12,-20,-21,-17,-18,-14,-22,-15,-16,12,12,-4,-5,12,-7,-8,12,12,12,12,12,-19,]),'EXPONENTIATION':([2,3,9,10,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,],[-22,13,-20,-21,-17,-18,13,-22,13,13,13,13,13,-5,13,13,13,13,13,13,13,13,-19,]),'MODULUS':([2,3,9,10,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,],[-22,15,-20,-21,-17,-18,-14,-22,-15,-16,15,15,-4,-5,15,-7,-8,15,15,15,15,15,-19,]),'MULTIPLY':([2,3,9,10,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,],[-22,16,-20,-21,-17,-18,-14,-22,-15,-16,16,16,-4,-5,16,-7,-8,16,16,16,16,16,-19,]),'AND':([2,3,9,10,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,],[-22,18,-20,-21,-17,-18,-14,-22,-15,-16,18,18,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-19,]),'OR':([2,3,9,10,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,],[-22,19,-20,-21,-17,-18,-14,-22,-15,-16,19,19,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-19,]),'XOR':([2,3,9,10,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,],[-22,20,-20,-21,-17,-18,-14,-22,-15,-16,20,20,-4,-5,-6,-7,-8,-9,20,20,-12,-13,-19,]),'RANDOM':([2,3,9,10,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,],[-22,21,-20,-21,-17,-18,-14,-22,-15,-16,21,21,-4,-5,-6,-7,-8,-9,21,21,21,-13,-19,]),'FACTORIAL':([2,3,9,10,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,],[-22,22,-20,-21,-17,-18,-14,-22,-15,-16,22,22,22,-5,22,22,22,22,22,22,22,22,-19,]),'SQRT':([2,3,9,10,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,],[-22,23,-20,-21,-17,-18,-14,-22,-15,-16,23,23,23,-5,23,23,23,23,23,23,23,23,-19,]),'RPAREN':([9,10,22,23,24,25,26,27,28,30,31,32,33,34,35,36,37,38,39,40,],[-20,-21,-17,-18,-14,-22,-15,-16,40,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-19,]),}

_lr_action = {}
for _k, _v in _lr_action_items.items():
   for _x,_y in zip(_v[0],_v[1]):
      if not _x in _lr_action:  _lr_action[_x] = {}
      _lr_action[_x][_k] = _y
del _lr_action_items

_lr_goto_items = {'statement':([0,],[1,]),'expression':([0,5,6,7,8,11,12,13,14,15,16,17,18,19,20,21,],[3,24,26,27,28,29,30,31,32,33,34,35,36,37,38,39,]),}

_lr_goto = {}
for _k, _v in _lr_goto_items.items():
   for _x, _y in zip(_v[0], _v[1]):
       if not _x in _lr_goto: _lr_goto[_x] = {}
       _lr_goto[_x][_k] = _y
del _lr_goto_items
_lr_productions = [
  ("S' -> statement","S'",1,None,None,None),
  ('statement -> ID ASSIGN expression','statement',3,'p_statement_assign','hmwk_03.py',152),
  ('statement -> expression','statement',1,'p_statement_expr','hmwk_03.py',163),
  ('statement -> STRING','statement',1,'p_statement_string','hmwk_03.py',187),
  ('expression -> expression DIVIDE expression','expression',3,'p_expression_binop','hmwk_03.py',193),
  ('expression -> expression EXPONENTIATION expression','expression',3,'p_expression_binop','hmwk_03.py',194),
  ('expression -> expression MINUS expression','expression',3,'p_expression_binop','hmwk_03.py',195),
  ('expression -> expression MODULUS expression','expression',3,'p_expression_binop','hmwk_03.py',196),
  ('expression -> expression MULTIPLY expression','expression',3,'p_expression_binop','hmwk_03.py',197),
  ('expression -> expression PLUS expression','expression',3,'p_expression_binop','hmwk_03.py',198),
  ('expression -> expression AND expression','expression',3,'p_expression_binop','hmwk_03.py',199),
  ('expression -> expression OR expression','expression',3,'p_expression_binop','hmwk_03.py',200),
  ('expression -> expression XOR expression','expression',3,'p_expression_binop','hmwk_03.py',201),
  ('expression -> expression RANDOM expression','expression',3,'p_expression_binop','hmwk_03.py',202),
  ('expression -> MINUS expression','expression',2,'p_expression_unop_prefix','hmwk_03.py',218),
  ('expression -> PLUS expression','expression',2,'p_expression_unop_prefix','hmwk_03.py',219),
  ('expression -> NOT expression','expression',2,'p_expression_unop_prefix','hmwk_03.py',220),
  ('expression -> expression FACTORIAL','expression',2,'p_expression_unop_suffix','hmwk_03.py',228),
  ('expression -> expression SQRT','expression',2,'p_expression_unop_suffix','hmwk_03.py',229),
  ('expression -> LPAREN expression RPAREN','expression',3,'p_expression_group','hmwk_03.py',235),
  ('expression -> INTEGER','expression',1,'p_expression_number','hmwk_03.py',239),
  ('expression -> REAL','expression',1,'p_expression_number','hmwk_03.py',240),
  ('expression -> ID','expression',1,'p_expression_name','hmwk_03.py',244),
]
