using DataStructures
m = map(l -> split(l, ""), readlines("input"))
for i in 1:10
    push!(q, i)
end
while length(q) > 0
    println(peek(q))
    dequeue!(q)
end