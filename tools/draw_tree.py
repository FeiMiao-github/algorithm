import graphviz

edges = [[6,0],[1,0],[5,1],[2,5],[3,1],[4,3]]
node_num = len(edges) + 1

graph = graphviz.Digraph()

for i in range(node_num):
    graph.node(str(i), str(i))

for edge in edges:
    graph.edge(str(edge[0]), str(edge[1]))

try:
    graph.render("tree.md")
except Exception as e:
    print(e)