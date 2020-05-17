/*
Author:     Jerry Olds
ID:         1001533643
Class:      CSE-2312-001 Summer 2018
Assignment: Program 3

Command to build: gcc -o jdo3643_p3 jdo3643_p3.s
Command to run: ./jdo3643_p3
*/

.global main
.func main

main:

@ Get both input parameters
    BL _getNum
    MOV R4, R0

    BL _getNum
    MOV R2, R0
    MOV R1, R4

@ Calculate partitions
    BL _count_partitions
    MOV R4, R0

@ Rearange registers for output    
    MOV R5, R1
    MOV R6, R2
    MOV R1, R4
    MOV R2, R5
    MOV R3, R6

@ Print result
    BL _print_result

@ Continious loop
    B main

_getNum:
    PUSH {LR}
    SUB SP, SP, #4
    LDR R0, =format_int
    MOV R1, SP
    BL scanf
    LDR R0, [SP]
    ADD SP, SP, #4
    POP {PC}

_count_partitions:
    PUSH {R4, FP, LR}
    ADD FP, SP, #8          @ Set frame pointer
    SUB SP, SP, #12         @ Move stack pointer
    STR R1, [FP, #-16]      @ Store input value n
    STR R2, [FP, #-20]      @ Store input value m
    LDR R3, [FP, #-16]      @ Check first conditional statement
    CMP R3, #0
    BNE _compare2
    MOV R3, #1
    B _return

    _compare2:              @ Check second conditional statement
        LDR R3, [FP, #-16]
        CMP R3, #0
        BGE _compare3
        MOV R3, #0
        B _return
    
    _compare3:              @ Check thrid conditional statement
        LDR R3, [FP, #-20]
        CMP R3, #0
        BNE _operation
        MOV R3, #0
        B _return

    _operation:
        LDR R5, [FP, #-16]
        LDR R3, [FP, #-20]
        SUB R3, R5, R3          @ n - m
        LDR R2, [FP, #-20]      @ m
        MOV R1, R3              @ n = n - m
        BL _count_partitions    @ count_partitions(n - m, m)
        MOV R4, R0
        LDR R3, [FP, #-20]
        SUB R3, R3, #1          @ m - 1
        MOV R2, R3              @ m = m - 1
        LDR R1, [FP, #-16]      @ n
        BL _count_partitions    @ count_partitions(n, m - 1)
        MOV R3, R0
        ADD R3, R4, R3          @ return count_partitions(n - m, m) + count_partitions(n, m - 1)
        LDR R2, [FP, #-20]      @ restore original value of m
        
    _return:
        MOV R0, R3
        SUB SP, FP, #8
        POP {R4, FP, PC}

_print_result:
    PUSH {LR}
    LDR R0, =print_result
    BL printf
    POP {PC}


.data

format_int:    .asciz    "%d"
print_result:  .asciz    "There are %d partitions of %d using integers up to %d\n\n"
