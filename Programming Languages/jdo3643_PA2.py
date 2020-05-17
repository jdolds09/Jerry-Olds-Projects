# Author: Jerry Olds
# ID: 1001533643
# Date: 10/21/2018
# Lab 2

import os

# Find file
file_name = "input.txt"
for root, directories, files in os.walk('.'):
    for name in files:
        if name == file_name:
            path = os.path.join(root, name)

f = open(path, "r") # Open file for reading
lines = f.readlines() # Read the lines of the file in to lines variable
brace_depth = 0 # Declare brace depth variable

# Find brace depth for every line
for i in lines:
    # Find braces before and after sets of quotations  
    if i.find('"') != -1 and i.count('"') > 1:
        start = 0 # This will hold the position after the end quotation mark of last set of quotations
                  # in case of multiple set of quotations on same line
        quotation_sets = i.count('"') # Count how many sets of quotations on same line
        
        # Calculate brace depth given one or multiple set of quotations in a single line
        for x in range(quotation_sets):
            first = i.find('"', start) # Find position of first quotation mark of set
            last = i.find('"', first + 1) # Find postion of last quotation mark of set
            
            # Increment brace depth if { is found before or after set of quotations
            if i.find('{') != 0: 
                brace_depth += i.count('{', 0, first)
                brace_depth += i.count('{', last)
            # Decrement brace depth if } is found before or after set of quotations
            if i.find('}') != 0:
                brace_depth -= i.count('}', 0, first)
                brace_depth -= i.count('}', last)
            
            start = last + 1 # set to position after ending quotation mark
            
            # End loop if there are no more set of quotations
            if i.find('"', start) == -1:
                break

        # Handle if there are braces after a comment on a line with quotations
        if i.find('//') != -1:
            if i.find('{', i.find('//')) != -1:
                brace_depth -= i.count('{', i.find('//') )
            if i.find('}', i.find('//')) != -1:
                brace_depth += i.count('}', i.find('//') )
                

        # Print line with brace depth
        print(brace_depth, " ", i)

    # Find braces before comment mark 
    elif i.find('//') != -1:
        comment_position = i.find('//')
        
        # Increment brace depth if { is found before comment mark
        if i.find('{', 0, comment_position) != -1:
            brace_depth += i.count('{')
        # Decrement brace depth if } is found before comment mark
        if i.find('}', 0, comment_position) != -1:
            brace_depth -= i.count('}')
        
        # Print line with brace depth
        print(brace_depth, " ", i)
    
    # Find braces in lines that contain no comments or quotations
    else:
        # Increment brace depth
        if i.find('{') != -1:
            brace_depth += i.count('{')
        # Decrement brace depth
        if i.find('}') != -1:
            brace_depth -= i.count('}')

        # Print line with brace depth
        print(brace_depth, " ", i)



f.close() # Close file