#!/usr/bin/python
import os

if __name__ == "__main__":
  os.system("latexmk -pdf test_latex.tex")
  os.system("mv test_latex.pdf test_pdf.pdf")
  os.system("mv test_latex.tex copy_test_latex.tex")
  os.system("rm test_latex.*")
  os.system("mv copy_test_latex.tex test_latex.tex")
