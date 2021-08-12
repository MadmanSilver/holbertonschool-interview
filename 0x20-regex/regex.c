#include "regex.h"

/**
 * regex_match - checks if a string matches with regex
 * @str: string to check
 * @pattern: regex to check against
 *
 * Return: 1 if match, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (!*str || !*pattern)
	{
		if (!*str && *pattern == '*' && !pattern[1])
			return (1);

		return (!*str && !*pattern);
	}

	if (*pattern == '*' || pattern[1] == '*')
		return (regex_match(str, pattern + 1) || regex_match(str + 1, pattern));

	if (*pattern == '.')
		return (regex_match(str + 1, pattern + 1));

	if (*str != *pattern)
		return (0);

	return (regex_match(str + 1, pattern + 1));
}
