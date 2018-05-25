/*******************************
 *
 *  Project Name: String 'Em Up.
 *  Description: Write a subset of the standard C library.
 *  File names: new_string.h new_string.c
 *  Date: 2 March 2018
 *  Authors: Jonathan Freaney, Tasin Choudhury.
 *
 *******************************/

#include "new_string.h"

char* new_strcpy(char* destination, const char* source) {
	char *copy = destination;

	// Copy until '\0' is reached.
	while (*destination++ = *source++);

	return copy;
}

char* new_strncpy(char* destination, const char* source, size_t n) {
	char *copy = destination;

	// Copy until '\0' is reached or n == 0.
	while (*source && n--)
		*destination++ = *source++;
	*destination = '\0';

	return copy;
}

int new_strcmp(const char* string1, const char* string2) {
	// Check equivalence.  Stop if '\0'.
	for (; *string1 == *string2; string1++, string2++)
		if (*string1 == '\0')
			return 0;

	// Case if not equivalent.
	return *(unsigned char *)string1 - *(unsigned char *)string2;
}

int new_strncmp(const char* string1, const char* string2, size_t n) {
	// Check equivalence for n chars.
	for (; n-- > 0; string1++, string2++)
		if (*string1 != *string2)
			return *(unsigned char *)string1 - *(unsigned char *)string2;

	// Case if equivalent.
	return 0;
}

char* new_strcat(char* destination, const char* source) {
	char *end = destination;
	// Skip to end of destination at '\0'.
	while (*end != '\0')
		end++;

	// Copy over chars until source expires.
	do {
		*(end++) = *source;
	} while (*(source++) != '\0');

	return destination;
}

char* new_strncat(char* destination, const char* source, size_t n) {
	char *end = destination;
	// Skip to end of destination at '\0'.
	while (*end != '\0')
		end++;

	// Copy over n chars.
	while (n-- > 0)
		*(end++) = *(source++);

	return destination;
}

size_t new_strlen(const char* string) {
	size_t length = 0;

	while (string[length] != '\0')
		length++;

	return length;
}

char* new_strchr(const char* string, int character) {
	// Check all chars up and including the '\0' char.
	do {
		if (*string == character)
			return (char *) string;

	} while (*(string++) != '\0');

	return NULL;
}

char* new_strstr(const char* haystack, const char* needle) {
	size_t haystackLength = new_strlen(haystack);
	size_t needleLength = new_strlen(needle);

	// Move char-by-by and compare until it works or runs out of chars.
	for (; *haystack != '\0'; haystack++, haystackLength--) {
		// In case haystack ended before needle.
		if (haystackLength < needleLength)
			return NULL;

		// Try comparing at this spot in haystack.
		if (new_strncmp(haystack, needle, needleLength) == 0)
			return (char *) haystack;
	}

	// In case needle was not empty.
	return *needle == '\0' ? (char *) haystack : NULL;
}

