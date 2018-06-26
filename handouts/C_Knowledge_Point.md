# C Knowledge Point
  * ## Chapter01
  	* 1.10 *Local and External variables and scope*
  		1. Terminology: *automatic* variables
  		2. In fact, common practice is to place definitions of all external
		variables at the beginning of the source file, and then omit all extern declarations.


  * ## Chapter02
    * 2.1 *Variable Names*
        1. At least te first 31 characters of an internal name are significant.
        For function names and exteranl variables,the number may be less than 31,
        because external names may be used by assemblers and loaders over which
        the language has no control.For example names,the standard guarantees
        uniqueness only for 6 characters and a signle case.
	* 2.3 *C string*
		1. A string constant is an array of characters. The internal representation of a string
		has a null character '\0' at the end
		2. string functions are declared in the standard header `<string.h>`
			* strlen
			* 
		3.  An enumeration is a list of constant **integer values**
	* 2.7 *Type Conversions*
		1. In general, if an operator like + or * that takes two operands (a binary operator) 
		has operands of different types, the \`lower\' type is promoted to 
		the \`higher\' type before the operation proceeds. The Rules:
			* If either operand is `long double`, convert the other to `long double`.
			* Otherwise, if either operand is `double`, convert the other to `double`.
			* Otherwise, if either operand is `float`, convert the other to `float`.
			* Otherwise, convert `char` and `short` to `int`.
			* Then, if either operand is `long`, convert the other to `long`.

