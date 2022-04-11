#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>

int cmp_string(const void* pa, const void* pb) {
	return (strcmp(*((char**)pa), *((char**)pb)));
}

int main() {
	FILE* in, * out, * tape, * tape1, * tape2;
	size_t i = 0, len = 0, max = 8, max2 = 4, num = 0, numcur = 0, counter1 = 0, counter2 = 0;
	int cmp = 0;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	tape = fopen("tape.txt", "w+");
	tape1 = fopen("tape1.txt", "w+");
	tape2 = fopen("tape2.txt", "w+");

	char** str = (char**)calloc(4, sizeof(char*));
	for (size_t j = 0; j < 4; j++) {
		str[j] = (char*)calloc(10000, sizeof(char));
	}
	while (1) {
		for (i = 0; i < 4; i++) {
			if (fgets(str[i], 10000, in) == NULL) {
				break;
			}
		}
		if (i == 0) {
			break;
		}

		len = strlen(str[i - 1]);

		if (str[i - 1][len - 1] != '\n') {
			str[i - 1][len] = '\n';
			str[i - 1][len + 1] = 0;
		}

		qsort(str, i, sizeof(char*), cmp_string);

		for (size_t j = 0; j < i; j++) {
			fputs(str[j], tape1);
		}

		num += i;

		if (i < 4) {
			break;
		}


		for (i = 0; i < 4; i++) {
			if (fgets(str[i], 10000, in) == NULL) {
				break;
			}
		}

		if (i == 0) {
			break;
		}

		len = strlen(str[i - 1]);
		if (str[i - 1][len - 1] != '\n') {
			str[i - 1][len] = '\n';
			str[i - 1][len + 1] = 0;
		}

		qsort(str, i, sizeof(char*), cmp_string);

		for (size_t j = 0; j < i; j++) {
			fputs(str[j], tape2);
		}

		num += i;

		if (i < 4) {
			break;
		}
	}

	while (1) {
		fseek(tape1, 0, SEEK_SET);
		fseek(tape2, 0, SEEK_SET);
		fclose(tape);
		tape = fopen("tape.txt", "w+");

		if (num <= max) {
			fgets(str[0], 10000, tape1);
			fgets(str[1], 10000, tape2);

			while (1) {
				cmp = strcmp(str[0], str[1]);

				if (cmp <= 0) {
					fputs(str[0], out);
					if (fgets(str[0], 10000, tape1) == NULL) {
						fputs(str[1], out);
						while (fgets(str[1], 10000, tape2) != NULL) {
							fputs(str[1], out);
						}
						break;
					}
				}

				else {
					fputs(str[1], out);
					if (fgets(str[1], 10000, tape2) == NULL) {
						fputs(str[0], out);
						while (fgets(str[0], 10000, tape1) != NULL) {
							fputs(str[0], out);
						}
						break;
					}
				}
			}
			break;
		}

		else {
			numcur = num;
			while (numcur) {
				if (fgets(str[1], 10000, tape2) == NULL) {
					while (fgets(str[0], 10000, tape1) != NULL) {
						fputs(str[0], tape);
					}
					break;
				}

				fgets(str[0], 10000, tape1);

				counter1 = 1;
				counter2 = 1;

				while (true) {
					cmp = strcmp(str[0], str[1]);

					if (cmp <= 0) {
						fputs(str[0], tape);
						if (counter1 >= max2 || (fgets(str[0], 10000, tape1) == NULL)) {
							fputs(str[1], tape);
							while (counter2 < max2 && fgets(str[1], 10000, tape2) != NULL) {
								counter2++;
								fputs(str[1], tape);
							}
							break;
						}
						counter1++;
					}

					else {
						fputs(str[1], tape);
						if (counter2 >= max2 || fgets(str[1], 10000, tape2) == NULL) {
							fputs(str[0], tape);
							while (counter1 < max2 && fgets(str[0], 10000, tape1) != NULL) {
								counter1++;
								fputs(str[0], tape);
							}
							break;
						}
						counter2++;
					}
				}
				if (numcur > max) {
					numcur -= max;
				}
				else {
					numcur = 0;
				}
			}
			fseek(tape, 0, SEEK_SET);
			fclose(tape1);
			tape1 = fopen("tape1.txt", "w+");
			fclose(tape2);
			tape2 = fopen("tape2.txt", "w+");

			for (size_t k = 0; k < num;) {
				for (size_t j = 0; j < max && k < num; j++, k++) {
					fgets(str[2], 10000, tape);
					fputs(str[2], tape1);
				}

				for (size_t j = 0; j < max && k < num; j++, k++) {
					fgets(str[2], 10000, tape);
					fputs(str[2], tape2);
				}
			}
			max2 = max;
			max *= 2;
		}
	}

	fclose(in);
	fclose(out);
	fclose(tape);
	fclose(tape1);
	fclose(tape2);
	for (size_t i = 0; i < 4; i++) {
		free(str[i]);
	}
	free(str);
	return 0;
}