# Assignment 1
Jose Huacuja

The problem is that I need to convert a number (including negative values) given by the user in the "string" data type to the "int" data type.
If the user inputs a letter or symbol in the string then the program must return 0.

- The way I attack this problem is to first check if the string has a negative sign as its first index. But before I get into that, Let me explain how I made sure the string was only numbers. 

    - I made a for loop that gets the corresponding character of the string (ex. if it is the first iteration it gets the first character), turns it into data type char, and checks if the character is a number using the "isdigit" function, which requires char data type. 

        - NOTE: In this loop, the iterations start at "i=0" which means that the index will be 0, thus the loop will start with the first character. If it started at "i=1", the index will be 1, so the loop will start with the second character.

    - If the "isdigit" function returns "false", the program returns zero.
    This is becauase that means that the string contains at least one character that is not a number, so it is not necessary to check the other characters.

- To account for the negative sign , I made an if statement that has the condition "s.at(0) == '-'",  meaning that the first character is a negative sign. If this condition is true, the program runs the for loop with "i=1" , thus starting with the second character of the string. 

- If the condition is not true, then there is a following else statment that has the loop starting at "i=0" (starts with the first character of string).
