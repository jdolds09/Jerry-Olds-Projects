/*
Author:     Jerry Olds
ID:         1001533643
Class:      CSE-2312-001 Summer 2018
Assignment: Program 1

Command to build: gcc -o jdo3643_p1 jdo3643_p1.s
Command to run: ./jdo3643_p1
*/

.global main
.func main

main:
    BL _getInt
    MOV R4, R0    @ Move first int to register 4 temporarily    
   
    BL _getChar
    MOV R5, R0    @ Move operation char to register 5 temporarily

    BL _getInt
    MOV R1, R4    /* Place first int and operation char
    MOV R2, R5       in registers 1 and 2 respectively */
    MOV R3, R0       
    
    BL _compare
    MOV R1, R0    @ Move result of operation to Register 1 

    BL _print     @ Print result

    B main


_getInt:
    PUSH {LR}
    SUB SP, SP, #4
    LDR R0, =format_int
    MOV R1, SP
    BL scanf
    LDR R0, [SP]
    ADD SP, SP, #4
    POP {PC}


_getChar:
    MOV R7, #3
    MOV R0, #0
    MOV R2, #1
    LDR R1, =input_char
    SWI 0
    LDR R0, [R1]
    AND R0, #0xFF
    MOV PC, LR


_compare:
    CMP R2, #'+'
    BEQ _add
    
    CMP R2, #'-'
    BEQ _subtract

    CMP R2, #'*'
    BEQ _multiply
 
    CMP R2, #'m'
    BEQ _min


_add:
    MOV R0, R1
    ADD R0, R3
    MOV PC, LR


_subtract:
    MOV R0, R1
    SUB R0, R3
    MOV PC, LR


_multiply:
    MUL R0, R1, R3
    MOV PC, LR


_min:
    MOV R0, R1
    CMP R1, R3
    MOVGE R0, R3
    MOV PC, LR


_print:
    MOV R4, LR
    LDR R0, =print_int
    BL printf
    MOV LR, R4
    MOV PC, LR


.data
format_int:    .asciz    "%d"
print_int:     .asciz    "Answer: %d\n\n"
input_char:    .ascii    " "
