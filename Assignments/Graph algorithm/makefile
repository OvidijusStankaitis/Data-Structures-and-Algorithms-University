PYTHON = python3
PYC = __pycache__/graph.cpython-310.pyc
INPUT = input.txt
OUTPUT = output.txt
all: $(PYC)
$(PYC): graph.py
	$(PYTHON) -m py_compile $<
run:
	$(PYTHON) $(PYC) $(INPUT) $(OUTPUT)
