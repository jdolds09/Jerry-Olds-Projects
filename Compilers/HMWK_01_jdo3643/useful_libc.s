# Olds, Jerry D.
# jdo3643
# 2020-03-05

# as --gstabs+ -o u.o useful_libc.s     <- Assemble the source code into object code.
#                                          (--gstabs+ includes debugging info for gdb)
# gcc -static -o test u.o useful_test.c <- Make a static executable from the object code,
#                                          linking it with stdlib and a test harness.
# ./test                                <- Run the executable.
# echo $?                               <- Display the exit code from the run.

.global readInteger
.global readReal
.global writeBoolean
.global writeInteger
.global writeNewLine
.global writeReal
.global writeString

.text
#-----------------------------------------------------------
readInteger:
  # Establish stack frame.
  pushq   %rbp          # Save old base (frame) ptr
  movq    %rsp, %rbp    # Make the current stack ptr the base (frame) ptr
  subq	  $16, %rsp		# Get space for locals

  # scanf( " %d", &np )
  movq    %rdi, -16(%rbp)   # Put passed in value to function on stack
  movq    -16(%rbp), %rsi   # Arg 2: &np
  movq    $int_fmt, %rdi    # Arg 1: format

  movl    $0, %eax      # Zero args are in the FP registers
  call    scanf         # scanf( " %d", &np )
  
  leave                 # Disestablish stack frame
  ret                   # Return to caller;  (integer) result in %eax

#-----------------------------------------------------------
readReal:
  # Establish stack frame.
  pushq   %rbp          # Save old base (frame) ptr
  movq    %rsp, %rbp    # Make the current stack ptr the base (frame) ptr
  subq    $16, %rsp     # Get space for locals

  # scanf( " %lf", &dp )
  movq    %rdi, -16(%rbp)    # Put passed in value to function on stack
  movq    -16(%rbp), %rsi    # Arg 2: &dp
  movq    $double_fmt, %rdi  # Arg 1: format

  movl    $0, %eax      # Zero args are in the FP registers
  call    scanf         # scanf( " %lf", &dp )

  leave                 # Disestablish stack frame
  ret                   # Return to caller;  (integer) result in %eax

#-----------------------------------------------------------
writeBoolean:
  pushq   %rbp          # Save old base (frame) ptr
  movq    %rsp, %rbp    # Make the current stack ptr the base (frame) ptr
  subq    $16, %rsp     # Get space for locals
  
  # Get value of n and check to see if n == 0
  movl    %edi, -4(%rbp)  # Do the command to read value from stack
  cmpl    $0, -4(%rbp)  # Get value of n
  je .ZERO              # If n == 0, print "false"

  # n == 1
  movq    $true, %rsi   # n != 0, print "true"
  jmp     .OUTPUT_RESULT   # Jump to OUTPUT_RESULT to output true result

.ZERO:
  movq    $false, %rsi  # set output message to "false"

.OUTPUT_RESULT:
  movq    $string_fmt, %rdi # Format for printf: "%s"
  movl    $0, %eax      # Zero args are in the FP registers
  call    printf        # printf ...
  movl    %eax, -4(%rbp)    # result <- printf ...
  movq	  stdout, %rdi      # stdout ...
  call	  fflush        # fflush ...
  
  cmpl    $0, -4(%rbp)  # 0 <= result
  setge   %al           # if (0 <= result), then return true, else return false
  movzbl  %al, %eax     # set %eax to true or false based the outcome of (0 <= result)
 
  leave                 # Disestablish stack frame
  ret                   # Return to caller;  (integer) result in %eax

#-----------------------------------------------------------
writeInteger:
  pushq   %rbp          # Save old base (frame) ptr
  movq    %rsp, %rbp    # Make the current stack ptr the base (frame) ptr
  subq    $16, %rsp     # Get space for locals
  
  # Get value of n
  movl    %edi, -4(%rbp)    # Put value on stack
  movl    -4(%rbp), %esi    # Store value of n in %esi
  
  # Write integer
  movq    $int_fmt2, %rdi    # Format for printf: "%d"
  movl    $0, %eax      # Zero args are in the FP registers
  call    printf        # printf ...
  movl    %eax, -4(%rbp)    # result <- printf ...
  movq	  stdout, %rdi      # stdout ...
  call	  fflush        # fflush ...
  
  cmpl    $0, -4(%rbp)  # 0 <= result
  setge   %al           # if (0 <= result), then return true, else return false
  movzbl  %al, %eax     # set %eax to true or false based the outcome of (0 <= result)

  leave                 # Disestablish stack frame
  ret                   # Return to caller;  (integer) result in %eax

#-----------------------------------------------------------
writeNewLine:
  pushq   %rbp          # Save old base (frame) ptr
  movq    %rsp, %rbp    # Make the current stack ptr the base (frame) ptr
  subq    $16, %rsp     # Get space for locals

  # Write newline
  movl    $10, %edi     # Arg 1 of putchar: '\n' (ASCII value of \n is 10)
  call    putchar       # putchar ...
  movl    %eax, -4(%rbp)    # result <- putchar ...
  movq    stdout, %rdi  # stdout ...
  call    fflush        # fflush ...

  cmpl    $-1, -4(%rbp) # EOF != result
  setne   %al           # if (EOF != result), then return true, else return false
  movzbl  %al, %eax     # set %eax to true or false based the outcome of (EOF != result)

  leave                 # Disestablish stack frame
  ret                   # Return to caller;  (integer) result in %eax

#-----------------------------------------------------------
writeReal:
  pushq   %rbp          # Save old base (frame) ptr
  movq    %rsp, %rbp    # Make the current stack ptr the base (frame) ptr
  subq    $16,  %rsp    # Get space for locals

  # Get value of d
  movq	  %xmm0, -8(%rbp)   # Put value on stack
  movq	  -8(%rbp), %xmm0   # Store value of d in %xmm0
  
  # Write real
  movq    $double_fmt2, %rdi    # Format for printf: "%lf"
  movl    $1, %eax      # One arg is in the FP registers
  call    printf        # printf ...
  movl    %eax, -4(%rbp)    # result <- printf ...
  movq	  stdout, %rdi      # stdout ...
  call	  fflush        # fflush ...
  
  cmpl    $0, -4(%rbp)  # 0 <= result
  setge   %al           # if (0 <= result), then return true, else return false
  movzbl  %al, %eax     # set %eax to true or false based the outcome of (0 <= result)

  leave                 # Disestablish stack frame
  ret                   # Return to caller;  (integer) result in %eax

#-----------------------------------------------------------
writeString:
  pushq   %rbp          # Save old base (frame) ptr
  movq    %rsp, %rbp    # Make the current stack ptr the base (frame) ptr
  subq    $16, %rsp     # Get space for locals

  # Get string
  movq    %rdi, -16(%rbp)       # Put string on stack
  movq    -16(%rbp), %rsi       # Store string in %rsi
  
  # Write string
  movq    $string_fmt, %rdi     # Format for printf: "%s"
  movl    $0, %eax      # Zero args are in the FP registers
  call printf           # printf ...
  movl    %eax, -4(%rbp)        # result <- printf
  movq	  stdout, %rdi      # stdout
  call	  fflush        # fflush ...
  
  cmpl    $0, -4(%rbp)  # 0 <= result
  setge   %al           # if (0 <= result), then return true, else return false
  movzbl  %al, %eax     # set %eax to true or false based the outcome of (0 <= result)

  leave                 # Disestablish stack frame
  ret                   # Return to caller;  (integer) result in %eax

#-----------------------------------------------------------
.data

# Need asciz here to get NUL byte on end.
.align 8
int_fmt:
  .asciz  " %d"
int_fmt2:
  .asciz  "%d"
double_fmt:
  .asciz  " %lf"
double_fmt2:
  .asciz  "%lf"
string_fmt:
  .asciz  "%s"
false:
  .asciz  "false"
true:
  .asciz  "true"
#-----------------------------------------------------------
