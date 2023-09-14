#include <stdio.h>
#include <stdlib.h>

#define NMIN 2
#define NMAX 10000
#define CMIN 1
#define CMAX 200

int main()
{
	FILE *fin = fopen("panglica.in", "r");

	if (!fin) { printf("Eroare panglica.in\n"); return 1; }

	unsigned short N, C, *ultpoz, *lg, i, c, lgmax, cmax, primpozmax, ultpozmax;
	short *primpoz;

	fscanf(fin, "%hu %hu", &N, &C);

	if (N < NMIN || N > NMAX) { printf("Eroare valoare N\n"); return 2; }

	if (C < CMIN || C > CMAX) { printf("Eroare valoare C\n"); return 3; }	

	primpoz = (short*)calloc(C+1, sizeof(short));
	ultpoz = (unsigned short*)calloc(C+1, sizeof(unsigned short));
	lg = (unsigned short*)calloc(C+1, sizeof(unsigned short));

	for (i = 1; i <= C; i++) primpoz[i] = -1;

	for (cmax = 1, lgmax = primpozmax = ultpozmax = i = 0; i < N; i++) {
		fscanf(fin, "%hu", &c);

		if (primpoz[c] < 0) primpoz[c] = i;

		ultpoz[c] = i;

		lg[c] = ultpoz[c]-primpoz[c]+1;

		if (lg[c] > lgmax) {
			lgmax = lg[c];
			cmax = c;
			primpozmax = primpoz[c];
			ultpozmax = ultpoz[c];
		}
	}

	fclose(fin);

	free(primpoz);
	free(ultpoz);
	free(lg);

	FILE *fout = fopen("panglica.out", "w");

	fprintf(fout, "%hu\n%hu\n%hu\n%hu", lgmax, cmax, primpozmax, N-ultpozmax-1);
	
	fclose(fout);

	return 0;
}

// scor 100
