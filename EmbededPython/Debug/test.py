import sys

def test_print(a, b):
	f = open('tt.txt', 'w')
	f.write("C Var: 1st %d, 2nd %d\n") % a, b
