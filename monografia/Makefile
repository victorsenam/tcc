SECTION_NAMES=Introducao MatrizMonge DivisaoEConquista
SECTION_PATHS=$(addprefix Sections/,${SECTION_NAMES})
SECTION_TEX=$(addsuffix .tex,${SECTION_PATHS})
SECTION_AUX=$(addsuffix .aux,${SECTION_PATHS})

AUXFILES=main.aux main.toc main.loc main.bbl main.blg main.lot main.log main.pdf main.out main-blx.bib main.lof main.dvi main.run.xml ${SECTION_AUX}

.PHONY: clear tex

all: main.pdf

tex: main.pdf

clear: 
	rm ${AUXFILES}

main.pdf: main.tex ${SECTION_TEX} definitions.tex
	rm -f ${AUXFILES}
	pdflatex main.tex
	bibtex main.aux
	pdflatex main.tex
	pdflatex main.tex
