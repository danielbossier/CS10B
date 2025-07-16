strcpy()	strcpy(destStr, sourceStr)

Copies sourceStr (up to and including the null character) to destStr. destStr must have enough space for sourceStr, including the null character.	
strcpy(targetText, userText);
   // Copies "UNICEF" + null char to targetText 
strcpy(targetText, orgName);
   // Error: "United Nations" has > 10 chars
targetText = orgName;
   // Error: Strings can't be copied this way

---------------------------------------------------------------------------------

strncpy()	strncpy(destStr, sourceStr, numChars)

Copies up to numChars characters from sourceStr. destStr must have enough space for the copied characters, including the null character. If sourceStr has less than numChars characters, strncpy will fill the remaining space with the null character.	
strncpy(orgName, userText, 6);
   // orgName is "UNICEF Nations"

---------------------------------------------------------------------------------

strcat()	strcat(destStr, sourceStr)

//Copies sourceStr to end of destStr (starting at destStr's null character) and then appends a null character. destStr must have enough space for the addition of sourceStr plus the null character.	
strcat(orgName, userText);
   // orgName is "United NationsUNICEF"

---------------------------------------------------------------------------------

strncat()	strncat(destStr, sourceStr, numChars)

//Copies up to numChars characters from sourceStr to end of destStr (starting at destStr's null character) and then appends a null character. destStr must have enough space for the addition of sourceStr plus the null character. Copying of sourceStr characters continues until either the end of sourceStr or numChars is reached.	
strcpy(targetText, "abc");
   // targetText is "abc"
strncat(targetText, "123456789", 3);
   // targetText is "abc123"
   
---------------------------------------------------------------------------------

strchr()	strchr(sourceStr, searchChar)

Returns NULL if searchChar does not exist in sourceStr. (Else, returns address of first occurrence, discussed elsewhere).
NULL is defined in the cstring library.	
if (strchr(orgName, 'U') != NULL) { // 'U' exists in orgName?
   ...  // 'U' exists in "United Nations", branch taken
}  
if (strchr(orgName, 'u') != NULL) { // 'u' exists in orgName?
   ...  // 'u' doesn't exist (case matters), branch not taken
}

---------------------------------------------------------------------------------

strlen()	size_t strlen(sourceStr)

Returns number of characters in sourceStr up to, but not including, first null character. size_t is integer type.	
x = strlen(orgName);    // Assigns 14 to x 
x = strlen(userText);   // Assigns 6 to x
x = strlen(targetText); // Error: targetText may lack null char

---------------------------------------------------------------------------------

strcmp()	int strcmp(str1, str2)

Returns 0 if str1 and str2 are equal, non-zero if they differ.	
if (strcmp(orgName, "United Nations") == 0) {
   ... // Equal, branch taken
}
if (strcmp(orgName, userText) != 0) {
   ... // Not equal, branch taken

---------------------------------------------------------------------------------