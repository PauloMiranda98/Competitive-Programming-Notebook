# GEMP - UFC Quixadá - ICPC Library
========================

Biblioteca de algoritmos para maratona de programação.
Script para gerar o pdf adaptado por @paulomiranda98 baseado no script feito pelo [time ACM de Stanford University](https://github.com/jaehyunp/stanfordacm).

========================

Ferramentas necessárias: [Python 2/3](https://www.python.org/) e [latexmk](https://www.ctan.org/pkg/latexmk/)

## Instalação
```script
sudo apt-get install python
sudo apt-get install latexmk
```

## Execução
```script
python generate_pdf.py
```

## Adicionar Novos Códigos
- Crie o arquivo do código na pasta `code/$categoria/` com o nome `nome_do_algoritmo.h`
- Crie o teste referente ao código na pasta `test/$categoria/` com o nome `nome_do_algoritmo_test.cpp`
- Adicione uma nova linha no arquivo `contests.md` em baixo de `**categoria**` com o seguinte formato: `- [x] [nome_no_pdf](code/$categoria/nome_do_algoritmo.h)`
- Por fim, é só rodar o gerador :)

## Adicionar Novos Teoremas e Fórmulas
- Primeiro teste se o LaTeX está formatado da maneira correta. Para isso, coloque o conteúdo no arquivo `test_latex/test_content.tex` e tente gerar o PDF com o seguinte comando : `python generate_test_pdf.py`
- Após isso, crie o arquivo na pasta `code/theorems_and_formulas/` com o nome `nome_do_assunto.tex`
- Por fim, adicione uma nova linha no arquivo `contests.md` em baixo de `**Theorems and Formulas**` com o seguinte formato: `- [x] [nome_no_pdf](code/theorems_and_formulas/nome_do_assunto.tex)`

## Remover Código do PDF
- Para remover do PDF basta remover o x: `- [ ] [nome_no_pdf](code/$categoria/nome_do_algoritmo.h)`