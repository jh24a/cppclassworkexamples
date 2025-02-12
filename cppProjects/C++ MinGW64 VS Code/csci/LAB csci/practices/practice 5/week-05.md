# Try this website
https://markdownlivepreview.com/

Copy the contents of this file and paste to the left side.


# Interstate highway numbers

Primary U.S. interstate highways are numbered 1-99. Odd numbers (like the 5 or 95) go north/south, and evens (like the 10 or 90) go east/west. Auxiliary highways are numbered 100-999, and service the primary highway indicated by the rightmost two digits. Thus, the 405 services the 5, and the 290 services the 90.

Given a highway number, indicate whether it is a primary or auxiliary highway. If auxiliary, indicate what primary highway it serves. Also indicate if the (primary) highway runs north/south or east/west.

Examples: If the input is:

90

the output is:

The 90 is primary, going east/west.

Example: If the input is:

    290

the output is:

    The 290 is auxiliary, serving the 90, going east/west.

Example: If the input is:

    0

the output is:

    0 is not a valid interstate highway number. 

# Leap year

A year in the modern Gregorian Calendar consists of 365 days. In reality, the earth takes longer to rotate around the sun. To account for the difference in time, every 4 years, a leap year takes place. A leap year is when a year has 366 days: An extra day, February 29th. The requirements for a given year to be a leap year are:

1) The year must be divisible by 4

2) If the year is a century year (1700, 1800, etc.), the year must be evenly divisible by 400

Some example leap years are 1600, 1712, and 2016.

Write a program that takes in a year and determines whether that year is a leap year.

Examples: If the input is:

    1712

the output is:

    1712 is a leap year. 

Example: If the input is:

    1913

the output is:

    1913 is not a leap year.


# Text message expander

Assume you have a list of abbreviations as follows:

- BFF -- best friend forever
- IDK -- I don't know
- JK -- just kidding
- TMI -- too much information
- TTYL -- talk to you later

Now given an input string, expand it using above rules.

Example: If the input is:

    IDK BFF

the output is:

    I don't know best friend forever

Example: If the input is 

    IDK how that happened. TTYL.

the output is:
    I don't know how that happened. talk to you later.


# Extra practice

Given today's date in the form of mmddyyyy, calculate how many days have passed from the beginning of the year.

Example: If the input is

    01012050

the output is:

    0

Example: If the input is

    02012010

the output is:

    31

*hints:* Do not forget to consider the leap year case, and check whether the input is valid or not.