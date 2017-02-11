AUXFILES=main.aux main.toc main.loc main.bbl main.blg main.lot main.log main.pdf main.out main-blx.bib main.lof main.dvi main.run.xml

clear: 
	rm ${AUXFILES}

main.pdf: main.tex Sections/KnuthYao.tex
	rm -f ${AUXFILES}
	pdflatex main.tex
	bibtex main.aux
	pdflatex main.tex
	pdflatex main.tex
