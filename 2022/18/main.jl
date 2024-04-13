σ = Set()
λ = (m) -> push!(σ, [m[1], m[2], m[3]])
Ψ = (x, y, z) -> [[x+1, y, z], [x-1, y, z], [x, y+1, z], [x, y-1, z], [x, y, z+1], [x, y, z-1]]
map(l -> λ(map(x -> parse(Int, x), match(r"(\d+),(\d+),(\d+)", l))), readlines("input"))
Σ = length(σ) * 6
for (x, y, z) in σ, ρ in Ψ(x, y, z)
    
    if ∈(σ, ρ)
        global Σ -= 1
    end
end
println(Σ)