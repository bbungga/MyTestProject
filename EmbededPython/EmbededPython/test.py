import sys

def test_print(a, b):
	f = open('tt.txt', 'a')
	out = "C Var: 1st %s 2nd %d" % (a, b)
	f.write(out) 
	f.close();
