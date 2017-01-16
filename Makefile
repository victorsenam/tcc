AUXFILES=main.aux main.toc main.loc

clear: 
	rm ${AUXFILES}

main.pdf: main.tex
	pdflatex main.tex
	bibtex main.tex
	pdflatex main.tex
	pdflatex main.tex
