#!/usr/bin/python

import sys

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
	def printxy(self):
		buf = "(%d,%d)" % (self.getx(), self.gety())

class Robot:
	def __init__(self, xpos, ypos):
		self.__x = xpos
		self.__y = ypos
		self.destNode = None

	def getx(self):
		"""Accessor method for private attr x"""
		return self.__x
	def gety(self):
		"""Accessor method for private attr y"""
		return self.__y
	def getxy(self):
		"""Return the (x,y) position of the Robot as a tuple"""
		return (self.getx, self.gety)
	def printxy(self):
		buf = "(%d,%d)" % (self.getx(), self.gety())
		return buf 
	def setx(self, xpos):
		self.__x = xpos
	def sety(self, ypos):
		self.__y = ypos
	def setxy(self, (xpos, ypos)):
		self.setx(xpos)
		self.sety(ypos)
	
	def setDest(self, Node):
		self.destNode = Node
	def getDest(self):
		return self.destNode
		
	
	# Temporary implementation
	def visit(self, node):
		if node.accessible == 1:
			self.setxy(node.getxy())
			return 0
		else:
			return 1
		


# Input args are map file, interference (R)
if len(sys.argv) != 3:
	print "Usage is %s <input file> <interference value>" % ( sys.argv[0] )
	sys.exit(1)

inFile = sys.argv[1]
interference = sys.argv[2]

# Vars to hold destination Nodes for robots 
with open(inFile) as f:
	nodeArr = []
	lines = f.readlines()
	y = len(lines)
	for l in lines:
		x = 0
		y -= 1
		for word in l:
			for ch in word:
				x += 1
				if ch == 'F':
					# Robot F found (F -> L)
					RobF = Robot(x,y)
				elif ch == 'L':
					# Destination found
					RFDest = Node(x,y)
					nodeArr.append(RFDest)
				elif ch == 'S':
					# Robot S Found (S -> E)
					RobS = Robot(x,y)
				elif ch == 'E':
					# Destination found
					RSDest = Node(x,y)
					nodeArr.append(RSDest)
				else:
					# Not a Robot, or a robot destination 
					nodeArr.append(Node(x, y))

# Attempt to visit a Node
print "Robot F found at %s" % RobF.printxy()
print "Robot S found at %s" % RobS.printxy()


			

