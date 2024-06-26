m = zeros(Int, 1000, 1000); m2 = zeros(Int, 1000, 1000)
ψ = (p, g, b) -> begin
    x = p[1]; y = p[2]; k = 0
    if b && (sign(p[3] - p[1]) != 0 && sign(p[4] - p[2]) != 0)
        return
    end
    while k <= max(abs(p[1] - p[3]), abs(p[2] - p[4]))
        g[y, x] += 1
        x += sign(p[3] - p[1])
        y += sign(p[4] - p[2])
        k += 1
    end
end
map(p -> (ψ(p, m, true), ψ(p, m2, false)), 
    map(l -> map(x -> parse(Int, x) + 1, 
        match(r"(\d+),(\d+) -> (\d+),(\d+)", l)), 
        readlines("input")
    )
)
println("$(count(x -> x >= 2, m))\n$(count(x -> x >= 2, m2))")