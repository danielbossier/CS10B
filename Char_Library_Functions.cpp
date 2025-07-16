isalpha(c) -- Returns true if c is alphabetic: a-z or A-Z.	

isalpha('A');            // Returns true
isalpha(myString[0]);    // Returns true because 'H' is alphabetic
isalpha(myString[3]);    // Returns false because '9' is not alphabetic


---------------------------------------------------------------------------------

isdigit(c) -- Returns true if c is a numeric digit: 0-9.

isdigit(myString[3]);    // Returns true because '9' is numeric
isdigit(myString[4]);    // Returns false because ! is not numeric

---------------------------------------------------------------------------------

isalnum(c) -- Returns true if c is alphabetic or a numeric digit. Thus, returns true if either isalpha or isdigit would return true.

isalnum('A');            // Returns true
isalnum(myString[3]);    // Returns true because '9' is numeric

---------------------------------------------------------------------------------

isspace(c) -- Returns true if character c is a whitespace.

isspace(myString[5]);    // Returns true because that character is a space ' '.
isspace(myString[0]);    // Returns false because 'H' is not whitespace.

---------------------------------------------------------------------------------

islower(c) -- Returns true if character c is a lowercase letter a-z.

islower(myString[0]);    // Returns false because 'H' is not lowercase. 
islower(myString[1]);    // Returns true because 'e' is lowercase.
islower(myString[3]);    // Returns false because '9' is not a lowercase letter.

---------------------------------------------------------------------------------

isupper(c) -- Returns true if character c is an uppercase letter A-Z.	
isupper(myString[0]);    // Returns true because 'H' is uppercase. 
isupper(myString[1]);    // Returns false because 'e' is not uppercase.
isupper(myString[3]);    // Returns false because '9' is not an uppercase letter.

---------------------------------------------------------------------------------

isblank(c) -- Returns true if character c is a blank character. Blank characters include spaces and tabs.	

isblank(myString[5]);    // Returns true because that character is a space ' '. 
isblank(myString[0]);    // Returns false because 'H' is not blank.


---------------------------------------------------------------------------------

isxdigit(c) -- Returns true if c is a hexadecimal digit: 0-9, a-f, A-F.

isxdigit(myString[3]);  // Returns true because '9' is a hexadecimal digit.
isxdigit(myString[1]);  // Returns true because 'e' is a hexadecimal digit.
isxdigit(myString[6]);  // Returns false because 'G' is not a hexadecimal digit.

---------------------------------------------------------------------------------

ispunct(c) -- //Returns true if c is a punctuation character. Punctuation characters include: !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~	

ispunct(myString[4]);  // Returns true because '!' is a punctuation character. 
ispunct(myString[6]); // Returns false because 'G' is not a punctuation character.

---------------------------------------------------------------------------------

isprint(c) -- Returns true if c is a printable character. Printable characters include alphanumeric, punctuation, and space characters.	

isprint(myString[0]);    // Returns true because 'H' is a alphabetic. 
isprint(myString[4]);    // Returns true because '!' is punctuation.
isprint(myString[5]);    // Returns true because that character is a space ' '.
isprint('\0');           // Returns false because the null character is not printable

---------------------------------------------------------------------------------

iscntrl(c) -- Returns true if c is a control character. Control characters are all characters that are not printable.	

iscntrl(myString[0]);    // Returns false because 'H' is a not a control character 
iscntrl(myString[5]);    // Returns false because space is a not a control character
iscntrl('\0');           // Returns true because the null character is a control character

---------------------------------------------------------------------------------

---------------------------------------------------------------------------------

