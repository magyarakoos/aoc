using DataStructures
m = map(l -> split(l, ""), readlines("input"))
dx = [1, -1, 0, 0]; dy = [0, 0, 1, -1]
q = BinaryMinHeap{Vector{Int}}()
push!(q, (0, 0, 0))
while !isempty(q)
    (dist, u) = pop!(q)

end