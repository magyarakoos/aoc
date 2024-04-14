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
        x = p[1]; y = p[2]
        
        while !(x == p[3] && y == p[4])
            m2[y, x] += 1
            x += sign(p[3] - p[1])
            y += sign(p[4] - p[2])
        end
    end
end
map(p -> ψ(p), 
    map(l -> map(x -> parse(Int, x) + 1, 
        match(r"(\d+),(\d+) -> (\d+),(\d+)", l)), 
        readlines("input")
    )
)
println("$(count(x -> x >= 2, m))\n$(count(x -> x >= 2, m2))")