/*
Author:     Jerry Olds
ID:         1001533643
Class:      CSE-2312-001 Summer 2018
Assignment: Final Exam Program

Command to build: gcc -o jdo3643_pfinal jdo3643_pfinal.s
Command to run: ./jdo3643_pfinal
*/

.global main
.func main
   
main:

    MOV R0, #0 @ Counter

_fill_array:           @ Fill array of size 10 with inputted values from user
    CMP R0, #10
    BEQ _fill_done
    LDR R1, =a
    LSL R2, R0, #2
    ADD R2, R1, R2
    PUSH {R0}
    PUSH {R2}
    BL _getNum
    POP {R2}
    STR R0, [R2]
    POP {R0}
    ADD R0, R0, #1
    B _fill_array

_fill_done:
    MOV R0, #0

_read_array:           @ Print values from array 
    CMP R0, #10
    BEQ _read_done
    LDR R1, =a
    LSL R2, R0, #2
    ADD R2, R1, R2
    LDR R1, [R2]
    PUSH {R0}
    PUSH {R1}
    PUSH {R2}
    MOV R2, R1
    MOV R1, R0
    BL _print_array
    POP {R2}
    POP {R1}
    POP {R0}
    ADD R0, R0, #1
    B _read_array

_read_done:
    MOV R0, #0

_prompt:               @ Prompt for search value
    MOV R7, #4
    MOV R0, #1
    MOV R2, #22
    LDR R1, =prompt
    SWI 0

_get_search_value:     @ Get search value from user
    BL _getNum
    MOV R3, R0
    MOV R0, #0
    MOV R4, #0
    BL _find_value

_find_value:           @ Search array for search value
    CMP R0, #10
    BEQ .NOT_FOUND
    LDR R1, =a
    LSL R2, R0, #2
    ADD R2, R1, R2
    LDR R1, [R2]
    PUSH {R0}
    PUSH {R1}
    PUSH {R2}
    PUSH {R3}
    CMP R1, R3
    BLEQ .FOUND
    POP {R3}
    POP {R2}
    POP {R1}
    POP {R0}
    ADD R0, R0, #1
    B _find_value
.FOUND:               @ Print found search value
    PUSH {LR}
    ADD R4, R4, #1
    MOV R2, R1
    MOV R1, R0
    BL _print_array
    POP {PC}
.NOT_FOUND:
    CMP R4, #0
    BEQ _not_found
    B _exit 

_getNum:              @ Input from user
    PUSH {LR}
    SUB SP, SP, #4
    LDR R0, =format_int
    MOV R1, SP
    BL scanf
    LDR R0, [SP]
    ADD SP, SP, #4
    POP {PC}

_print_array:         @ Print value
    PUSH {LR}
    LDR R0, =print_element
    BL printf
    POP {PC}

_not_found:
    MOV R7, #4
    MOV R0, #1
    MOV R2, #40
    LDR R1, =not_found
    SWI 0
    MOV R7, #1
    SWI 0
    
_exit:                @ End of program
    MOV R7, #1
    SWI 0


.data

.balign 4
a:                   .skip          40
format_int:          .asciz         "%d"
print_element:       .asciz         "array_a[%d] = %d\n"
prompt:              .ascii         "ENTER A SEARCH VALUE: "
not_found:           .ascii         "That value does not exist in the array!\n"
