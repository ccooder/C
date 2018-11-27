# C Knowledge Point

## Chapter-01

* 1.10 *Local and External variables and scope*
   1. Terminology: *automatic* variables
   2. In fact, common practice is to place definitions of all external
       variables at the beginning of the source file, and then omit all extern declarations.

## Chapter-02 Variables and Type
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
    * `strlen`
    * `strcmp`
  3. An enumeration is a list of constant **integer values**
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
        \+ \- | left to right
        << >> | left to right
        < <= > >=|left to right
        == != | left to right
        &|left to right
        ^|left to right
        &#124;|left to right
        &&|left to right
        &#124;&#124; | left to right
        ?: | left to right
        = \+= \-= \*= /= %= &= ^= &#124;= <<= >>=|right to left
        ,|left to right

## Chapter-03 Control Flow
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

## Chapter-04 Functions
* 4.1 *Basics of Functions*
    1. If the return type is omitted, int is assumed

* 4.2 *Functions Returning Non-integers*
    1. `double sum, atof(char []);`
    says that sum is a double variable, and that atof is a function that takes one char[] argument and returns a double.

* 4.4 *Scope Roles*
    1. Array sizes must be specified with the definition, but are optional with an `extern` declaration.

       Up to some moderate program size, it is probably best to have one header file that contains everything that is
        to be shared between any two parts of the program;

* 4.6 *Static Variables* 
    1. The internal `static` variables provide private, permanent storage within a single function.

* 4.9 *Initialization*
    1. In the absence of explicit initialization, external and static variables are guaranteed to be initialized to zero; automatic and register variables have undefined (i.e., garbage) initial values.

* 4.10 *Recursion*
    1. - [ ] Quick Sort

* 4.11.1 *File Inclusion*

    1.  Naturally, when an included file is changed, all files that depend on it must be recompiled.     

* 4.11.2 *Macro Substitution*

    1. The preprocessor operator ## provides a way to concatenate actual arguments during macro
       expansion. The rules for nested uses of `##` are arcane; further details may be found in Appendix A.

## Chapter-05 Pointers and Arrays

* 5.3 *Pointers and Arrays*
  1. These remarks are true regardless of the type or size of the variables in the array a. The
     meaning of "adding 1 to a pointer," and by extension, all pointer arithmetic, is that pa+1
     points to the next object, and pa+i points to the i-th object beyond pa.
  2. A pointer is a variable, so pa=a and pa++ are legal. But an array name is not a variable;
        constructions like a=pa and a++ are illegal.
* 5.4 *Pointers Arithmetic*
  1. Any pointer can be meaningfully compared for equality or inequality with zero.
* 5.5 *Character Pointers*
  1. lexicographical --> 词典编纂上的 adj.
* 5.6 *Pointers Array; Pointers to Pointers*
  1.  Sort a set of text lines into alphabetic order, a stripped-down version of the UNIX program `sort`.
* 5.7 *Multi-Dimensional Arrays*
  1.  Elements are stored by rows, so the rightmost subscript, or column, varies fastest as elements are accessed in storage order.
  2.  `f(int (*daytab)[13]) { ... }` which says that the parameter is a pointer to an array of 13 integers,the parentheses are necessary.   Without parentheses, the declaration:
      `int *daytab[13] ` is an array of 13 pointers to integers.
* 5.9 *Pointers vs. Multi-Dimensional Arrays*
  1.  The most frequent use of arrays of pointers is to store character strings of diverse lengths.
* 5.10 *Command-line Arguments*
  1. The first optional argument is `argv[1]` and the last is `argv[argc-1]`; additionally, the standard requires that `argv[argc]` be a null pointer.
  2. The format argument of `printf` can be an expression too.
* 5.11 *Pointers to Functions*
  1. The generic pointer type void * is used for the pointer arguments. Any pointer can be cast to void * and back again without loss of information
* 5.12 *Complicated Declaration*
  1. dcl, dir-dcl wtf? 为了说明这一小节真的很变态，我使用中文来阐述: 太太太难了，瞬间觉得自己并不适合编程。

## Chapter-06 Structures

* 6.1 *Basics of Structures*
  1.  Structures may be copied and assigned to, passed to functions, and returned by functions.

* 6.2 *Structures and Functions*
  1. The only legal operations on a structure are copying it or assigning to it as a unit, taking it's address with &, and accessing it's members.
  2. The structure's operators `->` and `.` are at top of precedence hierarchy and thus bind very tightly.

* 6.3 Structures and Arrays
  1. It would be more precise to enclose the initializers for each "row" or structure in braces. (P.119)
  2. C provides a compile-time unary operator called `sizeof` that can be used to compute the size of any object.
  3. `sizeof object` and `sizeof (type name)` yield an unsigned integer value whose type,`size_t` is defined in the header `<stddef.h>`.An object can be a variable or array or structure. A type name can be the name of a basic type like `int` or `double`, or a derived type like a structure or a pointer.
  4. 骚操作:`#define NKEYS (sizeof keytab / sizeof(struct key))`. (P.121)
  5. A `sizeof` can not be used in a `#if` line, because the preprocessor does not parse type names.The expression in the `#define` is not evaluated by the preprocessor, so the code here is legal.

* 6.4 Pointers to Structures
  1.  It is illegal for a structure to contain an instance of itself.

* 6.8 Unions

  1. The storage allocator in Chapter 8 shows how a union can be used to force a variable to be
     aligned on a particular kind of storage boundary.

* 6.9 Bit-fields

  1. ```c
     struct {
     unsigned int is_keyword : 1;
     unsigned int is_extern : 1;
     unsigned int is_static : 1;
     } flags;
     flags.is_extern = flags.is_static = 1; //Turn the bit on
     flags.is_extern = flags.is_static = 0; //Turn the bit off
     if (flags.is_extern == 0 && flags.is_static == 0) //Test them
     	...
     ```

  2.  Fields may be declared only as `int`s; for portability, specify signed or unsigned explicitly. They are not arrays and they do not have addresses, so the `&` operator cannot be applied on them.

## Chapter-07 Input and Output

* 7.2 Formatted Output - `printf`

  1. | Character | Argument type; Printed As                                    |
     | :-------- | :----------------------------------------------------------- |
     | d,i       | `int`; decimal number                                        |
     | o         | `int`; unsigned octal number (without a leading zero)        |
     | x,X       | `int`; unsigned hexadecimal number (without a leading `0x` or `0X`),using `abcdef` or `ABCDEF` for 10,...15. |
     | u         | `int`; unsigned decimal number                               |
     | c         | `int`;single character                                       |
     | s         | `char *`; print characters from the string until a '\0' or the number of characters given by the precision. |
     | f         | `double`; [-]`m`.`dddddd`, where the number of d's is given by the precision (default 6) |
     | e,E       | `double`; [-]`m`.`dddddde`+/-xx or [-]`m`.`ddddddE`+/-xx, where the number of d's is given by the precision (default 6) |
     | g,G       | `double`; use `%e` or `%E` if the exponent is less than -4 or greater than or equal to the precision;Otherwise use `%f`.Trailing zeros and a trailing decimal point are not printed. |
     | p         | `void *`;pointer(implementation-dependent representation).   |
     | %         | no argument is converted; print `a%`                         |

* 7.3 Formatted Input - `scanf`

* 7.7  Line Input and Output

  1. The library functions `gets` and `puts` are similar to `fgets` and `fputs`, but operate on `stdin` and `stdout`. Confusingly, `gets` deletes the terminating `'\n'`, and `puts` adds it.

* 7.7 之后有很多手册式的东西，需要可以来查询（字符串，字符判断，数学计算，随机数）

# Expert C Programming

## Chapter-01 C Through the Mists of Time

* `#define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))`
  instead of
  `#define TOTAL_ELEMENTS (sizeof(array) / sizeof(int))`
  because the former allows the base type of the array to change (from, say, int to char) without
  needing a change to the #define, too.

## Chapter-02  It's Not a Bug, It's a Language Feature

* Remember in C: multiplication and division come before addition and subtraction.Everything else should be in parentheses. We think that's excellent advice.

* Replaced:

  ```c
  gets(line);
  ```

  by the lines:

  ```c
  if (fgets(line, sizeof(line), stdin) == NULL)
  	exit(1);
  ```


## Chapter-03 Unscrambling Declarations in C

* P.69 Figure 3-1, 3-2, 3-3

* A typedef 'd name provides the type for every declarator in a declaration.

* Don't bother with `typedef`s for `struct`s.

* If you're stuck for a name for a structure tag, just give it a name that ends in "_tag". This
  makes it simpler to detect what a particular name is.

* Here's a better way to use `strcmp`:

  ```c
  #define STRCMP(a, R, b) (strcmp(a, b) R 0)
  ```

  Now, you can write code in the natural style:

  ```c
  if (STRCMP(s, ==, "const"))
  ```

## Chapter-04 The Shocking Truth: C Arrays and Pointers Are NOT the Same!

* A pointer definition does not allocate space for what's pointed at, only for the pointer, except when
  assigned a literal string.
* A string literal created by a pointer initialization is defined as read-only in ANSI C.

## Chapter-05 Thinking of Linking

* Always put the `-l` library options at the rightmost end of your compilation command line.

## Chapter-06  Poetry in Motion: Runtime Data Structures

## Chapter-07 Thanks for the Memory

* `memcpy()`library routine is tuned for high performance.

## Chapter-08 Why Programmers Can't Tell Halloween from Christmas Day

* OCT 31 equals DEC 25
* Don't Mix Old and New Styles in Function Declaration and Definition
* Get character-by-character input, P.184
* If I were stranded on a desert island and could only take one data structure with me, it
  would be the hash table.

## Chapter-09 More about Arrays

* When Arrays are Pointers:

  1. An array name in an expression (in contrast with a declaration) is treated
     by the compiler as a pointer to the first element of the array [1] (paraphrase,
     ANSI C Standard, paragraph 6.2.2.1).
  2. A subscript is always equivalent to an offset from a pointer (paraphrase,
     ANSI C Standard, paragraph 6.3.2.1).
  3. An array name in the declaration of a function parameter is treated by
     the compiler as a pointer to the first element of the array (paraphrase, ANSI
     C Standard, paragraph 6.7.1).

* Given a declaration like int a[10];, both the following are correct:
  `a[6] = ....;`
  `6[a] = ....;`

  The second version is never seen in production code, and has no known use apart from confusing
  those new to C.

* Arrays and Pointers Interchangeability Summary P. 215

* Never forget that when you point the finger at someone, three of your own fingers are pointing back at you...

# APUE

## Chapter-01 UNIX System Overview

* There are two rules to be aware of with respect to `errno`. First, its value is never
  cleared by a routine if an error does not occur. Therefore, we should examine its value
  only when the return value from a function indicates that an error occurred. 

## Chapter-02 UNIX Standardization and Implementations

* The runtime limits are obtained by calling one of the following three functions:`sysconf` `pathconf` `fpathconf`.

## Chapter-03 File I/O

* we can seek zero bytes from the current position to determine the current offset:

  ```c
  off_t currpos;
  currpos = lseek(fd, 0L, SEEK_CUR);
  ```

* UNIX atomic way: Set O_APPEND o_flag when file is opened,this causes the kernel to position the file to the `EOF` before each write.

* `BUFFSIZE = 4096` the I/O efficiency is better.

## Chapter-04 Files and Directories

* The contents of the symbolic link that are returned in `buf` are not `null` terminated

## Chapter-06 System data files and Informations

* `strftime` conversion specifiers. P.193
* `printf("%s\n", NULL);` Out: (null); But, `printf("%s \n", NULL);`Out: Segment Fault.Use `fprintf(stdout, "%s\n", NULL);` can avoid this problem.

## Chapter-07 Process Environments

* The optimizations don’t affect the global, static, and volatile variables; their values after the `longjmp` are the last values that they assumed.

## Chapter-08 Process Control

* If we write a long-running program that forks many child processes, they become zombies unless we wait for them and fetch their termination status.

## Chapter-11 Threads

* The handlers are recorded in a stack, which means that they are executed in the reverse order from that with which they were registered.