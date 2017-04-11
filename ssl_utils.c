int read_BIO( BIO bio, char* buffer, int buffer_len)
{
	int x = BIO_read (bio, buffer, buffer_len);
	if (x <= 0)
	{
		printf(" A wild error has appeared while reading.");
		return 1;
	}
	return 0;
}

void write_BIO( BIO bio, char* buffer, int buffer_len)
{
	int x = BIO_write( bio, buffer, buffer_len);
	if (x <= 0)
	{
		printf("A wild error as appeared while writing.");
		return 1;
	}
	return 0;
}

char* input_BIO(BIO bio, int len)
{
	if (len <= 0)
		return -1;

	char* line = malloc( sizeof(char) * len);
	
	if (fgets(line, len, stdin))
		if (write_BIO( bio, line, len) == 0)
			return line;
	free(line);
	return NULL;
}
