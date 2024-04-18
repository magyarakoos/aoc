using DataStructures
m = map(l -> split(l, ""), readlines("input"))
q = PriorityQueue{Tuple{Int, Int}}()
for i in 1:10
    