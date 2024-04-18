using DataStructures
m = map(l -> split(l, ""), readlines("input"))
q = PriorityQueue{Tuple{Int, Int}}()
for i in 1:10
    enqueue!(q, i)
end
while length(q) > 0
    println(peek(q))
    dequeue!(q)
end