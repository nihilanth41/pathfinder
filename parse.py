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
		self.accessible = -1 
		# accessible would be 1 for accessible and 0 for not 
	
	# Is this what you meant as far as accessor methods? 
	def getx(self):
		return self.__x
	def gety(self):
		return self.__y
	def getxy(self):
		return (self.getx, self.gety)


#
class Robot(Node):
	def __init__(self, xpos, ypos):
		self.__x = xpos
		self.__y = ypos

	def setx(self, xpos):
		self.__x = xpos
	def sety(self, ypos):
		self.__y = ypos
	def setxy(self, (xpos, ypos)):
		self.setx(xpos)
		self.sety(ypos)
	
	# Temporary implementation
	def visit(self, node):
		if node.accessible == 1:
			self.setxy(node.getxy())
			return 0
		else:
			return 1
		


# Robot 1: S -> E
# Robot 2: F -> L

# Print room.txt to stdout line by line
nodeArr = []
robArr = []
with open(sys.argv[1]) as f:
	lines = f.readlines()
	y = len(lines)
	for l in lines:
		x = 0
		y -= 1
		#if y != 0:
			#print y,
		
		for word in l:
			for ch in word:
				x += 1
				nodeArr.append(Node(x, y))
				i = len(nodeArr)-1
				if (ch == 'S') or (ch == 'F'):
					print "Robot %s found at position (%d,%d)" % (ch, nodeArr[len(nodeArr)-1].getx(), nodeArr[len(nodeArr)-1].gety())
					robArr.append(Robot(nodeArr[len(nodeArr)-1].getx(), nodeArr[len(nodeArr)-1].gety()))
				#print ch,
				#print "[%d,%d]" % (nodeArr[i].x, nodeArr[i].y),
		#print ""

# Attempt to visit a Node
rob1 = robArr[0]
rob2 = robArr[1] 

def test(rob):
	if(rob.visit(nodeArr[0])):
		print "Node not accessible"
	else:
		print "Robot visited Node: (%d,%d)" % (nodeArr[0].getx(), nodeArr[0].gety())

test(rob1)
test(rob2)
nodeArr[0].accessible = 1
test(rob1)
test(rob2)
				


			

