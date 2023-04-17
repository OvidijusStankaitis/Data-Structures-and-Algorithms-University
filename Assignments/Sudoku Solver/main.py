import sys

def solve_sudoku(board):

    row, col = find_empty_cell(board)

    if row is None:
        return True

    for num in range(1, 10):
        if is_valid_move(board, row, col, num):
            board[row][col] = num

            if solve_sudoku(board):
                return True

            board[row][col] = 0

    return False


def find_empty_cell(board):

    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:
                return row, col
    return None, None


def is_valid_move(board, row, col, num):

    for i in range(9):
        if board[row][i] == num:
            return False

    for i in range(9):
        if board[i][col] == num:
            return False

    box_row = row // 3 * 3
    box_col = col // 3 * 3
    for i in range(box_row, box_row + 3):
        for j in range(box_col, box_col + 3):
            if board[i][j] == num:
                return False

    return True

input_file = sys.argv[1]
with open(input_file) as f:
    lines = f.readlines()

board = []
for line in lines:
    row = [int(num) for num in line.strip()]
    board.append(row)

solve_sudoku(board)

output_file = sys.argv[2]
with open(output_file, 'w') as f:
    for i in range(9):
        if i % 3 == 0 and i != 0:
            f.write("- - - - - - - - - - -  \n")
        for j in range(9):
            if j % 3 == 0 and j != 0:
                f.write("| ")
            if j == 8:
                f.write(str(board[i][j]) + "\n")
            else:
                f.write(str(board[i][j]) + " ")
