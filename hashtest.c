#include "hashhead.h"

void main(int argc, char *argv[]) {

	node *a[256];
	FILE *f = stdout;
	FILE *fi = stdin;
	char str[2000];
	char word_t[50];
	char *estr, *letters, *symbols;
	unsigned int j;
	int k;
	letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	for (j = 0; j < 256; j++){
		a[j] = (node*)malloc(sizeof(node*));
		a[j] = NULL;
	}
	switch (argc) {
	case 1:
		printf("hashtable, version 0.0.0.1 x86\n");
		printf("Usage: Input an text file\n");
		printf("hashtable.exe -in filename -o|-out filename\n");
		printf("Output: file containing amount of each word\n");
		break;
	case 2:
		if ((strcmp(argv[1], "-help") == 0) || (strcmp(argv[1], "-HELP") == 0)){
			printf("hashtable, version 0.0.0.1 x86\n");
			printf("Usage: Input an text file\n");
			printf("hashtable.exe -in filename -o|-out filename\n");
			printf("Output: file containing amount of each word\n");
			break;
		}
	case 3:
		if (strcmp(argv[1], "-in") == 0){
			if (fopen_s(&fi, argv[2], "r") == 0)
			{
				while (1){
					estr = fgets(str, 2000, fi);
					if (estr == NULL)
					{
						if (feof(fi) != 0)
						{
							fclose(fi);
							break;
						}
						else
						{
							printf("\nFile read error\n");
							break;
						}
					}
					j = 0;
					while ((poscinstr(letters, str[j]) <0) && (j < strlen(str))){
						j++;
					}
					k = 0;
					while (j < strlen(str)){
						word_t[k] = str[j];
						k++;
						j++;
						if (poscinstr(letters, str[j]) <0){
							word_t[k] = '\0';
							if ((strlen(word_t) < 11) && (strlen(word_t) > 0)) {
								insert(a, word_t);
							}
							k = 0;
							while ((poscinstr(letters, str[j]) <0) && (j < strlen(str))){
								j++;
							}
						}
					}
					word_t[k] = '\0';
					if ((strlen(word_t) < 11) && (strlen(word_t) > 0)) {
						insert(a, word_t);
					}
				}
				prntable(a);
				getchar();
				break;
			}
			else{
				printf("Input file not opened.");
				getchar();
				break;
			}
		}
	case 5:
		if ((strcmp(argv[1], "-in") == 0) && ((strcmp(argv[3], "-o") == 0) || (strcmp(argv[3], "-out") == 0))){
			if (fopen_s(&fi, argv[2], "r") == 0)
			{
				while (1){
					estr = fgets(str, 2000, fi);
					if (estr == NULL)
					{
						if (feof(fi) != 0)
						{
							fclose(fi);
							break;
						}
						else
						{
							printf("\nFile read error\n");
							break;
						}
					}
					j = 0;
					while ((poscinstr(letters, str[j]) < 0) && (j < strlen(str))){
						j++;
					}
					k = 0;
					while (j < strlen(str)){
						word_t[k] = str[j];
						k++;
						j++;
						if (poscinstr(letters, str[j]) <0){
							word_t[k] = '\0';
							if ((strlen(word_t) < 11) && (strlen(word_t) > 0)) {
								insert(a, word_t);
							}
							k = 0;
							while ((poscinstr(letters, str[j]) < 0) && (j < strlen(str))){
								j++;
							}
						}
					}
					word_t[k] = '\0';
					if ((strlen(word_t) < 11) && (strlen(word_t) > 0)) {
						insert(a, word_t);
					}
				}
				if (fopen_s(&f, argv[4], "w") == 0)
				{
					prntable_f(a, f);
					fclose(f);
				}
				else{
					printf("Output file not opened.");
					getchar();
					break;
				}
				break;
			}
			else{
				printf("Input file not opened.");
				getchar();
				break;
			}
		}
	}
	return;
}