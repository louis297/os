#include "string.h"

inline void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len)
{
	for(; len != 0; len--){
		*dest++ = *src++;
	}
}

inline void memset(void *dest, uint8_t val, uint32_t len)
{
	uint8_t *dst = (uint8_t *) dest;
	for (; len != 0; len--){
		*dst++ = val;
	}
}

inline void bzero(void *dest, uint32_t len)
{
	memset(dest, 0, len);
}

int strcmp(const char *str1, const char *str2)
{
	int i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] > str2[i]){
			return 1;
		} else if (str1[i] < str2[i]){
			return -1;
		}
		i++;
	}
	if (str2[i] != '\0') {
		return -1;
	} else {
		return 0;
	}
}

char *strcpy(char *dest, const char *src)
{
	char *ret = dest;
	char *source = src;
	while(*source)
	{
		*ret++ = *source;
		source++;
	}
	return ret;
}

char *strcat(char *dest, const char *src)
{
	char *ret = dest;
	char *source = src;
 	while(*dest){
		dest++;
	}
	while(*source){
		*dest++ = *source++;
	}
	dest = '\0';
	return ret;
}

int strlen(const char *src)
{
	int len = 0;
	while(src[len]){
		len++;
	}
	return len;
}

