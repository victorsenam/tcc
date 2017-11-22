AUXFILES=main.aux main.toc main.loc main.bbl main.blg main.lot main.log main.pdf main.out main-blx.bib main.lof main.dvi main.run.xml

TIKZ=MatrizMonotona Holder
TIKZ_FILES=$(addsuffix .tikz,$(addprefix Figures/,${TIKZ}))

.PHONY: clear tex

all: main.pdf

tex: main.pdf

clear: 
	rm ${AUXFILES}

main.pdf: main.tex 
	pdflatex main.tex
