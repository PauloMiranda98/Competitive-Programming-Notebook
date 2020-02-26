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

## Adicionar novos códigos
- crie o arquivo do código na pasta `code/$categoria/` com o nome `nome_do_algoritmo.h`
- crie o teste referente ao código na pasta `test/$categoria/` com o nome `nome_do_algoritmo_test.cpp`
- Adiciona uma nova linha no arquivo `contests.md` em baixo de `**categoria**` com o seguinte formato: `- [x] [nome_no_pdf](code/$categoria/nome_do_algoritmo.h)`
- Por fim, é só rodar o gerador :)

## Remover código do PDF
- Para remover do PDF basta remover o x: `- [ ] [nome_no_pdf](code/$categoria/nome_do_algoritmo.h)`