# **Minimum Spanning Tree Algorithm**

This program implements the Minimum Spanning Tree (MST) algorithm using Kruskal's algorithm. Given a weighted graph, the program finds the MST by connecting all the vertices with the minimum total weight.

## **Description**

The program reads an input file containing the graph data and outputs the original graph and the corresponding MST. It uses the Kruskal's algorithm to find the MST efficiently.

The program performs the following steps:

Reads the input file and constructs the graph based on the provided data.
Applies the Kruskal's algorithm to find the MST of the graph.
Writes the original graph and the MST to an output file.
Clears the terminal/console.
Prints a success message indicating that the graphs were generated successfully.

## **Prerequisites**

- ### Python 3.x
- ### input.txt
- ### output.txt

## **Usage**

### **To run the program, follow these steps:**

- ### Ensure that you have Python 3.x installed on your system.

- ### Prepare an input file.

- ### Open a terminal or command prompt and navigate to the directory containing the program file.

- ### Run the program with the following command:

```shell
make
make run
```

- ### Or run the program (ONLY WORKS ON WINDOWS) by executing GO.cmd file.

- ### Check the output file to view the original graph and the generated MST.

# **File Descriptions**
- ### graph.py: The main program file containing the implementation of the MST algorithm.
- ### ReadMe.md: This file, providing information about the program and usage instructions.
- ### input.txt: An example input file with the graph data.

## **Format:**

```txt
<Number of Vertices>
<Edge 1 Start> <Edge 1 End> <Edge 1 Weight>
<Edge 2 Start> <Edge 2 End> <Edge 2 Weight>
...
```

## **Example:**

```txt
6
0 1 5
0 2 3
1 2 2
1 3 4
1 4 2
2 3 3
3 4 1
3 5 6
4 5 4
```

- ### output.txt: The output file where the original graph and MST will be written.

## **Format:**

```txt
Original Graph:
<Edge 1 Start> <Edge 1 Weight> <Edge 1 End> 
<Edge 2 Start> <Edge 2 Weight> <Edge 2 End> 
...

Minimum Spanning Tree:
<Edge x Start> <Edge x Weight> <Edge x End> 
<Edge y Start> <Edge y Weight> <Edge y End> 
...
```

## **Example:**

```txt
Original Graph:
0 --5-- 1
0 --3-- 2
1 --2-- 2
1 --4-- 3
1 --2-- 4
2 --3-- 3
3 --1-- 4
3 --6-- 5
4 --4-- 5

Minimum Spanning Tree:
3 --1-- 4
1 --2-- 2
1 --2-- 4
0 --3-- 2
4 --4-- 5
```

- ### makefile: Builds and executes the program.

```makefile
PYTHON = python3
PYC = __pycache__/graph.cpython-310.pyc
INPUT = input.txt
OUTPUT = output.txt
all: $(PYC)
$(PYC): graph.py
	$(PYTHON) -m py_compile $<
run:
	$(PYTHON) $(PYC) $(INPUT) $(OUTPUT)
```

- ### GO.cmd: executes makefile (ONLY WORKS ON WINDOWS).

```cmd
@echo off
if "%USERDOMAIN%" == "DESKTOP-RKG7LUC" goto savasPC
REM MIF kompiuteris
set PATH=C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%PATH%
make run
goto :eof

:savasPC
make run
goto :eof
```