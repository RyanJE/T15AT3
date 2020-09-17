int main(void) {
	int ch = getchar();
	char* type = (isdigit(ch)) ? "digit" : "non-digit";
	/*
	if (isdigit(ch))
		type = "digit";
	else
		type = "non-digit";
	*/
	printf("'%c' is a %s\n", ch, type);
}
