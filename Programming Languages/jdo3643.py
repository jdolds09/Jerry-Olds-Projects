# Author: Jerry Olds
# ID: 1001533643
# Date: 11/14/2018
# Lab 3

import os

# Find file
file_name = "input_RPN.txt"
for root, directories, files in os.walk('.'):
    for name in files:
        if name == file_name:
            path = os.path.join(root, name)

f = open(path, "r") # Open file for reading
lines = f.readlines() # Read the lines of the file in to lines variable

operator = ['+', '-', '*', '/'] # Usable operators

# Convert to RPN
for i in lines:
    print("Algebraic expression: ", i) # Print out original algebraic expression before converting to RPN
    operators = 0 # Will hold number of operators in expression
    RPN = "" # String that will store the RPN of algebraic expression
    x = 0 # Will hold position of line that is currently being examined
    positionAfterParentheses = 0 # Will hold the position in RPN string after numbers and operators that are in parentheses
    numbersAfterParentheses = 0 # Will keep track of numbers that are after the ones that are in parentheses

   # Skip white space
    while i[x] == " ":
        x += 1
    
    while x != len(i) - 1:
        # Put everything that is in parentheses at the beginning of RPN string
        if i[x] == '(':
            numbersInParentheses = []
            operatorsInParentheses = []
            x += 1
            while i[x] != ')':
                num = ""
                # Get first number
                while i[x].isdigit() or i[x] == '.':
                    num += i[x]
                    x += 1
                num += " "
                # Skip whitespace
                while i[x] == " ":
                    x += 1
                # If operator is + or -, put numbers in front and operators at the end
                if i[x] == '+' or i[x] == '-':
                    op = i[x] + " "
                    operatorsInParentheses.append(op)  
                    numbersInParentheses.insert(0, num)
                    num = ""
                    # Get second number
                    while i[x + 1].isdigit() or i[x + 1] == '.':
                        num += i[x + 1]
                        x += 1
                    x += 1
                    num += " "
                    # Skip whitespace
                    while i[x] == " ":
                        x += 1
                    numbersInParentheses.insert(1, num)
                # If operator is * or /, put numbers at end and put operator in front
                else:
                    numbersInParentheses.append(num)
                if i[x] in operator:
                    if i[x] == '*' or i[x] == '/':
                        op = i[x] + " "
                        operatorsInParentheses.insert(0, op)                 
                    x += 1
                    #Skip whitespace
                    while i[x] == " ":
                        x += 1
            # Insert numbers and operators in parentheses in RPN string with correct format
            for c in numbersInParentheses:
                RPN = RPN[:positionAfterParentheses] + c + RPN[positionAfterParentheses:]
                positionAfterParentheses += len(c)
            for c in operatorsInParentheses:
                RPN = RPN[:positionAfterParentheses] + c + RPN[positionAfterParentheses:]
                positionAfterParentheses += len(c)
        
        # If position currently being examined is outside parentheses and is a digit
        elif i[x].isdigit():
            # Get first number
            num = i[x]
            while i[x + 1].isdigit() or i[x + 1] == '.':
                num += i[x + 1]
                x += 1
            num += " "
            if x != len(i) - 1:
                x += 1
            # Skip whitespace
            while i[x] == " ":
                x += 1
            
            # If the operator after number is + or -, put operator at end and put numbers in front
            if i[x] == '+' or i[x] == '-':
                # Insert first number in RPN string
                RPN = RPN[:positionAfterParentheses] + num + RPN[positionAfterParentheses:]
                numbersAfterParentheses += len(num)
                num = ""
                op = i[x]
                # Get second number
                while (x != (len(i) - 1) and (i[x + 1].isdigit() or i[x + 1] == '.')):
                   num += i[x + 1]
                   x += 1
                num += " "
                if x != len(i) - 1:
                    x += 1
                # Skip whitespace
                while i[x] == " ":
                    x += 1
               
                # Insert second number and operator in to RPN string
                RPN = RPN[:positionAfterParentheses] + num + RPN[positionAfterParentheses:]
                numbersAfterParentheses += len(num)
                RPN += op
                operators += 1
            
            # If the operator after number is * or /, put numbers at end and put operator in front
            elif i[x] == '*' or i[x] == '/':
                # Insert first number in RPN string
                RPN = RPN[:positionAfterParentheses + numbersAfterParentheses] + num + RPN[positionAfterParentheses + numbersAfterParentheses:]
                numbersAfterParentheses += len(num)
                num = ""
                op = i[x]
                # Get second number
                while (x != (len(i) - 1) and (i[x + 1].isdigit() or i[x + 1] == '.')):
                   num += i[x + 1]
                   x += 1
                num += " "
                if x != len(i) - 1:
                    x += 1
                # Skip whitespace
                while i[x] == " ":
                    x += 1
                # Insert second number and operator in RPN string
                RPN = RPN[:positionAfterParentheses + numbersAfterParentheses] + num + RPN[positionAfterParentheses + numbersAfterParentheses:]
                RPN = RPN[:len(RPN) - operators] + op + RPN[len(RPN) - operators:]
                numbersAfterParentheses += len(num)
                operators += 1 
        
        # If position currently being examined is an operator or any other symbol
        else:
            # If position being examined is an operator
            if i[x] in operator:
                # If position being examined is * or /, put at beginning of operators
                if i[x] == '*' or i[x] == '/':
                    RPN = RPN[:len(RPN) - operators] + i[x] + RPN[len(RPN) - operators:]
                    operators += 1
                # If position being examined is + or -, append to end of RPN string
                else: 
                    RPN += i[x]
                    operators += 1
            # Advance position and skip whitespace
            if x != len(i) - 1:
                x += 1
            while i[x] == " ":
                x += 1

# Calculate result of expression
    print("Reverse Polish Notation: ", RPN)
    ops = []
    x = 0
    # Count amount of operators in expression 
    while x != (len(RPN)):
        if RPN[x] in operator:
            ops.append(RPN[x])
        x += 1
    
    x = 0
    while x != (len(ops)):
        j = 0
        # Set position to first operator
        while RPN[j] not in operator:
            if j <= (len(RPN) - 3) and (RPN[j + 1] == '-' and RPN[j + 2].isdigit()):
                    j += 2
            else:
                j += 1
        # Remove operator from string
        if j == len(RPN) - 1:
            RPN = RPN[:-1]
        else:
            RPN = RPN[:j] + RPN[j + 1:]

        while j >= len(RPN):
            j -= 1
        num1 = ""
        num2 = ""
        # Num 2
        while not RPN[j].isdigit():
            j -= 1
        while RPN[j].isdigit() or RPN[j] == '.' or RPN[j] == '-':
            j -= 1
        # Num 1
        while not RPN[j].isdigit():
            j -= 1
        if j != 0:
            while (RPN[j].isdigit() or RPN[j] == '.' or RPN[j] == '-'):
                j -= 1
        # Store num 1
        if j != 0 or (j == 0 and RPN[j] == " "):
            j += 1
        while RPN[j].isdigit() or RPN[j] == '.' or RPN[j] == '-':
            num1 += RPN[j]
            RPN = RPN[:j] + RPN[j + 1:]
        # Go to num 2
        while not RPN[j].isdigit():
            j += 1
        if RPN[j - 1] == '-':
            j -= 1
        # Store num 2
        while RPN[j].isdigit() or RPN[j] == '.' or RPN[j] == '-':
            num2 += RPN[j]
            RPN = RPN[:j] + RPN[j + 1:]

        # If number is not a float, append ".0" to string and cast to float    
        if num1.find('.') == -1:
            num1 += ".0"
        if num2.find('.') == -1:
            num2 += ".0"

        # Preform calculations
        if ops[x] == '+':
            result = float(num1) + float(num2)
        elif ops[x] == '-':
            result = float(num1) - float(num2)
        elif ops[x] == '*':
            result = float(num1) * float(num2)
        else:
            result = float(num1) / float(num2)

        # Insert result of operation to RPN string
        RPN = RPN[:j] + str(round(result, 1)) + RPN[j:]
        x += 1

        # Print final result
        if x == len(ops):
            print("Result: ", round(result, 1), end = '\n\n')

# Close file
f.close() 