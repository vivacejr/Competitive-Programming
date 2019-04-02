#include<stdio.h>
#include<string.h>
char str[1000005];

int main()
{
	int t,i,j;

	scanf("%i",&t);

	while(t--) {

		scanf("%s",str);

		int lenght = strlen(str);

		j = lenght;
		i = -1;

		while(++i <= --j) {
			if(str[i] != str[j]) {
				break;
			}
		}

		if(j < i) {
			/*   Number is palindrome   */

			if(lenght & 1) {
				/* odd lenght  */

				if(str[lenght/2] < '9'){
					/* check the middle one not 9 */

					str[lenght/2]++;

					printf("%s\n",str);
				}

				else {
					str[lenght/2] = '0';

					i = lenght/2 - 1;
					j = lenght/2 + 1;

					while(i >= 0) {

						if(str[i] < '9') {
							str[i]++;
							str[j]++;
							break;
						}

						else {
							str[i] = str[j] = '0';
						}

						i--;
						j++;
					}

					if(i < 0) {
						printf("1");

						i = lenght;
						while(--i > 0) {
							printf("0");
						}

						printf("1\n");
					}

					else {

						printf("%s\n",str);
					}
				}
			}

			else {
				/*  even lenght  */

				i = lenght/2 - 1;
				j = lenght/2;

				while(i >= 0) {

					if(str[i] < '9') {
						str[i]++;
						str[j]++;
						break;
					}

					else {
						str[i] = str[j] = '0';
					}

					i--;
					j++;
				}

				if(i < 0) {
					printf("1");

					i = lenght;
					while(--i > 0) {
						printf("0");
					}

					printf("1\n");
				}

				else {

					printf("%s\n",str);
				}
			}
		}

		else {
			if(lenght & 1) {
				i = lenght/2 - 1;
				j = lenght/2 + 1;
			}

			else {
				i =lenght/2 - 1;
				j = lenght/2;
			}

			int flag;

			while(i >= 0) {

				if(str[i] - str[j] > 0) {
					flag = 1;
					break;
				}

				else if( str[i] - str[j] < 0 ) {
					flag = 2;
					break;
				}

				i--;
				j++;
			}

			if(lenght & 1) {
				i = lenght/2 - 1;
				j = lenght/2 + 1;
			}

			else {
				i = lenght/2 - 1;
				j = lenght/2;
			}

			if(flag == 1) {    /*  line 1*/
				while(i >= 0) {
					str[j] = str[i];

					i--;
					j++;
				}
			}

			else if(flag == 2 && lenght&1 && str[lenght/2] < '9'){    /* line 2*/
				str[lenght/2]++;

				i = lenght/2 - 1;
				j = lenght/2 + 1;

				while(i >= 0) {
					str[j] = str[i];
					i--;
					j++;
				}
			}

			else {                          /* line 3   */

				if( lenght & 1) {
					str[lenght/2] = '0';
				}

				while(i >= 0) {
					if(str[i] < '9') {
						str[i]++;
						str[j] = str[i];
						break;
					}

					else {
						str[i] = str[j] = '0';
					}
					i--;
					j++;
				}

				while(i >= 0) {
					str[j] = str[i];

					i--;
					j++;
				}
			}

			printf("%s\n",str);
		}
	}

	return 0;
}
