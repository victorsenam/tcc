SECTION_NAMES=Introducao MatrizMonge DivisaoEConquista SMAWK KnuthYao EDPD Online
SECTION_PATHS=$(addprefix Sections/,${SECTION_NAMES})
SECTION_TEX=$(addsuffix .tex,${SECTION_PATHS})
SECTION_AUX=$(addsuffix .aux,${SECTION_PATHS})

DEPENDENCIES=Figures/MatrizMonge_Classificacao.tikz Figures/SMAWK_Reduce1.tikz Figures/SMAWK_Reduce2.tikz


AUXFILES=main.aux main.toc main.loc main.bbl main.blg main.lot main.log main.pdf main.out main-blx.bib main.lof main.dvi main.run.xml ${SECTION_AUX} 

.PHONY: clear tex

all: main.pdf

tex: main.pdf

clear: 
	rm ${AUXFILES}

main.pdf: main.tex ${SECTION_TEX} ${DEPENDENCIES} definitions.tex main.bib
	pdflatex main.tex
	bibtex main.aux
	pdflatex main.tex
	pdflatex main.tex
