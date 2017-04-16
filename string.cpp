char *strcat(char *str1, const char *str2) // соединяем 1-ю строку со 2-й
{
	char *cp = str1;
	while(*cp++);
	while(*cp++ = *str2++);

	return str1;
}

int strlen(const char *str) // длина строки
{
	const shar *eos = str;
	while(*eos++);

	return (eos-str-1);
}

int strcmp(const char *str1, const char *str2) // сравнение строк (0-если совпадают)
{
	while(*str1==*str2 && *str1)
	{
		str1++;
		str2++;
	}

	return *str1 - *str2;
}

char *strcpy(char *str1, const char *str2) // копирует 2-ю строку на месту 1-й
{
	char *d = str1;
	while (*d++ = *str2++);

	return str1;
}

char *strchr(const char *str, int ch) // поиск символа в строке
{
	while(*str && *str != (char) ch)
	{
		str++;
	}
	if (*str == (char) ch)
	{
		return (char *) str;
	}

	return NULL;
}

char *substr(char *str, char *sub) // поиск подстроки в строке
{
	int i,j;
	for (i=j=0; str[i]!='\0'; ++i)
	{
		while((srt[i+j]!='\0') && (sub[j]==str[i+j]))
		{
			j++;
		}
		if (sub[j] == '\0')
		{
			return &str[i]
		}
		j = 0;
	}

	return NULL;
}