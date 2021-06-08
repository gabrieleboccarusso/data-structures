# TO DO: add comments

string = input('enter the string to reverse: ')

# finding the length of the string
s_lenght = len(string)

# reversing the string
rev_str = [None] * s_lenght
j:int = 0
i: int = 0
for i in range(s_lenght - 1, -1, -1):
  rev_str[j] = string[i]
  j += 1

rev_str = "".join(rev_str)
print(rev_str)

