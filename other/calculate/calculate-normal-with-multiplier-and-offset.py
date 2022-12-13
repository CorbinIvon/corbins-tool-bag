import math
def main():
	P0 = Vector3(input("Initial Point: "))
	P1 = Vector3(input("Second  Point: "))
	desired_distance = input ("Desired Point Distance? ")

	Pdesired = Get_Desired_Position(P0, P1, desired_distance)
	print (
		"X: "+str(Pdesired.x) + "\n"
		"Y: "+str(Pdesired.y) + "\n"
		"Z: "+str(Pdesired.z)
		)
	return

class Vector3:
	x = 2
	y = 2
	z = 2
	def __init__(self, parse_string):
		# Explode by [,] and / or [ ], get the 3 numbers. Assign x y and z
		coords = parse_string.split(",")
		if len(coords) != 3:
			print ("Coordinate not 3 points. Exiting...")
			exit(1)
		self.x = float(coords[0])
		self.y = float(coords[1])
		self.z = float(coords[2])
		return

def Get_Normal_1_Magnitude(Pd):
	return # Vector3 the point 1 unit away from P0
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

main()
input("Press [ENTER] to continue")