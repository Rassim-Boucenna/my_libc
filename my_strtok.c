#include "my_libc.h"

char *
my_strtok(char *str, const char *delim)
{
	static char *saveptr = NULL;
	char *token;

	// Suppression de *delim == '\0' (et delim == NULL est optionnel mais
	// gardé par sécurité)
	if (delim == NULL)
		return NULL;

	if (str == NULL)
		str = saveptr;

	if (str == NULL)
		return NULL;

	// Passer les délimiteurs de début
	while (*str != '\0' && my_strchr(delim, *str) != NULL)
		str++;

	if (*str == '\0') {
		saveptr = NULL;
		return NULL;
	}

	// On marque le début du token
	token = str;

	// On avance jusqu'au prochain délimiteur
	while (*str != '\0' && my_strchr(delim, *str) == NULL)
		str++;

	// On coupe la chaîne et on sauvegarde la suite
	if (*str != '\0') {
		*str = '\0';
		saveptr = str + 1;
	} else {
		saveptr = NULL;
	}

	return token;
}