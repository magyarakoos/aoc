using DataStructures
m = map(l -> split(l, ""), readlines("input"))
q = BinaryMinHeap(Int)
for i in 1:10
    push!(q, i)
end
while !isempty(q)
    println(pop!(q))
end