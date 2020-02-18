int main()
{

yoliesProgramHeader();
yoliesProgramExplanation();

char operation = null;
double operand1 = 0.0,
       operand2 = 0.0,
       result = 0.0;

cout << "Please enter an operation (*/-+) and two real numbers to compute: /n";
cin >> operation >> operand1 >> operand2;

if(operation == '*' || operation == '/' || operation == '-' || operation == '+')
{
	switch (operation)
	{
		case *:
		result = operand1 * operand2;
		break;
		case /:
		result = operand1 / operand2;
		break;
		case -:
		result = operand1 - operand2;
		break;
		case +:
		result = operand1 + operand2;
		break;
	}
}
else
	cout << "Please enter a mathematical operation such as *, / , + ,-:
return 0;

}
