from cs50 import get_string

text = get_string("Text: ")

s = 0.0 # sentences
w = 1.0 # words
l = 0.0 # letters
c = ''

for i in range(len(text)):
    c = text[i]
    