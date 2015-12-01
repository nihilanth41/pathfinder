#!/usr/bin/python

import sys

# Input arg is map file
if len(sys.argv) != 2:
	print "Usage is %s <input file>\n" % ( argv[0] )

class Node:
	def __init__(self, xpos, ypos):
		self.__x = xpos
		self.__y = ypos
		self.wall_type = -1
		self.accessability = -1 
		#accessability would be 1 for accessable and 0 for not 

# Robot 1: S -> E
# Robot 2: F -> L

# Print room.txt to stdout line by line
nodeArr = []
with open(sys.argv[1]) as f:
	lines = f.readlines()
	y = len(lines)
	for l in lines:
		x = 0
		y -= 1
		if y != 0:
			print y,
		
		for word in l:
			for ch in word:
				x += 1
				nodeArr.append(Node(x, y))
				i = len(nodeArr)-1
				print ch,
				#print "[%d,%d]" % (nodeArr[i].x, nodeArr[i].y),
		#print ""
				


			

