a = map(x -> parse(Int, x), split(readline("input"), ","))
p1 = typemax(Int); p2 = typemax(Int)
for d in minimum(a):maximum(a)
    global p1 = min(p1, sum(x -> abs(x - d), a))
    global p2 = min(p2, sum(x -> sum(collect(1:abs(x - d))), a))
end
println("$p1\n$p2")