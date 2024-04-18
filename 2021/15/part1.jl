using DataStructures
m = map(l -> split(l, ""), readlines("input"))
dx = [1, -1, 0, 0]; dy = [0, 0, 1, -1]; n = length(m)
q = BinaryMinHeap{Tuple{Int, Int, Int}}()
push!(q, (0, 0, 0))
while !isempty(q)
    (dist, x, y) = pop!(q)
    if x == n && y == m
        println(dist)
        exit(0)
    end
    
end