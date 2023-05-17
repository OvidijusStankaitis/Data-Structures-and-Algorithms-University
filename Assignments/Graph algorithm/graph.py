import sys
import os

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []

    def add_edge(self, u, v, weight):
        self.graph.append((u, v, weight))

    def find(self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])

    def union(self, parent, rank, x, y):
        xroot = self.find(parent, x)
        yroot = self.find(parent, y)

        if rank[xroot] < rank[yroot]:
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot]:
            parent[yroot] = xroot
        else:
            parent[yroot] = xroot
            rank[xroot] += 1

    def kruskal_mst(self):
        result = []
        self.graph = sorted(self.graph, key=lambda x: x[2])
        parent = []
        rank = []

        for node in range(self.V):
            parent.append(node)
            rank.append(0)

        for u, v, weight in self.graph:
            x = self.find(parent, u)
            y = self.find(parent, v)

            if x != y:
                result.append((u, v, weight))
                self.union(parent, rank, x, y)

        return result

def read_graph_data(filename):
    with open(filename, 'r') as file:
        lines = file.readlines()
        try:
            vertices = int(lines[0].strip())
            graph = Graph(vertices)
            for line in lines[1:]:
                u, v, weight = map(int, line.strip().split())
                graph.add_edge(u, v, weight)
            return graph
        except (ValueError, IndexError):
            clear_terminal()
            error_message = "\n\nInvalid input data. Please check the format of the input file!!!\n\n"
            print(error_message)
            return None

def write_output(filename, original_edges, mst_edges, error_message):
    with open(filename, 'w') as file:
        if error_message:
            file.write(error_message)
        else:
            file.write("Original Graph:\n")
            for u, v, weight in original_edges:
                file.write(f'{u} --{weight}-- {v}\n')

            file.write("\nMinimum Spanning Tree:\n")
            for u, v, weight in mst_edges:
                file.write(f'{u} --{weight}-- {v}\n')

def visualize_graph(edges):
    for u, v, weight in edges:
        print(f'{u} --{weight}-- {v}')

def clear_terminal():
    command = "cls" if os.name == "nt" else "clear"
    os.system(command)

def main():
    if len(sys.argv) != 3:
        print("Usage: python minimum_spanning_tree.py <input_file> <output_file>")
        return

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    graph = read_graph_data(input_file)
    if graph is None:
        write_output(output_file, [], [], "Invalid input data. Please check the format of the input file!!!")
        return

    original_edges = graph.graph.copy()

    mst_edges = graph.kruskal_mst()

    write_output(output_file, original_edges, mst_edges, "")

    clear_terminal()
    print("\n\nGraphs generated successfully.\n\n")

if __name__ == "__main__":
    main()
