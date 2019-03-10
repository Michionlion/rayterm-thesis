#!/bin/bash

xelatex thesis.tex
bibtex thesis
xelatex thesis.tex
