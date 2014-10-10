# C Snippets
C-programs in repository illistrate various CS concepts.

To run programs: compile .c file with your favorite C compiler.
  ie. in a Linux terminal I would run: $ gcc [program]
    which would output a compiled "a.out", to run the program I would type $ ./a.out

## Stack Demo
 Program that demonstrates stack concepts: takes input then has a simple undo/redo functionality. At start of the program, it prompts the user to input a phrase, the phrase is appended onto master string. Undo/redo functions removes/adds words based on spaces.
 
 ie. if input is "abc this is a test" the undo process would remove only "test" from the string
