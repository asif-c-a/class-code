#include <stdio.h>

char nEq[50], Q[25];

void conPostfix(char eq[])
{
	int i = 0, k = 0, top = -1;

	while (eq[i] != '\0')
	{
		if (eq[i] == '(')
		{
			Q[++top] = eq[i];
		}
		else if (eq[i] >= 'a' && eq[i] <= 'z' || eq[i] >= 'A' && eq[i] <= 'Z')
		{
			nEq[k++] = eq[i];
		}
		else if (eq[i] == '+' || eq[i] == '-' || eq[i] == '*' || eq[i] == '/')
		{
			Q[++top] = eq[i];
		}
		else if (eq[i] == ')')
		{
			while (top >= 0 && Q[top] != '(')
			{
				nEq[k++] = Q[top--];
			}
			if (top >= 0 && Q[top] == '(')
			{
				top--;
			}
		}
		i++;
	}

	while (top >= 0)
	{
		nEq[k++] = Q[top--];
	}

	nEq[k] = '\0'; 
}

int main()
{
	char eq[50];

	printf("Input an equation: ");
	scanf("%s", eq);

	conPostfix(eq);

	printf("Postfix: %s\n", nEq);

	return 0;
}
