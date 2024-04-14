m = zeros(Int, 1000, 1000); m2 = m
Ψ = (p) -> begin 
    if p[1] == p[3] || p[2] == p[4] 
        for x in min(p[1], p[3]):max(p[1], p[3]), 
            y in min(p[2], p[4]):max(p[2], p[4]) 
            m[y, x] += 1
        end
    end
end
ψ = (p) -> begin
    if p[1] == p[3] || p[2] == p[4] Ψ(p)
end
map(p -> (Ψ(p), ψ(p)), 
    map(l -> map(x -> parse(Int, x) + 1, 
        match(r"(\d+),(\d+) -> (\d+),(\d+)", l)), 
        readlines("input")
    )
)
println("$(count(x -> x >= 2, m))")