#!/usr/bin/python3
# Used for the Space Engineers game.
import math
def main():
	P0raw = input("Initial Point: ").split(":")
	P1raw = input("Second  Point: ").split(":")
	P0 = Vector3(str(P0raw[2])+","+P0raw[3]+","+P0raw[4])
	P1 = Vector3(str(P1raw[2])+","+P1raw[3]+","+P1raw[4])
	desired_distance = input ("Desired Point Distance? ")

	Pdesired = Get_Desired_Position(P0, P1, desired_distance)
#	print (
#		"X: "+str(Pdesired.x) + "\n"
#		"Y: "+str(Pdesired.y) + "\n"
#		"Z: "+str(Pdesired.z)
#		)
	print (P0raw[0]+":"+P0raw[1]+":"+str(Pdesired.x)+":"+str(Pdesired.y)+":"+str(Pdesired.z)+":"+P0raw[5]+":")
	return

class Vector3:
	x = 0
	y = 0
	z = 0
	def __init__(self, parse_string):
		# Explode by [,] and / or [ ], get the 3 numbers. Assign x y and z
		list_of_chars = [' ','<','>','!','?','[',']','{','}','(',')','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
		translation_table = str.maketrans('', '', ''.join(list_of_chars))
		parse_string = parse_string.translate(translation_table)
		coords = parse_string.split(",")

		self.x = float(coords[0])
		self.y = float(coords[1])
		self.z = float(coords[2])
		return

def Get_Desired_Position(Pinitial, Pfinal, desired_distance):
	# Direction Vector = P1 - P0 = Pd
	Pdelta = Vector3(str(Pfinal.x-Pinitial.x) + "," + str(Pfinal.y-Pinitial.y) + "," + str(Pfinal.z-Pinitial.z))
	# distance = sqrt(Pdx^2+Pdy^2+Pdz^2)
	hypotenuse_length = math.sqrt(Pdelta.x*Pdelta.x+Pdelta.y*Pdelta.y+Pdelta.z*Pdelta.z)
	if hypotenuse_length == 0:
		return Pinitial
	# Normal of Pd (magnitude of 1) = Pd / distance = Pn
	Pnormal = Vector3(str(Pdelta.x / hypotenuse_length) + "," + str(Pdelta.y / hypotenuse_length) + "," + str(Pdelta.z / hypotenuse_length))
	# Desired Position = Pn * multiplier + P0
	Pdesired = Vector3(str(Pnormal.x * float(desired_distance) + Pinitial.x) + "," + str(Pnormal.y * float(desired_distance) + Pinitial.y) + "," + str(Pnormal.z * float(desired_distance) + Pinitial.z))
	return Pdesired # Vector3 the desired point n units away from P0 in the direction of Pd

while True:
	main()
	input("Press [ENTER] to continue")
