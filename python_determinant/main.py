import sys
import det_functions as df
import numpy as np


def print_main_menu():
    print("----------------------------")
    print("---Determinant Calculator---")
    print("----------------------------\n")
    print("1. Read matrix from file")
    print("2. Generate matrix")
    print("3. Calculate determinant")
    print("4. Display matrix")
    print("5. Exit\n")


def print_det_calc_menu():
    print("----------------------------")
    print("-----Calculation Method-----")
    print("----------------------------\n")
    print("1. Recursive")
    print("2. Fast(Conversion to Triangle Matrix)")
    print("3. Using numpy library")
    print("4. Return\n")


def main():
    a = []
    while True:
        print_main_menu()
        try:
            selection = int(input("Enter choice: "))
            if selection == 1:
                a = read_file()
            elif selection == 2:
                a = gen_rand_mat()
            elif selection == 3:
                det_calc_options(a)
            elif selection == 4:
                display_matrix(a)
            elif selection == 5:
                sys.exit()
            else:
                print("Invalid choice. Enter 1-5")
        except ValueError:
            print("Invalid choice. Enter 1-5")


def read_file():
    with open('sample_matrix.txt', 'r') as f:
        temp = [[float(num) for num in line.split(';')] for line in f]
    return temp


def gen_rand_mat():
    while True:
        try:
            selection = int(input("Enter size of the randomly generated array: "))
            temp = [[np.random.uniform(0.1, 5.0) for _ in range(selection)] for _ in range(selection)]
        except ValueError:
            print("Invalid size choice, please try again!")
        return temp


def det_calc_options(a):
    while True:
        print_det_calc_menu()
        try:
            calc_selection = int(input("Enter choice: "))
            if calc_selection == 1:
                try:
                    num_of_calls = df.get_num_of_rec_calls(a.__len__())
                    det = df.determinant_recursive(a, num_of_calls)
                    print("Determinant calculated using recursion equals", det)
                    print("Number of recursive calls: ", df.get_num_of_rec_calls(a.__len__()))
                except AttributeError:
                    pass
                except ZeroDivisionError:
                    print("The matrix doesn't exist!")

                df.recur_counter = 0
            elif calc_selection == 2:
                try:
                    det = df.determinant_fast(a)
                    print("Determinant calculated using triangle matrix equals", det)
                except TypeError:
                    print("The matrix needs to be generated or uploaded beforehand!")
            elif calc_selection == 3:
                try:
                    det = np.linalg.det(a)
                    print("Determinant calculated using numpy library equals", det)
                except np.linalg.LinAlgError:
                    print("The matrix doesn't exist")
            elif calc_selection == 4:
                break
            else:
                print("Invalid choice. Enter 1-4")
        except ValueError:
            print("Invalid choice. Enter 1-4")


def display_matrix(a):
    print(a)


main()
