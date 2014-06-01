#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Count the number of characters in a NULL-terminated string s (not
 * counting the NULL character).
 *
 * Example: my_strlen("foo") should return 3.
 */
int my_strlen(const char *s)
{
    int count_number = 0;//initialize count_number

    while(s[count_number])//if the character in s has a value
    {
      count_number++;//count_number increased by 1
    }

    return count_number;
}

/**
 * Count the number of occurrences of a particular character c in a
 * NULL-terminated string s.
 *
 * Example: my_countchar("foo", 'o') should return 2.
 */
int my_countchar(const char *s, char c)
{   
    int count_number = 0;//the number of character c in the s character array
    int lcv;//loop control variable for for loop
    int length = my_strlen(s);//the length of the character s

    for(lcv = 0; lcv < length; lcv++)//check for every character in the array
    {
      if(s[lcv] == c)//check if the character is c
      {
        count_number++;//increase count number by 1
      }
    }
    
    return count_number;
}

/**
 * Convert an entire NULL-terminated string s to uppercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: toupper(c) is a macro that returns
 * the uppercase version of a character c.
 *
 * Example: char foobar[10] = "ece264";
 * my_strupper(foobar) changes foobar to "ECE264".
 */
void my_strupper(char *s)
{
  int length = my_strlen(s);//length of the character array s
  int lcv;//loop control variable of the for loop
  
  for(lcv = 0; lcv < length; lcv++)//check every character in the array
  {
    if(s[lcv] >= 97 && s[lcv] <= 122)//check if the character is a lower case
    {
      s[lcv] = s[lcv] - 32;//if the character is a lower case, change it to upper
    }
  }
}

/**
 * Convert an entire NULL-terminated string s to lowercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: tolower(c) is a macro that return
 * the lowercase version of a character c.
 *
 * Example: char foobar[10] = "ECE264";
 * my_strupper(foobar) changes foobar to "ece264".
 */
void my_strlower(char *s)
{
  int length = my_strlen(s);//the length of the character array s
  int lcv;//loop control variable of the for loop
  
  for(lcv = 0; lcv < length; lcv++)//check every character in the character array
  {
    if(s[lcv] >= 65 && s[lcv] <= 90)//check if the character is in upper case
    {
      s[lcv] = s[lcv] + 32;//if the character is in upper case, change it to lower case
    }
  }
}

/** 
 * Copy the contents of a NULL-terminated string s2 into the memory
 * pointed to by s1.  Any existing data in s1 will be overwritten by
 * the contents of s2.  Note: you can assume that there is sufficient
 * memory available in s1.  Hint: Don't forget to terminate the new
 * string with '\0'!
 * 
 * Example: char foo[10];
 * my_strcpy(foo, "bar2") changes foo to "bar2".
 */
void my_strcpy(char *s1, const char *s2)
{
  int length_input = my_strlen(s2);//the length of the character array
  int lcv;//loop control variable of for loop

  for(lcv = 0; lcv < length_input; lcv++)//check every character in the character array
  {
    s1[lcv] = s2[lcv];//copy the character in array s2 to s1
  }
  s1[lcv] = '\0';//terminate the new string with '\0'
}

/**
 * Copy the first n characters of a NULL-terminated string s2 into the
 * memory pointed to by s1. Any existing data in s1 will be
 * overwritten by the contents of s2.  Note: you can assume that there
 * is sufficient memory available in s1.  Hint: Don't forget to
 * terminate the new string with '\0'!
 * 
 * Example: char foo[10];
 * my_strncpy(foo, "bar", 1) changes foo to "b".
 */
void my_strncpy(char *s1, const char *s2, int num)
{
  int lcv;//loop control variable for the for loop

  for(lcv = 0; lcv < num; lcv++)//check every character in the strings with the required number
  {
    s1[lcv] = s2[lcv];//copy the characters in string 2 to string 1
  }
  s1[lcv] = '\0';//terminate the string with '\0'
}

/** 
 * Concatenate (append) the contents of a NULL-terminated string s2
 * onto the end of the NULL-terminated string s1.  Note: you can
 * assume that there is sufficient memory available in s1.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "ece";
 * my_strcat(foo, "bar") changes foo to "ecebar".
 */
void my_strcat(char *s1, const char *s2) 
{
  int length_s1 = my_strlen(s1);//the length of the string 1
  int length_s2 = my_strlen(s2);//the length of the string 2
  int lcv;//loop control variable of the for loop

  for(lcv = 0; lcv < length_s2; lcv++)//check every character in string 2
  {
    s1[lcv + length_s1] = s2[lcv];//copy string 2 to the end of string 1
  }
  s1[lcv + length_s1] = '\0';//terminate the string with '\0'
}

/** 
 * Concatenate (append) the first n characters of a NULL-terminated
 * string s2 onto the end of the NULL-terminated string s1.  Note: you
 * can assume that there is sufficient memory available in s1.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "ece";
 * my_strcat(foo, "bar", 1) changes foo to "eceb".
 */
void my_strncat(char *s1, const char *s2, int num)
{
  int length_s1 = my_strlen(s1);//the lengh of the string 1
  int lcv;//loop control variable of the for loop

  for(lcv = 0; lcv < num; lcv++)//check every character in the strings with the required number
  {
    s1[lcv + length_s1] = s2[lcv];//copy string 2 with required characters into string 1
  }
  s1[lcv + length_s1] = '\0';//terminate the string with '\0'
}

/**
 * Return a pointer to the first occurrence of a NULL-terminated
 * substring s2 in a NULL-terminated string s1.  If s2 does not appear
 * in s1, the empty (NULL) pointer is returned.
 * 
 * Example: my_strstr("hello world!", "test") will return NULL.
 * Example(2): my_strstr("foobar", "bar") will return a pointer to the
 * "bar" portion of the "foobar" argument.
 */
const char *my_strstr(const char *s1, const char *s2)
{
  int length_s1 = my_strlen(s1);//length of string 1
  int length_s2 = my_strlen(s2);//length of string 2
  int lcv; //loop control variable of the for loop
  int count;//count number of the position

  for(lcv = 0; lcv < length_s1; lcv++)
  {
    count = lcv;//set position to zero first
    while(s1[count] == s2[count - lcv] && s1[count] && s2[count - lcv])//check if there are the same string in character array 1 and character array 2
    {
      count++;//count number to represent the current position
    }
    if((count - lcv) == length_s2)//check if the length of the string 2 equals to the same string in string 1
    {
      return &s1[count - length_s2];//return the first occurence of the same string in the character array
    }
  }
  
  return NULL;//return NULL if not occurences have been found
}


/**
 * Insert a NULL-terminated string s2 in the NULL-terminated string s1
 * at position pos.  All characters following position pos in s1 will
 * be moved to follow directly after the inserted characters from s2;
 * no characters will be overwritten.  Note: you can assume that there
 * is sufficient memory available in s1.
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos to its new location
 * starting from the back of the string and going forwards.
 * 
 * Insertions should happen BEFORE the character position referenced
 * by pos.  In other words, inserting s2 at position 0 (the first
 * character of a string) in s1 is equivalent to the string s2
 * followed by string s1.
 * 
 * If the character position pos is higher (or equivalent to) the
 * length of string s1, s2 will simply be appended to the end of s1
 * (i.e. it is equivalent to my_strcat(s1, s2);
 * 
 * Example: char foo[10] = "ece";
 * my_strinsert(foo, "bar", 0) changes foo to "barece".
 * 
 * Example(2): char foo[10] = "ece";
 * my_strinsert(foo, "bar", 100) changes foo to "ecebar".
 */
void my_strinsert(char *s1, const char *s2, int pos)
{
  int length_s1 = my_strlen(s1);//length of string 1
  int length_s2 = my_strlen(s2);//length of string 2
  int lcv;//loop control variable of the for loop

  if(pos >= length_s1)//if position larger or equal to length_s1, then just use my_strcat to copy s2 to the end of s1
  {
    my_strcat(s1, s2);
  }
  else
  {
    for(lcv = length_s1 + length_s2 - 1; lcv >= (pos + length_s2); lcv--)//for loop to check all the variables start at the position required and end at the end of string 1
    {
      s1[lcv] = s1[lcv - length_s2];//copy the overlapped characters in string 1 to the end
    }
    for(lcv = 0; lcv < length_s2; lcv++)//check all the characters in string 1 after the position
    {
      s1[lcv + pos] = s2[lcv];//copy string 2 in string 1
    }
    s1[length_s1 + length_s2] = '\0';//terminate the string with '\0'
  }
}

/**
 * Delete a portion of the NULL-terminated string s that starts at
 * character position pos and is length characters long.  All
 * characters following position pos + length in s will be moved up to
 * follow directly after the characters before position pos. 
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos + length to their new
 * location.
 * 
 * Deletions should happen BEFORE the character position referenced by
 * pos.  In other words, deleting position 0 (the first character of a
 * string) in s means will start deleting from the first character.
 *
 * If the character position pos is higher (or equivalent to) the
 * length of string s, the function will do nothing.
 * 
 * If the length of the deleted portion from its starting position pos
 * extends past the end of the string, the remainder of the string
 * will be deleted.
 * 
 * Example: char foo[10] = "ecebar";
 * my_strdelete(foo, 3, 3) changes foo to "ece".
 *
 * Example(2): char foo[10] = "ecebar";
 * my_strdelete(foo, 0, 3) changes foo to "bar".
 * 
 * Example(3): char foo[10] = "ecebar";
 * my_strdelete(foo, 0, 34) changes foo to "".
 */
void my_strdelete(char *s, int pos, int length)
{
  int length_s = my_strlen(s);//length of the string s
  int lcv;//loop control variable for the for loop

  if(pos >= length_s)//if position larger than or equal to the length of string s
  {
    return;//return do nothing to the string
  }
  else if(pos < length_s && length >= (length_s - pos))//if the position is less than the length of the string and the required length is larger or equal to the subtraction between the length of s and position
  {
    for(lcv = pos; lcv < (pos + length); lcv++)//use for loop to delete the required characters with required length
    {
      s[lcv] = '\0';//delete by changing it to '\0'
    }
    
  }
  else
  {
    for(lcv = pos; lcv < (pos + length); lcv++)//use for loop to delete the required characters with required length
    {
      s[lcv] = '\0';//delete by changing it to '\0'
    }
    for(lcv = pos + length; lcv < (length_s + length); lcv++)//use for loop to copy all the rest of the characters forward
    {
      s[lcv - length] = s[lcv];//copy the rest of the string forward
    }
    s[length_s + length] = '\0';//terminate the string with '\0'
  }
}
