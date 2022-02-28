FILE := "angles.txt"
NUM := 10
all: gen calc

run: all
	./gen_angles $(NUM) $(FILE)
	./calc_angle $(FILE)

gen:
	g++ gen_angles.cpp -o gen_angles
calc:
	g++ calc_angle.cpp -o calc_angle
