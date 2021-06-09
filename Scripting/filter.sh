#!/bin/bash

#Empty combined.txt every time
> combined.txt

#Go through each file in files/ directory
for file in $(find files -type f); do
    #Store all contents from the file into a variable
    contents="`cat $file`"
    
    #Check the contents for any substrings of the keyword
    if [[ $contents == *$1* ]]; then
        #Append the contents to combined.txt if true
        echo $contents >> combined.txt
    fi
done
