from cs50 import get_string

text = get_string("Text: ")

s = 0.0 # sentences
w = 1.0 # words
l = 0.0 # letters
c = ''

for i in range(len(text)):
    # get the current letter
    c = text[i]
    # save the ascii value for later
    j = ord(c.lower())
    # if this is the end of a sentence add one to sentences
    if c == '.' or c == '!' or c == '?':
        s += 1
    # if this is the end of a word add one to words
    elif c == ' ':
        w += 1
    # if this is a letter add one to letters
    elif 96 < j and j < 123:
        l += 1

print(s, w, l, c)
