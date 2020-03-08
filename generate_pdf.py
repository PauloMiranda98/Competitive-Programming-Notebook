#!/usr/bin/python
# This script was based in the file of the Stanford University ACM team

import os
title = "GEMP - UFC Quixadá - ICPC Library"

def get_sections():
  sections = []
  section_name = None
  with open("contents.md", 'r') as f:
    for line in f:
      line = line.strip()
      if len(line) < 2: 
        continue
      if line[:2] == "**":
        section_name = line[2:-2]
        subsections = []
        if section_name is not None:
          sections.append((section_name, subsections))
      elif line[: 6] == "- [x] ":
        line = line[6: ]
        subsection_name = line[line.find('[') + 1 : line.find(']')]
        filename = line[line.find('(') + 1 : line.find(')')]

        if len(subsection_name) == 0:
          raise ValueError("Subsection parse error: %" % line)
        if section_name is None:
          raise ValueError("Subsection given without section")

        run_test(filename)
        subsections.append((filename, subsection_name))
  return sections

def run_test(filename):
  if(get_style(filename) == "cpp"):
    testFileName = filename.replace("code/", "test/")
    testFileName = testFileName.replace(".h", "_test.cpp")

    print("------------------------------------------")
    print("Runnig the %s test: " % testFileName)
    print("Compiling...")
    retCompile = os.system("g++ -std='c++14' %s -o testApp" % testFileName)
    if(retCompile != 0):
      raise ValueError("Error compiling test %s!" % testFileName)
    print("Runnig the test...")
    retRun = os.system("./testApp")   
    if(retRun == 0):
      print("Passed the test!")
    else:
      raise ValueError("The %s test failed!" % testFileName)

def get_style(filename):
  ext = filename.lower().split('.')[-1]
  if ext in ['c', 'cc', 'cpp', 'h']:
    return 'cpp'
  elif ext in ['java']:
    return 'java'
  elif ext in ['py']:
    return 'py'
  elif ext in ['tex']:
    return 'tex'
  else:
    return 'txt'

def get_tex(sections):
  tex = ''
  for (section_name, subsections) in sections:
    tex += '\\section{%s}\n' % section_name
    for (filename, subsection_name) in subsections:
      tex += '\\subsection{%s}\n' % subsection_name
      if(get_style(filename) == 'tex'):
        tex += '\\raggedbottom{\\input{%s}}\n' % filename
      else:
        tex += '\\raggedbottom\\lstinputlisting[style=%s]{%s}\n' % (get_style(filename), filename)
      tex += '\\hrulefill\n'
    tex += '\n'
  return tex

if __name__ == "__main__":
  sections = get_sections()
  tex = get_tex(sections)
  with open('contents.tex', 'w') as f:
    f.write(tex)
  os.system("latexmk -pdf model/notebook.tex > generate_pdf.log")
  os.system("mv notebook.pdf GEMP-Notebook.pdf")
  os.system("rm contents.tex")
  os.system("rm notebook.*")
  os.system("rm testApp")   
  os.system("rm generate_pdf.log")