recur_counter = 0


def get_num_of_rec_calls(size):

    if size == 2 or size == 1:
        return 1
    elif size > 2:
        return get_num_of_rec_calls(size-1) * size + 1
    else:
        return 0


def determinant_recursive(A, num_of_calls, total=0, num_of_recs=0):
    # Section 1: store indices in list for row referencing
    indices = list(range(len(A)))

    global recur_counter
    # Section 2: when at 2x2 submatrices recursive calls end
    if len(A) == 1:
        val = A[0][0]
        recur_counter += 1
        print(recur_counter / num_of_calls * 100.0, " %")
        return val
    elif len(A) == 2 and len(A[0]) == 2:
        val = A[0][0] * A[1][1] - A[1][0] * A[0][1]
        recur_counter += 1
        print(recur_counter / num_of_calls * 100.0, " %")
        return val

    # Section 3: define submatrix for focus column and
    #      call this function
    for fc in indices:  # A) for each focus column, ...
        # find the submatrix ...
        As = A  # B) make a copy, and ...
        As = As[1:]  # ... C) remove the first row
        height = len(As)  # D)

        for i in range(height):
            # E) for each remaining row of submatrix ...
            #     remove the focus column elements
            As[i] = As[i][0:fc] + As[i][fc + 1:]

        sign = (-1) ** (fc % 2)  # F)
        # G) pass submatrix recursively
        sub_det = determinant_recursive(As, num_of_calls)
        # H) total all returns from recursion
        total += sign * A[0][fc] * sub_det
    recur_counter += 1
    print(recur_counter / num_of_calls * 100.0, " %")
    return total


def determinant_fast(A):
    # Section 1: Establish n parameter and copy A
    n = len(A)
    AM = A

    # Section 2: Row ops on A to get in upper triangle form
    for fd in range(n):  # A) fd stands for focus diagonal
        for i in range(fd + 1, n):  # B) only use rows below fd row
            if AM[fd][fd] == 0:  # C) if diagonal is zero ...
                AM[fd][fd] == 1.0e-18  # change to ~zero
            # D) cr stands for "current row"
            crScaler = AM[i][fd] / AM[fd][fd]
            # E) cr - crScaler * fdRow, one element at a time
            for j in range(n):
                AM[i][j] = AM[i][j] - crScaler * AM[fd][j]
        print(round(fd / n * 100.0, 2), "%")

    # Section 3: Once AM is in upper triangle form ...
    if n != 0:
        product = 1.0
    else:
        product = 0.0
    for i in range(n):
        # ... product of diagonals is determinant
        product *= AM[i][i]
    print("100.0 %")
    return product
