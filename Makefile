AUXFILES=main.aux main.toc main.loc main.bbl main.blg main.lot main.log main.pdf main.out main-blx.bib

clear: 
	rm ${AUXFILES}

main.pdf: main.tex Chapters/Chapter1.tex
	pdflatex main.tex
	bibtex main.aux
	pdflatex main.tex
