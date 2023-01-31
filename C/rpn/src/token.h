#ifndef TOKEN_H
#define TOKEN_H

enum token_type
{
	NUMBER,
	PLUS,
	MINUS,
	PROD,
	DIV,
	OPENPAR,
	CLOSEPAR
};

struct token
{
	enum token_type type;
	double value;
};


#endif
