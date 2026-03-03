# UTF-8 Analyzer

A small command-line tool that analyzes an input UTF-8 string and prints useful properties such as ASCII validity, byte length, code point count, code point values, and detected animal emojis.

## What it prints
Given one line of input, the program outputs:
- Whether the string is valid ASCII
- Uppercased ASCII-only version (non-ASCII bytes unchanged)
- Length in bytes
- Number of UTF-8 code points
- Bytes per code point (1/2/3/4)
- Substring of the first 6 code points
- Code points as decimal values
- Animal emojis found in the string (based on Unicode ranges)

# Example Output
$ ./utf8analyzer  
Enter a UTF-8 encoded string: My 🐩’s name is Erdős.  
Valid ASCII: false  
Uppercased ASCII: MY 🐩’S NAME IS ERDőS.  
Length in bytes: 27  
Number of code points: 21  
Bytes per code point: 1 1 1 4 3 1 1 1 1 1 1 1 1 1 1 1 1 1 2 1 1  
Substring of the first 6 code points: My 🐩’s  
Code points as decimal numbers: 77 121 32 128041 8217 115 32 110 97 109 101 32 105 115 32 69 114 100 337 115 46  
Animal emojis: 🐩  
