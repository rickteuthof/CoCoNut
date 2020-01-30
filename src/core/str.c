#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "core/str.h"
#include "core/ast_memory.h"


char *create_ast_string(const char *source){
	int length = strlen(source);
	char *new_string = ast_alloc((length+1) * sizeof(char), ast_string);
	strcpy(new_string, source);
  new_string[length] = '\0';
	return new_string;
}

void free_ast_string(char *source){
	ast_free(source);
}

/*******************************************************************************
 *
 * Description: Copy string and allocate memory for new string.
 *
 * Parameters: - source, char* to copy
 *
 * Return: - new copied char*
 *
 *******************************************************************************/

char *copy_ast_string(char *source)
{
  char* ret;
  int length = strlen(source);
  if (source != NULL) {
    ret =  ast_alloc((length+1) * sizeof(char), ast_string);
    strcpy(ret, source);
  } else {
    ret = NULL;
  }
  ret[length] = '\0';
  return ret;
}

/*******************************************************************************
 *
 * Description: Copy string and allocate memory for new string.
 *
 * Parameters: - source, char* to copy
 *
 * Return: - new copied char*
 *
 *******************************************************************************/

char *copy_string(char *source)
{
  char* ret;
  int length = strlen(source);
  if (source != NULL) {
    ret =  malloc((length+1) * sizeof(char));
    strcpy(ret, source);
  } else {
    ret = NULL;
  }
  ret[length] = '\0';
  return ret;
}

/*******************************************************************************
 *
 * Description: Copy string and allocate memory for new string. 
 *              Copy only maxlen characters.
 *
 * Parameters: - source, string to copy
 *             - maxlen, number of characters to copy
 *
 * Return: - new copied string
 *
 *******************************************************************************/

// str *STRncpy( str *source, int maxlen)
// {
//   str *ret;
//   int max;
   
//   if (source != NULL) {
//     max = source->length;
//     if (max > maxlen) {
//       max = maxlen;
//     }
// 	ret = malloc(sizeof(str) + (max+1) * sizeof(char));
//     strncpy(ret->text, source->text, max);
// 	ret->length = max;

//     /* make sure string ends with 0 */
//     ret->text[max] = '\0';
//   }
//   else {
//     ret = NULL;
//   }

//   return ret;
// }

// /** <!--********************************************************************-->
//  *                                                                             
//  * @fn char *STRsubStr( const char *string, int start, int len)
//  *                                                                             
//  * @brief copy part of a string from start to start + len.
//  *        if len is <0 then len is relative to the length of the string.
//  *                                                                           
//  *****************************************************************************/
// str *STRsubStr( const char *string, int start, int len)
// {
//   int strlen = 0;
//   char *ret = NULL;
  
//   strlen = STRlen( string);

//   if ( len < 0){
//     len = strlen + len; /* + - => - */
//   }
  
//   if ( ( start + len) > strlen){ /* to long take what we can */
//     len = strlen - start;
//   } 
  
//   if ( start > strlen){
//     ret = STRnull();
//   } else {
//     ret = memcpy( MEMmalloc( sizeof( char) * ( len + 1)),
//                   string + start, /* move to start of sub string */
//                   len); 
//     ret[len] = '\0';
//   }

//   return ret;
// }

// /** <!--********************************************************************-->
//  *                                                                             
//  * @fn char *STRnull( )
//  *                                                                             
//  * @brief return an empty string
//  *                                                                           
//  *****************************************************************************/
// char *STRnull( )
// {
//   str *ret = NULL;
  
//   ret = malloc(sizeof(str) + 1 * sizeof(char));
//   ret->length = 0;
//   ret->text[0] = '\0';

//   return ret;
// }

// /*******************************************************************************
//  *
//  * Description: Yield length of string
//  *
//  *  Mostly to provide a complete interface and to avoid using standard
//  *  string facilities throughout the compiler.
//  *
//  *******************************************************************************/

// int STRlen(str *source)
// {
//   int len; 

//   if (source == NULL) {
//     len = 0;
//   }
//   else {
//     len = source->length;
//   }
  
//   return len;
// }