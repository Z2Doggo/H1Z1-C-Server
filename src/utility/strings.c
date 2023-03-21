
i32
strings_cstring_length(char *cstring)
{
	i32 count = 0;
	while (*(cstring++))
	{
		++count;
	}

	return count;
}

String
strings_cstring_to_string(char *cstring)
{
	String result = { 0 };

	result.length = strings_cstring_length(cstring);
	result.content = cstring;

	return result;
}

b8
contains_only_letters(char *str) {
    i32 count = 0;
    char c;
    while ((c = str[count]) != '\0') {
        if (!isalpha(c)) {
            return 0;
        }
        count++;
    }
    return 1;
}