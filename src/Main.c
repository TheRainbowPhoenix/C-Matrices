#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/MatIO.h"
#include "../include/MatArith.h"
#include "../include/LibFt.h"

typedef struct Matrix Matrix;

void help(void) {
	ft_putstr("Usage: MultMat [options] file\n");
	ft_putstr("\nOptions:\n");
	ft_putstr("  -h\t\tPrint this message\n");
	ft_putstr("  -i\t\tInput two Matrix\n");
	ft_putstr("  -m\t\tMultiply two Matrix\n");
	ft_putstr("  -a\t\tAdd two Matrix\n");
	ft_putstr("  -s\t\tSubstract two Matrix\n");
	ft_putstr("  -e FILENAME\tExport input\n");
}

void Operator(int iflag, int ope, int eflag, char * fname) {
	int a[] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	int b[] = {
		1, 3, 2,
		4, 6, 5,
		12,11,14
	};
	Matrix* m1;
	Matrix* m2;
	Matrix* m3;

	if(eflag) {
		if(fname == NULL) {
			fname = "missingno.txt";
		}
	}
	if(iflag==1) {
		m1 = m_read();
		m_print(m1);
		ft_putstr("\n");
		m2 = m_read();
		m_print(m2);
		ft_putstr("\n");
		if(eflag==1) {
			m_export(fname, m1);
			m_export(fname, m2);
		}
	} else {
		ft_putstr("No input, using demo matrix :\n");
		m1 = m_populate(a, 3, 3);
		m_print(m1);
		ft_putstr("\n");
		m2 = m_populate(b, 3, 3);
		m_print(m2);
		ft_putstr("\n");
		if(eflag==1) {
			m_export(fname, m1);
			m_export(fname, m2);
		}
	}
	switch (ope) {
		case 1:
			m3 = m_multiply(m1,m2);
			break;
		case 2:
			m3 = m_add(m1,m2);
			break;
		case 3:
			m3 = m_sub(m1,m2);
			break;
		case 0:
			m3 = m_init(1,1);
			break;
		default:
			m3 = m_init(1,1);
			break;
	}
	m_print(m3);
	ft_putstr("\n");
}

int	main(int argc, char *argv[])
{
	int iflag;
	int eflag;
	int ope;
	char *fname = NULL;
	int c;
	iflag = 0;
	eflag = 0;
	ope = 0;
	opterr = 0;
	while ((c = getopt (argc, argv, "himase:")) != -1) {
		switch (c)
		{
			case 0:
				/* If this option set a flag, do nothing else now. */
				printf ("option %d", optopt);
				if (optarg)
					printf (" with arg %s", optarg);
				printf ("\n");
				break;
			case 'i':
				iflag = 1;
				break;
			case 'm':
				ope = 1;
				break;
			case 'a':
				ope = 2;
				break;
			case 's':
				ope = 3;
				break;
			case 'e':
				fname = (optarg == 0)?("TheNothing"):(optarg);
				eflag = 1;
				break;
			case '?':
				if (optopt == 'e') {
					ft_puterrstr("The option ");
					ft_puterrchar(optopt);
					ft_puterrstr(" requires an argument.\n");
				} else {
					ft_puterrstr("Error : option character ");
					ft_puterrchar(optopt);
					ft_puterrstr(" is unknown\n");
				}
				return 1;
			case 'h':
			default:
				help();
				break;
		}
	}
	if (argc == 1) {
		help();
	} else if(argc <= 5) {
		ft_putnbr(argc);
		Operator(iflag, ope, eflag, fname);
	} else {
		ft_puterrstr("Error : Too many arguments !\n");
	}
	return (0);
}
