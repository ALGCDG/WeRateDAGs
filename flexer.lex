// declaring shorthands
Decimal [0-9]
Alphabet [a-zA-Z]
Printable [a-zA-Z_0-9]
Hex [a-fA-F0-9]

Type [int]
Operator[+,-,*,/,&,&&,|,||]

%%

"int"	{
		return TYPE(INT);
	}

P*	{
		return IDENTIFIER;
	}

[-]+D+	{
		return CONSTANT;
	}

P*	{
		return KEYWORD;
	}

\".\"	{
		/*
		String-LITERAL
		*/
	}

\'.\'	{
		/*
		Char
		*/
	}
