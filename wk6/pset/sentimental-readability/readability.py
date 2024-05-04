from cs50 import get_string

text = get_string("Text: ")

s = 0.0 # track how many sentences there are
w = 1.0 # track how many words there are
l = 0.0 # letters
c = ''

for i in range(len(text)):
    c = text[i]
