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
	* 2.12 *Precedence and Order of Evaluation*
	    1.  Operators  | Associativity
	        -----------|--------------
	        () [] -> . | left to right
	        ! ~ ++ -- + - * (type) sizeof|right to left
	        \* / %|left to right
	        + - | left to right
	        << >> | left to right
	        < <= > >=|left to right
	        == != | left to right
	        &|left to right
	        ^|left to right
	        &#124;|left to right
	        &&|left to right
	        &#124;&#124; | left to right
	        ?: | left to right
	        = += -= \*= /= %= &= ^= &#124;= <<= >>=|right to left
	        ,|left to right
  * ## Chapter03
    * 3.2 *If*
        1.  It's a good idea to use braces when there are nested ifs.
    * 3.8 *Goto and labels*
        1. The most common is to abandon processing in some deeply nested structure, such as breaking out of two or more loops at once.
            ```c
            for ( ... )
                for ( ... ) {
                    ...
                    if (disaster)
                        goto error;
                 }
                ...
            error:
                /* clean up the mess */
            ```
  * ## Chapter04
    * 4.1 *Basics of Functions*
        1. If the return type is omitted, int is assumed
    * 4.2 *Functions Returning Non-integers*
        1. `double sum, atof(char []);`
        says that sum is a double variable, and that atof is a function that takes one char[] argument and returns a double.

`
        

