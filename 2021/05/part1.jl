m = zeros(Int, 1000, 1000); m2 = zeros(Int, 1000, 1000)
Ψ = (p, g) -> begin 
    if p[1] == p[3] || p[2] == p[4] 
        for x in min(p[1], p[3]):max(p[1], p[3]), 
            y in min(p[2], p[4]):max(p[2], p[4]) 
            g[y, x] += 1
        end
    end
end
ψ = (p) -> begin
    if p[1] == p[3] || p[2] == p[4] 
        Ψ(p, m); Ψ(p, m2)
    else
    end
end
map(p -> ψ(p), 
    map(l -> map(x -> parse(Int, x) + 1, 
        match(r"(\d+),(\d+) -> (\d+),(\d+)", l)), 
        readlines("input")
    )
)
for i in 1:10
    for j in 1:10
        if m2[i, j] == 0
            print('.')
        else print(m2[i, j]) end
    end
    println()
end
println("$(count(x -> x >= 2, m))")