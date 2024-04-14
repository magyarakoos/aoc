a = map(x -> parse(Int, x), split(readline("input"))); p1 = typemax(Int)
for d in minimum(a):maximum(a)
    p1 = min(p1, sum(x -> abs(x - )))
end