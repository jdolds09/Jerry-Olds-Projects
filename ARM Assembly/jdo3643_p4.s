/*
Author:     Jerry Olds
ID:         1001533643
Class:      CSE-2312-001 Summer 2018
Assignment: Program 4

Command to build: gcc -o jdo3643_p4 jdo3643_p4.s
Command to run: ./jdo3643_p4
*/

.global main
.func main

main:

@ Get numerator
    BL _getNum
    MOV R4, R0

@ Get denominator
    BL _getNum
    MOV R1, R4
    MOV R2, R0
    MOV R5, R0

@ Output numerator and denominator
    BL _print_operation

    MOV R1, R4
    MOV R2, R5

@ Divide
    BL _divide

@ Output result
    BL _print_result

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

_print_operation:
    PUSH {LR}
    LDR R0, =operation_str
    BL printf
    POP {PC}

_divide:
    PUSH {LR}
    
@ Move numerator and denominator to floating point registers
    VMOV S0, R1
    VMOV S1, R2

@ Convert to single float
    VCVT.F32.S32 S0, S0
    VCVT.F32.S32 S1, S1

@ Compute S2 = S0 / S1
    VDIV.F32 S2, S0, S1

@ Convert to double float
    VCVT.F64.F32 D4, S2

@ Split in to two registers
    VMOV R1, R2, D4

    POP {PC}

_print_result:
    PUSH {LR}
    LDR R0, =result_str
    BL printf
    POP {PC}    


.data

format_int:       .asciz    "%d"
operation_str:    .asciz    "%d / %d = "
result_str:      .asciz    "%.3f\n\n"
