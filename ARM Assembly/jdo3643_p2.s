/*
Author:     Jerry Olds
ID:         1001533643
Class:      CSE-2312-001 Summer 2018
Assignment: Program 2

Command to build: gcc -o jdo3643_p2 jdo3643_p2.s
Command to run: ./jdo3643_p2
*/

.global main
.func main
   
main:
    BL _seedrand      @ Set seed of random number generator        
    MOV R0, #0        @ Set iterator to 0
              
writeloop:            @ Fill array of size 10 full of random values
    CMP R0, #10            
    BEQ writedone           
    LDR R1, =a              
    LSL R2, R0, #2          
    ADD R2, R1, R2          
    PUSH {R0}               
    PUSH {R2}               
    BL _getrand
    MOV R2, R0
    BL _mod_unsigned             
    POP {R2}                
    STR R0, [R2]            
    POP {R0}                
    ADD R0, R0, #1          
    B   writeloop           

writedone:       
    MOV R0, #0        @ Reset iterator to 0           

readloop:             @ Read values of array and print 
    CMP R0, #10         
    BEQ readdone       
    LDR R1, =a       
    LSL R2, R0, #2         
    ADD R2, R1, R2     
    LDR R1, [R2]         
    PUSH {R0}       
    PUSH {R1}       
    PUSH {R2}              
    MOV R2, R1             
    MOV R1, R0           
    BL  _printArray            
    POP {R2}               
    POP {R1}                
    POP {R0}                
    ADD R0, R0, #1          
    B   readloop

readdone:          
    MOV R0, #0         @ Reset iterator to 0

findMin:               @ Find lowest value in array
    CMP R0, #0
    LDREQ R3, =#999    @ If iterator equals 0, set lowest value to be 999
    CMP R0, #10         
    BEQ mindone      
    LDR R1, =a       
    LSL R2, R0, #2         
    ADD R2, R1, R2     
    LDR R1, [R2]                               
    CMP R1, R3
    MOVLT R3, R1       @ If current value is lower than lowest value, set lowest value to current value       
    ADD R0, R0, #1          
    B   findMin

mindone:
    MOV R1, R3
    BL _printMin       @ Print lowest value
    MOV R3, #0         @ Set highest value to 0
    MOV R0, #0         @ Reset iterator

findMax:
    CMP R0, #10         
    BEQ maxdone      
    LDR R1, =a       
    LSL R2, R0, #2         
    ADD R2, R1, R2     
    LDR R1, [R2]                               
    CMP R1, R3
    MOVGT R3, R1       @ If current value is greater than highest value, set highest value to current value        
    ADD R0, R0, #1          
    B   findMax

maxdone:
    MOV R1, R3
    BL _printMax       @ Print highest value
    B _exit            

_exit:              
    MOV R7, #1           
    SWI 0              
       
_printArray:
    PUSH {LR}           
    LDR R0, =printf_value  
    BL printf             
    POP {PC}

_printMin:
    PUSH {LR}
    LDR R0, =print_min
    BL printf
    POP {PC}

_printMax:
    PUSH {LR}           
    LDR R0, =print_max  
    BL printf             
    POP {PC}
            
_seedrand:
    PUSH {LR}             
    MOV R0, #0           
    BL time              
    MOV R1, R0            
    BL srand              
    POP {PC}        
    
_getrand:
    PUSH {LR}            
    BL rand              
    POP {PC}

_mod_unsigned:
    PUSH {LR}
    LDR R6, =#1000
    B _modloopcheck
    _modloop:
        SUB R2, R2, R6
    _modloopcheck:
        CMP R2, R6
        BHS _modloop
    MOV R0, R2
    POP {PC}            

   
.data

.balign 4
a:              .skip       40
printf_value:   .asciz      "a[%d] = %d\n"
print_min:      .asciz      "MINIMUM VALUE = %d\n"
print_max:      .asciz      "MAXIMUM VALUE = %d\n" 
debug_str:      .asciz      "R%-2d   0x%08X  %011d \n"
 
