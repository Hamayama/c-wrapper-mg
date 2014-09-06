(lalr-parser
 (expect: 4)
 (output: c-grammar "c-wrapper/c-grammar.yy.scm")
 ; (out-table: "c-gram.out")
 (ID
  ;; For scheme
  SEMICOLON ;
  ;; COMMA=,  LCBRA={  RCBRA=} LSBRA=[  RSBRA=]
  ;; LPAREN=( RPAREN=) OR=| DOT=.
  COMMA LCBRA RCBRA LSBRA RSBRA 
  LPAREN RPAREN OR DOT COLON

  ~ ! + - * / ^ & % = ? < >

  IDENTIFIER CONSTANT STRING SIZEOF
  PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
  AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
  SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
  XOR_ASSIGN OR_ASSIGN TYPENAME

  TYPEDEF EXTERN STATIC AUTO REGISTER INLINE RESTRICT
  SIGNED UNSIGNED CONST VOLATILE
  STRUCT UNION ENUM ELLIPSIS RANGE

  CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

  ASM UNKNOWN EXTENSION

  AT_INTERFACE AT_IMPLEMENTATION AT_END AT_SELECTOR AT_DEFS AT_ENCODE
  AT_PUBLIC AT_PRIVATE AT_PROTECTED AT_PACKAGE AT_PROTOCOL
  AT_CLASS AT_ALIAS AT_THROW AT_TRY AT_CATCH AT_FINALLY AT_SYNCHRONIZED
  AT_PROPERTY AT_SYNTHESIZE AT_DYNAMIC AT_OPTIONAL AT_REQUIRED OBJC_STRING

  START_MACRO
  )

 (program
  ()
  (file)
  (START_MACRO statement_list) : (%MACRO-BODY $2)
  )

 (file
  (external_definition) 
  (file external_definition) 
  )

 (external_definition
  (maybe_extension function_definition) : (all-referenced-info-clear!)
  (maybe_extension asm_definition) : (all-referenced-info-clear!)
  (maybe_extension external_declaration) : (all-referenced-info-clear!)
  (objc_definition) : (all-referenced-info-clear!)
  (SEMICOLON) : (all-referenced-info-clear!)
  )

 (function_definition
  (declarator function_body) : (emit-define-inline '(int) $1 $2)
  (declaration_specifiers declarator function_body)
  : (emit-define-inline $1 $2 $3)
  )

 (function_body
  (compound_statement) : (%FUNCTION-BODY $1)
  (declaration_list compound_statement) : #f ;; TODO: support K&R style
  )

 (external_declaration
  (declaration_specifiers SEMICOLON) : (external-declaration $1 (list (null-declarator)))
  (declaration_specifiers init_declarator_list SEMICOLON) : (external-declaration $1 $2)
  )

 (declaration
  (declaration_specifiers SEMICOLON) : (declaration $1 '())
  (declaration_specifiers init_declarator_list SEMICOLON) : (declaration $1 $2)
  (extension declaration) : $2
  )

 (declaration_specifiers
  (storage_class_specifier)
  (storage_class_specifier declaration_specifiers) : (%APPEND $1 $2)
  (type_specifier) : $1
  (type_specifier declaration_specifiers) : (%APPEND $1 $2)
  )

 (init_declarator_list
  (init_declarator) : (%LIST (compose-variable-attribute $1))
  (init_declarator_list COMMA init_declarator)
  : (%ADD-LIST $1 (compose-variable-attribute $3))
  )

 (init_declarator
  (declarator maybe_asm = initializer) : (%COMPOSE-DECLARATOR $1 (init-value-declarator $4))
  (declarator maybe_asm) : $1
  )

 (storage_class_specifier
  (TYPEDEF) : '(TYPEDEF)
  (EXTERN) : '()
  (STATIC) : '()
  (AUTO) : '()
  (INLINE) : '()
  )

 (type_specifier
  (TYPENAME) : (%TYPENAME $1)
  (SIGNED) : '(SIGNED)
  (UNSIGNED) : '(UNSIGNED)
  (CONST) : '()
  (REGISTER) : '()
  (VOLATILE) : '()
  (struct_or_union_specifier) : (%STRUCT-OR-UNION-SPECIFIER $1)
  (enum_specifier) : (%ENUM-SPECIFIER $1)
  (RESTRICT) : '()
  (TYPENAME objc_non_empty_protocol_references) : (%TYPENAME $1)
  (objc_non_empty_protocol_references) : '(id)
  )

 (primary_expr 
  (identifier) : (%IDENTIFIER $1)
  (CONSTANT) : $1
  (STRING) : $1
  (OBJC_STRING) : (%OBJC-STRING $1)
  (LPAREN expr RPAREN) : (%EXPR-IN-PARENS $2)
  (LPAREN compound_statement RPAREN) : (%COMPOUND-STATEMENT $2)
  (LPAREN type_name RPAREN LCBRA initializer_list RCBRA) : #f
  (objc_message_expr) : $1
  (objc_selector_expr) : $1
  (objc_protocol_expr) : #f
  (objc_encode_expr) : #f
  )

 (postfix_expr 
  (primary_expr) : $1
  (postfix_expr LSBRA expr RSBRA) : (%REF-ARRAY $1 $3)
  (postfix_expr LPAREN RPAREN) : (%FUNCALL $1 '())
  (postfix_expr LPAREN argument_expr_list RPAREN) : (%FUNCALL $1 $3)
  (postfix_expr DOT identifier) : (%DOT-REF $1 $3)
  (postfix_expr PTR_OP identifier) : (%PTR-REF $1 $3)
  (postfix_expr INC_OP) : (%POST-INC $1)
  (postfix_expr DEC_OP) : (%POST-DEC $1)
  )

 (argument_expr_list
  (assignment_expr) : (%LIST $1)
  (argument_expr_list COMMA assignment_expr) : (%ADD-LIST $1 $3)
  )

 (unary_expr 
  (postfix_expr) : $1
  (INC_OP unary_expr) : (%PRE-INC $2)
  (DEC_OP unary_expr) : (%PRE-DEC $2)
  (unary_operator cast_expr) : (%UNARY $1 $2)
  (SIZEOF unary_expr) : (%SIZEOF-EXPR $2)
  (SIZEOF LPAREN type_name RPAREN) : (%SIZEOF-TYPE $3)
  (extension cast_expr) : $2
  )

 (unary_operator 
  (&) : '&
  (*) : '*
  (+) : '+
  (-) : '-
  (~) : '~
  (!) : '!
  )

 (cast_expr
  (unary_expr) : $1
  (LPAREN type_name RPAREN cast_expr) : (%CAST $2 $4)
  )

 (multiplicative_expr
  (cast_expr) : $1
  (multiplicative_expr * cast_expr) : (%MUL $1 $3)
  (multiplicative_expr / cast_expr) : (%DIV $1 $3)
  (multiplicative_expr % cast_expr) : (%MOD $1 $3)
  )

 (additive_expr
  (multiplicative_expr) : $1
  (additive_expr + multiplicative_expr) : (%ADD $1 $3)
  (additive_expr - multiplicative_expr) : (%SUB $1 $3)
  )

 (shift_expr
  (additive_expr) : $1
  (shift_expr LEFT_OP additive_expr) : (%SHIFT-LEFT $1 $3)
  (shift_expr RIGHT_OP additive_expr) : (%SHIFT-RIGHT $1 $3)
  )

 (relational_expr
  (shift_expr) : $1
  (relational_expr < shift_expr) : (%LT $1 $3)
  (relational_expr > shift_expr) : (%GT $1 $3)
  (relational_expr LE_OP shift_expr) : (%LE $1 $3)
  (relational_expr GE_OP shift_expr) : (%GE $1 $3)
  )

 (equality_expr
  (relational_expr) : $1
  (equality_expr EQ_OP relational_expr) : (%EQ $1 $3)
  (equality_expr NE_OP relational_expr) : (%NE $1 $3)
  )

 (and_expr
  (equality_expr) : $1
  (and_expr & equality_expr) : (%BIT-AND $1 $3)
  )


 (exclusive_or_expr
  (and_expr) : $1
  (exclusive_or_expr ^ and_expr) : (%BIT-XOR $1 $3)
  )


 (inclusive_or_expr
  (exclusive_or_expr) : $1
  (inclusive_or_expr OR exclusive_or_expr) : (%BIT-OR $1 $3)
  )


 (logical_and_expr
  (inclusive_or_expr) : $1
  (logical_and_expr AND_OP inclusive_or_expr) : (%LOG-AND $1 $3)
  )

 (logical_or_expr
  (logical_and_expr) : $1
  (logical_or_expr OR_OP logical_and_expr) : (%LOG-OR $1 $3)
  )

 (conditional_expr
  (logical_or_expr) : $1
  (logical_or_expr ? logical_or_expr COLON conditional_expr) : (%IF $1 $3 $5)
  )

 (assignment_expr
  (conditional_expr) : $1
  (unary_expr = assignment_expr) : (%ASSIGN $1 $3)
  (unary_expr MUL_ASSIGN assignment_expr) : (%ASSIGN $1 (%MUL $1 $3))
  (unary_expr DIV_ASSIGN assignment_expr) : (%ASSIGN $1 (%DIV $1 $3))
  (unary_expr MOD_ASSIGN assignment_expr) : (%ASSIGN $1 (%MOD $1 $3))
  (unary_expr ADD_ASSIGN assignment_expr) : (%ASSIGN $1 (%ADD $1 $3))
  (unary_expr SUB_ASSIGN assignment_expr) : (%ASSIGN $1 (%SUB $1 $3))
  (unary_expr LEFT_ASSIGN assignment_expr) : (%ASSIGN $1 (%SHIFT-LEFT $1 $3))
  (unary_expr RIGHT_ASSIGN assignment_expr) : (%ASSIGN $1 (%SHIFT-RIGHT $1 $3))
  (unary_expr AND_ASSIGN assignment_expr) : (%ASSIGN $1 (%BIT-AND $1 $3))
  (unary_expr XOR_ASSIGN assignment_expr) : (%ASSIGN $1 (%BIT-XOR $1 $3))
  (unary_expr OR_ASSIGN assignment_expr) : (%ASSIGN $1 (%BIT-OR $1 $3))
  )

 (expr
  (assignment_expr) : $1
  (expr COMMA assignment_expr) : (%CONCAT-EXPR $1 $3)
  )    
 
 (constant_expr
  (conditional_expr) : $1
  )

 (struct_or_union_specifier
  (struct_or_union identifier LCBRA struct_declaration_list RCBRA)
  : (decl-struct-or-union $1 $2 $4)
  (struct_or_union LCBRA struct_declaration_list RCBRA)
  : (decl-struct-or-union $1 #f $3)
  (struct_or_union identifier)
  : (decl-struct-or-union $1 $2 #f)
  )
 
 (struct_or_union
  (STRUCT) : 'STRUCT
  (UNION) : 'UNION
  )

 (struct_declaration_list
  (struct_declaration) : $1
  (struct_declaration_list struct_declaration) : (%APPEND $1 $2)
  )

 (struct_declaration
  (type_specifier_list struct_declarator_list SEMICOLON) : (begin
                                                             (parser-attribute-clear!)
                                                             (make-type-decl-list $1 $2))
  (extension type_specifier_list struct_declarator_list SEMICOLON)
  : (begin
      (parser-attribute-clear!)
      (make-type-decl-list $2 $3))
  (struct_or_union_specifier SEMICOLON)
  : (begin
      (parser-attribute-clear!)
      (make-type-decl-list (%LIST $1) (list (identifier-declarator (gensym "%unnamed")))))
  (extension struct_or_union_specifier SEMICOLON)
  : (begin
      (parser-attribute-clear!)
      (make-type-decl-list (%LIST $2) (list (identifier-declarator (gensym "%unnamed")))))
  (AT_DEFS LPAREN TYPENAME RPAREN) : '()
  )

 (struct_declarator_list
  (struct_declarator) : (%LIST (compose-variable-attribute $1))
  (struct_declarator_list COMMA struct_declarator) : (%ADD-LIST $1 (compose-variable-attribute $3))
  )
 
 (struct_declarator
  (declarator) : $1
  (COLON constant_expr) : (bit-field-declarator $2)
  (declarator COLON constant_expr) : (%COMPOSE-DECLARATOR (bit-field-declarator $3) $1)
  )

 (enum_specifier
  (ENUM LCBRA enumerator_list RCBRA) : (decl-enum #f $3)
  (ENUM LCBRA enumerator_list COMMA RCBRA) : (decl-enum #f $3)
  (ENUM identifier LCBRA enumerator_list RCBRA) : (decl-enum $2 $4)
  (ENUM identifier LCBRA enumerator_list COMMA RCBRA) : (decl-enum $2 $4)
  (ENUM identifier) : (decl-enum $2 '())
  )

 (enumerator_list
  (enumerator) : (%LIST $1)
  (enumerator_list COMMA enumerator) : (%ADD-LIST $1 $3)
  )

 (enumerator
  (identifier) : (decl-enumerator $1 #f)
  (identifier = constant_expr) : (decl-enumerator $1 $3)
  )

 (declarator
  (declarator2) : $1
  (pointer declarator2) : (%COMPOSE-DECLARATOR $2 $1)
  )
 
 (declarator2
  (identifier) : (identifier-declarator $1)
  (LPAREN declarator RPAREN) : $2
  (declarator2 LSBRA RSBRA) : (%COMPOSE-DECLARATOR (array-declarator #f) $1)
  (declarator2 LSBRA array_qualifier_list RSBRA) : (%COMPOSE-DECLARATOR (array-declarator #f) $1)
  (declarator2 LSBRA array_size_expr RSBRA) : (%COMPOSE-DECLARATOR (array-declarator $3) $1)
  (declarator2 LSBRA array_qualifier_list array_size_expr RSBRA)
  : (%COMPOSE-DECLARATOR (array-declarator $4) $1)
  (declarator2 LPAREN RPAREN) : (%COMPOSE-DECLARATOR $1 (func-declarator '()))
  (declarator2 LPAREN parameter_type_list RPAREN) : (%COMPOSE-DECLARATOR $1 $3)
  (declarator2 LPAREN parameter_identifier_list RPAREN) : $1 ;; not supported
  )
 
 (pointer
  (*) : (ptr-declarator)
  (* type_specifier_list) : (ptr-declarator)
  (* pointer) : (%COMPOSE-DECLARATOR (ptr-declarator) $2)
  (* type_specifier_list pointer) : (%COMPOSE-DECLARATOR (ptr-declarator) $3)
  )
 
 (type_specifier_list
  (type_specifier) : $1
  (type_specifier_list type_specifier) : (%APPEND $1 $2)
  )

 (parameter_identifier_list
  (identifier_list)
  (identifier_list COMMA ELLIPSIS)
  )
 
 (identifier_list
  (identifier) : (%LIST $1)
  (identifier_list COMMA identifier) : (%ADD-LIST $1 $3)
  )

 (parameter_type_list
  (parameter_list) : (func-declarator $1)
  (parameter_list COMMA ELLIPSIS) : (func-vaargs-declarator $1)
  )

 (parameter_list
  (parameter_declaration) : (%LIST $1)
  (parameter_list COMMA parameter_declaration) : (%ADD-LIST $1 $3)
  )

 (parameter_declaration
  (type_specifier_list declarator) : (parameter-declaration (make-type-decl $1 (compose-variable-attribute $2)))
  (type_name) : $1
  )

 (type_name
  (type_specifier_list) : (make-type-decl $1 (null-declarator))
  (type_specifier_list abstract_declarator) : (make-type-decl $1 $2)
  )

 (abstract_declarator
  (pointer) : $1
  (abstract_declarator2) : $1
  (pointer abstract_declarator2) : (%COMPOSE-DECLARATOR $2 $1)
  )


 (abstract_declarator2
  (LPAREN abstract_declarator RPAREN) : $2
  (LSBRA RSBRA) : (ptr-declarator)
  (LSBRA array_qualifier_list RSBRA) : (ptr-declarator)
  (LSBRA array_size_expr RSBRA) : (array-declarator $2)
  (LSBRA array_qualifier_list array_size_expr RSBRA) : (array-declarator $3)
  (abstract_declarator2 LSBRA RSBRA) : (%COMPOSE-DECLARATOR (ptr-declarator) $1)
  (abstract_declarator2 LSBRA array_qualifier_list RSBRA) : (%COMPOSE-DECLARATOR (ptr-declarator) $1)
  (abstract_declarator2 LSBRA array_size_expr RSBRA) : (%COMPOSE-DECLARATOR (array-declarator $3) $1)
  (abstract_declarator2 LSBRA array_qualifier_list array_size_expr RSBRA)
  : (%COMPOSE-DECLARATOR (array-declarator $4) $1)
  (LPAREN RPAREN) : (func-declarator '())
  (LPAREN parameter_type_list RPAREN) : $2
  (abstract_declarator2 LPAREN RPAREN) : (%COMPOSE-DECLARATOR $1 (func-declarator '()))
  (abstract_declarator2 LPAREN parameter_type_list RPAREN) : (%COMPOSE-DECLARATOR $1 $3)
  )

 (initializer
  (assignment_expr) : $1
  (LCBRA initializer_list RCBRA) : #f
  (LCBRA initializer_list COMMA RCBRA) : #f
  )

 (initializer_list
  (initializer)
  (initializer_list COMMA initializer)
  )

 (statement
  (labeled_statement) : #f
  (compound_statement) : $1
  (expression_statement) : $1
  (selection_statement) : $1
  (iteration_statement) : $1
  (jump_statement) : $1
  (asm_statement) : #f
  (objc_statement) : #f
  )

 (objc_statement
  (AT_THROW expr SEMICOLON) 
  (AT_THROW SEMICOLON) 
  (objc_try_catch_statement) 
  (AT_SYNCHRONIZED LPAREN expr RPAREN compound_statement)
  )

 (objc_catch_prefix
  (AT_CATCH LPAREN identifier RPAREN)
  )

 (objc_catch_clause
  (objc_catch_prefix compound_statement)
  )

 (objc_opt_catch_list
  ()
  (objc_opt_catch_list objc_catch_clause)
  )

 (objc_try_catch_clause
  (AT_TRY compound_statement objc_opt_catch_list)
  )

 (objc_finally_clause
  (AT_FINALLY compound_statement)
  )

 (objc_try_catch_statement
  (objc_try_catch_clause)
  (objc_try_catch_clause objc_finally_clause)
  )

 (labeled_statement
  (identifier COLON statement)
  (CASE constant_expr COLON statement)
  (DEFAULT COLON statement)
  )

 (compound_statement
  (LCBRA RCBRA) : (%COMPOUND-STATEMENT '(0))
  (LCBRA statement_list RCBRA) : (%COMPOUND-STATEMENT $2)
  (LCBRA declaration_list RCBRA) : (%COMPOUND-STATEMENT '(0))
  (LCBRA declaration_list statement_list RCBRA)
  : (%COMPOUND-STATEMENT-WITH-DECLARATION $2 $3)
  (error RCBRA) : #f
  )

 (declaration_list
  (declaration) : $1
  (declaration_list declaration) : (%APPEND $1 $2)
  )

 (statement_list
  (statement) : (%LIST $1)
  (statement_list statement) : (%ADD-LIST $1 $2)
  )

 (expression_statement
  (SEMICOLON) : 0
  (expr SEMICOLON) : $1
  (error SEMICOLON) : #f
  )

 (selection_statement
  (IF LPAREN expr RPAREN statement) : (%IF $3 $5 0)
  (IF LPAREN expr RPAREN statement ELSE statement) : (%IF $3 $5 $7)
  (SWITCH LPAREN expr RPAREN statement) : #f
  )

 (iteration_statement
  (WHILE LPAREN expr RPAREN statement) : (%WHILE $3 $5)
  (DO statement WHILE LPAREN expr RPAREN SEMICOLON) : (%DO-WHILE $5 $2)
  (FOR LPAREN SEMICOLON SEMICOLON RPAREN statement) : (%FOR 0 1 0 $6)
  (FOR LPAREN SEMICOLON SEMICOLON expr RPAREN statement) : (%FOR 0 1 $5 $7)
  (FOR LPAREN SEMICOLON expr SEMICOLON RPAREN statement) : (%FOR 0 $4 0 $7)
  (FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN statement) : (%FOR 0 $4 $6 $8)
  (FOR LPAREN expr SEMICOLON SEMICOLON RPAREN statement) : (%FOR $3 1 0 $7)
  (FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN statement) : (%FOR $3 1 $6 $8)
  (FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN statement) : (%FOR $3 $5 0 $8)
  (FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN statement)
  : (%FOR $3 $5 $7 $9)
  )

 (jump_statement
  (GOTO identifier SEMICOLON) : #f
  (CONTINUE SEMICOLON) : (%CONTINUE)
  (BREAK SEMICOLON) : (%BREAK)
  (RETURN SEMICOLON) : (%RETURN 0)
  (RETURN expr SEMICOLON) : (%RETURN $2)
  )
 
 (identifier
  (IDENTIFIER) : $1
  )
 
 ;;
 ;; asm
 ;;
 (maybe_asm
  ()
  (asm_expr)
  )

 (asm_expr
  (ASM LPAREN string_list RPAREN)
  )

 (asm_statement
  (ASM LPAREN asm_argument RPAREN SEMICOLON)
  (ASM type_qualifier LPAREN asm_argument RPAREN SEMICOLON)
  )
 
 (type_qualifier
  (CONST)
  (VOLATILE)
  (RESTRICT)
  )
 
 (array_qualifier
  (STATIC)
  (RESTRICT)
  (CONST)
  (VOLATILE)
  )

 (array_qualifier_list
  (array_qualifier)
  (array_qualifier_list array_qualifier)
  )
 
 (array_size_expr
  (assignment_expr) : $1
  (*) : #f
  )
 
 (asm_argument
  (string_list)
  (string_list COLON asm_operands)
  (string_list COLON asm_operands COLON asm_operands)
  (string_list COLON asm_operands COLON asm_operands COLON asm_clobbers)
  )

 (string_list
  (STRING)
  (string_list STRING)
  )

 (asm_operands
  ()
  (asm_operands2)
  )

 (asm_operands2
  (asm_operand)
  (asm_operands2 COMMA asm_operand)
  )

 (asm_operand
  (STRING LPAREN expr RPAREN)
  (LSBRA identifier RSBRA STRING LPAREN expr RPAREN)
  )
 
 (asm_clobbers
  (STRING)
  (asm_clobbers COMMA STRING)
  )
 
 (asm_definition
  (asm_expr SEMICOLON)
  )

 ;;
 ;; extension
 ;;
 (maybe_extension
  ()
  (extension)
  )

 (extension
  (EXTENSION)
  )

 ;; Objective-C
 (objc_definition
  (objc_class_definition)
  (objc_class_declaration)
  (objc_alias_declaration)
  (objc_protocol_definition)
  (objc_method_definition)
  )
 
 (classname
  (identifier) : $1
  (TYPENAME) : $1
  )
 
 (classname_list
  (classname) : (%LIST $1)
  (classname_list COMMA classname) : (%ADD-LIST $1 $3)
  )

 (objc_class_declaration
  (AT_CLASS classname_list SEMICOLON) : (emit-define-objc-class $2)
  )

 (objc_alias_declaration
  (AT_ALIAS identifier identifier SEMICOLON) : #f
  )
  
 (objc_superclass
  (COLON classname)
  ()
  )

 (objc_class_ivars
  (LCBRA objc_ivar_declaration_list RCBRA)
  ()
  )
 
 (objc_class_definition
  (objc_interface_head objc_superclass objc_protocol_references
                objc_class_ivars
                objc_method_prototype_list
                AT_END)
  (AT_IMPLEMENTATION classname objc_superclass
                     objc_class_ivars)
  (objc_interface_head LPAREN classname RPAREN objc_protocol_references
                objc_method_prototype_list
                AT_END)
  (AT_IMPLEMENTATION classname LPAREN identifier RPAREN)
  )

 (objc_interface_head
  (AT_INTERFACE classname) : (emit-define-objc-class (%LIST $2))
  )

 (objc_protocol_definition
  (AT_PROTOCOL identifier objc_protocol_references objc_method_prototype_list AT_END)
  (AT_PROTOCOL identifier_list SEMICOLON)
  )

 (objc_protocol_references
  ()
  (objc_non_empty_protocol_references)
  )

 (objc_non_empty_protocol_references
  (< classname_list >)
  )

 (objc_ivar_declaration_list
  (objc_ivar_declaration_list objc_visibility_spec objc_ivar_declarations)
  (objc_ivar_declarations)
  )

 (objc_visibility_spec
  (AT_PRIVATE)
  (AT_PROTECTED)
  (AT_PUBLIC)
  (AT_PACKAGE)
  )

 (objc_ivar_declarations
  ()
  (objc_ivar_declarations objc_ivar_declaration SEMICOLON)
  (objc_ivar_declarations SEMICOLON)
  )

 (objc_ivar_declaration
  (declaration_specifiers objc_ivars)
  )

 (objc_ivars
  ()
  (objc_ivar_declarator)
  (objc_ivars COMMA objc_ivar_declarator)
  )

 (objc_ivar_declarator
  (declarator)
  (declarator COLON assignment_expr)
  (COLON assignment_expr)
  )

 (objc_method_type
  (+)
  (-)
  )

 (objc_method_definition
  (objc_method_type objc_method_declaration optarglist compound_statement)
  )

 (objc_method_prototype_list
  ()
  (objc_method_prototype_list objc_method_prototype)
  (objc_method_prototype_list external_declaration)
  (objc_method_prototype_list objc_property)
  (objc_method_prototype_list AT_OPTIONAL)
  (objc_method_prototype_list AT_REQUIRED)
  )

 (objc_method_prototype
  (objc_method_type objc_method_declaration SEMICOLON)
  : (begin
      (parser-attribute-clear!)
      (apply emit-objc-method $2))
  )

 (objc_property
  (AT_PROPERTY LPAREN property_attribute_list RPAREN declaration)
  (AT_PROPERTY declaration)
  (AT_SYNTHESIZE init_declarator_list SEMICOLON)
  (AT_DYNAMIC init_declarator_list SEMICOLON)
  )

 (property_attribute_list
  ()
  (identifier)
  (property_attribute_list COMMA identifier)
  )

 (objc_protocol_qualifier
  ()
  (identifier)
  )

 (objc_method_declaration
  (LPAREN objc_protocol_qualifier type_name RPAREN unary_selector)
  : (decl-objc-method $3 $5)
  (unary_selector) : (decl-objc-method (var-id) $1)
  (LPAREN objc_protocol_qualifier type_name RPAREN keyword_selector optparmlist)
  : (decl-objc-method $3 $5)
  (keyword_selector optparmlist) : (decl-objc-method (var-id) $1)
  )

 (optarglist
  ()
  (SEMICOLON myxdecls)
  )

 (myxdecls
  ()
  (mydecls)
  )

 (error_statement
  (error SEMICOLON) : #f
  )

 (mydecls
  (mydecl)
  (error_statement)
  (mydecls mydecl)
  (mydecl error_statement)
  )

 (mydecl
  (declaration_specifiers parameter_list SEMICOLON)
  (declaration_specifiers SEMICOLON)
  )

 (optparmlist
  ()
  (COMMA ELLIPSIS)
  (COMMA parameter_list)
  )

 (unary_selector
  (selector) : (decl-keyword $1)
  )

 (keyword_selector
  (keyword_declarator) : (combine-decl-keyword $1)
  (keyword_selector keyword_declarator) : (combine-decl-keyword $1 $2)
  )

 (selector
  (identifier) : $1
  (TYPENAME) : $1
  (reserved_words) : $1
  )

 (reserved_words
  (ENUM)
  (STRUCT)
  (UNION)
  (IF)
  (ELSE)
  (WHILE)
  (DO)
  (FOR)
  (SWITCH)
  (CASE)
  (DEFAULT)
  (BREAK)
  (CONTINUE)
  (RETURN)
  (GOTO)
  (ASM)
  (SIZEOF)
  )

 ;; ignore variable attributes in Obj-C
 (keyword_declarator
  (selector COLON LPAREN objc_protocol_qualifier type_name RPAREN identifier)
  : (begin
      (parser-attribute-clear!)
      (decl-keyword $1 $5))
  (selector COLON identifier) : (begin
                                  (parser-attribute-clear!)
                                  (decl-keyword $1 (var-id)))
  (COLON LPAREN objc_protocol_qualifier type_name RPAREN identifier)
  : (begin
      (parser-attribute-clear!)
      (decl-keyword "" $4))
  (COLON identifier) : (begin
                         (parser-attribute-clear!)
                         (decl-keyword "" (var-id)))
  )

 (message_args
  (selector) : (%QUOTE $1)
  (keyword_arg_list) : $1
  )

 (keyword_arg_list
  (keyword_arg) : $1
  (keyword_arg_list keyword_arg) : (%APPEND $1 $2)
  )

 (keyword_arg
  (selector COLON expr) : (%KEYWORD-ARG $1 $3)
  (COLON expr) : (%KEYWORD-ARG-WITHOUT-SELECTOR $2)
  )

 (receiver
  (expr) : $1
  (TYPENAME) : $1
  )

 (objc_message_expr
  (LSBRA receiver message_args RSBRA) : (%OBJC-MESSAGE-EXPR $2 $3)
  )

 (selector_arg
  (selector) : (x->string $1)
  (keyword_name_list) : (string-join (map x->string $1) ":")
  )

 (keyword_name_list
  (keyword_name) : (%LIST $1)
  (keyword_name_list keyword_name) : (%ADD-LIST $1 $2)
  )

 (keyword_name
  (selector COLON) : $1
  (COLON) : :
  )

 (objc_selector_expr
  (AT_SELECTOR LPAREN selector_arg RPAREN) : (%SELECTOR $3)
  )

 (objc_protocol_expr
  (AT_PROTOCOL LPAREN identifier RPAREN)
  )

 (objc_encode_expr
  (AT_ENCODE LPAREN TYPENAME RPAREN)
  )


;;  ;;
;;  ;; attribute
;;  ;;
;;  (maybe_attribute
;;   ()
;;   (attributes)
;;   )

;;  (attributes
;;   (attribute)
;;   (attributes attribute)
;;   )

;;  (attribute
;;   (ATTRIBUTE LPAREN LPAREN attribute_list RPAREN RPAREN)
;;   )

;;  (attribute_list
;;   (attribute2)
;;   (attribute_list COMMA attribute2)
;;   )
 
;;  (attribute2
;;   ()
;;   (attribute_word)
;;   (attribute_word LPAREN IDENTIFIER RPAREN)
;;   (attribute_word LPAREN IDENTIFIER COMMA expr RPAREN)
;;   (attribute_word LPAREN RPAREN)
;;   (attribute_word LPAREN expr RPAREN)
;;   )
 
;;  (attribute_word
;;   (identifier)
;;   (storage_class_specifier)
;;   (TYPENAME)
;;   (type_qualifier)
;;   ) 
 
 )

